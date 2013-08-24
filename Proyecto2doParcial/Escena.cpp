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
*/
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

//Características del mundo
GLfloat ancho_plano=900.0;
GLfloat alto_plano=700.0;
GLfloat x_Spin=0.0f;
GLfloat y_Spin=0.0f;
GLfloat z_Spin=0.0f;
GLfloat xPosicion = 0.0f;
GLfloat yPosicion = 0.0f;
GLfloat zPosicion = 12.0f;

// listas del tablero del piso
GLuint _displayListId_AreaCeleste; 
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

//mastil
GLfloat *x_SpinMastil;
GLfloat *y_SpinMastil;
GLfloat *z_SpinMastil;
GLfloat *xPosicionMastil;
GLfloat *yPosicionMastil;
GLfloat *zPosicionMastil;

//techo
GLfloat yPosicionTecho = 8.0f;
int objeto=0;

//Luces
//Primera Luz
GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  spot0_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat	 lightPos[] = { 0.0f, 8.0f, 0.0f,1.0f };
GLfloat  light0x=-2.0f;
GLfloat  light0z=-3.0f;

//Segunda Luz
GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot1_direction[] = { 0.0f,1.0f, 0.0f };
GLfloat  light1x=2.0f;
GLfloat  light1z=-3.0f;

//Tercera Luz
GLfloat light2_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light2_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot2_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light2x=-2.0f;
GLfloat  light2z=0.0f;

//Cuarta Luz
GLfloat light3_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light3_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot3_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light3x=2.0f;
GLfloat  light3z=0.0f;

//Quinta Luz
GLfloat light4_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light4_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot4_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light4x=-2.0f;
GLfloat  light4z=3.0f;

//Sexta Luz
GLfloat light5_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light5_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat  spot5_direction[] = { 0.0f,-1.0f, 0.0f };
GLfloat  light5x=2.0f;
GLfloat  light5z=3.0f;


// Controladores de Iluminación de escena 1=ON 0=OFF
int switchL1=1;
int switchL2=1;
int switchL3=1;
int switchL4=1;
int switchL5=1;
int switchL6=1;

//Texturas 
GLuint noTextura =0;
GLuint textura1;
GLuint textura2;
GLuint textura3;
GLuint textura4;
GLuint textura5;
GLuint textura6;

//Texturasde objetos
GLuint * texturaBlancas;
GLuint * texturaCelestes;
GLuint * texturaEsfera;
GLuint * texturaToroide;
GLuint * texturaTea;
GLuint * texturaCubo;
GLuint * texturaMastil;


