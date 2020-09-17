/******************************************************
Long integers multiplicaton with N digits (or bits)  is O(N^2) fundamental 
multiplies  Standard arbitrary precison Long multply.
Devide and conqure can beat this with T(N) = 3 T(N/2) + 3 N 

see https://gmplib.org

****************************************************/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "print_int_types.h"

typedef unsigned long int INT; 
using namespace std;

INT prodRec(INT x, INT  y, INT base);

int main(void) {
  INT x =  76120582,  y  =  92635911; 
  INT xl, xh ,yl, yh;
  INT base = 1000;
  INT max_base = 4294967296;  // max int is 4294967296 -1 = 2**32 -1
  
  // Normal Unsigned Long Multiplication O(N^2) multiplies
  
  INT product = x*y;
  cout<<" product "<< product << endl  << endl;
  
  //  Devide and Conquer:  Split into two of half size integers
  xl = x % base;
  xh = x / base;
  yl = y % base;
  yh = y / base;
  
  // Still only break even: still O(N^2)!  T(N) = 4 T(N/2) + 4
  //  One step 4 multipies
  INT  xh_yh = xh*yh;
  INT  xh_yl = xh*yl;
  INT  xl_yh = xl*yh;
  INT  xl_yl = xl*yl;
  
  INT prod_break_even = base*base*xh_yh +  base* (xl_yh + xh_yl) +  xl_yl;
  cout<<" prod_break_even " <<  prod_break_even << endl  << endl;
  
  //With only 3 multiplies not 4 Now  T(N) = 3 T(N/2) + 3 N  recursively.
  //  One step 3 multiplies
  
  INT xy_sqr =  (xh + xl) * (yh + yl);
   
  INT product_div_and_conq =  base*(base -1)*xh_yh  +  base*xy_sqr +  xl_yl*(1 - base);
  cout<<" product_div_and_conq "<< product_div_and_conq << endl  << endl;
  
  INT recursive_product =  prodRec(x,  y, max_base);
  cout<<"  recursive_product "<<  recursive_product << endl  << endl;
  
  // print_int_types(); Can uncomment to see standard for integers
  
  return 0;
}

INT prodRec(INT x, INT y, INT base)
{
  // cout << "  base into prodRec " << base << endl << endl;
  if(base == 1) return x*y;
  base = sqrt(base);
  int xl = x % base;
  int xh = x / base;
  int yl = y % base;
  int yh = y / base;
  
  // Exercise reduce  4 products to 3 products 
  int xh_yh = prodRec (xh,yh,base);
  int xh_yl = prodRec (xh,yl,base);
  int xl_yh = prodRec (xl,yh,base);
  int xl_yl = prodRec (xl,yl,base);
  
  return base*base*xh_yh + base*(xh_yl + xl_yh) + xl_yl; 
}
  
