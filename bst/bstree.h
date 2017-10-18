#ifndef bintree_included
#define bintree_included

/* a pointer to Treenode */
typedef struct tnode *Treeptr;

/* */
//#define NAME_SIZE 40

/* a binary tree node */
typedef struct tnode {
  char *name;

  Treeptr left;
  Treeptr right;
} Treenode;

/* allocates space for a Treenode */
Treeptr tAlloc();

/* creates a new node with name */
Treeptr tNewNode(char *name);

/* free memory associated with a Treenode, discarding items it contains */
void tFree(Treeptr tp);

/* insert a new leaf to the Tree sorted by lastname */
Treeptr tInsert(Treeptr tp, char *name);

/* removes a node from the tree */
Treeptr tRemove(Treeptr root, char *name);

/* prints all of the members of tree */
void treePrint(Treeptr tp);

/* uses fputs to write names to a file in pre: order fasion*/
void tPrintFile(Treeptr root, FILE *fp);

/* writes the current tree to a file */
void tWrite(Treeptr, char *filename);

/* builds a bst from a file */
Treeptr tRead(char *filename);

/* frees all nodes from a tree discarding items they contained */
void tRemoveAll(Treeptr root);

#endif /* included */ 
