#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include <cstring>
using namespace std;

void load_input(string filename, int x_dim, int y_dim, int channels, float * out);
void conv2d(float * input_tensor, float * weights, float * biases, float * output_tensor, int * input_dim, int * weight_dim);
void maxPool2D(float * input_tensor, float * output_tensor, int * input_dim, int * pooling_dim);
void dense(float * input_arr, float * output_arr, float * weight_matrix, float * biases, int input_size, int output_size);