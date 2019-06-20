#include <stdio.h>
#include <stdlib.h>

long seed;
void Initrand () {
    seed = 74755L;   /* constant to long WR*/
}

int Rand () {
    seed = (seed * 1309L + 13849L) & 65535L;  /* constants to long WR*/
    return( (int)seed );     /* typecast back to int WR*/
}

void Bubble(int tam)
{
	int *v = (int*) malloc(sizeof(int) * tam);
	Initrand();

	for(int i = 0; i < tam; i++)
	{
		v[i] = Rand();
	}

	for(int i = 0; i < tam; i++)
	{
		for(int j = i + 1; j < tam; j++)
		{
			if(v[i] < v[j])
			{
				v[i] ^= v[j];
				v[j] ^= v[i];
				v[i] ^= v[j];
			}
		}
	}

	free(v);
}

int main(int argc, char** argv)
{
	Bubble(atoi(argv[1]));
	return 0;
}
