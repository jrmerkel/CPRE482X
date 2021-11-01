#pragma once

#define BLOCK_SIZE 4


template<int w, int h, int c, int s, int r, int m>
void conv2d(float (&input_tensor)[c][w][h], float (&weights)[m][c][r][s], float (&biases)[m], float * output_tensor) 
{

	//calculate P and Q which is the resulting size (we are using U = 1)
	int p = h - r + 1;
	int q = w - s + 1;
	//float (&output_tensor_arrform)[p,q,m] = (float*) malloc(m * p * q * sizeof(float));
	float matrix_output[m][p][q];
	memset( matrix_output, 0, p*q*m*sizeof(float) );
    //cout << "matrix output dim " << p << q << m << endl;
	// o[n][m][p][q] = sumc sum r sums i[n][c][p+r][q+s] * f[m][c][r][s] + b[m]
	//where n = 1
    
    
	for(int i = 0; i < c; i+=BLOCK_SIZE)////////////s = k
				{
	for(int x = 0; x < m; x+=BLOCK_SIZE)////////////////////////q = z
	{
		
	for(int z = 0; z < q; z+=BLOCK_SIZE) ///////////////////////////////m = x
		{
			
			
		for(int y = 0; y < p; y+=BLOCK_SIZE)////////////////////////////p = y
				{
				
					for(int j = 0; j < r; j+=BLOCK_SIZE)////////////////r = j
											{
				for(int k = 0; k < s; k+=BLOCK_SIZE)////////////////////c = i
					{		
						for(int zz =z; zz<min(q, z+BLOCK_SIZE); zz++)
						{									
							for(int kk = k; kk < min(k+BLOCK_SIZE, s); kk++)
							{
								for(int jj = j; jj< min(j+BLOCK_SIZE,r); jj++)
								{
										for(int yy =y; yy < min(p, y+BLOCK_SIZE); yy++)
									{
					
											for(int ii = i; ii < min(c,i+BLOCK_SIZE); ii++)
											{
												for(int xx = x; xx < min(m, x+BLOCK_SIZE); xx++)
												{
												//matrix[m][p][q] = i[c][p + r][q + s] * f[m][c][r][s]
												//Ours is not in this exact order
												//Ours is matrix[q][p][m] = i[q + s][p+r][c] * f[m][c][r][s]
													matrix_output[xx][zz][yy] +=  input_tensor[ii][zz + kk][yy+jj] * weights[xx][ii][jj][kk];
												}
											}
										}
									}
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
				matrix_output[x][z][y]   += biases[x];
				//activation function relu if negative then 0
				if(matrix_output[x][z][y]  < 0)
				{
					matrix_output[x][z][y]   = 0;
				} 
			}
		}
	}
	
//ck array into output tensor pointer
	memcpy(output_tensor, matrix_output, sizeof(float) * m * p * q);
}