#include "ClientSocket.h"
#include "SocketException.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
#include <unistd.h>
#include <vector>
#include <string>

using namespace std;

float a,b,c,d,e,f,g,h,i,j,k,l,m,n,o;
float x_pos = -30;


void display();
void overscr();
void reshape(int, int);
void timer(int);
void SpecialInput(int, int, int);
void sun(float, float);
void tokenize(std::string const &str, const char delim, std::vector<std::string> &out);
std::vector<std::string> out;
const char delim = '_';
int flag=0;

void init(){							// To change BG color
	glClearColor(0,0,0,1);
}


int main(int argc, char** argv)
{
try
    {

      ClientSocket client_socket ( "localhost", 30000 );

      std::string reply;
  
do{

      try
	{
	  client_socket << "CHECK";
	  client_socket >> reply;
	  //cout<<reply;
	}
      catch ( SocketException& ) {}
    
    sleep(1);
} while (reply=="NO");
/*
a=-111;
b=194;
c=b;
d=-12;
e=192;
f=e;
g=101;
h=175;
i=h;
j=-14;
k=176;
l=k;
m=60;
n=167;
n=o;
*/ 
  try
	{
	  client_socket << "ASK";
	  client_socket >> reply;
    tokenize(reply, delim, out);
    a=stoi(out[0]);
    b=stoi(out[1]);
    c = b;
    out.clear();
	}
      catch ( SocketException& ) {}
  
  try
	{
	  client_socket << "ASK";
	  client_socket >> reply;
    tokenize(reply, delim, out);
    d=stoi(out[0]);
    e=stoi(out[1]);
    f = e;
    out.clear();
	}
      catch ( SocketException& ) {}

  try
	{
	  client_socket << "ASK";
	  client_socket >> reply;
    tokenize(reply, delim, out);
    g=stoi(out[0]);
    h=stoi(out[1]);
    i = h;
    out.clear();
	}
      catch ( SocketException& ) {}

  try
	{
	  client_socket << "ASK";
	  client_socket >> reply;
    tokenize(reply, delim, out);
    j=stoi(out[0]);
    k=stoi(out[1]);
    l = k;
    out.clear();
	}
      catch ( SocketException& ) {}

   try
	{
	  client_socket << "ASK";
	  client_socket >> reply;
    tokenize(reply, delim, out);
    m=stoi(out[0]);
    n=stoi(out[1]);
    o = n;
    out.clear();
	}
      catch ( SocketException& ) {}

    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

	glutInit(&argc,argv);					//Initialize glut library
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);		//Display mode ( double for double buffers)
	glutInitWindowPosition(200,200);			// Windows position
	glutInitWindowSize(800,600);				//Windows size
	glutCreateWindow("LUPIN");
	//cout<<glutGetWindow();			//Creates window
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);				//reshape  callback function
	
	init();

    glutTimerFunc(0,timer,0);
	//glutMainLoop();
	/*	
	if(flag==5){
		//cout<<flag;
	glutDestroyWindow(1);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);		//Display mode ( double for double buffers)
	glutInitWindowPosition(200,200);			// Windows position
	glutInitWindowSize(800,600);				//Windows size
	glutCreateWindow("LUPIN2");				//Creates window
	glutDisplayFunc(overscr);
	//glutMainLoop();
	}*/
	
glutMainLoop();			
	
}


void display()											// Display callback function
{	
	
	glClear(GL_COLOR_BUFFER_BIT);								//Clearing buffer
	glLoadIdentity();									// resets transformations of matrix in which we are currently residing
	
	if(flag!=5){
			glBegin(GL_TRIANGLES);									// bottom player 1 triangle
	glColor3f(1,1,1);
	glVertex2f(x_pos,-199);
	glVertex2f(x_pos+40,-199);
	glVertex2f(x_pos+20,-170);
	
	glEnd();	
	sun(a,b);
	sun(d,e);
	sun(g,h);
	sun(j,k);
	sun(m,n);
	glutSwapBuffers();
	}
	else{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1,1,1);
 	glRasterPos2f(-30,0);
 	const unsigned char* t = reinterpret_cast<const unsigned char *>("Game Over");
 	glutBitmapString(GLUT_BITMAP_HELVETICA_18,t);
	glutSwapBuffers();

	}
									//Display frame buffer on screen( swapping of front and back buffers)
}

