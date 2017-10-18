#include <stdio.h>
#include <string.h> // for strcmp and strcpy
#include <stdlib.h> // for malloc
#include "bstree.h"

int main(){
  
  //printf("demo, making node");
  Treeptr proot = tRead("./demo.bst");
  printf("\nPrinting tree\n"); 
  tPrint(proot);

  printf("Inserting \"Lincoln Barnes\" into tree\n");
  proot = tInsert(proot, "Lincoln Barnes\n"); 

  printf("\nPrinting tree\n"); 
  tPrint(proot);

  printf("\nwriting to file\n");
  tWrite(proot, "write_demo.bst");

  printf("\nFreeing up used memory\n");
  tRemoveAll(proot); 
  printf("Done.\n");

}
