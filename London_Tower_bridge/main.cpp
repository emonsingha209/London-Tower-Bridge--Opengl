#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

#define PI          3.141516
#include<math.h>

GLboolean positionControl = false;

static GLfloat spin = 0.0;
static GLfloat spin_speed_open = 0.0;
static GLfloat spin_speed_close = 0.0;

GLfloat positionPlane = 1.0f;
GLfloat speedPlane = 0.012f;

GLfloat positionBus = 2.0f;
GLfloat speedBus = 0.012f;

GLfloat positionRCar = 0.0f;
GLfloat speedRCar = 0.016f;

GLfloat positionGCar = -0.5f;
GLfloat speedGCar = 0.015f;

GLfloat positionBLCar = -0.25f;
GLfloat speedBLCar = 0.014f;

GLfloat positionBCar = 1.0f;
GLfloat speedBCar = 0.015f;

GLfloat positionYCar = 1.5f;
GLfloat speedYCar = 0.013f;

GLfloat positionBoat = 0.0f;
GLfloat speedBoat = 0.0f;

GLfloat scaleb = 1.0f;
GLfloat scalebspeed = 0.0f;

GLfloat positionShip = 0.0f;
GLfloat speedShip = 0.0f;

GLfloat positionWater1 = 0.0f;
GLfloat positionWater2 = 0.0f;
GLfloat positionWater3 = 0.0f;
GLfloat positionWater4 = 0.0f;
GLfloat positionWater5 = 0.0f;
GLfloat speedWater = 0.005f;

GLfloat _move_sun = 1.00f;
GLfloat _move_cloud_1 = 0.00f;
GLfloat _move_cloud_2 = 0.00f;
GLfloat _speed_cloud_1 = 0.0025f;
GLfloat _speed_cloud_2 = 0.0025f;
GLfloat nControl = 0.0f;

GLboolean night = false;

bool rain = false;

float _rain1x = 0.0;
float _rain2x = 0.0;
float _rain3x = 0.0;
float _rain4x = 0.0;
float _rain5x = 0.0;
float _rain6x = 0.0;
float _rain7x = 0.0;
float _rain8x = 0.0;
float _rain9x = 0.0;
float _rain10x = 0.0;
float _rain11x = 0.0;

float _rain1y = 0.0;
float _rain2y = 0.0;
float _rain3y = 0.0;
float _rain4y = 0.0;
float _rain5y = 0.0;
float _rain6y = 0.0;
float _rain7y = 0.0;
float _rain8y = 0.0;
float _rain9y = 0.0;
float _rain10y = 0.0;
float _rain11y = 0.0;
float _rain12y = 0.0;
float _rain13y = 0.0;
float _rain14y = 0.0;
float _rain15y = 0.0;

int rainfall = 0;

GLfloat positionSnow1 = 0.0f;
GLfloat positionSnow2 = 0.0f;
GLfloat positionSnow3 = 0.0f;
GLfloat positionSnow4 = 0.0f;
GLfloat positionSnow5 = 0.0f;
GLfloat positionSnow6 = 0.0f;
GLfloat positionSnow7 = 0.0f;
GLfloat positionSnow8 = 0.0f;
GLfloat positionSnow9 = 0.0f;
GLfloat positionSnow10 = 0.0f;
GLfloat speedSnow = 0.015f;

bool snowfall = false;

/// cloud part update

void update_cloud_1(int value) {
    if(_speed_cloud_1>1.00f || _speed_cloud_1<0.00f)    // loop means round kore move korte se plus time loop
    {
        _speed_cloud_1 = 0.0f;
    }
    _move_cloud_1 += _speed_cloud_1;
    if(_move_cloud_1-1.3 > 1.0)
    {
        _move_cloud_1 = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_cloud_1, 0); //Notify GLUT to call update again in 25 milliseconds
}
void update_cloud_2(int value) {
    if(_speed_cloud_2>1 || _speed_cloud_2<0)
    {
        _speed_cloud_2 = 0.0f;
    }
    _move_cloud_2 -= _speed_cloud_2;
    if(_move_cloud_2+1.3 < -1.0)
    {
        _move_cloud_2 = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_cloud_2, 0); //Notify GLUT to call update again in 25 milliseconds
}

//sun update

void update_sun(int value)  // sun r position change with time
{
    _move_sun -= 0.00055f;
    if(_move_sun+1.0 < 0.1 || nControl == 1.0)
    {
        _move_sun = 1.0;
        nControl = 0.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(40, update_sun, 0);
}


void star()
{
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
}



// Sky

void sky()      // sun r shate shate aky r colour change r code
{
    if(_move_sun<=1.00f && _move_sun>=0.90f)
    {
        glClear (GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.922);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(1.0, 0.25);
        glVertex2f(-1.0, 0.25);
        glEnd();
        night=false;
    }
    else if(_move_sun<0.90f && _move_sun>=0.55f)
    {
        glBegin(GL_QUADS);
        glColor3f(0.000, 0.749, 1.000);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.8, 1.000, 1.000);
        glVertex2f(1.0, 0.25);
        glVertex2f(-1.0, 0.25);
        glEnd();
    }
    else if(_move_sun<0.55f && _move_sun>=0.45f)
    {
        glBegin(GL_QUADS);
        glColor3f(0.000, 0.749, 1.000);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(1.000, 0.961, 0.933);
        glVertex2f(1.0, 0.25);
        glVertex2f(-1.0, 0.25);
        glEnd();
    }
    else if(_move_sun<0.45f && _move_sun>=0.35f)
    {
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(1.000, 0.855, 0.725);
        glVertex2f(1.0, 0.25);
        glVertex2f(-1.0, 0.25);
        glEnd();
    }
    else if(_move_sun<0.35f && _move_sun>=0.2f)
    {
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.957, 0.643, 0.376);
        glVertex2f(1.0, 0.25);
        glVertex2f(-1.0, 0.25);
        glEnd();
    }
    else if(_move_sun<0.2f && _move_sun>=0.1f)
    {
        glBegin(GL_QUADS);
        glColor3f(1.000, 0.388, 0.278);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.957, 0.643, 0.376);
        glVertex2f(1.0, 0.25);
        glVertex2f(-1.0, 0.25);
        glEnd();
    }
    if(night || _move_sun<0.1f)
    {
        glBegin(GL_QUADS);
        glColor3f(0.412, 0.412, 0.412);

        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.8, 1.000, 1.000);

        glVertex2f(1.0, 0.25);
        glVertex2f(-1.0, 0.25);
        glEnd();

        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glTranslatef(0.80,1.05,0);
        glScalef(0.6,1,1);
        glColor3f(0.902, 0.902, 0.980);
        glBegin(GL_POLYGON);// moon
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }      /// night a star r asar jonno
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.95,0.95,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.75,0.85,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.65,0.65,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.60,0.85,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.65,0.93,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.10,0.67,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.15,0.67,0);

        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.35,0.85,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.25,0.73,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.72,0.63,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.05,0.43,0);
        star();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(0.15,0.13,0);
        star();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(-0.15,0.88,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.65,0.73,0);
        star();
        glPopMatrix();
        night=true;
    }
}


// *********
void sun_circle()
{
    glScalef(0.6,1,1);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.125;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
}

                                               ///Sun and moon with time loop
void sun()
{

    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);

    if(_move_sun<=1.00 && _move_sun>=0.95f)
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.647, 0.000);
        sun_circle();
        glPopMatrix();
    }
    else if(_move_sun<0.95f && _move_sun>=0.90f)
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.843, 0.000);
        sun_circle();
        glPopMatrix();
    }
    else if(_move_sun<0.90 && _move_sun>=0.75)
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 1.000, 0.000);
        sun_circle();
        glPopMatrix();
    }
    else if(_move_sun<0.75 && _move_sun>=0.65)
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.843, 0.000);
        sun_circle();
        glPopMatrix();
    }

    else if(_move_sun<0.65 && _move_sun>=0.55){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.647, 0.000);
        sun_circle();
        glPopMatrix();
    }
    else if(_move_sun<0.55 && _move_sun>=0.25)
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.549, 0.000);
        sun_circle();
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.271, 0.000);
        sun_circle();
        glPopMatrix();
    }
}


void cloud_struct()
{
    if(NULL)
    {

    }
    else
    {

        if(night==true)
    {
        glColor3f(0.6,0.6,0.7);
    }
    else
         glColor3f(1.000, 1.000, 1.000);
    }
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();

}


                                     ///Cloud

void cloud_left()
{
    //Cloud on the left
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.78,0.82,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.74,0.87,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.70,0.91,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.65,0.88,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.61,0.80,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.68,0.77,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.75,0.78,0);
    cloud_struct();
    glPopMatrix();
}

void cloud_right()
{
    //Cloud on the right
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.78,0.70,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.74,0.75,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.70,0.79,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.65,0.76,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.61,0.76,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.68,0.65,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.63,0.66,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.75,0.66,0);
    cloud_struct();
    glPopMatrix();
}

void plane()
{
    int i;

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // black
    glVertex2f(-0.45f, 0.9f);    // x, y
    glVertex2f(-0.45f,0.8f);
    glVertex2f(-0.25f, 0.8f);
    glVertex2f(-0.25f, 0.9f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.98f, 0.02f, 0.02f); // red
    glVertex2f(-0.38f, 0.81f);    // x, y
    glVertex2f(-0.42f,0.76f);
    glVertex2f(-0.36f, 0.76f);
    glVertex2f(-0.32f, 0.81f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.98f, 0.02f, 0.02f); // red
    glVertex2f(-0.45f, 0.95f);    // x, y
    glVertex2f(-0.45f,0.9f);
    glVertex2f(-0.38f, 0.9f);
    glVertex2f(-0.43f, 0.95f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.98f, 0.02f, 0.02f); // red
    glVertex2f(-0.36f, 0.94f);    // x, y
    glVertex2f(-0.33f,0.9f);
    glVertex2f(-0.28f, 0.9f);
    glVertex2f(-0.31f, 0.94f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.98f, 0.02f, 0.02f); // red
    glVertex2f(-0.25f, 0.8f);    // x, y
    glVertex2f(-0.2f,0.82f);
    glVertex2f(-0.15f, 0.85f);
    glVertex2f(-0.25f, 0.85f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.52f, 0.23f, 1.0f); // blue
    glVertex2f(-0.25f, 0.85f);    // x, y
    glVertex2f(-0.15f,0.85f);
    glVertex2f(-0.2f, 0.88f);
    glVertex2f(-0.25f, 0.9f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.74f, 0.65f, 0.89f); // sky-blue
    glVertex2f(-0.23f, 0.89f);    // x, y
    glVertex2f(-0.23f,0.86f);
    glVertex2f(-0.17f, 0.86f);
    glVertex2f(-0.2f, 0.88f);
    glEnd();

    GLfloat p1=-0.28f; GLfloat q1= 0.85f; GLfloat r1 = 0.01f;     //Circle
    int tringle1=80;

    GLfloat tp1 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.28f, 0.11f, 0.69f);  //sea blue
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle1; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp1/tringle1)),
                    q1+(r1*sin(i*tp1/tringle1))
                    );
    }
    glEnd ();

    GLfloat p2=-0.32f; GLfloat q2= 0.85f; GLfloat r2 = 0.01f;     //Circle
    int tringle2=80;

    GLfloat tp2 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.28f, 0.11f, 0.69f);  //sea blue
    glVertex2f (p2,q2);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp2/tringle2)),
                    q2+(r2*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    GLfloat p3=-0.36f; GLfloat q3= 0.85f; GLfloat r3 = 0.01f;     //Circle
    int tringle3=80;

    GLfloat tp3 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.28f, 0.11f, 0.69f);  //sea blue
    glVertex2f (p3,q3);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp3/tringle3)),
                    q3+(r3*sin(i*tp3/tringle3))
                    );
    }
    glEnd ();

    GLfloat p4=-0.4f; GLfloat q4= 0.85f; GLfloat r4 = 0.01f;     //Circle
    int tringle4=80;

    GLfloat tp4 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.28f, 0.11f, 0.69f);  //sea blue
    glVertex2f (p4,q4);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp4/tringle4)),
                    q4+(r4*sin(i*tp4/tringle4))
                    );
    }
    glEnd ();
}


void update(int value) {

    if(positionPlane > 1.5)
    {
        positionPlane = -1.0f;
    }

    if(positionBus < -0.5)
    {
        positionBus = 2.0f;
    }
    if(positionBCar <-0.5)
    {
        positionBCar = 2.0f;
    }
    if(positionYCar <-0.5)
    {
        positionYCar = 2.0f;
    }
    if(positionGCar > 2.0)
    {
        positionGCar = -0.5f;
    }
    if(positionRCar > 2.0)
    {
        positionRCar = -0.5f;
    }
    if(positionBLCar > 2.0)
    {
        positionBLCar = -0.5f;
    }
    if(positionShip > 2.0)
    {
        positionShip = -0.4f;
    }
    if(positionBus > 1.38 && positionBus < 1.4 && positionControl == true)
    {
        speedBus = 0.0f;
    }
    if(positionBCar > 1.28 && positionBCar < 1.3 && positionControl == true)
    {
        speedBCar = 0.0f;
    }
    if(positionYCar > 1.28 && positionYCar < 1.3 && positionControl == true)
    {
        speedYCar = 0.0f;
    }
    if(positionRCar > 0.1 && positionRCar < 0.12 && positionControl == true)
    {
        speedRCar = 0.0f;
    }
    if(positionGCar > 0.1 && positionGCar < 0.12 && positionControl == true)
    {
        speedGCar = 0.0f;
    }
    if(positionBLCar > 0.1 && positionBLCar < 0.12 && positionControl == true)
    {
        speedBLCar = 0.0f;
    }
    if(spin>60.0)
    {
        spin_speed_open = 0;
    }
    if(spin == 0.0)
    {
        spin_speed_close = 0;
    }
    if(scaleb < 0.1)
    {
        scaleb = 1.0f;
        positionBoat = -0.8f;
    }
    if(positionBoat < 0.0)
    {
        scaleb += scalebspeed;
    }
    if(rain)
    {
        _rain1y -= .05;
        _rain2y -= .05;
        _rain3y -= .05;
        _rain4y -= .05;
        _rain5y -= .05;
        _rain6y -= .05;
        _rain7y -= .05;
        _rain8y -= .05;
        _rain9y -= .05;
        _rain10y -= .05;
        rainfall += 1;
        _rain1x -= .0055;
        _rain2x -= .0055;
        _rain3x -= .0055;
        _rain4x -= .0055;
        _rain5x -= .0055;
        _rain6x -= .0055;
        _rain7x -= .0055;
        _rain8x -= .0055;
        _rain9x -= .0055;
        _rain10x -= .0055;
    }
    if(_rain1y < -1.9)
    {
        _rain1y = .1;
        _rain1x = 0;
    }
    if(_rain2y < -1.7)
    {
        _rain2y = .3;
        _rain2x = 0;
    }
    if(_rain3y < -1.5)
    {
        _rain3y = .5;
        _rain3x = 0;
    }
    if(_rain4y < -1.3)
    {
        _rain4y = .7;
        _rain4x = 0;
    }
    if(_rain5y < -1.1)
    {
        _rain5y = 0.9;
        _rain5x = 0;
    }
    if(_rain6y < -.9)
    {
        _rain6y = 1.1;
        _rain6x = 0;
    }
    if(_rain7y < -.7)
    {
        _rain7y = 1.3;
        _rain7x = 0;
    }
    if(_rain8y < -.5)
    {
        _rain8y = 1.5;
        _rain8x = 0;
    }
    if(_rain9y < -.3)
    {
        _rain9y = 1.7;
        _rain9x = 0;
    }
    if(_rain10y < -.1)
    {
        _rain10y = 1.9;
        _rain10x = 0;
    }

    if(positionSnow1 < -2.0)
    {
        positionSnow1 = 0.1f;
    }

    if(positionSnow2 < -1.8)
    {
        positionSnow2 = 0.3f;
    }

    if(positionSnow3 < -1.6)
    {
        positionSnow3 = 0.5f;
    }

    if(positionSnow4 < -1.4)
    {
        positionSnow4 = 0.7f;
    }

    if(positionSnow5 < -1.2)
    {
        positionSnow5 = 0.9f;
    }

    if(positionSnow6 < -1.0)
    {
        positionSnow6 = 1.1f;
    }

    if(positionSnow7 < -0.8)
    {
        positionSnow7 = 1.3f;
    }

    if(positionSnow8 < -0.6)
    {
        positionSnow8 = 1.5f;
    }

    if(positionSnow9 < -0.4)
    {
        positionSnow9 = 1.7f;
    }

    if(positionSnow10 < -0.2)
    {
        positionSnow10 = 1.9f;
    }

    if(positionWater1 < -0.2)
    {
        positionWater1 = 0.0f;
    }

    if(positionWater2 < -0.15)
    {
        positionWater2 = 0.1f;
    }

    if(positionWater3 < -0.1)
    {
        positionWater3 = 0.05f;
    }

    if(positionWater4 < -0.1)
    {
        positionWater4 = 0.1f;
    }

    if(positionWater5 < -0.05)
    {
        positionWater5 = 0.1f;
    }

    positionWater1 -= speedWater;
    positionWater2 -= speedWater;
    positionWater3 -= speedWater;
    positionWater4 -= speedWater;
    positionWater5 -= speedWater;

    positionSnow1 -= speedSnow;
    positionSnow2 -= speedSnow;
    positionSnow3 -= speedSnow;
    positionSnow4 -= speedSnow;
    positionSnow5 -= speedSnow;
    positionSnow6 -= speedSnow;
    positionSnow7 -= speedSnow;
    positionSnow8 -= speedSnow;
    positionSnow9 -= speedSnow;
    positionSnow10 -= speedSnow;

    positionPlane += speedPlane;

    positionBus -= speedBus;

    positionGCar += speedGCar;

    positionRCar += speedRCar;

    positionBLCar += speedBLCar;

    positionBCar -= speedBCar;

    positionYCar -= speedYCar;

    positionBoat += speedBoat;

    scaleb -= scalebspeed;

    positionShip += speedShip;

    spin=spin+spin_speed_open;

    spin=spin-spin_speed_close;

glutPostRedisplay();
glutTimerFunc(100, update, 0);
}

