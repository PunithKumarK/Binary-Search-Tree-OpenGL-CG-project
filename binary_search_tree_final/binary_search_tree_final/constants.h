#include<stdio.h>
#define SCREEN_SIZE_X 1000
#define SCREEN_SIZE_Y 700
#define BG_R 1.0
#define BG_G 1.0
#define BG_B 1.0
#define BG_A 1.0

struct node {
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node* NODE;

NODE root = NULL;
int dn=0;
int ycor=0;
char query_string[] = "Enter an Integer and Hit Enter : ";
char query_string2[]="Enter an Integer to be searched and Hit Enter :";
char query_string3[]="Enter an Integer to be deleted and Hit Enter :";
char query_string4[]="The preorder is:";
char query_string5[]="The inorder is:";
char query_string6[]="The postorder is:";
char not_found[] = "Item Not found";
char inserted[] = "inserted";


//float node_color[3] = {1.0, 1.0, 1.0};
void mydisplay();
void display();
void display1();