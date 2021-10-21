#pragma once
#include <stdint.h>

template<int h, int r, int w, int s, int m>
void dequantize(float (&dequant_output)[h - r + 1][w - s + 1][m], int32_t (&output)[h - r + 1][w - s + 1][m], float scale){
    int p, q;
    p=h-r+1;
    q=w-s+1;
    for(int i=0; i<p; i++){
        for(int j=0; j<q; j++){
            for(int k=0; k<m; k++){
                dequant_output[i][j][k] = float(output[i][j][k]) / scale;
            }
        }
	}
}