void tree()
{
    int i;
    glBegin(GL_QUADS);      //tree 2
    glColor3f(0.56f, 0.24f, 0.08f);
    glVertex2f(0.74f, -0.1f);
    glVertex2f(0.71f, -0.1f);
    glVertex2f(0.71f, 0.15f);
    glVertex2f(0.74f, 0.15f);
    glEnd();

    GLfloat tp1=0.7f; GLfloat tq1= 0.1f; GLfloat ttr1 = 0.04f;      // tree
    int tree=40;

    GLfloat tt =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(11, 144, 11);
    glVertex2f (tp1,tq1);
    for(i= 0;i<=tree; i++)
    {
        glVertex2f (
                    tp1+(ttr1*cos(i*tt/tree)),
                    tq1+(ttr1*sin(i*tt/tree))
                    );


    }
    glEnd ();

    GLfloat tp2=0.7f; GLfloat tq2= 0.15f; GLfloat ttr2 = 0.04f;      //tree

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(11, 144, 11);
    glVertex2f (tp2,tq2);
    for(i= 0;i<=tree; i++)
    {
        glVertex2f (
                    tp2+(ttr2*cos(i*tt/tree)),
                    tq2+(ttr2*sin(i*tt/tree))
                    );


    }
    glEnd ();

    GLfloat tp3=0.75f; GLfloat tq3= 0.15f; GLfloat ttr3 = 0.04f;      //tree

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(11, 144, 11);
    glVertex2f (tp3,tq3);
    for(i= 0;i<=tree; i++)
    {
        glVertex2f (
                    tp3+(ttr3*cos(i*tt/tree)),
                    tq3+(ttr3*sin(i*tt/tree))
                    );


    }
    glEnd ();

    GLfloat tp4=0.75f; GLfloat tq4= 0.1f; GLfloat ttr4 = 0.04f;      //tree

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(11, 144, 11);
    glVertex2f (tp4,tq4);
    for(i= 0;i<=tree; i++)
    {
        glVertex2f (
                    tp4+(ttr4*cos(i*tt/tree)),
                    tq4+(ttr4*sin(i*tt/tree))
                    );


    }
    glEnd ();

    GLfloat tp5=0.725f; GLfloat tq5= 0.2f; GLfloat ttr5 = 0.04f;      //tree

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub(11, 144, 11);
    glVertex2f (tp5,tq5);
    for(i= 0;i<=tree; i++)
    {
        glVertex2f (
                    tp5+(ttr5*cos(i*tt/tree)),
                    tq5+(ttr5*sin(i*tt/tree))
                    );


    }
    glEnd ();
}

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	sky();
    sun();
    if(night)
    {
        glPushMatrix();
        glTranslatef(positionPlane, 0.0f, 0.0f);
        plane();
        glPopMatrix();
    }
    cloud_left();
    cloud_right();

	int i;
	glBegin(GL_QUADS);      //River
    glColor3f(0.17f, 0.61f, 0.75f);
    if(night)
    {
        glColor3f(0.0f, 0.0f, 0.3f);
    }
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, 0.25f);
    glVertex2f(1.0f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);      //hills 3
    glColor3f(0.11f, 0.23f, 0.12f);
    glVertex2f(0.72f, 0.25f);
    glVertex2f(0.6f, 0.46f);
    glVertex2f(0.45f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);      //hills 2
    glColor3f(0.1f, 0.26f, 0.1f);
    glVertex2f(0.8f, 0.25f);
    glVertex2f(0.7f, 0.48f);
    glVertex2f(0.55f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);      //hills 1
    glColor3f(0.18f, 0.37f, 0.19f);
    glVertex2f(1.0f, 0.25f);
    glVertex2f(0.88f, 0.55f);
    glVertex2f(0.8f, 0.55f);
    glVertex2f(0.6f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);      //hills 4
    glColor3f(0.18f, 0.37f, 0.19f);
    glVertex2f(0.65f, 0.25f);
    glVertex2f(0.5f, 0.55f);
    glVertex2f(0.25f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);      //waterfall
    glColor3f(0.17f, 0.61f, 0.75f);
    glVertex2f(0.86f, 0.25f);
    glVertex2f(0.88f, 0.55f);
    glVertex2f(0.8f, 0.55f);
    glVertex2f(0.82f, 0.25f);
    glEnd();

    glLineWidth(1);  //water line

    glPushMatrix();
    glTranslatef(0.0f, positionWater1, 0.0f);
	glBegin(GL_LINES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.82f, 0.53f);
	glVertex2f(0.82f, 0.49f);

	glEnd();

	glPopMatrix();

	glPushMatrix();
    glTranslatef(0.0f, positionWater2, 0.0f);
	glBegin(GL_LINES);

	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(0.84f, 0.45f);
	glVertex2f(0.84f, 0.41f);

	glEnd();

	glPopMatrix();

	glPushMatrix();
    glTranslatef(0.0f, positionWater3, 0.0f);
	glBegin(GL_LINES);

	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(0.86f, 0.5f);
	glVertex2f(0.86f, 0.46f);

	glEnd();

	glPopMatrix();

	glPushMatrix();
    glTranslatef(0.0f, positionWater4, 0.0f);
	glBegin(GL_LINES);

	glVertex2f(0.83f, 0.37f);
	glVertex2f(0.83f, 0.33f);

	glEnd();

	glPopMatrix();

	glPushMatrix();
    glTranslatef(0.0f, positionWater5, 0.0f);
	glBegin(GL_LINES);

	glVertex2f(0.845f, 0.3f);
	glVertex2f(0.845f, 0.26f);
	glEnd();

	glPopMatrix();

    glBegin(GL_QUADS);      //base right
    glColor3f(0.0f, 0.7f, 0.0f);
    if(night)
    {
        glColor3f(0.0f, 0.4f, 0.45f);
    }
    glVertex2f(0.5f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.1f, 0.1f, 0.0f);

    tree();     // tree4

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, 0.1f, 0.0f);

    tree();     //tree5

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f);

    tree(); //tree3

    glPopMatrix();

    tree();

    glPushMatrix();
    glTranslatef(-0.2f, 0.0f, 0.0f);

    tree(); //tree1

    glPopMatrix();

    glBegin(GL_QUADS);      //base left
    glColor3f(0.0f, 0.7f, 0.0f);
    if(night)
    {
        glColor3f(0.0f, 0.4f, 0.45f);
    }
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(-1.0f, 0.25f);
    glVertex2f(-0.3f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);      //building 3
    glColor3f(0.6f, 0.5f, 0.75f);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(-0.8f, 0.1f);
    glVertex2f(-0.8f, 0.42f);
    glVertex2f(-0.6f, 0.42f);
    glEnd();

    glBegin(GL_QUADS);      //Window 1 - 3
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.62f, 0.15f);
    glVertex2f(-0.68f, 0.15f);
    glVertex2f(-0.68f, 0.2f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);      //Window 2 - 3
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.62f, 0.25f);
    glVertex2f(-0.68f, 0.25f);
    glVertex2f(-0.68f, 0.3f);
    glVertex2f(-0.62f, 0.3f);
    glEnd();

    glBegin(GL_QUADS);      //Window 3 - 3
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.62f, 0.35f);
    glVertex2f(-0.68f, 0.35f);
    glVertex2f(-0.68f, 0.4f);
    glVertex2f(-0.62f, 0.4f);
    glEnd();

    glBegin(GL_QUADS);      //Window 4 - 3
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.72f, 0.15f);
    glVertex2f(-0.78f, 0.15f);
    glVertex2f(-0.78f, 0.2f);
    glVertex2f(-0.72f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);      //Window 5 - 3
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.72f, 0.25f);
    glVertex2f(-0.78f, 0.25f);
    glVertex2f(-0.78f, 0.3f);
    glVertex2f(-0.72f, 0.3f);
    glEnd();

    glBegin(GL_QUADS);      //Window 6 - 3
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.72f, 0.35f);
    glVertex2f(-0.78f, 0.35f);
    glVertex2f(-0.78f, 0.4f);
    glVertex2f(-0.72f, 0.4f);
    glEnd();

    glBegin(GL_QUADS);      //building 1
    glColor3f(0.7f, 0.5f, 0.6f);
    glVertex2f(-0.8f, -0.2f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(-1.0f, 0.32f);
    glVertex2f(-0.8f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);      //Window 1
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.82f, -0.15f);
    glVertex2f(-0.88f, -0.15f);
    glVertex2f(-0.88f, -0.1f);
    glVertex2f(-0.82f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);      //Window 2
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.82f, -0.05f);
    glVertex2f(-0.88f, -0.05f);
    glVertex2f(-0.88f, 0.0f);
    glVertex2f(-0.82f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);      //Window 3
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.82f, 0.05f);
    glVertex2f(-0.88f, 0.05f);
    glVertex2f(-0.88f, 0.1f);
    glVertex2f(-0.82f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);      //Window 4
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.82f, 0.15f);
    glVertex2f(-0.88f, 0.15f);
    glVertex2f(-0.88f, 0.2f);
    glVertex2f(-0.82f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);      //Window 5
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.82f, 0.25f);
    glVertex2f(-0.88f, 0.25f);
    glVertex2f(-0.88f, 0.3f);
    glVertex2f(-0.82f, 0.3f);
    glEnd();

    glBegin(GL_QUADS);      //Window 6
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.92f, -0.15f);
    glVertex2f(-0.98f, -0.15f);
    glVertex2f(-0.98f, -0.1f);
    glVertex2f(-0.92f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);      //Window 7
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.92f, -0.05f);
    glVertex2f(-0.98f, -0.05f);
    glVertex2f(-0.98f, 0.0f);
    glVertex2f(-0.92f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);      //Window 8
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.92f, 0.05f);
    glVertex2f(-0.98f, 0.05f);
    glVertex2f(-0.98f, 0.1f);
    glVertex2f(-0.92f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);      //Window 9
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.92f, 0.15f);
    glVertex2f(-0.98f, 0.15f);
    glVertex2f(-0.98f, 0.2f);
    glVertex2f(-0.92f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);      //Window 10
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.92f, 0.25f);
    glVertex2f(-0.98f, 0.25f);
    glVertex2f(-0.98f, 0.3f);
    glVertex2f(-0.92f, 0.3f);
    glEnd();

    glBegin(GL_QUADS);      //building 2
    glColor3f(0.6f, 0.7f, 0.5f);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.7f, -0.2f);
    glVertex2f(-0.7f, 0.22f);
    glVertex2f(-0.5f, 0.22f);
    glEnd();

    glBegin(GL_QUADS);      //Window 1 - 2
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.52f, -0.15f);
    glVertex2f(-0.58f, -0.15f);
    glVertex2f(-0.58f, -0.1f);
    glVertex2f(-0.52f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);      //Window 2 - 2
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.52f, -0.05f);
    glVertex2f(-0.58f, -0.05f);
    glVertex2f(-0.58f, 0.0f);
    glVertex2f(-0.52f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);      //Window 3 - 2
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.52f, 0.05f);
    glVertex2f(-0.58f, 0.05f);
    glVertex2f(-0.58f, 0.1f);
    glVertex2f(-0.52f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);      //Window 4 - 2
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.52f, 0.15f);
    glVertex2f(-0.58f, 0.15f);
    glVertex2f(-0.58f, 0.2f);
    glVertex2f(-0.52f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);      //Window 5 - 2
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.62f, -0.15f);
    glVertex2f(-0.68f, -0.15f);
    glVertex2f(-0.68f, -0.1f);
    glVertex2f(-0.62f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);      //Window 6 - 2
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.62f, -0.05f);
    glVertex2f(-0.68f, -0.05f);
    glVertex2f(-0.68f, 0.0f);
    glVertex2f(-0.62f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);      //Window 7 - 2
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.62f, 0.05f);
    glVertex2f(-0.68f, 0.05f);
    glVertex2f(-0.68f, 0.1f);
    glVertex2f(-0.62f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);      //Window 8 - 2
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.62f, 0.15f);
    glVertex2f(-0.68f, 0.15f);
    glVertex2f(-0.68f, 0.2f);
    glVertex2f(-0.62f, 0.2f);
    glEnd();

	glPushMatrix();
    glTranslatef(positionBus,0.0f,  0.0f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);    //BUS
	glVertex2f(-0.63f, -0.18f);
	glVertex2f(-0.88f, -0.18f);
	glVertex2f(-0.88f, 0.04f);
	glVertex2f(-0.63f, 0.04f);
	glEnd();

	if(night)
    {
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);    //BUS Headlight
        glVertex2f(-0.88f, -0.16f);
        glVertex2f(-0.92f, -0.20f);
        glVertex2f(-0.98f, -0.20f);
        glVertex2f(-0.98f, -0.1f);
        glVertex2f(-0.88f, -0.14f);
        glEnd();
    }

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //Door
	glVertex2f(-0.635f, -0.17f);
	glVertex2f(-0.67f, -0.17f);
	glVertex2f(-0.67f, -0.07f);
	glVertex2f(-0.635f, -0.07f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 2nd row 4 no
	glVertex2f(-0.68f, -0.12f);
	glVertex2f(-0.72f, -0.12f);
	glVertex2f(-0.72f, -0.07f);
	glVertex2f(-0.68f, -0.07f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 2nd row 3 no
	glVertex2f(-0.73f, -0.12f);
	glVertex2f(-0.77f, -0.12f);
	glVertex2f(-0.77f, -0.07f);
	glVertex2f(-0.73f, -0.07f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);    //Window 2nd row 2 no
	glVertex2f(-0.78f, -0.12f);
	glVertex2f(-0.82f, -0.12f);
	glVertex2f(-0.82f, -0.07f);
	glVertex2f(-0.78f, -0.07f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);    //Window 2nd row 2 no
	glVertex2f(-0.83f, -0.12f);
	glVertex2f(-0.87f, -0.12f);
	glVertex2f(-0.87f, -0.07f);
	glVertex2f(-0.83f, -0.07f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);       // line in bus
	glVertex2f(-0.635f, -0.05f);
	glVertex2f(-0.875f, -0.05f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);    //Window 1st row 5 no
	glVertex2f(-0.635f, -0.03f);
	glVertex2f(-0.67f, -0.03f);
	glVertex2f(-0.67f, 0.02f);
	glVertex2f(-0.635f, 0.02f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 1st row 4 no
	glVertex2f(-0.68f, -0.03f);
	glVertex2f(-0.72f, -0.03f);
	glVertex2f(-0.72f, 0.02f);
	glVertex2f(-0.68f, 0.02f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 1st row 3 no
	glVertex2f(-0.73f, -0.03f);
	glVertex2f(-0.77f, -0.03f);
	glVertex2f(-0.77f, 0.02f);
	glVertex2f(-0.73f, 0.02f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 1st row 2 no
	glVertex2f(-0.78f, -0.03f);
	glVertex2f(-0.82f, -0.03f);
	glVertex2f(-0.82f, 0.02f);
	glVertex2f(-0.78f, 0.02f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 1st row 1 no
	glVertex2f(-0.83f, -0.03f);
	glVertex2f(-0.87f, -0.03f);
	glVertex2f(-0.87f, 0.02f);
	glVertex2f(-0.83f, 0.02f);

	glEnd();

    GLfloat bp1=-0.7f; GLfloat bq1= -0.18f; GLfloat br1 = 0.02f;      // 2nd Wheel of BUS
    int btringle=40;

    GLfloat btp =2.0f * PI  ;

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (bp1,bq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    bp1+(br1*cos(i*btp/btringle)),
                    bq1+(br1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat bp2=-0.85f; GLfloat bq2= -0.18f; GLfloat br2 = 0.02f;      // 1st Wheel of BUS

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (bp2,bq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    bp2+(br2*cos(i*btp/btringle)),
                    bq2+(br2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat brp1=-0.7f; GLfloat brq1= -0.18f; GLfloat brr1 = 0.015f;      // 2nd Wheel rim of bus

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(25, 25, 25);
    glVertex2f (brp1,brq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    brp1+(brr1*cos(i*btp/btringle)),
                    brq1+(brr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat brp2=-0.85f; GLfloat brq2= -0.18f; GLfloat brr2 = 0.015f;      // 1st Wheel rim of bus
	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(25, 25, 25);
    glVertex2f (brp2,brq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    brp2+(brr2*cos(i*btp/btringle)),
                    brq2+(brr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(positionBCar, 0.0f,  0.0f);

    glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);    //Blue Car
	glVertex2f(-0.62f, -0.18f);
	glVertex2f(-0.78f, -0.18f);
	glVertex2f(-0.78f, -0.13f);
	glVertex2f(-0.62f, -0.13f);

	glEnd();

	if(night)
    {
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);    //Blue car Headlight
        glVertex2f(-0.78f, -0.16f);
        glVertex2f(-0.82f, -0.20f);
        glVertex2f(-0.88f, -0.20f);
        glVertex2f(-0.88f, -0.1f);
        glVertex2f(-0.78f, -0.14f);
        glEnd();
    }

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);    //Blue Car
	glVertex2f(-0.645f, -0.13f);
	glVertex2f(-0.755f, -0.13f);
	glVertex2f(-0.74f, -0.09f);
	glVertex2f(-0.66f, -0.09f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 2nd Blue car
	glVertex2f(-0.67f, -0.125f);
	glVertex2f(-0.695f, -0.125f);
	glVertex2f(-0.695f, -0.095f);
	glVertex2f(-0.67f, -0.095f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 1st Blue car
	glVertex2f(-0.73f, -0.125f);
	glVertex2f(-0.705f, -0.125f);
	glVertex2f(-0.705f, -0.095f);
	glVertex2f(-0.73f, -0.095f);

	glEnd();

	GLfloat bcp1=-0.65f; GLfloat bcq1= -0.18f; GLfloat bcr1 = 0.02f;      // 2nd Wheel of blue car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (bcp1,bcq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    bcp1+(bcr1*cos(i*btp/btringle)),
                    bcq1+(bcr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat bcp2=-0.75f; GLfloat bcq2= -0.18f; GLfloat bcr2 = 0.02f;      // 1st Wheel of blue car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (bcp2,bcq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    bcp2+(bcr2*cos(i*btp/btringle)),
                    bcq2+(bcr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat bcrp1=-0.65f; GLfloat bcrq1= -0.18f; GLfloat bcrr1 = 0.013f;      // 2nd Wheel rim of blue car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(125, 125, 125);
    glVertex2f (bcrp1,bcrq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    bcrp1+(bcrr1*cos(i*btp/btringle)),
                    bcrq1+(bcrr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat bcrp2=-0.75f; GLfloat bcrq2= -0.18f; GLfloat bcrr2 = 0.013f;      // 1st Wheel rim of blue car
	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(125, 125, 125);
    glVertex2f (bcrp2,bcrq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    bcrp2+(bcrr2*cos(i*btp/btringle)),
                    bcrq2+(bcrr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(positionYCar, 0.0f,  0.0f);

    glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);    //yellow Car Body
	glVertex2f(-0.62f, -0.18f);
	glVertex2f(-0.78f, -0.18f);
	glVertex2f(-0.78f, -0.13f);
	glVertex2f(-0.62f, -0.13f);

	glEnd();

	if(night)
    {
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);    //yellow car Headlight
        glVertex2f(-0.78f, -0.16f);
        glVertex2f(-0.82f, -0.20f);
        glVertex2f(-0.88f, -0.20f);
        glVertex2f(-0.88f, -0.1f);
        glVertex2f(-0.78f, -0.14f);
        glEnd();
    }

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);    //yellow Car
	glVertex2f(-0.645f, -0.13f);
	glVertex2f(-0.755f, -0.13f);
	glVertex2f(-0.74f, -0.09f);
	glVertex2f(-0.66f, -0.09f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 2nd yellow car
	glVertex2f(-0.67f, -0.125f);
	glVertex2f(-0.695f, -0.125f);
	glVertex2f(-0.695f, -0.095f);
	glVertex2f(-0.67f, -0.095f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 1st yellow car
	glVertex2f(-0.73f, -0.125f);
	glVertex2f(-0.705f, -0.125f);
	glVertex2f(-0.705f, -0.095f);
	glVertex2f(-0.73f, -0.095f);

	glEnd();

	GLfloat ycp1=-0.65f; GLfloat ycq1= -0.18f; GLfloat ycr1 = 0.02f;      // 2nd Wheel of yellow car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (ycp1,ycq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    ycp1+(ycr1*cos(i*btp/btringle)),
                    ycq1+(ycr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat ycp2=-0.75f; GLfloat ycq2= -0.18f; GLfloat ycr2 = 0.02f;      // 1st Wheel of yellow car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (ycp2,ycq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    ycp2+(ycr2*cos(i*btp/btringle)),
                    ycq2+(ycr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat ycrp1=-0.65f; GLfloat ycrq1= -0.18f; GLfloat ycrr1 = 0.013f;      // 2nd Wheel rim of yellow car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(125, 125, 125);
    glVertex2f (ycrp1,ycrq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    ycrp1+(ycrr1*cos(i*btp/btringle)),
                    ycrq1+(ycrr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat ycrp2=-0.75f; GLfloat ycrq2= -0.18f; GLfloat ycrr2 = 0.013f;      // 1st Wheel rim of yellow car
	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(125, 125, 125);
    glVertex2f (ycrp2,ycrq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    ycrp2+(ycrr2*cos(i*btp/btringle)),
                    ycrq2+(ycrr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(positionGCar, 0.0f,  0.0f);

    glBegin(GL_QUADS);
	glColor3f(0.75f, 0.75f, 0.75f);    //Gray Car
	glVertex2f(-0.62f, -0.18f);
	glVertex2f(-0.78f, -0.18f);
	glVertex2f(-0.78f, -0.13f);
	glVertex2f(-0.62f, -0.13f);

	glEnd();

	if(night)
    {
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);    //Gray car Headlight
        glVertex2f(-0.62f, -0.16f);
        glVertex2f(-0.58f, -0.20f);
        glVertex2f(-0.5f, -0.20f);
        glVertex2f(-0.5f, -0.1f);
        glVertex2f(-0.62f, -0.14f);
        glEnd();
    }

	glBegin(GL_QUADS);
	glColor3f(0.75f, 0.75f, 0.75f);    //Gray Car
	glVertex2f(-0.645f, -0.13f);
	glVertex2f(-0.755f, -0.13f);
	glVertex2f(-0.74f, -0.09f);
	glVertex2f(-0.66f, -0.09f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 2nd Gray car
	glVertex2f(-0.67f, -0.125f);
	glVertex2f(-0.695f, -0.125f);
	glVertex2f(-0.695f, -0.095f);
	glVertex2f(-0.67f, -0.095f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 1st Gray car
	glVertex2f(-0.73f, -0.125f);
	glVertex2f(-0.705f, -0.125f);
	glVertex2f(-0.705f, -0.095f);
	glVertex2f(-0.73f, -0.095f);

	glEnd();

	GLfloat gcp1=-0.65f; GLfloat gcq1= -0.18f; GLfloat gcr1 = 0.02f;      // 2nd Wheel of gray car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (gcp1,gcq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    gcp1+(gcr1*cos(i*btp/btringle)),
                    gcq1+(gcr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat gcp2=-0.75f; GLfloat gcq2= -0.18f; GLfloat gcr2 = 0.02f;      // 1st Wheel of gray car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (gcp2,gcq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    gcp2+(gcr2*cos(i*btp/btringle)),
                    gcq2+(gcr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat gcrp1=-0.65f; GLfloat gcrq1= -0.18f; GLfloat gcrr1 = 0.013f;      // 2nd Wheel rim of gray car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(125, 125, 125);
    glVertex2f (gcrp1,gcrq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    gcrp1+(gcrr1*cos(i*btp/btringle)),
                    gcrq1+(gcrr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat gcrp2=-0.75f; GLfloat gcrq2= -0.18f; GLfloat gcrr2 = 0.013f;      // 1st Wheel rim of gray car
	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(125, 125, 125);
    glVertex2f (gcrp2,gcrq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    gcrp2+(gcrr2*cos(i*btp/btringle)),
                    gcrq2+(gcrr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(positionRCar, 0.0f,  0.0f);

    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);    //red Car
	glVertex2f(-0.62f, -0.18f);
	glVertex2f(-0.78f, -0.18f);
	glVertex2f(-0.78f, -0.13f);
	glVertex2f(-0.62f, -0.13f);

	glEnd();

	if(night)
    {
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);    //Red car Headlight
        glVertex2f(-0.62f, -0.16f);
        glVertex2f(-0.58f, -0.20f);
        glVertex2f(-0.5f, -0.20f);
        glVertex2f(-0.5f, -0.1f);
        glVertex2f(-0.62f, -0.14f);
        glEnd();
    }

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);    //red Car
	glVertex2f(-0.645f, -0.13f);
	glVertex2f(-0.755f, -0.13f);
	glVertex2f(-0.74f, -0.09f);
	glVertex2f(-0.66f, -0.09f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 2nd red car
	glVertex2f(-0.67f, -0.125f);
	glVertex2f(-0.695f, -0.125f);
	glVertex2f(-0.695f, -0.095f);
	glVertex2f(-0.67f, -0.095f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 1st red car
	glVertex2f(-0.73f, -0.125f);
	glVertex2f(-0.705f, -0.125f);
	glVertex2f(-0.705f, -0.095f);
	glVertex2f(-0.73f, -0.095f);

	glEnd();

	GLfloat rcp1=-0.65f; GLfloat rcq1= -0.18f; GLfloat rcr1 = 0.02f;      // 2nd Wheel of red car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (rcp1,rcq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    rcp1+(rcr1*cos(i*btp/btringle)),
                    rcq1+(rcr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat rcp2=-0.75f; GLfloat rcq2= -0.18f; GLfloat rcr2 = 0.02f;      // 1st Wheel of red car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (rcp2,rcq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    rcp2+(rcr2*cos(i*btp/btringle)),
                    rcq2+(rcr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat rcrp1=-0.65f; GLfloat rcrq1= -0.18f; GLfloat rcrr1 = 0.013f;      // 2nd Wheel rim of red car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(125, 125, 125);
    glVertex2f (rcrp1,rcrq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    rcrp1+(rcrr1*cos(i*btp/btringle)),
                    rcrq1+(rcrr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat rcrp2=-0.75f; GLfloat rcrq2= -0.18f; GLfloat rcrr2 = 0.013f;      // 1st Wheel rim of red car
	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(125, 125, 125);
    glVertex2f (rcrp2,rcrq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    rcrp2+(rcrr2*cos(i*btp/btringle)),
                    rcrq2+(rcrr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(positionBLCar, 0.0f,  0.0f);

    glBegin(GL_QUADS);
	glColor3f(0.2f, 0.2f, 0.2f);    //Black Car Body
	glVertex2f(-0.62f, -0.18f);
	glVertex2f(-0.78f, -0.18f);
	glVertex2f(-0.78f, -0.13f);
	glVertex2f(-0.62f, -0.13f);

	glEnd();

	if(night)
    {
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);    //black car Headlight
        glVertex2f(-0.62f, -0.16f);
        glVertex2f(-0.58f, -0.20f);
        glVertex2f(-0.5f, -0.20f);
        glVertex2f(-0.5f, -0.1f);
        glVertex2f(-0.62f, -0.14f);
        glEnd();
    }

	glBegin(GL_QUADS);
	glColor3f(0.2f, 0.2f, 0.2f);    //Black Car
	glVertex2f(-0.645f, -0.13f);
	glVertex2f(-0.755f, -0.13f);
	glVertex2f(-0.74f, -0.09f);
	glVertex2f(-0.66f, -0.09f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 2nd black car
	glVertex2f(-0.67f, -0.125f);
	glVertex2f(-0.695f, -0.125f);
	glVertex2f(-0.695f, -0.095f);
	glVertex2f(-0.67f, -0.095f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);   //Window 1st black car
	glVertex2f(-0.73f, -0.125f);
	glVertex2f(-0.705f, -0.125f);
	glVertex2f(-0.705f, -0.095f);
	glVertex2f(-0.73f, -0.095f);

	glEnd();

	GLfloat blcp1=-0.65f; GLfloat blcq1= -0.18f; GLfloat blcr1 = 0.02f;      // 2nd Wheel of black car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (blcp1,blcq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    blcp1+(blcr1*cos(i*btp/btringle)),
                    blcq1+(blcr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat blcp2=-0.75f; GLfloat blcq2= -0.18f; GLfloat blcr2 = 0.02f;      // 1st Wheel of black car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f (blcp2,blcq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    blcp2+(blcr2*cos(i*btp/btringle)),
                    blcq2+(blcr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat blcrp1=-0.65f; GLfloat blcrq1= -0.18f; GLfloat blcrr1 = 0.013f;      // 2nd Wheel rim of black car

	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(125, 125, 125);
    glVertex2f (blcrp1,blcrq1);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    blcrp1+(blcrr1*cos(i*btp/btringle)),
                    blcrq1+(blcrr1*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    GLfloat blcrp2=-0.75f; GLfloat blcrq2= -0.18f; GLfloat blcrr2 = 0.013f;      // 1st Wheel rim of black car
	glBegin (GL_TRIANGLE_FAN);
    glColor3ub(125, 125, 125);
    glVertex2f (blcrp2,blcrq2);
    for(i= 0;i<=btringle; i++)
    {
        glVertex2f (
                    blcrp2+(blcrr2*cos(i*btp/btringle)),
                    blcrq2+(blcrr2*sin(i*btp/btringle))
                    );
    }
    glEnd ();

    glPopMatrix();

	glPushMatrix();

    glTranslatef(-0.3f, -0.2f, 0.0f);
    glRotatef(spin,0.0f,0.0f,1.0f);

    glLineWidth(4);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(0.0+0.3f, -0.24f+0.2f);
	glVertex2f(-0.3+0.3f, -0.3f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.3f+0.3f, -0.2f+0.2f);
	glVertex2f(-0.3f+0.3f, -0.3f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.3f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.25f+0.3f, -0.29f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.25f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.25f+0.3f, -0.285f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.25f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.2f+0.3f, -0.28f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.2f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.2f+0.3f, -0.2755f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.2f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.15f+0.3f, -0.27f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.15f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.15f+0.3f, -0.265f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.15f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.1f+0.3f, -0.26f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.1f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.1f+0.3f, -0.255f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.1f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.05f+0.3f, -0.25f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of left middle road
	glVertex2f(-0.05f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.05f+0.3f, -0.245f+0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);    //middle left road
	glVertex2f(0.0f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.3f+0.3f, -0.24f+0.2f);
	glVertex2f(-0.3f+0.3f, -0.2f+0.2f);
	glVertex2f(0.0f+0.3f, -0.2f+0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);    // box of middle left road
	glVertex2f(-0.01f+0.3f, -0.225f+0.2f);
	glVertex2f(-0.3f+0.3f, -0.225f+0.2f);
	glVertex2f(-0.3f+0.3f, -0.21f+0.2f);
	glVertex2f(-0.01f+0.3f, -0.21f+0.2f);

	glEnd();

	glLineWidth(3);     // middle left road lines
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.05f+0.3f, -0.21f+0.2f);
	glVertex2f(-0.05f+0.3f, -0.225f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.1f+0.3f, -0.21f+0.2f);
	glVertex2f(-0.1f+0.3f, -0.225f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.15f+0.3f, -0.21f+0.2f);
	glVertex2f(-0.15f+0.3f, -0.225f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.2f+0.3f, -0.21f+0.2f);
	glVertex2f(-0.2f+0.3f, -0.225f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.25f+0.3f, -0.21f+0.2f);
	glVertex2f(-0.25f+0.3f, -0.225f+0.2f);

	glEnd();

    glPopMatrix();

	glBegin(GL_QUADS);
	glColor3f(0.61f, 0.7f, 0.54f);    //left Pillar
	glVertex2f(-0.3f, -0.45f);
	glVertex2f(-0.5f, -0.45f);
	glVertex2f(-0.5f, -0.19f);
	glVertex2f(-0.3f, -0.19f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //left Pillar light
	if(night)
    {
        glColor3f(0.0f, 0.0f, 0.7f);
    }
	glVertex2f(-0.395f, -0.27f);
	glVertex2f(-0.405f, -0.27f);
	glVertex2f(-0.405f, -0.25f);
	glVertex2f(-0.395f, -0.25f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //left Pillar light
	if(night)
    {
        glColor3f(0.0f, 0.0f, 0.7f);
    }
	glVertex2f(-0.375f, -0.27f);
	glVertex2f(-0.385f, -0.27f);
	glVertex2f(-0.385f, -0.25f);
	glVertex2f(-0.375f, -0.25f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //left Pillar light
	if(night)
    {
        glColor3f(0.0f, 0.0f, 0.7f);
    }
	glVertex2f(-0.415f, -0.27f);
	glVertex2f(-0.425f, -0.27f);
	glVertex2f(-0.425f, -0.25f);
	glVertex2f(-0.415f, -0.25f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //left Pillar light
	if(night)
    {
        glColor3f(0.0f, 0.0f, 0.7f);
    }
	glVertex2f(-0.46f, -0.27f);
	glVertex2f(-0.47f, -0.27f);
	glVertex2f(-0.47f, -0.25f);
	glVertex2f(-0.46f, -0.25f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //left Pillar light
	if(night)
    {
        glColor3f(0.0f, 0.0f, 0.7f);
    }
	glVertex2f(-0.33f, -0.27f);
	glVertex2f(-0.34f, -0.27f);
	glVertex2f(-0.34f, -0.25f);
	glVertex2f(-0.33f, -0.25f);

	glEnd();

	glPushMatrix();

    glTranslatef(0.3f, -0.2f, 0.0f);
    glRotatef(spin,0.0f,0.0f,-1.0f);

    glLineWidth(4);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.0f-0.3f, -0.245f+0.2f);
	glVertex2f(0.3f-0.3f, -0.3f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.3f-0.3f, -0.2f+0.2f);
	glVertex2f(0.3f-0.3f, -0.3f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.3f-0.3f, -0.24f+0.2f);
	glVertex2f(0.25f-0.3f, -0.29f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.25f-0.3f, -0.24f+0.2f);
	glVertex2f(0.25f-0.3f, -0.285f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.25f-0.3f, -0.24f+0.2f);
	glVertex2f(0.2f-0.3f, -0.28f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.2f-0.3f, -0.24f+0.2f);
	glVertex2f(0.2f-0.3f, -0.2755f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.2f-0.3f, -0.24f+0.2f);
	glVertex2f(0.15f-0.3f, -0.27f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.15f-0.3f, -0.24f+0.2f);
	glVertex2f(0.15f-0.3f, -0.265f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.15f-0.3f, -0.24f+0.2f);
	glVertex2f(0.1f-0.3f, -0.26f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.1f-0.3f, -0.24f+0.2f);
	glVertex2f(0.1f-0.3f, -0.255f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.1f-0.3f, -0.24f+0.2f);
	glVertex2f(0.05f-0.3f, -0.25f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.65f, 1.0f);       // Down design of right middle road
	glVertex2f(0.05f-0.3f, -0.24f+0.2f);
	glVertex2f(0.05f-0.3f, -0.245f+0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);    //middle right road
	glVertex2f(0.0f-0.3f, -0.24f+0.2f);
	glVertex2f(0.3f-0.3f, -0.24f+0.2f);
	glVertex2f(0.3f-0.3f, -0.2f+0.2f);
	glVertex2f(0.0f-0.3f, -0.2f+0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);    // box of middle right road
	glVertex2f(0.01f-0.3f, -0.225f+0.2f);
	glVertex2f(0.3f-0.3f, -0.225f+0.2f);
	glVertex2f(0.3f-0.3f, -0.21f+0.2f);
	glVertex2f(0.01f-0.3f, -0.21f+0.2f);

	glEnd();

	glLineWidth(3);     // middle right road lines
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.05f-0.3f, -0.21f+0.2f);
	glVertex2f(0.05f-0.3f, -0.225f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.1f-0.3f, -0.21f+0.2f);
	glVertex2f(0.1f-0.3f, -0.225f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.15f-0.3f, -0.21f+0.2f);
	glVertex2f(0.15f-0.3f, -0.225f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.2f-0.3f, -0.21f+0.2f);
	glVertex2f(0.2f-0.3f, -0.225f+0.2f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.25f-0.3f, -0.21f+0.2f);
	glVertex2f(0.25f-0.3f, -0.225f+0.2f);

	glEnd();

    glPopMatrix();

	glBegin(GL_QUADS);
	glColor3f(0.61f, 0.7f, 0.54f);    //right pillar
	glVertex2f(0.3f, -0.45f);
	glVertex2f(0.5f, -0.45f);
	glVertex2f(0.5f, -0.19f);
	glVertex2f(0.3f, -0.19f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //right Pillar light
	if(night)
    {
        glColor3f(0.0f, 0.0f, 0.7f);
    }
	glVertex2f(0.395f, -0.27f);
	glVertex2f(0.405f, -0.27f);
	glVertex2f(0.405f, -0.25f);
	glVertex2f(0.395f, -0.25f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //right Pillar light
	if(night)
    {
        glColor3f(0.0f, 0.0f, 0.7f);
    }
	glVertex2f(0.375f, -0.27f);
	glVertex2f(0.385f, -0.27f);
	glVertex2f(0.385f, -0.25f);
	glVertex2f(0.375f, -0.25f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //right Pillar light
	if(night)
    {
        glColor3f(0.0f, 0.0f, 0.7f);
    }
	glVertex2f(0.415f, -0.27f);
	glVertex2f(0.425f, -0.27f);
	glVertex2f(0.425f, -0.25f);
	glVertex2f(0.415f, -0.25f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //right Pillar light
	if(night)
    {
        glColor3f(0.0f, 0.0f, 0.7f);
    }
	glVertex2f(0.46f, -0.27f);
	glVertex2f(0.47f, -0.27f);
	glVertex2f(0.47f, -0.25f);
	glVertex2f(0.46f, -0.25f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);    //right Pillar light
	if(night)
    {
        glColor3f(0.0f, 0.0f, 0.7f);
    }
	glVertex2f(0.33f, -0.27f);
	glVertex2f(0.34f, -0.27f);
	glVertex2f(0.34f, -0.25f);
	glVertex2f(0.33f, -0.25f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);    //left road
	glVertex2f(-0.5f, -0.25f);
	glVertex2f(-1.0f, -0.25f);
	glVertex2f(-1.0f, -0.2f);
	glVertex2f(-0.5f, -0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);    // box of left road
	glVertex2f(-0.5f, -0.225f);
	glVertex2f(-1.0f, -0.225f);
	glVertex2f(-1.0f, -0.21f);
	glVertex2f(-0.5f, -0.21f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.55f, -0.21f);
	glVertex2f(-0.55f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.6f, -0.21f);
	glVertex2f(-0.6f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.65f, -0.21f);
	glVertex2f(-0.65f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.70f, -0.21f);
	glVertex2f(-0.70f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.75f, -0.21f);
	glVertex2f(-0.75f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.80f, -0.21f);
	glVertex2f(-0.80f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.85f, -0.21f);
	glVertex2f(-0.85f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.90f, -0.21f);
	glVertex2f(-0.90f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.95f, -0.21f);
	glVertex2f(-0.95f, -0.225f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);    //right road
	glVertex2f(0.5f, -0.25f);
	glVertex2f(1.0f, -0.25f);
	glVertex2f(1.0f, -0.2f);
	glVertex2f(0.5f, -0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);    // box of right road
	glVertex2f(0.5f, -0.225f);
	glVertex2f(1.0f, -0.225f);
	glVertex2f(1.0f, -0.21f);
	glVertex2f(0.5f, -0.21f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.55f, -0.21f);
	glVertex2f(0.55f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.6f, -0.21f);
	glVertex2f(0.6f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.65f, -0.21f);
	glVertex2f(0.65f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.70f, -0.21f);
	glVertex2f(0.70f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.75f, -0.21f);
	glVertex2f(0.75f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.80f, -0.21f);
	glVertex2f(0.80f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.85f, -0.21f);
	glVertex2f(0.85f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.90f, -0.21f);
	glVertex2f(0.90f, -0.225f);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.95f, -0.21f);
	glVertex2f(0.95f, -0.225f);

	glEnd();

	//left building

	glBegin(GL_QUADS);
    glColor3f(0.66f, 0.75f, 0.59f);         //left building
    glVertex2f(-0.33f, -0.19f);
    glVertex2f(-0.47f,-0.19f);
    glVertex2f(-0.47f, 0.65f);
    glVertex2f(-0.33f, 0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);         //left building left side border
    glVertex2f(-0.44f, -0.19f);
    glVertex2f(-0.47f,-0.19f);
    glVertex2f(-0.47f, 0.65f);
    glVertex2f(-0.44f, 0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);        //left building right side border
    glVertex2f(-0.33f, -0.19f);
    glVertex2f(-0.36f,-0.19f);
    glVertex2f(-0.36f, 0.65f);
    glVertex2f(-0.33f, 0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);         //left building 1st line fill up
    glVertex2f(-0.33f, 0.075f);
    glVertex2f(-0.47f, 0.075f);
    glVertex2f(-0.47f, 0.1f);
    glVertex2f(-0.33f, 0.1f);
    glEnd();

    glLineWidth(2.5);     // 1st Line on left building  1
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(-0.33f, 0.1f);
	glVertex2f(-0.47f, 0.1f);

	glEnd();

	glLineWidth(2.5);     // 1st Line on left building  2
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(-0.33f, 0.075f);
	glVertex2f(-0.47f, 0.075f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 1st Line Door
    glVertex2f(-0.39f, -0.07f);
    glVertex2f(-0.41f, -0.07f);
    glVertex2f(-0.41f, 0.025f);
    glVertex2f(-0.39f, 0.025f);

    glEnd();

    glLineWidth(1.5);     // left building 1st Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.4f, -0.07f);
	glVertex2f(-0.4f, 0.025f);

	glEnd();

	glLineWidth(1.5);     // left building 1st Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.39f, -0.01f);
	glVertex2f(-0.41f, -0.01f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 1st Line Door
    glVertex2f(-0.42f, 0.0f);
    glVertex2f(-0.435f, 0.0f);
    glVertex2f(-0.435f, 0.05f);
    glVertex2f(-0.42f, 0.05f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 1st Line Door
    glVertex2f(-0.365f, 0.0f);
    glVertex2f(-0.38f, 0.0f);
    glVertex2f(-0.38f, 0.05f);
    glVertex2f(-0.365f, 0.05f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 1st Line Door
    glVertex2f(-0.42f, -0.07f);
    glVertex2f(-0.435f, -0.07f);
    glVertex2f(-0.435f, -0.02f);
    glVertex2f(-0.42f, -0.02f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 1st Line Door
    glVertex2f(-0.365f, -0.07f);
    glVertex2f(-0.38f, -0.07f);
    glVertex2f(-0.38f, -0.02f);
    glVertex2f(-0.365f, -0.02f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 1st Line Door
    glVertex2f(-0.42f, -0.09f);
    glVertex2f(-0.435f, -0.09f);
    glVertex2f(-0.435f, -0.14f);
    glVertex2f(-0.42f, -0.14f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 1st Line Door
    glVertex2f(-0.365f, -0.09f);
    glVertex2f(-0.38f, -0.09f);
    glVertex2f(-0.38f, -0.14f);
    glVertex2f(-0.365f, -0.14f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 1st Line Door
    glVertex2f(-0.39f, -0.09f);
    glVertex2f(-0.41f, -0.09f);
    glVertex2f(-0.41f, -0.14f);
    glVertex2f(-0.39f, -0.14f);

    glEnd();

    glLineWidth(1.5);     // left building 1st Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.4f, -0.09f);
	glVertex2f(-0.4f, -0.14f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);         //left building 2nd line fill up
    glVertex2f(-0.33f, 0.275f);
    glVertex2f(-0.47f, 0.275f);
    glVertex2f(-0.47f, 0.3f);
    glVertex2f(-0.33f, 0.3f);
    glEnd();

	glLineWidth(2.5);     // 2nd Line on left building  1
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(-0.33f, 0.3f);
	glVertex2f(-0.47f, 0.3f);

	glEnd();

	glLineWidth(2.5);     // 2nd Line on left building  2
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(-0.33f, 0.275f);
	glVertex2f(-0.47f, 0.275f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 2nd Line Door
    glVertex2f(-0.39f, 0.12f);
    glVertex2f(-0.41f, 0.12f);
    glVertex2f(-0.41f, 0.2f);
    glVertex2f(-0.39f, 0.2f);

    glEnd();

    glLineWidth(1.5);     // left building 2nd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.4f, 0.2f);
	glVertex2f(-0.4f, 0.12f);

	glEnd();

	glLineWidth(1.5);     // left building 2nd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.39f, 0.17f);
	glVertex2f(-0.41f, 0.17f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 2nd Line Door
    glVertex2f(-0.42f, 0.12f);
    glVertex2f(-0.435f, 0.12f);
    glVertex2f(-0.435f, 0.2f);
    glVertex2f(-0.42f, 0.2f);

    glEnd();

    glLineWidth(1.5);     // left building 2nd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.42f, 0.17f);
	glVertex2f(-0.435f, 0.17f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 2nd Line Door
    glVertex2f(-0.365f, 0.12f);
    glVertex2f(-0.38f, 0.12f);
    glVertex2f(-0.38f, 0.2f);
    glVertex2f(-0.365f, 0.2f);

    glEnd();

    glLineWidth(1.5);     // left building 2nd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.365f, 0.17f);
	glVertex2f(-0.38f, 0.17f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);         //left building 3rd line fill up
    glVertex2f(-0.33f, 0.425f);
    glVertex2f(-0.47f, 0.425f);
    glVertex2f(-0.47f, 0.45f);
    glVertex2f(-0.33f, 0.45f);
    glEnd();

	glLineWidth(2.5);     // 3rd Line on left building  1
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(-0.33f, 0.45f);
	glVertex2f(-0.47f, 0.45f);

	glEnd();

	glLineWidth(2.5);     // 3rd Line on left building  2
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(-0.33f, 0.425f);
	glVertex2f(-0.47f, 0.425f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 3rd Line Door
    glVertex2f(-0.392f, 0.32f);
    glVertex2f(-0.408f, 0.32f);
    glVertex2f(-0.408f, 0.4f);
    glVertex2f(-0.392f, 0.4f);

    glEnd();

    glLineWidth(1.5);     // left building 3rd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.392f, 0.37f);
	glVertex2f(-0.408f, 0.37f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 3rd Line Door
    glVertex2f(-0.42f, 0.32f);
    glVertex2f(-0.435f, 0.32f);
    glVertex2f(-0.435f, 0.4f);
    glVertex2f(-0.42f, 0.4f);

    glEnd();

    glLineWidth(1.5);     // left building 3rd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.42f, 0.37f);
	glVertex2f(-0.435f, 0.37f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 3rd Line Door
    glVertex2f(-0.365f, 0.32f);
    glVertex2f(-0.38f, 0.32f);
    glVertex2f(-0.38f, 0.4f);
    glVertex2f(-0.365f, 0.4f);

    glEnd();

    glLineWidth(1.5);     // left building 3rd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.365f, 0.37f);
	glVertex2f(-0.38f, 0.37f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.95f, 0.4f, 0.4f);         //left building top filled lines
    glVertex2f(-0.33f, 0.6f);
    glVertex2f(-0.47f, 0.6f);
    glVertex2f(-0.47f, 0.62f);
    glVertex2f(-0.33f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 4th line
    glVertex2f(-0.385f, 0.5f);
    glVertex2f(-0.415f, 0.5f);
    glVertex2f(-0.415f, 0.56f);
    glVertex2f(-0.385f, 0.56f);

    glEnd();

    glLineWidth(1.5);     // left building 4th line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.395f, 0.5f);
	glVertex2f(-0.395f, 0.56f);

	glEnd();

	glLineWidth(1.5);     // left building 4th line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.405f, 0.5f);
	glVertex2f(-0.405f, 0.56f);

	glEnd();

	glLineWidth(1.5);     // left building 4th line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.385f, 0.53f);
	glVertex2f(-0.415f, 0.53f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 4th Line Door
    glVertex2f(-0.425f, 0.5f);
    glVertex2f(-0.435f, 0.5f);
    glVertex2f(-0.435f, 0.56f);
    glVertex2f(-0.425f, 0.56f);

    glEnd();

    glLineWidth(1.5);     // left building 4th Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.425f, 0.53f);
	glVertex2f(-0.435f, 0.53f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building 4th Line Door
    glVertex2f(-0.365f, 0.5f);
    glVertex2f(-0.375f, 0.5f);
    glVertex2f(-0.375f, 0.56f);
    glVertex2f(-0.365f, 0.56f);

    glEnd();

    glLineWidth(1.5);     // left building 4th Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.365f, 0.53f);
	glVertex2f(-0.375f, 0.53f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.66f, 0.75f, 0.59f);          //left building roof
    glVertex2f(-0.34f, 0.65f);
    glVertex2f(-0.46f, 0.65f);
    glVertex2f(-0.46f, 0.75f);
    glVertex2f(-0.34f, 0.75f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38f, 0.52f, 0.35f);          //left building middle top
    glVertex2f(-0.36f, 0.65f);
    glVertex2f(-0.44f, 0.65f);
    glVertex2f(-0.4f, 0.87f);

    glEnd();

    glLineWidth(4);     // 3rd Line on left building  2
	glBegin(GL_LINES);
	glColor3f(0.8f, 0.8f, 0.0f);
	glVertex2f(-0.4f, 0.85f);
	glVertex2f(-0.4f, 0.92f);

	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.87f, 0.89f, 0.81f);          //left building middle
    glVertex2f(-0.38f, 0.65f);
    glVertex2f(-0.42f, 0.65f);
    glVertex2f(-0.42f, 0.72f);
    glVertex2f(-0.4f, 0.77f);
    glVertex2f(-0.38f, 0.72f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //left building middle door
    glVertex2f(-0.385f, 0.66f);
    glVertex2f(-0.415f, 0.66f);
    glVertex2f(-0.415f, 0.71f);
    glVertex2f(-0.385f, 0.71f);

    glEnd();

    glLineWidth(1.5);     // left building middle door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.395f, 0.66f);
	glVertex2f(-0.395f, 0.71f);

	glEnd();

	glLineWidth(1.5);     // left building middle door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.405f, 0.66f);
	glVertex2f(-0.405f, 0.71f);

	glEnd();

	glLineWidth(1.5);     // left building middle door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.385f, 0.685f);
	glVertex2f(-0.415f, 0.685f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.87f, 0.89f, 0.81f);          //left building top overwrite
    glVertex2f(-0.33f, 0.62f);
    glVertex2f(-0.47f, 0.62f);
    glVertex2f(-0.47f, 0.65f);
    glVertex2f(-0.33f, 0.65f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.89f, 0.81f);          //left building left triangle
    glVertex2f(-0.44f, 0.65f);
    glVertex2f(-0.47f, 0.65f);
    glVertex2f(-0.47f, 0.71f);
    glVertex2f(-0.44f, 0.71f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38f, 0.52f, 0.35f);     //left building left triangle
    glVertex2f(-0.44f, 0.71f);
    glVertex2f(-0.47f, 0.71f);
    glVertex2f(-0.455f, 0.83f);

    glEnd();

    glLineWidth(1.5);     // left building left triangle
	glBegin(GL_LINES);
	glColor3f(0.38f, 0.52f, 0.35f);
	glVertex2f(-0.44f, 0.69f);
	glVertex2f(-0.47f, 0.69f);

	glEnd();

	glLineWidth(2);     // left building left triangle
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.455f, 0.82f);
	glVertex2f(-0.455f, 0.86f);

	glEnd();

	glLineWidth(2);     // left building left triangle
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.46f, 0.84f);
	glVertex2f(-0.45f, 0.84f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.89f, 0.81f);          //left building right triangle
    glVertex2f(-0.33f, 0.65f);
    glVertex2f(-0.36f, 0.65f);
    glVertex2f(-0.36f, 0.71f);
    glVertex2f(-0.33f, 0.71f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38f, 0.52f, 0.35f);     //left building right triangle
    glVertex2f(-0.33f, 0.71f);
    glVertex2f(-0.36f, 0.71f);
    glVertex2f(-0.345f, 0.83f);

    glEnd();

    glLineWidth(1.5);     // left building right triangle
	glBegin(GL_LINES);
	glColor3f(0.38f, 0.52f, 0.35f);
	glVertex2f(-0.33f, 0.69f);
	glVertex2f(-0.36f, 0.69f);

	glEnd();

	glLineWidth(2);     // left building right triangle
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.345f, 0.82f);
	glVertex2f(-0.345f, 0.86f);

	glEnd();

	glLineWidth(2);     // left building right triangle
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.35f, 0.84f);
	glVertex2f(-0.34f, 0.84f);

	glEnd();

	//left building

	//right building

	glBegin(GL_QUADS);
    glColor3f(0.66f, 0.75f, 0.59f);         //right building
    glVertex2f(0.33f, -0.19f);
    glVertex2f(0.47f,-0.19f);
    glVertex2f(0.47f, 0.65f);
    glVertex2f(0.33f, 0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);         //right building left side border
    glVertex2f(0.44f, -0.19f);
    glVertex2f(0.47f,-0.19f);
    glVertex2f(0.47f, 0.65f);
    glVertex2f(0.44f, 0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);        //right building right side border
    glVertex2f(0.33f, -0.19f);
    glVertex2f(0.36f,-0.19f);
    glVertex2f(0.36f, 0.65f);
    glVertex2f(0.33f, 0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);         //right building 1st line fill up
    glVertex2f(0.33f, 0.075f);
    glVertex2f(0.47f, 0.075f);
    glVertex2f(0.47f, 0.1f);
    glVertex2f(0.33f, 0.1f);
    glEnd();

    glLineWidth(2.5);     // 1st Line on right building  1
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(0.33f, 0.1f);
	glVertex2f(0.47f, 0.1f);

	glEnd();

	glLineWidth(2.5);     // 1st Line on right building  2
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(0.33f, 0.075f);
	glVertex2f(0.47f, 0.075f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 1st Line Door
    glVertex2f(0.39f, -0.07f);
    glVertex2f(0.41f, -0.07f);
    glVertex2f(0.41f, 0.025f);
    glVertex2f(0.39f, 0.025f);

    glEnd();

    glLineWidth(1.5);     // right building 1st Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.4f, -0.07f);
	glVertex2f(0.4f, 0.025f);

	glEnd();

	glLineWidth(1.5);     // right building 1st Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.39f, -0.01f);
	glVertex2f(0.41f, -0.01f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 1st Line Door
    glVertex2f(0.42f, 0.0f);
    glVertex2f(0.435f, 0.0f);
    glVertex2f(0.435f, 0.05f);
    glVertex2f(0.42f, 0.05f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 1st Line Door
    glVertex2f(0.365f, 0.0f);
    glVertex2f(0.38f, 0.0f);
    glVertex2f(0.38f, 0.05f);
    glVertex2f(0.365f, 0.05f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 1st Line Door
    glVertex2f(0.42f, -0.07f);
    glVertex2f(0.435f, -0.07f);
    glVertex2f(0.435f, -0.02f);
    glVertex2f(0.42f, -0.02f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 1st Line Door
    glVertex2f(0.365f, -0.07f);
    glVertex2f(0.38f, -0.07f);
    glVertex2f(0.38f, -0.02f);
    glVertex2f(0.365f, -0.02f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 1st Line Door
    glVertex2f(0.42f, -0.09f);
    glVertex2f(0.435f, -0.09f);
    glVertex2f(0.435f, -0.14f);
    glVertex2f(0.42f, -0.14f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 1st Line Door
    glVertex2f(0.365f, -0.09f);
    glVertex2f(0.38f, -0.09f);
    glVertex2f(0.38f, -0.14f);
    glVertex2f(0.365f, -0.14f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 1st Line Door
    glVertex2f(0.39f, -0.09f);
    glVertex2f(0.41f, -0.09f);
    glVertex2f(0.41f, -0.14f);
    glVertex2f(0.39f, -0.14f);

    glEnd();

    glLineWidth(1.5);     // right building 1st Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.4f, -0.09f);
	glVertex2f(0.4f, -0.14f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);         //right building 2nd line fill up
    glVertex2f(0.33f, 0.275f);
    glVertex2f(0.47f, 0.275f);
    glVertex2f(0.47f, 0.3f);
    glVertex2f(0.33f, 0.3f);
    glEnd();

	glLineWidth(2.5);     // 2nd Line on right building  1
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(0.33f, 0.3f);
	glVertex2f(0.47f, 0.3f);

	glEnd();

	glLineWidth(2.5);     // 2nd Line on right building  2
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(0.33f, 0.275f);
	glVertex2f(0.47f, 0.275f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 2nd Line Door
    glVertex2f(0.39f, 0.12f);
    glVertex2f(0.41f, 0.12f);
    glVertex2f(0.41f, 0.2f);
    glVertex2f(0.39f, 0.2f);

    glEnd();

    glLineWidth(1.5);     // right building 2nd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.4f, 0.2f);
	glVertex2f(0.4f, 0.12f);

	glEnd();

	glLineWidth(1.5);     // right building 2nd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.39f, 0.17f);
	glVertex2f(0.41f, 0.17f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 2nd Line Door
    glVertex2f(0.42f, 0.12f);
    glVertex2f(0.435f, 0.12f);
    glVertex2f(0.435f, 0.2f);
    glVertex2f(0.42f, 0.2f);

    glEnd();

    glLineWidth(1.5);     // right building 2nd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.42f, 0.17f);
	glVertex2f(0.435f, 0.17f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 2nd Line Door
    glVertex2f(0.365f, 0.12f);
    glVertex2f(0.38f, 0.12f);
    glVertex2f(0.38f, 0.2f);
    glVertex2f(0.365f, 0.2f);

    glEnd();

    glLineWidth(1.5);     // right building 2nd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.365f, 0.17f);
	glVertex2f(0.38f, 0.17f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);         //right building 3rd line fill up
    glVertex2f(0.33f, 0.425f);
    glVertex2f(0.47f, 0.425f);
    glVertex2f(0.47f, 0.45f);
    glVertex2f(0.33f, 0.45f);
    glEnd();

	glLineWidth(2.5);     // 3rd Line on right building  1
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(0.33f, 0.45f);
	glVertex2f(0.47f, 0.45f);

	glEnd();

	glLineWidth(2.5);     // 3rd Line on right building  2
	glBegin(GL_LINES);
	glColor3f(0.95f, 0.4f, 0.4f);
	glVertex2f(0.33f, 0.425f);
	glVertex2f(0.47f, 0.425f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 3rd Line Door
    glVertex2f(0.392f, 0.32f);
    glVertex2f(0.408f, 0.32f);
    glVertex2f(0.408f, 0.4f);
    glVertex2f(0.392f, 0.4f);

    glEnd();

    glLineWidth(1.5);     // right building 3rd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.392f, 0.37f);
	glVertex2f(0.408f, 0.37f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 3rd Line Door
    glVertex2f(0.42f, 0.32f);
    glVertex2f(0.435f, 0.32f);
    glVertex2f(0.435f, 0.4f);
    glVertex2f(0.42f, 0.4f);

    glEnd();

    glLineWidth(1.5);     // right building 3rd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.42f, 0.37f);
	glVertex2f(0.435f, 0.37f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 3rd Line Door
    glVertex2f(0.365f, 0.32f);
    glVertex2f(0.38f, 0.32f);
    glVertex2f(0.38f, 0.4f);
    glVertex2f(0.365f, 0.4f);

    glEnd();

    glLineWidth(1.5);     // right building 3rd Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.365f, 0.37f);
	glVertex2f(0.38f, 0.37f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.95f, 0.4f, 0.4f);         //right building top filled lines
    glVertex2f(0.33f, 0.6f);
    glVertex2f(0.47f, 0.6f);
    glVertex2f(0.47f, 0.62f);
    glVertex2f(0.33f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 4th line
    glVertex2f(0.385f, 0.5f);
    glVertex2f(0.415f, 0.5f);
    glVertex2f(0.415f, 0.56f);
    glVertex2f(0.385f, 0.56f);

    glEnd();

    glLineWidth(1.5);     // right building 4th line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.395f, 0.5f);
	glVertex2f(0.395f, 0.56f);

	glEnd();

	glLineWidth(1.5);     // right building 4th line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.405f, 0.5f);
	glVertex2f(0.405f, 0.56f);

	glEnd();

	glLineWidth(1.5);     // right building 4th line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.385f, 0.53f);
	glVertex2f(0.415f, 0.53f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 4th Line Door
    glVertex2f(0.425f, 0.5f);
    glVertex2f(0.435f, 0.5f);
    glVertex2f(0.435f, 0.56f);
    glVertex2f(0.425f, 0.56f);

    glEnd();

    glLineWidth(1.5);     // right building 4th Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.425f, 0.53f);
	glVertex2f(0.435f, 0.53f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building 4th Line Door
    glVertex2f(0.365f, 0.5f);
    glVertex2f(0.375f, 0.5f);
    glVertex2f(0.375f, 0.56f);
    glVertex2f(0.365f, 0.56f);

    glEnd();

    glLineWidth(1.5);     // right building 4th Line Door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.365f, 0.53f);
	glVertex2f(0.375f, 0.53f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.66f, 0.75f, 0.59f);          //right building roof
    glVertex2f(0.34f, 0.65f);
    glVertex2f(0.46f, 0.65f);
    glVertex2f(0.46f, 0.75f);
    glVertex2f(0.34f, 0.75f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38f, 0.52f, 0.35f);          //right building middle top
    glVertex2f(0.36f, 0.65f);
    glVertex2f(0.44f, 0.65f);
    glVertex2f(0.4f, 0.87f);

    glEnd();

    glLineWidth(4);     // 3rd Line on right building  2
	glBegin(GL_LINES);
	glColor3f(0.8f, 0.8f, 0.0f);
	glVertex2f(0.4f, 0.85f);
	glVertex2f(0.4f, 0.92f);

	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.87f, 0.89f, 0.81f);          //right building middle
    glVertex2f(0.38f, 0.65f);
    glVertex2f(0.42f, 0.65f);
    glVertex2f(0.42f, 0.72f);
    glVertex2f(0.4f, 0.77f);
    glVertex2f(0.38f, 0.72f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.33f, 0.33f);         //right building middle door
    glVertex2f(0.385f, 0.66f);
    glVertex2f(0.415f, 0.66f);
    glVertex2f(0.415f, 0.71f);
    glVertex2f(0.385f, 0.71f);

    glEnd();

    glLineWidth(1.5);     // right building middle door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.395f, 0.66f);
	glVertex2f(0.395f, 0.71f);

	glEnd();

	glLineWidth(1.5);     // right building middle door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.405f, 0.66f);
	glVertex2f(0.405f, 0.71f);

	glEnd();

	glLineWidth(1.5);     // right building middle door
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.385f, 0.685f);
	glVertex2f(0.415f, 0.685f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.87f, 0.89f, 0.81f);          //right building top overwrite
    glVertex2f(0.33f, 0.62f);
    glVertex2f(0.47f, 0.62f);
    glVertex2f(0.47f, 0.65f);
    glVertex2f(0.33f, 0.65f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.89f, 0.81f);          //right building left triangle
    glVertex2f(0.44f, 0.65f);
    glVertex2f(0.47f, 0.65f);
    glVertex2f(0.47f, 0.71f);
    glVertex2f(0.44f, 0.71f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38f, 0.52f, 0.35f);     //right building left triangle
    glVertex2f(0.44f, 0.71f);
    glVertex2f(0.47f, 0.71f);
    glVertex2f(0.455f, 0.83f);

    glEnd();

    glLineWidth(1.5);     // right building left triangle
	glBegin(GL_LINES);
	glColor3f(0.38f, 0.52f, 0.35f);
	glVertex2f(0.44f, 0.69f);
	glVertex2f(0.47f, 0.69f);

	glEnd();

	glLineWidth(2);     // right building left triangle
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.455f, 0.82f);
	glVertex2f(0.455f, 0.86f);

	glEnd();

	glLineWidth(2);     // right building left triangle
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.46f, 0.84f);
	glVertex2f(0.45f, 0.84f);

	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.89f, 0.81f);          //right building right triangle
    glVertex2f(0.33f, 0.65f);
    glVertex2f(0.36f, 0.65f);
    glVertex2f(0.36f, 0.71f);
    glVertex2f(0.33f, 0.71f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38f, 0.52f, 0.35f);     //right building right triangle
    glVertex2f(0.33f, 0.71f);
    glVertex2f(0.36f, 0.71f);
    glVertex2f(0.345f, 0.83f);

    glEnd();

    glLineWidth(1.5);     // right building right triangle
	glBegin(GL_LINES);
	glColor3f(0.38f, 0.52f, 0.35f);
	glVertex2f(0.33f, 0.69f);
	glVertex2f(0.36f, 0.69f);

	glEnd();

	glLineWidth(2);     // right building right triangle
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.345f, 0.82f);
	glVertex2f(0.345f, 0.86f);

	glEnd();

	glLineWidth(2);     // right building right triangle
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.35f, 0.84f);
	glVertex2f(0.34f, 0.84f);

	glEnd();

	//right building

    glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.33f, 0.54f);
	glVertex2f(-0.27f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.27f, 0.54f);
	glVertex2f(-0.21f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.21f, 0.54f);
	glVertex2f(-0.15f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.15f, 0.54f);
	glVertex2f(-0.09f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.09f, 0.54f);
	glVertex2f(-0.03f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.03f, 0.54f);
	glVertex2f(0.03f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.03f, 0.54f);
	glVertex2f(0.09f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.09f, 0.54f);
	glVertex2f(0.15f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.15f, 0.54f);
	glVertex2f(0.21f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.21f, 0.54f);
	glVertex2f(0.27f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.27f, 0.54f);
	glVertex2f(0.33f, 0.5f);

	glEnd();


	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.33f, 0.54f);
	glVertex2f(0.27f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.27f, 0.54f);
	glVertex2f(0.21f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.21f, 0.54f);
	glVertex2f(0.15f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.15f, 0.54f);
	glVertex2f(0.09f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.09f, 0.54f);
	glVertex2f(0.03f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.03f, 0.54f);
	glVertex2f(-0.03f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.03f, 0.54f);
	glVertex2f(-0.09f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.09f, 0.54f);
	glVertex2f(-0.15f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.15f, 0.54f);
	glVertex2f(-0.21f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.21f, 0.54f);
	glVertex2f(-0.27f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector design
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.27f, 0.54f);
	glVertex2f(-0.33f, 0.5f);

	glEnd();

	glLineWidth(2);     // middle connector logo part
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(0.0f, 0.56f);
	glVertex2f(0.0f, 0.58f);

	glEnd();

	glLineWidth(2);     // middle connector logo part
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.005f, 0.57f);
	glVertex2f(0.005f, 0.57f);

	glEnd();

	glLineWidth(2);     // middle connector logo part
	glBegin(GL_LINES);
	glColor3f(0.87f, 0.89f, 0.81f);
	glVertex2f(0.018f, 0.56f);
	glVertex2f(0.018f, 0.57f);

	glEnd();

	glLineWidth(2);     // middle connector logo part
	glBegin(GL_LINES);
	glColor3f(0.87f, 0.89f, 0.81f);
	glVertex2f(-0.018f, 0.56f);
	glVertex2f(-0.018f, 0.57f);

	glEnd();

	glLineWidth(2);     // FLAG Right
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.09f, 0.55f);
	glVertex2f(0.09f, 0.7f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);          //FLAG right
    glVertex2f(0.13f, 0.65f);
    glVertex2f(0.09f, 0.65f);
    glVertex2f(0.09f, 0.7f);
    glVertex2f(0.13f, 0.7f);

    glEnd();

    glLineWidth(3);     // FLAG right
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.11f, 0.65f);
	glVertex2f(0.11f, 0.7f);

	glEnd();

	glLineWidth(3);     // FLAG right
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.13f, 0.675f);
	glVertex2f(0.09f, 0.675f);

	glEnd();

	glLineWidth(2);     // FLAG Left
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.09f, 0.55f);
	glVertex2f(-0.09f, 0.7f);

	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);          //FLAG left
    glVertex2f(-0.05f, 0.65f);
    glVertex2f(-0.09f, 0.65f);
    glVertex2f(-0.09f, 0.7f);
    glVertex2f(-0.05f, 0.7f);

    glEnd();

    glLineWidth(5);     // FLAG left
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.07f, 0.65f);
	glVertex2f(-0.07f, 0.7f);

	glEnd();

	glLineWidth(5);     // FLAG left
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.05f, 0.675f);
	glVertex2f(-0.09f, 0.675f);

	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);         //Flag Left
    glVertex2f(-0.05f, 0.65f);
    glVertex2f(-0.055f, 0.65f);
    glVertex2f(-0.09f, 0.695f);
    glVertex2f(-0.09f, 0.7f);
    glVertex2f(-0.085f, 0.7f);
    glVertex2f(-0.05f, 0.655f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);         //Flag Left
    glVertex2f(-0.05f, 0.7f);
    glVertex2f(-0.05f, 0.695f);
    glVertex2f(-0.085f, 0.65f);
    glVertex2f(-0.09f, 0.65f);
    glVertex2f(-0.09f, 0.655f);
    glVertex2f(-0.055f, 0.7f);

    glEnd();

    glLineWidth(3);     // FLAG left
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.07f, 0.65f);
	glVertex2f(-0.07f, 0.7f);

	glEnd();

	glLineWidth(3);     // FLAG left
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.09f, 0.675f);
	glVertex2f(-0.05f, 0.675f);

	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);         //Flag Left
    glVertex2f(-0.05f, 0.65f);
    glVertex2f(-0.053f, 0.65f);
    glVertex2f(-0.09f, 0.697f);
    glVertex2f(-0.09f, 0.7f);
    glVertex2f(-0.087f, 0.7f);
    glVertex2f(-0.05f, 0.653f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);         //Flag Left
    glVertex2f(-0.05f, 0.7f);
    glVertex2f(-0.05f, 0.697f);
    glVertex2f(-0.087f, 0.65f);
    glVertex2f(-0.09f, 0.65f);
    glVertex2f(-0.09f, 0.653f);
    glVertex2f(-0.053f, 0.7f);

    glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);          //middle connector 1st part
    glVertex2f(-0.33f, 0.54f);
    glVertex2f(0.33f, 0.54f);
    glVertex2f(0.33f, 0.55f);
    glVertex2f(-0.33f, 0.55f);

    glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);          //middle connector 2nd part
    glVertex2f(-0.33f, 0.48f);
    glVertex2f(0.33f, 0.48f);
    glVertex2f(0.33f, 0.5f);
    glVertex2f(-0.33f, 0.5f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);          //middle connector Logo
    glVertex2f(0.02f, 0.48f);
    glVertex2f(-0.02f, 0.48f);
    glVertex2f(-0.02f, 0.56f);
    glVertex2f(0.02f, 0.56f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);          //middle connector left logo
    glVertex2f(-0.15f, 0.48f);
    glVertex2f(-0.175f, 0.48f);
    glVertex2f(-0.175f, 0.55f);
    glVertex2f(-0.15f, 0.55f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.72f, 0.55f);          //middle connector right logo
    glVertex2f(0.15f, 0.48f);
    glVertex2f(0.175f, 0.48f);
    glVertex2f(0.175f, 0.55f);
    glVertex2f(0.15f, 0.55f);

    glEnd();

    glLineWidth(3);     // left side extra design middle line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.72f, 0.13f);
	glVertex2f(-0.72f, -0.2f);

	glEnd();

	glLineWidth(3);     // left side extra design right line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.595f, 0.295f);
	glVertex2f(-0.595f, -0.2f);

	glEnd();

	glLineWidth(3);     // left side extra design left line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.845f, -0.02f);
	glVertex2f(-0.845f, -0.2f);

	glEnd();

    glLineWidth(7);     // Left side Big Blue line
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.47f, 0.44f);
	glVertex2f(-1.0f, -0.2f);

	glEnd();

	glLineWidth(3);     // right side extra design middle line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.72f, 0.13f);
	glVertex2f(0.72f, -0.2f);

	glEnd();

	glLineWidth(3);     // right side extra design left line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.595f, 0.295f);
	glVertex2f(0.595f, -0.2f);

	glEnd();

	glLineWidth(3);     // left side extra design right line
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.845f, -0.02f);
	glVertex2f(0.845f, -0.2f);

	glEnd();

    glLineWidth(7);     // Left side Big Blue line
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.47f, 0.44f);
	glVertex2f(1.0f, -0.2f);

	glEnd();


	//ship

	glPushMatrix();
    glTranslatef(positionShip, 0.0f, 0.0f);

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // black
    glVertex2f(-1.0f, -0.85f);    // x, y
    glVertex2f(-0.9f,-0.95f);
    glVertex2f(-0.8f, -0.95f);
    glVertex2f(-0.7f, -0.85f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.1f, 0.64f, 0.63f); // cyan
    glVertex2f(-0.89f, -0.94f);    // x, y
    glVertex2f(-0.9f, -0.95f);
    glVertex2f(-0.8f, -0.95f);
    glVertex2f(-0.79f, -0.94f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.44f, 0.73f, 0.06f); // green
    glVertex2f(-1.0f, -0.84f);    // x, y
    glVertex2f(-1.0f, -0.85f);
    glVertex2f(-0.7f, -0.85f);
    glVertex2f(-0.7f, -0.84f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.05f, 0.18f, 0.45f); // navy-blue
    glVertex2f(-0.97f, -0.8f);    // x, y
    glVertex2f(-0.97f, -0.84f);
    glVertex2f(-0.71f, -0.84f);
    glVertex2f(-0.71f, -0.8f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.38f, 0.01f, 0.36f); // purple
    glVertex2f(-0.96f, -0.75f);    // x, y
    glVertex2f(-0.96f, -0.8f);
    glVertex2f(-0.71f, -0.8f);
    glVertex2f(-0.75f, -0.75f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.82f, 0.36f, 0.44f); // pink
    glVertex2f(-0.9f, -0.76f);    // x, y
    glVertex2f(-0.9f, -0.79f);
    glVertex2f(-0.72f, -0.79f);
    glVertex2f(-0.74f, -0.76f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.68f, 0.22f, 0.0f); // orange
    glVertex2f(-0.95f, -0.74f);    // x, y
    glVertex2f(-0.96f, -0.75f);
    glVertex2f(-0.75f, -0.75f);
    glVertex2f(-0.76f, -0.74f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.4f, 0.26f, 0.28f); // brown
    glVertex2f(-0.93f, -0.7f);    // x, y
    glVertex2f(-0.93f, -0.74f);
    glVertex2f(-0.9f, -0.74f);
    glVertex2f(-0.9f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.4f, 0.26f, 0.28f); // brown
    glVertex2f(-0.87f, -0.7f);    // x, y
    glVertex2f(-0.87f, -0.74f);
    glVertex2f(-0.84f, -0.74f);
    glVertex2f(-0.84f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.4f, 0.26f, 0.28f); // brown
    glVertex2f(-0.81f, -0.7f);    // x, y
    glVertex2f(-0.81f, -0.74f);
    glVertex2f(-0.78f, -0.74f);
    glVertex2f(-0.78f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(-0.95f, -0.81f);    // x, y
    glVertex2f(-0.95f, -0.84f);
    glVertex2f(-0.92f, -0.84f);
    glVertex2f(-0.92f, -0.81f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(-0.89f, -0.81f);    // x, y
    glVertex2f(-0.89f, -0.84f);
    glVertex2f(-0.86f, -0.84f);
    glVertex2f(-0.86f, -0.81f);
    glEnd();


    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(-0.83f, -0.81f);    // x, y
    glVertex2f(-0.83f, -0.84f);
    glVertex2f(-0.8f, -0.84f);
    glVertex2f(-0.8f, -0.81f);
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // white
    glVertex2f(-0.77f, -0.81f);    // x, y
    glVertex2f(-0.77f, -0.84f);
    glVertex2f(-0.74f, -0.84f);
    glVertex2f(-0.74f, -0.81f);
    glEnd();

    GLfloat sp1=-0.9f; GLfloat sq1= -0.9f; GLfloat sr1 = 0.01f;     //Circle
    int stringle1=80;

    GLfloat stp1 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.28f, 0.11f, 0.69f);  //sea blue
    glVertex2f (sp1,sq1);
    for(i= 0;i<=stringle1; i++)
    {
        glVertex2f (
                    sp1+(sr1*cos(i*stp1/stringle1)),
                    sq1+(sr1*sin(i*stp1/stringle1))
                    );
    }
    glEnd ();

    GLfloat sp2=-0.85f; GLfloat sq2= -0.9f; GLfloat sr2 = 0.01f;     //Circle
    int stringle2=80;

    GLfloat stp2 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.28f, 0.11f, 0.69f);  //sea blue
    glVertex2f (sp2,sq2);
    for(i= 0;i<=stringle2; i++)
    {
        glVertex2f (
                    sp2+(sr2*cos(i*stp2/stringle2)),
                    sq2+(sr2*sin(i*stp2/stringle2))
                    );
    }
    glEnd ();

    GLfloat sp3=-0.8f; GLfloat sq3= -0.9f; GLfloat sr3 = 0.01f;     //Circle
    int stringle3=80;

    GLfloat stp3 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(0.28f, 0.11f, 0.69f);  //sea blue
    glVertex2f (sp3,sq3);
    for(i= 0;i<=stringle3; i++)
    {
        glVertex2f (
                    sp3+(sr3*cos(i*stp3/stringle3)),
                    sq3+(sr3*sin(i*stp3/stringle3))
                    );
    }
    glEnd ();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, positionBoat, 0.0f);
    glScalef(scaleb, scaleb, 0.0f);

    glBegin(GL_QUADS);      //base right
    glColor3f(0.05f, 0.16f, 0.28f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, -0.82f);
    glVertex2f(0.12f, -0.86f);
    glVertex2f(0.10f, -1.0f);
    glEnd();
    glLineWidth(3); //middle line
	glBegin(GL_LINES);
	glColor3f(0.46f, 0.59f, 0.75f);
	glVertex2f(0.0f, -0.82f);
	glVertex2f(0.0f, -1.0f);
	glEnd();
    glBegin(GL_QUADS);      //Base left
    glColor3f(0.05f, 0.16f, 0.28f);
    glVertex2f(-0.0f, -1.0f);
    glVertex2f(-0.0f, -0.82f);
    glVertex2f(-0.12f, -0.86f);
    glVertex2f(-0.10f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);      //ship 2 right
    glColor3f(0.55f, 0.64f, 0.74f);
    glVertex2f(0.0f, -0.84f);
    glVertex2f(0.0f, -0.82f);
    glVertex2f(0.10f, -0.84f);
    glVertex2f(0.12f, -0.86f);
    glEnd();
    glBegin(GL_QUADS);      //ship 2 left
    glColor3f(0.55f, 0.64f, 0.74f);
    glVertex2f(-0.0f, -0.84f);
    glVertex2f(-0.0f, -0.82f);
    glVertex2f(-0.10f, -0.84f);
    glVertex2f(-0.12f, -0.86f);
    glEnd();

    glBegin(GL_QUADS);      //ship 3 right
    glColor3f(0.8f, 0.86f, 0.94f);
    glVertex2f(0.0f, -0.76f);
    glVertex2f(0.0f, -0.82f);
    glVertex2f(0.08f, -0.84f);
    glVertex2f(0.09f, -0.76f);
    glEnd();
    glBegin(GL_QUADS);      //ship 3 left
    glColor3f(0.8f, 0.86f, 0.94f);
    glVertex2f(-0.0f, -0.76f);
    glVertex2f(-0.0f, -0.82f);
    glVertex2f(-0.08f, -0.84f);
    glVertex2f(-0.09f, -0.76f);
    glEnd();

    glBegin(GL_QUADS);      //last blue
    glColor3f(0.18f, 0.32f, 0.48f);
    glVertex2f(-0.08f, -0.76f);
    glVertex2f(-0.12f, -0.84f);
    glVertex2f(0.08f, -0.76f);
    glVertex2f(0.12f, -0.84f);
    glEnd();

    glLineWidth(.5);  //line right
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, -0.40f);
	glVertex2f(-0.08f, -0.76f);
	glEnd();
    glLineWidth(2);  //line middle
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, -0.76f);
	glVertex2f(0.0f, -0.40f);
	glEnd();
    glLineWidth(.5);  //line lrft
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, -0.40f);
	glVertex2f(0.08f, -0.76f);
	glEnd();

    glBegin(GL_QUADS);      //last pal 1
    glColor3f(0.8f, 0.84f, 0.89f);
    glVertex2f(-0.025f, -0.44f);
    glVertex2f(0.025f, -0.44f);
    glVertex2f(0.06f, -0.48f);
    glVertex2f(-0.06f, -0.48f);
    glEnd();

    glBegin(GL_QUADS);      //last pal 2
    glColor3f(0.8f, 0.84f, 0.89f);
    glVertex2f(-0.08f, -0.50f);
    glVertex2f(0.08f, -0.50f);
    glVertex2f(0.14f, -0.58f);
    glVertex2f(-0.14f, -0.58f);
    glEnd();

    glBegin(GL_QUADS);      //last pal 3
    glColor3f(0.8f, 0.84f, 0.89f);
    glVertex2f(-0.135f, -0.6f);
    glVertex2f(0.135f, -0.6f);
    glVertex2f(0.22f, -0.7f);
    glVertex2f(-0.22f, -0.7f);
    glEnd();
    glPopMatrix();

    //rain

 glLineWidth(1.5);


 if (rain){

        glPushMatrix();
        glTranslatef(_rain1x,_rain1y,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();

        //rain 2

        glPushMatrix();
        glTranslatef(_rain2x,_rain2y,0);

        glPushMatrix();
        glTranslatef(-.02,-.2,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();
        glEnd();


        glPushMatrix();
        glTranslatef(_rain3x,_rain3y,0);

        glPushMatrix();
        glTranslatef(-.0,-.4,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();

        //rain 4 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        glPushMatrix();
        glTranslatef(_rain4x,_rain4y,0);

        glPushMatrix();
        glTranslatef(-.03,-.6,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();

        //rain 5 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        glPushMatrix();
        glTranslatef(_rain5x,_rain5y,0);

        glPushMatrix();
        glTranslatef(-.03,-.8,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();

         //rain 6 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        glPushMatrix();
        glTranslatef(_rain6x,_rain6y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();

//rain 7 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        glPushMatrix();
        glTranslatef(_rain7x,_rain7y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.2,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();

       //rain 8 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain8x,_rain8y,0);

        glPushMatrix();
        glTranslatef(-.0,-1.4,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();

        //rain 9 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain9x,_rain9y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.6,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();

        //rain 10 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain10x,_rain10y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.8,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(0.43f, 0.44f, 0.44f);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();
    }

    if(snowfall)
    {
        glPushMatrix();
    glTranslatef(0.0f, positionSnow1, 0.0f);

    GLfloat p1=-0.95f; GLfloat q1= 0.95f; GLfloat r1 = 0.0095f;     //Circle
    int tringle1=10;

    GLfloat tp1 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle1; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp1/tringle1)),
                    q1+(r1*sin(i*tp1/tringle1))
                    );
    }
    glEnd ();

    GLfloat p2=-0.8f; GLfloat q2= 0.95f; GLfloat r2 = 0.0095f;     //Circle
    int tringle2=10;

    GLfloat tp2 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p2,q2);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp2/tringle2)),
                    q2+(r2*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    GLfloat p3=-0.65f; GLfloat q3= 0.95f; GLfloat r3 = 0.0095f;     //Circle
    int tringle3=10;

    GLfloat tp3 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p3,q3);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp3/tringle3)),
                    q3+(r3*sin(i*tp3/tringle3))
                    );
    }
    glEnd ();

    GLfloat p4=-0.5f; GLfloat q4= 0.95f; GLfloat r4= 0.0095f;     //Circle
    int tringle4=10;

    GLfloat tp4 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p4,q4);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p4+(r4*cos(i*tp4/tringle4)),
                    q4+(r4*sin(i*tp4/tringle4))
                    );
    }
    glEnd ();

    GLfloat p5=-0.35f; GLfloat q5= 0.95f; GLfloat r5= 0.0095f;     //Circle
    int tringle5=10;

    GLfloat tp5 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p5,q5);
    for(i= 0;i<=tringle5; i++)
    {
        glVertex2f (
                    p5+(r5*cos(i*tp5/tringle5)),
                    q5+(r5*sin(i*tp5/tringle5))
                    );
    }
    glEnd ();

    GLfloat p6=-0.2f; GLfloat q6= 0.95f; GLfloat r6= 0.0095f;     //Circle
    int tringle6=10;

    GLfloat tp6 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p6,q6);
    for(i= 0;i<=tringle6; i++)
    {
        glVertex2f (
                    p6+(r6*cos(i*tp6/tringle6)),
                    q6+(r6*sin(i*tp6/tringle6))
                    );
    }
    glEnd ();

    GLfloat p7=-0.05f; GLfloat q7= 0.95f; GLfloat r7= 0.0095f;     //Circle
    int tringle7=10;

    GLfloat tp7 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p7,q7);
    for(i= 0;i<=tringle7; i++)
    {
        glVertex2f (
                    p7+(r7*cos(i*tp7/tringle7)),
                    q7+(r7*sin(i*tp7/tringle7))
                    );
    }
    glEnd ();

    GLfloat p8=0.1f; GLfloat q8= 0.95f; GLfloat r8= 0.0095f;     //Circle
    int tringle8=10;

    GLfloat tp8 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p8,q8);
    for(i= 0;i<=tringle8; i++)
    {
        glVertex2f (
                    p8+(r8*cos(i*tp8/tringle8)),
                    q8+(r8*sin(i*tp8/tringle8))
                    );
    }
    glEnd ();

    GLfloat p9=0.25f; GLfloat q9= 0.95f; GLfloat r9= 0.0095f;     //Circle
    int tringle9=10;

    GLfloat tp9 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p9,q9);
    for(i= 0;i<=tringle9; i++)
    {
        glVertex2f (
                    p9+(r9*cos(i*tp9/tringle9)),
                    q9+(r9*sin(i*tp9/tringle9))
                    );
    }
    glEnd ();

    GLfloat p10=0.4f; GLfloat q10= 0.95f; GLfloat r10= 0.0095f;     //Circle
    int tringle10=10;

    GLfloat tp10 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p10,q10);
    for(i= 0;i<=tringle10; i++)
    {
        glVertex2f (
                    p10+(r10*cos(i*tp10/tringle10)),
                    q10+(r10*sin(i*tp10/tringle10))
                    );
    }
    glEnd ();

    GLfloat p11=0.55f; GLfloat q11= 0.95f; GLfloat r11= 0.0095f;     //Circle
    int tringle11=10;

    GLfloat tp11=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p11,q11);
    for(i= 0;i<=tringle11; i++)
    {
        glVertex2f (
                    p11+(r11*cos(i*tp11/tringle11)),
                    q11+(r11*sin(i*tp11/tringle11))
                    );
    }
    glEnd ();

    GLfloat p12=0.7f; GLfloat q12= 0.95f; GLfloat r12= 0.0095f;     //Circle
    int tringle12=10;

    GLfloat tp12=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p12,q12);
    for(i= 0;i<=tringle12; i++)
    {
        glVertex2f (
                    p12+(r12*cos(i*tp12/tringle12)),
                    q12+(r12*sin(i*tp12/tringle12))
                    );
    }
    glEnd ();

    GLfloat p13=0.85f; GLfloat q13= 0.95f; GLfloat r13= 0.0095f;     //Circle
    int tringle13=10;

    GLfloat tp13=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p13,q13);
    for(i= 0;i<=tringle13; i++)
    {
        glVertex2f (
                    p13+(r13*cos(i*tp13/tringle13)),
                    q13+(r13*sin(i*tp13/tringle13))
                    );
    }
    glEnd ();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, positionSnow2, 0.0f);

//2nd line
    GLfloat p14=-0.875f; GLfloat q14= 0.7f; GLfloat r14= 0.0095f;     //Circle
    int tringle14=10;

    GLfloat tp14=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p14,q14);
    for(i= 0;i<=tringle14; i++)
    {
        glVertex2f (
                    p14+(r14*cos(i*tp14/tringle14)),
                    q14+(r14*sin(i*tp14/tringle14))
                    );
    }
    glEnd ();

    GLfloat p15=-0.725f; GLfloat q15= 0.7f; GLfloat r15= 0.0095f;     //Circle
    int tringle15=10;

    GLfloat tp15=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p15,q15);
    for(i= 0;i<=tringle15; i++)
    {
        glVertex2f (
                    p15+(r15*cos(i*tp15/tringle15)),
                    q15+(r15*sin(i*tp15/tringle15))
                    );
    }
    glEnd ();

    GLfloat p16=-0.575f; GLfloat q16= 0.7f; GLfloat r16= 0.0095f;     //Circle
    int tringle16=10;

    GLfloat tp16=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p16,q16);
    for(i= 0;i<=tringle16; i++)
    {
        glVertex2f (
                    p16+(r16*cos(i*tp16/tringle16)),
                    q16+(r16*sin(i*tp16/tringle16))
                    );
    }
    glEnd ();

    GLfloat p17=-0.425f; GLfloat q17= 0.7f; GLfloat r17= 0.0095f;     //Circle
    int tringle17=10;

    GLfloat tp17=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p17,q17);
    for(i= 0;i<=tringle17; i++)
    {
        glVertex2f (
                    p17+(r17*cos(i*tp17/tringle17)),
                    q17+(r17*sin(i*tp17/tringle17))
                    );
    }
    glEnd ();

    GLfloat p18=-0.275f; GLfloat q18= 0.7f; GLfloat r18= 0.0095f;     //Circle
    int tringle18=10;

    GLfloat tp18=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p18,q18);
    for(i= 0;i<=tringle18; i++)
    {
        glVertex2f (
                    p18+(r18*cos(i*tp18/tringle18)),
                    q18+(r18*sin(i*tp18/tringle18))
                    );
    }
    glEnd ();

    GLfloat p19=-0.125f; GLfloat q19= 0.7f; GLfloat r19= 0.0095f;     //Circle
    int tringle19=10;

    GLfloat tp19=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p19,q19);
    for(i= 0;i<=tringle18; i++)
    {
        glVertex2f (
                    p19+(r19*cos(i*tp19/tringle19)),
                    q19+(r19*sin(i*tp19/tringle19))
                    );
    }
    glEnd ();

    GLfloat p20=0.025f; GLfloat q20= 0.7f; GLfloat r20= 0.0095f;     //Circle
    int tringle20=10;

    GLfloat tp20=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p20,q20);
    for(i= 0;i<=tringle20; i++)
    {
        glVertex2f (
                    p20+(r20*cos(i*tp20/tringle20)),
                    q20+(r20*sin(i*tp20/tringle20))
                    );
    }
    glEnd ();

    GLfloat p21=0.175f; GLfloat q21= 0.7f; GLfloat r21= 0.0095f;     //Circle
    int tringle21=10;

    GLfloat tp21=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p21,q21);
    for(i= 0;i<=tringle21; i++)
    {
        glVertex2f (
                    p21+(r21*cos(i*tp21/tringle21)),
                    q21+(r21*sin(i*tp21/tringle21))
                    );
    }
    glEnd ();

    GLfloat p22=0.325f; GLfloat q22= 0.7f; GLfloat r22= 0.0095f;     //Circle
    int tringle22=10;

    GLfloat tp22=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p22,q22);
    for(i= 0;i<=tringle22; i++)
    {
        glVertex2f (
                    p22+(r22*cos(i*tp22/tringle22)),
                    q22+(r22*sin(i*tp22/tringle22))
                    );
    }
    glEnd ();

    GLfloat p23=0.475f; GLfloat q23= 0.7f; GLfloat r23= 0.0095f;     //Circle
    int tringle23=10;

    GLfloat tp23=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p23,q23);
    for(i= 0;i<=tringle23; i++)
    {
        glVertex2f (
                    p23+(r23*cos(i*tp23/tringle23)),
                    q23+(r23*sin(i*tp23/tringle23))
                    );
    }
    glEnd ();

    GLfloat p24=0.625f; GLfloat q24= 0.7f; GLfloat r24= 0.0095f;     //Circle
    int tringle24=10;

    GLfloat tp24=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p24,q24);
    for(i= 0;i<=tringle24; i++)
    {
        glVertex2f (
                    p24+(r24*cos(i*tp24/tringle24)),
                    q24+(r24*sin(i*tp24/tringle24))
                    );
    }
    glEnd ();

    GLfloat p25=0.775f; GLfloat q25= 0.7f; GLfloat r25= 0.0095f;     //Circle
    int tringle25=10;

    GLfloat tp25=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p25,q25);
    for(i= 0;i<=tringle25; i++)
    {
        glVertex2f (
                    p25+(r25*cos(i*tp25/tringle25)),
                    q25+(r25*sin(i*tp25/tringle25))
                    );
    }
    glEnd ();

    GLfloat p26=0.925f; GLfloat q26= 0.7f; GLfloat r26= 0.0095f;     //Circle
    int tringle26=10;

    GLfloat tp26=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p26,q26);
    for(i= 0;i<=tringle26; i++)
    {
        glVertex2f (
                    p26+(r26*cos(i*tp26/tringle26)),
                    q26+(r26*sin(i*tp26/tringle26))
                    );
    }
    glEnd ();

    glPopMatrix();

//3rd line

    glPushMatrix();
    glTranslatef(0.0f, positionSnow3, 0.0f);

 GLfloat p27=-0.95f; GLfloat q27= 0.5f; GLfloat r27 = 0.0095f;     //Circle
    int tringle27=10;

    GLfloat tp27 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p27,q27);
    for(i= 0;i<=tringle27; i++)
    {
        glVertex2f (
                    p27+(r27*cos(i*tp27/tringle27)),
                    q27+(r27*sin(i*tp27/tringle27))
                    );
    }
    glEnd ();

    GLfloat p28=-0.8f; GLfloat q28= 0.5f; GLfloat r28 = 0.0095f;     //Circle
    int tringle28=10;

    GLfloat tp28 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p28,q28);
    for(i= 0;i<=tringle28; i++)
    {
        glVertex2f (
                    p28+(r28*cos(i*tp28/tringle28)),
                    q28+(r28*sin(i*tp28/tringle28))
                    );
    }
    glEnd ();

    GLfloat p29=-0.65f; GLfloat q29= 0.5f; GLfloat r29= 0.0095f;     //Circle
    int tringle29=10;

    GLfloat tp29 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p29,q29);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p29+(r29*cos(i*tp29/tringle29)),
                    q29+(r29*sin(i*tp29/tringle29))
                    );
    }
    glEnd ();

    GLfloat p30=-0.5f; GLfloat q30= 0.5f; GLfloat r30= 0.0095f;     //Circle
    int tringle30=10;

    GLfloat tp30 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p30,q30);
    for(i= 0;i<=tringle30; i++)
    {
        glVertex2f (
                    p30+(r30*cos(i*tp30/tringle30)),
                    q30+(r30*sin(i*tp30/tringle30))
                    );
    }
    glEnd ();

    GLfloat p31=-0.35f; GLfloat q31= 0.5f; GLfloat r31= 0.0095f;     //Circle
    int tringle31=10;

    GLfloat tp31 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p31,q31);
    for(i= 0;i<=tringle31; i++)
    {
        glVertex2f (
                    p31+(r31*cos(i*tp31/tringle31)),
                    q31+(r31*sin(i*tp31/tringle31))
                    );
    }
    glEnd ();

    GLfloat p32=-0.2f; GLfloat q32= 0.5f; GLfloat r32= 0.0095f;     //Circle
    int tringle32=10;

    GLfloat tp32 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p32,q32);
    for(i= 0;i<=tringle32; i++)
    {
        glVertex2f (
                    p32+(r32*cos(i*tp32/tringle32)),
                    q32+(r32*sin(i*tp32/tringle32))
                    );
    }
    glEnd ();

    GLfloat p33=-0.05f; GLfloat q33= 0.5f; GLfloat r33= 0.0095f;     //Circle
    int tringle33=10;

    GLfloat tp33 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p33,q33);
    for(i= 0;i<=tringle33; i++)
    {
        glVertex2f (
                    p33+(r33*cos(i*tp33/tringle33)),
                    q33+(r33*sin(i*tp33/tringle33))
                    );
    }
    glEnd ();

    GLfloat p34=0.1f; GLfloat q34= 0.5f; GLfloat r34= 0.0095f;     //Circle
    int tringle34=10;

    GLfloat tp34 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p34,q34);
    for(i= 0;i<=tringle34; i++)
    {
        glVertex2f (
                    p34+(r34*cos(i*tp34/tringle34)),
                    q34+(r34*sin(i*tp34/tringle34))
                    );
    }
    glEnd ();

    GLfloat p35=0.25f; GLfloat q35= 0.5f; GLfloat r35= 0.0095f;     //Circle
    int tringle35=10;

    GLfloat tp35 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p35,q35);
    for(i= 0;i<=tringle35; i++)
    {
        glVertex2f (
                    p35+(r35*cos(i*tp35/tringle35)),
                    q35+(r35*sin(i*tp35/tringle35))
                    );
    }
    glEnd ();

    GLfloat p36=0.4f; GLfloat q36= 0.5f; GLfloat r36= 0.0095f;     //Circle
    int tringle36=10;

    GLfloat tp36 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p36,q36);
    for(i= 0;i<=tringle36; i++)
    {
        glVertex2f (
                    p36+(r36*cos(i*tp36/tringle36)),
                    q36+(r36*sin(i*tp36/tringle36))
                    );
    }
    glEnd ();

    GLfloat p37=0.55f; GLfloat q37= 0.5f; GLfloat r37= 0.0095f;     //Circle
    int tringle37=10;

    GLfloat tp37=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p37,q37);
    for(i= 0;i<=tringle37; i++)
    {
        glVertex2f (
                    p37+(r37*cos(i*tp37/tringle37)),
                    q37+(r37*sin(i*tp37/tringle37))
                    );
    }
    glEnd ();

    GLfloat p38=0.7f; GLfloat q38= 0.5f; GLfloat r38= 0.0095f;     //Circle
    int tringle38=10;

    GLfloat tp38=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p38,q38);
    for(i= 0;i<=tringle38; i++)
    {
        glVertex2f (
                    p38+(r38*cos(i*tp38/tringle38)),
                    q38+(r38*sin(i*tp38/tringle38))
                    );
    }
    glEnd ();

    GLfloat p39=0.85f; GLfloat q39= 0.5f; GLfloat r39= 0.0095f;     //Circle
    int tringle39=10;

    GLfloat tp39=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p39,q39);
    for(i= 0;i<=tringle39; i++)
    {
        glVertex2f (
                    p39+(r39*cos(i*tp39/tringle39)),
                    q39+(r39*sin(i*tp39/tringle39))
                    );
    }
    glEnd ();

//4th line
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, positionSnow4, 0.0f);

    GLfloat p40=-0.875f; GLfloat q40= 0.3f; GLfloat r40= 0.0095f;     //Circle
    int tringle40=10;

    GLfloat tp40=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p40,q40);
    for(i= 0;i<=tringle40; i++)
    {
        glVertex2f (
                    p40+(r40*cos(i*tp40/tringle40)),
                    q40+(r40*sin(i*tp40/tringle40))
                    );
    }
    glEnd ();

    GLfloat p41=-0.725f; GLfloat q41= 0.3f; GLfloat r41= 0.0095f;     //Circle
    int tringle41=10;

    GLfloat tp41=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p41,q41);
    for(i= 0;i<=tringle41; i++)
    {
        glVertex2f (
                    p41+(r41*cos(i*tp41/tringle41)),
                    q41+(r41*sin(i*tp41/tringle41))
                    );
    }
    glEnd ();

    GLfloat p42=-0.575f; GLfloat q42= 0.3f; GLfloat r42= 0.0095f;     //Circle
    int tringle42=10;

    GLfloat tp42=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p42,q42);
    for(i= 0;i<=tringle42; i++)
    {
        glVertex2f (
                    p42+(r42*cos(i*tp42/tringle42)),
                    q42+(r42*sin(i*tp42/tringle42))
                    );
    }
    glEnd ();

    GLfloat p43=-0.425f; GLfloat q43= 0.3f; GLfloat r43= 0.0095f;     //Circle
    int tringle43=10;

    GLfloat tp43=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p43,q43);
    for(i= 0;i<=tringle43; i++)
    {
        glVertex2f (
                    p43+(r43*cos(i*tp43/tringle43)),
                    q43+(r43*sin(i*tp43/tringle43))
                    );
    }
    glEnd ();

    GLfloat p44=-0.275f; GLfloat q44= 0.3f; GLfloat r44= 0.0095f;     //Circle
    int tringle44=10;

    GLfloat tp44=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p44,q44);
    for(i= 0;i<=tringle44; i++)
    {
        glVertex2f (
                    p44+(r44*cos(i*tp44/tringle44)),
                    q44+(r44*sin(i*tp44/tringle44))
                    );
    }
    glEnd ();

    GLfloat p45=-0.125f; GLfloat q45= 0.3f; GLfloat r45= 0.0095f;     //Circle
    int tringle45=10;

    GLfloat tp45=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p45,q45);
    for(i= 0;i<=tringle45; i++)
    {
        glVertex2f (
                    p45+(r45*cos(i*tp45/tringle45)),
                    q45+(r45*sin(i*tp45/tringle45))
                    );
    }
    glEnd ();

    GLfloat p46=0.025f; GLfloat q46= 0.3f; GLfloat r46= 0.0095f;     //Circle
    int tringle46=10;

    GLfloat tp46=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p46,q46);
    for(i= 0;i<=tringle46; i++)
    {
        glVertex2f (
                    p46+(r46*cos(i*tp46/tringle46)),
                    q46+(r46*sin(i*tp46/tringle46))
                    );
    }
    glEnd ();

    GLfloat p47=0.175f; GLfloat q47= 0.3f; GLfloat r47= 0.0095f;     //Circle
    int tringle47=10;

    GLfloat tp47=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p47,q47);
    for(i= 0;i<=tringle47; i++)
    {
        glVertex2f (
                    p47+(r47*cos(i*tp47/tringle47)),
                    q47+(r47*sin(i*tp47/tringle47))
                    );
    }
    glEnd ();

    GLfloat p48=0.325f; GLfloat q48= 0.3f; GLfloat r48= 0.0095f;     //Circle
    int tringle48=10;

    GLfloat tp48=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p48,q48);
    for(i= 0;i<=tringle48; i++)
    {
        glVertex2f (
                    p48+(r48*cos(i*tp48/tringle48)),
                    q48+(r48*sin(i*tp48/tringle48))
                    );
    }
    glEnd ();

    GLfloat p49=0.475f; GLfloat q49= 0.3f; GLfloat r49= 0.0095f;     //Circle
    int tringle49=10;

    GLfloat tp49=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p49,q49);
    for(i= 0;i<=tringle49; i++)
    {
        glVertex2f (
                    p49+(r49*cos(i*tp49/tringle49)),
                    q49+(r49*sin(i*tp49/tringle49))
                    );
    }
    glEnd ();

    GLfloat p50=0.625f; GLfloat q50= 0.3f; GLfloat r50= 0.0095f;     //Circle
    int tringle50=10;

    GLfloat tp50=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p50,q50);
    for(i= 0;i<=tringle50; i++)
    {
        glVertex2f (
                    p50+(r50*cos(i*tp50/tringle50)),
                    q50+(r50*sin(i*tp50/tringle50))
                    );
    }
    glEnd ();

    GLfloat p51=0.775f; GLfloat q51= 0.3f; GLfloat r51= 0.0095f;     //Circle
    int tringle51=10;

    GLfloat tp51=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p51,q51);
    for(i= 0;i<=tringle51; i++)
    {
        glVertex2f (
                    p51+(r51*cos(i*tp51/tringle51)),
                    q51+(r51*sin(i*tp51/tringle51))
                    );
    }
    glEnd ();

    GLfloat p52=0.925f; GLfloat q52= 0.3f; GLfloat r52= 0.0095f;     //Circle
    int tringle52=10;

    GLfloat tp52=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p52,q52);
    for(i= 0;i<=tringle52; i++)
    {
        glVertex2f (
                    p52+(r52*cos(i*tp52/tringle52)),
                    q52+(r52*sin(i*tp52/tringle52))
                    );
    }
    glEnd ();


