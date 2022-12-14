#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<glut.h>
#include<malloc.h>
#include "constants.h"

float offset = 0.0;
int flag=0;
int flag1=0;

int page1=0;
int page2=0;

void mydisplay();
void backcolor()
{
glClearColor(0.0f,0.0f,0.0f,0.0f);
glColor3f(0.0,0.0,0.0);
}

void bgcolor()
{
	glClearColor(0.0f,0.11f,0.0f,0.0f);
    glColor3f(0.0,0.0,0.0);
}

void bgcolor2()
{
	glClearColor(0.1f,0.0f,0.12f,0.0f);
    glColor3f(0.0,0.0,0.0);
}

void bgcolor3()
{
	glClearColor(0.1f,0.1f,0.12f,0.0f);
    glColor3f(0.0,0.0,0.0);
}

bool box_clicked = false;
void delay(int abc)
{
    for(int i=0;i<abc;i++)
        for(int j=0;j<abc;j++);
}

int temp_x, temp_y, temp_item;
bool prev_search = false;

enum color_code {RED, GREEN, BLUE};
int sb;


int count_digit(int n){
	return (n==0)?0:(1+1);
}
void display_string(char s[], float x, float y, float z = 0.0){
	glRasterPos3f(x, y, z);
	for(int i=0; s[i]; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	glFlush();
}

void textsize(char s[], float x, float y, float z = 0.0){
	glRasterPos3f(x, y, z);
	for(int i=0; s[i]; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, s[i]);
	glFlush();
}

void writeDistance(int x, int y, char *text)
{	
    glRasterPos2i(x,y);
    int len = strlen(text);
    for(int i = 0; i < len; i++)
    { 
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , text[i]);
    }
    glFlush();
}

void DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
    float theta = 2 * 3.1415926 / num_segments; 
    float c = cosf(theta);//precalculate the sine and cosine
    float s = sinf(theta);
    float t;

    float x = r;//we start at angle = 0 
    float y = 0; 

    glBegin(GL_LINE_LOOP); 
    for(int ii = 0; ii < num_segments; ii++) 
    { 
        glVertex2f(x + cx, y + cy);//output vertex 

        //apply the rotation matrix
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    } 
    glEnd(); 
}
void frontscreen(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_QUADS);
 glColor3f(0.08,0.01,0.081);
 glVertex2f(0,0);
 glVertex2f(2000,0);
 glColor3f(0.2,0.03,0.40);
 glVertex2f(2000,2000);
 glVertex2f(0,1000);
 glEnd();
 /*glClearColor(0.0, 0.25, 0.25,0.16);
 glClear(GL_COLOR_BUFFER_BIT);*/
 
 //glClearColor();
 glColor3f(1.7,0.10,1);
 display_string("SDM INSTITUTE OF TECHNOLOGY",550, 750,0.0);
 glColor3f(1.7,0.10,1);
 display_string("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",400, 700,0.0);
 glColor3f(2.6,0,0.0);
 display_string("A MINI PROJECT ON",610, 650,0.0);
 glColor3f(2.6,0,0.0);
 display_string("Binary Search Tree",625,600,0.0);
 glColor3f(0,0.9,0.4);
 display_string("BY:",190,450,0.0);
 glColor3f(0,0.9,0.4);
 display_string("PREETHAM KUMAR D M  -   (4SU19CS069)",220,400,0.0);
 //glColor3f(0,0.9,0.4);
 display_string("PUNITH KUMAR K     -    (4SU19CS070)",220,350,0.0);
 //glColor3f(0,0.9,0.4);
 display_string("R MADHANANTHESH     -   (4SU19CS071)",220,300,0.0);
 glColor3f(0.1,1,1);
 display_string("Under the guidance of:",1100,400,0.0);
 glColor3f(0.1,1,1);
 display_string("Dr. Raghavendra Patil G E",1100,350,0.0);
 glColor3f(0.8,1,0.3);
 display_string("Mouse right click for help , about , flowchart",520,100,0.0);
 display_string("PRESS s TO START",650,50,0.0);
 //bg();
 glFlush();
}

