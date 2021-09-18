#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include <cstring>

using namespace std;

#define TOLERANCE 0.00001f


//Should've done loads as 1d, 2d etc but that's a stretch goal
template<int N, int C>
void load_input(string filename, float out[N][N][C])
{
    	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int r2 = fread(out, sizeof(float), (N*N*C), ptr_weights);
		printf("Read input values: %d\n", r2);
	}
	fclose(ptr_weights);
}

template<int s, int r, int c, int m>
void load_weights(string filename, float (&weights)[s][r][c][m])
{
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int r2 = fread(weights, sizeof(float), (s*r*c*m), ptr_weights);
		printf("Read weight values: %d\n", r2);
	}
	fclose(ptr_weights);
}

template<int x, int y>
void load_weights(string filename, float (&weights)[x][y])
{
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int r2 = fread(weights, sizeof(float), (x*y), ptr_weights);
		printf("Read weight values: %d\n", r2);
	}
	fclose(ptr_weights);
}

template <int len>
void load_biases(string filename, float (&biases)[len])
{
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int r2 = fread(biases, sizeof(float), len, ptr_weights);
		printf("Read biases values: %d\n", r2);
	}
	fclose(ptr_weights);
}

//Just a function to help us test
template <int X, int Y, int Z>
void load_intermediate_maps(string filename, float (&ifmap)[X][Y][Z])
{
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int r2 = fread(ifmap, sizeof(float), (X*Y*Z), ptr_weights);
		printf("Read fmap values: %d\n", r2);
	}
	fclose(ptr_weights);
}

template <int X>
void load_intermediate_maps(string filename, float (&ifmap)[X])
{
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int r2 = fread(ifmap, sizeof(float), (X), ptr_weights);
		printf("Read fmap values: %d\n", r2);
	}
	fclose(ptr_weights);
}


template <int x, int y, int z>
bool compareMatrix3d(float (&MatrixA)[x][y][z], float (&MatrixB)[x][y][z])
{

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if(abs(MatrixA[i][j][k] - MatrixB[i][j][k]) > TOLERANCE)
                {
                    return false;
                }
            }
            
        }
        
    }
    cout << "Matrix Match" << endl;
    return true;
}

void dense(float * input_arr, float * output_arr, float * weight_matrix, float * biases, int input_size, int output_size);