//5th line

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, positionSnow5, 0.0f);

    GLfloat p53=-0.95f; GLfloat q53= 0.1f; GLfloat r53 = 0.0095f;     //Circle
    int tringle53=10;

    GLfloat tp53 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p53,q53);
    for(i= 0;i<=tringle53; i++)
    {
        glVertex2f (
                    p53+(r53*cos(i*tp53/tringle53)),
                    q53+(r53*sin(i*tp53/tringle53))
                    );
    }
    glEnd ();

    GLfloat p54=-0.8f; GLfloat q54= 0.1f; GLfloat r54 = 0.0095f;     //Circle
    int tringle54=10;

    GLfloat tp54 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p54,q54);
    for(i= 0;i<=tringle54; i++)
    {
        glVertex2f (
                    p54+(r54*cos(i*tp54/tringle54)),
                    q54+(r54*sin(i*tp54/tringle54))
                    );
    }
    glEnd ();

    GLfloat p55=-0.65f; GLfloat q55= 0.1f; GLfloat r55 = 0.0095f;     //Circle
    int tringle55=10;

    GLfloat tp55 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p55,q55);
    for(i= 0;i<=tringle55; i++)
    {
        glVertex2f (
                    p55+(r55*cos(i*tp55/tringle55)),
                    q55+(r55*sin(i*tp55/tringle55))
                    );
    }
    glEnd ();

    GLfloat p56=-0.5f; GLfloat q56= 0.1f; GLfloat r56= 0.0095f;     //Circle
    int tringle56=10;

    GLfloat tp56 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p56,q56);
    for(i= 0;i<=tringle56; i++)
    {
        glVertex2f (
                    p56+(r56*cos(i*tp56/tringle56)),
                    q56+(r56*sin(i*tp56/tringle56))
                    );
    }
    glEnd ();

    GLfloat p57=-0.35f; GLfloat q57= 0.1f; GLfloat r57= 0.0095f;     //Circle
    int tringle57=10;

    GLfloat tp57 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p57,q57);
    for(i= 0;i<=tringle5; i++)
    {
        glVertex2f (
                    p57+(r57*cos(i*tp57/tringle57)),
                    q57+(r57*sin(i*tp57/tringle57))
                    );
    }
    glEnd ();

    GLfloat p58=-0.2f; GLfloat q58= 0.1f; GLfloat r58= 0.0095f;     //Circle
    int tringle58=10;

    GLfloat tp58 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p58,q58);
    for(i= 0;i<=tringle58; i++)
    {
        glVertex2f (
                    p58+(r58*cos(i*tp58/tringle58)),
                    q58+(r58*sin(i*tp58/tringle58))
                    );
    }
    glEnd ();

    GLfloat p59=-0.05f; GLfloat q59= 0.1f; GLfloat r59= 0.0095f;     //Circle
    int tringle59=10;

    GLfloat tp59 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p59,q59);
    for(i= 0;i<=tringle7; i++)
    {
        glVertex2f (
                    p59+(r59*cos(i*tp59/tringle59)),
                    q59+(r59*sin(i*tp59/tringle59))
                    );
    }
    glEnd ();

    GLfloat p60=0.1f; GLfloat q60= 0.1f; GLfloat r60= 0.0095f;     //Circle
    int tringle60=10;

    GLfloat tp60 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p60,q60);
    for(i= 0;i<=tringle60; i++)
    {
        glVertex2f (
                    p60+(r60*cos(i*tp60/tringle60)),
                    q60+(r60*sin(i*tp60/tringle60))
                    );
    }
    glEnd ();

    GLfloat p61=0.25f; GLfloat q61= 0.1f; GLfloat r61= 0.0095f;     //Circle
    int tringle61=10;

    GLfloat tp61 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p61,q61);
    for(i= 0;i<=tringle61; i++)
    {
        glVertex2f (
                    p61+(r61*cos(i*tp61/tringle61)),
                    q61+(r61*sin(i*tp61/tringle61))
                    );
    }
    glEnd ();

    GLfloat p62=0.4f; GLfloat q62= 0.1f; GLfloat r62= 0.0095f;     //Circle
    int tringle62=10;

    GLfloat tp62 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p62,q62);
    for(i= 0;i<=tringle62; i++)
    {
        glVertex2f (
                    p62+(r62*cos(i*tp62/tringle62)),
                    q62+(r62*sin(i*tp62/tringle62))
                    );
    }
    glEnd ();

    GLfloat p63=0.55f; GLfloat q63= 0.1f; GLfloat r63= 0.0095f;     //Circle
    int tringle63=10;

    GLfloat tp63=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p63,q63);
    for(i= 0;i<=tringle63; i++)
    {
        glVertex2f (
                    p63+(r63*cos(i*tp63/tringle63)),
                    q63+(r63*sin(i*tp63/tringle63))
                    );
    }
    glEnd ();

    GLfloat p64=0.7f; GLfloat q64= 0.1f; GLfloat r64= 0.0095f;     //Circle
    int tringle64=10;

    GLfloat tp64=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p64,q64);
    for(i= 0;i<=tringle64; i++)
    {
        glVertex2f (
                    p64+(r64*cos(i*tp64/tringle64)),
                    q64+(r64*sin(i*tp64/tringle64))
                    );
    }
    glEnd ();

    GLfloat p65=0.85f; GLfloat q65= 0.1f; GLfloat r65= 0.0095f;     //Circle
    int tringle65=10;

    GLfloat tp65=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p65,q65);
    for(i= 0;i<=tringle65; i++)
    {
        glVertex2f (
                    p65+(r65*cos(i*tp65/tringle65)),
                    q65+(r65*sin(i*tp65/tringle65))
                    );
    }
    glEnd ();

