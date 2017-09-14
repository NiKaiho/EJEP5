//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//******** Alumno: ALVAREZ POCEROS ABRAHAM ARTURO ************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -3.0f;
float transX = 0.0f;
float transY = 3.0f;
float angleX = 0.0f;
float angleY = 0.0f;
float angleHombro = 0.0f;
float angleCodo = 0.0f;
float angleMano = 0.0f;
float anglePulgar1 = 0.0f;
float anglePulgar2 = 0.0f;
float angleIndice1 = 0.0f;
float angleIndice2 = 0.0f;
float angleMedio1 = 0.0f;
float angleMedio2 = 0.0f;
float angleAnular1 = 0.0f;
float angleAnular2 = 0.0f;
float angleMen1 = 0.0f;
float angleMen2 = 0.0f;
int screenW = 0.0;
int screenH = 0.0;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner Código Aquí.
	//BRAZO DETYALLADO
	glPushMatrix();
		glRotatef(angleHombro, 0.0, 0.0, 1.0);//los ubicamos despues de un traslado ROTATE
		//HOMBRO
		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 0.5, 0.5);
			prisma();
		glPopMatrix();
		//BICEP
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glScalef(0.5, 1.0, 0.5);
			prisma();
		glPopMatrix();
		//codo
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angleCodo, 0.0,0.0,1.0); //LOS ROTATE los ubicamos despues de un traslado 
		glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glScalef(0.5, 0.5, 0.5);
			prisma();
		glPopMatrix();
		//antebrazo
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glScalef(0.5, 1.0, 0.5);
			prisma();
		glPopMatrix();
		//mano
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angleMano, 0.0, 0.0, 1.0);
		glPushMatrix();
			glColor3f(0.0, 1.0, 1.0);
			glScalef(0.5, 0.5, 0.25);
			prisma();
		glPopMatrix();
		//pulgar
	
		glPushMatrix();
		glRotatef(anglePulgar1, 0.0, 1.0, 0.0);
			glTranslatef(0.25, 0.0, 0.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.5, 0.0);
			//parte 1
			glRotatef(anglePulgar2, 0.0, 1.0, 0.0);

				glPushMatrix();
					glScalef(0.15, 0.15, 0.155);
					prisma();
				glPopMatrix();
			glTranslatef(0.15, 0.0, 0.0);
			glColor3f(0.3, 0.6, 1.0);
			//parte 2
			glPushMatrix();
				glScalef(0.15, 0.15, 0.15);
				prisma();
			glPopMatrix();

		glPopMatrix();

		//indice
		glRotatef(angleIndice1, 1.0, 0.0, 0.0);
		glPushMatrix();
				glTranslatef(0.1, -0.4, 0.0);
				glTranslatef(0.1, 0.0, 0.0);
				glColor3f(0.3, 0.5, 0.0);
			//parte 1
			glRotatef(angleIndice2, 1.0, 0.0, 0.0);
			glPushMatrix();
				glScalef(0.1, 0.3, 0.5);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.25, 0.0);
			glColor3f(0.3, 0.6, 1.0);
			//parte 2
			glPushMatrix();
				glScalef(0.1, 0.2, 0.5);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//medio
		glRotatef(angleMedio1, 1.0, 0.0, 0.0);
		glPushMatrix();
			glTranslatef(-0.025, -0.4, 0.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.5, 0.0);
			//parte 1
			glRotatef(angleMedio2, 1.0, 0.0, 0.0);
			glPushMatrix();
				glScalef(0.1, 0.3, 0.5);
				prisma();
			glPopMatrix();
				glTranslatef(0.0, -0.3, 0.0);
				glColor3f(0.3, 0.6, 1.0);
				//parte 2
				glPushMatrix();
					glScalef(0.1, 0.3, 0.5);
					prisma();
				glPopMatrix();
		glPopMatrix();
		//anular
		glRotatef(angleAnular1, 1.0, 0.0, 0.0);
			glPushMatrix();
				glTranslatef(-0.175, -0.4, 0.0);
				glTranslatef(0.1, 0.0, 0.0);
				glColor3f(0.3, 0.5, 0.0);
				//parte 1
				glRotatef(angleAnular2, 1.0, 0.0, 0.0);
				glPushMatrix();
					glScalef(0.1, 0.3, 0.5);
					prisma();
				glPopMatrix();
					glTranslatef(0.0, -0.25, 0.0);
					glColor3f(0.3, 0.6, 1.0);
				//parte 2
				glPushMatrix();
					glScalef(0.1, 0.2, 0.5);
					prisma();
				glPopMatrix();
			glPopMatrix();
			//meñique
			glRotatef(angleMen1, 5.0, 0.0, 0.0);
			glPushMatrix();
				glTranslatef(-0.3, -0.4, 0.0);
				glTranslatef(0.1, 0.0, 0.0);
				glColor3f(0.3, 0.5, 0.0);
				//parte 1
				glRotatef(angleMen2, 5.0, 0.0, 0.0);
				glPushMatrix();
					glScalef(0.1, 0.3, 0.5);
					prisma();
				glPopMatrix();
				glTranslatef(0.0, -0.3, 0.0);
				glColor3f(0.3, 0.6, 1.0);
				//parte 2
				glPushMatrix();
					glScalef(0.1, 0.3, 0.5);
					prisma();
				glPopMatrix();
			glPopMatrix(); 

	glPopMatrix();
		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		//MANIPULACION DE BRAZO
		case 't':
		case 'T':
			angleHombro += 0.5f; //hombro
		break;
		case 'g':
		case 'G':
			angleHombro -= 0.5f;//hombro
			break;
		case 'y':
		case 'Y':
			angleCodo += 0.5f; //codo
			break;
		case 'h':
		case 'H':
			angleCodo -= 0.5f;//codo
			break;
		case 'u':
		case 'U':
			angleMano += 0.5f; //mano
			break;
		case 'j':
		case 'J':
			angleMano -= 0.5f;//mano rotacion
			break;
		case 'i':
		case 'I':
			anglePulgar1 += 1.0f; //pulgar 1
			anglePulgar2 += 1.0f;//pulgar 2
			angleIndice1 += 1.0f;//
			angleIndice2 += 1.0f;
			angleMedio1 += 1.0f;
			angleMedio2 += 1.0f;
			angleAnular1 += 1.0f;
			angleAnular2 += 1.0f;
			angleMen1 += 1.0f;
			angleMen2 += 1.0f;

			break;
		case 'o':
		case 'O':
			anglePulgar1 -= 1.0f; //pulgar 1
			anglePulgar2 -= 1.0f;//pulgar 2
			angleIndice1 -= 1.0f;//
			angleIndice2 -= 1.0f;
			angleMedio1 -= 1.0f;
			angleMedio2 -= 1.0f;
			angleAnular1 -= 1.0f;
			angleAnular2 -= 1.0f;
			angleMen1 -= 1.0f;
			angleMen2 -= 1.0f;
			break;

		case 'w':
		case 'W':
			transY +=0.1f;
			break;
		case 's':
		case 'S':
			transY -=0.1f;
			break;
		case 'a':
		case 'A':
			transX +=0.1f;
			break;
		case 'd':
		case 'D':
			transX -=0.1f;
			break;
		case 'q':
		case 'Q':
			transZ += 0.1f;
			break;
		case 'e':
		case 'E':
			transZ -= 0.1f;
			break;
		case '1':
			angleY += 10;
			break;
		case '2':
			angleY -= 10;
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
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
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
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}
