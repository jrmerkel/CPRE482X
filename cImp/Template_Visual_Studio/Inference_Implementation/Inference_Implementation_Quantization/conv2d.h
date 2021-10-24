#pragma once
#include "quantize_input.h"
#include "quantize_weights.h"
#include "quantize_biases.h"
#include "dequantize.h"
#include <stdint.h>

template<int w, int h, int c, int s, int r, int m>
void conv2d(float (&input_tensor)[w][h][c], float (&weights)[s][r][c][m], float (&biases)[m], float * output_tensor) 
{
	float scale_input, scale_weight;
	//quantize the input, weight, and biases
	uint8_t quant_input[w][h][c];
	scale_input = quantize_input(input_tensor, quant_input);

	int8_t quant_weights[s][r][c][m];
	scale_weight = quantize_weights(weights, quant_weights);

	int32_t quant_biases[m];
	quantize_biases(biases, quant_biases, scale_input*scale_weight);

	//calculate P and Q which is the resulting size (we are using U = 1)
	int p = h - r + 1;
	int q = w - s + 1;
	//float (&output_tensor_arrform)[p,q,m] = (float*) malloc(m * p * q * sizeof(float));
	int32_t matrix_output[h - r + 1][w - s + 1][m];
	float dequant_output[h - r + 1][w - s + 1][m];
	memset( matrix_output, 0, p*q*m*sizeof(int32_t) );
    // cout << "CONV2D matrix output dim " << p << q << m << endl;
	// o[n][m][p][q] = sumc sum r sums i[n][c][p+r][q+s] * f[m][c][r][s] + b[m]
	//where n = 1
    //TODO stretch Fix the loop orderings but don't touch atm it works LMAO
	for(int z = 0; z < q; z++) ///////////////////////////////m = x
	{
		for(int y = 0; y < p; y++)////////////////////////////p = y
		{
			for(int x = 0; x < m; x++)////////////////////////q = z
			{
				for(int k = 0; k < s; k++)////////////////////c = i
				{
					for(int j = 0; j < r; j++)////////////////r = j
					{
						for(int i = 0; i < c; i++)////////////s = k
						{
							//matrix[m][p][q] = i[c][p + r][q + s] * f[m][c][r][s]
                            //Ours is not in this exact order
                            //Ours is matrix[m][p][q] = i[q + s][p+r][c] * f[s][r][c][m]
                            matrix_output[z][y][x] +=  quant_input[z + k][y+j][i] * quant_weights[k][j][i][x];
                        }
					}
				}
			}
		}
	}
	for(int z = 0; z < q; z++)
	{
		for(int y = 0; y < p; y++)
		{
			for(int x = 0; x < m; x++)
			{
				//Add bias
				matrix_output[z][y][x]   += quant_biases[x];
				//activation function relu if negative then 0
				if(matrix_output[z][y][x]  < 0)
				{
					matrix_output[z][y][x]   = 0;
				} 
			}
		}
	}
	// static const int s_p = static_cast<int>(p);
	// static const int s_q = static_cast<int>(q);
	dequantize(dequant_output, matrix_output, (float)(scale_input*scale_weight));
	//<(h - r + 1),(w - s + 1),m>
	//copy stack array into output tensor pointer
	memcpy(output_tensor, dequant_output, sizeof(float) * m * p * q);
}