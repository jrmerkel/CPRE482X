#pragma once

#define NUM_THREADS 32

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
	int id;
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
    //cout << "matrix output dim " << p << q << m << endl;

	pthread_t threads[NUM_THREADS];

	arg_struct args[NUM_THREADS];

	g_input_tensor = (float *)input_tensor;
	g_weights = (float *)weights;
	g_biases = (float *)biases;

	for(int i = 0; i < NUM_THREADS; i++)
	{
		
		args[i].w = w;
		args[i].h = h;
		args[i].c = c;
		args[i].s = s;
		args[i].r = r;
		args[i].m = m;
		args[i].p = p;
		args[i].q = q;
		args[i].id = i;
		pthread_create(&threads[i], NULL, thread_subroutine, (void *) &args[i]);
		//cout << threads[i] << endl;
	}

	for(int i = 0; i < NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}


	//copy stack array into output tensor pointer
	memcpy(output_tensor, matrix_output, sizeof(float) * m * p * q);
}

void * thread_subroutine(void* arg)
{
	//cout << "HERE " << endl;
	arg_struct * dims = (arg_struct *) arg;
	float (*t_matrix_output)[dims->p][dims->q][dims->m]  = (float (*)[dims->p][dims->q][dims->m]) (g_matrix_output);

	float (*t_input_tensor)[dims->w][dims->h][dims->c]  = (float (*)[dims->w][dims->h][dims->c]) g_input_tensor;
	float (*t_weights)[dims->s][dims->r][dims->c][dims->m]  = (float (*)[dims->s][dims->r][dims->c][dims->m]) g_weights;
	int id = dims->id;
	// o[n][m][p][q] = sumc sum r sums i[n][c][p+r][q+s] * f[m][c][r][s] + b[m]
	//where n = 1
	for(int x = (id*dims->m / NUM_THREADS); x < ((id+1)*dims->m / NUM_THREADS); x++) ///////////////////////////////m = x
	{
		for(int y = 0; y < dims->p; y++)////////////////////////////p = y
		{
			for(int z = 0; z < dims->q; z++)////////////////////////q = z
			{
				//cout << &(*t_matrix_output)[z][y][x] << endl;
				(*t_matrix_output)[z][y][x]  = 0;
				for(int i = 0; i < dims->c; i++)////////////////////c = i
				{
					for(int j = 0; j < dims->r; j++)////////////////r = j
					{
						for(int k = 0; k < dims->s; k++)////////////s = k
						{
							//matrix[m][p][q] = i[c][p + r][q + s] * f[m][c][r][s]
                            //Ours is not in this exact order
                            //Ours is matrix[m][p][q] = i[q + s][p+r][c] * f[s][r][c][m]
							(*t_matrix_output)[z][y][x] +=  (*t_input_tensor)[z + k][y+j][i] * (*t_weights)[k][j][i][x];
                        }
					}
				}
				//Add bias
				(*t_matrix_output)[z][y][x]   += g_biases[x];
				//activation function relu if negative then 0
				if((*t_matrix_output)[z][y][x]  < 0)
				{
					(*t_matrix_output)[z][y][x]   = 0;
				} 
			}
		}
	}
	return NULL;
}