void help() {
	bgcolor3();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.4,0.6,0);
    display_string("HELP",650,750,0.0);
	glColor3f(0.4,0.6,0);
    display_string("To start the project :",300,700,0.0);
    glColor3f(0.5,0,0.9);
    display_string("step 1 : Go to home page",325,660,0.0);
    glColor3f(0.5,0,0.9);
    display_string("step 2: Hit 's' key on keyboard ",325,630,0.0);
	glColor3f(0.5,0,0.9);
    display_string("step 3: click on start simulation or Hit 'k' key on keyboard ",325,600,0.0);
    //glColor3f(0.5,0,0.9);
    //display_string("step 3 : select binary search tree",-20,50,0.0);
    glColor3f(0.4,0.6,0);
    display_string("If u want to know about the project:",300,530,0.0);
    glColor3f(0.5,0,0.9);
    display_string("step 1: Right click select about or on options menu click on about or press 'a' key on keyboard",325,490,0.0);

	glColor3f(0.4,0.6,0);
	display_string("Flow chart of the project:",300,430,0.0);
    glColor3f(0.5,0,0.9);
    display_string("step 1: Right click select flowchart or on options menu click on about or press 'a' key on keyboard",325,390,0.0);
    
	glColor3f(0.4,0.6,0);
	display_string("On simulation:",300,330,0.0);
	glColor3f(0.5,0,0.9);
	display_string("click insert to insert a new node for the BST",325,290,0.0);
	//glColor3f(0.4,0.6,0);
	display_string("click search to search for a node in the BST",325,260,0.0);
	//glColor3f(0.4,0.6,0);
	display_string("click delete to remove a node from the BST",325,230,0.0);
	//glColor3f(0.4,0.6,0);
	display_string("click preorder,inorder,postorder to traverse the BST",325,200,0.0);
   
    glutSwapBuffers();
    glFlush();
}

void about() {
	bgcolor();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	//glClearColor(0, 0, 0.90,0.3); //background color of the screen
	//glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0.5,0);
    display_string("ABOUT",650,750,0.0);
    glColor3f(1,0.5,0.8);
    display_string("This project is about visualizing Binary Search Tree. It is implemented using ",400,650,0.0);
    glColor3f(1,0.5,0.8);
    display_string("different primitives available in OpenGL library and combining them together in a",400,600,0.0);
    glColor3f(1,0.5,0.8);
    display_string("required manner. It highlights the key features of Binary Search Tree. This project ",400,550,0.0);
    glColor3f(1,0.5,0.8);
    display_string("consists of Binary Search Tree which is constructed by using the concept of Linked ",400,500,0.0);
	glColor3f(1,0.5,0.8);
    display_string("Lists. Through this Project one can visualize the working of various features of a",400,450,0.0);
	glColor3f(1,0.5,0.8);
    display_string("Binary Search Tree. Computer Graphics allows the user to visualize the concept of ",400,400,0.0);
	glColor3f(1,0.5,0.8);
    display_string("functions that provides easier way to accomplish the project in an effective manner. ",400,350,0.0);
	glColor3f(1,0.5,0.8);
    display_string("The project has been implemented by efficiently using the data structure to obtain ",400,300,0.0);
	glColor3f(1,0.5,0.8);
    display_string("the optimized results and also various functions and features that are made available ",400,250,0.0);
	glColor3f(1,0.5,0.8);
    display_string("by the OpenGL software package have been utilized effectively.",400,200,0.0);
    glutSwapBuffers();
    glFlush();
}

void Aboutflow()

