//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************Guevara Chávez Marco A.					******//
//*************Ramírez Ancona Simón Eduardo				******//
//************************************************************//
//************************************************************//
#include "WINDOWS.h"
#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

int w = 500, h = 500;
int frame=0,tiempo,timebase=0;
int deltaTime = 0;

float time= 0.0;
float posx = 0.0;
float posy = 0.0;
float PosXini = 0.0;
float vini = 9.0;
float g = 9.81;
float ang_ini = 45;
bool inicia_tiro = false;
bool giro_reloj = false;
bool p_giro = false, p_giro2 = false, g_animacion = false;
float gr = 0;


float rot = 180.0f, movX = 0, mX = 0, mZ = 0, rot2 = 0,
movZ = 0.0, rotTires = 0.0, rotK = 180.0, MX = -34, MY = 30,
rotB = 180, movBX = 0, movBZ = 0;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Ambient[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 107.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat Material_Rojo[] = { 1.0, 0.0, 0.0, 0.6 };
GLfloat Material_Blanco[] = { 1.0, 1.0, 1.0 };
GLfloat Material_Verde[] = { 0.0, 1.0, 0.0 };
GLfloat Material_Negro[] = { 0.0, 0.0, 0.0 };
GLfloat Material_Amarillo[] = { 1.0, 1.0, 0.0 };


CTexture text1, t_mural, t_coche,t_pasto, t_nubes;
CTexture text2;
CTexture text3;	//Flecha
CTexture tabique1;
CTexture minterior1;
CTexture techoC;
CTexture techoEx;
CTexture tPiso;
CTexture pasto;
CTexture gris;
CTexture ventana;
CTexture puer, puer2;
CTexture sill, mad, bur, madb, madn, escrit, teclado, met, mac,
cb, cc, mac2, mouse, madn2, madc, piedra, libro, libro2, post1, tapa;
CTexture lamp, lamp1, marron, respaldo, almohada, almohada1, colchon, base,
cajon, carp, madebl, cds0, cds1, cuadrocd;

/////////////////////////////////////////////////
CTexture aguaG;
CTexture tAlfombra;
CTexture baseGarrafon;
CTexture bocina;
CTexture hoja;
CTexture tcolchon;
CTexture tlibro;
CTexture maderaAzul;
CTexture pTapiz;
CTexture tMaceta;
CTexture tSillon;
CTexture mReloj;


CTexture pisoBanio;
CModel tasaBanio;

/*ELEMENTOS CUARTO PRINCIPAL */
CTexture ventanal, piso2, pos2, alf, blanco, resp_principal, 
colchon2, base_c;

CTexture A1, A2, A3, A4, A5; // Cielo;
CTexture pixa_ball;
CTexture tree;
CFiguras fig1;
CFiguras fig3;
CFiguras cuarto;
CFiguras techoCuarto;
CFiguras sky;
CFiguras pisoCuarto;
CFiguras muro;
CFiguras s, b, m, k, t, a;
CFiguras clibrero, creloj, cmaceta;
CFiguras ccama;

CModel silla_office, bocho, avion, sofa, maceta, spider, audifonos, lampara_mesa;

CModel silla_prins;


bool f_animacion = false, f_mover = false, f_mover2 = false,

m_animacion = false,
m_mover = false, m_mover2 = false,
p_mover = false, p_animacion = false, p_mover2 = false;





//Fachada recamara 1
void cascaron_recamara1(void) {
	glPushMatrix(); //paredes
		glTranslatef(0, 20, 0);
		cuarto.skybox2(60.0, 85.0, 85.0, gris.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, 50, 0);
		techoCuarto.prisma(1, 90, 90,techoC.GLindex, techoEx.GLindex, gris.GLindex);// TECHO DE LA CASA
		glPushMatrix();//muro izquierdo
			glTranslatef(-41.99, -30, 0);
			muro.prisma_gen(60, 1, 85, marron.GLindex, marron.GLindex);
		glPopMatrix();
		glPushMatrix();//muro derecho
			glTranslatef(41.99, -30, 0);
			muro.prisma_gen(60, 1, 85, marron.GLindex, marron.GLindex);
		glPopMatrix();
		glPushMatrix();//ventana
			glTranslatef(-10, -30, -42);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			muro.prisma(30, 30, 1, ventana.GLindex, gris.GLindex, gris.GLindex);
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();
		//muro ventanas
		glPushMatrix();
			glTranslatef(23.74,-30 , -42);
			glRotatef(90, 1, 0, 0);
			muro.prisma(1, 37.5, 60, gris.GLindex, minterior1.GLindex, gris.GLindex );
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-33.74, -30, -42);
			glRotatef(90, 1, 0, 0);
			muro.prisma(1, 17.5, 60, gris.GLindex, minterior1.GLindex, gris.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-10, -52.5, -42);
			glRotatef(90, 1, 0, 0);
			muro.prisma(1, 30, 15, gris.GLindex, minterior1.GLindex, gris.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-10, -7.5, -42);
			glRotatef(90, 1, 0, 0);
			muro.prisma(1, 30, 15, gris.GLindex, minterior1.GLindex, gris.GLindex);
		glPopMatrix();// fin muro ventana
		// Muro puerta *******************************
		glPushMatrix();
			glTranslatef(-27.5, -35, 42);
			glRotatef(rot, 0, 1, 0);
			glTranslatef(-7.5, 0, 0);
			muro.prisma(50, 15, .5, puer2.GLindex, gris.GLindex, gris.GLindex);//puerta exterior
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-27.5, -35, 42.5);
			glRotatef(rot, 0, 1, 0);
			glTranslatef(-7.5, 0, 0);
			muro.prisma(50, 15, .5, puer.GLindex, gris.GLindex, gris.GLindex); //puerta interior
		glPopMatrix();
		glPushMatrix();
			glTranslatef(15, -30, 42.5);
			glRotatef(90, 1, 0, 0);
			muro.prisma(1, 54.9, 60, minterior1.GLindex, gris.GLindex, gris.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-35, -30, 42.5);
			glRotatef(90, 1, 0, 0);
			muro.prisma(1, 14.9, 60, minterior1.GLindex, gris.GLindex, gris.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-20, -5, 42.5);
			glRotatef(90, 1, 0, 0);
			muro.prisma(1, 15.2, 10, minterior1.GLindex, gris.GLindex, gris.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -10, 0);
	pisoCuarto.prisma(1, 85, 85, gris.GLindex, tPiso.GLindex, gris.GLindex);// piso cuarto
		/*//pasto
		glTranslatef(0, -1, 0);
		pisoCuarto.prisma(1, 350, 350, pasto.GLindex, pasto.GLindex, pasto.GLindex);
		//patio
		glTranslatef(-62.5, 1, -10);
		pisoCuarto.prisma(1, 40, 60, piedra.GLindex, piedra.GLindex, piedra.GLindex);*/
	glPopMatrix();
}


