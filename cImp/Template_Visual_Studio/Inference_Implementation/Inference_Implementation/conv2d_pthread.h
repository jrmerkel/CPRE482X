#pragma once

#define NUM_THREADS 2

float * g_input_tensor;
float * g_weights;
float * g_biases;
float * g_matrix_output;
void * thread_subroutine(void* arg);
struct arg_struct
{
	int w;
	int h;
	int c;
	int s;
	int r;
	int m;
	int p;
	int q;
};

template<int w, int h, int c, int s, int r, int m>
void conv2d(float (&input_tensor)[w][h][c], float (&weights)[s][r][c][m], float (&biases)[m], float * output_tensor) 
{
	//calculate P and Q which is the resulting size (we are using U = 1)
	int p = h - r + 1;
	int q = w - s + 1;
	//float (&output_tensor_arrform)[p,q,m] = (float*) malloc(m * p * q * sizeof(float));
	float matrix_output[p][q][m];
	g_matrix_output = (float *) matrix_output;
    cout << "matrix output dim " << p << q << m << endl;

	pthread_t threads[NUM_THREADS];

	arg_struct args;

	args.w = w;
	args.h = h;
	args.c = c;
	args.s = s;
	args.r = r;
	args.m = m;
	args.p = p;
	args.q = q;

	g_input_tensor = (float *)input_tensor;
	g_weights = (float *)weights;
	g_biases = (float *)biases;

	for(int i = 0; i < NUM_THREADS; i++)
	{
		pthread_create(&threads[i], NULL, thread_subroutine, (void *) &args);
	}




	//copy stack array into output tensor pointer
	memcpy(output_tensor, matrix_output, sizeof(float) * m * p * q);
}

void * thread_subroutine(void* arg)
{
	arg_struct * dims = (arg_struct *) arg;

	float t_matrix_output
	// o[n][m][p][q] = sumc sum r sums i[n][c][p+r][q+s] * f[m][c][r][s] + b[m]
	//where n = 1
    //TODO stretch Fix the loop orderings but don't touch atm it works LMAO
	for(int x = 0; x < dims->m; x++) ///////////////////////////////m = x
	{
		for(int y = 0; y < dims->p; y++)////////////////////////////p = y
		{
			for(int z = 0; z < dims->q; z++)////////////////////////q = z
			{
				((float [dims->p][dims->q][dims->m])g_matrix_output)[z][y][x]  = 0;
				for(int i = 0; i < dims->c; i++)////////////////////c = i
				{
					for(int j = 0; j < dims->r; j++)////////////////r = j
					{
						for(int k = 0; k < dims->s; k++)////////////s = k
						{
							//matrix[m][p][q] = i[c][p + r][q + s] * f[m][c][r][s]
                            //Ours is not in this exact order
                            //Ours is matrix[m][p][q] = i[q + s][p+r][c] * f[s][r][c][m]
                            //matrix_output[z][y][x] +=  input_tensor[z + k][y+j][i] * weights[k][j][i][x];
                        }
					}
				}
				//Add bias
				//matrix_output[z][y][x]   += biases[x];
				//activation function relu if negative then 0
				// if(matrix_output[z][y][x]  < 0)
				// {
				// 	matrix_output[z][y][x]   = 0;
				// } 
			}
		}
	}
}