{
	int i;
	glClearColor(0.18, 0.80, 0.69,0.3); //background color of the screen
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	writeDistance(600, 750, "Flow diagram of Binary Search Tree");
	writeDistance(800, 845, "__________");
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
	glColor3f(0,0,0);
	DrawCircle(750,650,40,300) ;
	glColor3f(0,0,0);
	writeDistance(720, 650, "BEGIN");
	glFlush();
	
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
	glBegin(GL_LINES);
	glVertex2f(750,610);
	glVertex2f(750,580);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
	//box1
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);//black
	glVertex2f(675,530);
	glVertex2f(835,530);
	glVertex2f(835,580);
	glVertex2f(675,580);
	glEnd();
	glColor3f(1,1,1);
	writeDistance(695, 550, "Display window");
	glFlush();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(750,530);
	glVertex2f(750,480);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
	//box1
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);//black
	glVertex2f(635,420);
	glVertex2f(880,420);
	glVertex2f(880,480);
	glVertex2f(635,480);
	glEnd();
	glColor3f(1,1,1);
	writeDistance(700, 460, "Input Elements");
	writeDistance(700, 440, "to be inserted");
	
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(750,460);
	glVertex2f(750,380);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
	//box1
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);//black
	glVertex2f(625,380);
	glVertex2f(890,380);
	glVertex2f(890,330);
	glVertex2f(625,330);
	glEnd();
	glColor3f(1,1,1);
	writeDistance(640, 360, "Click and hold suitable button");
	//writeDistance(700, 530, "to be inserted");
	glFlush();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(750,330);
	glVertex2f(750,300);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
	//box1
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);//black
	glVertex2f(625,300);
	glVertex2f(890,300);
	glVertex2f(890,260);
	glVertex2f(625,260);
	glEnd();
	glColor3f(1,1,1);
	writeDistance(680, 280, "Type the element");
	glColor3f(0,0,0);
	writeDistance(760, 235, "Hit Enter");

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(750,260);
	glVertex2f(750,210);
	glEnd();
	glFlush();
	for (int i = 0; i < 20000; i++) for (int j = 0; j < 20000; j++); //delay
	//box1
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);//black
	glVertex2f(625,210);
	glVertex2f(885,210);
	glVertex2f(885,160);
	glVertex2f(625,160);
	glEnd();
	glColor3f(1,1,1);
	writeDistance(680, 190, "suitable action is taken");
	writeDistance(680, 170, "and displays output");

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(750,160);
	glVertex2f(750,120);
	glEnd();

	glColor3f(0,0,0);
	DrawCircle(750,80,40,300) ;
	glColor3f(0,0,0);
	writeDistance(735, 80, "END");
	
	glFlush();
	glutSwapBuffers();
	glFlush();

}

void to_string(char *s, int num){
	int r, d;
	d = count_digit(abs(num));
	if(num==0)
		s[0]='0';
	if(num<0){
		s[0] = '-';
		d++;
	}
	s[d]='\0';
	num = abs(num);
	while(num!=0){
		r = num%10;
		s[--d] = r+'0';
		num/=10;
	}
}

void buttonm() {
	bgcolor2();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glClearColor(0.11, 0, 0.12,0.3); //background color of the screen
	//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1,1,1);
    display_string("New Simulation",680, 660,0);
	glColor3f(0,1,1);
	display_string("click here || press 'k' ",665, 620,-1);
	glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
	glVertex2f(625,700);
	glVertex2f(885,700);
	glVertex2f(885,600);
	glVertex2f(625,600);
	glEnd();
	glFlush();
    
	glColor3f(1,1,1);
    display_string("Help",720, 510,0 );
	glColor3f(0,1,1);
	display_string("click here || press 'h' ",665, 470,-1);
    glColor3f(1.0, 0.0, 0.5);
    glBegin(GL_LINE_LOOP);
    glVertex2f(625, 550);
    glVertex2f(885, 550);
    glVertex2f(885, 450);
    glVertex2f(625, 450);
    glEnd();
	glFlush();
    
	glColor3f(1,1,1);
    display_string("About",715,360,0);
	glColor3f(0,1,1);
	display_string("click here || press 'a' ",665, 320,-1);
    glColor3f(1.0, 0.0, 0.5);
    glBegin(GL_LINE_LOOP);
    glVertex2f(625, 400);
    glVertex2f(885, 400);
    glVertex2f(885, 300);
    glVertex2f(625, 300);
    glEnd();
	glFlush();

	glColor3f(1,1,1);
    display_string("Flow-Chart",695,210,0);
	glColor3f(0,1,1);
	display_string("click here || press 'f' ",665, 170,-1);
	glColor3f(1,1,1);
	display_string("Press esc for welcome screen",630,80,0);
    glColor3f(1.0, 0.0, 0.5);
    glBegin(GL_LINE_LOOP);
    glVertex2f(625, 250);
    glVertex2f(885, 250);
    glVertex2f(885, 150);
    glVertex2f(625, 150);
	//glColor3f(1,1,1);
    glEnd();
	glFlush();
}