//fachada recamara 2 - Rec. principal
void cascaron_recamara2(void) {
	glPushMatrix(); //paredes
		glTranslatef(0, 20, 0);
		cuarto.skybox3(50.0, 29.0, 52.0, gris.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, 45, 0);
		techoCuarto.prisma(1, 29.0, 52,techoC.GLindex, techoEx.GLindex, gris.GLindex);// TECHO DE LA CASA
		//**********muro izquierdo
		glPushMatrix();
			glTranslatef(-14.22, -25.5, -15);
			muro.prisma_gen(50, 0.5, 20, gris.GLindex, marron.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-14.23, -30, 0.5);
			glRotatef(90, 0, 1, 0);
			glRotatef(rot, 0, 1, 0);
			glTranslatef(-2.5, 0, 0);
			muro.prisma(40, 6.0, 0.5, puer2.GLindex, gris.GLindex, gris.GLindex);//puerta baño exterior
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-14.22, -30, 0.5);
			glRotatef(90, 0, 1, 0);
			glRotatef(rot, 0, 1, 0);
			glTranslatef(-2.5, 0, 0);
			muro.prisma(40, 6.0, 0.5, puer.GLindex, gris.GLindex, gris.GLindex); //puerta baño interior
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-14.22, -5, -2.0);
			muro.prisma_gen(10, 0.5, 6, gris.GLindex, marron.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-14.22, -25.5, 13.50);
			muro.prisma_gen(50, 0.5, 25, gris.GLindex, marron.GLindex);
		glPopMatrix();

		glPushMatrix();//muro derecho
			glTranslatef(14.22, -25, 0);
			glRotatef(180, 0, 0, 1);
			muro.prisma_gen(50, 0.5, 51.99, gris.GLindex, marron.GLindex);
		glPopMatrix();

		glPushMatrix();//ventana
			glTranslatef(0, -25, -25.5);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			muro.prisma(25, 15, 0.2, ventanal.GLindex, gris.GLindex, gris.GLindex);
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();
		//muro ventanas
		glPushMatrix();
			glTranslatef(0, -6.2 , -25.5);
			glRotatef(90, 1, 0, 0);
			glRotatef(180, 0, 0, 1);
			muro.prisma_gen(1, 15, 12.5, gris.GLindex, marron.GLindex);//minterior1.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0 , -44, -25.5);
			glRotatef(90, 1, 0, 0);
			glRotatef(180, 0, 0, 1);
			muro.prisma_gen(1, 15, 13.5, gris.GLindex, marron.GLindex);//minterior1.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-11, -25.5, -25.5);
			glRotatef(90, 1, 0, 0);
			muro.prisma(1, 7, 50.5, gris.GLindex, marron.GLindex, gris.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(11, -25.5, -25.5);
			glRotatef(90, 1, 0, 0);
			muro.prisma(1, 7, 50.5, gris.GLindex, marron.GLindex, gris.GLindex);
		glPopMatrix();// fin muro ventana
		// Muro puerta *******************************
		glPushMatrix();
			glTranslatef(-13.5, -30, 25.5);
			glRotatef(rot, 0, 1, 0);
			glTranslatef(-2.5, 0, 0);
			muro.prisma(40, 6.0, 0.5, puer2.GLindex, gris.GLindex, gris.GLindex);//puerta exterior
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-13.5, -30, 25.6);
			glRotatef(rot, 0, 1, 0);
			glTranslatef(-2.5, 0, 0);
			muro.prisma(40, 6.0, 0.5, puer.GLindex, gris.GLindex, gris.GLindex); //puerta interior
		glPopMatrix();
		glPushMatrix();
			glTranslatef(3.0, -25.1, 25.8);
			glRotatef(90, 1, 0, 0);
			muro.prisma(0.6, 22.5, 51, marron.GLindex, pTapiz.GLindex, gris.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-11.0, -4.85, 25.8);
			glRotatef(90, 1, 0, 0);
			muro.prisma(0.6, 6, 10.45, marron.GLindex, pTapiz.GLindex, gris.GLindex);
		glPopMatrix();//fin muro puerta
	glPopMatrix();

	
	glPushMatrix();
		glTranslatef(0, -5.5, 0);
		pisoCuarto.prisma(1, 29, 51, gris.GLindex, piso2.GLindex, gris.GLindex);// piso cuarto
	glPopMatrix();
}