/*
* Procedimiento: dibujarEspacioCeleste
* Parámetros: -
* Descripción: Permite definir todas las baldosas de color celeste en el piso de la escena
* Autor: Roger Granda
*/
void dibujarEspacioCeleste() {
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.77f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f,0.0f,0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.50f,0.0f,0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.5f,0.3f,0.0f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.77f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f,0.0f,0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.0f,0.0f,-1.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.0f,0.3f,-1.5f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.77f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(1.5f,0.0f,0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.5f,0.0f,-1.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(1.5f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.77f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f,0.0f,-1.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.50f,0.0f,-1.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.77f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f,0.0f,0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.50f,0.0f,0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.5f,0.0f,-1.5f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(0.0f,0.0f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.77f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f,0.3f,0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.50f,0.3f,0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
}

/*
* Procedimiento: dibujarEspacioBlanco
* Parámetros: -
* Descripción: Permite definir todas las baldosas de color blanco en la escena
* Autor: Roger Granda
*/
void dibujarEspacioBlanco() { 
	glBegin(GL_QUADS);	
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f,0.0f,0.0f);
		glTexCoord2f(1.0f, 0.0f);		
		glVertex3f(1.50f,0.0f,0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.5f,0.3f,0.0f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);	
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f,0.0f,0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.0f,0.0f,-1.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.0f,0.3f,-1.5f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);		
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(1.5f,0.0f,0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.5f,0.0f,-1.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(1.5f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);	
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f,0.0f,-1.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.50f,0.0f,-1.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);		
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f,0.0f,0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.50f,0.0f,0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.5f,0.0f,-1.5f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(0.0f,0.0f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);		
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f,0.3f,0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.50f,0.3f,0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glTexCoord2f(0.0f, 1.0f );
		glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();		
}

/*
* Procedimiento: iniciarTablero
* Parámetros: -
* Descripción: Permite enlistar las baldosas que se dibujaran en el piso
* Autor: Roger Granda
*/
void iniciarTablero (void){
	_displayListId_AreaCeleste = glGenLists(1); 
	glNewList(_displayListId_AreaCeleste, GL_COMPILE); 
		dibujarEspacioCeleste(); 
	glEndList();
	_displayListId_AreaBlanca = glGenLists(2); 
	glNewList(_displayListId_AreaBlanca, GL_COMPILE); 
		dibujarEspacioBlanco(); 
	glEndList();
}

/*
* Procedimiento: dibujarTablero
* Parámetros: -
* Descripción: Permite establecer el piso dentro de la escena
* Fuente: www.openglprojects.in/2013/02/chess-board-in-opengl-computer-graphics.html
* Modificado por: Roger Granda
*/
void dibujarTablero (void){
	glTranslatef(-4*1.5, 0.0, 4*1.5);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	int k=0;
	for(float j=0.0;j>(-8*1.5);j-=1.5) {
		k++;
		for(float i=0.0;i<(4*3.0);i+=3.0) {
			if(k%2==0) {
				glPushMatrix();
				glLoadName(2);
				glTranslatef(i,0.0,j);				
				if(*texturaCelestes!=noTextura){
					glEnable( GL_TEXTURE_2D );	
					glBindTexture(GL_TEXTURE_2D, *texturaCelestes);						
				}
				glCallList(_displayListId_AreaCeleste);
				glDisable( GL_TEXTURE_2D );					
				glPopMatrix();
			}
			else {
				glPushMatrix();
				glLoadName(2);
				glTranslatef(i+1.5,0.0,j);
					if(*texturaCelestes!=noTextura){
					glEnable( GL_TEXTURE_2D );	
					glBindTexture(GL_TEXTURE_2D,  *texturaCelestes);						
				}
				glCallList(_displayListId_AreaCeleste);
				glDisable( GL_TEXTURE_2D );	
				glPopMatrix();
			}
		}
	}
	for(float j=0.0;j>(-8*1.5);j-=1.5) {
		k++;
		for(float i=0.0;i<(4*3.0);i+=3.0) {
			if(k%2!=0) {
				glPushMatrix();
					glLoadName(1);
					glTranslatef(i,0.0,j);
					if(*texturaBlancas!=noTextura){
						glEnable( GL_TEXTURE_2D );		
						glBindTexture(GL_TEXTURE_2D, *texturaBlancas);			
					}
					glCallList(_displayListId_AreaBlanca);
					glDisable( GL_TEXTURE_2D );	
				glPopMatrix();
			}
			else {
				glPushMatrix();
					glLoadName(1);
					glTranslatef(i+1.5,0.0,j);
					if(*texturaBlancas!=noTextura){
						glEnable( GL_TEXTURE_2D );		
						glBindTexture(GL_TEXTURE_2D, *texturaBlancas);	

					}
					glCallList(_displayListId_AreaBlanca);
					glDisable( GL_TEXTURE_2D );	
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
* Procedimiento: luces
* Parámetros: -
* Descripción: Permite la deficinión de las 6 fuentes de luz que utilizará la escena
* Autor: Roger Granda
*/
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
	//Habilitar\Deshabilitar Luces
	if(switchL1==1)
		glEnable(GL_LIGHT0);
	else
		glDisable(GL_LIGHT0);

	if(switchL2==1)
		glEnable(GL_LIGHT1);
	else
		glDisable(GL_LIGHT1);

	if(switchL3==1)
		glEnable(GL_LIGHT2);
	else
		glDisable(GL_LIGHT2);

	if(switchL4==1)
		glEnable(GL_LIGHT3);
	else
		glDisable(GL_LIGHT3);

	if(switchL5==1)
		glEnable(GL_LIGHT4);
	else
		glDisable(GL_LIGHT4);

	if(switchL6==1)
		glEnable(GL_LIGHT5);
	else
		glDisable(GL_LIGHT5);
	
}

/*
* Procedimiento: lamparas
* Parámetros: -
* Descripción: Permite ubicar en el mundo 6 cuadrados que simularán la prescencia visible de las funtes de luz
* Autor: Roger Granda
*/
void lamparas(void){
	GLfloat no_emitir[] = { 0.0, 0.0, 0.0, 1.0 };			
	//lampara1	
	glPushMatrix();			
		glTranslatef(light0x,7.9f,light0z);		
		glColor3f(1.0f,0.0f,0.0f);
		GLfloat lampara1[] = {1.0, 1.0, 1.0};
		if(switchL1==1)
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara1);		
		else{
			glColor3f(0.5,0.5,0.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,no_emitir);
		}		
		glLoadName(8);
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
		if(switchL2==1)
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara2);	
		else{
			glColor3f(0.5,0.5,0.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,no_emitir);
		}		
		glLoadName(9);
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
		if(switchL3==1)
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara3);	
		else{
			glColor3f(0.5,0.5,0.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,no_emitir);
		}
		glLoadName(10);
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
		if(switchL4==1)
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara4);
		else{
			glColor3f(0.5,0.5,0.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,no_emitir);
		}
		glLoadName(11);
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
		if(switchL5==1)
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara5);
		else{
			glColor3f(0.5,0.5,0.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,no_emitir);
		}
		glLoadName(12);
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
		if(switchL6==1)
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,lampara6);
		else{
			glColor3f(0.5,0.5,0.5);
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,no_emitir);
		}		
		glLoadName(13);
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
* Procedimiento: debeRotar
* Parámetros: float objetoX, float objetoZ
* Descripción: Permite conocer si el objeto que tiene las coordenadas X y Z de los parametros debe empezar a rotar alrededor del mástil
* Return: 1= true, 0=false
* Autor: Roger Granda
*/
int debeRotar(float objetoX, float objetoZ){
	float x=objetoX-(float)*xPosicionMastil;
	float z=objetoZ-(float)*zPosicionMastil;
	x=pow(x,2.0f);
	z=pow(z,2.0f);
	float dis=x+z-2.25;
	if (dis >=0)
		return 0;
	else 
		return 1;
}