void clear_input_region(){
	glColor4f(0.11, 0, 0.12,0.3);
	glBegin(GL_POLYGON);
		glVertex2f(100, 630);
		glVertex2f(100, 700);
		glVertex2f(700, 650);
		glVertex2f(680, 700);
	glEnd();
	glColor4f(0.11, 0, 0.12,0.3);
	glBegin(GL_POLYGON);
		glVertex2f(40, 40);
		glVertex2f(40, 100);
		glVertex2f(650, 100);
		glVertex2f(650, 40);
	glEnd();
	glFlush();
}

void clear_input_region2(){
	glColor4f(0.11, 0, 0.12,0.3);
	glBegin(GL_POLYGON);
		glVertex2f(1000, 500);
		glVertex2f(1000, 600);
		glVertex2f(1300, 600);
		glVertex2f(1300, 500);
	glEnd();
	glFlush();


}

static int i=0;
//int dn=0;
class binary_search_tree {
	

	public:
		NODE root;
		int root_centre_x, root_centre_y;
		int node_width;
		int dn;
		float line_color[3];
		char data_string[10];
		// Method used to get the minimum valued node in the specified 
		NODE get_minimum(NODE temp, NODE *par){
			if(temp->left == NULL)
				return temp;
			*par = temp;
			return get_minimum(temp->left, par);
		}

	public:

		binary_search_tree(){
			root = NULL;
			root_centre_x = 500;
			root_centre_y = 500;
			dn=0;
			node_width = 30;
			line_color[RED] = 0.0;
			line_color[GREEN] = 0.7;
			line_color[BLUE] = 0.0;
		}

		// method used to draw a node and put the value at the given co-ordinate
		void draw_node(int item, int centre_x, int centre_y, bool write_value = true){
			char data_string[10];
			//glColor4f(0.0, 1.0, 1.0,1.0);
			glBegin(GL_POLYGON);
				glVertex2f(centre_x + node_width, centre_y + node_width);
				glVertex2f(centre_x - node_width, centre_y + node_width);
				glVertex2f(centre_x - node_width, centre_y - node_width);
				glVertex2f(centre_x + node_width, centre_y - node_width);
			glEnd();

			dn=1;
			if(write_value){
				to_string(data_string, item);
				glColor3f(1.0, 1.0, 0.0);
				display_string(data_string, centre_x - node_width + 10, centre_y);
			}
			
		}

		// method used to draw a line between a parent and a child
		void draw_arrow(int par_x, int par_y, int node_x, int node_y, bool color = true){
			if(color)
				glColor3f(line_color[RED], line_color[GREEN], line_color[BLUE]);
			else
				glColor3f(0, BG_G, BG_B);
			glLineWidth(3);
			glBegin(GL_LINES);
				glVertex2f(par_x, par_y - node_width);
				glVertex2f(node_x, node_y + node_width);
			glEnd();
		}

		// method used to insert an element into the tree and call the draw_node method
		NODE insert(int item){
			int num_of_nodes = 1;
			int node_x = root_centre_x, node_y = root_centre_y;
			int par_x, par_y;
			NODE temp, par = NULL, new_node;
			if(root == NULL){
				root = (NODE)malloc(sizeof(struct node));
				if(root == NULL){
					printf("There was an error in creating the node\n");
					return NULL;
				}
				root->data = item;
				root->left = root->right = NULL;
				glColor3f(0, 0, 1);
				draw_node(item, node_x, node_y);
				//dn=1;
				return root;
			}
			temp = root;
			while(temp != NULL){
				num_of_nodes *= 2;
				par_x = node_x;
				par_y = node_y;
				node_y -= 100;
				par = temp;
				if(item < temp->data) {
					temp = temp->left;
					node_x -= root_centre_x/num_of_nodes;
				}
				else {
					temp = temp->right;
					node_x += root_centre_x/num_of_nodes;
				}
			}
			new_node = (NODE)malloc(sizeof(struct node));
			if(new_node == NULL){
					printf("There was an error in creating the node\n");
					return NULL;
				}
			new_node->data = item;
			new_node->left = new_node->right = NULL;
			if(item < par->data)
				par->left = new_node;
			else
				par->right = new_node;
			glColor3f(0, 0, 1);
			draw_node(item, node_x, node_y);
			draw_arrow(par_x, par_y, node_x, node_y);
			//dn=1;
			glFlush();
			return root;
		}


