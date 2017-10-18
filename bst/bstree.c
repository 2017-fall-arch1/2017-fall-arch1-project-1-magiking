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
  printf("\nEntering tNewNode. Calling tAlloc()...\n"); 
  Treeptr tp = tAlloc();
  printf("assigning %s to new node.\n", name); 
  tp->name = name;
  //tp->name = strcpy(tp->name, name); // seg fault here...
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
  printf("\nInserting %s into tree...\n", name); 

  if(tp == NULL){
    return tNewNode(name);
  }

  if(strcmp(tp->name, name) < 0){
    return tInsert(tp->left, name);
  }
  else {
    return tInsert(tp->right, name);
  }
  return tp;
   
}

Treeptr tRemove(Treeptr root, char *name){
  /* Printing action */
  
  printf("\nRemoving %s from tree...\n", name); 
  if(root == NULL){
    return NULL;
  }
 
  /* find node */ 
  int res = strcmp(root->name, name); 
  Treeptr promotee;
  
  if(res < 0){        // need to check root->left for match
    printf("\t%s to left of current node, calling remove on left child.\n", name);
    root->left = tRemove(root->left, name);
  }
  else if (res > 0){ // need to check root->right for match
    printf("\t%s to right of current node, calling remove on right child.\n", name);
    root->right =  tRemove(root->right, name);
    printf("\troot->right ptr after calling remove on right child: %s\n",root->right); 
  }
  else{                                                                          //find node for promoting to current position
    printf("\t%s is name of current node. Finding child to promote.\n", name);
    if(root->left == NULL){                                                      // promote right node
      printf("\t\tLeft child is null. Promoting right child. \n");
                                                                                 //printf("right child pointer: %s\n", root->right);
      promotee = root->right;
      printf("\t\tpromotee pointer after getting root->right: %s\n", promotee);
      tFree(root);
      root = promotee;                                                          
      printf("\t\troot pointer after getting promotee: %s\n", root);
      //return root;


    }
    else if(root->right == NULL){
      printf("\t\tRight child is null. Promoting left child. \n");
      promotee = root->left;
      tFree(root);
      root = promotee;
      //return root;
    }
    else{ // find promotee using in-order traversal
      Treeptr prev = NULL;
      promotee = root->right;

      while(promotee->left){
	prev = promotee;
	promotee = promotee->left;
      }
      root->name = promotee->name; // promote node to present
      //strcpy(root->name, promotee->name);
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
  /*Treeptr tPrint(){
    printf("tPrint\n"); 
    }*/
void treePrint(Treeptr tp){
  if(tp){ // tp != NULL
    printf("%s\n", tp->name); 
    printf("calling treePrint on left\n");
    treePrint(tp->left);
    printf("calling treePrint on right\n");
    treePrint(tp->right);
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
  Treeptr root;
  FILE *fp;
  fp = fopen(filename, "r");
  char *line;
 
  while(fgets(line, 30, fp)){
    root = tInsert(root, line);
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
