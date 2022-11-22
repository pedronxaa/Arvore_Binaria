#include<stdio.h>
#include<stdlib.h>

typedef struct btree{
    int info;
    struct btree* left;
    struct btree* right;
}tree;

tree* create_root(int tinfo){
    tree* origin = (tree*)malloc(sizeof(tree));
    origin -> info = tinfo;
    origin -> left = NULL;
    origin -> right = NULL;
return origin;
}

void tinsert(tree** root, int tinfo){
    //Caso Base
    if((*root)-> right == NULL && (*root)-> left == NULL){
        //Criacao da folha
        tree* new_leaf = (tree*)malloc(sizeof(tree));
        new_leaf -> info = tinfo;
        new_leaf -> left = NULL;
        new_leaf -> right = NULL;

        //Apontando para essa folha
            if((*root) -> info > tinfo){
                (*root) -> left = new_leaf;
        }
            else
                (*root) -> right = new_leaf;
    }

    //Recursao
    else if((*root)->info > tinfo){
        tinsert(&(*root)->left, tinfo);
    }
    else
        tinsert(&(*root)->right, tinfo);


    }

void tprint(tree** root){
    if((*root)->left != NULL)
        tprint(&((*root)->left));
        printf("%d ", (*root)->info);
    if((*root)->right != NULL)
        tprint(&((*root)->right));
}

int main(){
    tree* family = create_root(20);
    tinsert(&family, 30);
    tinsert(&family, 10);
    tprint(&family);





    return 0;
}
