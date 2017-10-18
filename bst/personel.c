# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "personel.h"
# include "bstree.h"

# define MAX_LINE 150


int main(){
  Treeptr root;
  char filename[MAX_LINE];
  char line[MAX_LINE];
  printf("please give a filename to load from: ");
  if(fgets(line, MAX_LINE, stdin)){
    strcpy(filename, line);
  }
  int action = manage(root);
  if(action == 4){
    printf("Saving...\n");
    tWrite(root, filename);
  }
  tRemoveAll(root); 
}

int manage(Treeptr root){
  char buf[NAME_SIZE]
  int response = getResponse(); 
  while(response != 4){
    switch(response){

    case 1: // print names
      printf("Printing names in tree\n");
      tPrint(root);
      break;
    case 2: // insert name
      root = tInsert(root, getName(buf));
      break;
    case 3: // remove name
      root = tRemove(root, getName(buf));
      break;
    case 4: // save & quit
      return response;
    case 5: // quit without saving tree
      return response;
    default:
      printf("That wasn't an option. Please try again.\n");
    }
    response = getResponse();
  }
  return 0;
}

int getResponse(){
  char line[MAX_LINE];
  int selection;
  printf("1:print names 2:insert new name 3:remove a name 4:save changes and quit 5: quit\n");
  printf("Select an option(1-5): ");
  if(fgets(line, MAX_LINE, stdin)){
    if(selection = atoi(line))
      return selection;
  }
  return 0;
}

char *getName(char *buf){
   char line[NAME_SIZE];
   printf("Please specify a name(max 30 characters): ");
   if(fgets(line, NAME_SIZE, stdin)){
      return selection;
  } 
}
