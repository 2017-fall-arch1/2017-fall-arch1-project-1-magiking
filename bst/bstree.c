#include <stdio.h>
#include <string.h> // that string library
#include <stdlib.h> // the malloc one
#include "bstree.h"


/* allocates space for a Treenode */
Treeptr tAlloc(){
  /* Printing action */
  Treeptr tp = (Treeptr) malloc(sizeof(Treenode));
  if(tp == NULL){
    printf("out of memory, tAlloc\n");
  }
  return tp;
}

/* creates a new node with name, gets space using tAlloc */
Treeptr tNewNode(char *name){
  /* Printing action */
  //printf("\nEntering tNewNode. Calling tAlloc()...\n"); 
  Treeptr tp = tAlloc();
  strcpy(tp->name, name); // seg fault here...
  tp->left = NULL;
  tp->right = NULL;
  return tp;
}

/* frees space associsted with a Treenode */
void tFree(Treeptr tp){
  /* Printing action */
  free(tp);
}

Treeptr tInsert(Treeptr tp, char *name){
  /* Printing action */
  //printf("\nInserting %s into tree...\n", name); 

  if(tp == NULL){
    return tNewNode(name);
  }

  if(strcmp(tp->name, name) < 0){
     
    tp->left = tInsert(tp->left, name);
  }
  else {
    tp->right = tInsert(tp->right, name);
  }
  return tp;
   
}

Treeptr tRemove(Treeptr root, char *name){
  /* Printing action */
  
  //printf("\nRemoving %s from tree...\n", name); 
  if(root == NULL){
    return NULL;
  }
 
  /* find node */ 
  int res = strcmp(name, root->name); 
  Treeptr promotee;
  
  if(res < 0){        
    root->left = tRemove(root->left, name);
  }
  else if (res > 0){ 
    root->right =  tRemove(root->right, name);
  }
  else{                                                                          //find node for promoting to current position
    if(root->left == NULL){                                                      // promote right node 
      promotee = root->right;  
      tFree(root);
      root = promotee;                                                          
   
    


    }
    else if(root->right == NULL){
      
      promotee = root->left;
      tFree(root);
      root = promotee;
     
    }
    else{ // find promotee using in-order traversal
      Treeptr prev = NULL;
      promotee = root->right;

      while(promotee->left){
	prev = promotee;
	promotee = promotee->left;
      }
      strcpy(root->name, promotee->name);
      if(prev){ // remove promoted node from other location
        prev->left = tRemove(prev->left, prev->left->name);
      }
      else{
	root->right = tRemove(root->right, root->right->name);
      } 
    }
  }
  return root;
}

/* Prints all names in the tree */
void tPrint(Treeptr tp){
  if(tp){ // tp != NULL
    printf("%s\n", tp->name); 
    tPrint(tp->left);
    tPrint(tp->right);
  }
} 
/* uses fputs to write names to a file in pre: order fasion*/
void tPrintFile(Treeptr root, FILE *fp){
  if(root){
    fputs(root->name, fp);
    tPrintFile(root->left, fp);
    tPrintFile(root->right, fp);
  }
}

/* writes the current tree to a file */
void tWrite(Treeptr root, char *filename){
  FILE *fp;
  fp = fopen(filename, "w");
  tPrintFile(root, fp); 
  fclose(fp);
}
   
/* builds a bst from a file */
Treeptr tRead(char *filename){
  printf("Reading %s\n", filename);
  Treeptr root = NULL;
  FILE *fp;
  fp = fopen(filename, "r");
  if(fp == NULL){
    printf("\tcan't open %s\n", filename);
  }
  char name[MAX_NAME];
 
  while(fgets(name, MAX_NAME, fp)){
    root = tInsert(root, name);
  }

  fclose(fp);
  return root;
}

/* Removes all nodes from a tree */
void tRemoveAll(Treeptr root){
  if(root){
    tRemoveAll(root->left);
    tRemoveAll(root->right);
    tFree(root); 
  }
  //return root;
}