		// Method used to search for the first node with a given value in the tree
		NODE search(int item){
			int num_of_nodes = 1;
			int node_x = root_centre_x, node_y = root_centre_y;
			int par_x, par_y;
			NODE temp, par = NULL, new_node;
			if(root == NULL){
				glColor3f(1.0, 0.0, 0.0);
				display_string(not_found, 100, 600);
				return root;
			}
			temp = root;
			while(temp != NULL){
				num_of_nodes *= 2;
				par_x = node_x;
				par_y = node_y;
				par = temp;
				if(item == temp->data){
					prev_search = true;
					temp_x = node_x;
					temp_y = node_y;
					temp_item = item;
					glColor3f(1.0, 0.0, 0.0);
					draw_node(item, node_x, node_y);
					glFlush();
					return temp;
				}
				else if(item < temp->data) {
					temp = temp->left;
					node_y -= 100;
					node_x -= root_centre_x/num_of_nodes;
				}
				else {
					temp = temp->right;
					node_y -= 100;
					node_x += root_centre_x/num_of_nodes;
				}
			}
			glColor3f(1.0, 0.0, 0.0);
			display_string(not_found, 100, 600);
			glFlush();
			return temp;
		}

		void pre_order(NODE temp, binary_search_tree temp_tree){
			if(temp != NULL){
				temp_tree.insert(temp->data);
				pre_order(temp->left, temp_tree);
				pre_order(temp->right, temp_tree);
			}
		}
		void delay()
		{
    			for(int i=0;i<22000;i++)
      			for(int j=0;j<22000;j++);
		}
		void preorder(NODE temp, binary_search_tree temp_tree){
			if(temp != NULL){
				temp_tree.insert(temp->data);
				delay();
				to_string(data_string, temp->data);
				glColor3f(1.0, 1.0, 0.0);
				data_string[i]=temp->data;
				i=i+1;
				display_string(data_string,300+(i*20), 50);
				search(temp->data);				
				delay();
				i=i+1;
				preorder(temp->left, temp_tree);
				preorder(temp->right, temp_tree);
				}
		}
		
		void inorder(NODE temp, binary_search_tree temp_tree){
			if(temp != NULL){
				temp_tree.insert(temp->data);
				delay();
				inorder(temp->left, temp_tree);
				to_string(data_string, temp->data);
				glColor3f(1.0, 1.0, 0.0);
				data_string[i]=temp->data;
				i=i+1;
				display_string(data_string,300+(i*20), 50);
				search(temp->data);
				delay();
				i=i+1;
				inorder(temp->right, temp_tree);
				}
			}
		void postorder(NODE temp, binary_search_tree temp_tree){
		if(temp != NULL){
				temp_tree.insert(temp->data);
				postorder(temp->left, temp_tree);
				delay();
				postorder(temp->right, temp_tree);
				to_string(data_string, temp->data);
				glColor3f(1.0, 1.0, 0.0);
				data_string[i]=temp->data;
				i=i+1;
				display_string(data_string,300+(i*20), 50);
				search(temp->data);
				delay();
				i=i+1;
			}
		}

		void draw_tree(){
			binary_search_tree temp_tree;
			if(flag==0)
                display();
            else
                display1();
			pre_order(root, temp_tree);
		}
		void preordertraversal(){
			binary_search_tree temp_tree;
			display();
			display_string(query_string4,100, 50);
			preorder(root, temp_tree);
			pre_order(root, temp_tree);
			clear_input_region();
		}
		void inordertraversal(){
			binary_search_tree temp_tree;
			display();
			display_string(query_string5,100, 50);
			inorder(root, temp_tree);
			pre_order(root, temp_tree);
			clear_input_region();
		}
		void postordertraversal(){
			binary_search_tree temp_tree;
			display();	
			display_string(query_string6,100, 50);
			postorder(root, temp_tree);
			pre_order(root, temp_tree);
			clear_input_region();
		}

