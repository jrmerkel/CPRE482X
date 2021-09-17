#include "source.h"
#include "conv2d.h"
// Implement the layers as functions


int main()

{
	// Do this for all the three chosen inputs:


		// Load the input data from binary file.
			// First load the flattened array then reshape according to input dimensions.
		float input[64][64][3];
		int input_dim[3] = { 64, 64, 3};
		load_input("../../Image4/input4.bin", 64, 64, 3, (float *)input);
			//Print out some test values to see if we are matching the input. 
		//For x_val[4] we should see
			/*
		print(x_val[4][0][0][0])
		print(x_val[4][1][0][0])
		print(x_val[4][0][1][0])
		print(x_val[4][0][0][1])
		0.16078432
		0.69803923
		0.48235294
		0.20392157

			*/
		cout << "000 " << input[0][0][0] << endl;

		cout << "100 " << input[1][0][0] << endl;

		cout << "010 " << input[0][1][0] << endl;

		cout << "001 " << input[0][0][1] << endl;

		// Load the weights data from binary files.
			// First load the flattened array then reshape according to weights/bias dimensions.
		float weights_layer0[5][5][3][32];
		/* should see
			0000 -0.021224262
			1000 0.06164234
			0100 0.03920702
			0010 -0.0036433637
			0001 0.0074597695
		*/
		int dim_layer0[4] = {5,5,32,32};
		load_weights("../../Our_export/conv2d_weights.bin", dim_layer0, (float *) weights_layer0);

		cout << "0000 " << weights_layer0[0][0][0][0] << endl;

		cout << "1000 " << weights_layer0[1][0][0][0] << endl;

		cout << "0100 " << weights_layer0[0][1][0][0] << endl;

		cout << "0010 " << weights_layer0[0][0][1][0] << endl;

		cout << "0001 " << weights_layer0[0][0][0][1] << endl;

		float biases_layer0[32];
		load_biases("../../Our_export/conv2d_bias.bin", 32, biases_layer0);
		//Should be 0.00828
		cout << "0 " <<biases_layer0[0] << endl;

		// Load the intermediate feature map data from binary files.
		 // First load the flattened array then reshape according to intermediate feature map dimensions.
		int dim_fmap0[3] = {60, 60, 32};
		float fmap_layer0[60][60][32];
		load_intermediate_maps("../../Our_export/4conv2dintermediate.bin", dim_fmap0, (float *) fmap_layer0);
		/*
			000 0.268127
			100 0.16241197
			010 0.28409594
			001 0.13051246
		*/
		cout << "000 " << fmap_layer0[0][0][0] << endl;

		cout << "100 " << fmap_layer0[1][0][0] << endl;

		cout << "010 " << fmap_layer0[0][1][0] << endl;

		cout << "001 " << fmap_layer0[0][0][1] << endl;


		// Execute the inference code and validate against the imported inference output. 
		// For each of the input, for all of the intermediate feature maps provide the binary files for both the imported feature maps from python (true value) and the ones predicted by your own C/C++ implementation.
		// Were you able to get similar final classification probability as the python version executing? if not what was the difference.

		//First Conv2d
		float layer0_output[60][60][32];
		conv2d(input, weights_layer0, biases_layer0, (float * )layer0_output);
		cout << "000 " << layer0_output[0][0][0] << endl;

		cout << "100 " << layer0_output[1][0][0] << endl;

		cout << "010 " << layer0_output[0][1][0] << endl;

		cout << "001 " << layer0_output[0][0][1] << endl;

		//Which goes into Conv2d_1
		
}

void load_input(string filename, int x_dim, int y_dim, int channels, float * out)
{
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int r2 = fread(out, sizeof(float), (x_dim*y_dim*channels), ptr_weights);
		printf("Read input values: %d\n", r2);
	}
	fclose(ptr_weights);
}

void load_weights(string filename, int dim[4], float * weights)
{
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int r2 = fread(weights, sizeof(float), (dim[0] * dim[1] * dim[2] * dim[3]), ptr_weights);
		printf("Read weight values: %d\n", r2);
	}
	fclose(ptr_weights);
}

void load_biases(string filename, int biaslength, float * biases)
{
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int r2 = fread(biases, sizeof(float), (biaslength), ptr_weights);
		printf("Read biases values: %d\n", r2);
	}
	fclose(ptr_weights);
}

//Just a function to help us test
void load_intermediate_maps(string filename, int dim[3], float * ifmap)
{
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen(filename.c_str(), "rb");  // r for read, b for binary
	if(ptr_weights!=NULL)
	{
		int r2 = fread(ifmap, sizeof(float), (dim[0] * dim[1] * dim[2]), ptr_weights);
		printf("Read fmap values: %d\n", r2);
	}
	fclose(ptr_weights);
}
/**
 * Input tensor is a 3 dimensional array of floats specified by the first 3 ints in input_dim
 * The input tensor is matrix multiplied by the weight matrix specified by the weight dim (4 dim) and placed into the output tensor
 * 
 */


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