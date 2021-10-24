#pragma once
#include <stdint.h>
template<int m>

void quantize_biases(float (&biases)[m], int32_t (&quant_biases)[m], float scale){
    for(int i=0; i<m; i++)
    {
        quant_biases[i] = int32_t(biases[i]*scale);
	}
}

template<int m, int P, int Q>
void dequantize(float (&output)[P][Q][m], int32_t (&quant_output)[P][Q][m], float scale){
    for(int i=0; i<P; i++)
    {
        for(int j=0; j<Q; j++)
        {
            for(int k=0; k<m; k++)
            {
                output[i][j][k] = ((float)quant_output[i][j][k])/scale;
            }
        }
	}
}

template<int X>
void dequantize(float (&output)[X], int32_t (&quant_output)[X], float scale){
    for(int i=0; i<X; i++)
    {
        output[i] = ((float)quant_output[i])/scale;
	}
}