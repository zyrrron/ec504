
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
using namespace std;

void initialize_and_permute(int permutation[], int n)
{
  int i;
    for (i = 0; i < n-1; i++) {
        int j = i+ (rand()%(n-i));
        swap(permutation[i], permutation[j]);
    }
}

int main(int argc, char *argv[]){

	int*  sizes = new int[10];
	int * heights = new int[10];
        double * AvHeights = new double[10];
	sizes[0] = 8;
	SearchTree T;
	for(int i = 1;i<10;i++)  sizes[i] = sizes[i-1]*2;	
	for(int i = 0;i<10;i++){	
		int n = sizes[i];
      		int * IL = new int[n+1];
      		IL[0] = n;  // Set zero entry in in heap to n
      		for(int j=1; j<n+1 ; j++){
			IL[j] = rand()%100000;
		}
		for(int j=0;j<10;j++){
			T = MakeEmpty(NULL);
			initialize_and_permute(IL,n);				
      			for(int k=1; k<n+1 ; k++){
				T = Insert(IL[k] , T);
			}
			heights[i] = heights[i] + Height(T);
		}
		AvHeights[i] = heights[i] / (double) 10;
		cout << heights[i] << endl;
	}
	for (int i = 0; i < 10; i++) cout << "size" << sizes[i] << " height " << AvHeights[i] << endl; 
}

