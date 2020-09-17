#include <stdio.h>
#include <stdlib.h>

typedef unsigned long int INT; 

int fact(int n){
  /*
     Function: fact (n)
     Returns: n!
  */

 
  INT p = 1;

  for (int i=1; i <= n ; ++i){
    p = p * i;
  }
  return p;

}

int main(){
  int n;

  for(n = 1;n < 25 ; n++)
  printf ("%d ! = %d \n", n, fact(n));

  
  return 0;
}

