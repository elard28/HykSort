#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#include <omp.h>
 
#define SIZE 10

int A[SIZE];
int B[SIZE];
MPI_Comm comm;
int p;
int N=SIZE;
int n;
int k;
int s;
int tw;
int ts;
int tc;
int pr;
int Ar[SIZE];
int Mrs;
int partner;

int main(int argc, char const *argv[])
{
  	int m=k/p;

  	MPI_Init(NULL, NULL);
  	MPI_Comm_size(comm, &p);
  	MPI_Comm_rank(comm, &partner);

  	n=N/p;

  	if(p>1)
  	{
  		MPI_Allreduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, comm);


  		int color = k*pr/p;
  		MPI_Request R[k];
  		#pragma parallel for
  		for (int i = 0; i < k; ++i)
  		{
  			//MPI_Request 
  			int precv=m*((color-i)%k)+(pr%m);
  			MPI_Irecv(B, N, MPI_INT, , , comm, &R[i])
  		}

  		for (int i = 0; i < k; ++i)
  		{
  			int precv=m*((color-i)%k)+(pr%m);
  			int psend=m*((color+i)%k)+(pr%m);
  			MPI_Isend(B,N,MPI_INT,psend,comm);

  			j=2;
  			while(i>0 && i%j==0)
  			{

  				j=2*j
  			}
  			MPI_WaitRecv();
  		}
  		MPI_WaitAll();

  		MPI_Comm_split(comm,color,partner,comm);
  		pr=MPI_Comm_rank(comm,partner);
  	}

  	MPI_Finalize();

	return 0;
}