void cascaron_recamaraA(void) {
	glPushMatrix(); //paredes
	glTranslatef(0, 20, 0);
	cuarto.skybox3(50.0, 29.0, 52.0, gris.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 45, 0);
	techoCuarto.prisma(1, 29.0, 52, techoC.GLindex, techoEx.GLindex, gris.GLindex);// TECHO DE LA CASA
	//**********muro izquierdo
	glPushMatrix();
	glTranslatef(-14.22, -25.5, -15);
	muro.prisma_gen(50, 0.5, 20, gris.GLindex, pTapiz.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-14.23, -30, 0.5);
	glRotatef(90, 0, 1, 0);
	glRotatef(rot, 0, 1, 0);
	glTranslatef(-2.5, 0, 0);

	muro.prisma(40, 6.0, 0.5, puer2.GLindex, gris.GLindex, gris.GLindex);//puerta baño exterior
	glPopMatrix();

	//Muro puerta
	glPushMatrix();
	glTranslatef(-14.22, -30, 0.5);
	glRotatef(90, 0, 1, 0);
	glRotatef(rot, 0, 1, 0);
	glTranslatef(-2.5, 0, 0);
	muro.prisma(40, 6.0, 0.5, puer.GLindex, gris.GLindex, gris.GLindex); //puerta baño interior
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-14.22, -5, -2.0);
	muro.prisma_gen(10, 0.5, 6, gris.GLindex, pTapiz.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-14.22, -25.5, 13.50);
	muro.prisma_gen(50, 0.5, 25, gris.GLindex, pTapiz.GLindex);
	glPopMatrix();


	glPushMatrix();//muro derecho
	glTranslatef(14.22, -25, 0);
	glRotatef(180, 0, 0, 1);
	muro.prisma_gen(50, 0.5, 51.99, gris.GLindex, pTapiz.GLindex);
	glPopMatrix();


	glPushMatrix();//ventana
	glTranslatef(0, -25, -25.5);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	muro.prisma(25, 15, 0.2, ventanal.GLindex, gris.GLindex, gris.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//muro ventanas
	glPushMatrix();
	glTranslatef(0, -6.2, -25.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 0, 1);
	muro.prismaA(1, 15, 12.5,pTapiz.GLindex, gris.GLindex,gris.GLindex);//minterior1.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -44, -25.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 0, 1);
	muro.prismaA(1, 15, 13.5,pTapiz.GLindex, gris.GLindex, gris.GLindex);//minterior1.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-11, -25.5, -25.5);
	glRotatef(90, 1, 0, 0);
	muro.prismaA(1, 7, 50.5,gris.GLindex, pTapiz.GLindex, gris.GLindex);//Izquierda ventana dentro
	glPopMatrix();
	glPushMatrix();
	glTranslatef(11, -25.5, -25.5);
	glRotatef(90, 1, 0, 0);
	muro.prismaA(1, 7, 50.5, gris.GLindex, pTapiz.GLindex, gris.GLindex);//Derecha ventana dentro
	glPopMatrix();// fin muro ventana
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, -5.5, 0);
	pisoCuarto.prisma(1, 29, 51, gris.GLindex, tAlfombra.GLindex, gris.GLindex);// piso cuarto
	glPopMatrix();
}


void cuadro3() {
	glPushMatrix();
		glTranslatef(0, 0, 0);
		glScalef(4, 4, 0.5);
		m.prisma_gen(1, 1, 1, pos2.GLindex, gris.GLindex);
	glPopMatrix();
}

void cuadroA() {
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(4, 4, 0.5);
	m.prisma_gen(1, 1, 1, hoja.GLindex, gris.GLindex);
	glPopMatrix();
}

