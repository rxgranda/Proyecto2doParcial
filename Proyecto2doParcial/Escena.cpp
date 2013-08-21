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

// lista tablero del piso
GLuint _displayListId_AreaNegra; 
GLuint _displayListId_AreaBlanca;

//Esfera 
GLfloat *x_SpinEsfera;
GLfloat *y_SpinEsfera;
GLfloat *z_SpinEsfera;
GLfloat *xPosicionEsfera;
GLfloat *yPosicionEsfera;
GLfloat *zPosicionEsfera;
GLfloat *animacionEsfera;

// Toroide
GLfloat *x_SpinToroide;
GLfloat *y_SpinToroide;
GLfloat *z_SpinToroide;
GLfloat *xPosicionToroide;
GLfloat *yPosicionToroide;
GLfloat *zPosicionToroide;
GLfloat *animacionToroide;

//Cubo 
GLfloat *x_SpinCubo;
GLfloat *y_SpinCubo;
GLfloat *z_SpinCubo;
GLfloat *xPosicionCubo ;
GLfloat *yPosicionCubo ;
GLfloat *zPosicionCubo ;
GLfloat *animacionCubo;

//Cantina  
GLfloat *x_SpinTea;
GLfloat *y_SpinTea;
GLfloat *z_SpinTea;
GLfloat *xPosicionTea;
GLfloat *yPosicionTea;
GLfloat *zPosicionTea;
GLfloat *animacionTea;

//mastil 5.0,0.0,0.0
GLfloat *x_SpinMastil;
GLfloat *y_SpinMastil;
GLfloat *z_SpinMastil;
GLfloat *xPosicionMastil;
GLfloat *yPosicionMastil;
GLfloat *zPosicionMastil;

//techo
GLfloat yPosicionTecho = 8.0f;
int objeto=1;

//Luces
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

//Tercera Luz
GLfloat light2_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light2_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot2_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light2x=-3.0f;
GLfloat  light2z=0.0f;

//Cuarta Luz
GLfloat light3_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light3_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot3_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light3x=3.0f;
GLfloat  light3z=0.0f;

//Quinta Luz
GLfloat light4_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light4_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot4_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light4x=-3.0f;
GLfloat  light4z=3.0f;

//Sexta Luz
GLfloat light5_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light5_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot5_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light5x=3.0f;
GLfloat  light5z=3.0f;

GLuint textura1;

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
	//Primera  Luz
	glPushMatrix();
		glTranslatef(light0x,0.0f,light0z);
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25.0);
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot0_direction);
		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.1);
		glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glPopMatrix();
	//Segunda  Luz
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

	//Tercera Luz
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

	//Cuarta  Luz
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

	//Quinta  Luz
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

	//Sexta  Luz
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

	//Habilitar Luces
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

int debeRotar(float objetoX, float objetoZ){
	float x=objetoX-(float)*xPosicionMastil;
	float z=objetoZ-(float)*zPosicionMastil;
	x=pow(x,2.0f);
	z=pow(z,2.0f);
	float dis=sqrt(x+z);
	if (dis >=1.5)
		return 0;
	else 
		return 1;
}