		NODE remove(int item){
			bool found = false;
			int num_of_nodes = 1;
			int node_x = root_centre_x, node_y = root_centre_y;
			int par_x, par_y;
			NODE temp = root, par = root, new_node;
			if(root == NULL){
				glColor3f(1.0, 0.0, 0.0);
				display_string(not_found, 100, 600);
				return root;
			}
			while(temp != NULL){
				if(item == temp->data){
					found = true;
					if(temp == root){
						if(temp->left == NULL && temp->right == NULL){
							root = NULL;
							free(temp);
						}
						if(temp->left != NULL && temp->right != NULL){
							par = temp;
							NODE min_node = get_minimum(temp->right, &par);
							temp->data = min_node->data;
							temp = min_node;
							item = min_node->data;
							continue;
						}
						if(temp->left != NULL){
							root = temp->left;
							free(temp);
						}
						if(temp->right != NULL){
							root = temp->right;
							free(temp);
						}
					}
					else if(temp->left == NULL && temp->right == NULL){
						if(par->left == temp)
							par->left = NULL;
						else
							par->right = NULL;
						free(temp);
					}
					else if(temp->left != NULL && temp->right != NULL){
						par = temp;
						NODE min_node = get_minimum(temp->right, &par);
						temp->data = min_node->data;
						temp = min_node;
						item = min_node->data;
						continue;
					}
					else {
						if(temp->left != NULL)
							(par->left == temp) ? (par->left = temp->left) : (par->right = temp->left);
						else
							(par->left == temp) ? (par->left = temp->right) : (par->right = temp->right);
						free(temp);
					}
					break;
				}
				par = temp;
				if(item < temp->data)
					temp = temp->left;
				else
					temp = temp->right;
			}
			if(!found){
				glColor3f(1.0, 0.0, 0.0);
				display_string(not_found, 100, 600);
			}
			else
            {
                flag=1;
                draw_tree();
            }

		}
};

//Object of class binary_search_tree which is used to manipulate the tree
binary_search_tree tree;


//A member function pointer used to decide the method to be called at runtime
NODE (binary_search_tree::*operation)(int) = NULL;


class option_box {
	private:
		float bottom_corner_x, bottom_corner_y;
		float bc;
		float height, width; 
		float color[3];
		char option_name[20];
	public:
		option_box(){
			bottom_corner_x = 0;
			bottom_corner_y = 0;
			width = 0;
			height = 0;
			color[RED] = 0.0;
			color[GREEN] = 0.0;
			color[BLUE] = 1.0;
			strcpy(option_name, "");
		}
		option_box(const char name[]){
			bottom_corner_x = 150;
			bottom_corner_y = 700;
			width = 150;
			height = 50;
			color[RED] =0.36 ;
			color[GREEN] =  0.25 ;
			color[BLUE] =  0.20;
			strcpy(option_name, name);
		}
		void draw_box(){
			bottom_corner_x += offset;
			bc = bottom_corner_x;
			glColor3f(0,color[GREEN] ,0);
			glBegin(GL_POLYGON);
				glVertex2f(bottom_corner_x, bottom_corner_y);
				glVertex2f(bottom_corner_x + width, bottom_corner_y);
				glVertex2f(bottom_corner_x + width, bottom_corner_y + height);
				glVertex2f(bottom_corner_x, bottom_corner_y + height);
			glEnd();
			offset += 200.0;
			glColor3f(1.0, 1.0, 0.0);
			display_string(option_name, bottom_corner_x + 30.0, bottom_corner_y + 20.0);
		}
		bool clicked(int x, int y){
			if( x >=bc&& x < bc+width)
				if( y > bottom_corner_y && y < bottom_corner_y + height){
					box_clicked = true;
					return true;
				}
			return false;
		}
};



