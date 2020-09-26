#include<iostream>
#include<iomanip>
#include <cstdlib> 
#include <time.h>
#include <math.h>
#include "sorting.h"
using namespace std;

#define Debug 0

// Debugging routine: (should be in separate test.cpp)
void printArray(int a[], int N)
{ 
  cout << N << "\n";
  for(int i = 0;i<N;i++)
    cout << a[i] << "\n";
}

int main()
{
  
  // Put loop around N to make data for scaling  
  int N = 10000;
  int a[N];
  int a_save[N];
  int a_tmp[N];

  srand(137); // fixes intial seed 
  // Choose a random list of N integers.
  for(int i = 0;i<N;i++) 
    a[i] = (rand() +1)%1000000  ;
  
#if Debug
   cout <<" Unsorted Array " << endl;
   Debug  printArray(a, N);
#endif
  
  
  int Ncases = 2;  // re_ordering list
  
  for(int j = 0; j < Ncases; j++)
    {
      
     for(int i = 0;i<N;i++) a_save[i] = a[i]; // keep random array
     
     //Test insertionSort     
     swapCount = 0;
     insertionsort(a, N);
     cout << "Case = " << j << "  insertionSort swapCount " << swapCount << endl;

#if Debug
     Debug  printArray(a, N);
#endif
     
     
     //Test mergeSort
     swapCount = 0;
     for(int i = 0;i<N;i++) a[i] = a_save[i];
     mergeSort(a,  a_tmp, 0, N-1);
     cout << "Case = " << j << " Merge  swapCount " << swapCount << endl;

#if Debug
     Debug  printArray(a, N);
#endif
     
     //Test quickSort
     swapCount = 0;
     for(int i = 0;i<N;i++) a[i] = a_save[i];
     quicksort(a, 0,N-1);
     cout << "Case = " << j << " Quick  swapCount " << swapCount << endl;

#if Debug
     Debug  printArray(a, N);
#endif
     
     //Test shellSort
     swapCount = 0;
     for(int i = 0;i<N;i++) a[i] = a_save[i];
     shellsort(a,N);
     cout << "Case = " << j << " Shell Sort  swapCount " << swapCount << endl;

#if Debug
     Debug  printArray(a, N);
#endif
     
     // Get new permutation of random array.
     for(int i = 0;i<N;i++) a[i] = a_save[i];
     initialize_and_permute(a , N);
    
#if Debug
      cout << "Permuted Array " << endl;
     Debug  printArray(a, N);
#endif
    }
  
 
 return 0;
}
