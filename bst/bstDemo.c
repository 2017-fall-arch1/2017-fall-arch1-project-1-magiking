#include <stdio.h>
#include <string.h> // that string library
#include <stdlib.h> // the malloc one
#include "bstree.h"

int main(){
  // create a new tre with one element and remove it? 
  //printf("demo, making node");
  Treeptr proot = tNewNode("John Smith");
  proot = tInsert(proot, "Alice Doe"); 
  printf("\nPrinting tree\n"); 
  treePrint(proot);
  proot = tRemove(proot, "Alice Doe");
  printf("\nPrinting tree\n"); 
  printf("\name: %s leftchild ptr:%s right child ptr: %s\n", proot->name, proot->left, proot->right);
  treePrint(proot);
  proot = tRemove(proot, proot->name); 
  //printf("Printing name at root: %s\n", proot->name);  
  
}
