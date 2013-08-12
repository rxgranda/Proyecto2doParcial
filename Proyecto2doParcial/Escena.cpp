/**
*Proyecto 2 Gr�ficos por Computadora
*
* Integrantes:
*
*   Gianni Carlo
*   Roger Granda
*   Denisse Pintado
*
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;


GLfloat ancho_plano=900.0;
GLfloat alto_plano=700.0;
GLfloat x_Spin=0.0f;
GLfloat y_Spin=0.0f;
GLfloat z_Spin=0.0f;
GLfloat xPosicion = 0.0f;
GLfloat yPosicion = 0.0f;
GLfloat zPosicion = 10.0f;









//luz
GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat	 lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };

// lista tablero
GLuint _displayListId_AreaNegra; 
GLuint _displayListId_AreaBlanca;


void dibujarEspacioNegro() {
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.77f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(1.50f,0.0f,0.0f);
	glVertex3f(1.5f,0.3f,0.0f);
	glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.77f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.77f,1.0f);
	glVertex3f(1.5f,0.0f,0.0f);
	glVertex3f(1.5f,0.0f,-1.5f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(1.5f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.77f,1.0f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glVertex3f(1.50f,0.0f,-1.5f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.77f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(1.50f,0.0f,0.0f);
	glVertex3f(1.5f,0.0f,-1.5f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.77f,1.0f);
	glVertex3f(0.0f,0.3f,0.0f);
	glVertex3f(1.50f,0.3f,0.0f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
} 
void dibujarEspacioBlanco() { 
	glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(1.50f,0.0f,0.0f);
	glVertex3f(1.5f,0.3f,0.0f);
	glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(1.5f,0.0f,0.0f);
	glVertex3f(1.5f,0.0f,-1.5f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(1.5f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glVertex3f(1.50f,0.0f,-1.5f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(1.50f,0.0f,0.0f);
	glVertex3f(1.5f,0.0f,-1.5f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.0f,0.3f,0.0f);
	glVertex3f(1.50f,0.3f,0.0f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
}
void iniciarTablero (void){
	_displayListId_AreaNegra = glGenLists(1); //Make room for the display list 
	glNewList(_displayListId_AreaNegra, GL_COMPILE); //Begin the display list 
	dibujarEspacioNegro(); //Add commands for drawing a black area to the display list 
	glEndList(); //End the display list //Set up a display list for drawing a cube 
	_displayListId_AreaBlanca = glGenLists(2); //Make room for the display list 
	glNewList(_displayListId_AreaBlanca, GL_COMPILE); //Begin the display list 
	dibujarEspacioBlanco(); //Add commands for drawing a black to the display list
	glEndList(); //End the display list

}


void dibujarTablero (void){

	glTranslatef(-4*1.5, 0.0, 4*1.5);
	int k=0;
	for(float j=0.0;j>(-8*1.5);j-=1.5) {
		k++;
		for(float i=0.0;i<(4*3.0);i+=3.0) {
			if(k%2==0) {
				glPushMatrix();
				glTranslatef(i,0.0,j);
				glCallList(_displayListId_AreaNegra);
				glPopMatrix();
			}
			else {
				glPushMatrix();
				glTranslatef(i+1.5,0.0,j);
				glCallList(_displayListId_AreaNegra);
				glPopMatrix();
			}
		}
	}
	for(float j=0.0;j>(-8*1.5);j-=1.5) {
		k++;
		for(float i=0.0;i<(4*3.0);i+=3.0) {
			if(k%2!=0) {
				glPushMatrix();
				glTranslatef(i,0.0,j);
				glCallList(_displayListId_AreaBlanca);
				glPopMatrix();
			}
			else {
				glPushMatrix();
				glTranslatef(i+1.5,0.0,j);
				glCallList(_displayListId_AreaBlanca);
				glPopMatrix();
			}
		}
	}



}

/*
* Procedimiento: reshape
* Par�metros: int w, int h
* Descripci�n: Establece el worldspace, model, y viewport de la escena
* Autor: Gianni Carlo, Roger Granda
*/
void reshape(int w, int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0,1.0,-1.0, 1.0, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();		
}