void animar(GLfloat * animar,GLfloat* posiciony){
	glTranslatef(*xPosicionMastil,*posiciony,*zPosicionMastil);
	glRotatef(*animar, 0.0f, 1.0f, 0.0f);		
	glTranslatef(1.0,0.0,0.0);
	*animar+=0.5f;
	if((*animar)>360.0f)
		*animar=0.0f;
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
	
		//inicializar las luces
		luces();

		//dibujar piso con el tablero
		glPushMatrix();	
			dibujarTablero();
		glPopMatrix();

		//esfera
		glPushMatrix();
			glColor3f(0.945f,0.552f,0.0196f);
			if(debeRotar((float)(*xPosicionEsfera),(float)(*zPosicionEsfera))==1){
				animar(animacionEsfera,yPosicionEsfera);		
			}else{
				glTranslatef(*xPosicionEsfera,*yPosicionEsfera,*zPosicionEsfera);
			}
			glRotatef(*x_SpinEsfera,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinEsfera,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinEsfera,0.0f,0.0f,1.0f);
			glutSolidSphere(0.5,50,50);
		glPopMatrix();

		//toroide

		glPushMatrix();	
			glColor3f(0.0f,0.6313f,0.796f);
			if(debeRotar((float)(*xPosicionToroide),(float)(*zPosicionToroide))==1){
				animar(animacionToroide,yPosicionToroide);		
			}else{
				glTranslatef(*xPosicionToroide,*yPosicionToroide,*zPosicionToroide);
			}
			glRotatef(*x_SpinToroide,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinToroide,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinToroide,0.0f,0.0f,1.0f);
			glutSolidTorus(0.2,0.5,50,50);
		glPopMatrix();

		//cantina
		glPushMatrix();	
			//glColor3f(0.89f,0.254f,0.192f);
		glEnable( GL_TEXTURE_2D );		//1
			glBindTexture(GL_TEXTURE_2D, textura1);	//2	
			glColor4f(1.0, 1.0, 1.0, 1.0); //3
			if(debeRotar((float)(*xPosicionTea),(float)(*zPosicionTea))==1){
				animar(animacionTea,yPosicionTea);		
			}else{
				glTranslatef(*xPosicionTea,*yPosicionTea,*zPosicionTea);
			}
			glRotatef(*x_SpinTea,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinTea,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinTea,0.0f,0.0f,1.0f);
			glutSolidTeapot(1.0);
			glDisable( GL_TEXTURE_2D ); //4
		glPopMatrix();
		
		//cubo
		glPushMatrix();	
			//glColor3f(0.89f,0.254f,0.192f);
		glEnable( GL_TEXTURE_2D );	
		   glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, textura1);
			

			
			if(debeRotar((float)(*xPosicionCubo),(float)(*zPosicionCubo))==1){
				animar(animacionCubo,yPosicionCubo);		
			}else{
				glTranslatef(*xPosicionCubo,*yPosicionCubo,*zPosicionCubo);
			}
			glRotatef(*x_SpinCubo,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinCubo,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinCubo,0.0f,0.0f,1.0f);
			glutSolidCube(1.0);
			glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glDisable(GL_TEXTURE_GEN_T);
				glDisable( GL_TEXTURE_2D ); //4
		glPopMatrix();

		//mastil
		glPushMatrix();	
			//glColor3f(0.003921569f,0.250980392f,0.643137255f);
			glEnable( GL_TEXTURE_2D );		//1
			glBindTexture(GL_TEXTURE_2D, textura1);	//2	
			glColor4f(1.0, 1.0, 1.0, 1.0); //3
				
			glTranslatef(*xPosicionMastil,*yPosicionMastil,*zPosicionMastil);
			glRotatef(-90.0f,1.0,0.0f,0.0f);
			glRotatef(*x_SpinMastil,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinMastil,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinMastil,0.0f,0.0f,1.0f);
			GLUquadricObj * qobj;
			qobj = gluNewQuadric();
			//gluQuadricDrawStyle(qobj,GLU_FLAT);
			
			gluQuadricNormals(qobj, GLU_SMOOTH);
			gluQuadricTexture(qobj, GL_TRUE);
						
			gluCylinder(qobj, 0.50, 0.25, 5.0, 4,4);
			
			glDisable( GL_TEXTURE_2D ); //4
		glPopMatrix();

		//hasta de mastil
		glPushMatrix();	
			glColor3f(0.003921569f,0.250980392f,0.643137255f);
			glTranslatef(*xPosicionMastil,*yPosicionMastil+5.0f,*zPosicionMastil);
			glRotatef(-90.0f,1.0,0.0f,0.0f);
			glRotatef(*x_SpinMastil,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinMastil,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinMastil,0.0f,0.0f,1.0f);
			glutSolidCone(0.25,0.4,4,4);
		glPopMatrix();

		//techo
		glPushMatrix();	
			glTranslatef(-6.0f,yPosicionTecho,6.0f);
			glBegin(GL_QUADS);
				glColor3f(0.05f,0.77f,1.0f);
				glVertex3f(0.0f,0.0f,0.0f);
				glVertex3f(12.0f,0.0f,0.0f);
				glVertex3f(12.0f,0.0f,-12.0f);
				glVertex3f(0.0f,0.0f,-12.0f);
			glEnd();
		glPopMatrix();

		// Dibujar las lamparas
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