void librero()
{
	glTranslatef(0, 1, 0);
	clibrero.prisma(0.1, 1, 1.5, maderaAzul.GLindex, maderaAzul.GLindex, maderaAzul.GLindex);
	//Repisas
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	clibrero.prisma(0.1, 1, 1.5, maderaAzul.GLindex, maderaAzul.GLindex, maderaAzul.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	clibrero.prisma(0.1, 1, 1.5, maderaAzul.GLindex, maderaAzul.GLindex, maderaAzul.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	clibrero.prisma(0.1, 1, 1.5, maderaAzul.GLindex, maderaAzul.GLindex, maderaAzul.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.75, 0);
	clibrero.prisma(0.1, 1, 1.5, maderaAzul.GLindex, maderaAzul.GLindex, maderaAzul.GLindex);
	glPopMatrix();


	//Izquierdo
	glPushMatrix();
	glTranslatef(0, 0, -0.8);
	glRotatef(90, -1, 0, 0);
	clibrero.prisma(0.1, 1, 3.1, maderaAzul.GLindex, maderaAzul.GLindex, maderaAzul.GLindex);
	glPopMatrix();

	//Atras
	glPushMatrix();
	glTranslatef(0.5, 0, 0);
	clibrero.prisma(3, 0.1, 1.7, maderaAzul.GLindex, maderaAzul.GLindex, maderaAzul.GLindex);
	glPopMatrix();

	//Derecho
	glPushMatrix();
	glTranslatef(0, 0, 0.7);
	glRotatef(90, 0, 1, 0);
	clibrero.prisma(3, 0.1, 1, maderaAzul.GLindex, maderaAzul.GLindex, maderaAzul.GLindex);
	glPopMatrix();

	//Bocinas

	glPushMatrix();
	glTranslatef(-0.4, -0.4, 0);
	//glRotatef(90, 0, 1, 0);
	clibrero.prisma(0.6, 0.1, 1.4, bocina.GLindex, bocina.GLindex, bocina.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, -1, 0);
	//glRotatef(90, 0, 1, 0);
	clibrero.prisma(0.6, 0.1, 1.4, bocina.GLindex, bocina.GLindex, bocina.GLindex);
	glPopMatrix();

	//libros
	glPushMatrix();
	glTranslatef(-0.4, 1.1, -0.3);
	//glRotatef(90, 0, 1, 0);
	clibrero.prisma(0.5, 0.2, 0.1, tlibro.GLindex, tlibro.GLindex, tlibro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, 1.1, 0);
	//glRotatef(90, 0, 1, 0);
	clibrero.prisma(0.5, 0.2, 0.1, tlibro.GLindex, tlibro.GLindex, tlibro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, 1.1, 0.45);
	glRotatef(30, 1, 0, 0);
	clibrero.prisma(0.5, 0.2, 0.1, tlibro.GLindex, tlibro.GLindex, tlibro.GLindex);
	glPopMatrix();

}

void lampara(){
	glPushMatrix();
			glTranslatef(0, 0, 0);
			glScalef(3.5, 2, 5);
			k.prisma_gen(1, 1, 1, lamp.GLindex, lamp.GLindex);//
	glPopMatrix();
	glPushMatrix();
			glTranslatef(0, -.6, 0);
			glScalef(3, 1, 4.5);
			k.prisma_gen(1, 1, 1, lamp1.GLindex, lamp1.GLindex);
	glPopMatrix();
}

void cama(){// respaldo de la pared
	glPushMatrix();
		glTranslatef(0, 0, 0);
		glScalef(1, 10, 10);
		k.prisma_gen(1, 1, 1, respaldo.GLindex, respaldo.GLindex);//
	glPopMatrix();
}

void cama2() {
	glPushMatrix();
		glTranslatef(0, 0, 0);
		glPushMatrix();//base color negro
			glTranslatef(10, 4.5, 26.66666667);
			glScalef(20, 9, 29);
			t.prisma_gen(1, 1, 1, base.GLindex, base.GLindex);//
		glPopMatrix();
		glPushMatrix();//cajones /cajon1
				glTranslatef(10, 4.5, 6.083333335);
				glPushMatrix();//Cajon2
					glTranslatef(0, 6.25, 0);
						glPushMatrix();//cajon3
							glTranslatef(0, 0, 12.1666667);
								glPushMatrix();//cajon4
									glTranslatef(0, 0, 12.1666667);
									glScalef(20, 3.5, 12.1666667);
									t.prisma_gen(1, 1, 1, cajon.GLindex, cajon.GLindex);//fin cajon4
								glPopMatrix();
							glScalef(20, 3.5, 12.1666667);
							t.prisma_gen(1, 1, 1, cajon.GLindex, cajon.GLindex);//fin cajon3
						glPopMatrix();
					glScalef(20, 3.5, 12.1666667);
					t.prisma_gen(1, 1, 1, cajon.GLindex, cajon.GLindex);//fin cajon2
				glPopMatrix();
			glScalef(20, 9, 12.1666667);
			t.prisma_gen(1, 1, 1, cajon.GLindex, cajon.GLindex);// fin cajon1
		glPopMatrix();
		glPushMatrix();//colchon
			glTranslatef(10, 14.5, 18.25);
			glPushMatrix();//almohada
					glTranslatef(0, 3, -14.75);
					glPushMatrix();//almohada1
						glTranslatef(-3, 2.4, 3.5);
						glPushMatrix();//alm.ohada1.5
							glTranslatef(5.5, 4, 0);
							glRotatef(180, 1, 0, 1);
							glRotatef(90, 1, 0, 1);
							glScalef(8, 2, 8);
							t.prisma_gen(1, 1, 1, almohada1.GLindex, almohada1.GLindex);
						glPopMatrix();//fin Almohada1.5
						glRotatef(-133, 1, 0, 0);
						glScalef(8, 2, 8);
						t.prisma_gen(1, 1, 1, almohada1.GLindex, almohada1.GLindex);
					glPopMatrix();//fin almohada1*/
					glRotatef(180, 0, 0, 1);
					glScalef(20, 2, 7);
					t.prisma_gen(1, 1, 1, almohada.GLindex, almohada.GLindex);
				glPopMatrix(); //fin almohada
			glRotatef(180, 0, 0, 1);
			glScalef(20, 4, 36.5);
			t.prisma_gen(1, 1, 1, colchon.GLindex, colchon.GLindex);
		glPopMatrix();//fin colchon
	glPopMatrix();
}

void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}


void alfombra() {
	glPushMatrix();
		glTranslatef(0, 0, 0);
		glScalef(4, 0.5, 5);
		m.prisma_gen(1, 1, 1, alf.GLindex, gris.GLindex);
	glPopMatrix();
}

void alfombraA() {
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(4, 0.5, 5);
	m.prisma_gen(1, 1, 1, tAlfombra.GLindex, gris.GLindex);
	glPopMatrix();
}

void respaldo_principal() {
	glPushMatrix();
		glTranslatef(-.10, 0, -.1);
		m.prisma_gen(0.2, 5, 6, resp_principal.GLindex, madn.GLindex);
	glPopMatrix();
}

void cama_principal() {
	glPushMatrix();
		glTranslatef(0, -.4, 0);
		m.prisma_gen(2, 5, 6, colchon2.GLindex, madn.GLindex);//colchon
		glPushMatrix();
			glTranslatef(0, -2.55, 0);
			m.prisma_gen(3, 5, 6, madn.GLindex, base_c.GLindex);// base colchon
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, -0.5, -3); 
		glRotatef(90, 1, 0, 0);
		m.prisma_gen(0.5, 3, 0.5, resp_principal.GLindex, resp_principal.GLindex);
			glPushMatrix();
				glTranslatef(0, 0, .48);
				m.prisma_gen(0.45, 3, 0.4, respaldo.GLindex, respaldo.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-1, 0, 2);
				glScalef(0.4, 0.1, 3);
				m.prisma_gen(1, 1, 1, respaldo.GLindex, respaldo.GLindex);
			glPopMatrix();


	glPopMatrix();
}

