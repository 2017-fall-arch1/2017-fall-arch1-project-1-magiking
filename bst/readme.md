#Project 1
Author: Jake Lasley
email: jlasleu@miners.utep.edu
######I tried to style this with markdown, so hopefully it looks good in Github.
##Demo:
To run the demo, 
-```$make``` to setup
 - Sometimes you need to make twice for linking I think for the linking of the bstree.h or bstree.o.
-```$make demo``` to run demo

##personel:
Personel was supposed to be the interface where a user could specify a file to load, insert/delete a name, and print the tree.
- The skeleton non functioning code for personel is in `personel.c` and `personel.h` and a make option for running it in the makefile.
-The idea was to just read from stdin the user's action, and then again from stdin a name if the action required it.

##How it works:
The files `bstree.c` and `bstree.h` contain the functions for the bianry search tree that can be used for managing employee names.
###Nodes:
The binary search trees created by theese programs consist of a struct called `Treenode`:
```C
/* a pointer to Treenode */
typedef struct tnode *Treeptr;

/* a binary tree node */
typedef struct tnode {
  char name[NAME_SIZE];

  Treeptr left;
  Treeptr right;
} Treenode;

```
Treenode consists of a char[] for holding the name, and two pointers to Treenodes for the left and
right children.

###Insertion
-When insertions happen to the tree, the name being inserted to the tree is compared to the string in a node using `strcmp(s, t)` from `<string.h>`.
- If the new name is lexicographically less than that of the node, it is inserted in the left subtree of the node. Greater than to the right.
- The program does not handle insertion of multiple of the same name. 

###Removal:
When removing names from the tree, the space allocated for the Treenode is freed using `free(void *)` and pointers to it are set to `NULL`
3 cases for removal. A leaf, 1 child, and 2 children.
- leaf, the leaf is removed.
- one child, leaf is removed, and child is promoted to its place.
- 2 children: The node promoted is the lexicographically smallest of the right subtree of the node to be deleted. i.e. left most node in the right subtree. The promoted node is then deleted from its old location.
e.x. If N was being deleted, R2 would be its replacement. R2 

```
       OLD               NEW
	N                 R2 
       / \      ->       /  \
      L1  R1            L1   R1
         /  \                 \
	R2  R3                 R3
```

###File I/O:
The names are stored in .bst files in the demo. Each line of the file is a name.
-The file is read 1 line at a time(1 name at a time), inserting a new node to the tree with the name just read.
-The file is written in a similar manner. Because the `\n` is kept in the names(and in theory would have been appended to the user input for the names), the names can simply be written to the file in a pre-order traversal of the tree.
-The pre-order traversal of the tree preserves the arrangement of the tree on subsequent readings of the file/tree.

