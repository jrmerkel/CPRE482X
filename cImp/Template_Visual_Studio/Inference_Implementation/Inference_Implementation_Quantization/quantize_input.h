#pragma once
#include <stdint.h>
template<int w, int h, int c>

float quantize_input(float (&input_tensor)[w][h][c], uint8_t (&input)[w][h][c])
{
	float max=0;
	for(int i=0; i<w; i++)
	{
		for(int j=0; j<h; j++)
		{
			for(int k=0; k<c; k++)
			{
				if(abs(input_tensor[i][j][k])>max)
				{
					max=abs(input_tensor[i][j][k]);
				}
			}
		}
	}
    float scale=255/max;
    for(int i=0; i<w; i++)
	{
		for(int j=0; j<h; j++)
		{
			for(int k=0; k<c; k++)
			{
				input[i][j][k] = uint8_t(input_tensor[i][j][k]*scale);
			}
		}
	}
    return scale;
}

template<int w>
float quantize_input(float (&input_arr)[w], uint8_t (&q_input)[w])
{
	float max=0;
	for(int i=0; i<w; i++)
	{
		if(abs(input_arr[i])>max)
		{
			max=abs(input_arr[i]);
		}
	}
    float scale=255/max;
    for(int i=0; i<w; i++)
	{
		q_input[i] = uint8_t(input_arr[i]*scale);
	}
    return scale;
}