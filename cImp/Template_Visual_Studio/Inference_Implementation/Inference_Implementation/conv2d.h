#pragma once
template<int w, int h, int c, int s, int r, int m>
void conv2d(float (&input_tensor)[w][h][c], float (&weights)[s][r][c][m], float (&biases)[m], float * output_tensor) 
{

	//calculate P and Q which is the resulting size (we are using U = 1)
	int p = h - r + 1;
	int q = w - s + 1;
	//float (&output_tensor_arrform)[p,q,m] = (float*) malloc(m * p * q * sizeof(float));
	float matrix_output[p][q][m];
    cout << "matrix output dim " << p << q << m << endl;
	// o[n][m][p][q] = sumc sum r sums i[n][c][p+r][q+s] * f[m][c][r][s] + b[m]
	//where n = 1
    //TODO stretch Fix the loop orderings but don't touch atm it works LMAO
	for(int x = 0; x < m; x++) ///////////////////////////////m = x
	{
		for(int y = 0; y < p; y++)////////////////////////////p = y
		{
			for(int z = 0; z < q; z++)////////////////////////q = z
			{
				matrix_output[z][y][x]  = 0;
				for(int i = 0; i < c; i++)////////////////////c = i
				{
					for(int j = 0; j < r; j++)////////////////r = j
					{
						for(int k = 0; k < s; k++)////////////s = k
						{
							//matrix[m][p][q] = i[c][p + r][q + s] * f[m][c][r][s]
                            //Ours is not in this exact order
                            //Ours is matrix[m][p][q] = i[q + s][p+r][c] * f[s][r][c][m]
                            matrix_output[z][y][x] +=  input_tensor[z + k][y+j][i] * weights[k][j][i][x];
                        }
					}
				}
				//Add bias
				matrix_output[z][y][x]   += biases[x];
				//activation function relu if negative then 0
				if(matrix_output[z][y][x]  < 0)
				{
					matrix_output[z][y][x]   = 0;
				} 
			}
		}
	}

	//copy stack array into output tensor pointer
	memcpy(output_tensor, matrix_output, sizeof(float) * m * p * q);
}