//6th line

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, positionSnow6, 0.0f);

    GLfloat p67=-0.875f; GLfloat q67= -0.1f; GLfloat r67= 0.0095f;     //Circle
    int tringle67=10;

    GLfloat tp67=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p67,q67);
    for(i= 0;i<=tringle67; i++)
    {
        glVertex2f (
                    p67+(r67*cos(i*tp67/tringle67)),
                    q67+(r67*sin(i*tp67/tringle67))
                    );
    }
    glEnd ();

    GLfloat p68=-0.725f; GLfloat q68= -0.1f; GLfloat r68= 0.0095f;     //Circle
    int tringle68=10;

    GLfloat tp68=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p68,q68);
    for(i= 0;i<=tringle68; i++)
    {
        glVertex2f (
                    p68+(r68*cos(i*tp68/tringle68)),
                    q68+(r68*sin(i*tp68/tringle68))
                    );
    }
    glEnd ();

    GLfloat p69=-0.575f; GLfloat q69= -0.1f; GLfloat r69= 0.0095f;     //Circle
    int tringle69=10;

    GLfloat tp69=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p69,q69);
    for(i= 0;i<=tringle69; i++)
    {
        glVertex2f (
                    p69+(r69*cos(i*tp69/tringle69)),
                    q69+(r69*sin(i*tp69/tringle69))
                    );
    }
    glEnd ();

    GLfloat p70=-0.425f; GLfloat q70= -0.1f; GLfloat r70= 0.0095f;     //Circle
    int tringle70=10;

    GLfloat tp70=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p70,q70);
    for(i= 0;i<=tringle70; i++)
    {
        glVertex2f (
                    p70+(r70*cos(i*tp70/tringle70)),
                    q70+(r70*sin(i*tp70/tringle70))
                    );
    }
    glEnd ();

    GLfloat p71=-0.275f; GLfloat q71= -0.1f; GLfloat r71= 0.0095f;     //Circle
    int tringle71=10;

    GLfloat tp71=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p71,q71);
    for(i= 0;i<=tringle71; i++)
    {
        glVertex2f (
                    p71+(r71*cos(i*tp71/tringle71)),
                    q71+(r71*sin(i*tp71/tringle71))
                    );
    }
    glEnd ();

    GLfloat p72=-0.125f; GLfloat q72= -0.1f; GLfloat r72= 0.0095f;     //Circle
    int tringle72=10;

    GLfloat tp72=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p72,q72);
    for(i= 0;i<=tringle72; i++)
    {
        glVertex2f (
                    p72+(r72*cos(i*tp72/tringle72)),
                    q72+(r72*sin(i*tp72/tringle72))
                    );
    }
    glEnd ();

    GLfloat p73=0.025f; GLfloat q73= -0.1f; GLfloat r73= 0.0095f;     //Circle
    int tringle73=10;

    GLfloat tp73=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p73,q73);
    for(i= 0;i<=tringle73; i++)
    {
        glVertex2f (
                    p73+(r73*cos(i*tp73/tringle73)),
                    q73+(r73*sin(i*tp73/tringle73))
                    );
    }
    glEnd ();

    GLfloat p74=0.175f; GLfloat q74= -0.1f; GLfloat r74= 0.0095f;     //Circle
    int tringle74=10;

    GLfloat tp74=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p74,q74);
    for(i= 0;i<=tringle74; i++)
    {
        glVertex2f (
                    p74+(r74*cos(i*tp74/tringle74)),
                    q74+(r74*sin(i*tp74/tringle74))
                    );
    }
    glEnd ();

    GLfloat p75=0.325f; GLfloat q75= -0.1f; GLfloat r75= 0.0095f;     //Circle
    int tringle75=10;

    GLfloat tp75=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p75,q75);
    for(i= 0;i<=tringle75; i++)
    {
        glVertex2f (
                    p75+(r75*cos(i*tp75/tringle75)),
                    q75+(r75*sin(i*tp75/tringle75))
                    );
    }
    glEnd ();

    GLfloat p76=0.475f; GLfloat q76=-0.1f; GLfloat r76= 0.0095f;     //Circle
    int tringle76=10;

    GLfloat tp76=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p76,q76);
    for(i= 0;i<=tringle76; i++)
    {
        glVertex2f (
                    p76+(r76*cos(i*tp76/tringle76)),
                    q76+(r76*sin(i*tp76/tringle76))
                    );
    }
    glEnd ();

    GLfloat p77=0.625f; GLfloat q77= -0.1f; GLfloat r77= 0.0095f;     //Circle
    int tringle77=10;

    GLfloat tp77=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p77,q77);
    for(i= 0;i<=tringle77; i++)
    {
        glVertex2f (
                    p77+(r77*cos(i*tp77/tringle77)),
                    q77+(r77*sin(i*tp77/tringle77))
                    );
    }
    glEnd ();

    GLfloat p78=0.775f; GLfloat q78= -0.1f; GLfloat r78= 0.0095f;     //Circle
    int tringle78=10;

    GLfloat tp78=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p78,q78);
    for(i= 0;i<=tringle78; i++)
    {
        glVertex2f (
                    p78+(r78*cos(i*tp78/tringle78)),
                    q78+(r78*sin(i*tp78/tringle78))
                    );
    }
    glEnd ();

    GLfloat p79=0.925f; GLfloat q79=-0.1f; GLfloat r79= 0.0095f;     //Circle
    int tringle79=10;

    GLfloat tp79=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p79,q79);
    for(i= 0;i<=tringle79; i++)
    {
        glVertex2f (
                    p79+(r79*cos(i*tp79/tringle79)),
                    q79+(r79*sin(i*tp79/tringle79))
                    );
    }
    glEnd ();