void cuarto2() {
		glPushMatrix();// cuarto2
		glScalef(1.5, 0.70, 0.80);//glScalef(0.3, 0.3, 0.3);
		glTranslatef(0, 0, 0); 
		//glRotatef(180, 0, 1, 0);
		glColor3f(1, 1, 1);
		glDisable(GL_LIGHTING);
		glScalef(0.3, 0.3, 0.3);//glScalef(3.0, 1.8, 2);	
			cascaron_recamara2();// Se dibuja recamara


			glPushMatrix();//poster
				glTranslatef(14, 28, 0);
				glScalef(0.2, 5, 1.5);
				glRotatef(270, 0, 1, 0);
				cuadro3();
			glPopMatrix();

			glPushMatrix();//alfombra
				glTranslatef(-2, -5, 0);
				glRotatef(0, 0, 1, 0);
				glScalef(3, 0.5, 4);
				alfombra();
			glPopMatrix();

			glPushMatrix();//respaldo cama
				glTranslatef(13.8, 5.5, 0);
				glRotatef(90, 0, 0, 1);
				glScalef(4, 0.5, 2.5);
				respaldo_principal();
			glPopMatrix();

			glPushMatrix();// cama
				glTranslatef(7.5, 4, 0);
				glScalef(2.5, 2, 2);
				cama_principal();
			glPopMatrix();

			//Modelos silla
			/*glPushMatrix(); 
				glTranslatef(0, 3, 0);
				glScalef(.10, .15, .10);
				silla_prins.GLrender(NULL, _SHADED, 1);
			glPopMatrix();*/



		glEnable(GL_LIGHTING);
		glPopMatrix();
}

