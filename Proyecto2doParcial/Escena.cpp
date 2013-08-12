/**
*Proyecto 2 Gráficos por Computadora
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

int objeto=0;
GLfloat ancho_plano=900.0;
GLfloat alto_plano=700.0;





//camara
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
	glColor3f(0.05f,0.05f,0.05f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(1.50f,0.0f,0.0f);
	glVertex3f(1.5f,0.3f,0.0f);
	glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.05f,0.05f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.05f,0.05f);
	glVertex3f(1.5f,0.0f,0.0f);
	glVertex3f(1.5f,0.0f,-1.5f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(1.5f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.05f,0.05f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glVertex3f(1.50f,0.0f,-1.5f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.05f,0.05f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(1.50f,0.0f,0.0f);
	glVertex3f(1.5f,0.0f,-1.5f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.3f,0.0f);
	glVertex3f(1.50f,0.3f,0.0f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
} 
void dibujarEspacioBlanco() { 
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.05f,0.05f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(1.50f,0.0f,0.0f);
	glVertex3f(1.5f,0.3f,0.0f);
	glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.05f,0.05f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.05f,0.05f);
	glVertex3f(1.5f,0.0f,0.0f);
	glVertex3f(1.5f,0.0f,-1.5f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(1.5f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.05f,0.05f);
	glVertex3f(0.0f,0.0f,-1.5f);
	glVertex3f(1.50f,0.0f,-1.5f);
	glVertex3f(1.5f,0.3f,-1.5f);
	glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.05f,0.05f);
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
* Parámetros: int w, int h
* Descripción: Establece el worldspace, model, y viewport de la escena
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
* Parámetros: -
* Descripción: Realiza los procesos geométricos del cuerpo (Rotación y traslación del cuerpo), y Rasterizado del cuerpo y el plano cartesiano 
* Autores: Denisse Pintado, Roger Granda, Gianni Carlo
*/
void display (void){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0,5.0,zPosicion,0.0,0.0,0.0,0.0,1.0,0.0);


	glColor3f(1.0,0.0,0.0);
	glPushMatrix();	
	
	(void)dibujarTablero();

	glPopMatrix();
	glutSwapBuffers();

}

/*
* Procedimiento: init
* Parámetros: -
* Descripción: Iniciliza los parametros del worldspace
* Autores: Denisse Pintado, Roger Granda, Gianni Carlo
*/
void init (void){
	glClearColor(1.0,1.0,1.0,0.0);
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
* Parámetros: unsigned char key, int x, int y
* Descripción: Procedimiento que realiza las operaciones aritméticas involucradas en la rotación del cuerpo
* Autor: Roger Granda
*/
void keyboard( unsigned char key, int x, int y ){
	switch ( key ) {

	case 'l': // ZOOM OUT		
		zPosicion=zPosicion-0.1;			
		break;
	case 'o':	// ZOOM IN		
		zPosicion=zPosicion+0.1;				
		break;

	default:		
		break;
	}
	glutPostRedisplay();	
}

/*
* Procedimiento: handleSpecialKeypress
* Parámetros: int key, int x, int y
* Descripción: Procedimiento que realiza las operaciones aritméticas involucradas en la tranlación del cuerpo
* Autor: Gianni Carlo
*/
void handleSpecialKeypress(int key, int x, int y) {

	glutPostRedisplay();
}

/*
* Función: main
* Parámetros: int argc, char** argv
* Descripción: Punto de Inicio del programa
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