//7th line

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, positionSnow7, 0.0f);

GLfloat p80=-0.95f; GLfloat q80= -0.3f; GLfloat r80 = 0.0095f;     //Circle
    int tringle80=10;

    GLfloat tp80 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p80,q80);
    for(i= 0;i<=tringle80; i++)
    {
        glVertex2f (
                    p80+(r80*cos(i*tp80/tringle80)),
                    q80+(r80*sin(i*tp80/tringle80))
                    );
    }
    glEnd ();

    GLfloat p81=-0.8f; GLfloat q81= -0.3f; GLfloat r81 = 0.0095f;     //Circle
    int tringle81=10;

    GLfloat tp81=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p81,q81);
    for(i= 0;i<=tringle81; i++)
    {
        glVertex2f (
                    p81+(r81*cos(i*tp81/tringle81)),
                    q81+(r81*sin(i*tp81/tringle81))
                    );
    }
    glEnd ();

    GLfloat p82=-0.65f; GLfloat q82= -0.3f; GLfloat r82 = 0.0095f;     //Circle
    int tringle82=10;

    GLfloat tp82 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p82,q82);
    for(i= 0;i<=tringle82; i++)
    {
        glVertex2f (
                    p82+(r82*cos(i*tp82/tringle3)),
                    q82+(r82*sin(i*tp82/tringle3))
                    );
    }
    glEnd ();

    GLfloat p83=-0.5f; GLfloat q83= -0.3f; GLfloat r83= 0.0095f;     //Circle
    int tringle83=10;

    GLfloat tp83 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p83,q83);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p83+(r83*cos(i*tp83/tringle83)),
                    q83+(r83*sin(i*tp83/tringle83))
                    );
    }
    glEnd ();

    GLfloat p84=-0.35f; GLfloat q84= -0.3f; GLfloat r84= 0.0095f;     //Circle
    int tringle84=10;

    GLfloat tp84 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p84,q84);
    for(i= 0;i<=tringle84; i++)
    {
        glVertex2f (
                    p84+(r84*cos(i*tp84/tringle84)),
                    q84+(r84*sin(i*tp84/tringle84))
                    );
    }
    glEnd ();

    GLfloat p85=-0.2f; GLfloat q85= -0.3f; GLfloat r85= 0.0095f;     //Circle
    int tringle85=10;

    GLfloat tp85 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p85,q85);
    for(i= 0;i<=tringle85; i++)
    {
        glVertex2f (
                    p85+(r85*cos(i*tp85/tringle85)),
                    q85+(r85*sin(i*tp85/tringle85))
                    );
    }
    glEnd ();

    GLfloat p86=-0.05f; GLfloat q86= -0.3f; GLfloat r86= 0.0095f;     //Circle
    int tringle86=10;

    GLfloat tp86=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p86,q86);
    for(i= 0;i<=tringle86; i++)
    {
        glVertex2f (
                    p86+(r86*cos(i*tp86/tringle86)),
                    q86+(r86*sin(i*tp86/tringle86))
                    );
    }
    glEnd ();

    GLfloat p87=0.1f; GLfloat q87= -0.3f; GLfloat r87= 0.0095f;     //Circle
    int tringle87=10;

    GLfloat tp87 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p87,q87);
    for(i= 0;i<=tringle87; i++)
    {
        glVertex2f (
                    p87+(r87*cos(i*tp8/tringle8)),
                    q87+(r87*sin(i*tp8/tringle8))
                    );
    }
    glEnd ();

    GLfloat p88=0.25f; GLfloat q88= -0.3f; GLfloat r88= 0.0095f;     //Circle
    int tringle88=10;

    GLfloat tp88 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p88,q88);
    for(i= 0;i<=tringle88; i++)
    {
        glVertex2f (
                    p88+(r88*cos(i*tp88/tringle88)),
                    q88+(r88*sin(i*tp88/tringle88))
                    );
    }
    glEnd ();

    GLfloat p89=0.4f; GLfloat q89= -0.3f; GLfloat r89= 0.0095f;     //Circle
    int tringle89=10;

    GLfloat tp89 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p89,q89);
    for(i= 0;i<=tringle89; i++)
    {
        glVertex2f (
                    p89+(r89*cos(i*tp89/tringle89)),
                    q89+(r89*sin(i*tp89/tringle89))
                    );
    }
    glEnd ();

    GLfloat p90=0.55f; GLfloat q90= -0.3f; GLfloat r90= 0.0095f;     //Circle
    int tringle90=10;

    GLfloat tp90=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p90,q90);
    for(i= 0;i<=tringle90; i++)
    {
        glVertex2f (
                    p90+(r90*cos(i*tp90/tringle90)),
                    q90+(r90*sin(i*tp90/tringle90))
                    );
    }
    glEnd ();

    GLfloat p91=0.7f; GLfloat q91= -0.3f; GLfloat r91= 0.0095f;     //Circle
    int tringle91=10;

    GLfloat tp91=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p91,q91);
    for(i= 0;i<=tringle91; i++)
    {
        glVertex2f (
                    p91+(r91*cos(i*tp91/tringle91)),
                    q91+(r91*sin(i*tp91/tringle91))
                    );
    }
    glEnd ();

    GLfloat p92=0.85f; GLfloat q92= -0.3f; GLfloat r92= 0.0095f;     //Circle
    int tringle92=10;

    GLfloat tp92=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p92,q92);
    for(i= 0;i<=tringle92; i++)
    {
        glVertex2f (
                    p92+(r92*cos(i*tp92/tringle92)),
                    q92+(r92*sin(i*tp92/tringle92))
                    );
    }
    glEnd ();