void flecha(int giro)
{
	glRotatef(giro, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0, 0, -4.3);
	glRotatef(90, -1, 0, 0);
	creloj.cono(0.4, 0.2, 15, mReloj.GLindex);
	glPushMatrix();
	glTranslatef(0, -1.3, 0);
	creloj.cilindro(0.1, 1.5, 15, mReloj.GLindex);
	glPopMatrix();
	glPopMatrix();
}

void reloj()
{
	glRotatef(90, 1, 0, 0);
	creloj.cilindro(3, 0.1, 23, mReloj.GLindex);

	/*glPushMatrix();
	glTranslatef(0, 0, -3.8);
	glRotatef(90, -1, 0, 0);
	creloj.cono(0.4,0.2,15,mReloj.GLindex);
		glPushMatrix();
		glTranslatef(0, -1.5, 0);
		creloj.cilindro(0.1, 1.5, 15, mReloj.GLindex);
		glPopMatrix();
	glPopMatrix();*/

	for (int i = 0; i < 360; i += 30) {
		flecha(i);
	}

	glRotatef(gr,0,1,0);
	glTranslatef(0,0.31,0);

	glPushMatrix();
	
	glRotatef(90,0,0,1);
	//glTranslatef(0, 0, -2);
	creloj.cono(2.4, 0.1, 15, hoja.GLindex);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,1,0,0);
	//glTranslatef(0, 0, 2);
	creloj.cono(1.9, 0.1, 15, hoja.GLindex);
	
	glPopMatrix();

}

void Maceta()
{
	glPushMatrix();

	cmaceta.cilindro(2.4, 2, 20, tMaceta.GLindex);

	glTranslatef(0, 2, 0);
	glPushMatrix();
	cmaceta.cilindro(2.6, 0.6, 20, tMaceta.GLindex);
	glPopMatrix();

	glTranslatef(0, 0.7, 0);
	glPushMatrix();
	//glRotatef();
	//cmaceta.prisma(6.5,1.2,1.2,hoja.GLindex);
	cmaceta.cilindro(0.6, 6.5, 20, t_pasto.GLindex);
	glPopMatrix();

	glTranslatef(0, 2.5, 1);
	glPushMatrix();
	glRotatef(60, 1, 0, 0);
	cmaceta.prisma(2.5, 0.7, 0.7, t_pasto.GLindex, t_pasto.GLindex, t_pasto.GLindex);
	glPopMatrix();

	glTranslatef(0, 1.9, -2.5);
	glPushMatrix();
	glRotatef(70, -1, 0, 0);
	cmaceta.prisma(2.5, 0.7, 0.7, t_pasto.GLindex, t_pasto.GLindex, t_pasto.GLindex);
	glPopMatrix();



	glPopMatrix();
}

void camar()
{
	glPushMatrix();

	ccama.prisma(0.4, 7.5, 4, tAlfombra.GLindex, tAlfombra.GLindex, tAlfombra.GLindex);

	glTranslatef(0, 0.5, 0);
	glPushMatrix();
	ccama.prisma(0.4, 7.5, 3.5, tAlfombra.GLindex, tAlfombra.GLindex, tAlfombra.GLindex);
	glPopMatrix();

	//Colchon
	glTranslatef(0, 0.5, 0);
	glPushMatrix();
	ccama.prisma(1, 7, 3, colchon.GLindex, colchon.GLindex, colchon.GLindex);
	glPopMatrix();

	//Almohada
	glTranslatef(-2.3, 0.6, 0);
	glPushMatrix();
	ccama.prisma(0.3, 1.3, 2,aguaG.GLindex, aguaG.GLindex, aguaG.GLindex);
	glPopMatrix();

	glPopMatrix();
}

void cuartoA() {
	glPushMatrix();// cuarto2
	glScalef(1.5, 0.70, 0.80);//glScalef(0.3, 0.3, 0.3);
	glTranslatef(0, 0, 0);
	//glRotatef(180, 0, 1, 0);
	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	glScalef(0.3, 0.3, 0.3);//glScalef(3.0, 1.8, 2);	
	cascaron_recamaraA();// Se dibuja recamara


	glPushMatrix();//poster
	glTranslatef(14, 28, 0);
	glScalef(0.2, 5, 1.5);
	glRotatef(270, 0, 1, 0);
	cuadroA();
	glPopMatrix();

	///////////////////////////////////////////////Maceta
	glPushMatrix();//
	glTranslatef(12.5, 20.5, 3);
	glScalef(0.3, 0.8, 0.3);
	glRotatef(270, 0, 1, 0);
	Maceta();
	glPopMatrix();


	///////////////////////////////////////////////////Maceta
	glPushMatrix();//
	glTranslatef(12.5, 20.5, -3);
	glScalef(0.3, 0.8, 0.3);
	glRotatef(270, 0, 1, 0);
	Maceta();
	glPopMatrix();

	////////////////////////////////////////////////////Reloj

	glPushMatrix();//poster
	glTranslatef(-13.5, 28, -10);
	glRotatef(90, 0, 1, 0);
	reloj();
	glPopMatrix();
	/////////////////////////////////////////////////////////
	glPushMatrix();//cama
	glTranslatef(-2, -3, -16);
	/*glRotatef(90, 0, 0, 1);*/
	glScalef(2, 4, 2.8);
	camar();
	glPopMatrix();

	glPushMatrix();//librero
	glTranslatef(12.5, 0, 0);
	//glRotatef(90, 0, 0, 1);
	glScalef(2.5, 8, 8);
	librero();
	glPopMatrix();

	//glPushMatrix();// cama
	//glTranslatef(7.5, 4, 0);
	//glScalef(2.5, 2, 2);
	//cama_principal();
	//glPopMatrix();

	//Modelos silla
	/*glPushMatrix();
		glTranslatef(0, 3, 0);
		glScalef(.10, .15, .10);
		silla_prins.GLrender(NULL, _SHADED, 1);
	glPopMatrix();*/



	glEnable(GL_LIGHTING);
	glPopMatrix();

}

