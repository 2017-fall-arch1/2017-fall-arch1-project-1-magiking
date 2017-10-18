#include <stdio.h>
#include <string.h> // that string library
#include <stdlib.h> // the malloc one
#include "bstree.h"

int main(){
  
  //printf("demo, making node");
  Treeptr proot = tRead("./demo.bst");
  printf("\nPrinting tree\n"); 
  tPrint(proot);

  proot = tInsert(proot, "Lincoln Barnes\n"); 

  printf("\nPrinting tree\n"); 
  tPrint(proot);

  printf("\nwriting to file\n");
  tWrite(proot, "write_demo.bst");

  printf("\nnremoving all nodes\n");
  tRemoveAll(proot);
  
  
}