void aumentar(GLfloat * pos){
	*pos+=0.1f;
}
void disminuir(GLfloat * pos){
	*pos-=0.1f;
}
void handleSpecialKeypress(int key, int x, int y) {
	switch ( key ) {
	case GLUT_KEY_UP:	
		switch (objeto){
		case 0:
			yPosicion=yPosicion+0.1;	
			break;
		case 1:
			disminuir(zPosicionCubo);					
			break;
		case 2:
			disminuir(zPosicionTea);					
			break;
		case 3:
			disminuir(zPosicionToroide);					
			break;
		case 4:
			disminuir(zPosicionEsfera);					
			break;
		default:
			break;
		}

		break;
	case GLUT_KEY_DOWN:	
		switch (objeto){
		case 0:
			yPosicion=yPosicion-0.1;
			break;
		case 1:
			aumentar(zPosicionCubo);
			break;
		case 2:
			aumentar(zPosicionTea);					
			break;
		case 3:
			aumentar(zPosicionToroide);					
			break;
		case 4:
			aumentar(zPosicionEsfera);					
			break;
		default:
			break;
		}
		break;
	case GLUT_KEY_RIGHT:
		switch (objeto){
		case 0:
			xPosicion=xPosicion+0.1;			
			break;
		case 1:
			aumentar(xPosicionCubo);	
			break;
		case 2:
			aumentar(xPosicionTea);					
			break;
		case 3:
			aumentar(xPosicionToroide);					
			break;
		case 4:
			aumentar(xPosicionEsfera);					
			break;
		default:
			break;
		}
		break;
	case GLUT_KEY_LEFT:	
		switch (objeto){
		case 0:
			xPosicion=xPosicion-0.1;		
			break;
		case 1:
			disminuir(xPosicionCubo);
			break;
		case 2:
			disminuir(xPosicionTea);					
			break;
		case 3:
			disminuir(xPosicionToroide);					
			break;
		case 4:
			disminuir(xPosicionEsfera);					
			break;
		default:
			break;
		}
		break;
	default:									
		break;
	}
	glutPostRedisplay();
}

GLuint LoadTexture( const char * filename, int width, int height )
{
    GLuint texture;
    unsigned char * data;
    FILE * file;

    //The following code will read in our RAW file
    file = fopen( filename, "rb" );
    if ( file == NULL ) return 0;
    data = (unsigned char *)malloc( width * height * 3 );
    fread( data, width * height * 3, 1, file );
    fclose( file );

    glGenTextures( 1, &texture ); //generate the texture with the loaded data
    glBindTexture( GL_TEXTURE_2D, texture ); //bind the textureto it’s array
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE ); //set texture environment parameters

    //here we are setting what textures to use and when. The MINfilter is which quality to show
    //when the texture is near the view, and the MAG filter is whichquality to show when the texture
    //is far from the view.

    //The qualities are (in order from worst to best)
    //GL_NEAREST
    //GL_LINEAR
    //GL_LINEAR_MIPMAP_NEAREST
    //GL_LINEAR_MIPMAP_LINEAR

    //And if you go and use extensions, you can use Anisotropic filtering textures which are of an
    //even better quality, but this will do for now.
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

    //Here we are setting the parameter to repeat the texture instead of clamping the texture
    //to the edge of our shape. 
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

    //Generate the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,  GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
    free( data ); //free the texture
    return texture; //return whether it was successfull
}



void FreeTexture( GLuint texture )
{
  glDeleteTextures( 1, &texture ); 
}



