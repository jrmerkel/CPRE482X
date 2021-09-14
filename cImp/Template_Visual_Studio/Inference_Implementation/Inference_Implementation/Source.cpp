#include "source.h"
// Implement the layers as functions


int main()

{
	// Do this for all the three chosen inputs:


		// Load the input data from binary file.
			// First load the flattened array then reshape according to input dimensions.
		float out[64][64][3];
		load_input("../../Image4/input4.bin", 64, 64, 3, (float *)out);
		for(int k=0; k<3; k++)
		{
			for(int i=0; i<64; i++)
			{
				for(int j=0; j<64; j++)
				{
					cout << out[i][j][k] << "\t";
				}
				cout << endl;
			}
			cout << "\n\n";
		}

		// Load the weights data from binary files.
			// First load the flattened array then reshape according to weights/bias dimensions.


		// Load the intermediate feature map data from binary files.
		 // First load the flattened array then reshape according to intermediate feature map dimensions.


		/* Sample code to read a binary file (test.bin) exported from python into C:

		// SAMPLE CODE: Read a flattened 5*5*3*32 (2400 float values) convolution weight binary file (test.bin) into an array in C

		float conv1_weights[2400] = { 0 }; // reshape back to 5*5*3*32

		FILE* ptr_weights = fopen("C:\\Users\\mailr\\Downloads\\Conv_experiement\\conv1_weights.bin", "rb");  // r for read, b for binary
		int r2 = fread(conv1_weights, sizeof(float), 2400, ptr_weights);
		printf("Read weight values: %d\n", r2);
		fclose(ptr_weights);

		*/


		// Execute the inference code and validate against the imported inference output. 
		// For each of the input, for all of the intermediate feature maps provide the binary files for both the imported feature maps from python (true value) and the ones predicted by your own C/C++ implementation.
		// Were you able to get similar final classification probability as the python version executing? if not what was the difference.
}

void load_input(string filename, int x_dim, int y_dim, int channels, float * out)
{
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	float input[x_dim*y_dim*channels];
	if(ptr_weights!=NULL)
	{
		int r2 = fread(input, sizeof(float), (x_dim*y_dim*channels), ptr_weights);
		printf("Read weight values: %d\n", r2);
	}
	cout << input[0] << endl;
	fclose(ptr_weights);
	//float out[x_dim][y_dim][channels];
	int c = 0;
	for(int k=0; k<channels; k++)
	{
		for(int i=0; i<x_dim; i++)
		{
			for(int j=0; j<y_dim; j++)
			{
				*(out + i + x_dim *j + x_dim*y_dim*k) = input[i];
				c++;
			}
		}
	}
}

/**
 * Input tensor is a 3 dimensional array of floats specified by the first 3 ints in input_dim
 * The input tensor is matrix multiplied by the weight matrix specified by the weight dim (4 dim) and placed into the output tensor
 * 
 */
void conv2d(float * input_tensor, float * weights, float * biases, float * output_tensor, int * input_dim, int * weight_dim)
{
	//input terms
	int w = *(input_dim);
	int h = *(input_dim + 1);
	int c = *(input_dim + 2);

	//filter term
	int s = *(weight_dim);
	int r = *(weight_dim + 1);
	//int c = *weight_dim + 2
	int m = *(weight_dim + 3);

	//calculate P and Q which is the resulting size (we are using U = 1)
	int p = h - r;
	int q = w - s;
	//float (&output_tensor_arrform)[p,q,m] = (float*) malloc(m * p * q * sizeof(float));
	float matrix_output[p][q][m];
	// o[n][m][p][q] = sumc sum r sums i[n][c][p+r][q+s] * f[m][c][r][s] + b[m]
	//where n = 1
	for(int x = 0; x < m; x++)
	{
		for(int y = 0; y < p; y++)
		{
			for(int z = 0; z < q; z++)
			{
				matrix_output[x][y][z] = 0;
				for(int i = 0; i < c; i++)
				{
					for(int j = 0; j < r; j++)
					{
						for(int k = 0; k < s; k++)
						{
							//matrix[m][p][q] = i[c][p + r][q + s] * f[m][c][r][s]
							matrix_output[x][y][z] +=  *(input_tensor + (k+z) + (s+y)*s + r*s*i) * *(weights + k + s*j + r*s*i + r*s*c*m);
						}
					}
				}
				//Add bias
				matrix_output[x][y][z] += *(biases + m);
				//activation function relu if negative then 0
				if(matrix_output[x][y][z] < 0)
				{
					matrix_output[x][y][z] = 0;
				} 
			}
		}
	}

	//copy stack array into output tensor pointer
	memcpy(output_tensor, matrix_output, sizeof(float) * m * p * q);

}

/**
 * Same concept as conv2d except there's no weight matrix, just max pooling based on dimension
 * Input tensor is a 3 dimensional array of floats specified by the first 3 ints in input_dim
 * The input tensor is matrix multiplied by the weight matrix specified by the weight dim (4 dim) and placed into the output tensor
 * 
 */
void maxPool2D(float * input_tensor, float * output_tensor, int * input_dim, int * pooling_dim)
{
	//input terms
	int w = *(input_dim);
	int h = *(input_dim + 1);
	int c = *(input_dim + 2);

	//filter term
	int s = *(pooling_dim);
	int r = *(pooling_dim + 1);
	//int c = *weight_dim + 2 duplicated with input_dim
	int m = *(pooling_dim + 3);

	//calculate P and Q which is the resulting size (we are using U = 1)
	int p = h - r;
	int q = w - s;
	//float (&output_tensor_arrform)[p,q,m] = (float*) malloc(m * p * q * sizeof(float));
	float matrix_output[p][q][m];
	// o[n][m][p][q] = sumc sum r sums i[n][c][p+r][q+s] * f[m][c][r][s] + b[m]
	//where n = 1
	for(int x = 0; x < m; x++)
	{
		for(int y = 0; y < p; y++)
		{
			for(int z = 0; z < q; z++)
			{
				//init as the first num in the pool
				matrix_output[x][y][z]  =  *(input_tensor + y*s + z);
				for(int i = 0; i < c; i++)
				{
					for(int j = 0; j < r; j++)
					{
						for(int k = 0; k < s; k++)
						{
							if(*(input_tensor + (k+z) + (s+y)*s + r*s*i) > matrix_output[x][y][z])
							{
								matrix_output[x][y][z] =  *(input_tensor + (k+z) + (s+y)*s + r*s*i);
							}
						}
					}
				}
			}
		}
	}
	
	//copy stack array into output tensor pointer
	memcpy(output_tensor, matrix_output, sizeof(float) * m * p * q);

}

/**
 * Dense layer should be arrays
 */
void dense(float * input_arr, float * output_arr, float * weight_matrix, float * biases, int input_size, int output_size)
{
	for(int i = 0; i < output_size; i++)
	{
		*(output_arr + i) = 0;
		for(int j = 0; j < input_size; j++)
		{
			*(output_arr + i) += *(input_arr + j) * *(weight_matrix + j + input_size * i);
		}
		//activation function (RELU?) TODO maybe add sigmoid case?
		if(*(output_arr + i) < 0) 
		{
			*(output_arr + i) = 0;
		}
	}
}