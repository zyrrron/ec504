#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

struct TreeNode
{
  HeightType Height;
  ElementType Element;
  SearchTree  Left;
  SearchTree  Right;
};

SearchTree MakeEmpty( SearchTree T )
{
  if( T != NULL )
    {
      MakeEmpty( T->Left );
      MakeEmpty( T->Right );
      free( T );
    }
  return NULL;
}

Position Find( ElementType X, SearchTree T )
{
  if( T == NULL )
    return NULL;
  if( X < T->Element )
    return Find( X, T->Left );
  else
    if( X > T->Element )
      return Find( X, T->Right );
    else
      return T;
}

Position FindMin( SearchTree T )
{
  if( T == NULL )
    return NULL;
  else
    if( T->Left == NULL )
      return T;
    else
      return FindMin( T->Left );
}

Position FindMax( SearchTree T )
{
  if( T != NULL )
    while( T->Right != NULL )
      T = T->Right;
  
  return T;
}



SearchTree Insert( ElementType X, SearchTree T )
{
  if( T == NULL )
    {
      /* Create and return a one-node tree */
      T = (SearchTree) malloc( sizeof( struct TreeNode ) );
      if( T == NULL )
	printf( "Out of space!!!" );
      else
	{
	  T->Element = X;
	  T->Left = T->Right = NULL;
	  T->Height = 0;
	}
    }
  else
    //(* Change to < than or = rule *)
    //  if( X < T->Element )   //
     if( X <= T->Element )
      T->Left = Insert( X, T->Left );
    else
      if( X > T->Element )
	T->Right = Insert( X, T->Right );
  /* Else X is in the tree already; we'll do nothing */
  CalculateHeight(T); 
  return T; 
}

SearchTree Delete( ElementType X, SearchTree T )
{
  Position TmpCell;
  
  if( T == NULL )
    printf( "Element not found" );
  else
    if( X < T->Element )  /* Go left */
      T->Left = Delete( X, T->Left );
    else
      if( X > T->Element )  /* Go right */
	T->Right = Delete( X, T->Right );
      else  /* Found element to be deleted */
	if( T->Left && T->Right )  /* Two children */
	  {
	    /* Replace with smallest in right subtree */
	    TmpCell = FindMin( T->Right );
	    T->Element = TmpCell->Element;
	    T->Right = Delete( T->Element, T->Right );
	  }
	else  /* One or zero children */
	  {
	    TmpCell = T;
	    if( T->Left == NULL ) /* Also handles 0 children */
	      T = T->Right;
	    else if( T->Right == NULL )
	      T = T->Left;
	    free( TmpCell );
	  }
  CalculateHeight(T); 
  return T;
}

ElementType Retrieve( Position P )
{
  return P->Element;
}

HeightType CalculateHeight(SearchTree T){
	if(T != NULL){
		if(T->Left == NULL && T->Right == NULL){
			T->Height = 0;
		} else if(T->Left == NULL){
			T->Height = T->Right->Height +1;
		} else if(T->Right == NULL) {
			T->Height = T->Left->Height+1;
		} else{
			T->Height = T->Left->Height >= T->Right->Height ? T->Left->Height+1 : T->Right->Height+1;
		}
		return T->Height;
	} else {
		return 0;
	}
}

HeightType Height(SearchTree T){
	if(T == NULL) { 
		return 0;
	} else {
		return T->Height;
	}
}