void overscr(){
	glClear(GL_COLOR_BUFFER_BIT);								//Clearing buffer
	glLoadIdentity();									// resets transformations of matrix in which we are currently residing
	
	
cout<<"Hi";
	
	glutSwapBuffers();
	
	//glEnd();	
		
}


void reshape(int w, int h)								// readjusts the clipping area after window is maximized or minimized
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200,200,-200,200);
	glMatrixMode(GL_MODELVIEW);
}

int state = 1,state2 = 1,state3 = 1, state4 = 1, state5 = 1;

void timer(int)
{
	glutPostRedisplay();					//calls display func
	glutTimerFunc(1000/60,timer,0);				//60fps
	glutSpecialFunc(SpecialInput);
	switch(state)
	{ 
	case 1:
		if(b> -215)
			b=b-1.2;
		else
			state = -1;					//Ball1 going down
		break;
	case -1: 
		if(b=-215){
			b = c;
			state = 1;
			break;
		}
}
	switch(state2)
	{ 
	case 1:
		if(e> -215)
			e=e-1.5;
		else	
			state2 = -1;
		break;							//Ball2 going down
	case -1: 
		if(e=-215){
			e = f;
			state2 = 1;
			break;
		}
}
	switch(state3)
	{ 
	case 1:
		if(h> -215)
			h=h-1.75;
		else
			state3 = -1;
		break;							//Ball 3 going down
	case -1: 
		if(h=-215){
			h = i;
			state3 = 1;
			break;
		}
}
	switch(state4)
	{ 
	case 1:
		if(k> -215)
			k=k-1.25;
		else
			state4 = -1;
		break;							//Ball 4 going down
	case -1: 
		if(k=-215){
			k = l;
			state4 = 1;
			break;
		}
}
	switch(state5)
	{ 
	case 1:
		if(n> -215)
			n=n-1.4;
		else
			state5 = -1;
		break;							//Ball 5 going down
	case -1: 
		if(n=-215){
			n = o;
			state5 = 1;
			break;
		}
}
	
	if(x_pos +20 < g+10 && x_pos +20 > g-10 && h < -155 && h > -165 || x_pos +20 < a+10 && x_pos +20 > a-10 && b < -155 && b > -165 || x_pos +20 < d+10 && x_pos +20 > d-10 && e < -155 && e > -165 || x_pos +20 < j+10 && x_pos +20 > j-10 && k < -155 && k > -165 || x_pos +20 < m+10 && x_pos +20 > m-10 && n < -155 && n > -165 ){
		flag=5;
		}				// calls timer function again and again	
		
		
}

void SpecialInput(int key,int x,int y)	
{
	switch(key)
	{
		case GLUT_KEY_LEFT:
		if(x_pos>=-200)
			x_pos-=8;
		break;							//triangle movement
		case GLUT_KEY_RIGHT:
		if(x_pos<=160)
			x_pos+=8;
		break;
	}
	
}

void sun(float x, float y){
 //SUN
 glBegin(GL_POLYGON);
 glColor3f(.9765,.8431,.1098);
 

        // Iterate through all the

        // 360 degrees
	float angle_theta;
        for (int i = 0; i < 360; i++) {					// Ball Creation

 

            // Find the angle

            angle_theta = i * 3.142 / 180;

            glVertex2f(x + 15 * cos(angle_theta),

                       y + 15 * sin(angle_theta));

        }

 

        // Sets vertex

        glEnd();
 	glFlush();       
}


void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;
 
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}