/*
* Función: main
* Parámetros: int argc, char** argv
* Descripción: Punto de Inicio del programa
* Autor: Denisse Pintado, Gianni Carlo, Roger Granda
*/
int main( int argc, char** argv )
{
	//esfera 
	GLfloat x_SpinEsferaV=0.0f;
	GLfloat y_SpinEsferaV=0.0f;
	GLfloat z_SpinEsferaV=0.0f;
	GLfloat xPosicionEsferaV = -3.0f;
	GLfloat yPosicionEsferaV = 3.0f;
	GLfloat zPosicionEsferaV= 3.0f;

	x_SpinEsfera=& x_SpinEsferaV;
	y_SpinEsfera=& y_SpinEsferaV;
	z_SpinEsfera=& z_SpinEsferaV;
	xPosicionEsfera = &xPosicionEsferaV;
	yPosicionEsfera = &yPosicionEsferaV;
	zPosicionEsfera= &zPosicionEsferaV;

	// Toroide
	GLfloat x_SpinToroideV=0.0f;
	GLfloat y_SpinToroideV=0.0f;
	GLfloat z_SpinToroideV=0.0f;
	GLfloat xPosicionToroideV= 3.0f;
	GLfloat yPosicionToroideV= 3.0f;
	GLfloat zPosicionToroideV= 3.0f;

	x_SpinToroide=&x_SpinToroideV;
	y_SpinToroide=&y_SpinToroideV;
	z_SpinToroide=&z_SpinToroideV;
	xPosicionToroide= &xPosicionToroideV;
	yPosicionToroide= &yPosicionToroideV;
	zPosicionToroide= &zPosicionToroideV;

	//CUBO
	GLfloat x_SpinCuboV=0.0f;
	GLfloat y_SpinCuboV=0.0f;
	GLfloat z_SpinCuboV=0.0f;
	GLfloat xPosicionCuboV = 0.0f;
	GLfloat yPosicionCuboV = 3.0f;
	GLfloat zPosicionCuboV = 3.0f;

	x_SpinCubo=&x_SpinCuboV;
	y_SpinCubo=&y_SpinCuboV;
	z_SpinCubo=&z_SpinCuboV;
	xPosicionCubo = &xPosicionCuboV;
	yPosicionCubo = &yPosicionCuboV;
	zPosicionCubo = &zPosicionCuboV;

	//Cantina  
	GLfloat x_SpinTeaV=0.0f;
	GLfloat y_SpinTeaV=0.0f;
	GLfloat z_SpinTeaV=0.0f;
	GLfloat xPosicionTeaV= 0.0f;
	GLfloat yPosicionTeaV= 3.0f;
	GLfloat zPosicionTeaV= 0.0f;

	x_SpinTea=&x_SpinTeaV;
	y_SpinTea=&y_SpinTeaV;
	z_SpinTea=&z_SpinTeaV;
	xPosicionTea=& xPosicionTeaV;
	yPosicionTea=& yPosicionTeaV;
	zPosicionTea=& zPosicionTeaV;

	//mastil 
	GLfloat x_SpinMastilV=0.0f;
	GLfloat y_SpinMastilV=0.0f;
	GLfloat z_SpinMastilV=0.0f;
	GLfloat xPosicionMastilV= 5.0f;
	GLfloat yPosicionMastilV= 0.0f;
	GLfloat zPosicionMastilV= 0.0f;

	x_SpinMastil=&x_SpinMastilV;
	y_SpinMastil=&y_SpinMastilV;
	z_SpinMastil=&z_SpinMastilV;
	xPosicionMastil=&xPosicionMastilV;
	yPosicionMastil=&yPosicionMastilV;
	zPosicionMastil=&zPosicionMastilV;

	GLfloat animacionEsferaV=0.0f;
	GLfloat animacionToroideV=0.0f;
	GLfloat animacionCuboV=0.0f;
	GLfloat animacionTeaV=0.0f;

	animacionEsfera=&animacionEsferaV;
	animacionToroide=&animacionToroideV;
	animacionCubo=&animacionCuboV;
	animacionTea=&animacionTeaV;


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
		textura1 = LoadTexture( "textura4.bmp", 200,200);
	glutMainLoop();
	//FreeTexture( textura1 );
	return 0;	
}