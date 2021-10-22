#pragma once
#include <math.h>
template<int X, int W>
void denseRelu(float (&input_arr)[X], float (&weights)[X][W], float (&biases)[W], float * output) 
{
    int32_t output_arr[W];
    float dequantized_output_arr [W];

    float scale_input, scale_weight;
	//quantize the input, weight, and biases
	uint8_t quant_input[X];
	scale_input = quantize_input(input_arr, quant_input);

	int8_t quant_weights[X][W];
	scale_weight = quantize_weights(weights, quant_weights);

	int32_t quant_biases[W];
	quantize_biases(biases, quant_biases, scale_input*scale_weight);

    for (int i = 0; i < W; i++)
    {
        //Add bias
        output_arr[i] = quant_biases[i];
        //Matmul
        for (int j = 0; j < X; j++)
        {
            output_arr[i] += quant_input[j] * quant_weights[j][i];
        }
        //RELU
        if( output_arr[i] < 0)
        {
            output_arr[i] = 0;
        }
    }
    
    dequantize(dequantized_output_arr, output_arr, scale_input * scale_weight);
	//copy stack array into output tensor pointer
	memcpy(output, dequantized_output_arr, sizeof(float) * W);
}

template<int X, int W>
void denseSoftmax(float (&input_arr)[X], float (&weightsSM)[X][W], float (&biases)[W], float * output) 
{
    int32_t output_arr[W];
    float dequantized_output_arr[W];

    float scale_input, scale_weight;
	//quantize the input, weight, and biases
	uint8_t quant_input[X];
	scale_input = quantize_input(input_arr, quant_input);

	int8_t quant_weights[X][W];
	scale_weight = quantize_weights(weightsSM, quant_weights);

	int32_t quant_biases[W];
	quantize_biases(biases, quant_biases, scale_input*scale_weight);
    // cout << "dense arr " << W << endl;
    for (int i = 0; i < W; i++)
    {
        //cout << "bias " << i << " " << biases[i] << endl;
        //Add bias
        output_arr[i] = quant_biases[i];
        //Matmul
        for (int j = 0; j < X; j++)
        {
            // if(i == 11)
            // {
            //     cout << "weight " << j << " " << weights [j][11]<< endl;
            // }
            output_arr[i] += quant_input[j]* quant_weights[j][i];
        }
    }

    dequantize(dequantized_output_arr, output_arr, scale_input * scale_weight);
    float post_softmax[W];
    float denominator = 0.0;

    for (int i = 0; i < W; i++)
    {
        denominator += exp(dequantized_output_arr[i]);
    }
    //now we calc the actual outputs
    for (int i = 0; i < W; i++)
    {
        post_softmax[i] = exp(dequantized_output_arr[i])/ denominator;
    }
	//copy stack array into output tensor pointer
	memcpy(output, post_softmax, sizeof(float) * W);
}