#pragma once
#include <stdint.h>
template<int m>

void quantize_biases(float (&biases)[m], int32_t (&quant_biases)[m], float scale){
    for(int i=0; i<m; i++){
        quant_biases[i] = int32_t(biases[i]*scale);
	}
}

template<int m, int p, int q>
void dequantize(float (&output)[p][q][m], int32_t (&quant_output)[p][q][m], float scale){
    for(int i=0; i<p; i++){
        for(int j=0; j<q; j++){
            for(int k=0; k<m; k++){
                output[i] = float(quant_output[i]/scale);
            }
        }
	}
}