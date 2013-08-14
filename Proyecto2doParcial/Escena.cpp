/**
*Proyecto 2 Gráficos por Computadora
*
* Integrantes:
*
*   Denisse Pintado
*	Gianni Carlo
*   Roger Granda
*   
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
GLfloat zPosicion = 13.0f;









//luz
//GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };

GLfloat  spot0_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat	 lightPos[] = { 0.0f, 8.0f, 0.0f,1.0f };
GLfloat  light0x=-3.0f;
GLfloat  light0z=-3.0f;

//Segunda Luz
GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot1_direction[] = { 0.0f,1.0f, 0.0f };
GLfloat  light1x=3.0f;
GLfloat  light1z=-3.0f;

GLfloat light2_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light2_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot2_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light2x=-3.0f;
GLfloat  light2z=0.0f;

GLfloat light3_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light3_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot3_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light3x=3.0f;
GLfloat  light3z=0.0f;

GLfloat light4_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light4_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot4_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light4x=-3.0f;
GLfloat  light4z=3.0f;

GLfloat light5_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light5_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot5_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light5x=3.0f;
GLfloat  light5z=3.0f;


// lista tablero
GLuint _displayListId_AreaNegra; 
GLuint _displayListId_AreaBlanca;



//esfera 
GLfloat x_SpinEsfera=0.0f;
GLfloat y_SpinEsfera=0.0f;
GLfloat z_SpinEsfera=0.0f;
GLfloat xPosicionEsfera = -3.0;
GLfloat yPosicionEsfera = 3.0;
GLfloat zPosicionEsfera= 3.0f;

// Toroide

GLfloat x_SpinToroide=0.0f;
GLfloat y_SpinToroide=0.0f;
GLfloat z_SpinToroide=0.0f;
GLfloat xPosicionToroide= 3.0;
GLfloat yPosicionToroide= 3.0;
GLfloat zPosicionToroide= 3.0f;



//Cubo  1.0,3.0,3.0
GLfloat x_SpinCubo=0.0f;
GLfloat y_SpinCubo=0.0f;
GLfloat z_SpinCubo=0.0f;
GLfloat xPosicionCubo = 1.0f;
GLfloat yPosicionCubo = 3.0f;
GLfloat zPosicionCubo = 3.0f;

//Cantina  
GLfloat x_SpinTea=0.0f;
GLfloat y_SpinTea=0.0f;
GLfloat z_SpinTea=0.0f;
GLfloat xPosicionTea = 0.0f;
GLfloat yPosicionTea = 3.0f;
GLfloat zPosicionTea = 0.0f;




//mastil 5.0,0.0,0.0
GLfloat x_SpinMastil=0.0f;
GLfloat y_SpinMastil=0.0f;
GLfloat z_SpinMastil=0.0f;
GLfloat xPosicionMastil = 5.0f;
GLfloat yPosicionMastil = 0.0f;
GLfloat zPosicionMastil = 0.0f;


//techo

GLfloat yPosicionTecho = 0.0f;




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

void luces(void){
	
	glPushMatrix();
	glTranslatef(light0x,0.0f,light0z);
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25.0);
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot0_direction);
		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.1);
		glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
		
	glPopMatrix();

	glPushMatrix();
		glTranslatef(light1x,0.0f,light1z);			

		glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	
	
		glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0);

		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25.0);
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot0_direction);
		glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.1);
		glLightfv(GL_LIGHT1,GL_POSITION,lightPos);
		
	glPopMatrix();





	glPushMatrix();
		glTranslatef(light2x,0.0f,light2z);

		glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
	
	
		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.0);
	
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 25.0);
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot2_direction);
		glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 0.1);
		glLightfv(GL_LIGHT2,GL_POSITION,lightPos);
	
	glPopMatrix();

	glPushMatrix();


		glTranslatef(light3x,0.0f,light3z);

		glLightfv(GL_LIGHT3, GL_DIFFUSE, light3_diffuse);
		glLightfv(GL_LIGHT3, GL_SPECULAR, light3_specular);
	
		glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.0);

		glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 25.0);
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot3_direction);
		glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 0.1);
		glLightfv(GL_LIGHT3,GL_POSITION,lightPos);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(light4x,0.0f,light4z);

	glLightfv(GL_LIGHT4, GL_DIFFUSE, light4_diffuse);
		glLightfv(GL_LIGHT4, GL_SPECULAR, light4_specular);
	
		glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.0);

		glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 25.0);
		glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot4_direction);
		glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 0.1);
		glLightfv(GL_LIGHT4,GL_POSITION,lightPos);
		
	glPopMatrix();

	glPushMatrix();
	glTranslatef(light5x,0.0f,light5z);

	glLightfv(GL_LIGHT5, GL_DIFFUSE, light5_diffuse);
		glLightfv(GL_LIGHT5, GL_SPECULAR, light5_specular);
	
		glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 0.0);

		glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 25.0);
		glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spot5_direction);
		glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 0.1);
		glLightfv(GL_LIGHT5,GL_POSITION,lightPos);
		
	glPopMatrix();


	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	
}

void lamparas(void){
	GLfloat no_emitir[] = { 0.0, 0.0, 0.0, 1.0 };

	//lampara1
	glPushMatrix();	
		glTranslatef(light0x,7.9f,light0z);
		glColor3f(1.0f,0.0f,0.0f);
		GLfloat lampara1[] = {1.0, 1.0, 1.0};
	
		 glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara1);
		glBegin(GL_QUADS);
		
			glVertex3f(-1.0f,0.0f,-1.0f);
			glVertex3f(-1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,-1.0f);											
		glEnd();

	glPopMatrix();
	//lampara2
	glPushMatrix();	
		glTranslatef(light1x,7.9f,light1z);
		glColor3f(1.0f,0.0f,0.0f);
		GLfloat lampara2[] = {1.0, 1.0, 1.0};

		 glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara2);
		glBegin(GL_QUADS);
		
			glVertex3f(-1.0f,0.0f,-1.0f);
			glVertex3f(-1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,-1.0f);											
		glEnd();

	glPopMatrix();
	//lampara3
	glPushMatrix();	
		glTranslatef(light2x,7.9f,light2z);
		glColor3f(1.0f,0.0f,0.0f);
		GLfloat lampara3[] = {1.0, 1.0, 1.0};
	
		 glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara3);
		glBegin(GL_QUADS);
		
			glVertex3f(-1.0f,0.0f,-1.0f);
			glVertex3f(-1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,-1.0f);											
		glEnd();

	glPopMatrix();
	//lampara4
	glPushMatrix();	
		glTranslatef(light3x,7.9f,light3z);
		glColor3f(1.0f,0.0f,0.0f);
		GLfloat lampara4[] = {1.0, 1.0, 1.0};

		 glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara4);
		glBegin(GL_QUADS);
		
			glVertex3f(-1.0f,0.0f,-1.0f);
			glVertex3f(-1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,-1.0f);											
		glEnd();

	glPopMatrix();
	//lampara5
	glPushMatrix();	
		glTranslatef(light4x,7.9f,light4z);
		glColor3f(1.0f,0.0f,0.0f);
		GLfloat lampara5[] = {1.0, 1.0, 1.0};

		 glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara5);
		glBegin(GL_QUADS);
		
			glVertex3f(-1.0f,0.0f,-1.0f);
			glVertex3f(-1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,-1.0f);											
		glEnd();

	glPopMatrix();
	//lampara6
	glPushMatrix();	
		glTranslatef(light5x,7.9f,light5z);
		glColor3f(1.0f,0.0f,0.0f);
		GLfloat lampara6[] = {1.0, 1.0, 1.0};		
		 glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara6);
		glBegin(GL_QUADS);
		
			glVertex3f(-1.0f,0.0f,-1.0f);
			glVertex3f(-1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,-1.0f);											
		glEnd();
		
	glPopMatrix();
	//Deshabilitar emision
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,no_emitir);
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
	gluLookAt(0.0,5.0,zPosicion,0.0,3.0,0.0,0.0,1.0,0.0);

	

	glColor3f(1.0,0.0,0.0);
	glPushMatrix();
	// manipular escena
	glRotatef(x_Spin,1.0,0.0,0.0);
	glRotatef(y_Spin,0.0,1.0,0.0);
	glRotatef(z_Spin,0.0,0.0,1.0);
	
	glTranslatef(xPosicion,yPosicion,0);

	luces();

	glPushMatrix();	
	
	

	dibujarTablero();

	glPopMatrix();

	//esfera
	glPushMatrix();
	
	glColor3f(0.945f,0.552f,0.0196f);
	
	glTranslatef(xPosicionEsfera,yPosicionEsfera,zPosicionEsfera);
	glRotatef(x_SpinEsfera,1.0f,0.0f,0.0f);
	glRotatef(y_SpinEsfera,0.0f,1.0f,0.0f);
	glRotatef(z_SpinEsfera,0.0f,0.0f,1.0f);
	glutSolidSphere(0.5,50,50);

	glPopMatrix();
	
	//toroide

	glPushMatrix();	
	
	glColor3f(0.0f,0.6313f,0.796f);
	glTranslatef(xPosicionToroide,yPosicionToroide, zPosicionToroide);
	glRotatef(x_SpinToroide,1.0f,0.0f,0.0f);
	glRotatef(y_SpinToroide,0.0f,1.0f,0.0f);
	glRotatef(z_SpinToroide,0.0f,0.0f,1.0f);
	glutSolidTorus(0.2,0.5,50,50);
	
	glPopMatrix();
	//cantina
	glPushMatrix();	
	glColor3f(0.89f,0.254f,0.192f);
	glTranslatef(xPosicionTea,yPosicionTea,zPosicionTea);
	glRotatef(x_SpinTea,1.0f,0.0f,0.0f);
	glRotatef(y_SpinTea,0.0f,1.0f,0.0f);
	glRotatef(z_SpinTea,0.0f,0.0f,1.0f);
	glutSolidTeapot(1.0);
	
	glPopMatrix();
	//cubo

	glPushMatrix();	
	glColor3f(0.89f,0.254f,0.192f);
	glTranslatef(xPosicionCubo,yPosicionCubo,zPosicionCubo);
	glRotatef(x_SpinCubo,1.0f,0.0f,0.0f);
	glRotatef(y_SpinCubo,0.0f,1.0f,0.0f);
	glRotatef(z_SpinCubo,0.0f,0.0f,1.0f);
	
	glutSolidCube(1.0);
	glPopMatrix();


	//Obelisco
	glPushMatrix();	
	
	glColor3f(0.003921569f,0.250980392f,0.643137255f);
	glTranslatef(xPosicionMastil,yPosicionMastil,zPosicionMastil);
	glRotatef(-90.0f,1.0,0.0f,0.0f);
	glRotatef(x_SpinMastil,1.0f,0.0f,0.0f);
	glRotatef(y_SpinMastil,0.0f,1.0f,0.0f);
	glRotatef(z_SpinMastil,0.0f,0.0f,1.0f);

	GLUquadricObj * qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj,GLU_FLAT);
	
	
	gluCylinder(qobj, 0.50, 0.25, 5.0, 4,4);

	

	
	
	glPopMatrix();

	//hasta de obelisco

	glPushMatrix();	
	
	glColor3f(0.003921569f,0.250980392f,0.643137255f);
	glTranslatef(xPosicionMastil,yPosicionMastil+5.0f,zPosicionMastil);
	glRotatef(-90.0f,1.0,0.0f,0.0f);
	glRotatef(x_SpinMastil,1.0f,0.0f,0.0f);
	glRotatef(y_SpinMastil,0.0f,1.0f,0.0f);
	glRotatef(z_SpinMastil,0.0f,0.0f,1.0f);
	glutSolidCone(0.25,0.4,4,4);

	
	
	glPopMatrix();

	//techo

	



	glPushMatrix();	
	glTranslatef(-6.0f,8.0f,6.0f);
	glBegin(GL_QUADS);
	glColor3f(0.05f,0.77f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(12.0f,0.0f,0.0f);
	glVertex3f(12.0f,0.0f,-12.0f);
	glVertex3f(0.0f,0.0f,-12.0f);
	glEnd();
	glPopMatrix();
	
	
	
	
	//lamparas
	lamparas();
	
	

	
	
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
	
	glClearColor(1.0f,1.0f,1.0f,0.0f);
	glShadeModel(GL_SMOOTH);

	// habilitar luz
	glEnable(GL_LIGHTING);
	 glEnable(GL_NORMALIZE);

	// configurar y habilitar luz
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
	//glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
	/*glLightfv(GL_LIGHT1,GL_POSITION,lightPos);
	glEnable(GL_LIGHT1);
*/
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
* Parámetros: int key, int x, int y
* Descripción: Procedimiento que realiza las operaciones aritméticas involucradas en la tranlación del cuerpo
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