void pelota()
{

	glPushMatrix();
	glTranslatef(posx, posy, 0);
	m.esfera(3, 35, 35, pixa_ball.GLindex);
	glPopMatrix();
}

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_AMBIENT, Ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Specular);



	//glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	t_coche.LoadTGA("Textura/02.tga");
	t_coche.BuildGLTexture();
	t_coche.ReleaseImage();

	pixa_ball.LoadTGA("texturas/pixar_ball.tga");
	pixa_ball.BuildGLTexture();
	pixa_ball.ReleaseImage();

	t_mural.LoadTGA("Textura/mural.tga");
	t_mural.BuildGLTexture();
	t_mural.ReleaseImage();
    
    text1.LoadBMP("cielo.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	t_pasto.LoadTGA("pasto.tga");
	t_pasto.BuildGLTexture();
	t_pasto.ReleaseImage();

	t_nubes.LoadTGA("nube.tga");
	t_nubes.BuildGLTexture();
	t_nubes.ReleaseImage();



	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	/////////////////////////
	techoC.LoadTGA("texturas/techo.tga");
	techoC.BuildGLTexture();
	techoC.ReleaseImage();

	techoEx.LoadTGA("texturas/techo1.tga");
	techoEx.BuildGLTexture();
	techoEx.ReleaseImage();

	minterior1.LoadTGA("texturas/muro2.tga");
	minterior1.BuildGLTexture();
	minterior1.ReleaseImage();

	tPiso.LoadTGA("texturas/mozaico3.tga");
	tPiso.BuildGLTexture();
	tPiso.ReleaseImage();

	pasto.LoadTGA("texturas/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	gris.LoadTGA("texturas/gris.tga");
	gris.BuildGLTexture();
	gris.ReleaseImage();

	ventana.LoadTGA("texturas/ventana.tga");
	ventana.BuildGLTexture();
	ventana.ReleaseImage();

	puer.LoadTGA("texturas/puerta1.tga");
	puer.BuildGLTexture();
	puer.ReleaseImage();

	puer2.LoadTGA("texturas/puerta2.tga");
	puer2.BuildGLTexture();
	puer2.ReleaseImage();

	
	mad.LoadTGA("texturas/madera2.tga");
	mad.BuildGLTexture();
	mad.ReleaseImage();

	
	piedra.LoadTGA("texturas/piso_p.tga");
	piedra.BuildGLTexture();
	piedra.ReleaseImage();
	
	tapa.LoadTGA("texturas/portada.tga");
	tapa.BuildGLTexture();
	tapa.ReleaseImage();

	post1.LoadTGA("texturas/post1.tga");
	post1.BuildGLTexture();
	post1.ReleaseImage();

	///
	ventanal.LoadTGA("texturas2/ventanal.tga");
	ventanal.BuildGLTexture();
	ventanal.ReleaseImage();

	piso2.LoadTGA("texturas2/piso_mad.tga");
	piso2.BuildGLTexture();
	piso2.ReleaseImage();

	pos2.LoadTGA("texturas2/cuadro2.tga");
	pos2.BuildGLTexture();
	pos2.ReleaseImage();

	blanco.LoadTGA("texturas2/paredR.tga");
	blanco.BuildGLTexture();
	blanco.ReleaseImage();

	marron.LoadTGA("texturas/marron.tga");
	marron.BuildGLTexture();
	marron.ReleaseImage();

	alf.LoadTGA("texturas2/alfombra3.tga");
	alf.BuildGLTexture();
	alf.ReleaseImage();

	resp_principal.LoadTGA("texturas2/respaldo.tga");
	resp_principal.BuildGLTexture();
	resp_principal.ReleaseImage();

	colchon2.LoadTGA("texturas2/colchon.tga");
	colchon2.BuildGLTexture();
	colchon2.ReleaseImage();

	madn.LoadTGA("texturas/madn.tga");
	madn.BuildGLTexture();
	madn.ReleaseImage();

	base_c.LoadTGA("texturas2/base_c.tga");
	base_c.BuildGLTexture();
	base_c.ReleaseImage();

	//////////////////////////////////////////////////////////
	aguaG.LoadTGA("texturas/aguaG.tga");
	aguaG.BuildGLTexture();
	aguaG.ReleaseImage();

	tAlfombra.LoadTGA("texturas/alfombra.tga");
	tAlfombra.BuildGLTexture();
	tAlfombra.ReleaseImage();

	baseGarrafon.LoadTGA("texturas/baseGarrafon.tga");
	baseGarrafon.BuildGLTexture();
	baseGarrafon.ReleaseImage();

	bocina.LoadTGA("texturas/bocina.tga");
	bocina.BuildGLTexture();
	bocina.ReleaseImage();

	tcolchon.LoadTGA("texturas/colchon.tga");
	tcolchon.BuildGLTexture();
	tcolchon.ReleaseImage();

	hoja.LoadTGA("texturas/hoja.tga");
	hoja.BuildGLTexture();
	hoja.ReleaseImage();

	tlibro.LoadTGA("texturas/libro.tga");
	tlibro.BuildGLTexture();
	tlibro.ReleaseImage();

	maderaAzul.LoadTGA("texturas/maderaAzul.tga");
	maderaAzul.BuildGLTexture();
	maderaAzul.ReleaseImage();

	mReloj.LoadTGA("texturas/mReloj.tga");
	mReloj.BuildGLTexture();
	mReloj.ReleaseImage();

	pTapiz.LoadTGA("texturas/pTapiz.tga");
	pTapiz.BuildGLTexture();
	pTapiz.ReleaseImage();

	tMaceta.LoadTGA("texturas/tMaceta.tga");
	tMaceta.BuildGLTexture();
	tMaceta.ReleaseImage();

	tSillon.LoadTGA("texturas/tSillon.tga");
	tSillon.BuildGLTexture();
	tSillon.ReleaseImage();

	

	
	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

}


void display ( void )   // Creamos la funcion donde se dibuja
{
	
	
	
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		
		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
		
		glPushMatrix();		
		
			
		glPushMatrix(); //Creamos cielo
		glDisable(GL_LIGHTING);
		glTranslatef(0, 60, 0);
		fig1.skybox2(200.0, 200.0, 200.0, text1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//pasto
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(0, -40, 0.0);
		glScalef(200, .1, 200);
		fig3.prisma2(t_pasto.GLindex, t_pasto.GLindex);
		glPopMatrix();

		//nubes

		glPushMatrix();
		glTranslatef(0, 160, 0.0);
		glScalef(200, .1, 200);
		fig3.prisma2(t_nubes.GLindex, t_nubes.GLindex);
		glPopMatrix();		

			glPushMatrix(); //cuarto
					glTranslatef(8, -35, 0);
				glScalef(4, 4, 4);
				cuarto2();
			glPopMatrix();

			glTranslatef(-10, 0, 52);
			glPushMatrix(); //cuarto2
			glTranslatef(19,-35,-2.2);
			glScalef(4, 4, 4);
			glRotatef(180,0,1,0);
			
			cuartoA();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(8, -33, 3);
			pelota();
			glPopMatrix();
		glPopMatrix(); 
	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	if (g_animacion) {

			if (p_giro) {
				gr++;
				if (gr > 265) {
					p_giro = false;
					gr = 265;
				}
			}

			if (p_giro2) {

				gr--;//= 1;
				if (gr < 1) {
					p_giro2 = false;
					gr = 2;
				}
			}

		
	}
		
// pelota
	if (inicia_tiro) {
		time += 0.001;

		posx = PosXini*time*cos(ang_ini);
		posy = vini * time * sin(ang_ini) - 0.5*g*time*time;
		

		if (posy <= 0) {
		
			posy = 0.0;
			time = 0.0;
			PosXini = posx;
			vini = vini / 2.0;
			posy = vini * time * sin(ang_ini) - 0.5*g*time*time;
		}
	
	}// fin if pelota

	/*	Animacion puerta	*/
	if (p_animacion) {

		if (p_mover) {
			//rot += 1.0;
			rot++;
			if (rot > 265) {
				p_mover = false;
				rot = 265;
			}
		}

		if (p_mover2) {

			rot--;//= 1;
			if (rot < 179) {
				p_mover2 = false;
				rot = 180;
			}
		}
	}



	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 300.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.1 );//0.2
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.1));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.2));//0.4
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.2 );
			break;

			/*Movimiento de la puerta*/
		case 'p':
			p_mover ^= true;
			p_animacion = true;
			break;
		case 'P':
			p_mover2 ^= true;
			p_animacion = true;
			break;

			/*pelota*/

		case 'm':
		case 'M':
			inicia_tiro = !inicia_tiro;

		case 'h':
			p_giro ^= true;
			g_animacion = true;
			break;
		case 'H':
			p_giro2 ^= true;
			g_animacion = true;
		
		break;
				

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= .50f;//g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += .50f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Jerarquia"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