/*
* Procedimiento: animar
* Parámetros: GLfloat * animar,GLfloat* posiciony
* Descripción: Realiza la animación alrededor del mástil, a través del cálculo numérico de su posición.
* Autor: Roger Granda
*/
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
* Descripción: Realiza los procesos geométricos de los cuerpos (Rotación y traslación del cuerpo), y Rasterizado de los cuerpos de la escena
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
			glLoadName(3);			
			if(*texturaEsfera!=noTextura){
				glEnable( GL_TEXTURE_2D );	
				glEnable(GL_TEXTURE_GEN_S); 
				glEnable(GL_TEXTURE_GEN_T);
				glBindTexture(GL_TEXTURE_2D, *texturaEsfera);
				glColor4f(1.0, 1.0, 1.0, 1.0);					
			}else{
				glColor3f(0.945f,0.552f,0.0196f);
			}
			if(debeRotar((float)(*xPosicionEsfera),(float)(*zPosicionEsfera))==1){
				animar(animacionEsfera,yPosicionEsfera);		
			}else{
				glTranslatef(*xPosicionEsfera,*yPosicionEsfera,*zPosicionEsfera);
			}
			glRotatef(*x_SpinEsfera,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinEsfera,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinEsfera,0.0f,0.0f,1.0f);
			glutSolidSphere(0.5,50,50);
			glDisable( GL_TEXTURE_2D ); 
		glPopMatrix();

		//toroide
		glPushMatrix();	
			glLoadName(4);			
			if(*texturaToroide!=noTextura){
				glEnable( GL_TEXTURE_2D );	
				glEnable(GL_TEXTURE_GEN_S);
				glEnable(GL_TEXTURE_GEN_T);
				glBindTexture(GL_TEXTURE_2D, *texturaToroide);
				glColor4f(1.0, 1.0, 1.0, 1.0);	
			}else{
				glColor3f(0.0f,0.6313f,0.796f);
			}
			if(debeRotar((float)(*xPosicionToroide),(float)(*zPosicionToroide))==1){
				animar(animacionToroide,yPosicionToroide);		
			}else{
				glTranslatef(*xPosicionToroide,*yPosicionToroide,*zPosicionToroide);
			}
			glRotatef(*x_SpinToroide,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinToroide,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinToroide,0.0f,0.0f,1.0f);
			glutSolidTorus(0.2,0.5,50,50);		
			glDisable( GL_TEXTURE_2D ); 
		glPopMatrix();

		//cantina
		glPushMatrix();
			glLoadName(5);			
			if(*texturaTea!=noTextura){
				glEnable( GL_TEXTURE_2D );		
				glBindTexture(GL_TEXTURE_2D, *texturaTea);	
				glColor4f(1.0, 1.0, 1.0, 1.0); 			
			}else{
				glColor3f(0.89f,0.254f,0.192f);
			}				
			if(debeRotar((float)(*xPosicionTea),(float)(*zPosicionTea))==1){
				animar(animacionTea,yPosicionTea);		
			}else{
				glTranslatef(*xPosicionTea,*yPosicionTea,*zPosicionTea);
			}
			glRotatef(*x_SpinTea,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinTea,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinTea,0.0f,0.0f,1.0f);
			glutSolidTeapot(1.0);
			glDisable( GL_TEXTURE_2D ); 
		glPopMatrix();
		
		//cubo
		glPushMatrix();	
			glLoadName(6);			
			if(*texturaCubo!=noTextura){
				glEnable( GL_TEXTURE_2D );	
				glEnable(GL_TEXTURE_GEN_S); 
				glEnable(GL_TEXTURE_GEN_T);
				glBindTexture(GL_TEXTURE_2D, *texturaCubo);											
			}else{
				glColor3f(1.0f,1.0f,0.0f);	
			}									
			if(debeRotar((float)(*xPosicionCubo),(float)(*zPosicionCubo))==1){
				animar(animacionCubo,yPosicionCubo);		
			}else{
				glTranslatef(*xPosicionCubo,*yPosicionCubo,*zPosicionCubo);
			}
			glRotatef(*x_SpinCubo,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinCubo,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinCubo,0.0f,0.0f,1.0f);
			glutSolidCube(1.0);
			glDisable(GL_TEXTURE_GEN_S); 
			glDisable(GL_TEXTURE_GEN_T);
			glDisable( GL_TEXTURE_2D );
		glPopMatrix();

		//mastil
		glPushMatrix();	
			glLoadName(7);					
			glTranslatef(*xPosicionMastil,*yPosicionMastil,*zPosicionMastil);
			glRotatef(-90.0f,1.0,0.0f,0.0f);
			glRotatef(*x_SpinMastil,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinMastil,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinMastil,0.0f,0.0f,1.0f);
			GLUquadricObj * qobj;
			qobj = gluNewQuadric();						
			if(*texturaMastil!=noTextura){
				glEnable( GL_TEXTURE_2D );	
				glColor4f(1.0, 1.0, 1.0, 1.0); 
				glBindTexture(GL_TEXTURE_2D, *texturaMastil);													
			}else{
				glColor3f(0.003921569f,0.250980392f,0.643137255f);	
			}			
			gluQuadricNormals(qobj, GLU_SMOOTH);
			gluQuadricTexture(qobj, GL_TRUE);						
			gluCylinder(qobj, 0.50, 0.25, 5.0, 4,4);			
			glDisable( GL_TEXTURE_2D ); 
		glPopMatrix();

		//hasta de mastil
		glPushMatrix();	
			glLoadName(7);	
			if(*texturaMastil!=noTextura){
				glEnable( GL_TEXTURE_2D );	
				glColor4f(1.0, 1.0, 1.0, 1.0); 
				glBindTexture(GL_TEXTURE_2D, *texturaMastil);	
			}else{
				glColor3f(0.003921569f,0.250980392f,0.643137255f);	
			}
			glTranslatef(*xPosicionMastil,*yPosicionMastil+5.0f,*zPosicionMastil);
			glRotatef(-90.0f,1.0,0.0f,0.0f);
			glRotatef(*x_SpinMastil,1.0f,0.0f,0.0f);
			glRotatef(*y_SpinMastil,0.0f,1.0f,0.0f);
			glRotatef(*z_SpinMastil,0.0f,0.0f,1.0f);
			glutSolidCone(0.25,0.4,4,4);
			glDisable( GL_TEXTURE_2D ); 
		glPopMatrix();

		//techo
		glPushMatrix();	
			glLoadName(0);
			glTranslatef(-6.0f,yPosicionTecho,6.0f);		
			glBegin(GL_QUADS);
				glColor3f(1.0f,1.0f,0.0f);
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
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
	// Habilitar el rastreo de color
	glEnable(GL_COLOR_MATERIAL);
	// Poner las propiedades del material que se van a reflejar en glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	iniciarTablero();
}

