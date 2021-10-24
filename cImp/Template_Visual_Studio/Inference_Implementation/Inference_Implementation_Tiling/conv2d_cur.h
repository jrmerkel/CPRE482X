#pragma once

#define BLOCK_SIZE 8


template<int w, int h, int c, int s, int r, int m>
void conv2d(float (&input_tensor)[w][h][c], float (&weights)[s][r][c][m], float (&biases)[m], float * output_tensor) 
{

	//calculate P and Q which is the resulting size (we are using U = 1)
	int p = h - r + 1;
	int q = w - s + 1;
	//float (&output_tensor_arrform)[p,q,m] = (float*) malloc(m * p * q * sizeof(float));
	float matrix_output[p][q][m];
	memset( matrix_output, 0, p*q*m*sizeof(float) );
    //cout << "matrix output dim " << p << q << m << endl;
	// o[n][m][p][q] = sumc sum r sums i[n][c][p+r][q+s] * f[m][c][r][s] + b[m]
	//where n = 1

	for(int z = 0; z < q; z+=BLOCK_SIZE) ///////////////////////////////m = x
	{
		for(int y = 0; y < p; y+=BLOCK_SIZE)////////////////////////////p = y
		{
			for(int x = 0; x < m; x+=BLOCK_SIZE)////////////////////////q = z
			{
				for(int k = 0; k < s; k++)////////////////////c = i
				{
					for(int j = 0; j < r; j++)////////////////r = j
					{
						for(int i = 0; i < c; i+=BLOCK_SIZE)////////////s = k
						{
																
								// for(int kk = k; kk < min(k+BLOCK_SIZE, s); kk++)
								// {
								// 	for(int jj = j; jj< min(j+BLOCK_SIZE,r); jj++)
								// 	{
									for(int xx = x; xx < min(m, x+BLOCK_SIZE); xx++)
												{
										for(int yy = y; yy < min(p, y+BLOCK_SIZE); yy++)
										{
											
											for(int ii = i; ii < min(c,i+BLOCK_SIZE); ii++)
											{
												
												for(int zz =z; zz<min(q, z+BLOCK_SIZE); zz++)
											{
												//matrix[m][p][q] = i[c][p + r][q + s] * f[m][c][r][s]
												//Ours is not in this exact order
												//Ours is matrix[m][p][q] = i[q + s][p+r][c] * f[s][r][c][m]
													matrix_output[zz][yy][xx] +=  input_tensor[zz + k][yy+j][ii] * weights[k][j][ii][xx];
												}
											}
									// 	}
									// }
								}
							}

						}
					}
				}
			}
		}
	}
	for(int z = 0; z < q; z++)
	{
		for(int y = 0; y < p; y++)
		{
			for(int x = 0; x < m; x++)
			{
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
	
//ck array into output tensor pointer
	memcpy(output_tensor, matrix_output, sizeof(float) * m * p * q);
}