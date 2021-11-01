#include "source.h"
#include "conv2d.h"
#include "maxpool2d.h"
#include "dense.h"

// Implement the layers as functions

//Stretch goal implement as a loop
int main()
{
	// Do this for all the three chosen inputs:
	//Our chosen inputs are the 4th, 6th, and 8th image


		// Load the input data from binary file.
		// First load the flattened array then reshape according to input dimensions.
		float input[64][64][3];
		load_input("../JupyterExport/input4.bin", input);
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
		
		// Load the weights data from binary files.
		// First load the flattened array then reshape according to weights/bias dimensions.
		float weights_layer0[5][5][3][32];
		float biases_layer0[32];

		float weights_layer1[5][5][32][32];
		float biases_layer1[32];

		float weights_layer2[3][3][32][64];
		float biases_layer2[64];

		float weights_layer3[3][3][64][64];
		float biases_layer3[64];

		float weights_layer4[3][3][64][64];
		float biases_layer4[64];

		float weights_layer5[3][3][64][128];
		float biases_layer5[128];

		float weights_dense0[2048][256];
		float biases_dense0[256];

		float weights_dense1[256][200];
		float biases_dense1[200];
		
		load_weights("../JupyterExport/conv2d_weights.bin", weights_layer0);
		load_weights("../JupyterExport/conv2d_1_weights.bin", weights_layer1);
		load_weights("../JupyterExport/conv2d_2_weights.bin", weights_layer2);
		load_weights("../JupyterExport/conv2d_3_weights.bin", weights_layer3);
		load_weights("../JupyterExport/conv2d_4_weights.bin", weights_layer4);
		load_weights("../JupyterExport/conv2d_5_weights.bin", weights_layer5);

		load_weights("../JupyterExport/dense_weights.bin", weights_dense0);
		load_weights("../JupyterExport/test2.bin", weights_dense1);

		// export_weights("../JupyterExport/conv2d_c_weights.bin", weights_layer0);
		// export_weights("../JupyterExport/conv2d_c_1_weights.bin", weights_layer1);
		// export_weights("../JupyterExport/conv2d_c_2_weights.bin", weights_layer2);
		// export_weights("../JupyterExport/conv2d_c_3_weights.bin", weights_layer3);
		// export_weights("../JupyterExport/conv2d_c_4_weights.bin", weights_layer4);
		// export_weights("../JupyterExport/conv2d_c_5_weights.bin", weights_layer5);
		// export_weights("../JupyterExport/dense_weights.bin", weights_dense0);
		// export_weights("../JupyterExport/test2.bin", weights_dense1);


		load_biases("../JupyterExport/conv2d_bias.bin",biases_layer0);
		load_biases("../JupyterExport/conv2d_1_bias.bin",biases_layer1);
		load_biases("../JupyterExport/conv2d_2_bias.bin",biases_layer2);
		load_biases("../JupyterExport/conv2d_3_bias.bin",biases_layer3);
		load_biases("../JupyterExport/conv2d_4_bias.bin",biases_layer4);
		load_biases("../JupyterExport/conv2d_5_bias.bin",biases_layer5);

		load_biases("../JupyterExport/dense_bias.bin",biases_dense0);
		load_biases("../JupyterExport/dense_1_bias.bin",biases_dense1);
		// Load the intermediate feature map data from binary files.
		// First load the flattened array then reshape according to intermediate feature map dimensions.
		float fmap_layer0[60][60][32];
		float fmap_layer1[56][56][32];
		float fmap_layer2[26][26][64];
		float fmap_layer3[24][24][64];
		float fmap_layer4[10][10][64];
		float fmap_layer5[8][8][128];

		float fmap_dense0[256];
		float fmap_dense1[200];

		float fmap_maxpool0[28][28][32];
		float fmap_maxpool1[12][12][64];
		float fmap_maxpool2[4][4][128];


		load_intermediate_maps("../JupyterExport/4conv2dintermediate.bin", fmap_layer0);
		load_intermediate_maps("../JupyterExport/4conv2d_1intermediate.bin", fmap_layer1);
		load_intermediate_maps("../JupyterExport/4conv2d_2intermediate.bin", fmap_layer2);
		load_intermediate_maps("../JupyterExport/4conv2d_3intermediate.bin", fmap_layer3);
		load_intermediate_maps("../JupyterExport/4conv2d_4intermediate.bin", fmap_layer4);
		load_intermediate_maps("../JupyterExport/4conv2d_5intermediate.bin", fmap_layer5);

		load_intermediate_maps("../JupyterExport/4denseintermediate.bin", fmap_dense0);
		load_intermediate_maps("../JupyterExport/4dense_1intermediate.bin", fmap_dense1);

		load_intermediate_maps("../JupyterExport/4max_pooling2dintermediate.bin", fmap_maxpool0);
		load_intermediate_maps("../JupyterExport/4max_pooling2d_1intermediate.bin", fmap_maxpool1);
		load_intermediate_maps("../JupyterExport/4max_pooling2d_2intermediate.bin", fmap_maxpool2);
		// Execute the inference code and validate against the imported inference output. 
		// For each of the input, for all of the intermediate feature maps provide the binary files for both the imported feature maps from python (true value) and the ones predicted by your own C/C++ implementation.
		// Were you able to get similar final classification probability as the python version executing? if not what was the difference.
		float output_layer0[60][60][32];
		float output_layer1[56][56][32];
		float output_layer2[26][26][64];
		float output_layer3[24][24][64];
		float output_layer4[10][10][64];
		float output_layer5[8][8][128];

		float output_dense0[256];
		float output_dense1[200];

		float output_maxpool0[28][28][32];
		float output_maxpool1[12][12][64];
		float output_maxpool2[4][4][128];
		float flatten[2048];

		//Perform Inference
		//First Conv2d
		conv2d(input, weights_layer0, biases_layer0, (float * )output_layer0);
		//compareMatrix3d(output_layer0, fmap_layer0);
		//Which goes into Conv2d_1
		conv2d(output_layer0, weights_layer1, biases_layer1, (float *) output_layer1);
		//compareMatrix3d(output_layer1, fmap_layer1);

		//Which goes into max pooling
		maxPool2D(output_layer1, (float * )output_maxpool0);
		//compareMatrix3d(output_maxpool0, fmap_maxpool0);
		//Which goes into conv2d_2
		conv2d(output_maxpool0, weights_layer2, biases_layer2, (float *) output_layer2);
		//compareMatrix3d(output_layer2, fmap_layer2);
		//Which goes into conv2d_3
		conv2d(output_layer2, weights_layer3, biases_layer3, (float *) output_layer3);
		//compareMatrix3d(output_layer3, fmap_layer3);
		//which goes into max pooling 1
		maxPool2D(output_layer3, (float * )output_maxpool1);
		// compareMatrix3d(output_maxpool1, fmap_maxpool1);
		//Which goes into conv2d_4
		conv2d(output_maxpool1, weights_layer4, biases_layer4, (float *) output_layer4);
		// compareMatrix3d(output_layer4, fmap_layer4);
		//Which goes into conv2d_5
		conv2d(output_layer4, weights_layer5, biases_layer5, (float *) output_layer5);
		//compareMatrix3d(output_layer5, fmap_layer5);
		//which goes into the final max pooling 2
		maxPool2D(output_layer5, (float * )output_maxpool2);
		// compareMatrix3d(output_maxpool2, fmap_maxpool2);
		//which then is flattened and put through the 2 dense layers
		memcpy(flatten, output_maxpool2, sizeof(float) * 2048);

		denseRelu(flatten, weights_dense0, biases_dense0, (float * )output_dense0);
		// compare1d(output_dense0, fmap_dense0);
		//cout << fmap_dense1[0] << " " << output_dense1[0] << endl;
		//cout << compare1d(output_dense1, fmap_dense1) << endl;
		//comparemax1d(output_dense1, fmap_dense1);
		denseSoftmax(output_dense0, weights_dense1, biases_dense1, (float * )output_dense1);

		
		compare1d(output_dense1, fmap_dense1);
		comparemax1d(output_dense1, fmap_dense1);
}