/*
* Procedimiento: processHits
* Parámetros: GLint hits, GLuint nameBuffer[]
* Descripción: procesa los hits (objetos debajo del cursor del mouse) y retorna el Id del objeto más cercano
* Autor: Gianni Carlo
*/
int processHits( GLint hits, GLuint nameBuffer[] )
{
	unsigned int i;
	unsigned int j;
    GLuint names;
    GLuint* pPtr;
	GLuint* temp;
	float pasado;
    pPtr = nameBuffer;
	temp = nameBuffer;
	unsigned int seleccionado=0;
    for( i = 0; i < hits; ++i )
    {
		names = *pPtr;
		++pPtr;
		++temp;			
		if(i!=0){
			temp = pPtr;
			//se compara si la coordenada z del nuevo objeto es menor que el del pasado objeto
			if(pasado>(*pPtr/(pow(2.0 , 32.0)-1.0))){
				pasado = *pPtr/(pow(2.0 , 32.0)-1.0);
				++temp;
				++temp;
				seleccionado = *temp;
			}
		
		}else{
			pasado = *pPtr/(pow(2.0 , 32.0)-1.0);
			++temp;
			++temp;
			seleccionado = *temp;
		}

		++pPtr;
		++pPtr;
		for( j = 0; j < names; ++j, ++pPtr )
		{
		}
    }
	return seleccionado;
}

