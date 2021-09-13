#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

// Implement the layers as functions
using namespace std;
void load_input(string filename, int x_dim, int y_dim, int channels, float * out);
int main()

{
	// Do this for all the three chosen inputs:


		// Load the input data from binary file.
			// First load the flattened array then reshape according to input dimensions.
		float out[64][64][3];
		load_input("/home/augustom/482/CPRE482X/cImp/Template_Visual_Studio/Test_Input0/input.bin", 64, 64, 3, (float *)out);
		for(int k=0; k<3; k++){
			for(int i=0; i<64; i++){
				for(int j=0; j<64; j++){
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

void load_input(string filename, int x_dim, int y_dim, int channels, float * out){
	//save every 32 bits of info (float32) from input stream into one matrix element
	FILE* ptr_weights = fopen("/home/augustom/482/CPRE482X/cImp/Template_Visual_Studio/Test_Input0/input.bin", "rb");  // r for read, b for binary
	float input[x_dim*y_dim*channels];
	if(ptr_weights!=NULL){
		int r2 = fread(input, sizeof(float), (x_dim*y_dim*channels), ptr_weights);
		printf("Read weight values: %d\n", r2);
	}
	cout << input[0] << endl;
	fclose(ptr_weights);
	//float out[x_dim][y_dim][channels];
	int c = 0;
	for(int k=0; k<channels; k++){
		for(int i=0; i<x_dim; i++){
			for(int j=0; j<y_dim; j++){
				*(out + i + x_dim *j + x_dim*y_dim*k) = input[i];
				c++;
			}
		}
	}
}