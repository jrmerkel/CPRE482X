#pragma once
template<int w, int h, int c>
//Pooling is 2x2
void maxPool2D(float (&input_tensor)[w][h][c], float * output_tensor) 
{
//input terms
	//calculate P and Q which is the resulting size (we are using U = 2 this time)
    int U = 2; // incase this ever changes
    int r = U;
    int s = U;
	int p = (h - r + 2)/2;
	int q = (w - s + 2)/2;
	//float (&output_tensor_arrform)[p,q,m] = (float*) malloc(m * p * q * sizeof(float));
	float matrix_output[p][q][c];
    cout << "matrix pool output dim " << p << q << c << endl;
	// o[n][m][p][q] = sumc sum r sums i[n][c][p+r][q+s] * f[m][c][r][s] + b[m]
	//where n = 1
    //TODO stretch Fix the loop orderings but don't touch atm it works LMAO
	for(int x = 0; x < c; x++) ///////////////////////////////m = x
	{
		for(int y = 0; y < p; y++)////////////////////////////p = y
		{
			for(int z = 0; z < q; z++)////////////////////////q = z
			{
				matrix_output[z][y][x]  = input_tensor[U*z][U*y][x];

                for(int j = 0; j < r; j++)////////////////r = j
                {
                    for(int k = 0; k < s; k++)////////////s = k
                    {
                        //matrix[m][p][q] = i[c][Up + r][Uq + s] * f[m][c][r][s]
                        //Ours is not in this exact order
                        //Ours is matrix[m][p][q] = i[q + s][p+r][c] * f[s][r][c][m]
                        if(input_tensor[U*z + k][U*y+j][x] > matrix_output[z][y][x])
                        {
                            matrix_output[z][y][x] =  input_tensor[U*z + k][U*y+j][x];
                        }
                    }
                }
            
			}
		}
	}

	//copy stack array into output tensor pointer
	memcpy(output_tensor, matrix_output, sizeof(float) * c * p * q);
}