/*
* Procedimiento: mouse
* Parámetros: GLint hits, GLuint nameBuffer[]
* Descripción: procesa los eventos del mouse
* Autor: Gianni Carlo, Roger Granda
*/
GLvoid mouse(GLint button, GLint state, GLint x, GLint y){
	GLuint nameBuffer[50];
	GLint hits;
	GLint viewport[4];
	GLfloat projMatrix[16];
	unsigned int nameId;
	if( GLUT_LEFT_BUTTON == button && GLUT_DOWN == state )
	{
		glSelectBuffer( 50, nameBuffer ); //Declarar buffer de los hits
        glRenderMode( GL_SELECT ); // Cambiar a modo de seleccion
		// Inicializar el stack de nombres
		glInitNames();        
		glPushName( 70 ); // dummy						
		// Conseguir una copia de la matrix de proyección actual
		glGetFloatv( GL_PROJECTION_MATRIX, projMatrix );
		glMatrixMode( GL_PROJECTION );
		glPushMatrix();
		glLoadIdentity();
		// Reducir el viewport a una dimensión de 1x1
		glGetIntegerv( GL_VIEWPORT, viewport );
		gluPickMatrix( (GLdouble)x, (GLdouble)( viewport[3] - y ), 1, 1, viewport );		
		glMultMatrixf( projMatrix );
		glMatrixMode( GL_MODELVIEW );        
		display();
		glFlush();
		// Restaurar la matrix de proyección
		glMatrixMode( GL_PROJECTION );
		glPopMatrix();
		glMatrixMode( GL_MODELVIEW );
		hits = glRenderMode( GL_RENDER );
		if( -1 != hits )
		{
			nameId = processHits( hits, nameBuffer );
			switch (nameId)
			{				
			case 1:
				cout<<"Objeto seleccionado:\n";
				cout<<"Baldosas blancas\n\n";
				objeto=1;			
				break;
			case 2:
				objeto=2;
				cout<<"Objeto seleccionado:\n";
				cout<<"Baldosas celestes\n\n";
				break;
			case 3:
				objeto=3;
				cout<<"Objeto seleccionado:\n";
				cout<<"esfera\n\n";
				break;
			case 4:
				objeto=4;
				cout<<"Objeto seleccionado:\n";
				cout<<"toroide\n\n";
				break;
			case 5:
				objeto=5;
				cout<<"Objeto seleccionado:\n";
				cout<<"tea\n\n";
				break;
			case 6:
				objeto=6;
				cout<<"Objeto seleccionado:\n";
				cout<<"cubo\n\n";
				break;
			case 7:
				cout<<"Objeto seleccionado:\n";
				cout<<"mastil\n\n";
				objeto=7;
				break;
			case 8:
				cout<<"Objeto seleccionado:\n";
				cout<<"luz1\n\n";
				objeto=0;
				switchL1=(switchL1+1)%2;
				break;
			case 9:
				cout<<"Objeto seleccionado:\n";
				cout<<"luz2\n\n";
				objeto=0;
				switchL2=(switchL2+1)%2;
				break;
			case 10:
				cout<<"Objeto seleccionado:\n";
				cout<<"luz3\n\n";
				objeto=0;
				switchL3=(switchL3+1)%2;
				break;
			case 11:
				cout<<"Objeto seleccionado:\n";
				cout<<"luz4\n\n";
				objeto=0;
				switchL4=(switchL4+1)%2;
				break;
			case 12:
				cout<<"Objeto seleccionado:\n";
				cout<<"luz5\n\n";
				objeto=0;
				switchL5=(switchL5+1)%2;
				break;
			case 13:
				cout<<"Objeto seleccionado:\n";
				cout<<"luz6\n\n";
				objeto=0;
				switchL6=(switchL6+1)%2;
				break;
			default:
				cout<<"Objeto seleccionado:\n Mundo\n\n";
				objeto = 0;
				break;
			}
		}
		else
		{
			fprintf( stderr, "hits overflowed\n" );
		}
	}
}


void aumentar(GLfloat * pos){
	*pos+=0.1f;
}
void disminuir(GLfloat * pos){
	*pos-=0.1f;
}


