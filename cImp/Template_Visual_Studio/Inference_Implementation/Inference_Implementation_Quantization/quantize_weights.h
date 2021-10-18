#pragma once
#include <stdint.h>
template<int c, int s, int r, int m>

float quantize_weights(float (&weights)[s][r][c][m], int8_t (&quant_weights)[s][r][c][m]){
	float max=0;
	for(int i=0; i<s; i++){
		for(int j=0; j<r; j++){
			for(int k=0; k<c; k++){
                for(int l=0; l<m; l++){
                    if(abs(weights[i][j][k][l])>max){
					    max=abs(weights[i][j][k][l]);
                    }
                }
			}
		}
	}
    float scale=127/max;
    for(int i=0; i<s; i++){
		for(int j=0; j<r; j++){
			for(int k=0; k<c; k++){
                for(int l=0; l<m; l++){
                    quant_weights[i][j][k][l] = uint8_t(weights[i][j][k][l]*scale);
                }
			}
		}
	}
    return scale;
}