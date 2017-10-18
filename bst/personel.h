#ifndef personel_included
#define personel_included

#include "bstree.h"
#define MAX_LINE 150

/* interface for the user to manage employees */
int manage(Treeptr root);

/* prompts user for input on action */
int getResponse();

/* asks user for a name */
char *getName(char *buf);

#endif /* included */