option_box insert_box, search_box, delete_box,preorder_box,inorder_box,postorder_box; 

void init() {
	backcolor();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0,1500,0.0,800);
}

void displayOptions(){
 	option_box insert_box("Insert"), search_box("Search"), delete_box("Delete"),preorder_box("Preorder"),inorder_box("Inorder"),postorder_box("Postorder");
 	offset = 0.0;
	insert_box.draw_box();
	search_box.draw_box();
	delete_box.draw_box();
	preorder_box.draw_box();
	inorder_box.draw_box();
	postorder_box.draw_box();
	::insert_box = insert_box;
	::search_box = search_box;
	::delete_box = delete_box;
	::preorder_box=preorder_box;
	::inorder_box=inorder_box;
	::postorder_box=postorder_box;
	
 }

void display() {
	//glClear(GL_COLOR_BUFFER_BIT);
	displayOptions();
	glFlush();
}
void mydisplay(void)
{
 //glClear(GL_COLOR_BUFFER_BIT);
 if(page1==0)
   //glClear(GL_COLOR_BUFFER_BIT);
   frontscreen ();
 if(page1==1)
	 
	 buttonm();
     //glClear(GL_COLOR_BUFFER_BIT);
 if(page1==2)
	 display();
     page2=1;
 if(page1==3)
	 help();
     page2=1;
 if(page1==4)
	 about();
     page2=1;
 if(page1==5)
	 Aboutflow();
     page2=1;


  //display();
}



void display1()
{
   glClear(GL_COLOR_BUFFER_BIT);
	displayOptions();
	glFlush();
}

//int ic=0 , sc=0 , dc=0;
void mouse(int button, int state, int x, int y){
	y = 800- y;

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (x <= 820) && (x >= 510) && (y <= 700) && (y >= 600) && page1 == 1)
    {
        page1=2;
		glClear(GL_COLOR_BUFFER_BIT);
		mydisplay();
    }
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (x <= 820) && (x >= 510) && (y <= 550) && (y >= 450) && page1 == 1)
    {

        page1 = 3;
		glClear(GL_COLOR_BUFFER_BIT);
        mydisplay();

    }
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (x <= 820) && (x >= 510) && (y <= 400) && (y >= 300) && page1 == 1)
    {
        page1 = 4;
		glClear(GL_COLOR_BUFFER_BIT);
        mydisplay();

    }
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (x <= 820) && (x >= 510) && (y <= 250) && (y >= 150) && page1 == 1)
    {
        page1 = 5;
		glClear(GL_COLOR_BUFFER_BIT);
        mydisplay();

    }

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if(prev_search == true){
			glColor3f(0,0,1);
			tree.draw_node(temp_item, temp_x, temp_y);
			prev_search = false;
		}
		if(insert_box.clicked(x, y)){
			clear_input_region2();
			operation = &binary_search_tree::insert;
			clear_input_region();

			glColor3f(1.0, 1.0, 0.0);
			display_string(query_string, 100, 650);
			glFlush();
		}
		if(search_box.clicked(x, y)){
			operation = &binary_search_tree::search;
			clear_input_region();
			glColor3f(1.0, 1.0, 0.0);
			display_string(query_string2, 100, 650);
			glFlush();
		}
		if(delete_box.clicked(x, y)){
			operation = &binary_search_tree::remove;
			clear_input_region();
			glColor3f(1.0, 1.0, 0.0);
			display_string(query_string3, 100, 650);
			glFlush();
		}
		if(preorder_box.clicked(x, y)){
			i=0;
			tree.preordertraversal();
		}
		if(inorder_box.clicked(x, y)){
			i=0;
			tree.inordertraversal();
		}
		if(postorder_box.clicked(x, y)){
			i=0;
			tree.postordertraversal();
		}
	}
		
}