//8th line2

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, positionSnow8, 0.0f);

    GLfloat p93=-0.875f; GLfloat q93= -0.5f; GLfloat r93= 0.0095f;     //Circle
    int tringle93=10;

    GLfloat tp93=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p93,q93);
    for(i= 0;i<=tringle93; i++)
    {
        glVertex2f (
                    p93+(r93*cos(i*tp93/tringle93)),
                    q93+(r93*sin(i*tp93/tringle93))
                    );
    }
    glEnd ();

    GLfloat p94=-0.725f; GLfloat q94= -0.5f; GLfloat r94= 0.0095f;     //Circle
    int tringle94=10;

    GLfloat tp94=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p94,q94);
    for(i= 0;i<=tringle94; i++)
    {
        glVertex2f (
                    p94+(r94*cos(i*tp94/tringle94)),
                    q94+(r94*sin(i*tp94/tringle94))
                    );
    }
    glEnd ();

    GLfloat p95=-0.575f; GLfloat q95= -0.5f; GLfloat r95= 0.0095f;     //Circle
    int tringle95=10;

    GLfloat tp95=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p95,q95);
    for(i= 0;i<=tringle95; i++)
    {
        glVertex2f (
                    p95+(r95*cos(i*tp95/tringle95)),
                    q95+(r95*sin(i*tp95/tringle95))
                    );
    }
    glEnd ();

    GLfloat p96=-0.425f; GLfloat q96= -0.5f; GLfloat r96= 0.0095f;     //Circle
    int tringle96=10;

    GLfloat tp96=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p96,q96);
    for(i= 0;i<=tringle96; i++)
    {
        glVertex2f (
                    p96+(r96*cos(i*tp96/tringle96)),
                    q96+(r96*sin(i*tp6/tringle96))
                    );
    }
    glEnd ();

    GLfloat p97=-0.275f; GLfloat q97= -0.5f; GLfloat r97= 0.0095f;     //Circle
    int tringle97=10;

    GLfloat tp97=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p97,q97);
    for(i= 0;i<=tringle97; i++)
    {
        glVertex2f (
                    p97+(r97*cos(i*tp97/tringle97)),
                    q97+(r97*sin(i*tp97/tringle97))
                    );
    }
    glEnd ();

    GLfloat p98=-0.125f; GLfloat q98= -0.5f; GLfloat r98= 0.0095f;     //Circle
    int tringle98=10;

    GLfloat tp98=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p98,q98);
    for(i= 0;i<=tringle98; i++)
    {
        glVertex2f (
                    p98+(r98*cos(i*tp98/tringle98)),
                    q98+(r98*sin(i*tp98/tringle98))
                    );
    }
    glEnd ();

    GLfloat p99=0.025f; GLfloat q99= -0.5f; GLfloat r99= 0.0095f;     //Circle
    int tringle99=10;

    GLfloat tp99=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p99,q99);
    for(i= 0;i<=tringle99; i++)
    {
        glVertex2f (
                    p99+(r99*cos(i*tp99/tringle99)),
                    q99+(r99*sin(i*tp99/tringle99))
                    );
    }
    glEnd ();

    GLfloat p100=0.175f; GLfloat q100= -0.5f; GLfloat r100= 0.0095f;     //Circle
    int tringle100=10;

    GLfloat tp100=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p100,q100);
    for(i= 0;i<=tringle100; i++)
    {
        glVertex2f (
                    p100+(r100*cos(i*tp100/tringle100)),
                    q100+(r100*sin(i*tp100/tringle100))
                    );
    }
    glEnd ();

    GLfloat p101=0.325f; GLfloat q101= -0.5f; GLfloat r101= 0.0095f;     //Circle
    int tringle101=10;

    GLfloat tp101=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p101,q101);
    for(i= 0;i<=tringle101; i++)
    {
        glVertex2f (
                    p101+(r101*cos(i*tp101/tringle101)),
                    q101+(r101*sin(i*tp101/tringle101))
                    );
    }
    glEnd ();

    GLfloat p102=0.475f; GLfloat q102= -0.5f; GLfloat r102= 0.0095f;     //Circle
    int tringle102=10;

    GLfloat tp102=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p102,q102);
    for(i= 0;i<=tringle102; i++)
    {
        glVertex2f (
                    p102+(r102*cos(i*tp102/tringle102)),
                    q102+(r102*sin(i*tp102/tringle102))
                    );
    }
    glEnd ();

    GLfloat p103=0.625f; GLfloat q103= -0.5f; GLfloat r103= 0.0095f;     //Circle
    int tringle103=10;

    GLfloat tp103=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p103,q103);
    for(i= 0;i<=tringle103; i++)
    {
        glVertex2f (
                    p103+(r103*cos(i*tp103/tringle103)),
                    q103+(r103*sin(i*tp103/tringle103))
                    );
    }
    glEnd ();

    GLfloat p104=0.775f; GLfloat q104= -0.5f; GLfloat r104= 0.0095f;     //Circle
    int tringle104=10;

    GLfloat tp104=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p104,q104);
    for(i= 0;i<=tringle104; i++)
    {
        glVertex2f (
                    p104+(r104*cos(i*tp104/tringle104)),
                    q104+(r104*sin(i*tp104/tringle104))
                    );
    }
    glEnd ();

    GLfloat p105=0.925f; GLfloat q105= -0.5f; GLfloat r105= 0.0095f;     //Circle
    int tringle105=10;

    GLfloat tp105=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p105,q105);
    for(i= 0;i<=tringle105; i++)
    {
        glVertex2f (
                    p105+(r105*cos(i*tp105/tringle105)),
                    q105+(r105*sin(i*tp105/tringle105))
                    );
    }
    glEnd ();
