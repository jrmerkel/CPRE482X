#pragma once
#include <math.h>
template<int X, int W>
void denseRelu(float (&input_arr)[X], float (&weights)[X][W], float (&biases)[W], float * output) 
{
    float output_arr [W];
    cout << "dense arr " << W << " " << X << endl;
    for (int i = 0; i < W; i++)
    {
        //Add bias
        output_arr[i] = biases[i];
        //Matmul
        for (int j = 0; j < X; j++)
        {
            output_arr[i] += input_arr[j] * weights[j][i];
        }
        //RELU
        if( output_arr[i] < 0)
        {
            output_arr[i] = 0;
        }
    }
    
	//copy stack array into output tensor pointer
	memcpy(output, output_arr, sizeof(float) * X * W);
}

template<int X, int W>
void denseSoftmax(float (&input_arr)[X], float (&weightsSM)[X][W], float (&biases)[W], float * output) 
{
    float output_arr [W];
    cout << "dense arr " << W << endl;
    for (int i = 0; i < W; i++)
    {
        //cout << "bias " << i << " " << biases[i] << endl;
        //Add bias
        output_arr[i] = biases[i];
        //Matmul
        for (int j = 0; j < X; j++)
        {
            // if(i == 11)
            // {
            //     cout << "weight " << j << " " << weights [j][11]<< endl;
            // }
            output_arr[i] += input_arr[j]* weightsSM[j][i];
        }
    }
    float post_softmax[W];
    float denominator = 0.0;

    for (int i = 0; i < W; i++)
    {
        denominator += exp(output_arr[i]);
    }
    //now we calc the actual outputs
    for (int i = 0; i < W; i++)
    {
        post_softmax[i] = exp(output_arr[i])/ denominator;
    }
	//copy stack array into output tensor pointer
	memcpy(output, post_softmax, sizeof(float) * X * W);
}