#include "ClientSocket.h"
#include "SocketException.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void init(){							// To change BG color
	glClearColor(0,0,0,1);
}
void mouse(int , int ,int , int );

void reshape(int w, int h)								// readjusts the clipping area after window is maximized or minimized
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200,200,-200,200);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(1,1,0);
	glBegin(GL_LINES);
	glVertex2f(-200,150);
 	glVertex2f(200,150);
 	glEnd();
 	glColor3f(1,1,1);
 	glRasterPos2f(-100,0);
 	const unsigned char* t = reinterpret_cast<const unsigned char *>("Use left-mouse click to give 5 points above the line");
 	glutBitmapString(GLUT_BITMAP_HELVETICA_18,t);
 	glutSwapBuffers();
}
int count=0;
int main(int argc, char** argv)
{
	glutInit(&argc,argv);					//Initialize glut libraryat
	glutInitWindowSize(800,600);	
				//Windows size
	init();
	
	glutCreateWindow("Player 1");	
	//gluOrtho2D(-200,200,-200,200);			//Creates window
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
		
	//glutPassiveMotionFunc( mouse );
	try {
	glutMouseFunc(mouse);
	glutMainLoop();
	}
	catch(...)
	{
	//cout<<"Exception Caught";
	exit(0);
	}
	
						
}




void mouse(int button, int state, int x, int y)
{
	if (button==GLUT_LEFT_BUTTON && state ==GLUT_DOWN)
	{
	float a,b;
	a = -200 + (static_cast<float>(x)/800)*(200*2);
	b = 200 -(static_cast<float>(y)/600)*(200*2);
	count++;
	//cout<<static_cast<int>(a)<<" "<<static_cast<int>(b)<<" ";
	//cout<<count;

  try
    {

      ClientSocket client_socket ( "localhost", 30000 );

      std::string reply;
      std::string command;
  

      try
	{
    command="PUSH_"+std::to_string(static_cast<int>(a))+"_"+std::to_string(static_cast<int>(b))+"\n";
	  client_socket << command;
	  client_socket >> reply;
	}
      catch ( SocketException& ) {}
     // if (reply=="Success"){

      //}
     // std::cout << "server > " << reply << std::endl;
      
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }



	if(count==5){
	throw 10;
	}
	glutPostRedisplay();
	}
}