//9th line 1

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, positionSnow9, 0.0f);

    GLfloat p106=-0.95f; GLfloat q106= -0.7f; GLfloat r106 = 0.0095f;     //Circle
    int tringle106=10;

    GLfloat tp106 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p106,q106);
    for(i= 0;i<=tringle106; i++)
    {
        glVertex2f (
                    p106+(r106*cos(i*tp106/tringle106)),
                    q106+(r106*sin(i*tp106/tringle106))
                    );
    }
    glEnd ();

    GLfloat p107=-0.8f; GLfloat q107= -0.7f; GLfloat r107 = 0.0095f;     //Circle
    int tringle107=10;

    GLfloat tp107 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p107,q107);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p107+(r107*cos(i*tp107/tringle107)),
                    q107+(r107*sin(i*tp107/tringle107))
                    );
    }
    glEnd ();

    GLfloat p108=-0.65f; GLfloat q108= -0.7f; GLfloat r108 = 0.0095f;     //Circle
    int tringle108=10;

    GLfloat tp108 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p108,q108);
    for(i= 0;i<=tringle108; i++)
    {
        glVertex2f (
                    p108+(r108*cos(i*tp108/tringle108)),
                    q108+(r108*sin(i*tp108/tringle108))
                    );
    }
    glEnd ();

    GLfloat p109=-0.5f; GLfloat q109= -0.7f; GLfloat r109= 0.0095f;     //Circle
    int tringle109=10;

    GLfloat tp109=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p109,q109);
    for(i= 0;i<=tringle109; i++)
    {
        glVertex2f (
                    p109+(r109*cos(i*tp109/tringle109)),
                    q109+(r109*sin(i*tp109/tringle109))
                    );
    }
    glEnd ();

    GLfloat p110=-0.35f; GLfloat q110= -0.7f; GLfloat r110= 0.0095f;     //Circle
    int tringle110=10;

    GLfloat tp110=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p110,q110);
    for(i= 0;i<=tringle110; i++)
    {
        glVertex2f (
                    p110+(r110*cos(i*tp110/tringle110)),
                    q110+(r110*sin(i*tp110/tringle110))
                    );
    }
    glEnd ();

    GLfloat p111=-0.2f; GLfloat q111= -0.7f; GLfloat r111= 0.0095f;     //Circle
    int tringle111=10;

    GLfloat tp111 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p111,q111);
    for(i= 0;i<=tringle111; i++)
    {
        glVertex2f (
                    p111+(r111*cos(i*tp111/tringle111)),
                    q111+(r111*sin(i*tp111/tringle111))
                    );
    }
    glEnd ();

    GLfloat p112=-0.05f; GLfloat q112= -0.7f; GLfloat r112= 0.0095f;     //Circle
    int tringle112=10;

    GLfloat tp112 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p112,q112);
    for(i= 0;i<=tringle112; i++)
    {
        glVertex2f (
                    p112+(r112*cos(i*tp112/tringle112)),
                    q112+(r112*sin(i*tp112/tringle112))
                    );
    }
    glEnd ();

    GLfloat p113=0.1f; GLfloat q113= -0.7; GLfloat r113= 0.0095f;     //Circle
    int tringle113=10;

    GLfloat tp113 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p113,q113);
    for(i= 0;i<=tringle113; i++)
    {
        glVertex2f (
                    p113+(r113*cos(i*tp113/tringle113)),
                    q113+(r113*sin(i*tp113/tringle113))
                    );
    }
    glEnd ();

    GLfloat p114=0.25f; GLfloat q114= -0.7f; GLfloat r114= 0.0095f;     //Circle
    int tringle114=10;

    GLfloat tp114 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p114,q114);
    for(i= 0;i<=tringle114; i++)
    {
        glVertex2f (
                    p114+(r114*cos(i*tp114/tringle114)),
                    q114+(r114*sin(i*tp114/tringle114))
                    );
    }
    glEnd ();

    GLfloat p115=0.4f; GLfloat q115=-0.7f; GLfloat r115= 0.0095f;     //Circle
    int tringle115=10;

    GLfloat tp115 =2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p115,q115);
    for(i= 0;i<=tringle115; i++)
    {
        glVertex2f (
                    p115+(r115*cos(i*tp115/tringle115)),
                    q115+(r115*sin(i*tp115/tringle115))
                    );
    }
    glEnd ();

    GLfloat p116=0.55f; GLfloat q116= -0.7f; GLfloat r116= 0.0095f;     //Circle
    int tringle116=10;

    GLfloat tp116=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p116,q116);
    for(i= 0;i<=tringle116; i++)
    {
        glVertex2f (
                    p116+(r116*cos(i*tp116/tringle116)),
                    q116+(r116*sin(i*tp116/tringle116))
                    );
    }
    glEnd ();

    GLfloat p117=0.7f; GLfloat q117= -0.7f; GLfloat r117= 0.0095f;     //Circle
    int tringle117=10;

    GLfloat tp117=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p117,q117);
    for(i= 0;i<=tringle117; i++)
    {
        glVertex2f (
                    p117+(r117*cos(i*tp117/tringle117)),
                    q117+(r117*sin(i*tp117/tringle117))
                    );
    }
    glEnd ();

    GLfloat p118=0.85f; GLfloat q118=-0.7f; GLfloat r118= 0.0095f;     //Circle
    int tringle118=10;

    GLfloat tp118=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p118,q118);
    for(i= 0;i<=tringle13; i++)
    {
        glVertex2f (
                    p118+(r118*cos(i*tp118/tringle118)),
                    q118+(r118*sin(i*tp118/tringle118))
                    );
    }
    glEnd ();