/*
* Procedimiento: display
* Par�metros: -
* Descripci�n: Realiza los procesos geom�tricos del cuerpo (Rotaci�n y traslaci�n del cuerpo), y Rasterizado del cuerpo y el plano cartesiano 
* Autores: Denisse Pintado, Roger Granda, Gianni Carlo
*/
void display (void){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0,5.0,zPosicion,0.0,0.0,0.0,0.0,1.0,0.0);


	glColor3f(1.0,0.0,0.0);
	// manipular escena
	glRotatef(x_Spin,1.0,0.0,0.0);
	glRotatef(y_Spin,0.0,1.0,0.0);
	glRotatef(z_Spin,0.0,0.0,1.0);
	glTranslatef(xPosicion,yPosicion,0);


	glPushMatrix();	
	
	

	dibujarTablero();

	glPopMatrix();


	glPushMatrix();
	
	glColor3f(0.945f,0.552f,0.0196f);
	
	glTranslatef(-3.0,3.0,3.0);
	glutSolidSphere(0.5,50,50);

	glPopMatrix();
	

	glPushMatrix();	
	
	glColor3f(0.0f,0.6313f,0.796f);
	glTranslatef(3.0,3.0,3.0);
	glutSolidTorus(0.2,0.5,50,50);
	
	glPopMatrix();

	glPushMatrix();	
	glColor3f(0.89f,0.254f,0.192f);
	glTranslatef(0.0,3.0,0.0);
	glutSolidTeapot(1.0);
	
	glPopMatrix();

	glPushMatrix();	
	glColor3f(0.89f,0.254f,0.192f);
	glTranslatef(1.0,3.0,3.0);
	
	glutSolidCube(1.0);
	glPopMatrix();


	//Obelisco
	glPushMatrix();	
	
	glColor3f(0.003921569f,0.250980392f,0.643137255f);
	glTranslatef(5.0,0.0,0.0);
	glRotatef(-90.0f,1.0,0.0f,0.0f);
	GLUquadricObj * qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj,GLU_FLAT);
	
	
	gluCylinder(qobj, 0.50, 0.25, 5.0, 4,4);

	

	
	
	glPopMatrix();

	glPushMatrix();	
	
	glColor3f(0.003921569f,0.250980392f,0.643137255f);
	glTranslatef(5.0,5.0,0.0);
	glRotatef(-90.0f,1.0,0.0f,0.0f);
	
	glutSolidCone(0.25,0.4,4,4);

	
	
	glPopMatrix();

	

	glutSwapBuffers();

}

/*
* Procedimiento: init
* Par�metros: -
* Descripci�n: Iniciliza los parametros del worldspace
* Autores: Denisse Pintado, Roger Granda, Gianni Carlo
*/
void init (void){
	
	glClearColor(1.0f,1.0f,1.0f,0.0f);
	glShadeModel(GL_SMOOTH);

	// habilitar luz
	glEnable(GL_LIGHTING);

	// configurar y habilitar luz
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glEnable(GL_LIGHT0);

	// Habilitar el rastreo de color
	glEnable(GL_COLOR_MATERIAL);

	// Poner las propiedades del material que se van a reflejar en glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	iniciarTablero();
	



}



/*
* Procedimiento: keyboard
* Par�metros: unsigned char key, int x, int y
* Descripci�n: Procedimiento que realiza las operaciones aritm�ticas involucradas en la rotaci�n del cuerpo
* Autor: Roger Granda
*/
void keyboard( unsigned char key, int x, int y ){
	switch ( key ) {
		case 'l':
			zPosicion=zPosicion-0.1;										
			break;
		case 'o':
			zPosicion=zPosicion+0.1;										
			break;
		case 'q':
			z_Spin=z_Spin+5.0;	
			if (z_Spin>360.0)
				z_Spin=z_Spin-360.0;								
			break;
		case 'e':									
			z_Spin=z_Spin-5.0;	
			if (z_Spin<-360)
				z_Spin=z_Spin+360.0;					
			break;
		case 'a':
			y_Spin=y_Spin+5.0;	
			if (y_Spin>360.0)
				y_Spin=y_Spin-360.0;								
			break;
		case 'd':									
			y_Spin=y_Spin-5.0;	
			if (y_Spin<-360)
				y_Spin=y_Spin+360.0;					
			break;
		case 'w':
			x_Spin=x_Spin+5.0;	
			if (x_Spin>360.0)
				x_Spin=x_Spin-360.0;								
			break;
		case 's':									
			x_Spin=x_Spin-5.0;	
			if (x_Spin<-360)
				x_Spin=x_Spin+360.0;					
			break;
		default:		
			break;
	}
	glutPostRedisplay();	
}

/*
* Procedimiento: handleSpecialKeypress
* Par�metros: int key, int x, int y
* Descripci�n: Procedimiento que realiza las operaciones aritm�ticas involucradas en la tranlaci�n del cuerpo
* Autor: Gianni Carlo
*/
void handleSpecialKeypress(int key, int x, int y) {
	switch ( key ) {
		case GLUT_KEY_UP:									
			yPosicion=yPosicion+0.1;				
			break;
		case GLUT_KEY_DOWN:													
			yPosicion=yPosicion-0.1;
			break;
		case GLUT_KEY_RIGHT:									
			xPosicion=xPosicion+0.1;		
			break;
		case GLUT_KEY_LEFT:									
			xPosicion=xPosicion-0.1;		
			break;
		default:									
			break;
	}
	glutPostRedisplay();
}
/*
* Funci�n: main
* Par�metros: int argc, char** argv
* Descripci�n: Punto de Inicio del programa
* Autor: Denisse Pintado, Gianni Carlo, Roger Granda
*/
int main( int argc, char** argv )
{
	/* std::cout << radioExternoT << std::endl;
	std::cout << radioE << std::endl;*/

	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH );
	glutInitWindowPosition( 200, 0 );
	glutInitWindowSize( ancho_plano,alto_plano );
	glutCreateWindow( "Proyecto 2do Parcial");
	init();
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LESS);
	glutIdleFunc(display);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(handleSpecialKeypress);	
	glutMainLoop();
	return 0;	
}