/*
* Procedimiento: keyboard
* Parámetros: unsigned char key, int x, int y
* Descripción: Procedimiento que realiza las operaciones aritméticas involucradas en la rotación del cuerpo
* Autor: Gianni Carlo, Dennise Pintado, Roger Granda
*/
void keyboard( unsigned char key, int x, int y ){
	switch ( key ) {
	case 'l':
		switch (objeto){
			case 0:
				zPosicion=zPosicion+0.1;	
				break;
			case 3:
				if(*zPosicionEsfera<5.5){
					aumentar(zPosicionEsfera);
				}
				break;
			case 4:
				if(*zPosicionToroide<5.8){
					aumentar(zPosicionToroide);
				}
				break;
			case 5:
				if(*zPosicionTea<5.0){
					aumentar(zPosicionTea);
				}
				break;
			case 6:
				if(*zPosicionCubo<5.5){
					aumentar(zPosicionCubo);
				}
				break;
			case 7:
				if(*zPosicionMastil<5.5){
					aumentar(zPosicionMastil);
				}
				break;
			default:
				break;
		}
		break;
	case 'o':
		switch (objeto){
			case 0:
				zPosicion=zPosicion-0.1;	
				break;
			case 3:
				if(*zPosicionEsfera>-5.5){
					disminuir(zPosicionEsfera);
				}
				break;
			case 4:
				if(*zPosicionToroide>-5.8){
					disminuir(zPosicionToroide);					
				}
				break;
			case 5:
				if(*zPosicionTea>-5){
					disminuir(zPosicionTea);
				}
				break;
			case 6:
				if(*zPosicionCubo>-5.5){
					disminuir(zPosicionCubo);
				}
				break;
			case 7:
				if(*zPosicionMastil>-5.5){
					disminuir(zPosicionMastil);
				}
				break;
			default:
				break;
		}
		break;
	case 'q':		
		switch (objeto){
			case 0:
				z_Spin=z_Spin+5;	
				if (z_Spin>360)
					z_Spin=z_Spin-360;	
				break;
			case 3:
				*z_SpinEsfera=*z_SpinEsfera+5;	
				if (*z_SpinEsfera>360)
					*z_SpinEsfera=*z_SpinEsfera-360;
				break;
			case 4:
				*z_SpinToroide=*z_SpinToroide+5;	
				if (*z_SpinToroide>360)
					*z_SpinToroide=*z_SpinToroide-360;						
				break;
			case 5:
				*z_SpinTea=*z_SpinTea+5;	
				if (*z_SpinTea>360)
					*z_SpinTea=*z_SpinTea-360;
				break;
			case 6:
				*z_SpinCubo=*z_SpinCubo+5;	
				if (*z_SpinCubo>360)
					*z_SpinCubo=*z_SpinCubo-360;					
				break;
			default:
				break;
		}
		break;
	case 'e':									
		switch (objeto){
			case 0:
				z_Spin=z_Spin-5;	
				if (z_Spin>360)
					z_Spin=z_Spin+360;	
				break;
			case 3:
				*z_SpinEsfera=*z_SpinEsfera-5;	
				if (*z_SpinEsfera>360)
					*z_SpinEsfera=*z_SpinEsfera+360;
				break;
			case 4:
				*z_SpinToroide=*z_SpinToroide-5;	
				if (*z_SpinToroide>360)
					*z_SpinToroide=*z_SpinToroide+360;						
				break;
			case 5:
				*z_SpinTea=*z_SpinTea-5;
				if (*z_SpinTea>360)
					*z_SpinTea=*z_SpinTea+360;
				break;
			case 6:
				*z_SpinCubo=*z_SpinCubo-5;	
				if (*z_SpinCubo>360)
					*z_SpinCubo=*z_SpinCubo+360;					
				break;
			default:
				break;
			}					
			break;
		case 'a':
			switch (objeto){
			case 0:
				y_Spin=y_Spin+5;	
				if (y_Spin>360)
					y_Spin=y_Spin-360;	
				break;
			case 3:
				*y_SpinEsfera=*y_SpinEsfera+5;	
				if (*y_SpinEsfera>360)
					*y_SpinEsfera=*y_SpinEsfera-360;
				break;
			case 4:
				*y_SpinToroide=*y_SpinToroide+5;	
				if (*y_SpinToroide>360)
					*y_SpinToroide=*y_SpinToroide-360;						
				break;
			case 5:
				*y_SpinTea=*y_SpinTea+5;	
				if (*y_SpinTea>360)
					*y_SpinTea=*y_SpinTea-360;
				break;
			case 6:
				*y_SpinCubo=*y_SpinCubo+5;	
				if (*y_SpinCubo>360)
					*y_SpinCubo=*y_SpinCubo-360;					
				break;
			default:
				break;
		}								
		break;
	case 'd':									
		switch (objeto){
			case 0:
				y_Spin=y_Spin-5;	
				if (y_Spin>360)
					y_Spin=y_Spin+360;	
				break;
			case 3:
				*y_SpinEsfera=*y_SpinEsfera-5;	
				if (*y_SpinEsfera>360)
					*y_SpinEsfera=*y_SpinEsfera+360;
				break;
			case 4:
				*y_SpinToroide=*y_SpinToroide-5;	
				if (*y_SpinToroide>360)
					*y_SpinToroide=*y_SpinToroide+360;						
				break;
			case 5:
				*y_SpinTea=*y_SpinTea-5;
				if (*y_SpinTea>360)
					*y_SpinTea=*y_SpinTea+360;
				break;
			case 6:
				*y_SpinCubo=*y_SpinCubo-5;	
				if (*y_SpinCubo>360)
					*y_SpinCubo=*y_SpinCubo+360;					
				break;
			default:
				break;
		}						
		break;
	case 'w':
		switch (objeto){
			case 0:
				x_Spin=x_Spin+5;	
				if (x_Spin>360)
					x_Spin=x_Spin-360;	
				break;
			case 3:
				*x_SpinEsfera=*x_SpinEsfera+5;	
				if (*x_SpinEsfera>360)
					*x_SpinEsfera=*x_SpinEsfera-360;
				break;
			case 4:
				*x_SpinToroide=*x_SpinToroide+5;	
				if (*x_SpinToroide>360)
					*x_SpinToroide=*x_SpinToroide-360;						
				break;
			case 5:
				*x_SpinTea=*x_SpinTea+5;	
				if (*x_SpinTea>360)
					*x_SpinTea=*x_SpinTea-360;
				break;
			case 6:
				*x_SpinCubo=*x_SpinCubo+5;	
				if (*x_SpinCubo>360)
					*x_SpinCubo=*x_SpinCubo-360;					
				break;
			default:
				break;
			}									
		break;
	case 's':									
		switch (objeto){
			case 0:
				x_Spin=x_Spin-5;	
				if (x_Spin>360)
					x_Spin=x_Spin+360;	
				break;
			case 3:
				*x_SpinEsfera=*x_SpinEsfera-5;	
				if (*x_SpinEsfera>360)
					*x_SpinEsfera=*x_SpinEsfera+360;
				break;
			case 4:
				*x_SpinToroide=*x_SpinToroide-5;	
				if (*x_SpinToroide>360)
					*x_SpinToroide=*x_SpinToroide+360;						
				break;
			case 5:
				*x_SpinTea=*x_SpinTea-5;
				if (*x_SpinTea>360)
					*x_SpinTea=*x_SpinTea+360;
				break;
			case 6:
				*x_SpinCubo=*x_SpinCubo-5;	
				if (*x_SpinCubo>360)
					*x_SpinCubo=*x_SpinCubo+360;					
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

/*
* Procedimiento: handleSpecialKeypress
* Parámetros: int key, int x, int y
* Descripción: Procedimiento que realiza las operaciones aritméticas involucradas en la tranlación del cuerpo
* Autor: Gianni Carlo, Denisse Pintado
*/
void handleSpecialKeypress(int key, int x, int y) {
	switch ( key ) {
	case GLUT_KEY_UP:	
		switch (objeto){
			case 0:
				yPosicion=yPosicion-0.1;	
				break;
			case 3:
				if(*yPosicionEsfera<7.4){
					aumentar(yPosicionEsfera);			
				}
				break;
			case 4:
				if(*yPosicionToroide<7.3){
					aumentar(yPosicionToroide);
				}
				break;
			case 5:
				if(*yPosicionTea<7.2){
					aumentar(yPosicionTea);
				}
				break;
			case 6:
				if(*yPosicionCubo<7.5){
					aumentar(yPosicionCubo);
				}
				break;
			case 7:
				if(*yPosicionMastil<2.6){
					aumentar(yPosicionMastil);
				}
				break;
			default:
				break;
		}
		break;
	case GLUT_KEY_DOWN:	
		switch (objeto){
			case 0:
				yPosicion=yPosicion+0.1;
				break;
			case 3:
				if(*yPosicionEsfera>0.75){
					disminuir(yPosicionEsfera);
				}
				break;
			case 4:
				if(*yPosicionToroide>0.95){
					disminuir(yPosicionToroide);
				}
				break;
			case 5:
				if(*yPosicionTea>1){
					disminuir(yPosicionTea);
				}
				break;
			case 6:
				if(*yPosicionCubo>0.85){
					disminuir(yPosicionCubo);
				}
				break;
			case 7:
				if(*yPosicionMastil>0.3){
					disminuir(yPosicionMastil);
				}
				break;
			default:
				break;
		}
		break;
	case GLUT_KEY_RIGHT:
		switch (objeto){
			case 0:
				xPosicion=xPosicion-0.1;			
				break;
			case 3:
				if(*xPosicionEsfera<5.5){
					aumentar(xPosicionEsfera);
				}
				break;
			case 4:
				if(*xPosicionToroide<5.1){
					aumentar(xPosicionToroide);
				}
				break;
			case 5:
				if(*xPosicionTea<4.2){
					aumentar(xPosicionTea);
				}
				break;
			case 6:
				if(*xPosicionCubo<5.4){
					aumentar(xPosicionCubo);
				}
				break;
			case 7:
				if(*xPosicionMastil<5.5){
					aumentar(xPosicionMastil);
				}
				break;
			default:
				break;
		}
		break;
	case GLUT_KEY_LEFT:	
		switch (objeto){
			case 0:
				xPosicion=xPosicion+0.1;
				break;
			case 3:
				if(*xPosicionEsfera>-5.4){
					disminuir(xPosicionEsfera);			
				}
				break;
			case 4:
				if(*xPosicionCubo>-5.2){
					disminuir(xPosicionToroide);
				}
				break;
			case 5:
				if(*xPosicionTea>-4.7){
					disminuir(xPosicionTea);
				}
				break;
			case 6:
				if(*xPosicionCubo>-5.4){
					disminuir(xPosicionCubo);
				}
				break;
			case 7:
				if(*xPosicionMastil>-5.45){
					disminuir(xPosicionMastil);		
				}
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

/*
* Procedimiento: CargarTexturas
* Parámetros:  const char * filename, int width, int height
* Descripción: Carga en memoria las texturas que se utilizaran en la escena
* Autor: Denisse Pintado, Roger Granda
*/
GLuint CargarTexturas( const char * filename, int width, int height )
{
    GLuint texture;
    unsigned char * data;
    FILE * file; 
    file = fopen( filename, "rb" );
    if ( file == NULL ) return 0;
    data = (unsigned char *)malloc( width * height * 3 );
    fread( data, width * height * 3, 1, file );
    fclose( file );
    glGenTextures( 1, &texture ); 
    glBindTexture( GL_TEXTURE_2D, texture ); 
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE ); 
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,  GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
    free( data ); 
    return texture;
}

/*
* Procedimiento: LiberarTexturas
* Parámetros:  GLuint texturet
* Descripción: Libera de la memoria las texturas que se utilizaran en la escena
* Autor: Denisse Pintado, Roger Granda
*/
void LiberarTexturas( GLuint texture )
{
  glDeleteTextures( 1, &texture ); 
}

/*
* Procedimiento: cambiarTextura
* Parámetros: int val
* Descripción: Cambia la textura del objeto seleccionado, de acuerdo a la opción que escoge el usuario en el menú contextual
* Autor: Roger Granda
*/
void cambiarTextura (int val)
{
	GLuint* texturaSeleccionada;	
	switch (val){
		case 0:			
			texturaSeleccionada=&noTextura;
		break;
		case 1:				
			texturaSeleccionada=&textura1;
			break;
		case 2:			
			texturaSeleccionada=&textura2;
			break;
		case 3:			
			texturaSeleccionada=&textura3;
			break;
		case 4:			
			texturaSeleccionada=&textura4;
			break;
		case 5:			
			texturaSeleccionada=&textura5;
			break;
		case 6:			
			texturaSeleccionada=&textura6;
			break;
		default:
			break;
	}
	switch (objeto){
		case 1:
			texturaBlancas=texturaSeleccionada;
			break;
		case 2:
			texturaCelestes=texturaSeleccionada;
			break;
		case 3:
			texturaEsfera=texturaSeleccionada;
			break;
		case 4:
			texturaToroide=texturaSeleccionada;
			break;
		case 5:
			texturaTea=texturaSeleccionada;
			break;
		case 6:
			texturaCubo=texturaSeleccionada;
			break;
		case 7:
			texturaMastil=texturaSeleccionada;
			break;		
		default:
			break;
	}    
}

/*
* Procedimiento: setupMenus
* Parámetros: -
* Descripción: Carga las opciones del menú contextual, que se utilizará para cambiar la textura de los objetos.
* Autor: Roger Granda
*/
void setupMenus(){
	glutCreateMenu(cambiarTextura);
	glutAddMenuEntry("Sin Textura", 0);
	glutAddMenuEntry("Textura 1", 1);
	glutAddMenuEntry("Textura 2", 2);
	glutAddMenuEntry("Textura 3", 3);
	glutAddMenuEntry("Textura 4", 4);
	glutAddMenuEntry("Textura 5", 5);
	glutAddMenuEntry("Textura 6", 6);
  glutAttachMenu(GLUT_RIGHT_BUTTON); 
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
	GLfloat xPosicionToroideV= 2.0f;
	GLfloat yPosicionToroideV= 3.0f;
	GLfloat zPosicionToroideV= 1.0f;

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
	GLfloat xPosicionCuboV = -2.0f;
	GLfloat yPosicionCuboV = 3.0f;
	GLfloat zPosicionCuboV = 2.0f;

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
	GLfloat zPosicionTeaV= 2.0f;

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
	GLfloat xPosicionMastilV= 3.0f;
	GLfloat yPosicionMastilV= 0.0f;
	GLfloat zPosicionMastilV= 4.0f;

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
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LESS);
	glutIdleFunc(display);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(handleSpecialKeypress);	
	
	glutMouseFunc(mouse);
	setupMenus();
	textura1 = CargarTexturas( "textura1.bmp", 200,200);
	textura2 = CargarTexturas( "textura2.bmp", 200,200);
	textura3 = CargarTexturas( "textura3.bmp", 200,200);
	textura4 = CargarTexturas( "textura4.bmp", 200,200);
	textura5 = CargarTexturas( "textura5.bmp", 200,200);
	textura6 = CargarTexturas( "textura6.bmp", 200,200);

	texturaBlancas=&noTextura;
	texturaCelestes=&noTextura;
	texturaEsfera=&noTextura;
    texturaToroide=&noTextura;
	texturaTea=&noTextura;
	texturaCubo=&noTextura;
	texturaMastil=&noTextura;
	init();
	fprintf( stderr, "-----------Menu--------------\n" );
	fprintf( stderr, "\n" );
	fprintf( stderr, "Teclas:\n" );
		fprintf( stderr, "\n" );
	fprintf( stderr, "Direccionales: Movimiento en X e Y\n" );
	fprintf( stderr, "O,L: Movimiento en Z\n" );
	fprintf( stderr, "W,S: Rotacion alrededor de eje X\n" );
	fprintf( stderr, "A,D: Rotacion alrededor de eje Y\n" );
	fprintf( stderr, "Q,E: Rotacion alrededor de eje Z\n" );
	fprintf( stderr, "\n" );
	fprintf( stderr, "\n" );
	fprintf( stderr, "Nota: Seleccionar con el mouse,el elemento que se desea mover, rotar o cambiar textura\n" );
	fprintf( stderr, "\n" );
	fprintf( stderr, "Nota2:Click Derecho despliega el menu contextual de textura del elemento seleccionado\n" );

	fprintf( stderr, "-----------------------------\n" );
	glutMainLoop();
	LiberarTexturas( textura1 );
	LiberarTexturas( textura2 );
	LiberarTexturas( textura3 );
	LiberarTexturas( textura4 );
	LiberarTexturas( textura5 );
	LiberarTexturas( textura6 );
	return 0;	
}