void keys(unsigned char key, int x, int y) {
    
	int l=0;

    if (key == 115) {
		//glClear(GL_COLOR_BUFFER_BIT);
        page1=1;
		glClear(GL_COLOR_BUFFER_BIT);
    }
	if (key == 107) { //k
		if(page1==1){
			page1=2;
		    glClear(GL_COLOR_BUFFER_BIT);
		}    
    }
	if (key == 104) { //h
		//glClear(GL_COLOR_BUFFER_BIT);
		if(page1==1){
			page1=3;
		    glClear(GL_COLOR_BUFFER_BIT);
		}    
    }
	if (key == 97) { //a
			page1=4;
		    glClear(GL_COLOR_BUFFER_BIT);
		}    
	if (key == 8) { //backspace
		//glClear(GL_COLOR_BUFFER_BIT);
		if(page2==1){
			glClear(GL_COLOR_BUFFER_BIT);
			page1=1;
		    
		}    
    }
	if (key == 27) { //backspace
		//glClear(GL_COLOR_BUFFER_BIT);
		if(page2==1){
			glClear(GL_COLOR_BUFFER_BIT);
			page1=0;
		    
		}    
    }
	if (key == 102) { //f
		//glClear(GL_COLOR_BUFFER_BIT);
		if(page2==1){
			page1=5;
		    glClear(GL_COLOR_BUFFER_BIT);
		}    
    }
    if (key == 27)
    {
        if (l == 3)
        {
            l--;
        }
        if (l == 4)
        {
            l = l - 2;
        }
        l--;
    }
    mydisplay();

	char s[2];
	int ins=0;
	//int ycor = 10;
	static int digit = 0;
	static int number = 0;
	static int sign = 1;
	if(!box_clicked)
		return ;
	/*if(key==13)
	{
		//number = (number*10) + key - '0';
		//s[0]=number;
		//s[1]='\0';
		ins=1;
		display_string(s,950,550,0.0);
		display_string("inserted",950,550-ycor,0.0);
		ycor=ycor+18;
	}*/
	if(digit == 0 && key == '-'){
		s[0]=key;
		s[1]='\0';
		glColor3f(1.0, 1.0, 0.0);
		display_string(s, 570,650);
		glFlush();
		sign = -1;
	}
	else if(key != 13 && isdigit(key)){
		number = (number*10) + key - '0';
		s[0]=key;
		s[1]='\0';
		glColor3f(1.0, 1.0, 0.0);
		display_string(s, 570+(digit*10), 650);
		digit++;
		if(ins==1)
		{
			display_string(s, 950, 650);


		}
		/*ins=1;
		display_string("inserted",850,550,0.0);*/
		//dn=1;
	}
	/*if(ic==1)
		{
		display_string(s, 1050, 550);
		display_string("inserted", 1100, 550);
		}*/
	else if(key != 13 && !isdigit(key));
	else{
		digit = 0;
		clear_input_region();
		(tree.*operation)(sign*number);
		number = 0;
		sign = 1;
		box_clicked = false;
	}
}

void preorder1(struct node* NODE)
{
    //static int sign=1;
   if(NODE!=NULL)
{
    operation = &binary_search_tree::search;
    delay(15000);
    printf("%d\t",NODE->data);
    (tree.*operation)(NODE->data);
    preorder1(NODE->left);
    preorder1(NODE->right);
}

}
void menu(int id)
{
switch(id)
{
case 1:
    help();
	break;
case 2: 
	about();
	break;
case 3:
	Aboutflow();
	break;
}
}

/*void myreshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
gluOrtho2D(-2,2,-2*(GLfloat)h/(GLfloat)w,2*(GLfloat)h/(GLfloat)w);
else
gluOrtho2D(-2*(GLfloat)w/(GLfloat)h,2*(GLfloat)w/(GLfloat)h,-2,2);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}*/


int main(int argc,char **argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(SCREEN_SIZE_X,SCREEN_SIZE_Y);
	glutInitWindowPosition(0,0);
	glutCreateWindow("BINARY SEARCH TREE AND TRAVERSALS");
	glutDisplayFunc(mydisplay);
	glutKeyboardFunc(keys);
	glutMouseFunc(mouse);
	//glutReshapeFunc(myreshape);
	init();
    sb=glutCreateMenu(menu);
    glutAddMenuEntry("Help",1);
    glutAddMenuEntry("About",2);
	glutAddMenuEntry("Flow chart",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}