//10th line 2

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, positionSnow10, 0.0f);

    GLfloat p119=-0.875f; GLfloat q119= -0.9f; GLfloat r119= 0.0095f;     //Circle
    int tringle119=10;

    GLfloat tp119=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p119,q119);
    for(i= 0;i<=tringle119; i++)
    {
        glVertex2f (
                    p119+(r119*cos(i*tp119/tringle119)),
                    q119+(r119*sin(i*tp119/tringle119))
                    );
    }
    glEnd ();

    GLfloat p120=-0.725f; GLfloat q120= -0.9f; GLfloat r120= 0.0095f;     //Circle
    int tringle120=10;

    GLfloat tp120=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p120,q120);
    for(i= 0;i<=tringle120; i++)
    {
        glVertex2f (
                    p120+(r120*cos(i*tp120/tringle120)),
                    q120+(r120*sin(i*tp120/tringle120))
                    );
    }
    glEnd ();

    GLfloat p121=-0.575f; GLfloat q121= -0.9f; GLfloat r121= 0.0095f;     //Circle
    int tringle121=10;

    GLfloat tp121=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p121,q121);
    for(i= 0;i<=tringle121; i++)
    {
        glVertex2f (
                    p121+(r121*cos(i*tp121/tringle121)),
                    q121+(r121*sin(i*tp121/tringle121))
                    );
    }
    glEnd ();

    GLfloat p122=-0.425f; GLfloat q122= -0.9f; GLfloat r122= 0.0095f;     //Circle
    int tringle122=10;

    GLfloat tp122=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p122,q122);
    for(i= 0;i<=tringle122; i++)
    {
        glVertex2f (
                    p122+(r122*cos(i*tp122/tringle122)),
                    q122+(r122*sin(i*tp122/tringle122))
                    );
    }
    glEnd ();

    GLfloat p123=-0.275f; GLfloat q123= -0.9f; GLfloat r123= 0.0095f;     //Circle
    int tringle123=10;

    GLfloat tp123=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p123,q123);
    for(i= 0;i<=tringle123; i++)
    {
        glVertex2f (
                    p123+(r123*cos(i*tp123/tringle123)),
                    q123+(r123*sin(i*tp123/tringle123))
                    );
    }
    glEnd ();

    GLfloat p124=-0.125f; GLfloat q124= -0.9f; GLfloat r124= 0.0095f;     //Circle
    int tringle124=10;

    GLfloat tp124=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p124,q124);
    for(i= 0;i<=tringle124; i++)
    {
        glVertex2f (
                    p124+(r124*cos(i*tp124/tringle124)),
                    q124+(r124*sin(i*tp124/tringle124))
                    );
    }
    glEnd ();

    GLfloat p125=0.025f; GLfloat q125= -0.9f; GLfloat r125= 0.0095f;     //Circle
    int tringle125=10;

    GLfloat tp125=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p125,q125);
    for(i= 0;i<=tringle125; i++)
    {
        glVertex2f (
                    p125+(r125*cos(i*tp125/tringle125)),
                    q125+(r125*sin(i*tp125/tringle125))
                    );
    }
    glEnd ();

    GLfloat p126=0.175f; GLfloat q126= -0.9f; GLfloat r126= 0.0095f;     //Circle
    int tringle126=10;

    GLfloat tp126=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p126,q126);
    for(i= 0;i<=tringle21; i++)
    {
        glVertex2f (
                    p126+(r126*cos(i*tp126/tringle126)),
                    q126+(r126*sin(i*tp126/tringle126))
                    );
    }
    glEnd ();

    GLfloat p127=0.325f; GLfloat q127= -0.9f; GLfloat r127= 0.0095f;     //Circle
    int tringle127=10;

    GLfloat tp127=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p127,q127);
    for(i= 0;i<=tringle127; i++)
    {
        glVertex2f (
                    p127+(r127*cos(i*tp127/tringle127)),
                    q127+(r127*sin(i*tp127/tringle127))
                    );
    }
    glEnd ();

    GLfloat p128=0.475f; GLfloat q128= -0.9f; GLfloat r128= 0.0095f;     //Circle
    int tringle128=10;

    GLfloat tp128=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p128,q128);
    for(i= 0;i<=tringle23; i++)
    {
        glVertex2f (
                    p128+(r128*cos(i*tp128/tringle128)),
                    q128+(r128*sin(i*tp128/tringle128))
                    );
    }
    glEnd ();

    GLfloat p129=0.625f; GLfloat q129=-0.9f; GLfloat r129= 0.0095f;     //Circle
    int tringle129=10;

    GLfloat tp129=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p129,q129);
    for(i= 0;i<=tringle129; i++)
    {
        glVertex2f (
                    p129+(r129*cos(i*tp129/tringle129)),
                    q129+(r129*sin(i*tp129/tringle129))
                    );
    }
    glEnd ();

    GLfloat p130=0.775f; GLfloat q130= -0.9f; GLfloat r130= 0.0095f;     //Circle
    int tringle130=10;

    GLfloat tp130=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p130,q130);
    for(i= 0;i<=tringle25; i++)
    {
        glVertex2f (
                    p130+(r130*cos(i*tp130/tringle130)),
                    q130+(r130*sin(i*tp130/tringle130))
                    );
    }
    glEnd ();

    GLfloat p131=0.925f; GLfloat q131= -0.9f; GLfloat r131= 0.0095f;     //Circle
    int tringle131=10;

    GLfloat tp131=2.0f * PI ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  //sea blue
    glVertex2f (p131,q131);
    for(i= 0;i<=tringle131; i++)
    {
        glVertex2f (
                    p131+(r131*cos(i*tp131/tringle131)),
                    q131+(r131*sin(i*tp131/tringle131))
                    );
    }
    glEnd ();

    glPopMatrix();
    }

	glFlush();  // Render now
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'g':
        positionControl = true;
        break;
        case 'G':
        positionControl = false;
        speedRCar = 0.016f;
        speedGCar = 0.015f;
        speedBLCar = 0.014f;
        speedYCar = 0.013f;
        speedBCar = 0.015f;
        speedBus = 0.012f;
        break;
        case 'B':
        speedBoat = 0.0f;
        scalebspeed = 0.0f;
        break;
        case 'b':
        speedBoat = 0.002f;
        scalebspeed = 0.0055f;
        break;
        case 'S':
        speedShip = 0.0f;
        break;
        case 's':
        speedShip = 0.008f;
        break;
        case 'n':
        night = true;
        _move_sun = -0.2;
        break;
        case 'd':
        nControl = 1.0f;
        break;
        case 'r':
        rain = true;
        break;
        case 'R':
        rain = false;
        break;

        case 'w':
        snowfall = true;
        break;
        case 'W':
        snowfall = false;
        break;

        case 'o':
        spin_speed_open = 0.5;
        spin_speed_close = 0.0;
        break;
        case 'O':
        spin_speed_close = 0.5;
        spin_speed_open = 0.0;
        break;
glutPostRedisplay();
}
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT

	glutInitWindowSize(1200, 800);   // Set the window's initial width & height
	glutCreateWindow("London Tower Bridge"); // Create a window with the given title
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutTimerFunc(100, update, 0);
	glutTimerFunc(40, update_sun, 0);
    glutTimerFunc(20, update_cloud_1, 0);
    glutTimerFunc(20, update_cloud_2, 0);
	glutKeyboardFunc(handleKeypress);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
