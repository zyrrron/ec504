

        #ifndef _Tree_H
        #define _Tree_H

        typedef int ElementType;
	typedef int HeightType;


        struct TreeNode;
        typedef struct TreeNode *Position;
        typedef struct TreeNode *SearchTree;

        SearchTree MakeEmpty( SearchTree T );
	HeightType CalculateHeight(SearchTree T);
	HeightType Height(SearchTree T);
        Position Find( ElementType X, SearchTree T );
        Position FindMin( SearchTree T );
        Position FindMax( SearchTree T );
        SearchTree Insert( ElementType X, SearchTree T );
        SearchTree Delete( ElementType X, SearchTree T );
        ElementType Retrieve( Position P );

        #endif  /* _Tree_H */


