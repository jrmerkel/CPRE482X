#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include <cstring>
#include <cmath>

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
		// printf("Read input values: %d\n", r2);
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
		// printf("Read weight values: %d\n", r2);
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
		// printf("Read weight values: %d\n", r2);
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
		// printf("Read biases values: %d\n", r2);
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
		// printf("Read fmap values: %d\n", r2);
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
		// printf("Read fmap values: %d\n", r2);
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
                    cout << "!!!!!!!!!MISMATCH!!!!!!!!" << endl;
                    return false;
                }
            }
            
        }
        
    }
    cout << "Matrix Match" << endl;
    return true;
}

template <int x, int y, int z>
bool compareMaxMatrix3d(float (&MatrixA)[x][y][z], float (&MatrixB)[x][y][z])
{
    double max_diff = 0;
    double curr_diff = 0;
	double average_diff = 0;
	int index[3] = {0};
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                curr_diff = fabs(MatrixA[i][j][k] - MatrixB[i][j][k]);
				average_diff += curr_diff;
				if(curr_diff > max_diff)
				{
					max_diff = curr_diff;
					index[0] = i;
					index [1] = j;
					index[2] = k;
				}
            }
            
        }
        
    }
	cout << index[0] << index[1] << index[2] << endl;
	cout << "MAX DIFF " << max_diff << endl;
	cout << "AVG DIFF " << average_diff/(x*y*z) << endl;
   // cout << "Matrix Match" << endl;
    return true;
}


template<int x>
bool compare1d(float (&arrA)[x], float (&arrB)[x])
{
    for (int i = 0; i < x; i++)
    {
        if(fabs(arrA[i] - arrB[i]) > TOLERANCE)
        {
            cout << i << " " << arrA[i] << " " << arrB[i] << endl;
            cout << "!!!!!!!!!MISMATCH!!!!!!!!" << endl;
            return false;
        }
    }
    cout << "Arrays match" << endl;
    return true;
}

template<int N>
// Parameters: N: compares two 1d arrays of size N and returns the maximum difference
float comparemax1d(float (&Input1)[N], float (&Input2)[N]) {
    // display the maximum diff
    double max_diff = 0;
    double curr_diff = 0;
    int index = 0;
    for (int i = 0; i < N; i++) {
       
                curr_diff = abs(Input1[i] - Input2[i]);
                if (curr_diff > max_diff) {
                    max_diff = curr_diff;
                    index = i;
                }


      
    }
    cout << "index " << index << endl;
    cout << "expected " << Input1[index] << " actual " << Input2[index] << endl;
    return max_diff;

}

template<int X, int Y, int Z>
void export_binary(float (&fmap)[X][Y][Z], string filename)
{
    FILE* ptr_weights = fopen(filename.c_str(), "wb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int w2 = fwrite(fmap, sizeof(float), (X*Y*Z), ptr_weights);
		printf("wrote binary to : %s\n", filename.c_str());
	}
	fclose(ptr_weights);
}

template<int X>
void export_binary(float (&fmap)[X], string filename)
{
    FILE* ptr_weights = fopen(filename.c_str(), "wb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int w2 = fwrite(fmap, sizeof(float), (X), ptr_weights);
		printf("wrote binary to : %s\n", filename.c_str());
	}
	fclose(ptr_weights);
}