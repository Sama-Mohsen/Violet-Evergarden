//NOTE: If there are any errors due to the irrklang API, please comment out lines 5, 42, 48, 49, and 53.
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <irrKlang.h>
#include <cmath>
#include <iostream>

using namespace std;
using namespace irrklang;

void InitGraphics(int argc, char *argv[]);
void initGL();
void SetTransformations();
void OnDisplay();
void KeyPress(unsigned char key, int x, int y);

void drawBackground();
void drawWindow();
void rightPipe();
void leftPipe();
void drawUmbrella();

void drawBlouse();
void drawSkirt();

void drawVioletFace();
void violetMouse();
void violetNose();
void violetLeftEye();
void violetRightEye();
void violetLeftEyebrowOutline();
void violetHair();
void violetEar();

void luminousSpot( double x0, double y0, double rX, double rY, bool outlines=false, double outlinesAlfa=0.3);
void drawCircle(double x0, double y0, double rX, double rY, double R1,double G1, double B1, double alfa1, bool RGBA2=false, double R2=0, double G2=0, double B2=0,double alfa2=0);
void drawConcavePolygon(double vertices[][2], int size, double r1, double g1, double b1, double alfa1=1, bool RGBA2=false, double r2=0,double g2=0,double b2=0,double alfa2=1);

int layer=0;
ISoundEngine* sceneThemeMusic= createIrrKlangDevice();


int main(int argc, char* argv[])
{
    system("clear");
    sceneThemeMusic->play2D("The Long Night.mp3", true);
    cout<<"NOTE: THERE IS MUSIC (Music from the anime)\nIT'S UP TO YOU TO LISTEN OR NOT :)\n\n";
    cout<<"Please press D || d to change layer && ESC to EXIT\n";
    initGL();
    InitGraphics(argc, argv);
    sceneThemeMusic->drop();
    return 0;
}

void SetTransformations()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1472, -2616, 0);
}
void InitGraphics(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE | GLUT_DEPTH | GLUT_STENCIL);

    int windowWidth=1472/3;
    int windowHeight=2616/3;
    int windowPosX = abs(1920 - windowWidth) / 2;
    int windowPosY = abs(1080 - windowHeight) / 2;

    glutInitWindowSize(windowWidth,windowHeight);
    glutInitWindowPosition(windowPosX,windowPosY);
    glutCreateWindow("Violet Evergarden (Stu: Sama Mohsen)");

    //to enable alpha of glColor4f(R,G,B,Alfa);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    // Enable multisampling for smoother edges
    glEnable(GL_MULTISAMPLE);
    glutDisplayFunc(OnDisplay);
    glutKeyboardFunc(KeyPress);
    glutMainLoop();
}
void initGL()
{
    // Clear stencil buffer and set the clear value
    glClearStencil(0);                          // Clear stencil buffer to 0
    glClear(GL_STENCIL_BUFFER_BIT);             // Clear the stencil buffer

    // Enable stencil test
    glEnable(GL_STENCIL_TEST);                  // Enable stencil test

    // Stencil function and operation setup
    glStencilFunc(GL_ALWAYS, 1, 0xFF);          // Always pass the stencil test, with ref value 1 and mask 0xFF
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);  // Replace the stencil value with ref value if test passes

    // Set clear color and depth
    glClearDepth(1.0f);                         // Set depth buffer clear value to 1 (far)
    glDepthFunc(GL_LEQUAL);                     // Set depth function
}
void KeyPress(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27: // ESCAPE
            system("clear");
            cout<<"Key 'ESC' pressed\n";
            exit(0);
            break;

        case ' ':
            break;

        case 'd': // switch rendering modes
        case 'D': {
            layer = ++layer % 6;
            cout<<"Key 'D' pressed\n";
        }
            break;
        default:
            ;
    }
    glutPostRedisplay();
}


void luminousSpot( double x0, double y0, double rX, double rY, bool outlines, double outlinesAlfa)
{
    //luminous spot
    glBegin(GL_POLYGON);
    glColor4f(249/255.0f,204/255.0f,134/255.0f,1);
    glVertex2d(x0,-y0);
    for (int i = 0; i <= 360; ++i)
    {
        glColor4d(249/255.0f,204/255.0f,134/255.0f,0.35);
        double theta=i*3.14/180;
        glVertex2d(rX*cos(theta)+x0,-rY*sin(theta)-y0);
    }
    glEnd();

    //outlines
    if (outlines)
    {
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
        glColor4d(211 / 255.0f, 128 / 255.0f, 59 / 255.0f, outlinesAlfa);
        for (int i = 0; i <= 360; ++i) {
            double theta = i * 3.14 / 180;
            glVertex2d(rX * cos(theta) + x0, -rY * sin(theta) - y0);
        }
        glEnd();
        glLineWidth(1);
    }

}
void drawCircle(double x0, double y0, double rX, double rY, double R1,double G1, double B1, double alfa1, bool RGBA2, double R2, double G2, double B2,double alfa2)
{
    glBegin(GL_POLYGON);
    glColor4d(R1/255.0f,G1/255.0f,B1/255.0f,alfa1);
    glVertex2d(x0,-y0);
    for (int i = 0; i <= 360; ++i)
    {
        if(RGBA2) glColor4d(R2/255.0f,G2/255.0f,B2/255.0f,alfa2);
        double theta=i*3.14/180;
        glVertex2d(rX*cos(theta)+x0,-rY*sin(theta)-y0);
    }
    glEnd();
}
void rightPipe()
{
    //elBase beta3 elMasoura elYemeen
//    glColor3f(145/255.0f, 71/255.0f, 39/255.0f);
    glColor3f(175/255.0f, 93/255.0f, 47/255.0f);
    glBegin(GL_POLYGON);
    glVertex2d(83.5, -0);
    glVertex2d(197.5, -0);
    glVertex2d(197.5, -1518);
    glColor3f(139/255.0f, 62/255.0f, 33/255.0f);
    glVertex2d(219.5, -2616);
    glVertex2d(99, -2616);
    glColor3f(175/255.0f, 93/255.0f, 47/255.0f);
    glVertex2d(99, -1518);
    glEnd();

    //ElLight elly fy elganb elyemeen
    glPushMatrix();
    glTranslated(1,0,0);
    glLineWidth(4);
    glColor4f(1, 211/255.0f, 121/255.0f,0.4);
    glBegin(GL_LINE_STRIP);
    glVertex2d(190.667, -0.333);
    glVertex2d(205.667, -2301.333);
    glColor4f(145/255.0f, 71/255.0f, 39/255.0f,0.3);
    glVertex2d(210.667, -2613.000);
    glEnd();
    glPopMatrix();

    //half circle (light) 1
    glColor4f(1, 211/255.0f, 121/255.0f,1);
    glBegin(GL_POLYGON);
    glVertex2d(197.5, -983.125);
    for (int i = 0; i <= 36; ++i)
    {
        glColor4f(1, 211/255.0f, 121/255.0f,0.1);
        double theta = 2*3.14 * (static_cast<double>(i)/36.0f);
        glVertex2d(8.125 * cos(theta) + 197.5, 22.875 * sin(theta) - 983.125);
    }
    glEnd();

    //oval (light) 2
    glBegin(GL_POLYGON);
    glColor4f(1, 210/255.0f, 121/255.0f,1);
    glVertex2d(198.000, -1134.917);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(185.833, -1135.000);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(186.083, -1123.833);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(187.000, -1115.833);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(189.750, -1109.083);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(194.750, -1103.500);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(198.750, -1101.917);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(201.833, -1103.083);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(203.750, -1107.833);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(204.667, -1113.583);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(203.750, -1122.333);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(203.833, -1130.083);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(204.083, -1137.417);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(205.417, -1149.333);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(205.750, -1158.083);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(204.167, -1164.500);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(200.917, -1165.417);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(196.667, -1164.917);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(191.833, -1161.167);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(188.500, -1156.333);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(186.250, -1148.000);
    glColor4f(1, 210/255.0f, 121/255.0f,0.8);
    glVertex2d(185.750, -1135.167);
    glEnd();

    //Outlines of the oval
    glLineWidth(2);
    glColor4f(211/255.0f, 128/255.0f, 59/255.0f,0.3);
    glBegin(GL_LINE_LOOP);
    glVertex2d(185.833, -1135.000);
    glVertex2d(186.083, -1123.833);
    glVertex2d(187.000, -1115.833);
    glVertex2d(189.750, -1109.083);
    glVertex2d(194.750, -1103.500);
    glVertex2d(198.750, -1101.917);
    glVertex2d(201.833, -1103.083);
    glVertex2d(203.750, -1107.833);
    glVertex2d(204.667, -1113.583);
    glVertex2d(203.750, -1122.333);
    glVertex2d(203.833, -1130.083);
    glVertex2d(204.083, -1137.417);
    glVertex2d(205.417, -1149.333);
    glVertex2d(205.750, -1158.083);
    glVertex2d(204.167, -1164.500);
    glVertex2d(200.917, -1165.417);
    glVertex2d(196.667, -1164.917);
    glVertex2d(191.833, -1161.167);
    glVertex2d(188.500, -1156.333);
    glVertex2d(186.250, -1148.000);
    glVertex2d(185.750, -1135.167);
    glEnd();

    //half circle (light) 3
    glColor4f(1, 211/255.0f, 121/255.0f,1);
    glBegin(GL_POLYGON);
    glVertex2d(201.25, -1825);
    for (int i = 0; i <= 36; ++i)
    {
        glColor4f(1, 211/255.0f, 121/255.0f,0.1);
        double theta = 2*3.14 * (static_cast<double>(i)/36.0f);
        glVertex2d(5 * cos(theta) + 201.25, 62 * sin(theta) - 1825);
    }
    glEnd();

    //light point
    glColor4f(1, 211/255.0f, 121/255.0f,1);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2d(205,-2093);
    glEnd();

    //El_shadow el_black beta3 el_masora el_yemeen
    glBegin(GL_POLYGON);
    glColor4f(0,0,0,0.5);
    glVertex2d(109, -2616);
    glVertex2d(99, -2616);
    glVertex2d(82, 0);
    glVertex2d(97, 0);
    glColor4f(0,0,0,0.1);
    glVertex2d(115, 0);
    glVertex2d(127, -2616);
    glEnd();

    //black shadow 23
    glBegin(GL_POLYGON);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.3);
    glVertex2d(161,-989);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(192, -806);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(197, -1091);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(189, -1100);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(182, -1114);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(181, -1132);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(179, -1177);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(99, -844);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(192, -806);
    glEnd();


    //black shadow 24
    glBegin(GL_POLYGON);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.1);
    glVertex2f(179, -1467);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(152, -1644);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(181, -1524);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(201, -1439);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(200, -1391);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(179, -1316);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(152, -1643);
    glEnd();

    //black shadow 25
    glBegin(GL_POLYGON);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.1);
    glVertex2d(141,-1459);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(132, -1411);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(147, -1340);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(151, -1428);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(143, -1572);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(132, -1411);
    glEnd();


    //black shadow 26
    glBegin(GL_POLYGON);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.15);
    glVertex2d(168,-1783);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(132, -1904);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(189, -1893);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(196, -1699);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(159, -1665);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(143, -1787);
    glColor4f(0/255.0f,0/255.0f, 0/255.0f, 0.0);
    glVertex2f(132, -1904);
    glEnd();


    //3amoud end
}
void leftPipe()
{
    //base elMasoura
    glColor3f(171/255.0f, 82/255.0f, 37/255.0f);
    glBegin(GL_POLYGON);
    glVertex2d(83.5, -0);
    glVertex2d(99, -2616);
    glVertex2d(0,-2616);
    glVertex2d(0,0);
    glEnd();

    //elLignt
    glPushMatrix();
    glTranslated(-115,0,0);
    glLineWidth(4);
    glColor4f(1, 211/255.0f, 121/255.0f,0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2d(190.667, -0.333);
    glVertex2d(205.667, -2301.333);
    glColor4f(145/255.0f, 71/255.0f, 39/255.0f,0.2);
    glVertex2d(210.667, -2613.000);
    glEnd();
    glPopMatrix();



    //elElte7am elAwwal beta3 elmasoura
    glColor3f(186/255.0f, 90/255.0f, 43/255.0f);
    glBegin(GL_POLYGON);
    glVertex2d(87.833, -1047.500);
    glVertex2d(0, -1062.667);
    glVertex2d(95.833, -1061.000);
    glVertex2d(100.667, -1058.000);
    glVertex2d(102.167, -1053.833);
    glVertex2d(102.167, -1048.833);
    glVertex2d(101.500, -1043.667);
    glVertex2d(99.000, -1038.667);
    glVertex2d(95.000, -1035.167);
    glVertex2d(90.667, -1032.000);
    glVertex2d(86.833, -1029.667);
    glVertex2d(0, -1028.833);
    glVertex2d(0, -1062.500);
    glEnd();

    //elLignt elly fey elgand beta3 Awwel elte7am
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.9);

//    glColor4f(1, 211/255.0f, 121/255.0f,1);
    glBegin(GL_POLYGON);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(88.667, -1047.000);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(71.333, -1059.000);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(78.000, -1052.333);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(78.000, -1047.667);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(76.000, -1043.000);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(70.667, -1041.000);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(68.333, -1041.000);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(68.167, -1029.333);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.9);
    glVertex2d(87.000, -1029.333);
    glVertex2d(97.500, -1038.833);
    glVertex2d(100.000, -1043.500);
    glVertex2d(100.833, -1049.167);
    glVertex2d(100.167, -1054.500);
    glVertex2d(97.167, -1059.000);
    glVertex2d(71.333, -1059.000);
    glEnd();

    //elShadow elBlack ta7t awwel elte7am
    glBegin(GL_POLYGON);
    /*glVertex2d(0, -1060.500);
    glVertex2d(100.500, -1059.167);
    glVertex2d(99.167, -1062.833);
    glVertex2d(96.167, -1065.667);
    glVertex2d(0.000, -1067.333);*/
    glColor4f(0, 0, 0,0.5);

    glVertex2d(0,-1066);
    glVertex2d(0, -1060.500);
    glVertex2d(98.500, -1059.750);
    glVertex2d(93.750, -1065.000);
    glColor4f(0,0,0,0.1);
    glVertex2d(93.750, -1071.000);
    glVertex2d(0, -1071.500);
    glEnd();

    //elshadow elBlack elly ganb elmasoura
    glLineWidth(10);
    glColor4f(76/255.0f, 41/255.0f, 33/255.0f,0.9999);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glColor4f(76/255.0f, 41/255.0f, 33/255.0f,0.9999);
    glVertex2d(0,-2616);
    glEnd();

    //elElte7am eltany
//    glColor4f(175/255.0f, 76/255.0f, 32/255.0f,1);
    glColor3f(186/255.0f, 90/255.0f, 43/255.0f);
    glBegin(GL_POLYGON);
    glVertex2d(4.167, -2121.500);
    glVertex2d(105.500, -2121.333);
    glVertex2d(105.500, -2130.167);
    glVertex2d(104.833, -2133.333);
    glVertex2d(102.667, -2135.333);
    glVertex2d(4.333, -2135.833);
    glEnd();

    //upper light
    //7
    glColor3f(201/255.0f, 104/255.0f, 49/255.0f);
    glBegin(GL_POLYGON);
    /*glVertex2d(19.500, -2120.375);
    glVertex2d(19.500, -2110.250);
    glVertex2d(17.500, -2110.250);
    glVertex2d(13.375, -2110.750);
    glVertex2d(10.375, -2112.250);
    glVertex2d(7.375, -2115.125);
    glVertex2d(5.250, -2118.500);
    glVertex2d(4.750, -2121.375);
    glVertex2d(37.125, -2121.375);
    glVertex2d(36.875, -2115.250);
    glVertex2d(29.625, -2115.125);
    glVertex2d(27.750, -2113.625);
    glVertex2d(25.500, -2111.625);
    glVertex2d(22.875, -2110.750);
    glVertex2d(19.500, -2110.250);*/

    glVertex2d(21.250, -2119.875);
    glVertex2d(37.000, -2118.000);
    glVertex2d(36.750, -2115.250);
    glVertex2d(32.500, -2115.000);
    glVertex2d(29.250, -2113.312);
    glVertex2d(25.188, -2111.438);
    glVertex2d(22.688, -2110.375);
    glVertex2d(20.000, -2109.500);
    glVertex2d(16.333, -2109.000);
    glVertex2d(12.500, -2109.000);
    glVertex2d(8.833, -2111.833);
    glVertex2d(5.833, -2115.167);
    glVertex2d(5.000, -2117.167);
    glVertex2d(4.667, -2122.167);
    glVertex2d(37.500, -2121.500);
    glVertex2d(37.000, -2118.000);
    glEnd();

    //7
    glBegin(GL_POLYGON);
    glVertex2d(36.750, -2115.250);
    glVertex2d(88.500, -2114.333);
    glVertex2d(89.333, -2121.333);
    glVertex2d(37.333, -2121.500);
    glEnd();

    //8
    glBegin(GL_POLYGON);
    glVertex2d(97.500, -2114.000);
    glVertex2d(87.062, -2114.312);
    glVertex2d(92.500, -2113.083);
    glVertex2d(95.917, -2111.750);
    glVertex2d(97.167, -2109.083);
    glVertex2d(99.917, -2109.500);
    glVertex2d(102.333, -2110.917);
    glVertex2d(103.917, -2112.833);
    glVertex2d(105.167, -2115.083);
    glVertex2d(105.500, -2121.417);
    glVertex2d(89.250, -2121.333);
    glVertex2d(87.083, -2114.333);
    glEnd();


    glPushMatrix();
    glTranslated(-6,0,0);
    //1/2 elCircle elly 3amel elLight elly fou2 elElte7am (left)
    glBegin(GL_POLYGON);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.8);
    glVertex2d(18.75,-2116);
    glVertex2d(18.75,-2121.5);
    for (int i = 0; i <= 18; ++i)
    {
        double theta=3.14*i/18;
        glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
        glVertex2d((18.75-4.167)*cos(theta)+18.75, (2121.5-2110.583)*sin(theta)-2121.5);
    }
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.8);
    glVertex2d(18.75,-2121.5);
    glEnd();
    glPopMatrix();

    //like 1/2 elCircle elly 3amel elLight elly fou2 elElte7am (right)
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.9);
    glBegin(GL_POLYGON);
    glVertex2d(96.188, -2117.344);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(96.188, -2121.000);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(103.667, -2121.042);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(103.583, -2117.625);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(103.208, -2116.417);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(102.167, -2115.167);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(101.250, -2114.167);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(99.375, -2113.542);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(96.625, -2113.417);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(93.375, -2113.500);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(90.000, -2113.938);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(88.000, -2114.812);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(86.938, -2116.750);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(86.812, -2117.688);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(86.750, -2121.000);
    glColor4f(245/255.0f,189/255.0f,106/255.0f,0.1);
    glVertex2d(96.188, -2121.031);
    glEnd();

    //black shadow ta7t elLight beta3 tany elte7am
    glColor4f(0/255.0f, 0/255.0f, 0/255.0f, 0.05f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2d(6.333, -2122.333);
    glVertex2d(103.625, -2122.125);
//    glVertex2d(103.625, -2124.125);
//    glVertex2d(6.250, -2124.500);
    glEnd();


    //black shadow ta7t elElte7am elTany
    glBegin(GL_POLYGON);
    glColor4f(0,0,0,0.5);
    glVertex2d(9.333, -2141.000);
    glVertex2d(6.833, -2136.333);
    glVertex2d(98.167, -2136.833);
    glVertex2d(95.667, -2141.500);
    glColor4f(0,0,0,0.3);
    glVertex2d(95.667, -2145.333);
    glVertex2d(9.333, -2145.167);
    glEnd();

    //elShadow elGaneby beta3 elElte7am elTany
    glColor4f(0, 0, 0, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(3.500, -2126.250);
    glVertex2d(10.333, -2124.917);
    glVertex2d(10.250, -2121.917);
    glVertex2d(10.188, -2118.375);
    glVertex2d(10.250, -2115.750);
    glVertex2d(11.917, -2110.667);
    glVertex2d(6.000, -2113.250);
    glVertex2d(3.167, -2117.833);
    glVertex2d(1.750, -2124.917);
    glVertex2d(2.417, -2131.583);
    glVertex2d(4.917, -2136.417);
    glVertex2d(10.750, -2141.833);
    glVertex2d(10.250, -2136.917);
    glVertex2d(10.250, -2129.083);
    glVertex2d(10.333, -2125.083);
    glEnd();


    //elShadow elBlack beta3 tany masoura (elgoz2 elly ta7t elElte7am elAwwal)
    glColor4f(0, 0,0, 0.15);
    glBegin(GL_POLYGON);
    glVertex2d(28.667, -2153.333);
    glVertex2d(94.667, -2143.333);
    glVertex2d(94.000, -2151.333);
    glVertex2d(81.000, -2152.000);
    glVertex2d(69.000, -2153.000);
    glVertex2d(58.000, -2157.000);
    glVertex2d(51.000, -2162.667);
    glVertex2d(45.000, -2173.000);
    glVertex2d(43.333, -2196.000);
    glVertex2d(43.333, -2217.000);
    glVertex2d(10.000, -2217.000);
    glVertex2d(10.667, -2144.667);
    glVertex2d(94.333, -2143.000);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(43.333, -2217.333);
    glVertex2d(10.333, -2217.000);
    glVertex2d(11.667, -2615.000);
    glVertex2d(47.667, -2615.000);
    glEnd();



//elShadow elBlack fou2 elMasoura
    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.4);
    glVertex2d(35.0, -2615.0);
    glVertex2d(12.0, -2615.0);
    glVertex2d(3.0, -0.0);
    glVertex2d(21.0, -0.0);
    glColor4f(0, 0, 0, 0.1);
    glVertex2d(42.0, -0.0);
    glVertex2d(61.0, -2616.0);
    glEnd();

    //elMasouraEnd

}

void drawWindow()
{
    //elLight wara el4ebbak
    glBegin(GL_POLYGON);
    glColor4f(247/255.0f, 216/255.0f, 149/255.0f, 1);
    glVertex2f(723, -1677);
    glVertex2f(723, -333);
    glVertex2f(1401, -333);
    glVertex2f(1401, -1677);
    glColor4f(244/255.0f, 198/255.0f, 123/255.0f, 1);
    glVertex2f(1401, -2199);
    glVertex2f(723, -2199);
    glEnd();

    //clouds awwel fat7a fy el4ebbak
    //cloud 1
    glPushMatrix();
    glTranslated(1235,-443,0);
    glRotated(5,0,0,1);
    drawCircle(0,0,144*4,39*4,233,173,78,1,true,233,173,78,0.001);
    drawCircle(0,0,144,39,233,173,78,0.999,true,233,173,78,0.15);
    glPopMatrix();

    //cloud 2
    drawCircle(1067,580.5,60*1.5,14*1.5,233,173,78,1,true,234,178,96,0.001);

    //cloud 3
    glPushMatrix();
    glTranslated(1247,-582,0);
    glRotated(-3,0,0,1);
    drawCircle(0,0,51*1.5,11*1.5,233,173,78,0.8,true,234,178,96,0.001);
    glPopMatrix();

    //cloud 4 (Heart)
    glBegin(GL_POLYGON);
    glColor4f(233/255.0f, 173/255.0f, 78/255.0f, 0.7);
    glVertex2d(1253,-727);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1267.000, -761.500);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1205.000, -734.000);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1202.500, -726.500);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1202.500, -717.500);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1204.500, -713.000);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1211.500, -709.000);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1220.000, -707.000);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1243.000, -708.000);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1252.500, -700.000);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1259.000, -696.000);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1265.000, -694.500);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1277.500, -694.500);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1286.000, -695.500);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1294.000, -697.500);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1299.000, -705.000);
    glColor4f(246/255.0f, 217/255.0f, 165/255.0f, 1);
    glVertex2f(1267.000, -761.500);
    glEnd();

    //cloud 5
    glPushMatrix();
    glTranslated(1363,-759.5,0);
    glRotated(20,0,0,1);
    drawCircle(0,0,14*3,34*3,233,173,78,0.7,true,234,178,96,0.001);
    glPopMatrix();


    //clouds tany fat7a fy el4ebbak
    //1st shadow
    glBegin(GL_POLYGON);
    glColor4f(223/255.0f, 152/255.0f, 67/255.0f, 0.9);
    glVertex2f(1044.000, -862.000);
    glColor4f(239/255.0f, 186/255.0f, 100/255.0f, 0.9);
    glVertex2f(1265.000, -864.000);
    glColor4f(239/255.0f, 186/255.0f, 100/255.0f, 0.9);
    glVertex2f(1043.000, -898.000);
    glEnd();

    //2nd shadow
    glBegin(GL_POLYGON);
    glColor4f(223/255.0f, 152/255.0f, 67/255.0f, 0.7);
    glVertex2f(1044, -926);
    glColor4f(246/255.0f, 220/255.0f, 166/255.0f, 0.5);
    glVertex2f(1040, -835);
    glVertex2f(1384, -795);
    glColor4f(223/255.0f, 152/255.0f, 67/255.0f, 0.7);
    glVertex2f(1378, -910);
    glColor4f(246/255.0f, 220/255.0f, 166/255.0f, 0.5);
    glVertex2f(1381, -1010);
    glVertex2f(1045, -984);
    glEnd();


    //3rd shadow
    glPushMatrix();
    glTranslated(1339,-1033,0);
    glRotated(20,0,0,1);
    drawCircle(0,0,19*2,8*2,233,173,78,0.5,true,234,178,96,0.001);
    glPopMatrix();

    //4th shadow
    drawCircle(1067.5,1151.5,47,10,233,173,78,0.4,true,234,178,96,0.001);

    //5th shadow
    glPushMatrix();
    glTranslated(1361.5,-1213.5,0);
    glRotated(30,0,0,1);
    drawCircle(0,0,13*2,32*2,233,173,78,0.4,true,234,178,96,0.001);
    glPopMatrix();


    //clouds talet fat7a fy el4ebbak
    glBegin(GL_POLYGON);
    glColor4f(223/255.0f, 152/255.0f, 67/255.0f, 0.9);
    glVertex2f(1040.000, -1349.000);
    glColor4f(247/255.0f, 215/255.0f, 155/255.0f, 0.8);
    glVertex2f(1337.000, -1347.000);
    glColor4f(247/255.0f, 215/255.0f, 155/255.0f, 0.8);
    glVertex2f(1311.000, -1361.000);
    glColor4f(247/255.0f, 215/255.0f, 155/255.0f, 0.8);
    glVertex2f(1282.000, -1373.000);
    glColor4f(247/255.0f, 215/255.0f, 155/255.0f, 0.8);
    glVertex2f(1156.000, -1376.000);
    glColor4f(247/255.0f, 215/255.0f, 155/255.0f, 0.8);
    glVertex2f(1144.000, -1383.000);
    glColor4f(247/255.0f, 215/255.0f, 155/255.0f, 0.8);
    glVertex2f(1126.000, -1391.000);
    glColor4f(247/255.0f, 215/255.0f, 155/255.0f, 0.8);
    glVertex2f(1108.000, -1396.000);
    glColor4f(247/255.0f, 215/255.0f, 155/255.0f, 0.8);
    glVertex2f(1078.000, -1400.000);
    glColor4f(247/255.0f, 215/255.0f, 155/255.0f, 0.8);
    glVertex2f(1042.000, -1383.000);
    glEnd();

    //line
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor4f(248/255.0f, 210/255.0f, 150/255.0f, 0.7);
    glVertex2f(1295.000, -1670.000);
    glColor4f(223/255.0f, 152/255.0f, 67/255.0f, 0.5);
    glVertex2f(1298.000, -1340);
    glColor4f(248/255.0f, 210/255.0f, 150/255.0f, 0.7);
    glVertex2f(1329.000, -1443.000);
    glEnd();

    //polygon under the line
    glBegin(GL_POLYGON);
    glColor4f(223/255.0f, 152/255.0f, 67/255.0f, 0.6);
    glVertex2d(1227,-1766);
    glColor4f(248/255.0f, 210/255.0f, 150/255.0f, 0.7);
    glVertex2f(1233.000, -1720.000);
    glVertex2f(1034.000, -1530.000);
    glVertex2f(1033.000, -1764.000);
    glColor4f(223/255.0f, 152/255.0f, 67/255.0f, 0.6);
    glVertex2f(1389.000, -1770.000);
    glColor4f(248/255.0f, 210/255.0f, 150/255.0f, 0.7);
    glVertex2f(1391.000, -1593.000);
    glVertex2f(1233.000, -1720.000);
    glEnd();


    //shadows rabe3 fat7a fy el4ebbak
    glBegin(GL_POLYGON);
    glColor4f(239/255.0f, 193/255.0f, 118/255.0f, 0.3);
    glVertex2f(991.000-30, -1982.000);
    glVertex2f(991.000-30, -1742.000);
    glVertex2f(1450.000, -1742.000);
    glVertex2f(1450.000, -1982.000);
    glColor4f(240/255.0f, 184/255.0f, 99/255.0f, 1);
    glVertex2f(1450.000, -2209.000);
    glVertex2f(991.000-30, -2209.000);
    glEnd();

    //Line 1 x
    glBegin(GL_POLYGON);
    glColor4f(239/255.0f, 181/255.0f, 97/255.0f, 0.9);
    glVertex2d(1169,-1865);
    glColor4f(246/255.0f, 198/255.0f, 123/255.0f, 0.9);
    glVertex2f(1018.000, -1900.000);
    glVertex2f(1327.000, -1752.000);
    glVertex2f(1317.000, -1857.000);
    glVertex2f(1023.000, -1954.000);
    glVertex2f(1018.000, -1900.000);
    glEnd();

    //line2 x
//    glColor4f(207/255.0f, 127/255.0f, 56/255.0f, 0.4);
    glBegin(GL_POLYGON);
    glColor4f(224/255.0f, 156/255.0f, 72/255.0f, 0.9);
    glVertex2d(1228,-1844);
    glColor4f(246/255.0f, 198/255.0f, 123/255.0f, 0.9);
    glVertex2f(1008,-1796);
    glVertex2f(1014.000, -1781.000);
    glVertex2d(1209,-1817);
    glVertex2f(1402.000, -1854.000);
    glVertex2d(1403,-1872);
    glVertex2f(1405.000, -1893.000);
    glVertex2d(1201,-1854);
    glVertex2f(1002.000, -1816.000);
    glVertex2f(1008,-1796);
    glEnd();


    //vertical line fat7a a5eera
    glColor4f(223/255.0f, 152/255.0f, 67/255.0f, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(1332, -1766);
    glVertex2f(1407, -1772);
    glVertex2f(1412, -2185);
    glVertex2f(1342, -2184);
    glColor4f(243/255.0f, 200/255.0f, 126/255.0f, 0.0);
    glVertex2f(1311, -2185);
    glVertex2f(1295, -1764);
    glEnd();

    //horizontal line fat7a a5eera
    glBegin(GL_POLYGON);
    glColor4f(223/255.0f, 152/255.0f, 67/255.0f, 0.9);
    glVertex2f(1044.500, -2097.000);
    glVertex2f(1043.000, -2178.500);
    glVertex2f(1395.000, -2179.000);
    glVertex2f(1392.500, -2122.500);
    glColor4f(243/255.0f, 200/255.0f, 126/255.0f, 0.0);
    glVertex2f(1391.500, -2090.000);
    glVertex2f(1045.000, -2057.500);
    glEnd();


    //okret el4ebbak
    glColor4f(185/255.0f, 112/255.0f, 53/255.0f, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(1102.458, -2154.958);
    glVertex2f(1104.250, -2152.250);
    glVertex2f(1107.250, -2150.250);
    glVertex2f(1111.250, -2149.500);
    glVertex2f(1315.417, -2146.833);
    glVertex2f(1317.500, -2147.167);
    glVertex2f(1319.167, -2147.917);
    glVertex2f(1320.750, -2149.500);
    glVertex2f(1321.417, -2151.250);
    glVertex2f(1321.000, -2152.250);
    glVertex2f(1320.083, -2153.750);
    glVertex2f(1318.167, -2155.250);
    glVertex2f(1317.167, -2155.833);
    glVertex2f(1112.958, -2160.167);
    glVertex2f(1112.125, -2160.167);
    glVertex2f(1108.083, -2160.125);
    glVertex2f(1106.500, -2159.708);
    glVertex2f(1104.667, -2158.792);
    glVertex2f(1103.208, -2157.250);
    glEnd();


    // elgoz2 elda5ely men el4ebbak base (middle horizontal 1)
    glColor4f(204/255.0f, 127/255.0f, 60/255.0f, 1);
    glBegin(GL_POLYGON);
    glVertex2f(890, -842);
    glVertex2f(1378, -842);
    glVertex2f(1378, -871);
    glVertex2f(890, -871);
    glEnd();

    // elShadows elBlack beta3 elgoz2 elda5ely men el4ebbak base (middle horizontal 1)
    glLineWidth(5);
    glColor4f(0, 0, 0, 0.08);
    glBegin(GL_LINES);
    glVertex2f(890, -842-2);
    glVertex2f(1378, -842-2);
    glVertex2f(1378, -871+2);
    glVertex2f(890, -871+2);
    glEnd();


    glPushMatrix();
    glTranslated(0,-480,0);
    // elgoz2 elda5ely men el4ebbak base (middle horizontal 2)
    glColor4f(204/255.0f, 127/255.0f, 60/255.0f, 1);
    glBegin(GL_POLYGON);
    glVertex2f(890, -842);
    glVertex2f(1378, -842);
    glVertex2f(1378, -871);
    glVertex2f(890, -871);
    glEnd();

    // elShadows elBlack beta3 elgoz2 elda5ely men el4ebbak base (middle horizontal 2)
    glLineWidth(5);
    glColor4f(0, 0, 0, 0.08);
    glBegin(GL_LINES);
    glVertex2f(890, -842-2);
    glVertex2f(1378, -842-2);
    glVertex2f(1378, -871+2);
    glVertex2f(890, -871+2);
    glEnd();
    glPopMatrix();

    //elLight elly fy elShadows elBlack elgoz2 elda5ely men el4ebbak base (middle horizontal 2) (upper)
    luminousSpot(1104,1324,48,5.5, true,0.3);

    //elLight elly fy elShadows elBlack elgoz2 elda5ely men el4ebbak base (middle horizontal 2) (lower)
    luminousSpot(1233,1347, 68,9,true,0.45);


    glPushMatrix();
    glTranslated(4,-480*1.9,0);
    // elgoz2 elda5ely men el4ebbak base (middle horizontal 3)
    glColor4f(204/255.0f, 123/255.0f, 50/255.0f, 1);
    glBegin(GL_POLYGON);
    glVertex2f(890, -842);
    glVertex2f(1378, -842);
    glVertex2f(1378, -871);
    glVertex2f(890, -871);
    glEnd();

    // elShadows elBlack beta3 elgoz2 elda5ely men el4ebbak base (middle horizontal 3)
    glLineWidth(6);
    glColor4f(217/255.0f, 139/255.0f, 62/255.0f, 0.5);
    glBegin(GL_LINES);
    glVertex2f(890, -842-1);
    glVertex2f(1378, -842-1);
    glVertex2f(1378, -871+1);
    glVertex2f(890, -871+1);
    glEnd();
    glPopMatrix();


    // elgoz2 elda5ely men el4ebbak (middle (vertical))
    glColor4f(195/255.0f, 118/255.0f, 58/255.0f, 1);
    glBegin(GL_POLYGON);
    glVertex2f(1005, -263);
    glVertex2f(1046, -263);
    glVertex2f(1046, -2229);
    glVertex2f(1005, -2229);
    glEnd();

    glColor4f(246/255.0f, 219/255.0f, 165/255.0f, 0.08);
    glBegin(GL_POLYGON);
    glVertex2f(1005, -263);
    glVertex2f(1046, -263);
    glVertex2f(1046, -2229);
    glVertex2f(1005, -2229);
    glEnd();
    glColor4f(246/255.0f, 219/255.0f, 165/255.0f, 0.1);
    glLineWidth(7);
    glBegin(GL_LINES);
    glVertex2f(1005, -263);
    glVertex2f(1005, -2229);
    glVertex2f(1046, -263);
    glVertex2f(1046, -2229);
    glEnd();



    // elgoz2 elda5ely men el4ebbak (upper one)
    glBegin(GL_POLYGON);
    glColor4f(219/255.0f, 128/255.0f, 58/255.0f, 1);
    glVertex2f(1404.0, -336.0);
    glVertex2f(1404.0, -354.0);
    glVertex2f(1186.0, -354.0);
    glVertex2f(1186.0, -336.0);

    glColor4f(156/255.0f, 86/255.0f, 46/255.0f, 1);
    glVertex2f(1186.0, -307.0);
    glVertex2f(1404.0, -307.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor4f(0,0,0,0.05);
    glVertex2f(1404.0, -354.0);
    glVertex2f(1186.0, -354.0);
    glEnd();


    // elgoz2 elda5ely men el4ebbak (right one)
    glBegin(GL_POLYGON);
    glColor4f(177/255.0f, 100/255.0f, 52/255.0f, 1);
    glVertex2f(1379.0, -334.5);
    glVertex2f(1402.5, -305.5);
    glVertex2f(1415.5, -2211.0);
    glVertex2f(1402.0, -2211.0);
    glColor4f(205/255.0f, 126/255.0f, 57/255.0f, 1);
    glVertex2f(1388.0, -2211.0);
    glVertex2f(1363.5, -354.0);
    glEnd();


    // elgoz2 elda5ely men el4ebbak (lower one)
    glBegin(GL_POLYGON);
    glColor4f(177/255.0f, 100/255.0f, 52/255.0f, 1);
    glVertex2f(1212, -2170);
    glVertex2f(1418, -2170);
    glVertex2f(1418, -2213);
    glVertex2f(1212, -2213);
    glColor4f(204/255.0f, 124/255.0f, 54/255.0f, 1);
    glVertex2f(1007, -2213);
    glVertex2f(1007, -2170);
    glEnd();




    //elShadow elBlack elly ta7t el4ebbak (horizontal)
    glBegin(GL_POLYGON);
    glColor4f(138/255.0f, 71/255.0f, 34/255.0f, 0.9);
    glVertex2f(1049.0, -2331.0);
    glVertex2f(1049.0, -2294.0);
    glVertex2f(1426.0, -2294.0);
    glVertex2f(1426.0, -2331.0);
    glColor4f(190/255.0f, 105/255.0f, 49/255.0f, 0.45);
    glVertex2f(1426.0, -2377.0);
    glVertex2f(1049.0, -2377.0);
    glEnd();

    //elShadow elBlack elly ta7t el4ebbak  (vertical)
    glBegin(GL_POLYGON);
    glColor4f(138/255.0f, 71/255.0f, 34/255.0f, 0.8);
    glVertex2f(1406.0, -2331.0);
    glVertex2f(1426.0, -2331.0);
    glVertex2f(1422, -2616);
    glVertex2f(1406, -2616);
    glColor4f(138/255.0f, 71/255.0f, 34/255.0f, 0.45);
    glVertex2f(1385, -2616);
    glVertex2f(1389, -2331.0);
    glEnd();


    //base elGanb elYmeen men el4ebbak
    glBegin(GL_POLYGON);
    glColor4f(185/255.0f, 100/255.0f, 50/255.0f, 1);
    glVertex2d(1404,-399);
    glVertex2f(1404, -300);
    glVertex2f(1472, -300);
    glVertex2d(1472,-399);
    glColor4f(214/255.0f, 125/255.0f, 62/255.0f, 1);
    glVertex2d(1472,-1050);
    glColor4f(181/255.0f, 101/255.0f, 51/255.0f, 1);
    glVertex2f(1472, -2616);
    glVertex2f(1422, -2616);
    glColor4f(214/255.0f, 125/255.0f, 62/255.0f, 1);
    glVertex2d(1410,-1050);
    glEnd();

    //elShadow elBlack fou2 elGanb elYmeen
    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.25);
    glVertex2f(1472.0, -2018.0);
    glVertex2f(1472.0, -877.0);
    glColor4f(0, 0, 0, 0.1);
    glVertex2f(1472.0, -491.0);
    glVertex2f(1440.0, -491.0);
    glVertex2f(1434.0, -492.0);
    glVertex2f(1429.0, -496.0);
    glVertex2f(1426.0, -500.0);
    glVertex2f(1424.0, -505.0);
    glVertex2f(1424.0, -729.0);
    glColor4f(0,0,0,0.25);
    glVertex2f(1434.0, -2020.0);
    glColor4f(0,0,0,0.001);
    glVertex2f(1430.0, -2215.0);
    glVertex2f(1472.0, -2215.0);
    glEnd();

    //elgloz2 el8ame2 fy elShadow
    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0.1);
    glVertex2f(1423.0, -729.0);
    glVertex2f(1438.0, -741.0);
    glVertex2f(1441.0, -773.0);
    glVertex2f(1442.0, -823.0);
    glColor4f(0,0,0,0.0);
    glVertex2f(1442.0, -910.0);
    glVertex2f(1426.0, -910.0);
    glColor4f(0, 0, 0, 0.1);
    glVertex2f(1426.0, -823.0);
    glEnd();


    //elBlack shadow beta3 elganb elYemeen men el4ebbak (elly ganboh)
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor4f(138/255.0f, 71/255.0f, 34/255.0f, 1);
    glVertex2f(1404, -300);
    glVertex2d(1422,-2008);
    glColor4f(181/255.0f, 101/255.0f, 51/255.0f, 0.5);
    glVertex2f(1422, -2616);
    glEnd();
    //light elgnab elymeen
    luminousSpot(1423.5,2195.5,5,14,true);
    luminousSpot(1424.5,2162.5,2.5,17,true);

    //elBase beta3 7awaf el4ebbak elly fou2
    glBegin(GL_POLYGON);
    glColor4f(182 / 255.0f, 100 / 255.0f, 49 / 255.0f, 1);
    glVertex2f(1174, -244);
    glVertex2f(1174, -182);
    glVertex2f(1472, -182);
    glColor4f(205 / 255.0f, 114 / 255.0f, 60 / 255.0f, 1);
    glVertex2f(1472, -244);
    glVertex2f(1472, -308);
    glVertex2f(1174, -308);
    glEnd();

    //upper light, beta3 7awaf el4ebbak elly fou2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor4f(1, 211/255.0f, 121/255.0f,0.4);
    glVertex2f(1174, -182);
    glColor4f(182 / 255.0f, 100 / 255.0f, 49 / 255.0f, 1);
    glVertex2f(1472, -182);
    glEnd();

    //elShadow elly ta7t, beta3 7awaf el4ebbak elly fou2
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor4f(138/255.0f, 71/255.0f, 34/255.0f, 1);
    glVertex2f(1472, -308);
    glVertex2f(1174, -308);
    glEnd();


    //elBase beta3 7awaf el4ebbak elly ta7t
    glBegin(GL_POLYGON);
    glColor4f(181/255.0f, 100/255.0f, 51/255.0f, 1);
    glVertex2f(1253, -2211);
    glVertex2f(1472, -2211);
    glVertex2f(1472, -2303);
    glVertex2f(1253, -2303);
    glColor4f(211/255.0f, 132/255.0f, 60/255.0f, 1);
    glVertex2f(1035, -2303);
    glVertex2f(1035, -2211);
    glEnd();

    //elLight beta3 7awaf el4ebbak elly ta7t
    glBegin(GL_LINE_LOOP);
    glColor4f(1, 211/255.0f, 121/255.0f,0.25);
    glVertex2f(1035, -2211);
    glVertex2f(1253, -2211);
    glColor4f(246/255.0f, 167/255.0f, 85/255.0f,0.15);
    glVertex2f(1472, -2211);
    glEnd();

    //luminous spots
    luminousSpot(1248,2214,40,7,true,0.2);
    luminousSpot(1245,2214,25,7,true,0.2);
    luminousSpot(1075,2214,32,6,true,0.2);
    luminousSpot(1148,2216,7,5,true,0.2);
    luminousSpot(1173,2218,18,3,true,0.2);

    glLineWidth(3);
    //elBlack shadow beta3 7awaf el4ebbak elly ta7t
    glBegin(GL_LINE_LOOP);
    glColor4f(138/255.0f, 71/255.0f, 34/255.0f, 1);
    glVertex2f(1472, -2303);
    glVertex2f(1253, -2303);
    glColor4f(138/255.0f, 71/255.0f, 34/255.0f, 0.5);
    glVertex2f(1035, -2303);
    glEnd();
    glLineWidth(1);


}
void drawBackground()
{
    //background color
    glBegin(GL_POLYGON);
    glColor4f(222/255.0f, 158/255.0f, 76/255.0f, 1);
    glVertex2f(0, -1308);
    glVertex2f(0, 0);
    glVertex2f(1472, 0);
    glVertex2f(1472, -1308);
    glVertex2f(1472, -2616);
    glColor4f(207/255.0f, 114/255.0f, 53/255.0f, 1);
    glVertex2f(0, -2616);
    glEnd();

    //ElSadow elblack fou2 elShamseyya (the triangle)
    {
        glBegin(GL_POLYGON);
        glColor4f(32/255.0f, 20/255.0f, 24/255.0f, 1);
        glVertex2f(188, 0);
        glColor4f(90/255.0f, 48/255.0f, 36/255.0f, 1);
        glVertex2f(192, -249);
        glVertex2f(647, 0);
        glEnd();
    }

    //elLine elly ganb elPipes (1)
    {
        glColor4f(222/255.0f, 150/255.0f, 74/255.0f, 1);
        glBegin(GL_POLYGON);
        glVertex2d(212.875, -1339.562);
        glVertex2d(213.000, -1333.750);
        glVertex2d(224.750, -1334.375);
        glVertex2d(228.062, -1335.000);
        glVertex2d(233.375, -1336.062);
        glVertex2d(240.000, -1337.625);
        glVertex2d(243.188, -1338.812);
        glVertex2d(243.500, -1340.625);
        glVertex2d(243.250, -1342.812);
        glVertex2d(241.750, -1345.438);
        glVertex2d(212.875, -1345.438);
        glEnd();
    }
    //elLine elly ganb elPipes (2)
    {
        glColor4d(246/255.0f, 219/255.0f, 165/255.0f, 0.08);
        glBegin(GL_POLYGON);
        glVertex2f(211.500, -1737.000);
        glVertex2f(255.250, -1736.500);
        glVertex2f(251.750, -1740.750);
        glVertex2f(247.250, -1745.500);
        glVertex2f(242.000, -1747.500);
        glVertex2f(230.000, -1749.500);
        glVertex2f(215.500, -1750.000);
        glVertex2f(211.750, -1750.000);
        glEnd();
    }
    //elLine elly ganb elPipes (3)
    {
        glLineWidth(2);
        glColor4f(205/255.0f, 119/255.0f, 56/255.0f, 1);
        glBegin(GL_POLYGON);
        glVertex2f(212.000, -2144.750);
        glVertex2f(231.750, -2154.000);
        glVertex2f(252.500, -2157.250);
        glVertex2f(269.250, -2156.250);
        glColor4f(205/255.0f, 119/255.0f, 56/255.0f, 0.5);
        glVertex2f(285.000, -2150.000);
        glEnd();
    }
    //elLine elly ganb elPipes (4)
    {
        glBegin(GL_POLYGON);
        glColor4f(176/255.0f, 95/255.0f, 44/255.0f, 0.5);
        glVertex2f(252.000, -2174.375);
        glVertex2f(244.375, -2174.000);
        glVertex2f(233.875, -2172.625);
        glVertex2f(226.375, -2170.750);
        glVertex2f(213.125, -2166.750);
        glColor4f(176/255.0f, 95/255.0f, 44/255.0f, 1);
        glVertex2f(213.500, -2178.750);
        glVertex2f(233.625, -2181.000);
        glVertex2f(255.167, -2182.167);
        glVertex2f(280.333, -2182.667);
        glColor4f(176/255.0f, 95/255.0f, 44/255.0f, 0.5);
        glVertex2f(285.667, -2182.500);
        glVertex2f(285.167, -2179.667);
        glVertex2f(281.500, -2176.500);
        glVertex2f(275.667, -2175.167);
        glVertex2f(264.750, -2174.875);
        glEnd();
    }
    //elLine elly ganb elPipes (5)
    {
        glLineWidth(3);
        glColor4f(190/255.0f, 107/255.0f, 46/255.0f, 1);
        glBegin(GL_LINE_STRIP);
        glVertex2f(208.333, -2335.000);
        glVertex2f(259.667, -2334.667);
        glColor4f(190/255.0f, 107/255.0f, 46/255.0f, 0.1);
        glVertex2f(337.667, -2333.000);
        glEnd();
    }

    //el 2 pipes elly on the left side of the image
    rightPipe();
    leftPipe();

    //shadows comp.
    {
        //elPipe el4emal
        {
            glBegin(GL_POLYGON);
            glColor4f(32/255.0f, 20/255.0f, 24/255.0f, 0.9);
            glVertex2f(0, 0);
            glVertex2f(0, -260);
            glColor4f(68/255.0f, 40/255.0f, 34/255.0f, 0.8);
            glVertex2f(85, -260);
            glColor4f(32/255.0f, 20/255.0f, 24/255.0f, 0.9);
            glVertex2f(85, 0);
            glEnd();
        }
        //elPipe elymeen
        {
            glBegin(GL_POLYGON);
            glColor4f(32/255.0f, 20/255.0f, 24/255.0f, 0.9);
            glVertex2f(85, 0);
            glVertex2f(85, -251);
            glColor4f(68/255.0f, 40/255.0f, 34/255.0f, 0.8);
            glVertex2f(201, -251);
            glColor4f(32/255.0f, 20/255.0f, 24/255.0f, 0.9);
            glVertex2f(201, 0);
            glEnd();
        }
    }

    //el4ebbak
    drawWindow();
}

void drawUmbrella()
{

    //umbrella's inner base
    {
        double vertices[][2] = {
                {0.000, -506},
                {21.000, -487},
                {49.000, -466},
                {91.000, -440},
                {143.000, -413},
                {197.000, -384},
                {235.000, -369},
                {270.000, -351},
                {310.000, -333},
                {359.000, -311},
                {433.000, -286},
                {508.000, -261},
                {555.000, -247},
                {650.000, -216},
                {673.000, -228},
                {677.000, -229},
                {679.000, -229},
                {681.000, -228},
                {682.000, -226},
                {682.000, -224},
                {681.000, -220},
                {677.000, -213},
                {675.000, -212},
                {704.000, -195},
                {742.000, -178},
                {775.000, -165},
                {824.000, -147},
                {867.000, -133},
                {900.000, -122},
                {939.000, -112},
                {1032.000, -93},
                {1070.000, -85},
                {1104.000, -80},
                {1134.000, -78},
                {1202.000, -74},
                {1244.000, -71},
                {1284.000, -68},
                {1293.000, -68},
                {1302.000, -69},
                {1306.000, -71},
                {1309.000, -71},
                {1310.000, -69},
                {1310.000, -67},
                {1286.000, -53},
                {1294.000, -50},
                {1304.000, -47},
                {1313.000, -45},
                {1322.000, -45},
                {1333.000, -47},
                {1346.000, -51},
                {1357.000, -55},
                {1383.000, -65},
                {1415.000, -79},
                {1427.000, -85},
                {1447.000, -95},
                {1471.000, -107},
                {1471.083, -115.583},
                {1467.167, -114.750},
                {1457.500, -113.000},
                {1450.000, -111.917},
                {1441.667, -111.500},
                {1434.417, -111.083},
                {1422.417, -111.667},
                {1409.250, -113.167},
                {1396.500, -117.250},
                {1376.000, -126.500},
                {1363.250, -132.750},
                {1346.000, -143.250},
                {1330.750, -154.750},
                {1317.750, -165.500},
                {1284.750, -199.750},
                {1275.000, -210.250},
                {1264.500, -221.750},
                {1248.500, -240.500},
                {1235.750, -256.250},
                {1233.000, -262.250},
                {1219.250, -283.000},
                {1200.250, -322.500},
                {1186.000, -354.500},
                {1174.500, -380.500},
                {1171.750, -389.750},
                {1167.250, -402.250},
                {1163.750, -413.250},
                {1162.000, -420.750},
                {1161.000, -429.250},
                {1159.000, -441.000},
                {1156.500, -453.500},
                {1156.333, -463.333},
                {1156.167, -472.000},
                {1155.667, -482.333},
                {1156.500, -489.000},
                {1161.833, -502.167},
                {1161.500, -504.500},
                {1157.000, -508.833},
                {1155.667, -509.167},
                {1154.333, -509.000},
                {1144.000, -501.333},
                {1142.667, -500.667},
                {1140.667, -500.833},
                {1130.000, -502.000},
                {1121.250, -503.500},
                {1113.125, -504.875},
                {1103.750, -506.625},
                {1096.375, -508.375},
                {1069.875, -516.875},
                {1038.000, -528.000},
                {1006.000, -541.500},
                {962.000, -562.000},
                {453.333, -885.500},
                {444.667, -886.833},
                {431.000, -890.500},
                {355.333, -909.000},
                {318.000, -921.000},
                {295.333, -930.333},
                {252.000, -947.000},
                {221.333, -961.000},
                {186.667, -978.333},
                {132.000, -1004.333},
                {94.000, -1024.333},
                {60.667, -1044.333},
                {32.000, -1060.333},
                {0.000, -1078.333}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
            glVertex2d(vertices[i][0], vertices[i][1]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
        {
            if (vertices[i][0]<=555)
                glColor4f(23/255.0f,17/255.0f,16/255.0f,1);
            else
                glColor4d(33/255.0f,27/255.0f,25/255.0f,1);
            glVertex2d(vertices[i][0], vertices[i][1]);
        }
        glEnd();
        glDisable(GL_STENCIL_TEST);
    }
    //umbrella's inner lignt
    {
        double vertices[][2] = {
                {1471.083, -115.583},
                {1467.167, -114.750},
                {1457.500, -113.000},
                {1450.000, -111.917},
                {1441.667, -111.500},
                {1434.417, -111.083},
                {1422.417, -111.667},
                {1409.250, -113.167},
                {1396.500, -117.250},
                {1376.000, -126.500},
                {1363.250, -132.750},
                {1346.000, -143.250},
                {1330.750, -154.750},
                {1317.750, -165.500},
                {1284.750, -199.750},
                {1275.000, -210.250},
                {1264.500, -221.750},
                {1248.500, -240.500},
                {1235.750, -256.250},
                {1233.000, -262.250},
                {1219.250, -283.000},
                {1200.250, -322.500},
                {1186.000, -354.500},
                {1174.500, -380.500},
                {1171.750, -389.750},
                {1167.250, -402.250},
                {1163.750, -413.250},
                {1162.000, -420.750},
                {1161.000, -429.250},
                {1159.000, -441.000},
                {1156.500, -453.500},
                {1156.333, -463.333},
                {1156.167, -472.000},
                {1155.667, -482.333},
                {1156.500, -489.000},
                {1161.833, -502.167},
                {1161.500, -504.500},
                {1157.000, -508.833},
                {1155.667, -509.167},
                {1154.333, -509.000},
                {1144.000, -501.333},
                {1142.667, -500.667},
                {1140.667, -500.833},
                {1130.000, -502.000},
                {1121.250, -503.500},
                {1113.125, -504.875},
                {1103.750, -506.625},
                {1096.375, -508.375},
                {1069.875, -516.875},
                {1038.000, -528.000},
                {1006.000, -541.500},
                {962.000, -562.000},
                {453.333, -885.500},
                {444.667, -886.833},
                {431.000, -890.500},
                {355.333, -909.000},
                {318.000, -921.000},
                {295.333, -930.333},
                {252.000, -947.000},
                {221.333, -961.000},
                {186.667, -978.333},
                {132.000, -1004.333},
                {94.000, -1024.333},
                {60.667, -1044.333},
                {32.000, -1060.333},
                {0.000, -1078.333},
                /*{6, -996},
                {108, -924},
                {198, -864},
                {342, -813},
                {639, -744},
                {924, -495},
                {1068, -420},
                {1107, -336},
                {1158, -225},*/
                {0,-930},
                {1263, -126},
                {1325, -97},
                {1413, -91},
                {1470, -101}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
            glVertex2d(vertices[i][0], vertices[i][1]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        glColor4d(70/255.0f,33/255.0f,26/255.0f,0.3);
        glVertex2d(642,-654);
        //VERTICES
        for (int i = 0; i < size; ++i) {
            if (i>65)
                glColor4d(70/255.0f,33/255.0f,26/255.0f,0.0);
            glVertex2dv(vertices[i]);
        }
        glVertex2dv(vertices[0]);
        glEnd();
        glDisable(GL_STENCIL_TEST);
    }


    //3asayet elUmbrella
    {
        glBegin(GL_POLYGON);
        glColor4f(25 / 225.0f, 17 / 225.0f, 16 / 225.0f, 0.8);
//        glColor4f(23/255.0f,17/255.0f,16/255.0f,0.8);
        glVertex2f(348.000, -350.500);
        glVertex2f(368.000, -390.500);

        glColor4f(25 / 225.0f, 17 / 225.0f, 16 / 225.0f, 1);
//        glColor4f(23/255.0f,17/255.0f,16/255.0f,1);
        glVertex2f(395.333, -376.333);
        glVertex2f(390.667, -358.667);
        glVertex2f(385.667, -345.333);
        glVertex2f(378.000, -331.000);
        glVertex2f(355.000, -302.333);

        glColor4f(25 / 225.0f, 17 / 225.0f, 16 / 225.0f, 0.8);
//        glColor4f(23/255.0f,17/255.0f,16/255.0f,0.8);
        glVertex2f(328.667, -315.000);

        glColor4f(25 / 225.0f, 17 / 225.0f, 16 / 225.0f, 1);
//        glColor4f(23/255.0f,17/255.0f,16/255.0f,1);
        glVertex2f(311.333, -322.333);
        glVertex2f(311.333, -342.000);
        glVertex2f(315.333, -353.667);
        glVertex2f(322.000, -372.000);
        glVertex2f(331.667, -389.333);
        glVertex2f(346.500, -404.000);

        glColor4f(25 / 225.0f, 17 / 225.0f, 16 / 225.0f, 0.8);
//        glColor4f(23/255.0f,17/255.0f,16/255.0f,0.8);
        glVertex2f(368.000, -390.500);
        glEnd();
    }
    {
        glBegin(GL_POLYGON);
        glColor4f(25 / 225.0f, 17 / 225.0f, 16 / 225.0f, 1);
        glVertex2f(400, -430);
        glVertex2f(334.000, -313.000);

        glColor4f(25 / 225.0f, 17 / 225.0f, 16 / 225.0f, 0.8);
        glVertex2f(351.000, -303.000);
        glVertex2f(483.000, -538.000);

        glColor4f(25 / 225.0f, 17 / 225.0f, 16 / 225.0f, 1);
        glVertex2f(470.000, -545.000);

        glColor4f(25 / 225.0f, 17 / 225.0f, 16 / 225.0f, 0.8);
        glVertex2f(456.000, -554.000);
        glVertex2f(312.000, -324.000);
        glEnd();

    }
    //light 3asayet elUmbrella
    {
        double vertices[][2] = {
                {377.875, -383.750},
                {380.125, -384.000},
                {392.833, -378.250},
                {394.500, -378.375},
                {396.500, -380.500},
                {402.250, -390.750},
                {402.500, -389.625},
                {402.250, -386.000},
                {395.250, -373.875},
                {394.250, -373.875},
                {377.750, -382.500}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 182, 99, 62, 1.0);

        glColor4f(70/225.0f,44/225.0f,37/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(361.562, -387.938);
        glVertex2f(358.188, -390.344);
        glVertex2f(357.906, -391.375);
        glVertex2f(358.125, -392.344);
        glVertex2f(359.000, -393.000);
        glVertex2f(360.156, -392.844);
        glVertex2f(368.938, -386.375);
        glVertex2f(369.125, -385.594);
        glVertex2f(369.000, -384.750);
        glVertex2f(368.375, -384.375);
        glVertex2f(367.219, -384.375);
        glEnd();

        glColor4f(53/255.0f,46/255.0f,43/255.0f,1);
        glPointSize(2);
        glBegin(GL_POINTS);
        glVertex2d(349,-399);
        glEnd();
    }


    //umbrella's outer base
    {
        double vertices[][2] = {
                {0.000, -506}, {21.000, -487}, {49.000, -466}, {91.000, -440}, {143.000, -413},
                {197.000, -384}, {235.000, -369}, {270.000, -351}, {310.000, -333}, {359.000, -311},
                {433.000, -286}, {508.000, -261}, {555.000, -247}, {650.000, -216}, {673.000, -228},
                {677.000, -229}, {679.000, -229}, {681.000, -228}, {682.000, -226}, {682.000, -224},
                {681.000, -220}, {677.000, -213}, {675.000, -212}, {704.000, -195}, {742.000, -178},
                {775.000, -165}, {824.000, -147}, {867.000, -133}, {900.000, -122}, {939.000, -112},
                {1032.000, -93}, {1070.000, -85}, {1104.000, -80}, {1134.000, -78}, {1202.000, -74},
                {1244.000, -71}, {1284.000, -68}, {1293.000, -68}, {1302.000, -69}, {1306.000, -71},
                {1309.000, -71}, {1310.000, -69}, {1310.000, -67}, {1286.000, -53}, {1294.000, -50},
                {1304.000, -47}, {1313.000, -45}, {1322.000, -45}, {1333.000, -47}, {1346.000, -51},
                {1357.000, -55}, {1383.000, -65}, {1415.000, -79}, {1427.000, -85}, {1447.000, -95},
                {1471.000, -107}, {1471.500, -96}, {1402.500, -62}, {1358.500, -43}, {1309.000, -19.25},
                {1267.500, -0}, {620.333, -0}, {557.000, -21}, {544.167, -25.333}, {512.333, -35.167},
                {504.500, -37.833}, {476.833, -46.833}, {452.667, -53}, {427.333, -59}, {421.667, -60.167},
                {411.000, -61.667}, {388.833, -65.667}, {373.333, -67.667}, {358.000, -68.5}, {349.000, -67.5},
                {345.250, -66.75}, {340.875, -66.375}, {338.000, -67.125}, {335.625, -68.75}, {331.875, -71},
                {325.500, -75.667}, {309.833, -87.5}, {270.333, -113}, {259.667, -121}, {240.667, -134},
                {219.667, -149.333}, {208.000, -156}, {196.667, -162.333}, {177.625, -174.625},
                {161.250, -182.875}, {152.875, -187.75}, {139.000, -195.5}, {125.750, -201.25}, {100.333, -211},
                {91.333, -214.667}, {80.333, -219.333}, {67.667, -223.333}, {36.000, -228.667},
                {29.667, -229.333}, {21.667, -230}, {0.000, -232}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
            glVertex2d(vertices[i][0], vertices[i][1]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        //VERTICES
        glColor4f(24/255.0f,23/255.0f,24/255.0f,1);
        glVertex2d(488, -128);
        for (int i = 0; i < size; ++i)
        {
            if ((vertices[i][0]<=330&&vertices[i][1]<=-72)||(vertices[i][0]<=650&&vertices[i][1]<=-215))
                glColor4f(24/255.0f,23/255.0f,24/255.0f,1);
            else
                glColor4d(74/255.0f,49/255.0f,47/255.0f,1);
            glVertex2d(vertices[i][0], vertices[i][1]);
        }
        glVertex2d(vertices[0][0], vertices[0][1]);
        glEnd();
        glDisable(GL_STENCIL_TEST);
    }

    //light under light beta3 elCurve elAwwal
    {
        double vertices[][2] = {
                {449, -100}, {459, -93}, {662, -207}, {681, -225}, {675, -229},
                {626, -203}, {606, -191}, {590, -183}, {567, -171}, {550, -162},
                {537, -153}, {518, -143}, {485, -127}, {460, -117}, {439, -109},
                {410, -100}, {440, -73}, {459, -93}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
            glVertex2d(vertices[i][0], vertices[i][1]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        //VERTICES

        for (int i = 0; i < size; ++i)
        {
            if (i==1||i>=14)
                glColor4d(74/255.0f,49/255.0f,47/255.0f,0.0);
            else
                glColor4f(242/255.0f, 181/255.0f, 113/255.0f, 0.1);
            glVertex2d(vertices[i][0], vertices[i][1]);
        }
        glEnd();
        glDisable(GL_STENCIL_TEST);
    }

    //Light awwel tania
    {
        double vertices[][2] = {
                {594.000, -172.250}, {602.250, -178.500}, {610.750, -184.750}, {619.250, -190.000},
                {629.500, -196.750}, {636.750, -201.000}, {645.750, -205.500}, {657.000, -210.250},
                {663.250, -212.750}, {668.500, -215.500}, {672.083, -220.417}, {673.208, -222.542},
                {675.167, -225.750}, {677.688, -228.125}, {679.062, -228.062}, {680.375, -228.000},
                {681.875, -226.188}, {682.250, -224.438}, {682.125, -221.625}, {680.500, -218.938},
                {677.312, -214.375}, {674.812, -211.688}, {671.312, -209.062}, {660.500, -201.250},
                {656.500, -198.875}, {648.250, -194.000}, {644.000, -191.625}, {635.500, -186.500},
                {628.625, -182.625}, {624.375, -179.625}, {620.500, -177.000}, {615.125, -173.625},
                {607.500, -169.125}, {619.250, -174.875}, {630.000, -180.250}, {640.375, -186.375},
                {657.000, -195.312}, {662.750, -199.000}, {667.250, -202.500}, {673.375, -208.000},
                {674.125, -208.125}, {674.812, -207.750}, {693.188, -190.938}, {693.438, -190.000},
                {693.312, -189.312}, {692.688, -188.750}, {672.875, -180.625}, {661.833, -176.583},
                {644.667, -171.333}, {637.167, -168.500}, {624.167, -164.167}, {614.333, -161.000},
                {600.667, -155.250}, {576.250, -144.667}, {572.750, -142.833}, {560.333, -135.833},
                {538.583, -123.750}, {530.000, -119.333}, {527.500, -117.667}, {519.333, -113.833},
                {504.833, -107.333}, {499.167, -105.000}, {490.333, -101.333}, {470.958, -93.167},
                {455.667, -87.167}, {453.833, -86.667}, {452.167, -86.500}, {451.000, -86.500},
                {449.833, -87.000}, {448.750, -88.500}, {447.833, -90.083}, {448.000, -92.333},
                {449.500, -94.250}, {452.250, -95.583}, {487.500, -113.333}, {499.875, -118.750},
                {507.125, -122.250}, {509.500, -123.375}, {515.250, -126.625}, {528.500, -136.417},
                {532.250, -138.500}, {536.000, -141.000}, {543.000, -144.500}, {554.500, -150.167},
                {572.333, -159.333}, {580.500, -163.333}, {587.167, -167.333}, {591.500, -170.333}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 242, 181, 113, 1.0);
    }
    //Light awwel tania outline
    {
        glLineWidth(1);
        glColor4f(24 / 255.0f, 23 / 255.0f, 24 / 255.0f, 1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(594.000, -172.250);
        glVertex2f(602.250, -178.500);
        glVertex2f(610.750, -184.750);
        glVertex2f(619.250, -190.000);
        glVertex2f(629.500, -196.750);
        glVertex2f(636.750, -201.000);
        glVertex2f(645.750, -205.500);
        glVertex2f(657.000, -210.250);
        glVertex2f(663.250, -212.750);
        glVertex2f(668.500, -215.500);
        glVertex2f(672.083, -220.417);
        glVertex2f(673.208, -222.542);
        glVertex2f(675.167, -225.750);
        glVertex2f(677.688, -228.125);
        glVertex2f(679.062, -228.062);
        glVertex2f(680.375, -228.000);
        glVertex2f(681.875, -226.188);
        glVertex2f(682.250, -224.438);
        glVertex2f(682.125, -221.625);
        glVertex2f(680.500, -218.938);
        glVertex2f(677.312, -214.375);
        glVertex2f(674.812, -211.688);
        glVertex2f(671.312, -209.062);
        glVertex2f(660.500, -201.250);
        glVertex2f(656.500, -198.875);
        glVertex2f(648.250, -194.000);
        glVertex2f(644.000, -191.625);
        glVertex2f(635.500, -186.500);
        glVertex2f(628.625, -182.625);
        glVertex2f(624.375, -179.625);
        glVertex2f(620.500, -177.000);
        glVertex2f(615.125, -173.625);
        glVertex2f(607.500, -169.125);
        glVertex2f(619.250, -174.875);
        glVertex2f(630.000, -180.250);
        glVertex2f(640.375, -186.375);
        glVertex2f(657.000, -195.312);
        glVertex2f(662.750, -199.000);
        glVertex2f(667.250, -202.500);
        glVertex2f(673.375, -208.000);
        glVertex2f(674.125, -208.125);
        glVertex2f(674.812, -207.750);
        glVertex2f(693.188, -190.938);
        glVertex2f(693.438, -190.000);
        glVertex2f(693.312, -189.312);
        glVertex2f(692.688, -188.750);
        glVertex2f(672.875, -180.625);
        glVertex2f(661.833, -176.583);
        glVertex2f(644.667, -171.333);
        glVertex2f(637.167, -168.500);
        glVertex2f(624.167, -164.167);
        glVertex2f(614.333, -161.000);
        glVertex2f(600.667, -155.250);
        glVertex2f(576.250, -144.667);
        glVertex2f(572.750, -142.833);
        glVertex2f(560.333, -135.833);
        glVertex2f(538.583, -123.750);
        glVertex2f(530.000, -119.333);
        glVertex2f(527.500, -117.667);
        glVertex2f(519.333, -113.833);
        glVertex2f(504.833, -107.333);
        glVertex2f(499.167, -105.000);
        glVertex2f(490.333, -101.333);
        glVertex2f(470.958, -93.167);
        glVertex2f(455.667, -87.167);
        glVertex2f(453.833, -86.667);
        glVertex2f(452.167, -86.500);
        glVertex2f(451.000, -86.500);
        glVertex2f(449.833, -87.000);
        glVertex2f(448.750, -88.500);
        glVertex2f(447.833, -90.083);
        glVertex2f(448.000, -92.333);
        glVertex2f(449.500, -94.250);
        glVertex2f(452.250, -95.583);
        glVertex2f(487.500, -113.333);
        glVertex2f(499.875, -118.750);
        glVertex2f(507.125, -122.250);
        glVertex2f(509.500, -123.375);
        glVertex2f(515.250, -126.625);
        glVertex2f(528.500, -136.417);
        glVertex2f(532.250, -138.500);
        glVertex2f(536.000, -141.000);
        glVertex2f(543.000, -144.500);
        glVertex2f(554.500, -150.167);
        glVertex2f(572.333, -159.333);
        glVertex2f(580.500, -163.333);
        glVertex2f(587.167, -167.333);
        glVertex2f(591.500, -170.333);
        glEnd();
    }

    //Light awwel tania men fou2
    {
        double vertices[][2] = {
                {344.667, -73.250},
                {340.667, -73.417},
                {338.583, -73.583},
                {336.750, -74.417},
                {314.583, -89.167},
                {313.500, -89.417},
                {312.750, -89.250},
                {312.667, -88.667},
                {312.833, -87.250},
                {337.000, -68.167},
                {338.250, -67.500},
                {340.167, -66.833},
                {342.417, -66.583},
                {345.083, -66.583},
                {347.917, -67.000},
                {371.500, -71.500},
                {385.500, -75.250},
                {394.917, -79.250},
                {395.500, -80.333},
                {394.917, -81.083},
                {393.000, -81.250},
                {389.750, -81.083},
                {354.750, -73.375},
                {352.125, -73.167},
                {349.500, -73.125}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 242, 181, 113, 1.0);
    }

    //elMiddle light fy elUmbrella
    {
        double vertices[][2] = {
                {988.500, -84.500},
                {1134.500, -67.000},
                {1140.500, -74.000},
                {1125.500, -75.500},
                {1104.000, -77.500},
                {1073.500, -81.000},
                {1036.000, -88.000},
                {999.500, -97.500}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 139, 75, 41, 0.3);
    }
    //
    {
        double vertices[][2] = {
                {543.500, -27.125},
                {623.250, -0.250},
                {969.000, -0.000},
                {1041.333, -33.333},
                {1061.000, -41.750},
                {1085.625, -51.875},
                {1109.000, -59.375},
                {1137.000, -67.000},
                {1137.250, -68.625},
                {1136.250, -69.500},
                {1100.500, -72.625},
                {1065.000, -76.875},
                {1052.250, -78.250},
                {1032.125, -81.875},
                {1007.625, -86.375},
                {1000.000, -87.833},
                {995.000, -89.000},
                {991.750, -89.125},
                {989.000, -88.875},
                {986.250, -87.875},
                {961.750, -78.625},
                {958.125, -77.250},
                {948.500, -73.750},
                {922.167, -65.833},
                {892.500, -57.000},
                {884.750, -54.250},
                {877.250, -51.500},
                {868.250, -48.250},
                {859.750, -44.500},
                {849.000, -38.250},
                {838.250, -32.250},
                {832.250, -29.250},
                {825.500, -25.500},
                {820.250, -22.000},
                {815.000, -18.500},
                {810.500, -15.750},
                {806.250, -13.000},
                {798.500, -9.750},
                {784.500, -5.750},
                {776.750, -4.500},
                {767.000, -2.583},
                {755.083, -1.083},
                {747.417, -0.250},
                {673.833, -0.333},
                {665.333, -1.500},
                {639.833, -6.000},
                {613.167, -11.833},
                {601.833, -14.500},
                {568.750, -21.750}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 240, 187, 111, 1.0);
    }
    //elMiddle light fy elUmbrella outlines
    {
        glLineWidth(1);
        glColor4f(24/255.0f,23/255.0f,24/255.0f,0.7);
        glBegin(GL_LINE_LOOP);
        glVertex2f(543.500, -27.125);
        glVertex2f(623.250, -0.250);
        glVertex2f(969.000, -0.000);
        glVertex2f(1041.333, -33.333);
        glVertex2f(1061.000, -41.750);
        glVertex2f(1085.625, -51.875);
        glVertex2f(1109.000, -59.375);
        glVertex2f(1137.000, -67.000);
        glVertex2f(1137.250, -68.625);
        glVertex2f(1136.250, -69.500);
        glVertex2f(1100.500, -72.625);
        glVertex2f(1065.000, -76.875);
        glVertex2f(1052.250, -78.250);
        glVertex2f(1032.125, -81.875);
        glVertex2f(1007.625, -86.375);
        glVertex2f(1000.000, -87.833);
        glVertex2f(995.000, -89.000);
        glVertex2f(991.750, -89.125);
        glVertex2f(989.000, -88.875);
        glVertex2f(986.250, -87.875);
        glVertex2f(961.750, -78.625);
        glVertex2f(958.125, -77.250);
        glVertex2f(948.500, -73.750);
        glVertex2f(922.167, -65.833);
        glVertex2f(892.500, -57.000);
        glVertex2f(884.750, -54.250);
        glVertex2f(877.250, -51.500);
        glVertex2f(868.250, -48.250);
        glVertex2f(859.750, -44.500);
        glVertex2f(849.000, -38.250);
        glVertex2f(838.250, -32.250);
        glVertex2f(832.250, -29.250);
        glVertex2f(825.500, -25.500);
        glVertex2f(820.250, -22.000);
        glVertex2f(815.000, -18.500);
        glVertex2f(810.500, -15.750);
        glVertex2f(806.250, -13.000);
        glVertex2f(798.500, -9.750);
        glVertex2f(784.500, -5.750);
        glVertex2f(776.750, -4.500);
        glVertex2f(767.000, -2.583);
        glVertex2f(755.083, -1.083);
        glVertex2f(747.417, -0.250);
        glVertex2f(673.833, -0.333);
        glVertex2f(665.333, -1.500);
        glVertex2f(639.833, -6.000);
        glVertex2f(613.167, -11.833);
        glVertex2f(601.833, -14.500);
        glVertex2f(568.750, -21.750);
        glEnd();

    }

    //A'5er light base (elLight el8ame2 elly men ta7t)
    {
        double vertices[][2] = {
                {1286.000, -49.667},
                {1282.667, -52.000},
                {1298.333, -62.000},
                {1309.667, -54.000},
                {1320.667, -52.000},
                {1334.667, -53.333},
                {1349.000, -58.000},
                {1365.333, -65.333},
                {1397.000, -77.667},
                {1424.000, -89.667},
                {1450.667, -96.667},
                {1435.667, -87.667},
                {1328.333, -40.667},
                {1317.667, -41.333},
                {1296.000, -44.333}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 139, 75, 41, 0.6);
    }
    //A'5er light base
    {
        double vertices[][2] = {
                {1236.000, -43.625},
                {1234.125, -42.625},
                {1233.625, -40.750},
                {1233.375, -39.750},
                {1200.125, -23.000},
                {1171.750, -9.250},
                {1150.333, -0.000},
                {1164.417, -0.042},
                {1186.333, -11.333},
                {1168.250, -0.083},
                {1266.167, -0.167},
                {1333.750, -32.000},
                {1363.000, -46.000},
                {1397.750, -61.000},
                {1441.750, -82.250},
                {1471.625, -97.125},
                {1471.625, -106.625},
                {1422.875, -82.500},
                {1418.750, -80.500},
                {1414.000, -78.000},
                {1409.500, -76.000},
                {1402.125, -72.750},
                {1377.625, -62.250},
                {1366.125, -57.875},
                {1345.750, -50.000},
                {1334.000, -46.500},
                {1327.875, -45.000},
                {1322.500, -44.250},
                {1320.375, -44.000},
                {1316.000, -43.875},
                {1312.750, -44.250},
                {1306.875, -45.625},
                {1294.250, -49.125},
                {1287.625, -51.000},
                {1286.000, -50.625},
                {1284.875, -50.000},
                {1246.750, -34.500},
                {1241.000, -31.750},
                {1234.500, -28.750},
                {1228.000, -25.750},
                {1214.500, -19.750},
                {1249.750, -36.250},
                {1264.750, -42.750},
                {1280.000, -49.750},
                {1293.750, -58.000},
                {1303.250, -63.750},
                {1309.250, -68.250},
                {1309.750, -70.250},
                {1308.250, -71.000},
                {1304.250, -69.750},
                {1294.250, -66.250},
                {1272.500, -58.500},
                {1252.750, -50.250}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 293, 189, 112, 1.0);
    }
    //A'5er light base
    {
        double vertices[][2] =
                {
                        {1129.000, -0.000},
                        {1142.250, -4.500},
                        {1168.250, -14.250},
                        {1188.000, -23.250},
                        {1223.250, -39.000},
                        {1249.750, -49.500},
                        {1252.333, -44.333},
                        {1159.000, -0.000}
                };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 117, 56, 27, 0.5);
    }

    //A'5er light outline
    {
        glColor4f(0/225.0f,0/225.0f,0/225.0f,0.4f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(1129.000, -0.000);
        glVertex2f(1142.250, -4.500);
        glVertex2f(1168.250, -14.250);
        glVertex2f(1188.000, -23.250);
        glVertex2f(1223.250, -39.000);
        glColor4f(114/225.0f,50/225.0f,27/225.0f,0.1f);
        glVertex2f(1249.750, -49.500);
        glEnd();

        glColor4f(0/225.0f,0/225.0f,0/225.0f,0.4f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(1236.000, -43.625);
        glVertex2f(1234.125, -42.625);
        glVertex2f(1233.625, -40.750);
        glVertex2f(1233.375, -39.750);
        glVertex2f(1200.125, -23.000);
        glVertex2f(1171.750, -9.250);
        glVertex2f(1150.333, -0.000);
        glVertex2f(1164.417, -0.042);
        glVertex2f(1186.333, -11.333);
        glVertex2f(1168.250, -0.083);
        glVertex2f(1266.167, -0.167);
        glVertex2f(1333.750, -32.000);
        glVertex2f(1363.000, -46.000);
        glVertex2f(1397.750, -61.000);
        glVertex2f(1441.750, -82.250);
        glVertex2f(1471.625, -97.125);
        glVertex2f(1471.625, -106.625);
        glVertex2f(1422.875, -82.500);
        glVertex2f(1418.750, -80.500);
        glVertex2f(1414.000, -78.000);
        glVertex2f(1409.500, -76.000);
        glVertex2f(1402.125, -72.750);
        glVertex2f(1377.625, -62.250);
        glVertex2f(1366.125, -57.875);
        glVertex2f(1345.750, -50.000);
        glVertex2f(1334.000, -46.500);
        glVertex2f(1327.875, -45.000);
        glVertex2f(1322.500, -44.250);
        glVertex2f(1320.375, -44.000);
        glVertex2f(1316.000, -43.875);
        glVertex2f(1312.750, -44.250);
        glVertex2f(1306.875, -45.625);
        glVertex2f(1294.250, -49.125);
        glVertex2f(1287.625, -51.000);
        glVertex2f(1286.000, -50.625);
        glVertex2f(1284.875, -50.000);
        glVertex2f(1246.750, -34.500);
        glVertex2f(1241.000, -31.750);
        glVertex2f(1234.500, -28.750);
        glVertex2f(1228.000, -25.750);
        glVertex2f(1214.500, -19.750);
        glVertex2f(1249.750, -36.250);
        glVertex2f(1264.750, -42.750);
        glVertex2f(1280.000, -49.750);
        glVertex2f(1293.750, -58.000);
        glVertex2f(1303.250, -63.750);
        glVertex2f(1309.250, -68.250);
        glVertex2f(1309.750, -70.250);
        glVertex2f(1308.250, -71.000);
        glVertex2f(1304.250, -69.750);
        glVertex2f(1294.250, -66.250);
        glVertex2f(1272.500, -58.500);
        glVertex2f(1252.750, -50.250);
        glEnd();

    }
    //umbrella's inner outline
    {
        glLineWidth(1);
        glColor4f(0, 0, 0, 1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(0, -506);
        glVertex2f(21, -487);
        glVertex2f(49, -466);
        glVertex2f(91, -440);
        glVertex2f(143, -413);
        glVertex2f(197, -384);
        glVertex2f(235, -369);
        glVertex2f(270, -351);
        glVertex2f(310, -333);
        glVertex2f(359, -311);
        glVertex2f(433, -286);
        glVertex2f(508, -261);
        glVertex2f(555, -247);
        glVertex2f(650, -216);
        glVertex2f(673, -228);
        glVertex2f(677, -229);
        glVertex2f(679, -229);
        glVertex2f(681, -228);
        glVertex2f(682, -226);
        glVertex2f(682, -224);
        glVertex2f(681, -220);
        glVertex2f(677, -213);
        glVertex2f(675, -212);
        glVertex2f(704, -195);
        glVertex2f(742, -178);
        glVertex2f(775, -165);
        glVertex2f(824, -147);
        glVertex2f(867, -133);
        glVertex2f(900, -122);
        glVertex2f(939, -112);
        glVertex2f(1032, -93);
        glVertex2f(1070, -85);
        glVertex2f(1104, -80);
        glVertex2f(1134, -78);
        glVertex2f(1202, -74);
        glVertex2f(1244, -71);
        glVertex2f(1284, -68);
        glVertex2f(1293, -68);
        glVertex2f(1302, -69);
        glVertex2f(1306, -71);
        glVertex2f(1309, -71);
        glVertex2f(1310, -69);
        glVertex2f(1310, -67);
        glVertex2f(1286, -53);
        glVertex2f(1294, -50);
        glVertex2f(1304, -47);
        glVertex2f(1313, -45);
        glVertex2f(1322, -45);
        glVertex2f(1333, -47);
        glVertex2f(1346, -51);
        glVertex2f(1357, -55);
        glVertex2f(1383, -65);
        glVertex2f(1415, -79);
        glVertex2f(1427, -85);
        glVertex2f(1447, -95);
        glVertex2f(1471, -107);
        glVertex2f(1471.083, -115.583);
        glVertex2f(1467.167, -114.750);
        glVertex2f(1457.500, -113.000);
        glVertex2f(1450.000, -111.917);
        glVertex2f(1441.667, -111.500);
        glVertex2f(1434.417, -111.083);
        glVertex2f(1422.417, -111.667);
        glVertex2f(1409.250, -113.167);
        glVertex2f(1396.500, -117.250);
        glVertex2f(1376.000, -126.500);
        glVertex2f(1363.250, -132.750);
        glVertex2f(1346.000, -143.250);
        glVertex2f(1330.750, -154.750);
        glVertex2f(1317.750, -165.500);
        glVertex2f(1284.750, -199.750);
        glVertex2f(1275.000, -210.250);
        glVertex2f(1264.500, -221.750);
        glVertex2f(1248.500, -240.500);
        glVertex2f(1235.750, -256.250);
        glVertex2f(1233.000, -262.250);
        glVertex2f(1219.250, -283.000);
        glVertex2f(1200.250, -322.500);
        glVertex2f(1186.000, -354.500);
        glVertex2f(1174.500, -380.500);
        glVertex2f(1171.750, -389.750);
        glVertex2f(1167.250, -402.250);
        glVertex2f(1163.750, -413.250);
        glVertex2f(1162.000, -420.750);
        glVertex2f(1161.000, -429.250);
        glVertex2f(1159.000, -441.000);
        glVertex2f(1156.500, -453.500);
        glVertex2f(1156.333, -463.333);
        glVertex2f(1156.167, -472.000);
        glVertex2f(1155.667, -482.333);
        glVertex2f(1156.500, -489.000);
        glVertex2f(1161.833, -502.167);
        glVertex2f(1161.500, -504.500);
        glVertex2f(1157.000, -508.833);
        glVertex2f(1155.667, -509.167);
        glVertex2f(1154.333, -509.000);
        glVertex2f(1144.000, -501.333);
        glVertex2f(1142.667, -500.667);
        glVertex2f(1140.667, -500.833);
        glVertex2f(1130.000, -502.000);
        glVertex2f(1121.250, -503.500);
        glVertex2f(1113.125, -504.875);
        glVertex2f(1103.750, -506.625);
        glVertex2f(1096.375, -508.375);
        glVertex2f(1069.875, -516.875);
        glVertex2f(1038.000, -528.000);
        glVertex2f(1006.000, -541.500);
        glVertex2f(962.000, -562.000);
        glVertex2f(453.333, -885.500);
        glVertex2f(444.667, -886.833);
        glVertex2f(431.000, -890.500);
        glVertex2f(355.333, -909.000);
        glVertex2f(318.000, -921.000);
        glVertex2f(295.333, -930.333);
        glVertex2f(252.000, -947.000);
        glVertex2f(221.333, -961.000);
        glVertex2f(186.667, -978.333);
        glVertex2f(132.000, -1004.333);
        glVertex2f(94.000, -1024.333);
        glVertex2f(60.667, -1044.333);
        glVertex2f(32.000, -1060.333);
        glVertex2f(0.000, -1078.333);
        glEnd();
    }
    //umbrella's outer outline
    {
        glColor4f(0, 0, 0, 1);
        glLineWidth(1);
        glBegin(GL_LINE_STRIP);
        glVertex2f(1471.500, -96.000);
        glVertex2f(1402.500, -62.000);
        glVertex2f(1358.500, -43.000);
        glVertex2f(1309.000, -19.250);
        glVertex2f(1267.500, 0.000);
        glVertex2f(620.333, 0.000);
        glVertex2f(557.000, -21.000);
        glVertex2f(544.167, -25.333);
        glVertex2f(512.333, -35.167);
        glVertex2f(504.500, -37.833);
        glVertex2f(476.833, -46.833);
        glVertex2f(452.667, -53.000);
        glVertex2f(427.333, -59.000);
        glVertex2f(421.667, -60.167);
        glVertex2f(411.000, -61.667);
        glVertex2f(388.833, -65.667);
        glVertex2f(373.333, -67.667);
        glVertex2f(358.000, -68.500);
        glVertex2f(349.000, -67.500);
        glVertex2f(345.250, -66.750);
        glVertex2f(340.875, -66.375);
        glVertex2f(338.000, -67.125);
        glVertex2f(335.625, -68.750);
        glVertex2f(331.875, -71.000);
        glVertex2f(325.500, -75.667);
        glVertex2f(309.833, -87.500);
        glVertex2f(270.333, -113.000);
        glVertex2f(259.667, -121.000);
        glVertex2f(240.667, -134.000);
        glVertex2f(219.667, -149.333);
        glVertex2f(208.000, -156.000);
        glVertex2f(196.667, -162.333);
        glVertex2f(177.625, -174.625);
        glVertex2f(161.250, -182.875);
        glVertex2f(152.875, -187.750);
        glVertex2f(139.000, -195.500);
        glVertex2f(125.750, -201.250);
        glVertex2f(100.333, -211.000);
        glVertex2f(91.333, -214.667);
        glVertex2f(80.333, -219.333);
        glVertex2f(67.667, -223.333);
        glVertex2f(36.000, -228.667);
        glVertex2f(29.667, -229.333);
        glVertex2f(21.667, -230.000);
        glVertex2f(0.000, -232.000);
        glEnd();


        glBegin(GL_LINE_STRIP);
        glVertex2f(361.333, -87.000);
        glVertex2f(391.667, -95.000);
        glVertex2f(407.000, -99.667);
        glVertex2f(427.667, -104.667);
        glVertex2f(437.667, -108.667);
        glVertex2f(461.000, -117.500);
        glVertex2f(479.000, -124.500);
        glVertex2f(501.500, -134.000);
        glVertex2f(518.500, -142.500);
        glVertex2f(546.500, -156.000);
        glVertex2f(662.500, -221.500);
        glVertex2f(667.250, -224.500);
        glEnd();

        glColor4f(0, 0, 0, 0.8);
        glBegin(GL_LINE_STRIP);
        glVertex2f(357.500, -68.500);
        glVertex2f(382.000, -74.000);
        glVertex2f(388.500, -76.250);
        glVertex2f(394.500, -79.000);
        glVertex2f(397.750, -80.750);
        glVertex2f(402.500, -83.000);
        glVertex2f(415.750, -87.250);
        glVertex2f(444.500, -95.000);
        glColor4d(74 / 255.0f, 49 / 255.0f, 47 / 255.0f, 1);
        glVertex2f(454.500, -98.000);
        glEnd();
    }


    //base elket3a ela5era men el3asaya
    {
        double vertices[][2] = {
                {1053.500, -1435.333},
                {1057.333, -1441.667},
                {1054.500, -1443.667},
                {1054.000, -1446.500},
                {1054.500, -1450.500},
                {1058.500, -1459.500},
                {1062.333, -1467.167},
                {1066.000, -1471.667},
                {1170.000, -1632.333},
                {1174.000, -1645.250},
                {1177.750, -1654.000},
                {1181.750, -1661.500},
                {1184.750, -1666.250},
                {1205.125, -1799.875},
                {1206.833, -1804.667},
                {1210.500, -1810.167},
                {1216.000, -1816.833},
                {1224.833, -1825.167},
                {1229.667, -1829.000},
                {1235.000, -1832.750},
                {1240.938, -1836.312},
                {1247.833, -1840.333},
                {1255.417, -1843.917},
                {1261.000, -1846.333},
                {1268.083, -1848.750},
                {1277.000, -1851.167},
                {1282.208, -1851.792},
                {1287.375, -1852.083},
                {1297.250, -1852.083},
                {1303.917, -1851.667},
                {1311.583, -1849.833},
                {1315.500, -1847.417},
                {1318.917, -1844.750},
                {1319.312, -1842.812},
                {1319.188, -1842.000},
                {1318.438, -1841.750},
                {1317.125, -1841.125},
                {1316.938, -1840.688},
                {1317.062, -1839.688},
                {1317.500, -1838.312},
                {1324.375, -1823.188},
                {1327.875, -1813.875},
                {1329.125, -1810.000},
                {1330.625, -1805.500},
                {1331.125, -1802.000},
                {1331.500, -1796.125},
                {1331.250, -1789.125},
                {1330.375, -1786.125},
                {1329.750, -1784.250},
                {1329.875, -1782.875},
                {1331.625, -1781.500},
                {1332.625, -1780.625},
                {1333.250, -1777.250},
                {1332.500, -1775.333},
                {1331.417, -1774.167},
                {1329.500, -1771.667},
                {1326.333, -1768.583},
                {1324.500, -1766.833},
                {1230.125, -1629.375},
                {1229.312, -1628.062},
                {1225.500, -1625.750},
                {1220.188, -1622.062},
                {1207.667, -1609.167},
                {1139.083, -1472.333},
                {1137.917, -1469.917},
                {1135.500, -1466.500},
                {1132.250, -1462.750},
                {1124.500, -1456.083},
                {1118.417, -1450.000},
                {1114.417, -1444.333},
                {1112.167, -1439.750},
                {1109.833, -1435.583},
                {1106.333, -1431.750},
                {1102.083, -1427.917},
                {1098.417, -1425.583},
                {1093.833, -1422.500},
                {1091.167, -1421.000},
                {1090.000, -1420.250},
                {1081.562, -1424.750},
                {1080.083, -1422.833},
                {1078.344, -1420.281},
                {1077.250, -1418.667}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        // drawConcavePolygon(vertices, size, 136, 73, 34);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_KEEP);

        glBegin(GL_POLYGON);
        for (int i = 0; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1) (check if it inside the polygon)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        for (int i = 0; i < size; ++i) {
            /*if (i<=7||i>=63)
                glColor4d(136/255.0f,73/255.0f,34/255.0f,1);
            else*/
            glColor4d(92/255.0f,39/255.0f,17/255.0f,1);
            glVertex2dv(vertices[i]);
        }
        glEnd();
        glDisable(GL_STENCIL_TEST);

    }
    //base el3asaya
    {
        double vertices[][2] = {
                {749.667, -888.667},
                {781.000, -935.333},
                {804.000, -972.667},
                {818.000, -996.667},
                {836.000, -1026.000},
                {852.333, -1051.333},
                {864.667, -1072.000},
                {876.667, -1089.000},
                {879.667, -1095.333},
                {891.667, -1116.000},
                {934.333, -1185.000},
                {1078.500, -1424.000},
                {1071.000, -1427.500},
                {1064.000, -1431.500},
                {1057.000, -1438.000},
                {1056.000, -1439.000},
                {1008.000, -1362.000},
                {899.000, -1183.000},
                {853.000, -1120.500},
                {835.000, -1072.667},
                {752.333, -945.667},
                {725.500, -897.500}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 136, 73, 34);
        drawConcavePolygon(vertices, size, 92, 39, 17,0.5);
    }
    //elTmweeh beta3 light el3asaya
    {
        double vertices[][2] = {
                {896.500, -1134.500},
                {878.500, -1112.500},
                {849.500, -1097.000},
                {865.000, -1131.500},
                {891.500, -1166.500},
                {1031.000, -1393.000},
                {1032.500, -1381.500},
                {1033.500, -1361.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 252, 177, 89,0.1);
    }
    // light el3asaya
    {
        double vertices[][2] = {
                {1071.250, -1424.083},
                {1073.333, -1422.000},
                {1073.167, -1420.000},
                {1072.000, -1416.833},
                {1048.333, -1376.333},
                {1010.500, -1313.000},
                {989.833, -1279.000},
                {965.125, -1238.000},
                {956.875, -1223.625},
                {882.500, -1106.250},
                {878.750, -1101.000},
                {865.750, -1087.500},
                {861.500, -1083.500},
                {857.750, -1080.750},
                {849.750, -1071.000},

                {854.250, -1085.500},
                {862.250, -1101.250},
                {868.500, -1110.250},
                {896.500, -1145.250},
                {914.000, -1169.000},
                {917.750, -1177.250},
                {929.750, -1197.750},
                {1065.750, -1422.750},
                {1068.083, -1423.917}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_KEEP);

        glBegin(GL_POLYGON);
        for (int i = 0; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1) (check if it inside the polygon)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        for (int i = 0; i < size; ++i) {
            if (i<=14)
                glColor4d(240/255.0f,151/255.0f,74/255.0f,1);
            else
                glColor4d(253/255.0f,178/255.0f,89/255.0f,1);
            glVertex2dv(vertices[i]);
        }
        glEnd();
        glDisable(GL_STENCIL_TEST);
    }
    //light elgoz2 elly 3and elHands men el3asaya
    {
        //the horizontal line
        {
            double vertices[][2] = {
                    {1069.500, -1429.250},
                    {1071.333, -1431.000},
                    {1073.417, -1431.333},
                    {1078.250, -1429.417},
                    {1084.083, -1426.833},
                    {1090.500, -1423.167},
                    {1089.917, -1422.500},
                    {1088.000, -1422.750},
                    {1086.333, -1423.250},
                    {1077.083, -1427.250},
                    {1073.417, -1428.250}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 175, 96, 45,1,true,169,92,41);
        }
        //elLight elly ta7t elLine
        {
            double vertices[][2] = {
                    {1085.833, -1426.667},
                    {1077.958, -1430.917},
                    {1089.292, -1446.708},
                    {1094.167, -1446.750},
                    {1106.625, -1463.812},
                    {1108.000, -1466.625},
                    {1110.062, -1470.250},
                    {1111.812, -1472.688},
                    {1114.500, -1475.062},
                    {1117.125, -1476.312},
                    {1121.625, -1477.750},
                    {1122.531, -1477.688},
                    {1122.688, -1477.312},
                    {1122.188, -1476.438},
                    {1117.688, -1472.219},
                    {1115.812, -1470.250},
                    {1114.344, -1467.938},
                    {1114.958, -1466.583},
                    {1119.208, -1463.042},
                    {1119.958, -1462.417},
                    {1121.667, -1462.333},
                    {1123.000, -1463.083},
                    {1127.500, -1467.375},
                    {1131.167, -1471.417},
                    {1132.167, -1473.417},
                    {1132.500, -1475.667},
                    {1134.417, -1475.000},
                    {1136.583, -1472.917},
                    {1136.583, -1470.750},
                    {1134.688, -1467.188},
                    {1132.750, -1465.438},
                    {1130.812, -1463.562},
                    {1129.062, -1462.438},
                    {1127.125, -1461.562},
                    {1125.188, -1459.938},
                    {1122.062, -1455.875},
                    {1117.500, -1450.688},
                    {1112.812, -1444.125},
                    {1111.458, -1441.875},
                    {1110.208, -1439.167},
                    {1108.500, -1436.042},
                    {1107.792, -1435.375},
                    {1102.958, -1438.417},
                    {1101.792, -1438.417},
                    {1101.208, -1438.083},
                    {1101.208, -1437.458},
                    {1101.583, -1436.792},
                    {1102.917, -1435.750},
                    {1105.167, -1434.708},
                    {1105.875, -1434.250},
                    {1103.833, -1431.625},
                    {1101.750, -1429.833},
                    {1098.417, -1427.208},
                    {1093.062, -1424.062},
                    {1091.750, -1423.562}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 245, 162, 77,1,true,208,115,52);
        }
        //elLight elly been elHands
        {
            double vertices[][2] = {
                    {1198.833, -1617.083},
                    {1209.417, -1612.750},
                    {1211.917, -1615.042},
                    {1216.167, -1620.000},
                    {1220.667, -1624.250},
                    {1226.417, -1628.083},
                    {1229.417, -1630.000},
                    {1220.167, -1642.000},
                    {1217.333, -1643.917},
                    {1213.917, -1645.500},
                    {1210.583, -1643.833},
                    {1207.542, -1640.208},
                    {1204.583, -1635.917},
                    {1202.667, -1631.667},
                    {1200.812, -1626.938},
                    {1199.000, -1622.000}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 224, 139, 59);
        }
        //elgoz2 ela5eer
        {
            //line
            {
                glLineWidth(1);
                glBegin(GL_LINE_STRIP);
                glColor4f(156/255.0f, 102/255.0f, 60/255.0f, 1);
                glVertex2f(1291.062, -1781.188);
                glVertex2f(1293.250, -1779.062);
                glVertex2f(1295.625, -1777.188);
                glColor4f(156/255.0f, 102/255.0f, 60/255.0f, 0.5);
                glVertex2f(1298.875, -1775.062);
                glColor4f(156/255.0f, 102/255.0f, 60/255.0f, 0.1);
                glVertex2f(1303.938, -1771.938);
                glVertex2f(1307.562, -1770.500);
                glEnd();
            }
            //elCurve elly ganb elline
            {
                double vertices[][2] = {
                        {1306.750, -1770.438},
                        {1310.594, -1769.781},
                        {1314.781, -1769.594},
                        {1317.812, -1769.906},
                        {1320.083, -1770.667},
                        {1321.750, -1772.125},
                        {1322.438, -1772.812},
                        {1324.125, -1774.812},
                        {1325.750, -1776.625},
                        {1327.562, -1776.938},
                        {1329.312, -1776.875},
                        {1330.188, -1775.938},
                        {1330.250, -1774.625},
                        {1329.562, -1773.125},
                        {1327.688, -1770.562},
                        {1325.375, -1768.000},
                        {1324.656, -1767.188},
                        {1324.125, -1766.906},
                        {1314.625, -1766.875},
                        {1312.625, -1767.562},
                        {1310.625, -1768.375},
                        {1308.938, -1769.188},
                        {1307.812, -1769.688}
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                drawConcavePolygon(vertices, size, 156, 102, 60,0.1,true,189,106,49);
            }
            //elPoint elly ganb
            {
                glPointSize(1);
                glBegin(GL_POINTS);
                glColor4f(142/255.0f, 91/255.0f, 58/255.0f, 1);
                glVertex2f(1310, -1785);
                glEnd();
            }
            //elLine elly fou2 elganb el4emal
            {
                glLineWidth(1);
                glBegin(GL_POLYGON);
                glColor4f(122/255.0f, 51/255.0f, 16/255.0f, 1);
                glVertex2f(1244.375, -1800.500);
                glColor4f(122/255.0f, 51/255.0f, 16/255.0f, 0.5);
                glVertex2f(1249.375, -1801.125);
                glColor4f(191/255.0f, 108/255.0f, 53/255.0f, 0.5);
                glVertex2f(1253.625, -1800.625);
                glVertex2f(1258.375, -1798.500);
                glVertex2f(1262.625, -1796.375);
                glVertex2f(1265.250, -1794.125);
                glEnd();
            }
            //elganb el4emal
            {
                double vertices[][2] = {
                        {1220.750, -1806.625},
                        {1227.125, -1813.625},
                        {1232.500, -1818.375},
                        {1237.750, -1822.625},
                        {1243.250, -1826.250},
                        {1249.750, -1829.750},
                        {1259.125, -1832.750},
                        {1264.500, -1833.750},
                        {1273.000, -1834.875},
                        {1281.125, -1835.000},
                        {1288.375, -1834.250},
                        {1292.500, -1832.875},
                        {1290.125, -1830.625},
                        {1285.625, -1827.625},
                        {1280.250, -1824.625},
                        {1276.875, -1822.875},
                        {1273.500, -1821.125},
                        {1270.000, -1820.500},
                        {1267.500, -1820.500},
                        {1263.875, -1820.000},
                        {1260.750, -1818.125},
                        {1258.125, -1816.500},
                        {1255.375, -1813.750},
                        {1254.875, -1812.375},
                        {1259.125, -1815.625},
                        {1262.000, -1816.875},
                        {1265.000, -1817.625},
                        {1267.250, -1817.750},
                        {1269.750, -1817.125},
                        {1272.375, -1814.750},
                        {1277.875, -1807.625},
                        {1281.875, -1801.625},
                        {1284.125, -1796.500},
                        {1285.250, -1790.875},
                        {1285.375, -1786.500},
                        {1285.250, -1783.875},
                        {1282.625, -1785.875},
                        {1280.250, -1787.625},
                        {1275.250, -1789.375},
                        {1272.250, -1790.750},
                        {1269.875, -1792.875},
                        {1268.125, -1796.000},
                        {1267.375, -1799.250},
                        {1266.750, -1801.750},
                        {1264.375, -1801.875},
                        {1262.375, -1801.875},
                        {1259.250, -1802.875},
                        {1256.625, -1804.375},
                        {1253.750, -1805.375},
                        {1249.000, -1807.875},
                        {1246.375, -1809.125},
                        {1243.375, -1810.125},
                        {1239.875, -1810.500},
                        {1235.875, -1810.500},
                        {1232.125, -1810.125},
                        {1228.750, -1809.750},
                        {1225.125, -1808.375}
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                drawConcavePolygon(vertices, size, 240, 149, 72,1,true,229,140,63);
            }
            //elShadow beta3 elganb el4emal
            {
                double vertices[][2] = {
                        {1266.500, -1802.750},
                        {1272.875, -1812.875},
                        {1276.250, -1809.125},
                        {1278.750, -1805.125},
                        {1281.625, -1799.125},
                        {1283.875, -1791.375},
                        {1284.750, -1787.000},
                        {1279.125, -1789.375},
                        {1273.625, -1791.125},
                        {1271.250, -1793.125},
                        {1268.750, -1795.875},
                        {1267.750, -1800.875}
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                drawConcavePolygon(vertices, size, 199, 116, 52,0.8);
            }
        }
    }

}

void violetMouse()
{
    //mouse light
    {
        glColor4f(249/225.0f,198/225.0f,135/225.0f,0.3f);
        glBegin(GL_POLYGON);
        glVertex2f(852.417, -853.583);
        glVertex2f(860.500, -853.750);
        glVertex2f(865.333, -846.750);
        glVertex2f(859.083, -843.000);
        glEnd();


        glColor4f(249/225.0f,198/225.0f,135/225.0f,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(863.833, -843.333);
        glVertex2f(862.417, -850.417);
        glVertex2f(862.167, -849.000);
        glVertex2f(861.833, -847.167);
        glVertex2f(861.083, -846.333);
        glVertex2f(859.917, -845.333);
        glVertex2f(859.083, -845.000);
        glVertex2f(859.000, -843.750);
        glVertex2f(859.750, -841.083);
        glVertex2f(861.250, -838.583);
        glVertex2f(862.250, -836.583);
        glVertex2f(862.833, -835.083);
        glVertex2f(866.000, -837.417);
        glVertex2f(867.417, -839.167);
        glVertex2f(868.333, -841.333);
        glVertex2f(868.667, -843.333);
        glVertex2f(867.750, -845.333);
        glVertex2f(866.500, -846.750);
        glVertex2f(864.000, -849.417);
        glVertex2f(862.500, -850.250);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(852.250, -854.167);
        glVertex2f(860.250, -854.167);
        glVertex2f(856.333, -860.167);
        glVertex2f(855.417, -860.833);
        glVertex2f(854.333, -861.000);
        glVertex2f(852.750, -861.000);
        glVertex2f(851.083, -860.667);
        glVertex2f(850.417, -858.833);
        glVertex2f(850.333, -857.250);
        glVertex2f(850.250, -856.083);
        glEnd();


    }
    //mouse outline
    {
        glLineWidth(1);
        glBegin(GL_LINE_STRIP);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 0.0f);
        glVertex2f(816.000, -841.500);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 1.0f);
        glVertex2f(820.750, -838.250);
        glVertex2f(822.875, -836.875);
        glVertex2f(827.500, -834.875);
        glVertex2f(831.375, -833.500);
        glVertex2f(836.375, -832.375);
        glVertex2f(840.375, -831.750);
        glVertex2f(844.250, -831.125);
        glVertex2f(847.500, -831.000);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 0.0f);
        glVertex2f(851.875, -830.750);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 0.0f);
        glVertex2f(854.833, -834.083);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 1.0f);
        glVertex2f(856.417, -832.667);
        glVertex2f(857.833, -831.500);
        glVertex2f(859.083, -831.000);
        glVertex2f(860.667, -830.583);
        glVertex2f(862.583, -831.667);
        glVertex2f(864.167, -833.417);
        glVertex2f(867.000, -836.917);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 0.0f);
        glVertex2f(868.667, -839.250);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 1.0f);
        glVertex2f(845.500, -854.833);
        glVertex2f(850.000, -854.833);
        glVertex2f(852.500, -853.833);
        glVertex2f(853.875, -853.250);
        glVertex2f(855.875, -853.062);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 0.0f);
        glVertex2f(858.688, -853.062);
        glEnd();
    }
}
void violetNose()
{
    //nose light
    {
        double vertices[][2] = {
                {861.333, -712.250},
                {862.000, -717.917},
                {863.667, -723.167},
                {867.583, -729.500},
                {873.583, -737.417},
                {880.917, -745.500},
                {889.667, -754.833},
                {895.250, -759.917},
                {895.583, -761.500},
                {895.583, -763.417},
                {894.667, -765.833},
                {888.667, -774.417},
                {877.917, -786.917},
                {876.750, -789.583},
                {876.333, -790.500},
                {875.917, -793.583},
                {875.583, -797.833},
                {874.583, -800.750},
                {873.500, -800.583},
                {872.917, -797.500},
                {872.667, -793.583},
                {872.583, -787.000},
                {873.000, -783.417},
                {875.000, -780.750},
                {890.917, -762.667},
                {891.083, -761.417},
                {890.583, -760.167},
                {866.250, -733.062},
                {865.062, -731.250},
                {863.625, -728.938},
                {861.375, -725.125},
                {859.688, -722.625},
                {858.875, -716.750}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
        {
            if (i<5)
                glColor4d(255/255.0f,221/255.0f,143/255.0f,0.5);
            else
                glColor4d(255/255.0f,221/255.0f,143/255.0f,1);
            glVertex2dv(vertices[i]);
        }
        glEnd();
        glDisable(GL_STENCIL_TEST);    }
    //nose outline
    {
        glLineWidth(1);
        glBegin(GL_LINE_STRIP);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 0.0f);
        glVertex2f(861.333, -712.250);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 1.0f);
        glVertex2f(862.000, -717.917);
        glVertex2f(863.667, -723.167);
        glVertex2f(867.583, -729.500);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 0.8f);
        glVertex2f(873.583, -737.417);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 0.5f);
        glVertex2f(880.917, -745.500);
        glVertex2f(889.667, -754.833);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 7.0f);
        glVertex2f(895.250, -759.917);
        glVertex2f(895.583, -761.500);
        glVertex2f(895.583, -763.417);
        glVertex2f(894.667, -765.833);
        glVertex2f(888.667, -774.417);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 1.0f);
        glVertex2f(877.917, -786.917);
        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 0.0f);
        glVertex2f(876.750, -789.583);
        glEnd();

        glColor4f(106 / 225.0f, 51 / 225.0f, 28 / 225.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(859.167, -783.833);
        glVertex2f(865.333, -781.667);
        glEnd();
    }

}
void violetLeftEye()
{

    //white base
    {
        double vertices[][2] = {
                {791.000, -687.500},
                {789.333, -692.000},
                {787.833, -695.833},
                {785.125, -699.688},
                {782.667, -703.167},
                {779.583, -706.750},
                {775.917, -709.333},
                {771.750, -710.917},
                {768.083, -711.250},
                {758.333, -711.333},
                {759.333, -688.667},
                {758.250, -671.667},
                {762.250, -671.917},
                {767.583, -672.500},
                {771.750, -673.833},
                {777.167, -675.750},
                {787.000, -681.750},
                {790.250, -685.333}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 189, 138, 107, 1);

        glBegin(GL_POLYGON);
        glColor4f(164/225.0f,92/225.0f,63/225.0f,1.0f);
        glVertex2f(791.958, -688.167);
        glColor4f(189/225.0f,138/225.0f,107/225.0f,1.0f);
        glVertex2f(781.250, -677.833);
        glVertex2f(781.833, -704.292);
        glEnd();
    }

    //pupil black base
    {
        glColor4f(29 / 225.0f, 20 / 225.0f, 18 / 225.0f, 1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(724.667, -685.083);
        glVertex2f(742.250, -673.000);
        glVertex2f(755.917, -671.083);
        glVertex2f(760.750, -673.667);
        glVertex2f(763.562, -676.625);
        glVertex2f(765.375, -680.500);
        glVertex2f(766.667, -684.750);
        glVertex2f(766.875, -688.250);
        glVertex2f(767.000, -691.312);
        glVertex2f(766.938, -695.250);
        glVertex2f(766.625, -698.062);
        glVertex2f(766.125, -700.812);
        glVertex2f(765.250, -703.750);
        glVertex2f(763.438, -707.500);
        glVertex2f(760.938, -710.188);
        glVertex2f(759.188, -711.250);
        glVertex2f(738.938, -711.312);
        glVertex2f(733.083, -708.667);
        glVertex2f(730.667, -707.667);
        glVertex2f(728.167, -706.667);
        glVertex2f(725.375, -702.875);
        glVertex2f(723.875, -699.625);
        glVertex2f(722.875, -697.250);
        glVertex2f(723.000, -692.125);
        glEnd();
    }
    //layer 1 (grayBlue)
    {
        glColor4f(62/225.0f,69/225.0f,69/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(737.750, -690.417);
        glVertex2f(727.250, -700.333);
        glVertex2f(725.917, -700.250);
        glVertex2f(724.000, -698.417);
        glVertex2f(723.833, -694.667);
        glVertex2f(724.000, -691.333);
        glVertex2f(724.500, -688.167);
        glVertex2f(726.167, -686.083);
        glVertex2f(730.000, -682.500);
        glVertex2f(733.833, -679.667);
        glVertex2f(738.833, -677.500);
        glVertex2f(741.917, -676.333);
        glVertex2f(743.750, -676.500);
        glVertex2f(744.583, -677.500);
        glVertex2f(744.917, -680.000);
        glVertex2f(744.750, -681.583);
        glVertex2f(743.417, -684.167);
        glVertex2f(740.250, -687.750);
        glEnd();
    }
    //top point
    {
        glPointSize(1);
        glColor4f(80/225.0f,80/225.0f,73/225.0f,1.0f);
        glBegin(GL_POINTS);
        glVertex2d(748,-678);
        glEnd();
    }

    //lower part layer 1
    {
        double vertices[][2] = {
                {737.583, -689.417},
                {731.083, -691.250},
                {727.667, -695.083},
                {726.500, -698.583},
                {729.583, -702.500},
                {739.333, -710.750},
                {753.667, -710.833},
                {758.000, -707.833},
                {761.667, -701.000},
                {762.083, -695.917},
                {761.833, -693.417},
                {760.417, -690.500},
                {759.333, -687.333},
                {757.000, -684.833},
                {755.417, -685.167},
                {754.500, -687.833},
                {753.500, -690.500},
                {750.750, -696.833},
                {748.167, -699.667},
                {744.833, -698.250},
                {742.750, -695.333}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 74, 108, 103, 1.0);
    }
    // lower pary layer 2 (brightest one)
    {
        double vertices[][2] = {
                {743.000, -703.000},
                {737.188, -694.312},
                {730.000, -699.312},
                {729.250, -700.500},
                {729.625, -702.062},
                {740.438, -710.500},
                {741.500, -711.312},
                {753.875, -710.875},
                {755.000, -709.188},
                {754.875, -708.062},
                {751.188, -705.375},
                {751.500, -704.250},
                {756.312, -699.875},
                {756.125, -696.562},
                {755.938, -693.938},
                {756.250, -690.375},
                {754.938, -688.938},
                {754.312, -688.938},
                {753.688, -689.312},
                {753.500, -691.500},
                {753.625, -693.250},
                {753.000, -695.625},
                {751.625, -697.688},
                {750.000, -699.438},
                {748.688, -700.625},
                {746.188, -699.562},
                {742.500, -695.062},
                {740.938, -693.250},
                {739.312, -692.812},
                {737.188, -694.312}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        glColor4f(191/255.0f,243/255.0f,226/255.0f,1);
        glVertex2dv(vertices[0]);
        glColor4d(122/255.0f,164/255.0f,156/255.0f,1);
        for (int i = 1; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();
        glDisable(GL_STENCIL_TEST);
    }
    //upper part (lower polygon)
    {
        glBegin(GL_POLYGON);
        glColor4f(101/225.0f,147/225.0f,144/225.0f,1.0f);
        glVertex2f(748.938, -693.406);
        glColor4f(88/225.0f,127/225.0f,124/225.0f,1.0f);
        glVertex2f(752.312, -689.438);
        glVertex2f(752.594, -690.156);
        glVertex2f(752.531, -691.906);
        glVertex2f(752.125, -694.000);
        glVertex2f(751.469, -695.625);
        glVertex2f(749.812, -697.594);
        glVertex2f(748.500, -699.156);
        glVertex2f(747.656, -699.031);
        glVertex2f(746.156, -697.750);
        glVertex2f(744.312, -694.688);
        glVertex2f(744.625, -693.250);
        glVertex2f(745.906, -691.188);
        glVertex2f(747.656, -689.531);
        glVertex2f(749.719, -688.188);
        glVertex2f(750.938, -687.562);
        glVertex2f(752.312, -689.406);
        glEnd();

    }

    //upper part (upper polygon)
    {
        glBegin(GL_POLYGON);
        glColor4f(72/225.0f,98/225.0f,95/225.0f,1.0f);
        glVertex2f(748.938, -693.406);
        glVertex2f(752.312, -689.438);
        glVertex2f(752.594, -690.156);
        glVertex2f(752.531, -691.906);
        glVertex2f(752.125, -694.000);

        glColor4f(65/225.0f,82/225.0f,81/225.0f,1.0f);
        glVertex2f(751.469, -695.625);
        glVertex2f(749.812, -697.594);
        glVertex2f(748.500, -699.156);
        glVertex2f(747.656, -699.031);
        glVertex2f(746.156, -697.750);
        glVertex2f(744.312, -694.688);
        glVertex2f(744.625, -693.250);
        glVertex2f(745.906, -691.188);
        glColor4f(72/225.0f,98/225.0f,95/225.0f,1.0f);
        glVertex2f(747.656, -689.531);
        glVertex2f(749.719, -688.188);
        glVertex2f(750.938, -687.562);
        glVertex2f(752.312, -689.406);
        glEnd();

    }

    //upper right white part
    {
        double vertices[][2] = {
                {755.000, -681.500},
                {756.458, -683.833},
                {758.000, -685.417},
                {759.875, -685.458},
                {762.417, -684.375},
                {763.667, -682.208},
                {763.708, -680.208},
                {763.000, -678.125},
                {760.875, -676.292},
                {759.792, -675.667},
                {757.833, -675.542},
                {754.917, -675.667},
                {753.167, -676.333},
                {751.792, -677.625},
                {751.500, -678.250},
                {751.958, -679.417},
                {752.958, -680.333}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 255, 255, 255, 1.0);
    }
    //brown eyeliner
    {
        double vertices[][2] = {
                {771.500, -711.125},
                {765.750, -711.750},
                {745.750, -712.000},
                {741.000, -712.000},
                {738.250, -712.000},
                {734.500, -709.125},
                {731.625, -708.000},
                {726.375, -707.250},
                {721.417, -704.917},
                {717.750, -702.583},
                {713.667, -699.917},
                {711.333, -697.917},
                {708.250, -695.583},
                {705.833, -692.417},
                {702.167, -690.917},
                {699.500, -689.667},
                {696.667, -688.833},
                {692.917, -687.917},
                {686.625, -686.875},
                {691.625, -685.542},
                {700.583, -682.500},
                {705.250, -680.250},
                {708.750, -677.583},
                {715.438, -671.938},
                {715.938, -671.438},
                {714.312, -671.500},
                {712.625, -671.812},
                {710.750, -672.375},
                {708.083, -673.083},
                {705.458, -674.000},
                {708.562, -671.875},
                {711.042, -670.375},
                {713.375, -669.312},
                {716.062, -668.875},
                {719.188, -668.812},
                {723.312, -668.812},
                {726.333, -666.750},
                {729.083, -665.417},
                {733.917, -663.833},
                {738.750, -662.167},
                {743.917, -660.833},
                {748.750, -659.375},
                {752.542, -658.917},
                {759.375, -658.812},
                {773.000, -659.625},
                {779.000, -660.312},
                {786.167, -661.167},
                {788.000, -664.250},
                {813.833, -671.750},
                {809.438, -671.500},
                {804.750, -670.875},
                {797.812, -669.250},
                {789.875, -667.250},
                {791.667, -669.583},
                {796.188, -672.188},
                {800.750, -674.750},
                {805.000, -677.000},
                {809.917, -678.750},
                {805.750, -678.917},
                {801.417, -677.917},
                {797.750, -676.833},
                {792.333, -673.833},
                {793.250, -676.250},
                {794.417, -678.500},
                {796.583, -681.667},
                {798.833, -684.000},
                {802.333, -686.917},
                {806.667, -689.750},
                {804.167, -689.583},
                {799.833, -688.667},
                {795.833, -687.083},
                {791.833, -684.917},
                {788.333, -683.917},
                {784.333, -680.500},
                {779.583, -677.083},
                {772.917, -674.583},
                {762.625, -672.375},
                {750.583, -672.250},
                {747.750, -672.583},
                {747.750, -674.833},
                {747.208, -675.542},
                {746.458, -675.792},
                {744.958, -676.042},
                {743.708, -675.542},
                {740.562, -675.438},
                {738.438, -676.562},
                {733.438, -679.312},
                {729.542, -681.750},
                {727.333, -683.500},
                {725.042, -685.458},
                {723.875, -687.417},
                {723.708, -689.833},
                {723.542, -693.500},
                {723.417, -695.417},
                {723.708, -697.625},
                {724.125, -699.042},
                {724.875, -700.250},
                {726.208, -701.500},
                {727.583, -702.208},
                {727.833, -705.750},
                {728.083, -706.917},
                {728.750, -707.688},
                {731.562, -708.000},
                {734.500, -709.062},
                {738.125, -712.688},
                {765.562, -712.562}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 61, 24, 14, 1.0);
    }
    //elTriangle elly 3aly elBrown eyeliner
    {
        glColor4f(180/225.0f,104/225.0f,70/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(710.042, -693.167);
        glVertex2f(716.958, -686.750);
        glVertex2f(717.375, -686.625);
        glVertex2f(717.792, -686.792);
        glVertex2f(718.042, -687.208);
        glVertex2f(718.219, -692.062);
        glVertex2f(718.281, -693.781);
        glVertex2f(718.875, -694.906);
        glVertex2f(723.094, -703.000);
        glVertex2f(723.031, -704.000);
        glVertex2f(721.969, -704.062);
        glVertex2f(720.562, -703.656);
        glVertex2f(718.667, -702.417);
        glVertex2f(714.083, -698.250);
        glVertex2f(710.750, -695.083);
        glVertex2f(709.917, -694.167);
        glEnd();

    }

    //eLine elly ta7t el7ageb
    {
        double vertices[][2] = {
                {710.125, -664.125},
                {722.750, -661.500},
                {731.375, -659.000},
                {742.125, -656.375},
                {750.438, -655.125},
                {756.000, -654.125},
                {761.875, -653.188},
                {768.875, -652.875},
                {778.000, -653.312},
                {783.312, -654.938},
                {785.625, -655.938},
                {789.562, -656.562},
                {797.125, -656.875},
                {798.500, -657.312},
                {801.062, -658.250},
                {803.562, -659.375},
                {808.375, -662.625},
                {809.688, -663.438},
                {804.438, -658.500},
                {801.938, -656.750},
                {799.375, -655.062},
                {794.625, -652.562},
                {789.250, -651.000},
                {784.667, -650.333},
                {759.875, -650.000},
                {751.667, -651.667},
                {744.000, -653.000},
                {733.167, -656.000},
                {725.917, -658.583}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 107, 45, 28, 1.0);
    }

    //base el7ageb
    {
        double vertices[][2] = {
                {809.833, -649.667},
                {801.667, -645.500},
                {792.667, -643.000},
                {784.833, -642.500},
                {771.167, -642.333},
                {762.125, -642.125},
                {757.250, -642.000},
                {752.500, -642.000},
                {742.750, -641.875},
                {733.750, -642.500},
                {725.375, -643.375},
                {712.375, -645.125},
                {732.125, -640.250},
                {742.750, -638.250},
                {752.375, -636.250},
                {767.125, -634.375},
                {774.000, -633.500},
                {791.750, -633.125},
                {797.125, -634.125},
                {799.500, -634.750},
                {802.125, -635.875},
                {812.875, -642.625}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 116, 52, 28, 1.0);
    }
    //light el7ageb
    {
        glColor4f(138/225.0f,69/225.0f,42/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(742.625, -640.000);
        glVertex2f(761.125, -639.750);
        glVertex2f(768.750, -639.375);
        glVertex2f(783.250, -636.250);
        glVertex2f(774.125, -635.875);
        glVertex2f(763.625, -635.750);
        glVertex2f(755.125, -636.875);
        glEnd();

    }

    //light under eye
    {
        glBegin(GL_POLYGON);
        glColor4f(248/225.0f,185/225.0f,127/225.0f,1.0f);
        glVertex2f(777.000, -719.000);
        glColor4f(218/225.0f,151/225.0f,99/225.0f,1.0f);
        glVertex2f(772.000, -720.750);
        glVertex2f(766.875, -716.875);
        glVertex2f(766.750, -716.250);
        glVertex2f(767.750, -715.500);
        glVertex2f(776.875, -715.750);
        glVertex2f(785.375, -719.750);
        glVertex2f(786.000, -721.000);
        glVertex2f(785.875, -721.625);
        glVertex2f(780.375, -724.125);
        glVertex2f(779.250, -724.250);
        glVertex2f(777.875, -724.125);
        glVertex2f(775.875, -723.500);
        glVertex2f(772.000, -720.750);
        glEnd();

    }
}
void violetRightEye()
{
    //elShadow elly ta7t el3een
    {
        glColor4f(196/225.0f,94/225.0f,47/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(864.875, -710.688);
        glVertex2f(864.938, -714.812);
        glVertex2f(866.875, -717.812);
        glVertex2f(869.375, -720.000);
        glVertex2f(872.438, -722.625);
        glVertex2f(875.625, -724.375);
        glVertex2f(882.750, -724.875);
        glVertex2f(890.188, -724.250);
        glVertex2f(893.250, -722.938);
        glVertex2f(892.438, -715.125);
        glEnd();

    }
    //elShadow elly fou2 el3een
    {
        double vertices[][2] = {
                {872.000, -679.625},
                {879.000, -674.375},
                {884.500, -671.750},
                {891.000, -670.000},
                {894.625, -670.625},
                {896.875, -672.125},
                {898.250, -673.375},
                {912.875, -673.500},
                {910.125, -671.750},
                {906.125, -669.625},
                {901.125, -667.750},
                {898.250, -667.000},
                {877.500, -667.750},
                {874.125, -669.625},
                {872.250, -672.125},
                {871.750, -676.250}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 141, 65, 25, 1.0);
    }

    //el7ageb elYmeen
    {
        double vertices[][2] = {
                {918.125, -654.125},
                {912.438, -651.812},
                {906.375, -649.500},
                {901.438, -648.375},
                {896.688, -647.188},
                {890.188, -647.375},
                {884.000, -649.125},
                {880.312, -650.062},
                {880.375, -651.188},
                {891.062, -653.188},
                {901.188, -654.750},
                {909.688, -656.875},
                {913.250, -658.000},
                {919.000, -660.875},
                {920.938, -662.125}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 171, 78, 33, 1.0);
    }
    //outlines el7ageb elymeen
    {
        glColor4f(109/225.0f,40/225.0f,12/225.0f,1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(918.125, -654.125);
        glVertex2f(912.438, -651.812);
        glVertex2f(906.375, -649.500);
        glVertex2f(901.438, -648.375);
        glVertex2f(896.688, -647.188);
        glVertex2f(890.188, -647.375);
        glVertex2f(884.000, -649.125);
        glVertex2f(880.312, -650.062);
        glVertex2f(880.375, -651.188);
        glVertex2f(891.062, -653.188);
        glVertex2f(901.188, -654.750);
        glVertex2f(909.688, -656.875);
        glVertex2f(913.250, -658.000);
        glVertex2f(919.000, -660.875);
        glVertex2f(920.938, -662.125);
        glEnd();

    }


    //right eyeliner
    {
        double vertices[][2] = {
                {867.375, -708.500},
                {871.500, -699.875},
                {873.500, -697.000},
                {879.333, -692.083},
                {886.500, -688.583},
                {891.667, -687.000},
                {896.125, -687.250},
                {900.875, -690.500},
                {903.500, -693.375},
                {907.000, -697.375},
                {909.000, -700.000},
                {909.083, -707.917},
                {907.083, -711.333},
                {903.594, -715.969},
                {902.292, -717.708},
                {900.500, -720.000},
                {904.312, -717.156},
                {907.344, -714.000},
                {910.000, -710.969},
                {912.219, -708.781},
                {916.000, -705.938},
                {918.688, -704.312},
                {920.938, -703.562},
                {924.750, -702.500},
                {928.125, -700.875},
                {928.500, -700.375},
                {928.188, -699.375},
                {912.562, -687.188},
                {914.062, -686.375},
                {917.375, -686.375},
                {921.438, -686.375},
                {923.625, -685.375},
                {925.688, -683.500},
                {927.188, -680.938},
                {926.688, -678.188},
                {926.062, -680.938},
                {924.500, -682.812},
                {922.875, -683.938},
                {921.062, -684.438},
                {917.625, -684.562},
                {913.875, -684.562},
                {911.125, -684.562},
                {902.333, -677.500},
                {892.500, -676.083},
                {885.167, -676.167},
                {881.167, -677.000},
                {878.667, -678.583},
                {874.917, -681.083},
                {872.917, -684.083},
                {871.917, -686.250},
                {869.833, -691.000},
                {868.000, -694.833},
                {866.500, -700.500},
                {865.250, -709.833},
                {865.667, -713.500},
                {868.417, -716.167},
                {871.083, -718.583},
                {874.438, -720.688},
                {879.375, -722.938},
                {882.917, -724.167},
                {887.167, -724.083},
                {892.833, -719.750},
                {896.667, -715.000},
                {898.250, -710.583},
                {898.000, -702.917},
                {895.833, -698.833},
                {896.083, -687.250},
                {889.833, -687.250},
                {880.500, -691.000},
                {873.417, -697.083},
                {871.500, -699.833}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 103, 43, 14, 1.0);
    }
    //right light
    {
        glColor4f(166/225.0f,78/225.0f,29/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(915.417, -691.500);
        glVertex2f(926.583, -699.500);
        glVertex2f(923.000, -701.375);
        glVertex2f(915.083, -694.583);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(916.250, -698.500);
        glVertex2f(922.250, -702.417);
        glVertex2f(916.833, -703.750);
        glEnd();

    }
    //creamy base
    {
        glColor4f(253 / 225.0f, 238 / 225.0f, 185 / 225.0f, 1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(885.375, -686.625);
        glVertex2f(889.750, -723.000);
        glVertex2f(894.625, -722.375);
        glVertex2f(899.750, -720.000);
        glVertex2f(904.000, -716.375);
        glVertex2f(907.125, -712.125);
        glVertex2f(908.875, -709.625);
        glVertex2f(910.000, -700.250);
        glVertex2f(898.500, -685.750);
        glEnd();
    }
    //upper shadow of the creamy base
    {
        glColor4f(189/225.0f,148/225.0f,113/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(905.250, -708.542);
        glVertex2f(886.000, -686.000);
        glVertex2f(896.792, -686.000);
        glVertex2f(906.042, -692.250);
        glEnd();

    }
    //black layer (layer1)
    {
        double vertices[][2] = {
                {871.417, -701.083},
                {879.917, -692.250},
                {882.750, -690.167},
                {884.833, -689.000},
                {887.583, -688.583},
                {890.083, -688.250},
                {893.333, -689.583},
                {895.333, -692.750},
                {896.583, -696.500},
                {897.833, -700.750},
                {898.333, -705.833},
                {897.417, -711.833},
                {895.833, -715.167},
                {893.417, -718.000},
                {889.917, -720.750},
                {887.500, -721.500},
                {883.750, -722.167},
                {878.500, -721.583},
                {873.500, -718.417},
                {871.000, -715.500},
                {868.000, -712.333},
                {868.000, -705.917}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 0, 0, 0, 1.0);
    }
    //layer 2
    {
        double vertices[][2] = {
                {888.750, -703.750},
                {892.250, -699.583},
                {892.500, -697.750},
                {891.750, -695.833},
                {886.833, -692.417},
                {883.417, -692.417},
                {881.083, -694.333},
                {878.500, -697.083},
                {876.417, -699.417},
                {874.083, -703.167},
                {873.167, -704.750},
                {872.167, -708.083},
                {872.250, -713.000},
                {873.250, -716.667},
                {875.167, -718.333},
                {878.833, -720.417},
                {883.083, -721.000},
                {887.083, -720.250},
                {891.917, -717.167},
                {894.750, -713.333},
                {895.917, -709.083},
                {895.667, -703.667},
                {895.083, -701.667},
                {894.083, -701.250},
                {892.583, -701.167},
                {890.667, -702.333},
                {889.083, -704.833},
                {888.250, -706.750},
                {886.917, -710.083},
                {886.250, -711.167},
                {885.500, -712.167},
                {884.333, -712.750},
                {882.500, -712.583},
                {881.333, -711.000},
                {880.667, -708.583},
                {880.500, -706.917},
                {881.917, -704.833},
                {884.667, -701.750},
                {885.750, -701.000},
                {884.500, -702.917},
                {883.333, -704.917},
                {882.500, -706.750},
                {882.250, -708.500},
                {882.750, -709.833},
                {884.500, -709.750},
                {886.750, -707.250}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 87, 76, 61, 1.0);
    }
    //layer 3
    {
        double vertices[][2] = {
                {884.417, -700.667},
                {885.667, -698.417},
                {885.667, -696.667},
                {885.000, -696.000},
                {882.500, -696.750},
                {877.917, -700.917},
                {874.500, -704.167},
                {873.167, -710.417},
                {873.500, -714.250},
                {878.833, -719.500},
                {884.000, -720.250},
                {890.333, -717.417},
                {894.750, -711.917},
                {896.250, -706.500},
                {895.500, -705.000},
                {893.917, -704.083},
                {890.667, -703.917},
                {889.167, -706.583},
                {887.500, -710.333},
                {885.500, -713.250},
                {883.500, -714.000},
                {880.750, -712.667},
                {879.500, -710.500},
                {878.750, -707.167},
                {879.583, -705.250}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 111, 97, 76, 1.0);
    }
    //layer4
    {
        glColor4f(164/225.0f,161/225.0f,141/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(872.312, -709.438);
        glVertex2f(872.875, -707.875);
        glVertex2f(874.562, -707.750);
        glVertex2f(875.562, -708.500);
        glVertex2f(875.750, -709.938);
        glVertex2f(876.312, -712.875);
        glVertex2f(878.062, -715.812);
        glVertex2f(878.500, -717.250);
        glVertex2f(877.812, -718.062);
        glVertex2f(875.812, -718.000);
        glVertex2f(873.938, -716.812);
        glVertex2f(872.312, -714.125);
        glVertex2f(872.062, -711.312);
        glEnd();
    }
    //middle part, layer1
    {
        glColor4f(106/225.0f,121/225.0f,101/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(887.708, -714.042);
        glVertex2f(889.333, -704.458);
        glVertex2f(890.167, -704.375);
        glVertex2f(891.083, -705.458);
        glVertex2f(891.458, -706.875);
        glVertex2f(892.000, -708.208);
        glVertex2f(894.333, -707.708);
        glVertex2f(895.667, -708.375);
        glVertex2f(895.375, -710.667);
        glEnd();

    }
    //middle part, layer2
    {
        glColor4f(145/225.0f,171/225.0f,139/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(888.167, -715.667);
        glVertex2f(888.333, -706.458);
        glVertex2f(889.167, -706.375);
        glVertex2f(890.083, -707.458);
        glVertex2f(890.458, -708.875);
        glVertex2f(891.000, -710.208);
        glVertex2f(893.333, -709.708);
        glVertex2f(894.667, -710.375);
        glVertex2f(894.375, -712.667);
        glEnd();

    }
    //middle part, layer3
    {
        double vertices[][2] = {
                {879.917, -717.458},
                {887.375, -713.083},
                {889.042, -708.292},
                {891.208, -710.542},
                {892.500, -712.542},
                {892.583, -714.542},
                {891.958, -716.417},
                {889.125, -718.417},
                {886.167, -719.583},
                {882.542, -719.750},
                {881.125, -719.417},
                {880.347, -718.528},
                {880.042, -718.000}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 193, 217, 184, 1.0);
    }
    //middle part, last layer
    {
        double vertices[][2] = {
                {880.167, -716.208},
                {878.125, -712.583},
                {877.583, -710.375},
                {877.875, -708.125},
                {878.792, -707.375},
                {880.292, -707.917},
                {881.208, -710.542},
                {881.583, -712.083},
                {882.333, -713.458},
                {883.625, -713.667},
                {884.875, -713.250},
                {886.167, -712.083},
                {886.417, -711.917},
                {887.083, -712.208},
                {887.583, -712.792},
                {887.750, -713.417},
                {887.917, -714.458},
                {887.250, -715.875},
                {886.167, -717.167},
                {884.708, -717.333},
                {882.208, -717.333}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 233, 252, 231, 1.0);
    }
    //upper layers
    {
        glBegin(GL_POLYGON);
        glColor4f(238/225.0f,255/225.0f,238/225.0f,1.0f);
        glVertex2f(884.375, -706.656);
        glColor4f(185/225.0f,204/225.0f,186/225.0f,1.0f);
        glVertex2f(886.781, -702.938);
        glVertex2f(886.406, -702.594);
        glVertex2f(885.656, -702.000);
        glColor4f(50/225.0f,46/225.0f,36/225.0f,1.0f);
        glVertex2f(885.000, -702.875);
        glVertex2f(883.000, -706.156);
        glVertex2f(882.438, -707.469);
        glVertex2f(882.500, -709.062);
        glVertex2f(883.281, -709.625);
        glVertex2f(884.500, -709.312);
        glVertex2f(885.812, -707.562);
        glColor4f(185/225.0f,204/225.0f,186/225.0f,1.0f);
        glVertex2f(886.750, -706.125);
        glVertex2f(887.062, -703.562);
        glVertex2f(886.812, -702.938);
        glEnd();

    }
    //creamy right upper polygon
    {
        glColor4f(252/225.0f,246/225.0f,219/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(886.292, -690.083);
        glVertex2f(894.292, -697.667);
        glVertex2f(893.000, -689.917);
        glEnd();

    }
    //the point
    {
        glPointSize(1);
        glColor4f(246 / 225.0f, 238 / 225.0f, 197 / 225.0f, 1.0f);
        glBegin(GL_POINTS);
        glVertex2d(894, -703);
        glEnd();
    }
    //right eye, second eyeliner
    {
        double vertices[][2] = {
                {870.083, -715.417},
                {867.917, -711.917},
                {867.333, -708.750},
                {869.500, -703.583},
                {872.833, -698.833},
                {878.167, -693.250},
                {882.333, -690.333},
                {887.000, -688.167},
                {893.167, -686.833},
                {897.083, -687.500},
                {902.667, -692.167},
                {905.417, -695.167},
                {908.250, -699.083},
                {909.167, -702.417},
                {909.000, -706.500},
                {908.000, -709.917},
                {907.083, -711.917},
                {903.750, -715.917},
                {901.667, -718.333},
                {907.917, -712.750},
                {912.000, -706.167},
                {911.583, -697.667},
                {906.750, -688.333},
                {900.417, -683.500},
                {890.917, -682.167},
                {880.583, -685.000},
                {870.000, -695.417},
                {867.417, -704.417},
                {866.583, -709.083},
                {867.083, -711.667}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 103, 43, 14, 1.0);
    }


}
void drawVioletFace()
{
    //face base
    {
        double vertices[][2] = {
                {638, -507},
                {645, -781},
                {683, -854},
                {719, -876},
                {768, -902},
                {804, -915},
                {819, -920},
                {831, -924},
                {840, -926},
                {844, -926},
                {847, -925},
                {852, -921},
                {855, -915},
                {858, -908},
                {862, -900},
                {868, -887},
                {872, -879},
                {878, -869},
                {892, -846},
                {901, -831},
                {906, -818},
                {908, -811},
                {910, -805},
                {911, -799},
                {912, -775},
                {913, -740},
                {913, -732},
                {914, -723},
                {915, -717},
                {917, -706},
                {928, -699},
                {928, -690},
                {927, -677},
                {924, -667},
                {925, -658},
                {920, -617},
                {887, -488}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        //VERTICES
        glColor4d(173/255.0f,94/255.0f,58/255.0f,1);
        glVertex2dv(vertices[0]);
        glColor4d(215/255.0f,134/255.0f,79/255.0f,1);
        for (int i = 1; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();
        glDisable(GL_STENCIL_TEST);
    }
    //face light
    {
        double vertices[][2] = {
                {768, -902},
                {804, -915},
                {819, -920},
                {831, -924},
                {840, -926},
                {844, -926},
                {847, -925},
                {852, -921},
                {855, -915},
                {858, -908},
                {862, -900},
                {868, -887},
                {872, -879},
                {878, -869},
                {892, -846},
                {901, -831},
                {906, -818},
                {908, -811},
                {910, -805},
                {911, -799},
                {912, -775},
                {913, -740},
                {913, -732},
                {914, -723},
                {915, -717},
                {917, -706},
                {928, -699},
                {917.667, -702.000},
                {904.167, -712.667},
                {902.167, -717.333},
                {900.667, -721.667},
                {898.250, -727.500},
                {895.250, -737.000},
                {894.000, -744.000},
                {894.167, -750.833},
                {894.417, -755.833},
                {894.583, -760.833},
                {894.500, -769.000},
                {894.500, -777.500},
                {894.000, -789.500},
                {892.000, -803.333},
                {888.500, -819.000},
                {885.000, -829.000},
                {881.167, -837.500},
                {876.167, -846.667},
                {870.833, -855.667},
                {862.667, -868.167},
                {855.333, -880.333},
                {849.000, -892.500},
                {838.750, -915.500},
                {833.250, -918.250},
                {826.000, -917.250},
                {809.500, -914.250},
                {791.250, -908.000}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 253, 226, 165, 1.0);
    }
    //face outer light
    {
        double vertices[][2] = {
                {833.250, -918.250},
                {826.000, -917.250},
                // Empty line here
                {908.667, -701.000},
                {895.167, -711.667},
                {893.167, -716.333},
                {891.667, -720.667},
                {889.250, -726.500},
                {886.250, -736.000},
                {885.000, -743.000},
                {885.167, -749.833},
                {885.417, -754.833},
                {885.583, -759.833},
                {885.500, -768.000},
                {885.500, -776.500},
                {885.000, -788.500},
                {883.000, -802.333},
                {879.500, -818.000},
                {876.000, -828.000},
                {872.167, -836.500},
                {867.167, -845.667},
                {861.833, -854.667},
                {853.667, -867.167},
                {846.333, -879.333},
                {840.000, -891.500},
                {829.750, -914.500},
                {824.250, -917.250},
                {817.000, -916.250},
                // Empty line here
                {917.667, -702.000},
                {904.167, -712.667},
                {902.167, -717.333},
                {900.667, -721.667},
                {898.250, -727.500},
                {895.250, -737.000},
                {894.000, -744.000},
                {894.167, -750.833},
                {894.417, -755.833},
                {894.583, -760.833},
                {894.500, -769.000},
                {894.500, -777.500},
                {894.000, -789.500},
                {892.000, -803.333},
                {888.500, -819.000},
                {885.000, -829.000},
                {881.167, -837.500},
                {876.167, -846.667},
                {870.833, -855.667},
                {862.667, -868.167},
                {855.333, -880.333},
                {849.000, -892.500},
                {838.750, -915.500}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i <= 1; ++i)
            glVertex2dv(vertices[i]);
        for (int i = 26; i >=2; --i)
            glVertex2dv(vertices[i]);
        for (int i = 27; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        for (int i = 0; i <= 1; ++i)
        {
            glColor4d(215/255.0f,134/255.0f,79/255.0f,0.1);
            glVertex2dv(vertices[i]);
        }
        for (int i = 26; i >=2; --i)
        {
            glColor4d(215/255.0f,134/255.0f,79/255.0f,0.1);
            glVertex2dv(vertices[i]);
        }
        for (int i = 27; i <= 49; ++i)
        {
            glColor4d(253/255.0f,226/255.0f,165/255.0f,0.2);
            glVertex2dv(vertices[i]);
        }
        glEnd();
        glDisable(GL_STENCIL_TEST);
    }

    //mouse
    violetMouse();
    //mose
    violetNose();
    //leftEye
    violetLeftEye();
    //rightEye
    violetRightEye();

    //face outline
    {
        glLineWidth(1);
        glColor4f(104 / 225.0f, 60 / 225.0f, 29 / 225.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(683, -854);
        glVertex2f(719, -876);
        glVertex2f(768, -902);
        glVertex2f(804, -915);
        glVertex2f(819, -920);
        glVertex2f(831, -924);
        glVertex2f(840, -926);
        glVertex2f(844, -926);
        glVertex2f(847, -925);
        glVertex2f(852, -921);
        glVertex2f(855, -915);
        glVertex2f(858, -908);
        glVertex2f(862, -900);
        glVertex2f(868, -887);
        glVertex2f(872, -879);
        glVertex2f(878, -869);
        glVertex2f(892, -846);
        glVertex2f(901, -831);
        glVertex2f(906, -818);
        glVertex2f(908, -811);
        glVertex2f(910, -805);
        glVertex2f(911, -799);
        glVertex2f(912, -775);
        glVertex2f(913, -740);
        glVertex2f(913, -732);
        glVertex2f(914, -723);
        glVertex2f(915, -717);
        glVertex2f(917, -706);
        glEnd();

        glColor4f(136/225.0f,63/225.0f,24/225.0f,1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(907.667, -682.167);
        glVertex2f(910.333, -678.500);
        glVertex2f(912.667, -674.833);
        glVertex2f(914.667, -670.833);
        glVertex2f(915.167, -668.167);
        glVertex2f(915.167, -666.000);
        glVertex2f(914.667, -656.333);
        glEnd();

    }

}
void violetLeftEyebrowOutline()
{
    glLineWidth(1);
    glColor4f(90/225.0f,37/225.0f,20/225.0f,1.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(808.333, -648.667);
    glVertex2f(802.667, -645.667);
    glVertex2f(796.500, -643.667);
    glVertex2f(788.250, -642.583);
    glVertex2f(775.000, -642.583);
    glVertex2f(758.625, -642.125);
    glColor4f(60/225.0f,25/225.0f,14/225.0f,0.8f);
    glVertex2f(751.625, -641.875);
    glVertex2f(743.812, -642.000);
    glVertex2f(734.167, -642.667);
    glVertex2f(725.333, -643.833);
    glVertex2f(717.500, -644.333);
    glVertex2f(708.250, -648.583);
    glVertex2f(716.000, -643.833);
    glVertex2f(718.000, -643.000);
    glVertex2f(726.333, -641.750);
    glColor4f(90/225.0f,37/225.0f,20/225.0f,1.0f);
    glVertex2f(734.083, -640.167);
    glVertex2f(750.333, -636.833);
    glVertex2f(759.500, -635.417);
    glVertex2f(767.500, -634.833);
    glColor4f(60/225.0f,25/225.0f,14/225.0f,0.8f);
    glVertex2f(774.000, -634.333);
    glVertex2f(789.125, -634.375);
    glVertex2f(796.375, -634.500);
    glVertex2f(802.750, -636.750);
    glVertex2f(812.250, -642.750);
    glEnd();

}
void violetEar()
{
    //ear base
    {
        double vertices[][2] = {
                {562.417, -799.917},
                {561.000, -795.250},
                {558.500, -787.750},
                {556.750, -777.000},
                {556.250, -771.500},
                {557.250, -761.000},
                {560.500, -750.500},
                {562.125, -742.875},
                {564.500, -735.625},
                {567.125, -726.375},
                {565.625, -717.625},
                {564.875, -712.500},
                {563.875, -706.875},
                {563.167, -705.500},
                {561.167, -705.000},
                {556.500, -704.667},
                {552.417, -705.333},
                {549.250, -706.417},
                {546.417, -708.417},
                {544.417, -710.083},
                {542.417, -712.500},
                {540.500, -715.250},
                {538.917, -718.167},
                {537.750, -720.500},
                {536.750, -723.375},
                {535.812, -727.188},
                {534.875, -731.000},
                {534.062, -735.375},
                {533.750, -738.938},
                {533.500, -747.917},
                {533.500, -753.583},
                {533.417, -759.417},
                {533.500, -763.917},
                {533.750, -767.583},
                {535.000, -770.500},
                {536.833, -774.333},
                {539.333, -777.833},
                {541.583, -780.583},
                {544.417, -783.583},
                {549.917, -789.167},
                {553.583, -792.583},
                {557.083, -795.917},
                {561.083, -800.583}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 139, 72, 46);
    }
    //ear upper light
    {
        double vertices[][2] = {
                {561.667, -715.833},
                {559.500, -714.167},
                {557.333, -713.333},
                {553.833, -713.500},
                {550.667, -715.500},
                {546.667, -718.500},
                {542.667, -724.167},
                {540.167, -729.833},
                {538.167, -736.667},
                {535.500, -746.667},
                {534.500, -754.167},
                {534.000, -738.667},
                {536.000, -727.333},
                {537.833, -721.333},
                {541.667, -714.333},
                {547.833, -708.833},
                {552.000, -706.667},
                {556.667, -705.667},
                {560.833, -705.833},
                {563.333, -706.500},
                {564.167, -713.833},
                {564.000, -716.500},
                {562.333, -716.167}
        };

        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 132, 67, 45);
    }
    //upper light outline
    {
        glColor4f(97/225.0f,41/225.0f,25/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(562.000, -715.667);
        glVertex2f(559.667, -714.167);
        glVertex2f(557.667, -713.167);
        glVertex2f(554.667, -713.167);
        glVertex2f(551.000, -715.167);
        glVertex2f(547.000, -719.000);
        glVertex2f(543.667, -722.833);
        glColor4f(132/225.0f,67/225.0f,45/225.0f,1.0f);
        glVertex2f(540.833, -729.333);
        glEnd();

    }
    //ear outline
    {
        //outer
        glLineWidth(1);
        glColor4f(33 / 225.0f, 9 / 225.0f, 3 / 225.0f, 0.5f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(562.417, -799.917);
        glVertex2f(561.000, -795.250);
        glVertex2f(558.500, -787.750);
        glVertex2f(556.750, -777.000);
        glVertex2f(556.250, -771.500);
        glVertex2f(557.250, -761.000);
        glVertex2f(560.500, -750.500);
        glVertex2f(562.125, -742.875);
        glVertex2f(564.500, -735.625);
        glVertex2f(567.125, -726.375);
        glVertex2f(565.625, -717.625);
        glVertex2f(564.875, -712.500);
        glVertex2f(563.875, -706.875);
        glVertex2f(563.167, -705.500);
        glVertex2f(561.167, -705.000);
        glVertex2f(556.500, -704.667);
        glVertex2f(552.417, -705.333);
        glVertex2f(549.250, -706.417);
        glVertex2f(546.417, -708.417);
        glVertex2f(544.417, -710.083);
        glVertex2f(542.417, -712.500);
        glVertex2f(540.500, -715.250);
        glVertex2f(538.917, -718.167);
        glVertex2f(537.750, -720.500);
        glVertex2f(536.750, -723.375);
        glVertex2f(535.812, -727.188);
        glVertex2f(534.875, -731.000);
        glVertex2f(534.062, -735.375);
        glVertex2f(533.750, -738.938);
        glVertex2f(533.500, -747.917);
        glVertex2f(533.500, -753.583);
        glVertex2f(533.417, -759.417);
        glVertex2f(533.500, -763.917);
        glVertex2f(533.750, -767.583);
        glVertex2f(535.000, -770.500);
        glVertex2f(536.833, -774.333);
        glVertex2f(539.333, -777.833);
        glVertex2f(541.583, -780.583);
        glVertex2f(544.417, -783.583);
        glVertex2f(549.917, -789.167);
        glVertex2f(553.583, -792.583);
        glVertex2f(557.083, -795.917);
        glVertex2f(561.083, -800.583);
        glEnd();

        //inner
        glBegin(GL_LINE_LOOP);
        glVertex2f(544.333, -746.000);
        glVertex2f(543.500, -749.167);
        glVertex2f(543.000, -752.000);
        glVertex2f(542.667, -755.000);
        glVertex2f(543.333, -757.000);
        glVertex2f(544.333, -758.500);
        glVertex2f(545.833, -758.333);
        glVertex2f(548.000, -755.167);
        glVertex2f(550.833, -749.000);
        glVertex2f(553.667, -740.500);
        glVertex2f(555.167, -735.500);
        glVertex2f(557.333, -729.667);
        glVertex2f(559.000, -725.500);
        glVertex2f(563.333, -715.333);
        glVertex2f(560.833, -717.000);
        glVertex2f(557.167, -719.833);
        glVertex2f(554.833, -723.000);
        glVertex2f(551.833, -727.333);
        glVertex2f(549.000, -732.833);
        glVertex2f(546.500, -738.667);
        glEnd();
    }
    //inner ear base
    {
        glBegin(GL_POLYGON);
        glColor4f(109/225.0f,48/225.0f,26/225.0f,1.0f);
        glVertex2f(536.333, -741.500);
        glVertex2f(537.500, -735.667);
        glVertex2f(539.833, -730.167);
        glVertex2f(542.000, -725.667);
        glVertex2f(544.500, -721.833);
        glVertex2f(547.500, -718.333);
        glVertex2f(551.833, -714.500);
        glVertex2f(554.500, -713.000);
        glVertex2f(557.333, -712.500);
        glVertex2f(562.167, -714.667);
        glVertex2f(563.333, -715.833);
        glVertex2f(562.667, -718.000);
        glVertex2f(559.667, -724.667);
        glVertex2f(556.333, -732.000);
        glVertex2f(551.833, -744.667);
        glColor4f(119/225.0f,56/225.0f,33/225.0f,1);
        glVertex2f(550.667, -749.333);
        glVertex2f(547.667, -756.667);
        glVertex2f(544.333, -758.667);
        glVertex2f(537.833, -755.000);
        glVertex2f(536.500, -753.167);
        glVertex2f(536.167, -749.333);
        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(93/225.0f,37/225.0f,21/225.0f,1.0f);
        glVertex2f(544.333, -746.000);
        glVertex2f(543.500, -749.167);
        glVertex2f(543.000, -752.000);
        glVertex2f(542.667, -755.000);
        glVertex2f(543.333, -757.000);
        glVertex2f(544.333, -758.500);
        glVertex2f(545.833, -758.333);
        glVertex2f(548.000, -755.167);
        glVertex2f(550.833, -749.000);

        glColor4f(99/225.0f,42/225.0f,25/225.0f,1.0f);
        glVertex2f(553.667, -740.500);
        glVertex2f(555.167, -735.500);
        glVertex2f(557.333, -729.667);
        glVertex2f(559.000, -725.500);
        glVertex2f(563.333, -715.333);
        glVertex2f(560.833, -717.000);
        glVertex2f(557.167, -719.833);
        glVertex2f(554.833, -723.000);
        glVertex2f(551.833, -727.333);
        glVertex2f(549.000, -732.833);
        glVertex2f(546.500, -738.667);
        glEnd();
    }

}
void violetHair()
{
    //hair base
    {
        //hair base
        {
            double vertices[][2] = {
                    {563.833, -706},
                    {564.167, -710.333},
                    {564.833, -714.5},
                    {565.5,   -719.667},
                    {567.5,   -726.667},
                    {561.833, -748.833},
                    {560.667, -754.5},
                    {558,     -763.833},
                    {557.167, -770.833},
                    {557,     -779.333},
                    {558.5,   -785.667},
                    {564.167, -802.167},
                    {575.333, -838.167},
                    {582.25,  -861.25},
                    {587.75,  -880.75},
                    {592.75,  -894.5},
                    {597.333, -915.833},
                    {599,     -924.167},
                    {601.167, -935.833},
                    {605.667, -954.833},
                    {611.667, -974.167},
                    {620.333, -998.667},
                    {635.5,   -1028.83},
                    {647.25,  -1050.25},
                    {656.25,  -1067},
                    {665.5,   -1078},
                    {656.333, -1065.5},
                    {644.833, -1044.33},
                    {641.667, -1037},
                    {628.5,   -1001.67},
                    {603.667, -900},
                    {618.667, -955.333},
                    {621.667, -969.667},
                    {626.667, -985},
                    {632.667, -998.333},
                    {644,     -1020},
                    {662,     -1048.17},
                    {668,     -1055.17},
                    {674,     -1060.67},
                    {678.5,   -1063},
                    {685.167, -1065.17},
                    {689.833, -1065},
                    {691.833, -1064.33},
                    {696,     -1061.75},
                    {698.75,  -1056.5},
                    {701,     -1049},
                    {702.5,   -1039.5},
                    {703.25,  -1030.5},
                    {700,     -1010.75},
                    {703,     -1019.75},
                    {704.5,   -1027},
                    {708.083, -1039.17},
                    {711,     -1047.08},
                    {714,     -1059.83},
                    {714.667, -1084.67},
                    {715.167, -1057.83},
                    {714.333, -1045.67},
                    {713.167, -1032.5},
                    {708.5,   -1014.83},
                    {714.333, -1028.33},
                    {717.5,   -1040.67},
                    {719,     -1049.5},
                    {719,     -1068},
                    {717.833, -1108.33},
                    {720.333, -1066.17},
                    {721.667, -1051.67},
                    {721.5,   -1046.67},
                    {721.167, -1038.83},
                    {720.333, -1030.5},
                    {717.5,   -1012.67},
                    {714,     -997.333},
                    {718.167, -1005.5},
                    {722.833, -1015.5},
                    {726,     -1025.33},
                    {730,     -1036.83},
                    {736.167, -1055.67},
                    {740.667, -1071.33},
                    {742.667, -1081.5},
                    {744.667, -1093.17},
                    {745.333, -1105.17},
                    {745.333, -1117.33},
                    {737.667, -1126.17},
                    {747,     -1116.83},
                    {753.833, -1097.67},
                    {756,     -1085.17},
                    {756.5,   -1058.25},
                    {754.25,  -1042.5},
                    {761.5,   -1033.25},
                    {766.75,  -1022},
                    {768.75,  -1008.75},
                    {770.25,  -988.75},
                    {769.5,   -979.75},
                    {766.75,  -969.75},
                    {764.5,   -958.625},
                    {756,     -930},
                    {729.25,  -863.5},
                    {743.25,  -884.25},
                    {747.25,  -891},
                    {753.75,  -899},
                    {774.5,   -923.75},
                    {773.5,   -920.5},
                    {747.5,   -883.5},
                    {743.25,  -875.25},
                    {737,     -867},
                    {730.25,  -855.25},
                    {723.25,  -843},
                    {709.75,  -821},
                    {705.25,  -812.25},
                    {700,     -799.5},
                    {698.5,   -789.5},
                    {694.75,  -770},
                    {691.25,  -751.25},
                    {687.5,   -736},
                    {683.875, -720.25},
                    {682.375, -708},
                    {686.875, -718.25},
                    {692,     -726.375},
                    {698.25,  -735.875},
                    {704.125, -746.25},
                    {716.167, -766.167},
                    {722.5,   -778.833},
                    {729.667, -794.333},
                    {734.333, -806.5},
                    {737.333, -815.333},
                    {739,     -828.667},
                    {739.167, -841.333},
                    {738.833, -867.333},
                    {743.333, -874.167},
                    {744.5,   -870.167},
                    {745.167, -860.833},
                    {744.833, -845.667},
                    {743.833, -834.833},
                    {740.833, -821.333},
                    {738,     -809},
                    {736,     -801},
                    {730.5,   -784.833},
                    {727.333, -777.333},
                    {720.833, -763.833},
                    {713.167, -748.667},
                    {709,     -741.5},
                    {705.667, -735.333},
                    {701.833, -726},
                    {697.833, -716.667},
                    {693.833, -708.333},
                    {689.833, -696.167},
                    {685.333, -683.833},
                    {683.5,   -676.333},
                    {688.833, -672.167},
                    {695.5,   -664},
                    {704.833, -651.333},
                    {707,     -648.25},
                    {713.25,  -644.25},
                    {718,     -643.25},
                    {722.25,  -642.25},
                    {730.75,  -628.5},
                    {745.5,   -604.75},
                    {755.5,   -584},
                    {760.333, -572},
                    {763,     -561.333},
                    {765.333, -548.333},
                    {768,     -524},
                    {768.333, -540.333},
                    {771.333, -558.667},
                    {774.667, -573.667},
                    {779.25,  -589.5},
                    {782.75,  -598.25},
                    {787.25,  -608.5},
                    {791.5,   -618.25},
                    {797.25,  -629},
                    {800.75,  -633.5},
                    {802.25,  -636.5},
                    {808.5,   -640.25},
                    {802,     -636.25},
                    {808.5,   -648.75},
                    {813.5,   -659.625},
                    {815.875, -664.125},
                    {817.375, -671.5},
                    {818.375, -679.375},
                    {818.375, -689.25},
                    {815.625, -703.375},
                    {813.5,   -710.375},
                    {810.125, -717.5},
                    {805.875, -722.75},
                    {801.625, -726.875},
                    {794.125, -731},
                    {800.875, -730.25},
                    {806.125, -727.875},
                    {812,     -723.5},
                    {816.625, -718.375},
                    {819.625, -712.875},
                    {822.25,  -707.5},
                    {823.875, -701.75},
                    {824.75,  -694.75},
                    {824.75,  -708.25},
                    {823.25,  -717.875},
                    {820.125, -727.125},
                    {816.5,   -734.5},
                    {812,     -738.5},
                    {823.5,   -731.25},
                    {831.125, -725.625},
                    {827,     -737.625},
                    {836,     -726.5},
                    {842.75,  -727.375},
                    {853,     -722.625},
                    {857.375, -718.875},
                    {860.5,   -713.5},
                    {864.667, -709.833},
                    {866.833, -704.667},
                    {869.167, -697},
                    {870.667, -687.5},
                    {871.833, -682.333},
                    {872.167, -677.167},
                    {872,     -675.667},
                    {874.167, -671.333},
                    {874.833, -663},
                    {876,     -656.667},
                    {877,     -650.833},
                    {877.833, -643.833},
                    {877.875, -637.125},
                    {877.25,  -631.25},
                    {875,     -622},
                    {872.125, -612.625},
                    {856.625, -570.25},
                    {869.875, -598.375},
                    {874.5,   -609.625},
                    {877,     -617.667},
                    {880.5,   -629.75},
                    {883.333, -645.833},
                    {884.833, -654.667},
                    {885.167, -661.333},
                    {885.167, -674.333},
                    {885.5,   -676.667},
                    {886.833, -677.833},
                    {889,     -676.667},
                    {889.333, -673.667},
                    {889.5,   -669.167},
                    {890.667, -656.833},
                    {891,     -646.167},
                    {890.5,   -624.833},
                    {890.5,   -610},
                    {889.833, -597.5},
                    {889.833, -590},
                    {892.667, -585},
                    {892.667, -590.667},
                    {892.667, -594.333},
                    {893.167, -597.667},
                    {897.5,   -607.833},
                    {902.167, -620},
                    {907.833, -632.833},
                    {914.833, -649.333},
                    {917.5,   -657.25},
                    {919.25,  -662.875},
                    {924.5,   -670},
                    {926.25,  -672.875},
                    {927.833, -679.167},
                    {929,     -689.167},
                    {928.667, -701.5},
                    {927,     -714.167},
                    {924.667, -729.833},
                    {922,     -741.167},
                    {921.125, -746.625},
                    {919.75,  -748.875},
                    {916.25,  -751.75},
                    {914.25,  -753.875},
                    {913,     -756.375},
                    {912.875, -758.75},
                    {914.375, -759.25},
                    {916.875, -757.875},
                    {923.375, -750.5},
                    {913.5,   -760},
                    {913.833, -765.333},
                    {914,     -771.5},
                    {914.167, -777.667},
                    {914.167, -784.5},
                    {913.667, -793},
                    {912.333, -802},
                    {909.5,   -812.5},
                    {907,     -820.167},
                    {903.833, -828.833},
                    {899.5,   -836.667},
                    {893.167, -847.833},
                    {887.167, -857.5},
                    {880.167, -868.833},
                    {874,     -878.167},
                    {871.667, -883.667},
                    {866.167, -893.5},
                    {870.167, -887.667},
                    {867,     -919.833},
                    {863.167, -950},
                    {862.333, -984.167},
                    {863.167, -1008.5},
                    {865.667, -1024.17},
                    {870,     -1036},
                    {869.25,  -1052},
                    {870,     -1061.25},
                    {871.5,   -1070.75},
                    {874,     -1080.5},
                    {877.5,   -1085.25},
                    {879.75,  -1089.25},
                    {882,     -1092},
                    {887.5,   -1095},
                    {893.75,  -1095.5},
                    {900.75,  -1095.5},
                    {906,     -1094.25},
                    {917.5,   -1092.25},
                    {909.5,   -1085.33},
                    {905.333, -1087.67},
                    {898.833, -1090.67},
                    {894.667, -1092},
                    {891.5,   -1092},
                    {888,     -1091.83},
                    {885,     -1090.33},
                    {882.5,   -1088.17},
                    {879.833, -1084.17},
                    {877.5,   -1078},
                    {875.5,   -1073.17},
                    {874.5,   -1067},
                    {873.667, -1059.33},
                    {873.333, -1047.5},
                    {872.833, -1034.83},
                    {867.667, -1022.33},
                    {865.333, -1005.67},
                    {864.333, -991.167},
                    {864,     -975.667},
                    {865.833, -947},
                    {870,     -918},
                    {878.667, -1025.67},
                    {878.833, -1034.67},
                    {879.667, -1047.67},
                    {881.667, -1057.33},
                    {884.5,   -1063.33},
                    {886.833, -1068.83},
                    {891.167, -1074.5},
                    {897.167, -1078.33},
                    {900.333, -1080.17},
                    {911.167, -1080.83},
                    {915.833, -1079.17},
                    {917.833, -1076.17},
                    {914.333, -1077},
                    {908.667, -1077.17},
                    {903.833, -1076.83},
                    {899.333, -1075.67},
                    {895.5,   -1073},
                    {891.333, -1068.83},
                    {887.167, -1063},
                    {884.167, -1056.17},
                    {882.833, -1049.33},
                    {882,     -1043},
                    {882.167, -1033.83},
                    {881.833, -1021.67},
                    {883,     -1007.33},
                    {885.75,  -991.75},
                    {886.25,  -984.25},
                    {885.75,  -962},
                    {889,     -980.75},
                    {892,     -995},
                    {895.75,  -1011.25},
                    {900,     -1027.5},
                    {904.375, -1041.25},
                    {906.875, -1047.5},
                    {910.5,   -1055.88},
                    {915,     -1062.75},
                    {917.5,   -1066},
                    {920.125, -1068.38},
                    {922,     -1069.12},
                    {925.875, -1062.12},
                    {922.5,   -1058},
                    {918.125, -1051.62},
                    {912.625, -1042.75},
                    {908,     -1034.38},
                    {903.5,   -1023.75},
                    {895.25,  -997.5},
                    {891.25,  -974.5},
                    {890.25,  -954.5},
                    {889.25,  -931.75},
                    {889.75,  -905.25},
                    {891,     -890.5},
                    {893.75,  -907.75},
                    {897,     -925.25},
                    {902,     -944.25},
                    {906.5,   -959.5},
                    {910.667, -969.333},
                    {913.5,   -976.167},
                    {917.667, -985},
                    {923.333, -994.667},
                    {929.167, -1004.83},
                    {933.833, -1013.83},
                    {933.667, -1035.67},
                    {931.833, -1044},
                    {928.667, -1052.83},
                    {926.167, -1061.83},
                    {922,     -1069.17},
                    {917.75,  -1076.06},
                    {915.812, -1079.19},
                    {909.5,   -1085.25},
                    {917.688, -1092.31},
                    {912.625, -1095.25},
                    {907.5,   -1099.12},
                    {899.25,  -1104.75},
                    {903.125, -1104.62},
                    {908.5,   -1103.12},
                    {914.75,  -1099.12},
                    {922.375, -1093},
                    {929.125, -1086.75},
                    {938.125, -1074.75},
                    {943.25,  -1066.62},
                    {948.375, -1056},
                    {954.875, -1042.5},
                    {958.875, -1030.88},
                    {964,     -1009.83},
                    {964.167, -991.167},
                    {963.333, -970.167},
                    {961.333, -957},
                    {967.333, -988.667},
                    {968.667, -1004.33},
                    {969.667, -1025.67},
                    {968,     -1052.33},
                    {963.667, -1069.67},
                    {957,     -1082},
                    {945.5,   -1095.83},
                    {953.833, -1090.33},
                    {962.333, -1080.83},
                    {967.833, -1069.5},
                    {972.667, -1055.33},
                    {973.333, -1043.33},
                    {973.417, -1028.42},
                    {972.667, -1017.25},
                    {970.75,  -979},
                    {967.25,  -963.25},
                    {964.75,  -954.75},
                    {976.25,  -989.5},
                    {979,     -1010.5},
                    {979.75,  -1037.75},
                    {978.25,  -1058.5},
                    {974.5,   -1075},
                    {979.5,   -1055.5},
                    {981.5,   -1035},
                    {980.75,  -1010.75},
                    {978.25,  -992.5},
                    {985,     -1016.75},
                    {990,     -1027.75},
                    {993.5,   -1044},
                    {997.75,  -1061},
                    {999.25,  -1081.75},
                    {999.5,   -1093.5},
                    {998.5,   -1101.75},
                    {993.75,  -1112.5},
                    {988.5,   -1120.5},
                    {981.25,  -1125.75},
                    {978.25,  -1127.75},
                    {987,     -1124.5},
                    {996.25,  -1118},
                    {1002.5,  -1110.5},
                    {1006.25, -1095.75},
                    {1007.25, -1080.25},
                    {1004.25, -1053.5},
                    {1008,    -1067.25},
                    {1012.25, -1075.75},
                    {1019.75, -1087.25},
                    {1025.25, -1095},
                    {1032,    -1103.25},
                    {1039.5,  -1110},
                    {1049,    -1115},
                    {1054.75, -1115.25},
                    {1060.75, -1114.5},
                    {1066.5,  -1111},
                    {1071.25, -1105.62},
                    {1068.25, -1108},
                    {1063.62, -1111.25},
                    {1059.38, -1112},
                    {1054.75, -1111.5},
                    {1048.38, -1109.75},
                    {1042.25, -1106.88},
                    {1037.5,  -1103},
                    {1031,    -1095.12},
                    {1024.33, -1083.33},
                    {1019.33, -1074.67},
                    {1012.83, -1060.17},
                    {1004.17, -1039.5},
                    {988,     -988.667},
                    {979.667, -955.667},
                    {979,     -951.667},
                    {984.333, -937.667},
                    {984,     -919},
                    {982.667, -906.333},
                    {990.667, -921.333},
                    {997,     -938.333},
                    {1003.33, -951.333},
                    {1008.67, -965.667},
                    {1013.33, -987.667},
                    {1013.67, -999.333},
                    {1013,    -1013.33},
                    {1009.67, -1029},
                    {1005,    -1038},
                    {1013.33, -1028},
                    {1016.67, -1019.67},
                    {1018.33, -1011},
                    {1018.33, -1001},
                    {1017.33, -989.667},
                    {1010.5,  -962.5},
                    {1007,    -951.667},
                    {1001.5,  -940.167},
                    {994,     -923.167},
                    {988.25,  -909},
                    {986.25,  -898.5},
                    {980.75,  -890},
                    {955.167, -787.5},
                    {954.125, -779.75},
                    {958.5,   -794.5},
                    {964.5,   -803.25},
                    {967.5,   -813.25},
                    {975,     -827.25},
                    {983,     -838},
                    {985.25,  -844.25},
                    {990,     -854.5},
                    {1006.25, -867.75},
                    {1015,    -875.75},
                    {1024.75, -887.75},
                    {1030.5,  -895.5},
                    {1038.5,  -906.75},
                    {1046.75, -919.75},
                    {1053,    -933.5},
                    {1059.75, -948.5},
                    {1063.5,  -962},
                    {1065,    -979.5},
                    {1063.75, -996.75},
                    {1061,    -1007},
                    {1056.5,  -1015.75},
                    {1051.75, -1021},
                    {1043.75, -1024},
                    {1028.5,  -1026.5},
                    {1041.75, -1026.25},
                    {1052.5,  -1022.25},
                    {1059.25, -1016},
                    {1055.75, -1023.5},
                    {1051.5,  -1027.5},
                    {1045.25, -1032.25},
                    {1038,    -1034},
                    {1052.25, -1031.5},
                    {1056,    -1028},
                    {1063,    -1021.75},
                    {1066.5,  -1017.5},
                    {1065.25, -1026.67},
                    {1064.83, -1030.42},
                    {1063.33, -1033.25},
                    {1061.42, -1035.5},
                    {1059.25, -1036.58},
                    {1058.33, -1035.25},
                    {1057.33, -1032.25},
                    {1057.75, -1029.25},
                    {1055.5,  -1032.83},
                    {1055.33, -1035.33},
                    {1056.08, -1037.33},
                    {1057.58, -1038.5},
                    {1060,    -1038.67},
                    {1062,    -1037.25},
                    {1064.33, -1034.75},
                    {1066.5,  -1031.92},
                    {1068.33, -1025.92},
                    {1070.08, -971.583},
                    {1048.25, -918.625},
                    {1058.25, -934.125},
                    {1063.5,  -939.875},
                    {1069.88, -945.125},
                    {1080.5,  -960},
                    {1087.92, -970.333},
                    {1095.17, -980.833},
                    {1105.75, -1000.92},
                    {1111.17, -1013.17},
                    {1114,    -1022.75},
                    {1115.33, -1031.33},
                    {1115.17, -1042.25},
                    {1114,    -1050.5},
                    {1112.75, -1052.58},
                    {1102.08, -1062.42},
                    {1108.08, -1059.42},
                    {1112.58, -1056.33},
                    {1116.42, -1052.17},
                    {1119.5,  -1047.5},
                    {1122.17, -1041.83},
                    {1122.25, -1035.92},
                    {1121.75, -1031},
                    {1120.83, -1026.5},
                    {1118.67, -1021},
                    {1116.5,  -1015.08},
                    {1110.83, -1003.33},
                    {1107.67, -998.167},
                    {1102.5,  -987.833},
                    {1097.5,  -980.167},
                    {1074.17, -947},
                    {1070.83, -942.667},
                    {1067.17, -937},
                    {1062.83, -931.667},
                    {1059.83, -928.5},
                    {1055.67, -924},
                    {1051.67, -918.333},
                    {1048.17, -914.167},
                    {1029.67, -887.833},
                    {1021.33, -877.833},
                    {1014.5,  -868.833},
                    {1009,    -862.75},
                    {1005,    -857.25},
                    {1002,    -852.75},
                    {996,     -846.5},
                    {987,     -836.5},
                    {982.5,   -829.25},
                    {977.25,  -820},
                    {973,     -812.5},
                    {969.833, -805.667},
                    {966.167, -794.5},
                    {961.667, -784.167},
                    {956.5,   -772.667},
                    {950.667, -758.167},
                    {951,     -756},
                    {956.333, -754},
                    {956.167, -754.667},
                    {959.333, -753.667},
                    {963.167, -750},
                    {968,     -744.167},
                    {972.167, -738.667},
                    {976.5,   -731.833},
                    {978.667, -726.333},
                    {980,     -714.25},
                    {982,     -722.5},
                    {982.25,  -730.5},
                    {981.5,   -738.5},
                    {980.5,   -745},
                    {977.5,   -752.75},
                    {981.75,  -747.25},
                    {984.25,  -742.5},
                    {985.75,  -736.25},
                    {987.25,  -728},
                    {988.5,   -719.25},
                    {989.5,   -707.5},
                    {990,     -696.5},
                    {989.5,   -688},
                    {990.5,   -693.75},
                    {991,     -696.5},
                    {992.5,   -700.5},
                    {993.5,   -704.125},
                    {995,     -706.625},
                    {995.875, -711.125},
                    {997,     -715.625},
                    {997.125, -720},
                    {996.875, -725.625},
                    {996,     -732.875},
                    {998.75,  -729.375},
                    {1001.62, -721.75},
                    {1003,    -717.125},
                    {1003.38, -712.5},
                    {1003.75, -707},
                    {1004.25, -699.25},
                    {1003.25, -687.875},
                    {1008,    -696.125},
                    {1012.12, -702.875},
                    {1015.62, -709.375},
                    {1018.75, -717},
                    {1023.5,  -729},
                    {1024.25, -733.125},
                    {1023.38, -741},
                    {1021.5,  -746.875},
                    {1012,    -758.125},
                    {1019.88, -754.75},
                    {1025.5,  -747.625},
                    {1028.25, -743.25},
                    {1030.38, -731.25},
                    {1029,    -723.25},
                    {1010,    -681.125},
                    {1007.12, -675.125},
                    {1005.38, -667},
                    {1003.38, -659.625},
                    {994.5,   -631},
                    {983.5,   -600.25},
                    {979,     -589.5},
                    {972.75,  -581.5},
                    {967.75,  -574.25},
                    {963.5,   -568.75},
                    {961.75,  -563.5},
                    {956.5,   -554.75},
                    {967.5,   -571.667},
                    {971.583, -576.167},
                    {977.083, -582.167},
                    {982.333, -588.417},
                    {995.667, -604.667},
                    {1002.67, -615},
                    {1009.33, -626},
                    {1015.83, -637.167},
                    {1020.5,  -647.667},
                    {1025.33, -660.667},
                    {1027.33, -667.5},
                    {1028.67, -679.333},
                    {1028.17, -691.833},
                    {1026.33, -698.833},
                    {1025,    -702.333},
                    {1029,    -696.333},
                    {1031.5,  -689.5},
                    {1032.5,  -683.167},
                    {1031,    -671},
                    {1028,    -658.667},
                    {1026.83, -654.667},
                    {1029.5,  -657.667},
                    {1034.83, -665},
                    {1038.17, -670.667},
                    {1041.33, -680.833},
                    {1041.5,  -689.667},
                    {1039.33, -694.5},
                    {1037,    -698.667},
                    {1033,    -702.5},
                    {1030.17, -704.333},
                    {1026.5,  -705.5},
                    {1025,    -706},
                    {1024.83, -707.167},
                    {1025.67, -708.167},
                    {1029.17, -707.833},
                    {1034.67, -704.5},
                    {1038.83, -701},
                    {1043,    -694.333},
                    {1044.5,  -686},
                    {1044.33, -678.833},
                    {1042.5,  -674},
                    {1039.67, -668.167},
                    {1036.17, -662.167},
                    {1028,    -652.167},
                    {1025.67, -651.667},
                    {1021.12, -641.375},
                    {1017.38, -633.875},
                    {1015,    -627.125},
                    {1016.62, -626},
                    {1016.62, -621.25},
                    {1015.5,  -610.125},
                    {1012.75, -598.625},
                    {1008.75, -588.125},
                    {1002.75, -577.125},
                    {998.375, -570.125},
                    {992.375, -561.25},
                    {982.125, -550.125},
                    {977.125, -544.625},
                    {967.25,  -534.75},
                    {959.875, -527.25},
                    {951.875, -518.75},
                    {950.5,   -517.5},
                    {947.875, -517.25},
                    {944.25,  -514.75},
                    {938.375, -507.625},
                    {933.25,  -500.75},
                    {929.875, -496.625},
                    {924.833, -486.667},
                    {920.5,   -478.333},
                    {915.667, -470.5},
                    {912.833, -465.167},
                    {910.833, -460.833},
                    {909,     -455.5},
                    {907,     -450.167},
                    {904.5,   -445.833},
                    {899.833, -438.167},
                    {893.5,   -429},
                    {882.667, -414.833},
                    {876,     -408},
                    {864.667, -395.833},
                    {858.333, -391},
                    {854.167, -388.333},
                    {849.167, -386.833},
                    {843.083, -387.25},
                    {840.5,   -388.167},
                    {837.5,   -389.25},
                    {835.5,   -389.083},
                    {831.833, -387.667},
                    {830.312, -387.375},
                    {828.062, -387.312},
                    {826.125, -387.75},
                    {823.188, -388.5},
                    {820.438, -389.938},
                    {819.062, -390.562},
                    {817.812, -391.688},
                    {815.125, -393.812},
                    {813.312, -395.688},
                    {811.312, -397.938},
                    {809.375, -400.562},
                    {806.5,   -405.688},
                    {802.688, -402.5},
                    {796.375, -397.292},
                    {788.875, -387.833},
                    {782.25,  -378.917},
                    {780.083, -377},
                    {776.833, -374.833},
                    {772.583, -372.5},
                    {769.167, -371.583},
                    {763.333, -371.167},
                    {738.438, -370.25},
                    {736.875, -370.125},
                    {734.625, -370.875},
                    {718,     -381.5},
                    {714.625, -383},
                    {707.25,  -385.875},
                    {702.625, -387.25},
                    {699.25,  -388.625},
                    {694.375, -390.625},
                    {689.375, -393.25},
                    {683.875, -396.5},
                    {676.75,  -401},
                    {670.625, -405.375},
                    {665.625, -409.625},
                    {663.25,  -413.625},
                    {662.5,   -411.5},
                    {661.125, -410.5},
                    {659.5,   -409.875},
                    {656.625, -409.125},
                    {654.25,  -408.875},
                    {651,     -409.25},
                    {648.5,   -409.5},
                    {646.625, -409.812},
                    {643.25,  -410.5},
                    {638.688, -411.938},
                    {631.625, -415.312},
                    {626.312, -418.438},
                    {617.25,  -424.125},
                    {612,     -427.875},
                    {603.875, -433.375},
                    {598.875, -437.75},
                    {597,     -439.5},
                    {589.833, -440.167},
                    {575.833, -443.5},
                    {566.833, -447.667},
                    {551.333, -455},
                    {542,     -461.5},
                    {535.25,  -466.75},
                    {530.625, -471.5},
                    {526,     -476.375},
                    {520.375, -482.5},
                    {514.25,  -490},
                    {510.625, -495.875},
                    {507.875, -499},
                    {503.5,   -505.25},
                    {500.625, -509.625},
                    {498.5,   -511.25},
                    {496,     -512.125},
                    {494.437, -513},
                    {492.687, -515.125},
                    {489,     -520.938},
                    {485.875, -526.438},
                    {484.833, -522.667},
                    {484.333, -520.583},
                    {483.75,  -519.75},
                    {483.25,  -519.833},
                    {481.917, -520.667},
                    {480.25,  -521.75},
                    {478.417, -523.583},
                    {477.917, -524.167},
                    {476,     -522.25},
                    {474.083, -521.333},
                    {470.5,   -519.5},
                    {468.75,  -519.083},
                    {465.75,  -519.333},
                    {464.667, -520.5},
                    {465.167, -522.167},
                    {467,     -524.333},
                    {465.167, -524.25},
                    {463.333, -524.833},
                    {461.25,  -526.75},
                    {459.333, -529.25},
                    {458.167, -533},
                    {457.5,   -538.083},
                    {456.75,  -542.333},
                    {454.833, -543.167},
                    {453.5,   -545.5},
                    {450.833, -544.75},
                    {448.417, -544.75},
                    {443,     -546.583},
                    {436.833, -549.833},
                    {430.083, -553.667},
                    {425.5,   -557.75},
                    {422.083, -561.5},
                    {416.125, -571.125},
                    {412.062, -576.375},
                    {406.688, -584.375},
                    {402.625, -590.625},
                    {400,     -594.625},
                    {397.5,   -600.25},
                    {395.75,  -606.125},
                    {395.438, -609.875},
                    {394.75,  -612.438},
                    {394.625, -614.75},
                    {394.75,  -618},
                    {395.25,  -620.375},
                    {396.438, -621.562},
                    {395.5,   -625.5},
                    {392.583, -631.667},
                    {390.833, -636.917},
                    {389,     -645.333},
                    {387.333, -653.833},
                    {386.667, -661.833},
                    {386.167, -669},
                    {387,     -681.167},
                    {389.667, -688.167},
                    {395.667, -702},
                    {401.167, -709.333},
                    {407,     -717.5},
                    {413,     -725.667},
                    {421.875, -738.625},
                    {426.25,  -743.25},
                    {429.875, -748.5},
                    {436.5,   -753.75},
                    {443.125, -757.25},
                    {446.625, -760.375},
                    {454.375, -763.75},
                    {459.625, -764.875},
                    {465.75,  -767.125},
                    {470.5,   -769.625},
                    {473.75,  -773.375},
                    {479.125, -780.25},
                    {481.5,   -784.667},
                    {486.167, -777.333},
                    {490.167, -772},
                    {494.833, -767.833},
                    {499.333, -765.833},
                    {504,     -764},
                    {508,     -764.5},
                    {514.833, -764.833},
                    {519.333, -767.667},
                    {523.667, -774.167},
                    {527.333, -780.833},
                    {534.833, -798.667},
                    {540,     -805.5},
                    {546.5,   -814.833},
                    {555.333, -824.167},
                    {562.833, -833.167},
                    {569.438, -842.125},
                    {577.75,  -853.5},
                    {581.667, -861.167},
                    {582.188, -861.312},
                    {575.312, -838.188},
                    {564.125, -802.188},
                    {559.5,   -798.625},
                    {556.125, -794.625},
                    {551.125, -789},
                    {547,     -786},
                    {538.75,  -777.625},
                    {536.688, -774},
                    {534.75,  -769.5},
                    {533.438, -764.375},
                    {533.25,  -750.125},
                    {533.25,  -739.375},
                    {534.625, -730.5},
                    {537.75,  -720.75},
                    {542.625, -712.375},
                    {547.5,   -708.125},
                    {553.375, -704.875},
                    {558.875, -704.625}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glEnable(GL_STENCIL_TEST);          // enable stencil test
            glEnable(GL_DEPTH_TEST);

            // PASS 1: draw to stencil buffer only
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
            glStencilFunc(GL_ALWAYS, 1, 1);
            glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

            glBegin(GL_POLYGON);
            //VERTICES
            for (int i = 0; i < size; ++i)
                glVertex2dv(vertices[i]);
            glEnd();

            // PASS 2: draw color buffer
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
            glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
            glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
            glDisable(GL_DEPTH_TEST);

            glBegin(GL_POLYGON);
            glColor4d(125 / 255.0f, 61 / 255.0f, 35 / 255.0f, 1.0);
            glVertex2d(768, -525);
            for (int i = 0; i < size; ++i) {
                if ((vertices[i][0] <= 600 && vertices[i][1] >= -935) ||
                    (vertices[i][0] <= 806 && vertices[i][1] <= -067))
                    glColor4d(125 / 255.0f, 61 / 255.0f, 35 / 255.0f, 1.0);
                else
                    glColor4d(178 / 255.0f, 95 / 255.0f, 46 / 255.0f, 1.0);
                glVertex2dv(vertices[i]);
            }
            glVertex2dv(vertices[0]);
            glEnd();
            glDisable(GL_STENCIL_TEST);
        }
        //95
        /*{
            double vertices[][2] = {
                    { 766.000, -528.000 },
                    { 889.500, -587.500 },
                    { 887.500, -572.000 },
                    { 875.500, -534.500 },
                    { 853.500, -486.000 },
                    { 816.500, -434.000 },
                    { 797.500, -424.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 178, 95, 46,0.005,true,178, 95, 46);
        }*/
        {
            glLineWidth(1);
            glBegin(GL_POLYGON);
            glColor4f(178/255.0f, 95/255.0f, 46/255.0f, 1);
            glVertex2d(889.500, -587.500+4);
            glColor4f(178/255.0f, 95/255.0f, 46/255.0f, 0.1);
            glVertex2d(887.500, -572.000);
            glVertex2d(875.500, -534.500);
            glVertex2d(766.000, -528.000+3);
            glEnd();
        }
    }
    //hair light1
    {
        double vertices[][2] = {
                {634.667, -543.500},
                {635.333, -525.500},
                {636.667, -513.000},
                {639.500, -497.500},
                {642.667, -485.500},
                {647.667, -473.333},
                {655.000, -458.333},
                {656.833, -452.500},
                {658.000, -453.500},
                {658.500, -457.000},
                {657.167, -462.000},
                {654.667, -470.000},
                {652.833, -477.667},
                {652.333, -483.000},
                {652.500, -485.833},
                {655.000, -479.667},
                {656.500, -477.000},
                {657.000, -477.000},
                {657.167, -479.833},
                {657.333, -484.167},
                {658.333, -484.833},
                {661.167, -480.833},
                {662.500, -476.167},
                {668.000, -463.667},
                {672.000, -451.833},
                {677.167, -442.667},
                {681.833, -435.500},
                {689.333, -428.000},
                {683.000, -436.000},
                {678.500, -445.500},
                {672.000, -461.500},
                {666.167, -480.000},
                {662.167, -498.167},
                {657.000, -514.667},
                {654.167, -520.667},
                {644.833, -511.167},
                {640.667, -520.500},
                {636.833, -533.500}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 165, 90, 53);
    }
    //hair light2
    {
        double vertices[][2] = {
                {719.375, -521.250},
                {727.000, -503.875},
                {730.250, -496.625},
                {734.375, -487.750},
                {737.375, -481.750},
                {737.875, -489.125},
                {732.000, -498.250},
                {732.000, -501.875},
                {726.000, -513.500}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 189, 116, 67);
    }
    //hair light3
    {
        double vertices[][2] = {
                {734.333, -530.000},
                {735.000, -515.083},
                {736.917, -503.083},
                {739.750, -490.750},
                {742.667, -481.333},
                {746.750, -473.000},
                {746.167, -488.583},
                {742.500, -497.000},
                {739.667, -506.750},
                {736.917, -518.250},
                {735.667, -523.750}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 186, 112, 62);
    }
    //hair light4
    {
        double vertices[][2] = {
                {734.250, -543.500},
                {737.750, -529.125},
                {739.625, -519.375},
                {742.750, -509.875},
                {744.750, -502.375},
                {748.000, -494.125},
                {750.625, -486.875},
                {750.750, -494.500},
                {748.750, -498.875},
                {748.375, -505.125},
                {747.250, -512.125},
                {745.250, -521.125},
                {742.875, -526.875},
                {739.875, -533.125}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 173, 100, 54);
    }
    //hair light5
    {
        double vertices[][2] = {
                {748.375, -519.000},
                {751.500, -509.750},
                {753.250, -503.375},
                {753.250, -497.250},
                {755.250, -492.625},
                {758.500, -483.750},
                {756.875, -491.875},
                {755.875, -496.125},
                {756.000, -499.750},
                {755.000, -503.750},
                {755.625, -517.125},
                {753.750, -515.500},
                {752.375, -514.750},
                {751.625, -515.375}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 172, 99, 54);
    }
    //hair light6
    {
        double vertices[][2] = {
                {761.667, -560.167},
                {764.833, -544.833},
                {766.333, -534.167},
                {766.500, -525.167},
                {766.500, -511.833},
                {766.500, -494.000},
                {767.333, -487.000},
                {768.833, -478.667},
                {772.833, -471.500},
                {775.333, -467.500},
                {774.167, -474.167},
                {772.333, -481.167},
                {771.000, -488.333},
                {770.333, -495.833},
                {769.000, -508.333},
                {768.333, -520.500},
                {767.500, -530.833},
                {766.000, -540.667}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 158, 87, 49);
    }
    //hair light7
    {
        double vertices[][2] = {
                {782.750, -486.417},
                {780.417, -495.917},
                {779.333, -498.917},
                {779.333, -523.583},
                {780.250, -533.583},
                {780.917, -519.667},
                {784.833, -513.417},
                {786.583, -509.167},
                {785.250, -492.167}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 153, 82, 46);
    }
    //hair light8
    {
        double vertices[][2] = {
                {810.500, -512.750},
                {810.250, -515.500},
                {809.500, -517.250},
                {807.875, -516.125},
                {805.875, -513.375},
                {805.000, -508.750},
                {804.625, -503.500},
                {804.750, -495.000},
                {809.125, -513.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 183, 108, 60);
    }
    //hair light9
    {
        double vertices[][2] = {
                {819.062, -507.000},
                {820.875, -517.500},
                {820.938, -523.250},
                {820.688, -526.250},
                {819.812, -526.062},
                {811.688, -507.500},
                {812.167, -492.667},
                {812.667, -492.167},
                {819.667, -501.500},
                {821.417, -503.167},
                {822.083, -502.500},
                {820.250, -496.000},
                {816.917, -482.833},
                {814.167, -473.750},
                {810.000, -465.083},
                {818.750, -483.833},
                {823.917, -495.250},
                {827.417, -505.833},
                {829.333, -514.917},
                {830.167, -522.333},
                {829.667, -523.667}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 190, 112, 61);
    }
    //hair light10
    {
        double vertices[][2] = {
                {830.833, -509.167},
                {834.667, -521.000},
                {838.000, -533.833},
                {843.333, -555.167},
                {846.667, -569.500},
                {849.000, -581.500},
                {849.000, -574.667},
                {848.833, -566.667},
                {848.333, -560.500},
                {847.000, -549.000},
                {844.333, -536.167},
                {840.333, -524.333},
                {835.500, -513.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 246, 172, 102);
    }
    //hair light11
    {
        glColor4f(190/225.0f,115/225.0f,60/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(856.750, -527.500);
        glVertex2f(851.875, -524.375);
        glVertex2f(848.000, -520.000);
        glVertex2f(844.750, -515.000);
        glVertex2f(843.000, -509.250);
        glVertex2f(842.625, -504.375);
        glVertex2f(843.125, -500.250);
        glVertex2f(843.625, -497.875);
        glVertex2f(845.250, -496.250);
        glVertex2f(846.750, -495.750);
        glVertex2f(848.250, -495.375);
        glVertex2f(851.375, -495.500);
        glVertex2f(854.125, -497.500);
        glVertex2f(856.000, -501.250);
        glVertex2f(857.375, -505.750);
        glVertex2f(858.375, -510.000);
        glVertex2f(858.875, -514.750);
        glVertex2f(858.875, -519.125);
        glVertex2f(858.125, -523.625);
        glEnd();

    }
    //hair light -1
    {
        double vertices[][2] = {
                {590.000, -520.833},
                {596.250, -513.250},
                {602.167, -506.083},
                {606.917, -499.750},
                {613.000, -490.750},
                {617.917, -482.917},
                {618.417, -486.000},
                {617.750, -489.500},
                {614.250, -495.000},
                {608.500, -503.333},
                {602.917, -510.083},
                {597.167, -515.250}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 150, 79, 46);
    }
    //hair light -2
    {
        glColor4f(137/225.0f,76/225.0f,51/225.0f,1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(537.000, -528.500);
        glVertex2f(537.167, -525.417);
        glVertex2f(537.583, -522.917);
        glVertex2f(538.833, -520.167);
        glVertex2f(541.250, -517.917);
        glVertex2f(541.250, -539.667);
        glVertex2f(540.083, -537.333);
        glVertex2f(538.500, -534.583);
        glVertex2f(537.417, -531.917);
        glEnd();

    }

    //HL 2-1
    {
        double vertices[][2] = {
                {840.833, -710.333},
                {841.875, -700.875},
                {843.625, -686.500},
                {845.375, -673.250},
                {846.625, -662.375},
                {848.375, -641.250},
                {848.875, -657.875},
                {848.250, -672.250},
                {845.375, -687.625},
                {842.875, -701.188}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 227, 150, 84);
    }
    //HL 2-2
    {
        double vertices[][2] = {
                {849.000, -582.500},
                {853.667, -615.167},
                {853.833, -625.667},
                {855.000, -640.833},
                {857.167, -653.333},
                {858.167, -662.167},
                {859.667, -668.333},
                {860.167, -681.167},
                {860.000, -698.833},
                {859.500, -709.833},
                {855.667, -716.333},
                {844.667, -725.667},
                {856.167, -719.167},
                {867.333, -700.667},
                {873.667, -667.333},
                {876.333, -644.833},
                {875.583, -631.167},
                {872.667, -618.167},
                {861.333, -585.500},
                {862.833, -615.167},
                {860.667, -618.833},
                {859.500, -617.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 253, 219, 135);
    }
    //HL 2-3
    {
        double vertices[][2] = {
                {881.500, -627.250},
                {880.000, -602.750},
                {878.000, -584.500},
                {874.250, -566.500},
                {880.250, -587.500},
                {884.250, -601.000},
                {888.750, -618.750},
                {890.000, -633.500},
                {890.250, -643.500},
                {890.000, -655.250},
                {888.250, -674.250},
                {887.250, -677.750},
                {885.500, -675.750},
                {886.250, -649.000},
                {884.000, -644.000},
                {882.500, -635.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 252, 215, 135);
    }
    //HL 2-4
    {
        double vertices[][2] = {
                {884.125, -588.875},
                {882.625, -576.250},
                {879.250, -561.500},
                {875.750, -544.125},
                {873.250, -535.875},
                {869.417, -525.833},
                {867.000, -522.000},
                {864.250, -517.750},
                {861.500, -511.500},
                {857.000, -502.500},
                {853.000, -494.000},
                {848.750, -485.500},
                {847.875, -483.750},
                {846.875, -481.000},
                {847.375, -480.750},
                {848.625, -482.000},
                {853.750, -488.875},
                {858.500, -498.125},
                {862.750, -508.000},
                {864.250, -513.250},
                {865.750, -516.625},
                {867.750, -520.000},
                {869.750, -522.250},
                {874.875, -534.875},
                {881.000, -554.875},
                {884.125, -567.500},
                {888.667, -588.667},
                {889.417, -600.583},
                {890.417, -612.750},
                {888.500, -601.167},
                {886.917, -595.083},
                {885.833, -592.083}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 245, 205, 114);
    }

    //HL 2-5 (upper light)
    {
        glBegin(GL_POLYGON);
        glColor4f(173/225.0f,92/225.0f,38/225.0f,1.0f);
        glVertex2f(889.250, -545.000);
        glVertex2f(899.000, -502.000);
        glColor4f(173/225.0f,92/225.0f,38/225.0f,0.0f);
        glVertex2f(870.500, -462.750);
        glVertex2f(858.250, -472.750);
        glEnd();

    }

    //HL 2-5
    {
        double vertices[][2] = {
                {890.000, -586.750},
                {889.750, -581.000},
                {890.250, -572.750},
                {889.250, -560.750},
                {887.500, -545.750},
                {885.000, -536.750},
                {882.000, -530.500},
                {877.500, -522.500},
                {874.750, -516.250},
                {872.250, -509.750},
                {871.000, -502.000},
                {868.500, -497.000},
                {864.500, -489.000},
                {859.000, -481.000},
                {854.750, -474.500},
                {847.500, -464.250},
                {840.250, -454.500},
                {834.750, -449.000},
                {837.250, -449.000},
                {847.500, -458.250},
                {856.250, -469.750},
                {867.750, -489.000},
                {875.000, -503.250},
                {880.750, -514.250},
                {885.000, -524.500},
                {888.500, -533.500},
                {890.500, -542.000},
                {892.000, -550.000},
                {893.250, -564.250},
                {893.500, -577.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 251, 207, 122);
    }
    //hL 2-6
    {
        double vertices[][2] = {
                {892.250, -596.500},
                {894.250, -580.000},
                {895.000, -560.750},
                {893.000, -545.250},
                {903.250, -558.000},
                {907.250, -568.000},
                {919.750, -604.500},
                {923.500, -618.500},
                {929.750, -645.500},
                {933.000, -669.500},
                {934.250, -684.000},
                {935.500, -699.500},
                {936.250, -709.750},
                {934.250, -723.750},
                {926.000, -743.500},
                {915.000, -756.250},
                {914.250, -755.000},
                {919.250, -750.000},
                {921.750, -747.500},
                {922.500, -739.250},
                {924.000, -731.250},
                {926.500, -719.000},
                {928.000, -707.250},
                {928.750, -693.750},
                {929.000, -685.000},
                {926.750, -673.750},
                {919.250, -663.250},
                {909.750, -638.500},
                {901.500, -618.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 204, 111, 46);
    }
    //HL 2-7
    {
        double vertices[][2] = {
                {903.750, -559.750},
                {909.625, -577.000},
                {918.750, -603.250},
                {926.250, -627.750},
                {929.750, -647.000},
                {935.500, -685.000},
                {936.500, -702.750},
                {935.500, -721.000},
                {929.500, -737.000},
                {921.750, -749.250},
                {915.250, -754.250},
                {913.500, -756.750},
                {913.750, -758.750},
                {915.250, -758.750},
                {918.500, -755.750},
                {925.750, -748.000},
                {934.250, -734.750},
                {939.750, -723.250},
                {944.000, -711.500},
                {948.750, -698.250},
                {952.000, -686.000},
                {953.500, -670.750},
                {952.250, -659.250},
                {955.000, -678.250},
                {955.000, -694.250},
                {954.500, -714.500},
                {951.250, -725.250},
                {947.750, -733.750},
                {942.750, -740.250},
                {940.000, -744.000},
                {940.500, -747.750},
                {942.500, -751.250},
                {947.000, -756.000},
                {950.000, -755.750},
                {960.750, -750.750},
                {974.250, -732.500},
                {979.000, -716.250},
                {978.750, -696.750},
                {979.917, -716.500},
                {982.083, -723.750},
                {982.250, -728.833},
                {982.083, -733.667},
                {981.667, -738.917},
                {981.333, -743.250},
                {980.083, -747.583},
                {977.833, -753.167},
                {980.833, -746.167},
                {982.000, -740.500},
                {985.333, -721.833},
                {985.667, -711.333},
                {987.000, -691.333},
                {985.000, -681.167},
                {982.167, -672.167},
                {977.667, -661.667},
                {975.667, -696.833},
                {974.500, -695.167},
                {973.667, -692.333},
                {971.833, -681.500},
                {966.500, -643.833},
                {963.667, -632.833},
                {959.667, -617.500},
                {955.833, -601.500},
                {951.500, -583.750},
                {976.750, -636.750},
                {983.000, -651.500},
                {989.750, -672.750},
                {996.250, -693.500},
                {998.833, -703.667},
                {998.833, -714.667},
                {997.500, -719.833},
                {996.667, -731.833},
                {1002.500, -716.333},
                {1003.833, -702.667},
                {1003.833, -692.833},
                {1003.667, -688.500},
                {1012.500, -703.333},
                {1020.333, -719.000},
                {1022.833, -727.167},
                {1024.000, -729.833},
                {1024.167, -721.500},
                {1018.167, -704.500},
                {1012.333, -688.333},
                {1007.000, -676.833},
                {981.667, -598.333},
                {978.667, -590.333},
                {968.333, -576.667},
                {957.000, -557.333},
                {932.667, -570.333},
                {939.667, -593.667},
                {929.833, -569.167},
                {923.333, -550.667},
                {915.833, -532.833},
                {907.667, -513.500},
                {902.333, -503.667},
                {894.167, -490.667},
                {881.333, -474.000},
                {874.167, -466.167},
                {879.500, -476.000},
                {890.333, -492.833},
                {891.500, -498.833},
                {898.167, -510.833},
                {905.333, -520.333},
                {907.167, -524.667},
                {914.000, -542.833},
                {915.500, -548.000},
                {919.167, -559.167},
                {924.000, -573.667},
                {930.000, -588.500},
                {935.500, -599.667},
                {938.667, -608.167},
                {941.333, -615.833},
                {943.500, -623.667},
                {946.500, -634.667},
                {949.333, -647.000},
                {950.833, -655.000},
                {946.167, -640.000},
                {942.667, -631.333},
                {940.333, -625.500},
                {934.667, -614.500},
                {930.000, -605.500},
                {927.500, -600.667},
                {925.000, -595.333},
                {921.500, -590.667},
                {917.500, -582.500},
                {914.167, -576.667},
                {910.500, -570.333},
                {908.000, -565.333}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 255, 223, 151);
    }
    //HL 2-6.5
    {
        double vertices[][2] = {
                {890.333, -510.750},
                {888.667, -506.250},
                {888.000, -502.583},
                {886.417, -499.250},
                {884.417, -495.500},
                {884.000, -493.917},
                {888.583, -498.083},
                {892.667, -503.333},
                {895.333, -507.917},
                {896.917, -512.000},
                {897.333, -515.833},
                {898.833, -525.167}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 245, 207, 124);
    }
    //HL 2-6 under light
    {
        double vertices[][2] = {
                {948.000, -645.250},
                {944.250, -627.500},
                {940.500, -615.750},
                {934.000, -595.500},
                {921.250, -564.000},
                {910.750, -534.750},
                {906.250, -524.000},
                {899.250, -511.750},
                {902.500, -528.000},
                {898.250, -526.750},
                {890.250, -516.250},
                {892.250, -526.500},
                {892.250, -540.750},
                {904.500, -557.500},
                {911.250, -568.250},
                {918.000, -582.000},
                {926.750, -598.250},
                {936.250, -616.250},
                {943.250, -632.750}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 182, 93, 35);
    }

    //HL 2-8
    {
        double vertices[][2] = {
                {952.167, -541.667},
                {952.833, -553.250},
                {932.417, -570.333},
                {957.833, -556.583},
                {965.333, -569.083},
                {971.417, -576.750},
                {982.000, -588.000},
                {993.750, -602.750},
                {1000.917, -612.917},
                {1009.833, -625.833},
                {1015.333, -635.500},
                {1020.333, -646.750},
                {1024.750, -658.500},
                {1027.333, -667.667},
                {1028.333, -674.250},
                {1029.417, -682.750},
                {1029.000, -689.583},
                {1027.583, -697.500},
                {1030.667, -690.667},
                {1032.000, -683.750},
                {1030.250, -671.167},
                {1028.333, -662.917},
                {1026.500, -656.833},
                {1026.167, -654.333},
                {1034.167, -663.833},
                {1039.000, -672.167},
                {1041.000, -677.333},
                {1042.188, -684.938},
                {1042.062, -687.562},
                {1041.583, -692.000},
                {1040.042, -695.042},
                {1038.042, -698.792},
                {1036.500, -700.792},
                {1034.125, -702.917},
                {1031.792, -704.583},
                {1027.750, -706.333},
                {1025.500, -707.083},
                {1025.375, -707.625},
                {1028.458, -707.708},
                {1031.833, -706.500},
                {1037.500, -702.208},
                {1041.667, -696.125},
                {1043.667, -690.500},
                {1044.167, -686.583},
                {1044.083, -680.500},
                {1043.667, -678.917},
                {1041.167, -672.000},
                {1038.750, -667.667},
                {1036.583, -663.875},
                {1034.250, -660.875},
                {1030.938, -656.750},
                {1028.438, -653.438},
                {1028.000, -653.000},
                {1028.625, -655.000},
                {1026.188, -653.438},
                {1025.500, -652.188},
                {1021.062, -641.625},
                {1020.000, -639.500},
                {1018.750, -636.500},
                {1016.438, -631.500},
                {1015.000, -627.688},
                {1016.750, -627.375},
                {1016.812, -625.438},
                {1016.750, -621.000},
                {1014.667, -606.750},
                {1011.833, -596.917},
                {1008.500, -588.667},
                {1002.250, -577.333},
                {996.583, -568.333},
                {991.750, -561.500},
                {985.167, -553.750},
                {972.167, -540.000},
                {958.500, -526.333},
                {950.500, -518.333},
                {947.625, -517.875},
                {945.625, -516.500},
                {936.500, -505.250},
                {933.125, -500.875},
                {928.250, -493.125},
                {927.125, -491.875},
                {920.125, -491.625},
                {914.625, -486.500},
                {907.000, -479.375},
                {902.250, -473.000},
                {899.250, -468.375},
                {903.000, -482.500},
                {907.250, -494.375},
                {912.375, -504.875},
                {919.250, -518.000},
                {927.125, -525.625},
                {933.375, -530.250},
                {936.875, -532.125},
                {937.750, -530.500},
                {936.750, -523.250},
                {931.625, -511.500}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 250, 220, 143);
    }
    //HL UnderLight (triangle)
    {
        double vertices[][2] = {
                {975.333, -695.333},
                {972.000, -687.000},
                {970.000, -672.333},
                {968.000, -658.000},
                {966.333, -646.000},
                {963.000, -631.667},
                {957.667, -610.000},
                {951.667, -584.000},
                {975.000, -632.000},
                {987.667, -661.667},
                {993.333, -687.000},
                {998.000, -699.000},
                {999.000, -717.000},
                {998.333, -721.667},
                {989.000, -688.333},
                {989.667, -715.667},
                {986.333, -735.667},
                {979.333, -751.000},
                {985.667, -726.667},
                {987.667, -703.333},
                {986.333, -688.333},
                {981.000, -670.333},
                {978.667, -660.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 205, 117, 47);
    }
    //HL UnderLight before go up
    {
        double vertices[][2] = {
                {929.500, -569.000},
                {953.500, -554.000},
                {952.250, -542.500},
                {932.500, -512.000},
                {935.500, -520.000},
                {936.750, -524.500},
                {937.750, -529.250},
                {937.500, -531.500},
                {931.000, -528.750},
                {923.500, -522.500},
                {919.500, -517.750},
                {914.500, -509.250},
                {908.250, -496.000},
                {902.000, -482.500},
                {899.000, -468.250},
                {905.000, -477.500},
                {910.250, -483.000},
                {919.000, -490.750},
                {916.750, -481.500},
                {907.500, -467.250},
                {893.500, -450.500},
                {879.333, -461.333},
                {868.667, -452.000},
                {864.333, -447.000},
                {862.000, -447.000},
                {861.667, -448.333},
                {877.667, -469.333},
                {889.333, -482.333},
                {896.667, -493.333},
                {905.333, -507.667},
                {913.333, -522.667},
                {919.000, -536.667},
                {924.000, -551.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 197, 103, 40);
    }
    //HL 2-9
    {
        double vertices[][2] = {
                {920.500, -491.500},
                {927.250, -491.375},
                {924.500, -486.625},
                {920.750, -480.000},
                {916.875, -473.625},
                {912.125, -463.375},
                {908.250, -454.250},
                {904.625, -446.625},
                {896.125, -433.125},
                {879.750, -412.500},
                {870.500, -401.500},
                {860.750, -392.500},
                {853.833, -388.167},
                {850.000, -387.000},
                {846.167, -387.000},
                {842.167, -387.500},
                {839.500, -389.000},
                {837.333, -392.833},
                {844.500, -391.167},
                {849.333, -391.333},
                {853.833, -392.667},
                {858.500, -396.333},
                {888.833, -430.833},
                {906.500, -456.333},
                {895.500, -445.000},
                {891.000, -439.667},
                {887.333, -436.333},
                {883.333, -433.000},
                {880.833, -431.167},
                {878.000, -428.167},
                {873.500, -423.500},
                {880.167, -434.667},
                {884.167, -440.167},
                {890.167, -447.333},
                {903.167, -461.833},
                {914.000, -476.500},
                {918.000, -484.333}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 249, 209, 116);
    }

    //1_st upper light
    {
        double vertices[][2] = {
                {836.167, -393.667},
                {839.500, -389.667},
                {836.667, -389.833},
                {832.167, -389.167},
                {829.833, -388.833},
                {826.833, -389.333},
                {822.000, -390.333},
                {818.667, -392.333},
                {814.667, -396.000},
                {810.833, -400.667},
                {806.833, -407.167},
                {796.833, -399.833},
                {794.500, -397.333},
                {793.167, -395.833},
                {790.000, -391.000},
                {784.833, -384.000},
                {782.500, -380.500},
                {779.500, -378.000},
                {775.750, -375.583},
                {771.333, -373.417},
                {768.000, -373.000},
                {757.417, -372.167},
                {749.750, -372.000},
                {736.917, -372.000},
                {733.625, -372.875},
                {717.125, -383.250},
                {709.375, -386.375},
                {702.250, -388.750},
                {695.375, -391.750},
                {686.250, -396.375},
                {679.750, -400.250},
                {673.250, -405.250},
                {668.000, -409.500},
                {665.500, -411.875},
                {664.875, -413.625},
                {665.750, -414.250},
                {670.125, -411.250},
                {679.125, -404.500},
                {689.375, -398.500},
                {698.625, -393.875},
                {707.625, -390.250},
                {711.625, -389.000},
                {715.125, -387.000},
                {717.625, -384.875},
                {715.000, -389.875},
                {707.500, -398.250},
                {704.250, -403.375},
                {702.250, -407.375},
                {704.500, -405.875},
                {712.875, -396.000},
                {719.125, -388.625},
                {723.250, -384.750},
                {729.583, -379.833},
                {733.750, -376.833},
                {738.083, -374.833},
                {742.667, -374.667},
                {762.188, -374.562},
                {764.750, -374.938},
                {766.250, -375.625},
                {766.625, -376.875},
                {765.938, -377.938},
                {761.875, -379.750},
                {755.750, -384.875},
                {749.688, -391.875},
                {745.250, -398.188},
                {741.812, -403.312},
                {736.375, -412.250},
                {730.750, -423.375},
                {727.125, -431.750},
                {724.375, -438.875},
                {723.000, -445.750},
                {727.375, -435.125},
                {732.000, -426.125},
                {738.375, -415.500},
                {746.000, -403.500},
                {751.500, -394.625},
                {758.750, -386.000},
                {762.750, -383.000},
                {767.688, -381.375},
                {770.438, -381.250},
                {773.188, -381.312},
                {775.812, -382.312},
                {778.375, -383.938},
                {784.125, -389.188},
                {803.917, -411.583},
                {804.917, -412.250},
                {806.875, -410.000},
                {812.125, -406.875},
                {820.875, -401.625},
                {826.875, -398.125},
                {831.625, -395.500}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 250, 196, 121);
    }
    //ellight elly ganb eltania elly fou2
    {
        double vertices[][2] = {
                {694.625, -514.875},
                {708.000, -482.000},
                {711.750, -477.750},
                {714.875, -466.875},
                {722.875, -445.625},
                {725.125, -436.250},
                {717.625, -451.875},
                {708.750, -473.000},
                {702.250, -488.500}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 169, 96, 50);
    }
    //elllight elly ganbaha
    {
        double vertices[][2] = {
                {691.750, -515.750},
                {699.000, -482.250},
                {702.000, -471.250},
                {704.250, -462.000},
                {713.000, -442.500},
                {716.750, -433.750},
                {722.000, -424.750},
                {725.750, -417.750},
                {733.250, -406.750},
                {728.000, -418.000},
                {726.500, -424.250},
                {723.750, -432.750},
                {718.000, -445.750},
                {714.750, -455.000},
                {708.750, -468.500},
                {703.750, -478.500},
                {700.000, -488.500},
                {697.000, -497.750}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 255, 201, 109);
    }
    //2_nd upper light
    {
        double vertices[][2] = {
                {661.812, -414.750},
                {662.000, -413.250},
                {661.250, -412.625},
                {658.875, -411.250},
                {655.750, -410.812},
                {649.438, -410.938},
                {643.812, -412.875},
                {627.875, -419.438},
                {621.562, -423.062},
                {615.688, -426.688},
                {611.375, -429.938},
                {607.312, -432.625},
                {602.062, -436.562},
                {596.688, -441.250},
                {593.750, -441.188},
                {589.750, -441.562},
                {586.438, -442.188},
                {578.188, -444.562},
                {567.250, -449.375},
                {556.750, -454.750},
                {551.375, -457.500},
                {546.750, -459.750},
                {542.375, -463.125},
                {534.750, -469.250},
                {529.250, -474.625},
                {519.250, -486.625},
                {513.375, -493.500},
                {507.375, -501.500},
                {502.500, -508.125},
                {516.000, -492.750},
                {526.500, -480.875},
                {534.000, -473.500},
                {542.125, -466.250},
                {554.417, -459.167},
                {558.250, -457.333},
                {563.000, -455.917},
                {568.125, -453.375},
                {576.750, -449.125},
                {587.625, -444.688},
                {589.938, -444.250},
                {591.375, -444.000},
                {589.500, -446.500},
                {588.625, -448.375},
                {588.688, -449.000},
                {589.625, -449.000},
                {591.688, -447.812},
                {601.875, -439.562},
                {619.688, -427.062},
                {622.750, -425.125},
                {626.625, -423.125},
                {630.188, -421.562},
                {636.625, -418.938},
                {644.688, -416.062},
                {647.625, -414.938},
                {651.250, -414.688},
                {654.188, -414.625},
                {658.125, -414.812}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 242, 183, 110);
    }
    //3_rd upper light
    {
        double vertices[][2] = {
                {487.750, -528.000},
                {493.667, -519.417},
                {496.583, -515.417},
                {497.500, -513.500},
                {497.167, -513.417},
                {496.000, -513.583},
                {493.833, -515.167},
                {492.417, -517.417},
                {490.167, -521.167},
                {488.083, -524.083},
                {486.833, -526.583}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 187, 113, 70);
    }
    //4_th upper light
    {
        double vertices[][2] = {
                {486.750, -526.333},
                {487.750, -528.167},
                {475.000, -556.167},
                {475.083, -551.917},
                {476.417, -546.917},
                {479.333, -539.750},
                {483.500, -531.250}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 128, 64, 38);
    }
    //5_th upper light
    {
        double vertices[][2] = {
                {475.969, -538.812},
                {477.469, -525.375},
                {477.000, -524.750},
                {475.625, -523.625},
                {469.219, -520.562},
                {467.812, -520.375},
                {466.188, -520.625},
                {465.594, -521.156},
                {465.438, -522.031},
                {466.625, -523.219},
                {469.781, -525.406},
                {471.406, -526.781},
                {471.656, -528.094},
                {471.469, -530.406},
                {471.438, -532.750},
                {471.875, -534.344},
                {472.438, -535.656},
                {473.042, -536.375},
                {473.917, -537.958},
                {474.750, -538.667}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 255, 189, 115);
    }
    //6_th upper light
    {
        double vertices[][2] = {
                {458.625, -542.938},
                {459.688, -538.375},
                {461.375, -534.188},
                {464.125, -529.938},
                {467.875, -528.125},
                {469.688, -527.312},
                {468.875, -526.000},
                {467.750, -525.438},
                {466.625, -525.312},
                {465.312, -525.312},
                {463.812, -525.750},
                {462.000, -527.125},
                {460.062, -529.188},
                {458.750, -532.938},
                {458.250, -536.125},
                {458.062, -539.125}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 255, 189, 115);
    }
    //7 upper light
    {
        double vertices[][2] = {
                {412.917, -577.500},
                {420.167, -570.583},
                {427.333, -564.083},
                {430.500, -561.750},
                {436.000, -558.833},
                {441.250, -557.583},
                {444.167, -557.417},
                {446.667, -558.000},
                {451.667, -560.167},
                {451.000, -556.375},
                {450.625, -552.875},
                {450.500, -551.500},
                {451.625, -549.500},
                {452.500, -547.125},
                {451.750, -546.188},
                {450.625, -545.812},
                {447.875, -546.250},
                {442.812, -547.812},
                {435.562, -551.875},
                {431.500, -554.500},
                {426.250, -558.750},
                {423.417, -561.750},
                {421.083, -565.250},
                {417.667, -570.083}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 241, 162, 100);
    }
    //last one
    {
        double vertices[][2] = {
                {399.167, -687.000},
                {402.667, -695.500},
                {405.833, -701.667},
                {409.833, -709.500},
                {414.583, -716.917},
                {418.833, -722.667},
                {423.583, -727.333},
                {431.167, -732.083},
                {434.083, -734.250},
                {439.167, -738.500},
                {444.167, -742.500},
                {450.083, -746.250},
                {455.250, -748.750},
                {458.333, -750.083},
                {459.917, -750.000},
                {460.583, -749.083},
                {459.917, -747.917},
                {458.000, -746.417},
                {451.583, -743.083},
                {448.083, -740.917},
                {443.083, -737.417},
                {435.000, -732.333},
                {433.083, -730.750},
                {428.000, -727.667},
                {421.750, -721.333},
                {417.833, -716.750},
                {411.750, -707.500},
                {408.125, -701.875},
                {404.000, -693.438},
                {400.875, -686.062}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 153, 78, 39);
    }

    //Light elHair men el4emal
    {
        double vertices[][2] = {
                {658.000, -830.750},
                {694.250, -971.250},
                {709.750, -1003.250},
                {715.000, -1019.500},
                {693.500, -972.500},
                {689.000, -965.750},
                {685.750, -962.250},
                {691.250, -983.000},
                {693.250, -1001.750},
                {695.750, -1018.500},
                {696.250, -1042.500},
                {694.250, -1058.250},
                {689.750, -1065.000},
                {696.500, -1058.500},
                {699.250, -1051.500},
                {701.000, -1041.500},
                {701.750, -1024.000},
                {700.250, -1013.250},
                {704.000, -1023.000},
                {708.000, -1033.000},
                {710.500, -1041.500},
                {713.750, -1056.750},
                {714.375, -1062.125},
                {713.125, -1048.000},
                {713.000, -1036.875},
                {711.625, -1030.125},
                {708.500, -1015.375},
                {713.250, -1026.250},
                {717.000, -1036.625},
                {718.625, -1044.500},
                {720.250, -1054.875},
                {720.625, -1045.125},
                {719.000, -1028.750},
                {716.250, -1013.750},
                {712.875, -995.375},
                {717.500, -1002.750},
                {724.625, -1016.750},
                {732.333, -1034.167},
                {737.250, -1052.667},
                {740.417, -1064.333},
                {745.125, -1085.375},
                {746.625, -1097.000},
                {746.500, -1114.625},
                {753.375, -1096.750},
                {755.625, -1083.500},
                {755.750, -1064.625},
                {754.500, -1050.000},
                {752.167, -1039.333},
                {742.000, -1007.875},
                {727.625, -964.375},
                {722.500, -950.375},
                {721.375, -936.625},
                {719.625, -928.625},
                {716.625, -916.375},
                {713.375, -905.000},
                {707.375, -886.750},
                {696.000, -858.333},
                {691.000, -845.167},
                {686.167, -834.667},
                {680.667, -822.000},
                {677.167, -814.500},
                {677.833, -821.500},
                {684.833, -840.833},
                {692.500, -865.833},
                {698.833, -886.000},
                {702.000, -905.833},
                {703.000, -913.500},
                {697.833, -898.500},
                {693.333, -891.500},
                {698.667, -915.667},
                {702.500, -931.167},
                {705.000, -946.667},
                {711.333, -962.667},
                {699.667, -938.500},
                {687.333, -911.500},
                {674.667, -878.833},
                {667.667, -858.167}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 253, 224, 151);
    }
    //Light elHair men el4emal (complete)
    {
        double vertices[][2] = {
                {753.000, -1039.250},
                {761.750, -1025.250},
                {766.333, -1014.750},
                {768.333, -1005.667},
                {769.833, -991.583},
                {769.583, -984.417},
                {767.667, -977.333},
                {767.833, -985.333},
                {767.000, -998.583},
                {765.500, -1008.583},
                {761.833, -1021.000},
                {755.500, -1030.500},
                {751.833, -1034.667}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 248, 222, 137);
    }
    //Light elHair men el4emal (complete)
    {
        double vertices[][2] = {
                {718.000, -861.500},
                {709.000, -830.500},
                {728.750, -863.000},
                {739.000, -878.250},
                {753.250, -899.500},
                {765.750, -913.250},
                {774.250, -923.250},
                {767.000, -910.500},
                {755.750, -895.750},
                {748.250, -885.000},
                {744.000, -877.000},
                {740.000, -872.000},
                {732.500, -860.500},
                {715.750, -831.500},
                {705.000, -811.750},
                {694.250, -789.750},
                {687.750, -775.500},
                {679.500, -758.750},
                {689.000, -783.250},
                {697.750, -801.500},
                {703.250, -820.000},
                {709.000, -837.500},
                {712.250, -852.000},
                {714.750, -859.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 248, 222, 137);
    }

    //elRa2aba
    {
        double vertices[][2] = {
                {716.500, -865.500},
                {719.500, -873.667},
                {720.833, -879.833},
                {721.833, -889.833},
                {722.167, -899.667},
                {722.167, -909.000},
                {721.667, -920.167},
                {720.000, -925.000},
                {720.167, -927.667},
                {722.667, -930.333},
                {761.167, -953.833},
                {762.833, -954.333},
                {754.167, -932.333},
                {747.333, -918.000},
                {732.500, -892.125},
                {723.250, -875.625}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 174, 90, 45);
    }
    {
        double vertices[][2] = {
                {743.375, -893.500},
                {750.500, -914.000},
                {753.875, -923.625},
                {755.500, -928.250},
                {757.875, -933.750},
                {762.375, -942.250},
                {765.500, -945.250},
                {767.750, -945.125},
                {768.375, -940.875},
                {768.500, -932.750},
                {762.125, -922.875},
                {758.750, -917.125},
                {753.750, -909.500},
                {748.250, -900.875}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 175, 91, 46);
    }
    {
        glBegin(GL_POLYGON);
        glColor4f(142/225.0f,68/225.0f,29/225.0f,1.0f);
        glVertex2f(729.125, -864.000);
        glColor4f(120/225.0f,53/225.0f,21/225.0f,1.0f);
        glVertex2f(740.000, -891.000);
        glVertex2f(742.000, -890.750);
        glVertex2f(743.375, -890.250);
        glVertex2f(744.125, -888.875);
        glVertex2f(744.625, -887.500);
        glEnd();

    }
    {
        double vertices[][2] = {
                {741.000, -889.625},
                {744.333, -887.250},
                {773.917, -923.583},
                {774.583, -922.333},
                {774.333, -920.000},
                {755.667, -895.167},
                {762.833, -900.583},
                {770.083, -903.917},
                {777.875, -907.000},
                {781.500, -908.250},
                {788.250, -909.625},
                {783.125, -913.875},
                {780.250, -918.750},
                {776.500, -925.625},
                {775.375, -927.000},
                {775.562, -928.312},
                {776.250, -929.875},
                {772.500, -934.083},
                {771.500, -938.417},
                {769.500, -943.333},
                {769.167, -944.583},
                {768.833, -932.333},
                {743.500, -892.917}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 113, 50, 20);
    }
    {
        double vertices[][2] = {
                {719.250, -927.375},
                {721.750, -935.750},
                {723.375, -943.250},
                {724.375, -951.875},
                {725.250, -956.125},
                {727.750, -959.375},
                {731.625, -961.625},
                {766.625, -978.250},
                {765.875, -970.375},
                {764.625, -963.500},
                {763.250, -956.625},
                {762.000, -953.875},
                {743.875, -944.000},
                {739.125, -941.375},
                {734.000, -938.375},
                {727.750, -934.250},
                {723.750, -931.375}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 191, 112, 61);
    }
    {
        double vertices[][2] = {
                {724.083, -953.333},
                {766.167, -983.250},
                {765.833, -997.167},
                {765.250, -1005.833},
                {763.000, -1014.000},
                {759.417, -1023.500},
                {753.167, -1031.167},
                {751.333, -1032.750},
                {738.417, -993.167},
                {734.417, -980.833},
                {730.250, -970.250}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 179, 106, 56);
    }
    {
        double vertices[][2] = {
                {732.917, -959.667},
                {731.417, -959.333},
                {730.583, -960.000},
                {730.667, -961.500},
                {735.583, -964.667},
                {740.500, -967.250},
                {745.333, -969.417},
                {750.833, -972.583},
                {755.583, -976.917},
                {759.583, -980.583},
                {764.000, -985.583},
                {765.167, -985.750},
                {765.250, -983.917},
                {765.333, -977.000},
                {763.750, -969.500},
                {761.833, -964.500},
                {759.167, -958.500},
                {758.500, -957.417},
                {758.083, -958.250},
                {758.000, -960.583},
                {758.333, -964.417},
                {758.333, -967.417},
                {757.750, -968.917},
                {755.583, -969.333},
                {753.083, -969.250},
                {750.333, -968.917},
                {747.917, -968.333},
                {745.917, -967.417}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 249, 222, 143);

        glColor4f(151/255.0f,91/255.0f,44/255.0f,1);
        glLineWidth(0.5);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < size; ++i)
        {
            glVertex2dv(vertices[i]);
        }
        glEnd();
    }
    {
        double vertices[][2] = {
                {757.750, -937.750},
                {762.500, -944.500},
                {765.000, -947.000},
                {766.000, -947.500},
                {768.000, -947.500},
                {770.000, -946.250},
                {773.125, -940.625},
                {773.875, -940.500},
                {774.500, -941.125},
                {774.500, -945.250},
                {772.000, -973.500},
                {772.875, -975.875},
                {774.250, -978.125},
                {777.500, -982.000},
                {781.333, -985.000},
                {782.667, -986.833},
                {784.667, -989.333},
                {785.667, -990.667},
                {785.167, -992.333},
                {783.667, -993.333},
                {780.333, -993.333},
                {775.667, -992.167},
                {770.833, -990.500},
                {770.167, -983.333},
                {769.000, -978.667},
                {767.375, -972.875},
                {766.250, -967.875},
                {764.375, -959.125},
                {761.250, -948.125}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 247, 209, 129);
    }

    //goz2 elBlouse elly fou2 el4a3r
    {
        double vertices[][2] = {
                {691.500, -1001.500},
                {670.500, -980.750},
                {652.250, -962.750},
                {641.500, -952.250},
                {635.750, -946.750},
                {627.000, -939.500},
                {621.250, -934.000},
                {618.000, -930.250},
                {618.500, -941.500},
                {618.750, -951.500},
                {621.500, -965.750},
                {626.000, -980.333},
                {629.250, -989.750},
                {635.250, -1000.750},
                {642.667, -1016.000},
                {649.750, -1028.500},
                {656.750, -1039.250},
                {662.250, -1048.000},
                {668.750, -1056.000},
                {678.750, -1063.750},
                {686.750, -1065.750},
                {691.000, -1063.500},
                {693.500, -1057.750},
                {694.500, -1047.000},
                {693.000, -1006.250}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
//        drawConcavePolygon(vertices, size, 165, 96, 52);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        glColor4d(165/255.0f,96/255.0f,52/255.0f,1);
        glVertex2dv(vertices[0]);
        glColor4d(140/255.0f,78/255.0f,49/255.0f,1);
        for (int i = 1; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();
        glDisable(GL_STENCIL_TEST);


        //elOutline beta3 elgoz2 elly fou2 el4a3r men elBlouse
        glColor4f(62/255.0f,24/255.0f,9/255.0f,1);
        glLineWidth(0.5);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < size; ++i)
        {
            glVertex2dv(vertices[i]);
        }
        glEnd();

        //elLines elly fou2 el7eta dy (elBlouse)
        //elLines elly fou2 el7eta dy (elBlouse) (lower one)
        glBegin(GL_LINE_STRIP);
        glVertex2f(645.167, -1020.667);
        glVertex2f(651.000, -1028.833);
        glVertex2f(656.667, -1035.667);
        glVertex2f(661.000, -1040.333);
        glVertex2f(668.333, -1047.333);
        glVertex2f(674.333, -1052.500);
        glVertex2f(679.000, -1055.167);
        glVertex2f(686.333, -1059.000);
        glVertex2f(691.667, -1060.500);
        glEnd();
        //elLines elly fou2 el7eta dy (elBlouse) (middle one)
        glBegin(GL_LINE_STRIP);
        glVertex2f(641.167, -985.917);
        glVertex2f(675.656, -990.562);
        glColor4f(62/255.0f,24/255.0f,9/255.0f,0.2);
        glVertex2f(682.250, -991.167);
        glEnd();
        //elLines elly fou2 el7eta dy (elBlouse) (upper one)
        glColor4f(62/255.0f,24/255.0f,9/255.0f,1);
        glBegin(GL_LINE_STRIP);
        glVertex2f(628.500, -969.500);
        glVertex2f(657.375, -977.875);
        glVertex2f(667.875, -981.500);
        glVertex2f(679.625, -987.000);
        glEnd();
    }

    {
        double vertices[][2] = {
                {689, -999},
                {673, -977},
                {660, -961},
                {651, -945},
                {636, -925},
                {625, -900},
                {618, -868},
                {630, -896},
                {641, -912},
                {651, -925},
                {662, -941},
                {673, -948},
                {647, -911},
                {627, -869},
                {612, -825},
                {601, -769},
                {595, -721},
                {668, -666},
                {686, -741},
                {680, -764},
                {691, -791},
                {701, -812},
                {709, -839},
                {718, -879},
                {720, -919},
                {709, -880},
                {697, -850},
                {689, -835},
                {677, -812},
                {674, -814},
                {683, -843},
                {687, -881},
                {703, -949},
                {678, -884},
                {668, -856},
                {664, -845},
                {657, -819},
                {660, -852},
                {664, -880},
                {670, -916},
                {674, -931},
                {676, -939},
                {684, -957},
                {689, -970},
                {690, -984}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
//        drawConcavePolygon(vertices, size, 168, 86, 39);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        //VERTICES
        glColor4d(168/255.0f,86/255.0f,39/255.0f,1);
        glVertex2dv(vertices[0]);
        glColor4d(168/255.0f,86/255.0f,39/255.0f,0.0);
        for (int i = 1; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();
        glDisable(GL_STENCIL_TEST);
    }

    {
        double vertices[][2] = {
                {680.167, -678.667},
                {679.000, -672.000},
                {678.333, -666.667},
                {679.833, -661.833},
                {685.167, -685.833},
                {690.333, -700.000},
                {699.333, -723.000},
                {704.667, -734.167},
                {702.000, -733.167},
                {699.000, -730.000},
                {692.667, -715.000},
                {685.167, -695.000},
                {682.333, -687.667}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 215, 131, 74);
    }
    {
        double vertices[][2] = {
                {700.333, -738.167},
                {699.000, -729.167},
                {705.833, -736.167},
                {718.833, -761.667},
                {726.000, -778.000},
                {730.667, -790.667},
                {737.000, -810.167},
                {730.333, -793.000},
                {727.333, -786.333},
                {722.833, -777.667},
                {715.167, -762.833},
                {708.500, -751.500}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 180, 97, 59);
    }

    //elLight fy el5ousal elYmeen
    {
        double vertices[][2] = {
                {929.000, -786.500},
                {932.500, -831.000},
                {932.000, -855.000},
                {934.000, -874.500},
                {938.000, -897.500},
                {945.000, -931.000},
                {947.500, -968.000},
                {948.000, -1003.500},
                {946.000, -1033.500},
                {937.500, -1061.500},
                {927.000, -1085.000},
                {910.500, -1100.500},
                {925.000, -1089.500},
                {937.000, -1074.500},
                {951.500, -1045.000},
                {959.500, -1022.000},
                {961.000, -989.500},
                {960.000, -963.500},
                {954.000, -930.000},
                {952.500, -913.500},
                {953.000, -901.000},
                {951.500, -880.000},
                {946.500, -855.500},
                {937.500, -824.000},
                {935.000, -807.500}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 255, 224, 145);
    }
    {
        double vertices[][2] = {
                {956.000, -1039.667},
                {970.333, -1012.000},
                {962.667, -941.333},
                {962.667, -937.333},
                {970.000, -955.667},
                {975.000, -971.000},
                {986.333, -1006.667},
                {994.333, -1035.333},
                {998.667, -1054.000},
                {1000.667, -1068.667},
                {1001.667, -1080.000},
                {1001.667, -1095.667},
                {999.000, -1107.667},
                {991.667, -1120.333},
                {998.667, -1111.000},
                {1003.000, -1103.333},
                {1004.667, -1092.667},
                {1005.333, -1071.333},
                {1004.333, -1054.333},
                {1008.667, -1066.000},
                {1015.333, -1079.667},
                {1025.333, -1094.667},
                {1033.333, -1104.667},
                {1042.000, -1111.333},
                {1055.667, -1114.000},
                {1045.000, -1110.333},
                {1041.667, -1107.000},
                {1037.333, -1104.333},
                {1031.667, -1097.667},
                {1024.333, -1086.333},
                {1019.667, -1076.333},
                {1014.667, -1066.667},
                {1007.667, -1050.000},
                {999.667, -1032.667},
                {982.000, -974.333},
                {980.000, -968.667},
                {978.333, -956.000},
                {976.667, -945.333},
                {974.000, -933.000},
                {969.000, -916.000},
                {963.667, -892.333},
                {959.667, -876.000},
                {956.000, -859.000},
                {953.667, -837.667},
                {944.667, -827.000},
                {945.667, -841.000},
                {949.000, -853.667},
                {951.667, -865.000},
                {954.667, -881.000},
                {956.000, -892.667},
                {957.333, -919.667},
                {959.333, -941.000},
                {962.000, -955.333},
                {963.000, -965.667},
                {964.333, -990.333},
                {965.000, -1008.667},
                {962.000, -1025.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 252, 219, 143);
    }
    {
        double vertices[][2] = {
                {961.500, -867.667},
                {964.000, -881.750},
                {966.500, -892.250},
                {968.333, -899.000},
                {970.917, -909.333},
                {972.000, -912.583},
                {973.250, -918.000},
                {974.875, -926.625},
                {976.500, -934.250},
                {976.250, -917.875},
                {975.125, -908.750},
                {972.375, -896.375},
                {969.000, -883.250}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 252, 218, 131);
    }
    {
        double vertices[][2] = {
                {943.667, -825.000},
                {956.333, -839.833},
                {957.500, -847.833},
                {960.000, -855.500},
                {963.333, -860.833},
                {967.500, -876.167},
                {971.667, -885.667},
                {973.667, -895.833},
                {977.250, -913.167},
                {978.333, -927.917},
                {977.750, -936.000},
                {980.083, -947.000},
                {982.000, -940.333},
                {983.083, -935.083},
                {982.750, -924.500},
                {980.917, -898.000},
                {978.500, -886.167},
                {974.500, -867.167},
                {953.333, -783.000},
                {942.333, -773.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 252, 219, 143);
    }
    {
        double vertices[][2] = {
                {982.167, -906.167},
                {987.250, -915.781},
                {999.917, -942.917},
                {1003.917, -950.917},
                {1009.167, -966.500},
                {1011.500, -977.333},
                {1014.000, -989.667},
                {1013.833, -1011.500},
                {1011.333, -1025.500},
                {1005.833, -1037.167},
                {1003.167, -1039.500},
                {1010.333, -1031.333},
                {1013.500, -1024.500},
                {1016.500, -1015.333},
                {1017.000, -1010.667},
                {1016.333, -991.833},
                {1014.667, -979.167},
                {1013.000, -971.167},
                {1008.500, -955.667},
                {1003.667, -944.667},
                {999.333, -935.833},
                {988.500, -909.500},
                {986.750, -902.750},
                {979.000, -887.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 228, 191, 115);
    }

    {
        double vertices[][2] = {
                {976.750, -828.500},
                {1009.250, -870.250},
                {1025.625, -888.000},
                {1037.125, -903.375},
                {1049.167, -923.250},
                {1050.917, -924.667},
                {1051.000, -922.917},
                {1050.917, -920.333},
                {1039.750, -902.750},
                {1030.917, -890.000},
                {1002.917, -855.083},
                {989.250, -839.917}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 246, 233, 141);
    }

    {
        double vertices[][2] = {
                {1051.750, -922.500},
                {1058.375, -933.500},
                {1063.375, -939.375},
                {1069.000, -944.125},
                {1066.250, -938.750},
                {1062.000, -933.000},
                {1057.250, -927.375}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 230, 146, 67);
    }

    {
        double vertices[][2] = {
                {1113.875, -1053.500},
                {1115.625, -1049.000},
                {1116.375, -1043.625},
                {1116.000, -1029.875},
                {1115.500, -1025.375},
                {1113.625, -1017.500},
                {1102.375, -989.375},
                {1114.375, -1011.500},
                {1118.625, -1021.250},
                {1121.250, -1027.875},
                {1122.250, -1033.875},
                {1122.375, -1041.250},
                {1121.125, -1046.125},
                {1117.750, -1052.125},
                {1112.125, -1057.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 232, 181, 113);
    }

    {
        double vertices[][2] = {
                {1063.000, -958.000},
                {1064.833, -966.167},
                {1065.833, -977.833},
                {1065.333, -993.667},
                {1061.333, -1008.667},
                {1056.667, -1017.667},
                {1051.500, -1022.917},
                {1040.750, -1026.333},
                {1033.833, -1027.167},
                {1031.333, -1027.417},
                {1041.583, -1027.583},
                {1044.667, -1027.000},
                {1047.417, -1026.167},
                {1053.083, -1023.500},
                {1057.083, -1020.500},
                {1059.667, -1018.500},
                {1064.333, -1011.250},
                {1068.083, -1000.750},
                {1069.417, -994.083},
                {1069.833, -990.083},
                {1070.333, -972.167},
                {1068.500, -967.333},
                {1064.750, -959.417},
                {1062.333, -954.417}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 247, 199, 113);
    }

    {
        double vertices[][2] = {
                {906.000, -828.000},
                {910.500, -817.000},
                {915.500, -806.500},
                {919.000, -795.000},
                {921.500, -780.500},
                {920.000, -762.000},
                {924.500, -751.000},
                {933.500, -741.500},
                {941.500, -725.000},
                {948.500, -707.000},
                {953.000, -684.000},
                {953.500, -707.500},
                {950.000, -724.000},
                {945.000, -734.333},
                {938.333, -742.000},
                {937.667, -746.667},
                {940.500, -767.250},
                {941.500, -789.250},
                {942.750, -826.000},
                {945.000, -845.000},
                {930.750, -785.250},
                {930.000, -784.000},
                {929.000, -783.750},
                {928.000, -785.000},
                {931.000, -826.000},
                {930.500, -849.500},
                {929.500, -864.500},
                {932.500, -880.000},
                {936.500, -902.000},
                {940.000, -919.000},
                {943.000, -932.000},
                {945.500, -1022.000},
                {939.000, -1053.500},
                {933.500, -1065.500},
                {926.000, -1081.500},
                {917.500, -1091.500},
                {900.500, -1095.500},
                {892.500, -1095.000},
                {909.000, -1086.500},
                {921.000, -1072.500},
                {928.000, -1059.000},
                {934.000, -1031.500},
                {935.000, -1012.500},
                {927.000, -996.000},
                {919.000, -983.500},
                {913.000, -971.000},
                {905.500, -949.000},
                {899.500, -927.000},
                {896.000, -907.500},
                {892.000, -885.500},
                {889.500, -856.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 186, 102, 44);
    }

    {
        glBegin(GL_POLYGON);
        glColor4f(142/225.0f,68/225.0f,30/225.0f,1.0f);
        glVertex2f(932.750, -983.750);
        glColor4f(161/225.0f,82/225.0f,37/225.0f,0.5f);
        glVertex2f(930.500, -961.000);
        glVertex2f(923.500, -915.000);
        glVertex2f(909.250, -833.750);
        glVertex2f(890.750, -862.500);
        glVertex2f(906.750, -905.250);
        glVertex2f(916.750, -934.500);
        glVertex2f(923.750, -956.750);
        glEnd();

    }

    {
        double vertices[][2] = {
                {885.000, -962.000},
                {888.750, -975.000},
                {889.750, -984.250},
                {894.250, -1004.000},
                {898.250, -1020.000},
                {903.000, -1035.250},
                {911.250, -1056.000},
                {916.750, -1065.250},
                {920.500, -1069.750},
                {925.750, -1062.250},
                {919.750, -1055.750},
                {915.000, -1048.000},
                {907.000, -1034.500},
                {900.750, -1018.500},
                {894.500, -997.750},
                {888.750, -971.750},
                {888.000, -959.500},
                {888.250, -935.750},
                {888.250, -918.750},
                {889.000, -899.750},
                {889.750, -882.250},
                {888.750, -865.250},
                {887.000, -860.500},
                {878.250, -874.750},
                {870.000, -890.750},
                {865.750, -933.500},
                {863.125, -972.875},
                {863.250, -992.500},
                {864.125, -1007.250},
                {863.375, -985.000},
                {864.125, -964.625},
                {864.500, -952.000},
                {865.500, -944.500},
                {867.167, -933.167},
                {869.167, -919.167},
                {869.833, -918.167},
                {870.167, -916.833},
                {874.167, -959.333},
                {877.125, -993.125},
                {878.500, -1013.000},
                {879.250, -1016.750},
                {880.250, -1018.000},
                {881.375, -1016.125},
                {883.500, -994.000},
                {883.750, -984.000},
                {884.750, -972.500},
                {884.250, -965.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 161, 85, 35);
    }

    {
        double vertices[][2] = {
                {941.333, -772.000},
                {952.333, -779.000},
                {961.000, -797.333},
                {969.667, -811.667},
                {977.333, -823.000},
                {968.333, -802.667},
                {965.000, -793.333},
                {954.667, -768.000},
                {951.000, -757.000},
                {938.667, -746.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 251, 222, 153);
    }

    //elAgza2 elBlack fy el4a3r
    {
        double vertices[][2] = {
                {687.667, -573.333},
                {686.000, -585.667},
                {684.167, -592.833},
                {681.667, -600.000},
                {679.500, -607.833},
                {678.000, -617.833},
                {676.667, -634.667},
                {675.333, -620.667},
                {674.250, -607.000},
                {675.333, -591.333},
                {677.500, -580.000},
                {681.000, -568.667},
                {687.000, -549.167},
                {693.167, -525.083},
                {696.667, -514.750},
                {700.333, -505.000},
                {712.333, -477.667},
                {723.500, -446.333},
                {731.500, -428.167},
                {748.500, -404.833},
                {753.917, -399.583},
                {760.750, -394.000},
                {764.083, -392.583},
                {768.000, -392.167},
                {772.833, -394.333},
                {779.250, -398.500},
                {786.250, -406.000},
                {791.750, -414.750},
                {797.250, -424.250},
                {787.250, -424.250},
                {773.250, -425.500},
                {759.500, -430.250},
                {752.000, -435.500},
                {740.000, -445.000},
                {733.250, -451.750},
                {724.333, -463.000},
                {716.833, -477.333},
                {709.500, -491.167},
                {703.667, -505.333},
                {701.500, -519.333},
                {691.167, -552.500},
                {689.667, -560.333}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 86, 39, 20);
    }

    {
        double vertices[][2] = {
                {873.833, -449.333},
                {878.000, -456.812},
                {879.167, -461.167},
                {869.500, -452.833},
                {852.000, -438.000},
                {843.667, -432.500},
                {839.500, -430.000},
                {837.000, -429.000},
                {829.667, -425.500},
                {836.500, -419.667},
                {840.667, -417.833},
                {851.167, -424.167},
                {859.167, -431.833},
                {865.333, -438.333},
                {870.833, -445.333}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        glEnable(GL_STENCIL_TEST);          // enable stencil test
        glEnable(GL_DEPTH_TEST);

        // PASS 1: draw to stencil buffer only
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
        glStencilFunc(GL_ALWAYS, 1, 1);
        glStencilOp(GL_KEEP, GL_INVERT, GL_INVERT);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
            glVertex2dv(vertices[i]);
        glEnd();

        // PASS 2: draw color buffer
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
        glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1)
        glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
        glDisable(GL_DEPTH_TEST);

        glBegin(GL_POLYGON);
        //VERTICES
        for (int i = 0; i < size; ++i)
        {
            if (i<=3)
                glColor4d(86/255.0f,39/255.0f,20/255.0f,0.3);
            else
                glColor4d(86/255.0f,39/255.0f,20/255.0f,1);

            glVertex2dv(vertices[i]);
        }
        glEnd();
        glDisable(GL_STENCIL_TEST);
    }

    {
        double vertices[][2] = {
                {837.167, -414.500},
                {840.750, -413.917},
                {844.750, -414.500},
                {852.667, -418.167},
                {859.167, -421.500},
                {864.500, -424.917},
                {869.833, -428.583},
                {871.917, -430.417},
                {876.250, -434.833},
                {881.083, -440.167},
                {875.583, -429.333},
                {872.583, -425.417},
                {867.083, -421.417},
                {860.417, -417.167},
                {853.917, -413.833},
                {848.917, -412.000},
                {844.750, -411.667}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 101, 48, 22);
    }

    {
        double vertices[][2] = {
                {825.375, -419.250},
                {834.188, -411.875},
                {840.875, -406.938},
                {844.188, -405.375},
                {847.750, -404.812},
                {850.125, -404.812},
                {853.938, -405.250},
                {858.625, -407.250},
                {863.375, -410.500},
                {868.312, -414.938},
                {876.750, -424.188},
                {872.062, -417.500},
                {867.750, -412.438},
                {863.875, -408.812},
                {860.562, -405.500},
                {857.500, -403.375},
                {854.438, -402.062},
                {851.688, -401.312},
                {849.375, -401.125},
                {845.625, -401.188},
                {843.062, -402.938},
                {836.667, -408.083}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 88, 39, 15);
    }

    //ellines elblack
    {
        glLineWidth(1);
        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);

        glBegin(GL_LINE_STRIP);
        glVertex2f(855.500, -442.500);
        glVertex2f(865.000, -453.000);
        glVertex2f(886.000, -479.500);
        glVertex2f(897.500, -494.500);
        glVertex2f(904.500, -506.500);
        glVertex2f(913.500, -523.000);
        glVertex2f(920.500, -540.500);
        glVertex2f(929.000, -564.500);
        glVertex2f(936.000, -591.500);
        glVertex2f(938.000, -601.500);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2d(809,-413);
        glVertex2d(809,-420);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(819.667, -435.000);
        glVertex2d(838.667, -450.000);
        glVertex2d(855.667, -468.333);
        glVertex2d(861.000, -476.333);
        glVertex2d(871.667, -495.333);
        glVertex2d(880.333, -510.667);
        glVertex2d(887.000, -526.333);
        glVertex2d(891.667, -540.333);
        glVertex2d(893.333, -553.667);
        glVertex2d(894.667, -571.333);
        glVertex2d(893.000, -582.333);
        glVertex2d(892.333, -590.000);
        glVertex2d(892.667, -598.000);
        glVertex2d(901.000, -617.667);
        glVertex2d(913.000, -646.667);
        glVertex2d(918.667, -660.000);
        glVertex2d(920.333, -663.833);
        glVertex2d(925.167, -671.833);
        glVertex2d(925.833, -676.667);
        glVertex2d(925.167, -665.167);
        glVertex2d(923.000, -654.000);
        glVertex2d(911.333, -618.833);
        glVertex2d(893.750, -582.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(803.333, -445.333);
        glVertex2d(813.667, -462.667);
        glVertex2d(821.667, -478.667);
        glVertex2d(829.333, -496.667);
        glVertex2d(837.333, -518.333);
        glVertex2d(845.667, -541.667);
        glVertex2d(849.667, -556.333);
        glVertex2d(855.000, -568.667);
        glVertex2d(860.667, -580.333);
        glVertex2d(870.667, -603.833);
        glVertex2d(877.667, -619.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(863.000, -586.500);
        glVertex2d(869.500, -606.333);
        glVertex2d(873.667, -617.500);
        glVertex2d(877.333, -630.667);
        glVertex2d(878.833, -639.000);
        glVertex2d(878.000, -651.000);
        glVertex2d(875.167, -666.167);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(845.833, -543.333);
        glVertex2d(847.667, -560.000);
        glVertex2d(851.000, -581.167);
        glVertex2d(852.500, -592.833);
        glVertex2d(857.167, -608.500);
        glVertex2d(861.500, -625.000);
        glVertex2d(864.000, -640.750);
        glVertex2d(866.000, -664.250);
        glVertex2d(866.000, -689.000);
        glVertex2d(862.500, -712.500);
        glVertex2d(855.500, -720.000);
        glVertex2d(844.000, -727.000);
        glVertex2d(857.500, -712.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(851.250, -666.750);
        glVertex2d(851.750, -683.500);
        glVertex2d(849.500, -699.000);
        glVertex2d(844.750, -711.750);
        glVertex2d(828.000, -737.250);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(830.750, -726.750);
        glVertex2d(812.500, -738.500);
        glVertex2d(819.000, -727.750);
        glVertex2d(822.500, -719.750);
        glVertex2d(823.750, -710.500);
        glVertex2d(823.750, -706.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(792.000, -525.333);
        glVertex2d(799.333, -551.333);
        glVertex2d(811.333, -581.333);
        glVertex2d(817.667, -610.667);
        glVertex2d(823.333, -647.667);
        glVertex2d(825.000, -674.333);
        glVertex2d(825.333, -689.667);
        glVertex2d(824.000, -704.333);
        glVertex2d(817.333, -717.667);
        glVertex2d(810.667, -724.667);
        glVertex2d(802.333, -729.333);
        glVertex2d(794.333, -731.000);
        glVertex2d(806.667, -722.333);
        glVertex2d(814.333, -706.000);
        glVertex2d(817.667, -694.000);
        glVertex2d(817.333, -675.333);
        glVertex2d(815.667, -666.667);
        glVertex2d(811.000, -653.667);
        glVertex2d(798.667, -629.000);
        glVertex2d(793.667, -622.000);
        glVertex2d(788.000, -609.667);
        glVertex2d(780.667, -591.000);
        glVertex2d(776.000, -579.333);
        glVertex2d(772.000, -563.000);
        glVertex2d(769.000, -545.000);
        glVertex2d(768.000, -532.000);
        glVertex2d(769.000, -511.000);
        glVertex2d(770.500, -492.500);
        glVertex2d(773.500, -474.000);
        glVertex2d(777.500, -460.000);
        glVertex2d(782.000, -446.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(780.250, -473.500);
        glVertex2d(778.500, -490.000);
        glVertex2d(777.250, -509.750);
        glVertex2d(778.000, -526.750);
        glVertex2d(779.250, -536.250);
        glVertex2d(784.500, -553.000);
        glVertex2d(791.250, -573.000);
        glVertex2d(799.500, -595.000);
        glVertex2d(807.500, -619.500);
        glVertex2d(813.000, -640.000);
        glVertex2d(816.000, -657.500);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(757.667, -580.333);
        glVertex2d(755.333, -652.000);
        glVertex2d(754.000, -669.667);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(767.833, -530.667);
        glVertex2d(766.667, -545.333);
        glVertex2d(764.333, -560.333);
        glVertex2d(760.167, -573.667);
        glVertex2d(756.167, -585.833);
        glVertex2d(749.500, -598.750);
        glVertex2d(734.000, -623.250);
        glVertex2d(722.750, -641.000);
        glVertex2d(718.500, -648.250);
        glVertex2d(712.750, -658.000);
        glVertex2d(706.667, -665.833);
        glVertex2d(701.625, -670.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 0.5);
        glBegin(GL_POLYGON);
        glVertex2d(758.625, -583.000);
        glVertex2d(770.125, -557.250);
        glVertex2d(768.125, -538.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(738.000, -568.000);
        glVertex2d(734.250, -579.000);
        glVertex2d(732.750, -585.250);
        glVertex2d(730.750, -592.250);
        glVertex2d(726.750, -610.250);
        glVertex2d(719.250, -629.250);
        glVertex2d(705.000, -651.500);
        glVertex2d(694.250, -665.000);
        glVertex2d(687.000, -674.250);
        glVertex2d(684.750, -675.000);
        glVertex2d(682.500, -674.250);
        glVertex2d(683.500, -669.750);
        glVertex2d(695.500, -653.750);
        glVertex2d(707.750, -634.500);
        glVertex2d(715.250, -616.250);
        glVertex2d(722.250, -597.250);
        glVertex2d(726.750, -582.000);
        glVertex2d(729.000, -572.250);
        glVertex2d(731.000, -558.000);
        glVertex2d(733.750, -539.500);
        glVertex2d(737.500, -520.250);
        glVertex2d(743.000, -501.500);
        glVertex2d(753.000, -476.250);
        glVertex2d(762.000, -457.500);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_POLYGON);
        glVertex2d(733.500, -539.333);
        glVertex2d(731.333, -556.667);
        glVertex2d(729.500, -570.000);
        glVertex2d(726.000, -584.333);
        glVertex2d(723.333, -593.333);
        glVertex2d(716.167, -602.000);
        glVertex2d(709.500, -610.833);
        glVertex2d(703.000, -619.833);
        glVertex2d(684.667, -651.000);
        glVertex2d(698.833, -622.833);
        glVertex2d(701.833, -616.833);
        glVertex2d(709.167, -601.667);
        glVertex2d(720.500, -574.667);
        glVertex2d(728.833, -551.833);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(700.000, -568.750);
        glVertex2d(694.667, -590.000);
        glVertex2d(690.250, -605.500);
        glVertex2d(680.000, -644.000);
        glEnd();


        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(751.667, -451.333);
        glVertex2d(740.333, -460.333);
        glVertex2d(724.333, -478.333);
        glVertex2d(714.333, -494.333);
        glVertex2d(706.333, -511.667);
        glVertex2d(696.000, -536.000);
        glVertex2d(688.333, -568.667);
        glVertex2d(685.333, -583.667);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(716.125, -525.875);
        glVertex2d(693.250, -573.250);
        glVertex2d(683.250, -595.000);
        glVertex2d(679.500, -609.000);
        glVertex2d(676.500, -634.250);
        glVertex2d(675.000, -621.500);
        glVertex2d(675.500, -604.500);
        glVertex2d(677.000, -584.500);
        glVertex2d(680.500, -570.000);
        glVertex2d(684.500, -552.500);
        glVertex2d(692.500, -526.000);
        glVertex2d(699.000, -509.500);
        glVertex2d(709.000, -492.000);
        glVertex2d(729.000, -457.000);
        glVertex2d(742.000, -443.000);
        glVertex2d(755.000, -433.000);
        glVertex2d(764.000, -429.500);
        glVertex2d(780.000, -425.000);
        glVertex2d(794.500, -424.500);
        glVertex2d(797.000, -425.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(720.000, -405.500);
        glVertex2d(709.000, -423.500);
        glVertex2d(701.500, -449.500);
        glVertex2d(696.000, -470.000);
        glVertex2d(688.000, -503.500);
        glVertex2d(681.500, -534.000);
        glVertex2d(677.500, -567.000);
        glVertex2d(676.500, -582.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(690.000, -428.500);
        glVertex2d(680.500, -457.500);
        glVertex2d(674.000, -481.000);
        glVertex2d(666.000, -526.500);
        glVertex2d(664.000, -565.000);
        glVertex2d(666.500, -593.500);
        glVertex2d(674.000, -624.000);
        glVertex2d(676.500, -636.000);
        glVertex2d(679.000, -645.500);
        glVertex2d(679.500, -659.500);
        glVertex2d(684.500, -683.000);
        glVertex2d(695.667, -710.333);
        glVertex2d(703.500, -730.000);
        glVertex2d(714.167, -751.333);
        glVertex2d(726.333, -776.667);
        glVertex2d(734.000, -793.000);
        glVertex2d(738.500, -811.750);
        glVertex2d(742.000, -830.250);
        glVertex2d(744.750, -846.250);
        glVertex2d(744.750, -870.500);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_POLYGON);
        glVertex2d(672.167, -496.333);
        glVertex2d(669.500, -525.333);
        glVertex2d(669.667, -537.167);
        glVertex2d(668.333, -558.500);
        glVertex2d(668.333, -588.667);
        glVertex2d(674.500, -625.167);
        glVertex2d(667.500, -595.333);
        glVertex2d(665.167, -576.667);
        glVertex2d(664.500, -551.833);
        glVertex2d(665.667, -525.833);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(661.333, -616.500);
        glVertex2d(665.500, -632.667);
        glVertex2d(671.833, -649.333);
        glVertex2d(675.667, -662.667);
        glVertex2d(679.667, -674.500);
        glVertex2d(681.667, -682.833);
        glVertex2d(686.667, -702.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(659.833, -657.000);
        glVertex2d(673.667, -688.667);
        glVertex2d(679.667, -701.833);
        glVertex2d(683.833, -711.167);
        glVertex2d(702.333, -743.333);
        glVertex2d(720.667, -774.000);
        glVertex2d(732.000, -799.667);
        glVertex2d(736.000, -812.000);
        glVertex2d(738.625, -831.625);
        glVertex2d(739.250, -852.250);
        glVertex2d(739.250, -865.750);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(681.750, -707.500);
        glVertex2d(686.250, -731.500);
        glVertex2d(691.500, -752.500);
        glVertex2d(694.000, -766.000);
        glVertex2d(696.000, -777.000);
        glVertex2d(699.000, -794.000);
        glVertex2d(702.000, -804.000);
        glVertex2d(694.000, -785.750);
        glVertex2d(686.500, -768.750);
        glVertex2d(678.750, -754.250);
        glVertex2d(672.250, -740.000);
        glVertex2d(666.250, -726.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(701.250, -802.750);
        glVertex2d(711.500, -823.500);
        glVertex2d(733.000, -860.500);
        glVertex2d(755.000, -894.000);
        glVertex2d(773.750, -919.750);
        glVertex2d(775.750, -923.750);
        glVertex2d(773.000, -921.750);
        glVertex2d(753.000, -898.000);
        glVertex2d(743.500, -885.750);
        glVertex2d(737.500, -877.500);
        glVertex2d(731.250, -869.250);
        glVertex2d(708.000, -831.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(712.333, -839.333);
        glVertex2d(714.167, -848.000);
        glVertex2d(716.500, -855.000);
        glVertex2d(720.500, -862.500);
        glVertex2d(726.333, -873.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(738.167, -902.167);
        glVertex2d(729.333, -887.000);
        glVertex2d(719.833, -869.500);
        glVertex2d(716.833, -863.167);
        glVertex2d(721.333, -881.167);
        glVertex2d(722.333, -893.667);
        glVertex2d(722.500, -908.833);
        glVertex2d(720.333, -924.333);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(684.750, -831.000);
        glVertex2d(692.250, -846.750);
        glVertex2d(697.750, -860.250);
        glVertex2d(703.250, -875.000);
        glVertex2d(708.750, -890.750);
        glVertex2d(715.000, -908.250);
        glVertex2d(718.500, -920.500);
        glVertex2d(719.750, -927.750);
        glVertex2d(729.500, -934.750);
        glVertex2d(745.500, -944.250);
        glVertex2d(758.500, -951.500);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(719.875, -928.125);
        glVertex2d(721.625, -937.750);
        glVertex2d(724.500, -955.000);
        glVertex2d(730.750, -971.625);
        glVertex2d(746.000, -1019.667);
        glVertex2d(751.167, -1033.667);
        glVertex2d(757.500, -1026.500);
        glVertex2d(763.500, -1011.000);
        glVertex2d(766.000, -992.000);
        glVertex2d(765.500, -977.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(770.000, -987.000);
        glVertex2d(769.333, -1006.333);
        glVertex2d(766.000, -1022.667);
        glVertex2d(758.333, -1039.333);
        glVertex2d(754.333, -1046.667);
        glVertex2d(752.667, -1036.000);
        glVertex2d(754.333, -1051.667);
        glVertex2d(756.333, -1072.000);
        glVertex2d(755.333, -1089.333);
        glVertex2d(752.667, -1102.667);
        glVertex2d(747.000, -1116.667);
        glVertex2d(739.333, -1126.000);
        glVertex2d(745.667, -1114.667);
        glVertex2d(746.000, -1104.000);
        glVertex2d(743.667, -1084.000);
        glVertex2d(739.333, -1059.667);
        glVertex2d(729.333, -1034.667);
        glVertex2d(719.000, -1009.333);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(658.500, -822.500);
        glVertex2d(663.500, -850.000);
        glVertex2d(671.500, -874.500);
        glVertex2d(680.000, -897.000);
        glVertex2d(689.500, -914.500);
        glVertex2d(699.000, -934.000);
        glVertex2d(710.500, -960.500);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(718.000, -1106.000);
        glVertex2d(719.000, -1078.500);
        glVertex2d(718.000, -1048.000);
        glVertex2d(710.000, -1017.000);
        glVertex2d(714.375, -1047.000);
        glVertex2d(714.625, -1056.250);
        glVertex2d(715.625, -1083.250);
        glVertex2d(714.125, -1059.125);
        glVertex2d(711.125, -1048.000);
        glVertex2d(706.000, -1028.875);
        glVertex2d(701.500, -1014.500);
        glVertex2d(703.375, -1029.875);
        glVertex2d(703.000, -1042.375);
        glVertex2d(700.250, -1055.375);
        glVertex2d(693.375, -1064.625);
        glVertex2d(686.250, -1065.625);
        glVertex2d(678.375, -1062.875);
        glVertex2d(669.000, -1056.333);
        glVertex2d(658.333, -1044.000);
        glVertex2d(650.333, -1028.333);
        glVertex2d(657.333, -1036.667);
        glVertex2d(667.000, -1046.333);
        glVertex2d(675.667, -1053.333);
        glVertex2d(688.333, -1059.333);
        glVertex2d(692.333, -1059.333);
        glVertex2d(694.000, -1055.667);
        glVertex2d(694.667, -1040.000);
        glVertex2d(694.000, -1013.000);
        glVertex2d(692.667, -1004.000);
        glVertex2d(690.333, -979.667);
        glVertex2d(688.667, -969.667);
        glVertex2d(685.000, -958.000);
        glVertex2d(680.333, -949.667);
        glVertex2d(677.333, -941.000);
        glVertex2d(673.000, -924.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_POLYGON);
        glVertex2d(636.333, -629.333);
        glVertex2d(639.000, -671.333);
        glVertex2d(642.667, -701.333);
        glVertex2d(648.667, -731.000);
        glVertex2d(661.333, -771.333);
        glVertex2d(670.667, -797.667);
        glVertex2d(679.000, -816.667);
        glVertex2d(672.333, -796.333);
        glVertex2d(663.333, -767.333);
        glVertex2d(652.333, -724.333);
        glVertex2d(647.333, -697.000);
        glVertex2d(642.333, -668.667);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(612, -730);
        glVertex2d(611, -700);
        glVertex2d(611, -678);
        glVertex2d(611, -655);
        glVertex2d(613, -636);
        glVertex2d(615, -620);
        glVertex2d(618, -603);
        glVertex2d(623, -572);
        glVertex2d(617, -627);
        glVertex2d(617, -665);
        glVertex2d(622, -726);
        glVertex2d(635, -825);
        glVertex2d(643, -874);
        glVertex2d(650, -897);
        glVertex2d(660, -918);
        glVertex2d(671, -941);
        glVertex2d(657, -911);
        glVertex2d(646, -885);
        glVertex2d(636, -854);
        glVertex2d(626, -827);
        glVertex2d(621, -815);
        glVertex2d(610, -763);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 0.8);
        glBegin(GL_POLYGON);
        glVertex2d(620.667, -716.000);
        glVertex2d(623.667, -739.000);
        glVertex2d(627.333, -771.000);
        glVertex2d(632.667, -817.333);
        glVertex2d(640.000, -864.667);
        glVertex2d(625.667, -823.667);
        glVertex2d(623.333, -817.667);
        glVertex2d(621.333, -788.333);
        glVertex2d(620.333, -765.667);
        glVertex2d(619.333, -732.667);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(611.000, -843.667);
        glVertex2d(610.000, -835.000);
        glVertex2d(606.667, -830.667);
        glVertex2d(602.833, -810.833);
        glVertex2d(601.167, -801.500);
        glVertex2d(600.000, -789.500);
        glVertex2d(599.167, -779.167);
        glVertex2d(598.833, -767.167);
        glVertex2d(599.333, -741.167);
        glVertex2d(604.833, -784.333);
        glVertex2d(608.833, -804.667);
        glVertex2d(613.667, -827.667);
        glVertex2d(618.500, -849.167);
        glVertex2d(622.000, -862.000);
        glVertex2d(630.500, -882.750);
        glVertex2d(641.000, -902.000);
        glVertex2d(653.500, -921.500);
        glVertex2d(666.000, -939.000);
        glVertex2d(671.125, -945.250);
        glEnd();

        {
            double vertices[][2] = {
                    {607.000, -831.750},
                    {602.500, -811.500},
                    {600.500, -795.000},
                    {599.000, -782.250},
                    {598.500, -763.500},
                    {599.000, -745.250},
                    {604.000, -780.250},
                    {611.250, -819.500},
                    {617.000, -844.250},
                    {624.000, -868.500},
                    {639.000, -899.667},
                    {654.667, -924.000},
                    {667.667, -941.833},
                    {648.500, -915.667},
                    {636.500, -900.000},
                    {626.333, -882.333},
                    {619.333, -869.500},
                    {620.000, -882.000},
                    {623.833, -899.500},
                    {631.333, -916.167},
                    {640.333, -932.500},
                    {650.500, -946.667},
                    {674.750, -978.500},
                    {679.250, -985.750},
                    {659.250, -966.250},
                    {643.500, -951.750},
                    {630.750, -941.000},
                    {624.500, -934.250},
                    {618.250, -927.750},
                    {617.250, -907.500},
                    {612.500, -874.500},
                    {610.000, -856.750},
                    {607.000, -839.250}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 86, 39, 20,0.8);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(630.250, -1005.000);
        glVertex2d(637.750, -1027.500);
        glVertex2d(640.250, -1031.750);
        glVertex2d(640.250, -1037.250);
        glVertex2d(651.750, -1059.750);
        glVertex2d(666.250, -1079.500);
        glVertex2d(652.250, -1059.750);
        glVertex2d(640.250, -1037.000);
        glVertex2d(627.000, -1010.375);
        glVertex2d(614.125, -981.250);
        glVertex2d(606.500, -956.500);
        glVertex2d(602.250, -942.250);
        glVertex2d(598.750, -926.750);
        glVertex2d(585.667, -844.667);
        glVertex2d(579.333, -759.333);
        glVertex2d(579.667, -723.000);
        glVertex2d(580.000, -698.000);
        glVertex2d(582.667, -673.667);
        glEnd();

        {
            double vertices[][2] = {
                    {580.667, -687.667},
                    {578.667, -700.667},
                    {579.000, -721.667},
                    {578.667, -755.667},
                    {581.000, -788.667},
                    {585.000, -844.000},
                    {589.333, -874.000},
                    {596.667, -907.667},
                    {579.333, -827.000},
                    {574.333, -804.333},
                    {569.333, -790.000},
                    {565.667, -767.000},
                    {564.000, -750.667},
                    {567.000, -731.000},
                    {575.667, -758.333},
                    {575.667, -739.333},
                    {574.667, -733.000},
                    {575.000, -721.667},
                    {576.000, -715.000},
                    {576.000, -706.333},
                    {576.000, -700.333}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 86, 39, 20,0.7);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(568.000, -610.333);
        glVertex2d(565.667, -630.333);
        glVertex2d(565.333, -656.667);
        glVertex2d(563.667, -691.000);
        glVertex2d(564.333, -716.333);
        glVertex2d(570.333, -740.667);
        glVertex2d(575.333, -755.667);
        glEnd();

        {
            double vertices[][2] = {
                    {569.000, -690.667},
                    {574.000, -662.000},
                    {583.667, -634.667},
                    {594.000, -608.333},
                    {606.000, -580.667},
                    {583.667, -620.000},
                    {580.000, -630.000},
                    {584.667, -592.667},
                    {594.667, -558.000},
                    {607.667, -526.667},
                    {618.000, -508.333},
                    {628.000, -493.333},
                    {602.000, -529.333},
                    {595.667, -543.000},
                    {589.333, -560.000},
                    {582.667, -580.000},
                    {578.000, -604.333},
                    {574.667, -628.667},
                    {572.333, -643.667}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 86, 39, 20);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(566.750, -727.250);
        glVertex2d(562.250, -750.000);
        glVertex2d(557.000, -766.250);
        glVertex2d(557.000, -779.500);
        glVertex2d(565.500, -807.000);
        glVertex2d(574.750, -835.750);
        glVertex2d(580.500, -849.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(562.333, -833.167);
        glVertex2d(567.667, -839.667);
        glVertex2d(574.833, -847.833);
        glVertex2d(582.000, -858.333);
        glVertex2d(585.167, -867.333);
        glVertex2d(588.667, -882.167);
        glVertex2d(593.833, -900.167);
        glVertex2d(595.500, -910.000);
        glEnd();

        {
            double vertices[][2] = {
                    {563.000, -801.250},
                    {570.250, -822.500},
                    {566.000, -817.000},
                    {561.750, -814.250},
                    {553.000, -811.000},
                    {546.250, -806.250},
                    {537.750, -798.250},
                    {530.250, -787.750},
                    {523.500, -775.250},
                    {522.250, -767.500},
                    {525.250, -744.500},
                    {532.250, -728.500},
                    {536.000, -724.250},
                    {533.250, -734.500},
                    {532.500, -748.000},
                    {532.750, -766.750},
                    {536.000, -775.750},
                    {541.250, -782.250},
                    {549.750, -789.000}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 86, 39, 20,0.8);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(521.750, -774.250);
        glVertex2d(519.250, -769.500);
        glVertex2d(517.250, -762.500);
        glVertex2d(517.500, -756.750);
        glVertex2d(522.500, -742.750);
        glVertex2d(527.000, -729.250);
        glVertex2d(536.000, -711.500);
        glEnd();

        {
            double vertices[][2] = {
                    {517.000, -769.375},
                    {510.500, -764.500},
                    {505.375, -761.125},
                    {500.375, -757.125},
                    {496.375, -752.250},
                    {493.125, -747.375},
                    {499.375, -733.875},
                    {501.500, -730.625},
                    {504.375, -728.625},
                    {508.500, -721.750},
                    {507.250, -731.625},
                    {507.875, -736.750},
                    {509.875, -741.250},
                    {511.500, -748.250},
                    {512.625, -757.250}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 74, 31, 20);
        }

        {
            double vertices[][2] = {
                    {512.500, -750.833},
                    {513.833, -741.167},
                    {517.333, -733.167},
                    {525.333, -722.167},
                    {530.667, -716.833},
                    {537.000, -705.333},
                    {541.333, -696.167},
                    {544.500, -690.333},
                    {549.667, -683.000},
                    {557.000, -673.333},
                    {562.500, -661.833},
                    {565.000, -654.333},
                    {562.000, -704.167},
                    {553.667, -704.167},
                    {544.833, -708.167},
                    {540.833, -713.000},
                    {535.667, -722.500},
                    {532.667, -727.833},
                    {533.833, -715.333},
                    {523.667, -737.167},
                    {520.333, -747.333},
                    {517.667, -755.000},
                    {517.000, -762.000},
                    {520.500, -772.167},
                    {514.667, -763.833},
                    {513.000, -758.500}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 74, 30, 17);
        }


        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(557.667, -636.167);
        glVertex2d(552.500, -651.000);
        glVertex2d(546.167, -668.667);
        glVertex2d(539.500, -684.667);
        glVertex2d(535.167, -696.667);
        glVertex2d(532.833, -704.333);
        glVertex2d(529.500, -714.333);
        glVertex2d(525.000, -721.833);
        glVertex2d(520.167, -728.333);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(525.250, -689.125);
        glVertex2d(522.000, -698.375);
        glVertex2d(519.750, -704.000);
        glVertex2d(518.000, -710.625);
        glVertex2d(516.500, -716.625);
        glVertex2d(515.875, -722.000);
        glVertex2d(513.625, -731.625);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(511.750, -748.000);
        glVertex2d(511.000, -741.750);
        glVertex2d(508.500, -734.750);
        glVertex2d(508.500, -728.000);
        glVertex2d(508.750, -716.750);
        glVertex2d(510.750, -704.750);
        glVertex2d(515.500, -690.500);
        glVertex2d(522.000, -673.500);
        glVertex2d(538.333, -646.333);
        glVertex2d(549.333, -627.667);
        glVertex2d(554.333, -616.667);
        glVertex2d(559.000, -602.000);
        glVertex2d(564.667, -581.000);
        glVertex2d(585.333, -530.000);
        glVertex2d(597.500, -498.000);
        glVertex2d(606.500, -477.500);
        glVertex2d(618.000, -457.000);
        glVertex2d(635.500, -434.000);
        glVertex2d(646.000, -424.000);
        glVertex2d(658.000, -415.500);
        glVertex2d(662.875, -414.750);
        glEnd();


        {
            double vertices[][2] = {
                    {510.000, -673.000},
                    {520.333, -653.333},
                    {525.333, -638.000},
                    {531.667, -623.667},
                    {537.333, -612.667},
                    {546.000, -603.333},
                    {552.000, -596.333},
                    {564.000, -585.667},
                    {565.333, -578.333},
                    {593.000, -509.333},
                    {585.000, -527.000},
                    {575.667, -542.667},
                    {566.000, -558.667},
                    {556.000, -574.000},
                    {549.333, -587.000},
                    {540.333, -600.000},
                    {532.000, -612.667},
                    {524.333, -624.667},
                    {516.000, -642.000},
                    {511.667, -661.667}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 68, 32, 15);
        }

        {
            double vertices[][2] = {
                    {508.667, -716.833},
                    {504.333, -713.000},
                    {501.333, -708.000},
                    {498.167, -702.167},
                    {495.500, -694.167},
                    {493.833, -688.000},
                    {492.167, -679.333},
                    {492.167, -671.333},
                    {492.500, -678.000},
                    {495.500, -682.500},
                    {500.333, -690.333},
                    {503.667, -697.167},
                    {507.333, -704.167},
                    {508.667, -708.667},
                    {508.500, -703.833},
                    {509.833, -696.167},
                    {511.667, -688.833},
                    {515.667, -682.333},
                    {519.333, -676.500},
                    {523.000, -673.833},
                    {514.167, -695.667},
                    {510.833, -707.333},
                    {509.667, -714.833}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 81, 34, 20);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(500.333, -658.125);
        glVertex2d(503.500, -662.750);
        glVertex2d(505.583, -665.583);
        glVertex2d(507.708, -668.625);
        glVertex2d(510.542, -674.375);
        glEnd();

        {
            double vertices[][2] = {
                    {511.417, -660.750},
                    {509.833, -657.667},
                    {507.250, -653.833},
                    {503.417, -648.000},
                    {500.250, -641.750},
                    {499.167, -636.833},
                    {498.167, -629.000},
                    {499.167, -624.167},
                    {505.750, -606.125},
                    {501.000, -623.000},
                    {500.000, -631.125},
                    {505.750, -643.250},
                    {510.750, -651.125},
                    {513.875, -652.250}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 73, 30, 18);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(519.500, -636.167);
        glVertex2d(509.833, -615.667);
        glVertex2d(506.833, -607.500);
        glVertex2d(505.833, -600.667);
        glVertex2d(503.833, -594.167);
        glVertex2d(491.667, -608.333);
        glVertex2d(482.167, -620.667);
        glVertex2d(473.667, -636.000);
        glVertex2d(468.167, -649.000);
        glVertex2d(464.833, -661.000);
        glVertex2d(464.000, -671.333);
        glVertex2d(468.167, -681.500);
        glVertex2d(478.250, -701.250);
        glEnd();


        {
            double vertices[][2] = {
                    {479.250, -667.000},
                    {486.250, -650.500},
                    {490.000, -643.500},
                    {495.000, -636.750},
                    {496.500, -635.875},
                    {491.250, -645.000},
                    {491.875, -654.625},
                    {488.333, -676.833},
                    {487.000, -692.667},
                    {486.000, -712.000},
                    {486.333, -725.667},
                    {488.000, -738.000},
                    {493.000, -748.167},
                    {486.167, -737.667},
                    {484.333, -731.167},
                    {484.167, -723.333},
                    {484.167, -712.667},
                    {480.167, -721.500},
                    {478.000, -730.500},
                    {475.333, -736.667},
                    {473.833, -746.167},
                    {476.667, -752.500},
                    {483.500, -748.833},
                    {481.167, -742.167},
                    {480.833, -731.667},
                    {483.167, -743.833},
                    {487.667, -754.000},
                    {491.167, -758.667},
                    {495.333, -763.667},
                    {498.833, -765.167},
                    {504.333, -763.500},
                    {500.167, -766.500},
                    {496.333, -766.000},
                    {492.000, -762.667},
                    {488.000, -757.333},
                    {484.000, -753.000},
                    {479.000, -756.833},
                    {477.500, -758.333},
                    {472.833, -746.500},
                    {473.667, -737.667},
                    {476.500, -730.167},
                    {478.167, -724.000},
                    {480.167, -716.167},
                    {480.500, -712.667},
                    {476.667, -720.500},
                    {472.167, -732.500},
                    {469.500, -742.000},
                    {470.167, -749.833},
                    {475.000, -756.833},
                    {469.333, -751.167},
                    {468.000, -744.500},
                    {468.667, -736.833},
                    {471.833, -726.833},
                    {476.500, -714.500},
                    {478.167, -706.500},
                    {477.833, -703.333},
                    {471.167, -710.000},
                    {467.167, -713.667},
                    {466.500, -714.167},
                    {466.667, -717.000},
                    {468.000, -722.667},
                    {464.333, -717.167},
                    {464.000, -714.333},
                    {467.500, -710.333},
                    {475.000, -703.333},
                    {479.667, -697.333},
                    {484.167, -681.167},
                    {489.500, -655.500},
                    {489.333, -649.500},
                    {484.333, -659.333}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 67, 27, 16);
        }

        {
            double vertices[][2] = {
                    {486.750, -602.750},
                    {500.500, -586.250},
                    {504.750, -580.000},
                    {509.000, -564.500},
                    {506.500, -582.000},
                    {510.750, -591.750},
                    {516.000, -602.500},
                    {521.750, -617.000},
                    {522.000, -622.000},
                    {520.750, -610.250},
                    {518.250, -600.000},
                    {517.000, -593.000},
                    {513.250, -586.250},
                    {507.500, -578.500}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 72, 31, 22);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(523.667, -607.667);
        glVertex2d(530.667, -587.667);
        glVertex2d(535.333, -579.333);
        glVertex2d(544.667, -568.333);
        glVertex2d(560.333, -552.000);
        glEnd();

        {
            double vertices[][2] = {
                    {581.167, -519.167},
                    {577.750, -524.583},
                    {573.000, -530.333},
                    {564.750, -538.333},
                    {558.833, -544.750},
                    {550.333, -553.500},
                    {540.750, -565.167},
                    {533.333, -575.000},
                    {532.167, -577.667},
                    {527.167, -570.833},
                    {524.333, -564.667},
                    {521.500, -555.167},
                    {519.667, -546.500},
                    {520.000, -539.000},
                    {521.500, -531.000},
                    {522.833, -524.667},
                    {522.000, -541.500},
                    {523.500, -553.333},
                    {525.167, -559.500},
                    {527.667, -566.167},
                    {532.167, -574.667},
                    {534.667, -567.833},
                    {539.167, -558.500},
                    {541.667, -549.000},
                    {546.500, -537.000},
                    {551.167, -529.167},
                    {565.833, -511.833},
                    {584.625, -492.750},
                    {571.375, -514.125},
                    {560.375, -527.375},
                    {549.500, -543.125},
                    {541.375, -554.250},
                    {537.375, -567.000},
                    {548.000, -552.125},
                    {557.625, -541.125},
                    {570.625, -529.000},
                    {577.000, -522.750}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 72, 31, 18);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(532.750, -493.250);
        glVertex2d(549.500, -480.500);
        glVertex2d(563.250, -471.500);
        glVertex2d(572.250, -466.500);
        glVertex2d(583.000, -454.000);
        glVertex2d(565.250, -477.750);
        glVertex2d(555.750, -494.000);
        glVertex2d(551.500, -502.500);
        glVertex2d(548.500, -512.750);
        glVertex2d(545.750, -523.500);
        glVertex2d(543.750, -534.250);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(559.750, -460.500);
        glVertex2d(547.250, -471.000);
        glVertex2d(530.250, -485.500);
        glVertex2d(522.000, -493.500);
        glVertex2d(514.500, -503.000);
        glVertex2d(506.000, -515.750);
        glVertex2d(498.500, -528.750);
        glVertex2d(492.000, -542.000);
        glEnd();

        {
            double vertices[][2] = {
                    {499.833, -541.333},
                    {489.333, -565.833},
                    {481.833, -584.500},
                    {475.333, -604.000},
                    {472.500, -617.000},
                    {471.333, -619.500},
                    {469.667, -619.000},
                    {469.333, -617.167},
                    {469.833, -608.000},
                    {470.667, -602.500},
                    {476.833, -586.000},
                    {480.333, -577.000},
                    {484.333, -569.000},
                    {491.167, -555.333}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 72, 31, 18);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(487.333, -533.833);
        glVertex2d(479.000, -552.667);
        glVertex2d(474.333, -565.500);
        glVertex2d(468.833, -582.000);
        glVertex2d(465.000, -596.167);
        glVertex2d(462.500, -613.833);
        glVertex2d(462.833, -629.500);
        glVertex2d(462.000, -640.667);
        glVertex2d(457.500, -657.500);
        glVertex2d(456.667, -668.333);
        glVertex2d(453.167, -683.833);
        glVertex2d(450.333, -700.167);
        glVertex2d(454.833, -684.000);
        glVertex2d(457.500, -678.833);
        glVertex2d(459.500, -672.333);
        glVertex2d(464.667, -662.500);
        glVertex2d(462.333, -673.167);
        glVertex2d(459.667, -686.167);
        glVertex2d(458.833, -698.333);
        glVertex2d(458.333, -706.667);
        glVertex2d(459.250, -720.750);
        glVertex2d(468.250, -737.750);
        glVertex2d(454.875, -710.000);
        glVertex2d(451.375, -706.000);
        glVertex2d(448.000, -701.750);
        glVertex2d(444.500, -693.875);
        glVertex2d(438.750, -681.875);
        glVertex2d(436.250, -676.000);
        glVertex2d(431.000, -669.250);
        glVertex2d(426.750, -663.375);
        glVertex2d(422.500, -654.500);
        glVertex2d(415.500, -637.750);
        glVertex2d(412.500, -628.000);
        glVertex2d(409.750, -616.500);
        glVertex2d(409.750, -607.250);
        glVertex2d(416.000, -634.250);
        glVertex2d(420.500, -644.500);
        glVertex2d(428.250, -655.000);
        glVertex2d(428.000, -649.500);
        glVertex2d(427.000, -639.500);
        glVertex2d(424.750, -631.500);
        glVertex2d(422.000, -623.000);
        glVertex2d(420.500, -619.250);
        glVertex2d(421.000, -609.750);
        glVertex2d(420.750, -605.750);
        glVertex2d(422.000, -594.000);
        glVertex2d(420.250, -615.500);
        glVertex2d(421.000, -620.750);
        glVertex2d(424.500, -631.500);
        glVertex2d(430.500, -656.500);
        glVertex2d(438.250, -676.500);
        glVertex2d(435.500, -661.500);
        glVertex2d(433.750, -646.750);
        glEnd();

        {
            double vertices[][2] = {
                    {437.500, -676.750},
                    {429.750, -668.500},
                    {423.750, -657.000},
                    {417.500, -643.500},
                    {411.500, -625.000},
                    {409.000, -607.250},
                    {416.250, -635.500},
                    {425.000, -652.500},
                    {431.000, -657.750}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 61, 27, 18);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(430.000, -594.250);
        glVertex2d(429.250, -609.250);
        glVertex2d(430.500, -625.250);
        glVertex2d(437.000, -643.750);
        glVertex2d(444.500, -661.000);
        glVertex2d(448.500, -668.000);
        glVertex2d(451.500, -664.000);
        glVertex2d(455.500, -652.250);
        glVertex2d(460.750, -637.500);
        glVertex2d(463.000, -626.750);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(450.250, -629.500);
        glVertex2d(452.750, -620.000);
        glVertex2d(454.500, -615.250);
        glVertex2d(459.000, -604.750);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(451.500, -612.500);
        glVertex2d(448.500, -609.000);
        glVertex2d(444.667, -601.333);
        glVertex2d(442.000, -594.500);
        glVertex2d(441.500, -588.500);
        glVertex2d(443.167, -581.167);
        glVertex2d(446.500, -575.500);
        glVertex2d(450.000, -571.000);
        glVertex2d(450.333, -567.833);
        glVertex2d(450.125, -571.125);
        glVertex2d(453.875, -577.188);
        glVertex2d(457.167, -583.000);
        glVertex2d(459.833, -586.833);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(463.500, -581.333);
        glVertex2d(464.667, -572.500);
        glVertex2d(468.333, -560.833);
        glVertex2d(475.667, -545.333);
        glVertex2d(482.333, -531.500);
        glVertex2d(488.167, -522.667);
        glVertex2d(495.667, -513.333);
        glVertex2d(500.333, -510.000);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(467.833, -524.167);
        glVertex2d(464.333, -524.167);
        glVertex2d(461.167, -525.500);
        glVertex2d(458.667, -530.000);
        glVertex2d(458.167, -534.667);
        glVertex2d(457.500, -539.167);
        glVertex2d(452.667, -546.667);
        glVertex2d(451.833, -552.667);
        glVertex2d(451.500, -561.167);
        glVertex2d(451.000, -564.667);
        glVertex2d(445.667, -567.500);
        glVertex2d(438.000, -569.833);
        glVertex2d(430.667, -574.833);
        glVertex2d(422.667, -581.667);
        glVertex2d(415.333, -593.333);
        glVertex2d(407.667, -604.667);
        glVertex2d(402.000, -612.333);
        glVertex2d(395.333, -624.333);
        glVertex2d(399.333, -609.667);
        glVertex2d(403.667, -599.000);
        glVertex2d(409.000, -587.667);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(395.000, -625.667);
        glVertex2d(389.833, -640.000);
        glVertex2d(387.167, -663.000);
        glVertex2d(387.333, -677.833);
        glVertex2d(391.167, -692.333);
        glVertex2d(399.667, -706.333);
        glVertex2d(404.667, -714.167);
        glVertex2d(418.333, -733.667);
        glVertex2d(423.667, -739.667);
        glVertex2d(429.667, -749.000);
        glVertex2d(442.000, -757.000);
        glVertex2d(451.333, -762.000);
        glVertex2d(459.333, -765.333);
        glVertex2d(466.167, -766.833);
        glVertex2d(471.000, -770.333);
        glVertex2d(478.000, -779.167);
        glVertex2d(482.000, -785.667);
        glEnd();

        {
            double vertices[][2] = {
                    {406.500, -711.333},
                    {400.500, -703.000},
                    {394.833, -693.500},
                    {389.833, -678.667},
                    {389.333, -662.500},
                    {391.167, -644.667},
                    {396.500, -630.333},
                    {394.333, -663.167},
                    {396.000, -679.500},
                    {402.333, -695.833},
                    {412.000, -713.333},
                    {418.500, -722.250},
                    {429.250, -732.500}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 40, 18, 16);
        }

        {
            double vertices[][2] = {
                    {408.500, -718.625},
                    {402.875, -709.625},
                    {402.375, -708.375},
                    {403.000, -707.625},
                    {406.000, -710.750},
                    {413.375, -718.625},
                    {423.500, -727.500},
                    {431.250, -733.375},
                    {447.500, -744.875},
                    {459.375, -751.375},
                    {463.625, -752.375},
                    {460.833, -747.667},
                    {450.167, -740.500},
                    {441.667, -735.667},
                    {434.167, -729.167},
                    {419.500, -716.333},
                    {412.667, -707.167},
                    {407.167, -698.833},
                    {404.167, -691.833},
                    {403.500, -688.333},
                    {403.167, -680.833},
                    {409.667, -692.667},
                    {415.833, -704.167},
                    {434.500, -725.333},
                    {421.333, -705.667},
                    {415.333, -697.333},
                    {409.667, -685.833},
                    {418.833, -696.333},
                    {436.833, -707.500},
                    {442.833, -710.500},
                    {446.667, -714.500},
                    {447.167, -718.333},
                    {448.833, -722.667},
                    {452.667, -727.333},
                    {480.667, -756.500},
                    {484.333, -754.000},
                    {496.167, -767.167},
                    {490.167, -772.333},
                    {485.500, -777.833},
                    {481.833, -784.833},
                    {470.833, -769.667},
                    {467.333, -767.000},
                    {460.333, -765.333},
                    {464.333, -764.667},
                    {463.667, -763.500},
                    {462.333, -761.500},
                    {453.167, -759.000},
                    {447.000, -756.000},
                    {442.500, -754.000},
                    {436.667, -751.000},
                    {433.000, -747.333},
                    {428.000, -744.500},
                    {423.167, -739.000},
                    {414.833, -728.667}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 65, 27, 17);
        }

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(403.250, -689.917);
        glVertex2d(400.500, -678.667);
        glVertex2d(398.167, -664.083);
        glVertex2d(403.417, -677.833);
        glVertex2d(407.250, -687.583);
        glEnd();

        glColor4f(86/255.0f, 39/255.0f, 20/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(404.667, -626.167);
        glVertex2d(406.667, -637.333);
        glVertex2d(407.667, -642.833);
        glVertex2d(409.833, -649.500);
        glVertex2d(411.500, -654.500);
        glVertex2d(413.667, -658.667);
        glVertex2d(416.667, -662.500);
        glVertex2d(420.500, -665.667);
        glEnd();
    }

    //Taraf fyonket el4a3r el4Ymeen
    {
        double vertices[][2] = {
                {524.750, -933.250},
                {511.750, -962.000},
                {514.250, -1009.750},
                {513.250, -1030.500},
                {512.750, -1046.250},
                {508.000, -1072.250},
                {507.000, -1078.750},
                {506.917, -1082.250},
                {509.250, -1082.000},
                {517.875, -1077.000},
                {521.500, -1074.375},
                {524.750, -1071.125},
                {527.250, -1067.125},
                {529.125, -1060.625},
                {532.625, -1046.938},
                {533.812, -1042.000},
                {534.938, -1037.250},
                {535.917, -1030.250},
                {535.750, -1002.667},
                {531.417, -1002.500},
                {531.333, -1001.917},
                {531.917, -1000.750},
                {533.167, -998.417},
                {534.417, -997.083},
                {535.917, -995.750},
                {539.167, -993.250},
                {542.500, -991.000},
                {544.333, -989.917},
                {544.125, -984.625},
                {543.625, -977.750},
                {542.750, -969.375},
                {541.750, -961.000},
                {539.750, -946.125},
                {539.250, -941.750}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 71, 23, 9,1, true,78,29,14);
    }
    //fyonket el4a3r
    {
        double vertices[][2] = {
                {508.500, -765.000},
                {504.333, -765.000},
                {501.000, -766.000},
                {495.667, -768.000},
                {490.000, -773.000},
                {484.250, -782.250},
                {480.167, -791.167},
                {476.500, -798.167},
                {473.000, -805.833},
                {468.000, -818.333},
                {463.333, -829.333},
                {459.500, -836.833},
                {455.833, -845.500},
                {454.500, -853.167},
                {453.333, -863.000},
                {453.833, -886.167},
                {457.333, -890.333},
                {460.000, -892.167},
                {464.000, -894.333},
                {467.833, -896.167},
                {472.167, -897.000},
                {476.833, -897.667},
                {481.500, -903.833},
                {485.167, -908.000},
                {489.167, -911.167},
                {494.500, -914.500},
                {499.833, -917.500},
                {539.000, -942.750},
                {543.000, -939.250},
                {553.000, -929.667},
                {554.333, -927.667},
                {556.083, -924.333},
                {557.417, -920.833},
                {558.667, -916.417},
                {559.083, -912.917},
                {559.333, -908.167},
                {562.667, -906.167},
                {567.083, -902.000},
                {571.500, -896.083},
                {574.833, -890.333},
                {579.083, -884.083},
                {579.750, -882.750},
                {580.083, -880.250},
                {579.500, -876.333},
                {578.000, -872.333},
                {576.500, -868.500},
                {574.500, -863.667},
                {575.500, -862.333},
                {579.167, -862.667},
                {581.167, -865.167},
                {583.500, -869.500},
                {584.500, -873.250},
                {582.750, -862.125},
                {580.875, -857.625},
                {577.375, -852.375},
                {571.250, -844.000},
                {560.125, -831.625},
                {551.250, -822.000},
                {545.250, -814.000},
                {538.750, -803.750},
                {532.250, -791.750},
                {525.750, -780.500},
                {520.250, -772.750},
                {516.500, -769.250},
                {512.500, -766.750}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 51, 16, 11,1,true,82,24,11,1);
    }
    //Taraf fyonket el4a3r el4emal
    {
        double vertices[][2] = {
                {514.750, -926.500},
                {500.750, -918.000},
                {498.000, -926.500},
                {491.750, -941.750},
                {482.500, -956.750},
                {470.750, -975.000},
                {467.000, -979.750},
                {455.667, -988.333},
                {450.667, -993.000},
                {444.667, -999.500},
                {439.000, -1007.667},
                {433.833, -1017.833},
                {429.500, -1026.833},
                {426.667, -1033.667},
                {423.000, -1046.167},
                {419.833, -1057.667},
                {418.833, -1065.833},
                {423.000, -1065.917},
                {426.333, -1066.500},
                {429.583, -1067.833},
                {433.167, -1071.083},
                {438.667, -1075.917},
                {441.750, -1079.667},
                {445.667, -1083.000},
                {448.250, -1084.833},
                {450.000, -1085.583},
                {450.917, -1085.417},
                {451.500, -1083.667},
                {454.333, -1072.750},
                {457.417, -1061.417},
                {459.833, -1054.250},
                {465.750, -1034.000},
                {468.417, -1027.583},
                {471.333, -1019.250},
                {473.417, -1015.250},
                {479.750, -1001.125},
                {485.500, -992.375},
                {490.625, -985.000},
                {494.875, -980.375},
                {499.250, -975.250},
                {504.875, -969.625},
                {509.375, -964.750},
                {512.625, -961.875},
                {523.167, -950.500},
                {528.833, -942.500},
                {530.500, -937.000}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 82,24,11,1, true,101,40,17);
    }
    //elShadow elly fe elganb el4emal
    {
        double vertices[][2] = {
                {502.167, -774.083},
                {497.312, -774.562},
                {494.562, -775.562},
                {492.625, -777.812},
                {488.438, -783.875},
                {483.750, -791.312},
                {474.333, -810.333},
                {469.333, -822.833},
                {463.000, -836.375},
                {461.000, -841.500},
                {458.875, -847.250},
                {457.250, -853.875},
                {456.500, -856.625},
                {455.750, -878.625},
                {456.250, -882.250},
                {456.875, -883.875},
                {458.375, -884.375},
                {465.750, -877.000},
                {468.125, -871.500},
                {473.750, -858.750},
                {478.000, -849.000},
                {480.750, -839.625},
                {486.583, -820.417},
                {489.083, -814.583},
                {494.000, -801.667},
                {497.500, -792.917},
                {503.000, -784.417},
                {504.667, -780.833},
                {504.667, -778.250},
                {504.000, -775.583},
                {500.812, -773.812}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 42, 15, 10,1, true,60,20,13);
    }
    //elShadow elly fe elMiddle
    {
        double vertices[][2] = {
                {504.667, -781.250},
                {503.667, -783.333},
                {503.167, -815.000},
                {503.312, -818.062},
                {504.000, -821.938},
                {508.375, -843.375},
                {509.312, -847.500},
                {510.188, -854.188},
                {510.688, -861.188},
                {510.438, -870.062},
                {508.500, -883.875},
                {507.875, -887.125},
                {507.208, -893.917},
                {507.167, -900.042},
                {507.125, -906.375},
                {506.583, -919.583},
                {506.667, -923.000},
                {506.750, -928.500},
                {507.333, -930.833},
                {508.000, -932.167},
                {508.917, -933.250},
                {509.917, -933.833},
                {511.167, -932.917},
                {514.000, -929.167},
                {516.167, -924.417},
                {517.750, -918.583},
                {519.583, -911.667},
                {520.083, -906.833},
                {521.333, -897.833},
                {523.500, -889.667},
                {527.167, -881.667},
                {529.000, -876.833},
                {528.000, -863.000},
                {526.917, -854.333},
                {526.167, -850.000},
                {525.083, -846.167},
                {523.167, -839.083},
                {521.625, -832.417},
                {520.438, -827.969},
                {518.292, -821.958},
                {516.500, -818.375},
                {514.667, -813.667},
                {512.917, -808.083},
                {510.833, -799.333},
                {509.750, -795.167},
                {508.417, -788.750},
                {507.167, -783.333},
                {506.250, -779.417}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 40, 14, 10,1, true,62,21,14);
    }
    //elShadow elly fe elganb elYmeen
    {
        double vertices[][2] = {
                {522.750, -777.500},
                {522.750, -783.875},
                {523.250, -787.625},
                {524.750, -794.000},
                {528.875, -803.500},
                {532.375, -810.625},
                {536.750, -817.375},
                {542.875, -825.375},
                {546.750, -830.375},
                {546.917, -813.500},
                {541.917, -808.917},
                {537.625, -803.625},
                {532.250, -794.500},
                {529.250, -788.250},
                {527.500, -783.875},
                {525.000, -779.625}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 44, 13, 11,1, true,61,20,14);
    }
    //elShadow elle ta7t fe elganb elyeen
    {
        double vertices[][2] = {
                {531.167, -936.250},
                {534.167, -931.000},
                {537.417, -925.083},
                {540.167, -917.500},
                {540.917, -913.333},
                // empty line
                {541.000, -911.417},
                {544.417, -911.583},
                {548.250, -911.000},
                {551.500, -910.500},
                {557.083, -909.000},
                {559.333, -908.000},
                {559.062, -913.250},
                {558.188, -917.688},
                {556.688, -922.625},
                {554.562, -927.375},
                {552.938, -929.750},
                {539.625, -942.375}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 67, 22, 12,1, true,65,22,12);
    }
    //outlines fuonket el4a3r
    {
        glBegin(GL_LINE_LOOP);
        glColor4f(26/255.0f, 8/255.0f, 5/255.0f, 1.0f);
        glVertex2d(508.500, -765.000);
        glVertex2d(504.333, -765.000);
        glVertex2d(501.000, -766.000);
        glVertex2d(495.667, -768.000);
        glVertex2d(490.000, -773.000);
        glVertex2d(484.250, -782.250);
        glVertex2d(480.167, -791.167);
        glVertex2d(476.500, -798.167);
        glVertex2d(473.000, -805.833);
        glVertex2d(468.000, -818.333);
        glColor4f(26/255.0f, 8/255.0f, 5/255.0f, 0.0f);
        glVertex2d(463.333, -829.333);
        glVertex2d(459.500, -836.833);
        glVertex2d(455.833, -845.500);
        glVertex2d(454.500, -853.167);
        glVertex2d(453.333, -863.000);
        glVertex2d(453.833, -886.167);
        glVertex2d(457.333, -890.333);
        glVertex2d(460.000, -892.167);
        glVertex2d(464.000, -894.333);
        glVertex2d(467.833, -896.167);
        glVertex2d(472.167, -897.000);
        glVertex2d(476.833, -897.667);
        glVertex2d(481.500, -903.833);
        glVertex2d(485.167, -908.000);
        glVertex2d(489.167, -911.167);
        glVertex2d(494.500, -914.500);
        glVertex2d(499.833, -917.500);
        glVertex2d(539.000, -942.750);
        glVertex2d(543.000, -939.250);
        glVertex2d(553.000, -929.667);
        glVertex2d(554.333, -927.667);
        glVertex2d(556.083, -924.333);
        glVertex2d(557.417, -920.833);
        glVertex2d(558.667, -916.417);
        glVertex2d(559.083, -912.917);
        glVertex2d(559.333, -908.167);
        glVertex2d(562.667, -906.167);
        glVertex2d(567.083, -902.000);
        glVertex2d(571.500, -896.083);
        glVertex2d(574.833, -890.333);
        glVertex2d(579.083, -884.083);
        glVertex2d(579.750, -882.750);
        glVertex2d(580.083, -880.250);
        glVertex2d(579.500, -876.333);
        glVertex2d(578.000, -872.333);
        glVertex2d(576.500, -868.500);
        glVertex2d(574.500, -863.667);
        glVertex2d(575.500, -862.333);
        glVertex2d(579.167, -862.667);
        glVertex2d(581.167, -865.167);
        glVertex2d(583.500, -869.500);
        glVertex2d(584.500, -873.250);
        glVertex2d(582.750, -862.125);
        glVertex2d(580.875, -857.625);
        glVertex2d(577.375, -852.375);
        glVertex2d(571.250, -844.000);
        glVertex2d(560.125, -831.625);
        glColor4f(26/255.0f, 8/255.0f, 5/255.0f, 1.0f);
        glVertex2d(551.250, -822.000);
        glVertex2d(545.250, -814.000);
        glVertex2d(538.750, -803.750);
        glVertex2d(532.250, -791.750);
        glVertex2d(525.750, -780.500);
        glVertex2d(520.250, -772.750);
        glVertex2d(516.500, -769.250);
        glVertex2d(512.500, -766.750);
        glEnd();

    }
    //outlines elShadow elly fe elMiddle
    {
        glColor4f(41/255.0f, 15/255.0f, 12/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(504.667, -781.250);
        glVertex2d(503.667, -783.333);
        glVertex2d(503.167, -815.000);
        glVertex2d(503.312, -818.062);
        glVertex2d(504.000, -821.938);
        glVertex2d(508.375, -843.375);
        glVertex2d(509.312, -847.500);
        glVertex2d(510.188, -854.188);
        glVertex2d(510.688, -861.188);
        glVertex2d(510.438, -870.062);
        glVertex2d(508.500, -883.875);
        glColor4f(41/255.0f, 15/255.0f, 12/255.0f, 0.0f);
        glVertex2d(507.875, -887.125);
        glEnd();

        glColor4f(40/255.0f, 14/255.0f, 10/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(503.667, -775.667);
        glVertex2d(509.000, -793.333);
        glVertex2d(515.000, -812.167);
        glVertex2d(518.500, -823.333);
        glVertex2d(523.333, -840.167);
        glVertex2d(527.833, -857.333);
        glColor4f(40/255.0f, 14/255.0f, 10/255.0f, 0.5f);
        glVertex2d(529.000, -872.667);
        glVertex2d(529.333, -889.167);
        glVertex2d(529.000, -903.333);
        glColor4f(40/255.0f, 314/255.0f, 10/255.0f, 0.1f);
        glVertex2d(526.833, -907.833);
        glEnd();

    }
    //outlines elShadow elly fe elganb elYmeen
    {
        glColor4f(41 / 255.0f, 15 / 255.0f, 12 / 255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(522.250, -776.125);
        glVertex2d(523.000, -786.375);
        glVertex2d(524.125, -792.250);
        glVertex2d(528.000, -801.750);
        glVertex2d(532.875, -811.125);
        glVertex2d(537.625, -818.500);
        glColor4f(41 / 255.0f, 15 / 255.0f, 12 / 255.0f, 0.2);
        glVertex2d(542.625, -825.000);
        glVertex2d(549.750, -833.375);
        glEnd();
    }
    //outlinrs elShadow elle ta7t fe elganb elyeen men ta7t
    {
        glColor4f(65/255.0f, 17/255.0f, 10/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(536.000, -910.500);
        glVertex2d(544.750, -910.250);
        glVertex2d(558.500, -908.000);
        glVertex2d(565.250, -904.250);
        glVertex2d(571.250, -897.250);
        glVertex2d(574.250, -892.250);
        glVertex2d(579.500, -884.500);
        glVertex2d(580.250, -882.500);
        glVertex2d(580.250, -879.250);
        glVertex2d(579.250, -873.750);
        glVertex2d(577.750, -871.000);
        glVertex2d(575.750, -866.250);
        glVertex2d(574.250, -863.250);
        glVertex2d(574.500, -862.250);
        glVertex2d(576.250, -862.250);
        glVertex2d(578.250, -863.750);
        glVertex2d(580.750, -866.000);
        glVertex2d(584.250, -871.250);
        glVertex2d(586.500, -878.250);
        glEnd();

    }
    //elLight elly fe elganb el4emal
    {
        glBegin(GL_LINE_STRIP);
        glColor4f(137/255.0f, 53/255.0f, 15/255.0f, 0.5f);
        glVertex2d(494.875, -771.500);
        glVertex2d(483.750, -788.875);
        glVertex2d(475.625, -803.875);
        glColor4f(137/255.0f, 53/255.0f, 15/255.0f, 1);
        glVertex2d(466.125, -826.750);
        glColor4f(137/255.0f, 53/255.0f, 15/255.0f, 0.6);
        glVertex2d(459.375, -843.250);
        glVertex2d(456.750, -853.000);
        glVertex2d(455.250, -860.000);
        glColor4f(137/255.0f, 53/255.0f, 15/255.0f, 0.3);
        glVertex2d(454.750, -868.500);
        glVertex2d(454.625, -881.625);
        glEnd();

    }
    //light eltaraf el4emal 1
    {
        glColor4f(90/255.0f, 32/255.0f, 12/255.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2d(531.667, -939.333);
        glVertex2d(525.833, -946.000);
        glVertex2d(521.167, -949.167);
        glVertex2d(515.333, -951.667);
        glVertex2d(502.833, -955.333);
        glVertex2d(496.000, -958.333);
        glVertex2d(490.000, -961.500);
        glVertex2d(483.000, -969.833);
        glVertex2d(479.167, -973.833);
        glVertex2d(476.500, -975.667);
        glVertex2d(473.000, -977.667);
        glVertex2d(466.167, -979.667);
        glEnd();

    }
    //light eltaraf el4emal 2
    {
        double vertices[][2] = {
                {422.250, -1055.250},
                {426.250, -1044.500},
                {432.500, -1029.250},
                {438.500, -1017.000},
                {444.500, -1006.500},
                {455.250, -995.250},
                {459.750, -990.500},
                {464.500, -986.500},
                {468.750, -982.250},
                {477.250, -977.500},
                {466.750, -982.000},
                {458.500, -986.000},
                {452.000, -991.250},
                {448.250, -996.000},
                {444.250, -1001.250},
                {440.500, -1006.500},
                {436.250, -1013.750},
                {431.750, -1023.750},
                {428.250, -1032.500},
                {425.000, -1042.250}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 184, 62, 11);
    }
}

void drawBlouse()
{
    //blouse base
    {
        //elgz2 elso8ayar men elymeen fe elganb beta3 elblouse
        {
            //elbase
            {
                double vertices[][2] = {
                        { 1005.167, -1517.333 },
                        { 1014.333, -1527.833 },
                        { 1026.000, -1547.167 },
                        { 1035.000, -1564.500 },
                        { 1039.333, -1578.000 },
                        { 1041.333, -1590.000 },
                        { 1044.500, -1604.500 },
                        { 1048.833, -1615.667 },
                        { 1051.500, -1627.667 },
                        { 1048.833, -1631.167 },
                        { 1025.667, -1645.500 },
                        { 1023.500, -1644.500 },
                        { 1021.500, -1637.167 },
                        { 1020.167, -1628.333 },
                        { 1018.333, -1617.333 },
                        { 1016.000, -1604.167 },
                        { 1011.833, -1594.667 },
                        { 1006.333, -1586.000 },
                        { 1002.333, -1579.667 },
                        { 1000.250, -1575.333 },
                        { 999.583, -1573.000 },
                        { 993.583, -1581.750 },
                        { 992.333, -1579.667 },
                        { 992.333, -1576.750 },
                        { 993.667, -1574.000 },
                        { 995.333, -1571.167 },
                        { 998.083, -1568.583 },
                        { 999.833, -1567.250 },
                        { 1002.083, -1567.167 },
                        { 1005.750, -1567.917 },
                        { 1001.083, -1557.667 }
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                drawConcavePolygon(vertices, size, 186, 100, 46);
            }
            //elLight elle fe elganb 3ala el4emal
            {
                double vertices[][2] = {
                        { 1016.417, -1604.083 },
                        { 1015.583, -1597.083 },
                        { 1014.500, -1592.083 },
                        { 1012.083, -1586.750 },
                        { 1010.333, -1583.750 },
                        { 1009.417, -1580.083 },
                        { 1008.917, -1576.000 },
                        { 1008.750, -1572.750 },
                        { 1007.417, -1570.750 },
                        { 1004.833, -1568.583 },
                        { 1002.583, -1567.667 },
                        { 999.667, -1568.000 },
                        { 997.083, -1570.500 },
                        { 994.833, -1573.417 },
                        { 993.250, -1576.250 },
                        { 992.750, -1579.250 },
                        { 993.167, -1580.750 },
                        { 994.667, -1578.667 },
                        { 996.583, -1575.667 },
                        { 998.500, -1573.500 },
                        { 999.333, -1572.833 },
                        { 1000.333, -1573.833 },
                        { 1001.667, -1577.833 },
                        { 1004.667, -1583.000 },
                        { 1008.500, -1588.917 },
                        { 1010.833, -1593.000 },
                        { 1013.250, -1596.583 },
                        { 1014.333, -1599.750 }
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                drawConcavePolygon(vertices, size, 211, 123, 55);
            }
            //elLight elle fe elganb 3ala elymeen
            {
                double vertices[][2] = {
                        { 1009.250, -1571.375 },
                        { 1003.750, -1566.500 },
                        { 1008.750, -1528.875 },
                        { 1009.000, -1570.125 },
                        { 1011.750, -1577.000 },
                        { 1011.625, -1524.750 },
                        { 1026.375, -1547.250 },
                        { 1035.625, -1566.125 },
                        { 1039.500, -1581.875 },
                        { 1041.750, -1593.250 },
                        { 1043.500, -1600.125 },
                        { 1045.500, -1606.625 },
                        { 1049.625, -1618.500 },
                        { 1050.000, -1628.375 },
                        { 1041.625, -1635.625 },
                        { 1041.250, -1635.625 },
                        { 1038.500, -1615.375 },
                        { 1036.250, -1603.875 },
                        { 1031.750, -1594.875 },
                        { 1024.375, -1586.250 },
                        { 1011.750, -1576.875 }
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                drawConcavePolygon(vertices, size, 208, 127, 64,0.8,true,252,228,170);
            }
            //elgoz2 el8ame2 ta7t
            {
                glBegin(GL_POLYGON);
                glColor4f(123/255.0f, 57/255.0f, 21/255.0f, 1);
                glVertex2f(1037.875, -1637.875);
                glColor4f(123/255.0f, 57/255.0f, 21/255.0f, 0.4);
                glVertex2f(1035.250, -1639.250);
                glVertex2f(1035.500, -1622.562);
                glVertex2f(1035.562, -1612.750);
                glVertex2f(1039.562, -1623.688);
                glVertex2f(1039.938, -1629.000);
                glVertex2f(1039.938, -1636.562);
                glEnd();
            }



        }
        //layer1
        {
            double vertices[][2]={
                    {400 , -1240.5},
                    {400 , -1253.5},
                    {400.667 , -1321.17},
                    {401.75 , -1356.5},
                    {404.5 , -1378.88},
                    {410.25 , -1413.88},
                    {415.25 , -1440.75},
                    {420.167 , -1467},
                    {425 , -1486.83},
                    {418.167 , -1518.5},
                    {414.667 , -1528.17},
                    {408.667 , -1545.17},
                    {403 , -1558.5},
                    {401.708 , -1560.58},
                    {401.25 , -1563.58},
                    {402.083 , -1566.96},
                    {413.438 , -1591.75},
                    {402.667 , -1607.83},
                    {398.167 , -1615.83},
                    {393.333 , -1626.17},
                    {389 , -1636.67},
                    {384.333 , -1648.83},
                    {379.833 , -1663.5},
                    {373.667 , -1685.42},
                    {372.583 , -1691.17},
                    {370.833 , -1698.17},
                    {370.333 , -1703},
                    {370.833 , -1712.58},
                    {372 , -1716.21},
                    {374.292 , -1720.04},
                    {376.125 , -1723},
                    {381.333 , -1729.75},
                    {387.75 , -1736.83},
                    {406.417 , -1754.83},
                    {411.583 , -1759.25},
                    {415.417 , -1763},
                    {423 , -1770.33},
                    {436 , -1783.33},
                    {447.25 , -1794.67},
                    {455.167 , -1801.42},
                    {463.583 , -1808.33},
                    {466.5 , -1810.58},
                    {470.167 , -1813},
                    {473.5 , -1814.67},
                    {476.5 , -1815.75},
                    {478.75 , -1816},
                    {486.125 , -1816.25},
                    {500.75 , -1816.5},
                    {518.125 , -1817.75},
                    {534.458 , -1819.88},
                    {542.917 , -1821},
                    {550.958 , -1822.67},
                    {550 , -1829.46},
                    {548.167 , -1838.04},
                    {546.125 , -1843.44},
                    {545.875 , -1845.38},
                    {546.75 , -1846.25},
                    {557.562 , -1853.06},
                    {564.875 , -1847.06},
                    {565.25 , -1845.81},
                    {565.188 , -1844.75},
                    {564 , -1839.62},
                    {563.812 , -1838.88},
                    //flag1
                    {565.188 , -1840.5},
                    {565.875 , -1840.62},
                    {567.375 , -1840.19},
                    {582.625 , -1828.19},
                    {602.75 , -1832.5},
                    {611.75 , -1834.25},
                    {623 , -1838},
                    {647.25 , -1848.75},
                    {660.25 , -1848.25},
                    {689.667 , -1860.33},
                    {696.5 , -1877.67},
                    {699.833 , -1884},
                    {702.833 , -1888.5},
                    {707.667 , -1895},
                    {711.25 , -1898.75},
                    {713 , -1900},
                    {716.583 , -1900.5},
                    {725.583 , -1900.75},
                    {737.083 , -1900.33},
                    {744.083 , -1899.42},
                    {756 , -1897},
                    {765.167 , -1894.33},
                    {807 , -1883},
                    {828 , -1876.75},
                    {843.25 , -1872.5},
                    {850.688 , -1872},
                    {847.25 , -1872.12},
                    {849.75 , -1873.62},
                    {855 , -1874.88},
                    {863.875 , -1875.38},
                    {875.875 , -1876.12},
                    {897.25 , -1877.25},
                    {910.875 , -1877.25},
                    {929.5 , -1877.25},
                    {938.125 , -1877},
                    {953.75 , -1875},
                    {961.5 , -1874.67},
                    {972.75 , -1872.67},
                    {985.583 , -1870.25},
                    {1012 , -1865.83},
                    {1027 , -1862.67},
                    {1036.5 , -1860.17},
                    {1037.5 , -1859.17},
                    {1066.17 , -1861.17},
                    {1090.67 , -1862.33},
                    {1131.5 , -1862.83},
                    {1136.25 , -1859.25},
                    {1139.5 , -1852.62},
                    {1144.25 , -1842},
                    {1147.5 , -1829.38},
                    {1148.25 , -1823},
                    {1141 , -1755},
                    {1140.25 , -1751.25},
                    {1136.75 , -1744.75},
                    {1133.88 , -1738.62},
                    {1126.88 , -1727.88},
                    {1121.62 , -1719.88},
                    {1117.75 , -1715.75},
                    {1112 , -1711.75},
                    {1108.88 , -1710.5},
                    {1102.62 , -1710.25},
                    {1095.17 , -1711.5},
                    {1088.5 , -1713.5},
                    {1080.83 , -1715.33},
                    {1075.33 , -1716.5},
                    {1069 , -1716.83},
                    {1056.5 , -1716.83},
                    {1049.5 , -1715.67},
                    {1042.33 , -1714.17},
                    {1033.83 , -1710.17},
                    {1025.25 , -1704.38},
                    {1018.38 , -1699.38},
                    {1015.88 , -1697.5},
                    {1015.17 , -1697},
                    {1012.83 , -1691.83},
                    {1010 , -1683.67},
                    {1007.83 , -1671.17},
                    {1006 , -1656},
                    {1004.17 , -1636.83},
                    {1003.33 , -1624.83},
                    {1005 , -1566.67},
                    {1004.33 , -1553.67},
                    {1005.38 , -1542.88},
                    {1006.38 , -1536.12},
                    {1007.62 , -1527.62},
                    {1009.12 , -1520.38},
                    {1010.62 , -1513.25},
                    {1010.75 , -1502},
                    {1013.75 , -1424.5},
                    {1013.88 , -1395.75},
                    {1013.38 , -1379.5},
                    {1012.88 , -1371.12},
                    {1011.5 , -1365.75},
                    {1006.12 , -1350.88},
                    {991.5 , -1321.62},
                    {987.667 , -1310.33},
                    {980.833 , -1294},
                    {972.833 , -1279},
                    {963 , -1263.83},
                    {954.5 , -1253},
                    {941.875 , -1236.5},
                    {935.5 , -1229.12},
                    {928.375 , -1221.75},
                    {921.375 , -1214.62},
                    {914.5 , -1209.12},
                    {914.625 , -1199.12},
                    {912.75 , -1188.75},
                    {909.25 , -1177},
                    {905.5 , -1172.5},
                    {893.25 , -1165},
                    {895 , -1171},
                    {900.5 , -1178.75},
                    {894.75 , -1173.5},
                    {897.5 , -1179.5},
                    {900.75 , -1183},
                    {902.5 , -1186.5},
                    {894.5 , -1176.75},
                    {891.75 , -1173.5},
                    {887.25 , -1166.75},
                    {878.5 , -1154.75},
                    {872.25 , -1146.75},
                    {863 , -1132.75},
                    {845.833 , -1113.33},
                    {838.5 , -1100.83},
                    {825 , -1072.83},
                    {821.5 , -1067.5},
                    {818.833 , -1063},
                    {814 , -1054.5},
                    {811.333 , -1048.83},
                    {809.667 , -1044.17},
                    {807.167 , -1038.33},
                    {798.667 , -1014},
                    {795 , -1003.67},
                    {793.833 , -1001.5},
                    {790.667 , -997.5},
                    {787.667 , -994.333},
                    {786 , -992.25},
                    {785.5 , -989.5},
                    {784.417 , -986.417},
                    {780.75 , -982.833},
                    {775.583 , -978.583},
                    {773.5 , -976.25},
                    {772.25 , -970},
                    {773.75 , -960.75},
                    {774.75 , -954},
                    {774.75 , -944.25},
                    {774 , -940},
                    {771.917 , -942.167},
                    {770.75 , -944},
                    //flag2
                    {587.125 , -881.625},
                    {579.625 , -883.875},
                    {578 , -886},
                    {579 , -891.375},
                    {580.375 , -898.75},
                    {582.375 , -903.375},
                    {569.25 , -911.125},
                    {569.625 , -913.375},
                    {572.5 , -919.25},
                    {572.625 , -920.75},
                    {549.25 , -936},
                    {548.958 , -937.125},
                    {549.042 , -938.583},
                    {555.875 , -953.125},
                    {550.25 , -964.917},
                    {548.583 , -969.417},
                    {546.667 , -974.75},
                    {545.167 , -980.833},
                    {544.417 , -988.5},
                    {544.75 , -989.667},
                    {535.5 , -997.25},
                    {533 , -999.75},
                    {532.375 , -1001.5},
                    {532.375 , -1002.62},
                    {512.5 , -1029.12},
                    {511.25 , -1032.75},
                    {505.125 , -1038.62},
                    {493.375 , -1048.25},
                    {489.625 , -1051.62},
                    {488.875 , -1054.5},
                    {488.875 , -1059.75},
                    {486.75 , -1066.69},
                    {482.375 , -1075.94},
                    {478.438 , -1083.25},
                    {470 , -1096.75},
                    {454.75 , -1125.62},
                    {444.125 , -1145.62},
                    {433.375 , -1166.62},
                    {408 , -1215.75},
                    {404.5 , -1224.5},
                    {402.75 , -1229.88},
                    {401.25 , -1235.12},
                    {400.25 , -1238.88}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size,/* 115, 63, 39,1,true,*/165,96,52,1);
        }
        //layer2 && 3
        {
            //base elShadow
            double vertices[][2]={
                    {587.125 , -881.625},
                    {579.625 , -883.875},
                    {578 , -886},
                    {579 , -891.375},
                    {580.375 , -898.75},
                    {582.375 , -903.375},
                    {569.25 , -911.125},
                    {569.625 , -913.375},
                    {572.5 , -919.25},
                    {572.625 , -920.75},
                    {549.25 , -936},
                    {548.958 , -937.125},
                    {549.042 , -938.583},
                    {555.875 , -953.125},
                    {550.25 , -964.917},
                    {548.583 , -969.417},
                    {546.667 , -974.75},
                    {545.167 , -980.833},
                    {544.417 , -988.5},
                    {544.75 , -989.667},
                    {535.5 , -997.25},
                    {533 , -999.75},
                    {532.375 , -1001.5},
                    {532.375 , -1002.62},
                    {512.5 , -1029.12},
                    {511.25 , -1032.75},
                    {505.125 , -1038.62},
                    {493.375 , -1048.25},
                    {489.625 , -1051.62},
                    {488.875 , -1054.5},
                    {488.875 , -1059.75},
                    {486.75 , -1066.69},
                    {482.375 , -1075.94},
                    {478.438 , -1083.25},
                    {470 , -1096.75},
                    {454.75 , -1125.62},
                    {444.125 , -1145.62},
                    {433.375 , -1166.62},
                    {408 , -1215.75},
                    {404.5 , -1224.5},
                    {402.75 , -1229.88},
                    {401.25 , -1235.12},
                    {400.25 , -1238.88},
                    {400 , -1240.5},
                    {400 , -1253.5},
                    {400.667 , -1321.17},
                    {401.75 , -1356.5},
                    {404.5 , -1378.88},
                    {410.25 , -1413.88},
                    {415.25 , -1440.75},
                    {420.167 , -1467},
                    {425 , -1486.83},
                    {418.167 , -1518.5},
                    {414.667 , -1528.17},
                    {408.667 , -1545.17},
                    {403 , -1558.5},
                    {401.708 , -1560.58},
                    {401.25 , -1563.58},
                    {402.083 , -1566.96},
                    {413.438 , -1591.75},
                    {402.667 , -1607.83},
                    {398.167 , -1615.83},
                    {393.333 , -1626.17},
                    {389 , -1636.67},
                    {384.333 , -1648.83},
                    {379.833 , -1663.5},
                    {373.667 , -1685.42},
                    {372.583 , -1691.17},
                    {370.833 , -1698.17},
                    {370.333 , -1703},
                    {370.833 , -1712.58},
                    {372 , -1716.21},
                    {374.292 , -1720.04},
                    {376.125 , -1723},
                    {381.333 , -1729.75},
                    {387.75 , -1736.83},
                    {406.417 , -1754.83},
                    {411.583 , -1759.25},
                    {415.417 , -1763},
                    {423 , -1770.33},
                    {436 , -1783.33},
                    {447.25 , -1794.67},
                    {455.167 , -1801.42},
                    {463.583 , -1808.33},
                    {466.5 , -1810.58},
                    {470.167 , -1813},
                    {473.5 , -1814.67},
                    {476.5 , -1815.75},
                    {478.75 , -1816},
                    {486.125+60 , -1816.25},
                    //el point elly fe nose zel elkom
                    /*{486.125+30 , -1353},*/
                    {519 , -1503},

                    {500.75 , -1816.5},
                    {518.125 , -1817.75},
                    {534.458 , -1819.88},
                    {542.917 , -1821},
                    {550.958 , -1822.67},
                    {550 , -1829.46}
                    /*
                {548.167 , -1838.04},
                {546.125 , -1843.44},
                {545.875 , -1845.38},
                {546.75 , -1846.25},
                {557.562 , -1853.06},
                {564.875 , -1847.06},
                {565.25 , -1845.81},
                {565.188 , -1844.75},
                {564 , -1839.62},
                {563.812 , -1838.88},*/
                    //flag1
                    /*{565.188 , -1840.5},
                {565.875 , -1840.62},
                {567.375 , -1840.19},
                {582.625 , -1828.19},
                {602.75 , -1832.5},
                {611.75 , -1834.25},
                {623 , -1838},
                {647.25 , -1848.75},
                {660.25 , -1848.25},
                {689.667 , -1860.33},
                {696.5 , -1877.67},
                {699.833 , -1884},
                {702.833 , -1888.5},
                {707.667 , -1895},
                {711.25 , -1898.75},
                {713 , -1900},
                {716.583 , -1900.5},
                {725.583 , -1900.75},
                {737.083 , -1900.33},
                {744.083 , -1899.42},
                {756 , -1897},
                {765.167 , -1894.33},
                {807 , -1883},
                {828 , -1876.75},
                {843.25 , -1872.5},
                {850.688 , -1872},
                {847.25 , -1872.12},
                {849.75 , -1873.62},
                {855 , -1874.88},
                {863.875 , -1875.38},
                {875.875 , -1876.12},
                {897.25 , -1877.25},
                {910.875 , -1877.25},
                {929.5 , -1877.25},
                {938.125 , -1877},
                {953.75 , -1875},
                {961.5 , -1874.67},
                {972.75 , -1872.67},
                {985.583 , -1870.25},
                {1012 , -1865.83},
                {1027 , -1862.67},
                {1036.5 , -1860.17},
                {1037.5 , -1859.17},
                {1066.17 , -1861.17},
                {1090.67 , -1862.33},
                {1131.5 , -1862.83},
                {1136.25 , -1859.25},
                {1139.5 , -1852.62},
                {1144.25 , -1842},
                {1147.5 , -1829.38},
                {1148.25 , -1823},
                {1141 , -1755},
                {1140.25 , -1751.25},
                {1136.75 , -1744.75},
                {1133.88 , -1738.62},
                {1126.88 , -1727.88},
                {1121.62 , -1719.88},
                {1117.75 , -1715.75},
                {1112 , -1711.75},
                {1108.88 , -1710.5},
                {1102.62 , -1710.25},
                {1095.17 , -1711.5},
                {1088.5 , -1713.5},
                {1080.83 , -1715.33},
                {1075.33 , -1716.5},
                {1069 , -1716.83},
                {1056.5 , -1716.83},
                {1049.5 , -1715.67},
                {1042.33 , -1714.17},
                {1033.83 , -1710.17},
                {1025.25 , -1704.38},
                {1018.38 , -1699.38},
                {1015.88 , -1697.5},
                {1015.17 , -1697},
                {1012.83 , -1691.83},
                {1010 , -1683.67},
                {1007.83 , -1671.17},
                {1006 , -1656},
                {1004.17 , -1636.83},
                {1003.33 , -1624.83},
                {1005 , -1566.67},
                {1004.33 , -1553.67},
                {1005.38 , -1542.88},
                {1006.38 , -1536.12},
                {1007.62 , -1527.62},
                {1009.12 , -1520.38},
                {1010.62 , -1513.25},
                {1010.75 , -1502},
                {1013.75 , -1424.5},
                {1013.88 , -1395.75},
                {1013.38 , -1379.5},
                {1012.88 , -1371.12},
                {1011.5 , -1365.75},
                {1006.12 , -1350.88},
                {991.5 , -1321.62},
                {987.667 , -1310.33},
                {980.833 , -1294},
                {972.833 , -1279},
                {963 , -1263.83},
                {954.5 , -1253},
                {941.875 , -1236.5},
                {935.5 , -1229.12},
                {928.375 , -1221.75},
                {921.375 , -1214.62},
                {914.5 , -1209.12},
                {914.625 , -1199.12},
                {912.75 , -1188.75},
                {909.25 , -1177},
                {905.5 , -1172.5},
                {893.25 , -1165},
                {895 , -1171},
                {900.5 , -1178.75},
                {894.75 , -1173.5},
                {897.5 , -1179.5},
                {900.75 , -1183},
                {902.5 , -1186.5},
                {894.5 , -1176.75},
                {891.75 , -1173.5},
                {887.25 , -1166.75},
                {878.5 , -1154.75},
                {872.25 , -1146.75},
                {863 , -1132.75},
                {845.833 , -1113.33},
                {838.5 , -1100.83},
                {825 , -1072.83},
                {821.5 , -1067.5},
                {818.833 , -1063},
                {814 , -1054.5},
                {811.333 , -1048.83},
                {809.667 , -1044.17},
                {807.167 , -1038.33},
                {798.667 , -1014},
                {795 , -1003.67},
                {793.833 , -1001.5},
                {790.667 , -997.5},
                {787.667 , -994.333},
                {786 , -992.25},
                {785.5 , -989.5},
                {784.417 , -986.417},
                {780.75 , -982.833},
                {775.583 , -978.583},
                {773.5 , -976.25},
                {772.25 , -970},
                {773.75 , -960.75},
                {774.75 , -954},
                {774.75 , -944.25},
                {774 , -940},
                {771.917 , -942.167},
                {770.75 , -944}*/
                    //flag2

            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size-6, 115, 63, 39,1);

            //elShadow line el5aregee
            glLineWidth(3);
            glColor4f(113/255.0f,56/255.0f,31/255.0f,0.8);
            glBegin(GL_LINE_STRIP);
            for (int i = 0; i < size; i++) {
                if (i==size-7) continue;
                if (i==size-6)
                    glColor4f(113/255.0f,56/255.0f,31/255.0f,0.5);
                glVertex2dv(vertices[i]);
            }
            glEnd();

            //elTamweeh beta3 elShadow
            glBegin(GL_POLYGON);
            glColor4f(115/255.0f,63/255.0f,39/255.0f,1);
            //el point elly fe nose zel elkom
            // glVertex2d(486.125+30,-1353);
            glVertex2d(519,-1503);
            glVertex2d(486.125+60,-1816.25);
            glVertex2f(500.75, -1816.5);
            glVertex2f(518.125, -1817.75);
            glVertex2f(534.458, -1819.88);
            glVertex2f(542.917, -1821);
            glVertex2f(550.958, -1822.67);
            glVertex2f(550, -1829.46);
            glVertex2f(548.167, -1838.04);
            glVertex2f(546.125, -1843.44);
            glVertex2f(545.875, -1845.38);
            glVertex2f(546.75, -1846.25);
            glVertex2f(557.562, -1853.06);
            glVertex2f(564.875, -1847.06);
            glVertex2f(565.25, -1845.81);
            glVertex2f(565.188, -1844.75);
            glVertex2f(564, -1839.62);
            glVertex2f(563.812, -1838.88);
            glVertex2f(565.188, -1840.5);
            glVertex2f(565.875, -1840.62);
            glVertex2f(567.375, -1840.19);
            glVertex2f(582.625, -1828.19);

            glColor4f(165/255.0f,96/255.0f,52/255.0f,1);
            glVertex2d(687,-1862);
            glVertex2d(592+100,-881.625);
            glColor4f(115/255.0f,63/255.0f,39/255.0f,1);
            glVertex2d(587.125,-881.625);
            //el point elly fe nose zel elkom
            // glVertex2d(486.125+30,-1353);
            glEnd();
        }
        //elgz2 elso8ayar men el4emal ta7t fe elblouse
        {
            double vertices[][2] = {
                    { 518.250, -1818.500 },
                    { 515.583, -1827.250 },
                    { 511.417, -1833.667 },
                    { 503.333, -1842.833 },
                    { 493.500, -1849.750 },
                    { 486.000, -1853.500 },
                    { 480.625, -1855.750 },
                    { 478.500, -1855.875 },
                    { 465.625, -1840.000 },
                    { 468.500, -1837.250 },
                    { 472.500, -1831.500 },
                    { 475.750, -1826.125 },
                    { 477.875, -1820.375 },
                    { 478.250, -1816.000 },
                    { 494.500, -1811.250 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 115, 63, 39,1);
            glLineWidth(1);
            //color outline elBlouse
            glColor4f(68/255.0f,28/255.0f,15/255.0f,0.8);
            glBegin(GL_LINE_STRIP);
            for (int i = 0; i < size-1; i++) {
                glVertex2dv(vertices[i]);
            }
            glEnd();
        }
    }
    //blouse light
    {
        //elSelection elawal men el4emal (3ala elkom)
        {
            double vertices[][2] = {
                    {880.833, -1587.833},
                    {876.500, -1584.333},
                    {871.500, -1582.000},
                    {865.167, -1580.333},
                    {855.500, -1580.333},
                    {847.500, -1582.167},
                    {836.667, -1586.333},
                    {824.000, -1592.000},
                    {809.000, -1601.333},
                    {794.250, -1613.500},
                    {789.500, -1617.250},
                    {780.500, -1621.750},
                    {772.000, -1624.000},
                    {766.250, -1624.000},
                    {752.500, -1624.250},
                    {740.750, -1624.750},
                    {733.500, -1625.250},
                    {727.500, -1626.500},
                    {722.000, -1628.000},
                    {716.750, -1630.500},
                    {708.750, -1633.000},
                    {700.500, -1636.000},
                    {690.750, -1640.750},
                    {685.750, -1643.250},
                    {680.000, -1643.500},
                    {675.250, -1645.500},
                    {666.000, -1650.750},
                    {652.750, -1658.500},
                    {642.000, -1665.250},
                    {636.750, -1667.750},
                    {635.000, -1667.250},
                    {633.250, -1665.750},
                    {631.167, -1663.000},
                    {629.333, -1660.167},
                    {627.333, -1656.417},
                    {624.500, -1651.000},
                    {622.167, -1642.000},
                    {598.500, -1568.625},
                    {591.875, -1548.250},
                    {588.625, -1532.875},
                    {587.500, -1522.875},
                    {588.000, -1498.000},
                    {588.250, -1480.750},
                    {593.500, -1440.250},
                    {597.500, -1416.000},
                    {601.500, -1382.500},
                    {604.250, -1356.750},
                    {604.667, -1341.833},
                    {603.833, -1328.667},
                    {603.500, -1311.500},
                    {609.667, -1328.833},
                    {618.667, -1346.833},
                    {626.167, -1365.000},
                    {632.833, -1382.667},
                    {650.250, -1410.000},
                    {662.250, -1430.250},
                    {671.500, -1446.500},
                    {677.750, -1458.000},
                    {683.250, -1469.000},
                    {689.250, -1478.750},
                    {686.000, -1468.750},
                    {684.250, -1458.000},
                    {681.500, -1445.000},
                    {676.000, -1425.500},
                    {673.750, -1414.500},
                    {669.125, -1402.375},
                    {664.500, -1391.250},
                    {658.750, -1377.000},
                    {655.000, -1366.750},
                    {648.750, -1342.000},
                    {642.250, -1322.125},
                    {639.500, -1312.500},
                    {638.500, -1302.375},
                    {637.125, -1289.375},
                    {635.000, -1276.500},
                    {633.875, -1267.625},
                    {630.000, -1252.500},
                    {629.000, -1247.667},
                    {625.833, -1242.833},
                    {620.667, -1234.667},
                    {615.667, -1227.333},
                    {611.500, -1220.500},
                    {608.833, -1213.667},
                    {608.000, -1209.500},
                    {608.167, -1206.833},
                    {609.833, -1206.833},
                    {612.000, -1209.333},
                    {621.667, -1221.000},
                    {631.667, -1232.167},
                    {636.000, -1236.500},
                    {666.750, -1233.250},
                    {670.667, -1249.667},
                    {674.667, -1262.333},
                    {685.333, -1293.000},
                    {700.333, -1330.000},
                    {715.000, -1355.750},
                    {736.667, -1385.667},
                    {753.167, -1411.500},
                    {760.667, -1431.333},
                    {763.000, -1440.167},
                    {765.667, -1445.500},
                    {773.500, -1464.833},
                    {777.500, -1472.500},
                    {784.333, -1484.833},
                    {799.500, -1500.667},
                    {812.167, -1510.833},
                    {829.667, -1523.667},
                    {847.875, -1538.375},
                    {863.375, -1552.000},
                    {868.875, -1557.625},
                    {872.500, -1563.000},
                    {875.375, -1567.750},
                    {878.250, -1573.125},
                    {879.375, -1577.000},
                    {880.625, -1583.250}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(5);
            glBegin(GL_LINE_LOOP);
            glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 253, 231, 185);
        }
        //129
        {
            double vertices[][2] = {
                    { 877.750, -1567.875 },
                    { 880.500, -1573.750 },
                    { 883.125, -1580.250 },
                    { 884.250, -1587.000 },
                    { 884.375, -1594.750 },
                    { 882.750, -1603.875 },
                    { 896.250, -1592.250 },
                    { 905.250, -1581.875 },
                    { 912.875, -1570.750 },
                    { 922.000, -1550.750 },
                    { 931.500, -1527.750 },
                    { 943.250, -1503.750 },
                    { 949.750, -1484.000 },
                    { 954.500, -1472.500 },
                    { 957.750, -1460.083 },
                    { 959.333, -1452.000 },
                    { 961.583, -1441.083 },
                    { 958.083, -1452.417 },
                    { 955.333, -1465.833 },
                    { 951.250, -1475.667 },
                    { 947.500, -1481.583 },
                    { 941.250, -1489.125 },
                    { 932.000, -1501.125 },
                    { 927.250, -1506.500 },
                    { 924.375, -1510.625 },
                    { 918.125, -1519.375 },
                    { 910.125, -1530.000 },
                    { 901.875, -1539.250 },
                    { 892.000, -1549.875 },
                    { 881.500, -1561.875 },
                    { 877.000, -1567.250 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 108, 57, 34,0.4,true,108, 57, 34,0.7);
        }

        //elSelection eltany men elymeen (3ala elkom)
        {
            double vertices[][2] = {
                    {666.750, -1233.250},
                    {636.167, -1236.500},
                    {635.833, -1232.667},
                    {635.167, -1227.917},
                    {633.583, -1220.333},
                    {631.000, -1214.750},
                    {621.125, -1194.750},
                    {618.250, -1189.750},
                    {615.625, -1185.125},
                    {612.750, -1181.375},
                    {609.750, -1179.125},
                    {605.625, -1177.375},
                    {601.875, -1176.750},
                    {599.250, -1176.625},
                    {595.750, -1176.750},
                    {594.000, -1177.250},
                    {595.375, -1174.250},
                    {597.750, -1171.375},
                    {598.750, -1170.875},
                    {619.750, -1170.875},
                    {629.875, -1172.375},
                    {639.125, -1174.625},
                    {647.333, -1177.667},
                    {656.688, -1182.500},
                    {675.125, -1195.062},
                    {679.000, -1197.875},
                    {682.750, -1200.438},
                    {688.000, -1204.562},
                    {691.500, -1207.562},
                    {700.000, -1214.750},
                    {706.750, -1221.375},
                    {711.750, -1228.125},
                    {716.375, -1234.000},
                    {719.625, -1239.375},
                    {722.250, -1244.125},
                    {724.875, -1249.250},
                    {728.750, -1256.875},
                    {733.750, -1266.875},
                    {740.000, -1283.125},
                    {742.375, -1293.125},
                    {744.000, -1297.500},
                    {746.000, -1301.833},
                    {748.167, -1308.333},
                    {750.500, -1316.167},
                    {753.000, -1323.833},
                    {755.167, -1329.833},
                    {758.500, -1340.500},
                    {761.167, -1348.333},
                    {762.833, -1354.833},
                    {763.500, -1358.167},
                    {763.812, -1363.250},
                    {763.875, -1368.375},
                    {763.688, -1374.438},
                    {762.625, -1377.562},
                    {758.167, -1391.750},
                    {756.438, -1397.312},
                    {755.438, -1400.438},
                    {754.750, -1404.250},
                    {754.312, -1408.500},
                    {754.625, -1411.375},
                    {752.625, -1406.500},
                    {752.062, -1403.875},
                    {752.000, -1398.500},
                    {752.375, -1364.125},
                    {752.375, -1363.375},
                    {752.000, -1360.667},
                    {751.500, -1358.312},
                    {750.750, -1356.281},
                    {749.750, -1353.875},
                    {747.875, -1349.625},
                    {718.750, -1307.750},
                    {698.375, -1277.250},
                    {690.875, -1266.500},
                    {686.250, -1259.500},
                    {681.000, -1252.000},
                    {674.625, -1242.875}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(6);
            glBegin(GL_LINE_LOOP);
            glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 253, 231, 185);
        }
        //elSelection elawal men el4emal (3ala elketf)
        {
            double vertices[][2]={
                    {661 , -1182.5},
                    {657.375 , -1173.5},
                    {655.625 , -1169.62},
                    {651.625 , -1163.25},
                    {645.5 , -1155.62},
                    {639.125 , -1150.38},
                    {635 , -1147.38},
                    {630.5 , -1144.62},
                    {627 , -1142.88},
                    {623.25 , -1141.12},
                    {619.5 , -1139.38},
                    {615.875 , -1138.38},
                    {614.875 , -1137.75},
                    {614.375 , -1136.75},
                    {615.5 , -1135.12},
                    {620.125 , -1131},
                    {625.75 , -1126.25},
                    {632.875 , -1122.38},
                    {644.5 , -1116.12},
                    {650.25 , -1112.5},
                    {658.75 , -1110.62},
                    {663.5 , -1109.75},
                    {679.25 , -1109.5},
                    {681 , -1108.38},
                    {681.75 , -1106.88},
                    {682.25 , -1105.19},
                    {682.188 , -1104.31},
                    {681.25 , -1102.88},
                    {676.5 , -1097.94},
                    {677.188 , -1096.56},
                    {678.625 , -1096.12},
                    {681.75 , -1095.5},
                    {697.167 , -1092.42},
                    {703.083 , -1092.33},
                    {706.333 , -1090.83},
                    {711.5 , -1087.33},
                    {716.833 , -1080.83},
                    {722.25 , -1078},
                    {732 , -1075.5},
                    {742.5 , -1073.25},
                    {753.25 , -1073},
                    {757.5 , -1084.25},
                    {762 , -1090.25},
                    {768.75 , -1096.75},
                    {777.25 , -1102.75},
                    {785.5 , -1109.25},
                    {791.25 , -1113.5},
                    {797.25 , -1117.25},
                    {800.5 , -1119.5},
                    {797 , -1234.25},
                    {795.375 , -1238.62},
                    {793.375 , -1240.12},
                    {792.25 , -1240.5},
                    {789.5 , -1241},
                    {804.25 , -1272.25},
                    {832.25 , -1271.5},
                    {832 , -1313.25},
                    {829 , -1330.25},
                    {826.125 , -1343.62},
                    {819.375 , -1361.5},
                    {818.125 , -1364.5},
                    {816.875 , -1368.44},
                    {816.25 , -1371.06},
                    {816.125 , -1373.44},
                    {816.562 , -1375.12},
                    {817.75 , -1376.5},
                    {818.125 , -1378.12},
                    {818.125 , -1383.5},
                    {803.25 , -1407.5},
                    {799.125 , -1413.5},
                    {787.625 , -1427.5},
                    {778.917 , -1436.42},
                    {771.167 , -1444.92},
                    {769.167 , -1447.5},
                    {768.417 , -1446.83},
                    {762.5 , -1431.12},
                    {760.75 , -1426.5},
                    {758.25 , -1419.75},
                    {756.5 , -1414.75},
                    {756.375 , -1413.5},
                    {756.625 , -1412.12},
                    {758.25 , -1405.38},
                    {760 , -1398.62},
                    {761.5 , -1392.12},
                    {762.75 , -1386.38},
                    {765 , -1379.25},
                    {766.125 , -1374.5},
                    {767.25 , -1369.12},
                    {767.375 , -1364.12},
                    {766.875 , -1360.88},
                    {765.875 , -1355.12},
                    {763.375 , -1345.88},
                    {759 , -1334},
                    {756.5 , -1327},
                    {756.25 , -1323.75},
                    {759 , -1320},
                    {763.75 , -1315.5},
                    {767.5 , -1309.5},
                    {769 , -1299.67},
                    {769.833 , -1295.83},
                    {771.5 , -1289.67},
                    {773 , -1284.33},
                    {774 , -1278.17},
                    {776.167 , -1269.83},
                    {778 , -1263},
                    {778.333 , -1258.83},
                    {778.667 , -1254},
                    {778.167 , -1249.67},
                    {777.667 , -1248},
                    {776.833 , -1247},
                    {774.333 , -1249.33},
                    {769.5 , -1255.83},
                    {764.667 , -1263.33},
                    {759.667 , -1270.33},
                    {757.062 , -1275.44},
                    {755.75 , -1277.81},
                    {754.188 , -1281.38},
                    {753.938 , -1283.44},
                    {746.125 , -1276.25},
                    {745.188 , -1261.56},
                    {749.875 , -1255.12},
                    {753.5 , -1250.88},
                    {757.25 , -1245},
                    {759.875 , -1239.12},
                    {762 , -1232.88},
                    {761.75 , -1219.19},
                    {760.562 , -1214.06},
                    {758.75 , -1208.69},
                    {754.375 , -1195.75},
                    {750.75 , -1186.62},
                    {748.375 , -1181.81},
                    {746.312 , -1178.5},
                    {743.938 , -1174.94},
                    {742 , -1172.69},
                    {742.062 , -1195.75},
                    {743.125 , -1216.62},
                    {742.375 , -1270},
                    {741.875 , -1280.5},
                    {741.875 , -1281.62},
                    {740.625 , -1277.75},
                    {739.625 , -1274.12},
                    {738.375 , -1271.25},
                    {736.375 , -1266.88},
                    {734.375 , -1263},
                    {733.375 , -1261.12},
                    {731.5 , -1235},
                    {730.833 , -1224.5},
                    {728.833 , -1206.33},
                    {724.333 , -1183},
                    {721 , -1169},
                    {715.25 , -1148},
                    {711 , -1138.5},
                    {705.5 , -1129},
                    {700.5 , -1121.25},
                    {696.688 , -1117.25},
                    {694.062 , -1115.25},
                    {691.875 , -1114.25},
                    {691 , -1117.38},
                    {690.812 , -1126.25},
                    {691.5 , -1139},
                    {693 , -1151.62},
                    {695.375 , -1163.5},
                    {697.875 , -1171.88},
                    {699.625 , -1176.75},
                    {701 , -1179.62},
                    {703.625 , -1185.75},
                    {706.5 , -1190.62},
                    {710 , -1196.12},
                    {712.5 , -1204.25},
                    {717.25 , -1222.12},
                    {719.125 , -1230.88},
                    {720.562 , -1235.81},
                    {724.062 , -1241.5},
                    {714.625 , -1227.81},
                    {707.438 , -1218.19},
                    {700.562 , -1210.81},
                    {695.375 , -1206.12},
                    {686 , -1198.62},
                    {676.938 , -1192.06},
                    {668.75 , -1186.5}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(6);
            glBegin(GL_LINE_LOOP);
            glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 253, 231, 185);
        }
        //elSelection eltany men elymeen 3ala (elChest)
        {
            double vertices[][2]={
                    {834.667 , -1120},
                    {856.667 , -1254.33},
                    {854.333 , -1274.33},
                    {850.5 , -1288.5},
                    {847.25 , -1304.75},
                    {842.875 , -1325.88},
                    {840.5 , -1341.88},
                    {838.75 , -1352.62},
                    {837.625 , -1366.12},
                    {837.375 , -1372.12},
                    {845.042 , -1372.12},
                    {848.708 , -1372.25},
                    {851.875 , -1373.42},
                    {856.417 , -1376},
                    {859.083 , -1378.58},
                    {860.667 , -1381.08},
                    {861.417 , -1383.25},
                    {861.833 , -1385.83},
                    {861.75 , -1388.25},
                    {861.5 , -1391},
                    {861 , -1395.75},
                    {859.667 , -1399.67},
                    {855.625 , -1408.56},
                    {850.875 , -1419.06},
                    {846.5 , -1427.81},
                    {842.5 , -1436.5},
                    {830.188 , -1462.19},
                    {828.312 , -1465.75},
                    {824.125 , -1472.5},
                    {807.75 , -1499.17},
                    {807.667 , -1500.5},
                    {809.333 , -1499.75},
                    {827.5 , -1471.92},
                    {838.25 , -1456.88},
                    {841.375 , -1453},
                    {847.375 , -1445.5},
                    {852.625 , -1439.62},
                    {858.375 , -1434.25},
                    {862.75 , -1430},
                    {868.5 , -1425.5},
                    {874.625 , -1421.88},
                    {878.25 , -1420.12},
                    {882.875 , -1419.75},
                    {885.125 , -1420.88},
                    {886.875 , -1423.38},
                    {887.375 , -1428.62},
                    {886.375 , -1438},
                    {881.375 , -1450.62},
                    {873.875 , -1463.75},
                    {871.625 , -1469},
                    {871 , -1471.75},
                    {871.5 , -1474.75},
                    {873.125 , -1475.25},
                    {877 , -1474.62},
                    {881.875 , -1472.5},
                    {898.167 , -1463.08},
                    {918.75 , -1448.17},
                    {932.083 , -1437.92},
                    {940.583 , -1430.42},
                    {948.25 , -1423.33},
                    {953.583 , -1416.67},
                    {956.583 , -1412},
                    {957.5 , -1408.33},
                    {957.833 , -1404.33},
                    {959.375 , -1408.12},
                    {960 , -1415.38},
                    {960.833 , -1423.92},
                    {960.917 , -1433.42},
                    {960.375 , -1441.88},
                    {963 , -1434.5},
                    {965.625 , -1426},
                    {967.375 , -1415.75},
                    {968.75 , -1406.5},
                    {969.75 , -1398.38},
                    {970 , -1389.88},
                    {970 , -1383.88},
                    {969.75 , -1379},
                    {972.5 , -1397.62},
                    {974.25 , -1404.38},
                    {978.5 , -1415.25},
                    {983.625 , -1425.75},
                    {986.875 , -1435.12},
                    {990.125 , -1447.38},
                    {991.375 , -1453.88},
                    {992.625 , -1465.25},
                    {993.5 , -1475.88},
                    {993.25 , -1485.12},
                    {992.625 , -1492.38},
                    {994.875 , -1485.12},
                    {997.625 , -1476.12},
                    {1000.25 , -1464.38},
                    {1000.88 , -1460.62},
                    {1002.75 , -1453.5},
                    {1005.75 , -1444.12},
                    {1006.75 , -1439.38},
                    {1007.88 , -1430.25},
                    {1010.33 , -1408.83},
                    {1011.17 , -1388.83},
                    {1011.67 , -1373},
                    {1010.33 , -1364.33},
                    {1006.83 , -1354.83},
                    {1003.19 , -1347.19},
                    {1002.12 , -1345.38},
                    {1004 , -1356.88},
                    {1004.88 , -1366},
                    {1006.25 , -1379.25},
                    {1006.88 , -1384.5},
                    {1004.75 , -1374.88},
                    {1002.62 , -1363.75},
                    {1001.75 , -1357.75},
                    {1000.88 , -1353},
                    {998.375 , -1340.88},
                    {996 , -1332.25},
                    {991.167 , -1319.83},
                    {984.667 , -1305.67},
                    {977.833 , -1290.67},
                    {970.833 , -1277.5},
                    {964 , -1267.67},
                    {957.667 , -1257.67},
                    {947.25 , -1245.08},
                    {936.417 , -1231.5},
                    {927.167 , -1221.67},
                    {921.417 , -1216.08},
                    {914.75 , -1210.75},
                    {912.833 , -1209.17},
                    {912.75 , -1204.92},
                    {912 , -1195.58},
                    {910.875 , -1186.31},
                    {909.75 , -1182.12},
                    {909.125 , -1179.06},
                    {907.688 , -1175.94},
                    {906 , -1173.69},
                    {903.938 , -1172.12},
                    {893.562 , -1165.69},
                    {894.125 , -1168.94},
                    {897.938 , -1174.31},
                    {901.938 , -1179.19},
                    {905.812 , -1184.12},
                    {909.562 , -1190.69},
                    {911.5 , -1195.44},
                    {902.188 , -1182.06},
                    {899.438 , -1178.5},
                    {897 , -1176.44},
                    {897.125 , -1177.56},
                    {897.812 , -1179.44},
                    {902 , -1184.38},
                    {902.625 , -1185.88},
                    {903.125 , -1187.81},
                    {901 , -1186.56},
                    {867 , -1141.88},
                    {862.625 , -1136.5}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 253, 231, 185);
        }
        //eline elly fe light elKom men 3and elDera3
        {
            double vertices[][2] = {
                    { 909.125, -1696.375 },
                    { 918.750, -1696.750 },
                    { 925.000, -1698.250 },
                    { 933.875, -1700.500 },
                    { 941.000, -1701.625 },
                    { 947.125, -1702.750 },
                    { 943.875, -1706.500 },
                    { 934.625, -1704.250 },
                    { 928.625, -1703.125 },
                    { 916.500, -1700.000 },
                    { 911.000, -1698.375 },
                    { 908.000, -1697.500 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 222, 160, 102);
        }
        //elKom men 3and elDera3
        {
            double vertices[][2] = {
                    {910.375, -1697.562},
                    {909.562, -1696.812},
                    {905.562, -1696.625},
                    {897.688, -1696.500},
                    {889.312, -1699.125},
                    {883.500, -1701.438},
                    {877.250, -1704.438},
                    {873.625, -1705.875},
                    {869.250, -1706.750},
                    {860.938, -1707.750},
                    {855.812, -1708.062},
                    {850.438, -1708.562},
                    {842.688, -1710.938},
                    {833.562, -1714.562},
                    {826.750, -1717.500},
                    {813.667, -1722.833},
                    {810.417, -1724.750},
                    {808.417, -1726.333},
                    {807.667, -1727.167},
                    {813.250, -1729.250},
                    {820.167, -1730.417},
                    {828.083, -1731.833},
                    {837.750, -1733.083},
                    {846.667, -1733.167},
                    {855.167, -1733.667},
                    {861.917, -1734.833},
                    {866.750, -1737.083},
                    {870.000, -1740.000},
                    {874.417, -1744.750},
                    {877.917, -1749.583},
                    {878.667, -1752.000},
                    {878.333, -1756.250},
                    {876.000, -1760.917},
                    {866.667, -1776.583},
                    {862.083, -1783.833},
                    {854.917, -1796.500},
                    {850.250, -1806.917},
                    {845.167, -1817.667},
                    {839.000, -1834.875},
                    {837.250, -1843.875},
                    {835.562, -1851.500},
                    {835.438, -1855.062},
                    {835.500, -1856.688},
                    {836.062, -1857.375},
                    {837.188, -1857.625},
                    {840.312, -1857.812},
                    {846.812, -1857.250},
                    {857.938, -1854.188},
                    {891.667, -1840.667},
                    {918.333, -1827.833},
                    {943.833, -1812.333},
                    {989.000, -1782.000},
                    {1021.500, -1761.250},
                    {1055.750, -1740.250},
                    {1067.500, -1733.500},
                    {1075.917, -1728.833},
                    {1077.000, -1728.667},
                    {1078.083, -1728.833},
                    {1078.250, -1729.750},
                    {1077.250, -1731.083},
                    {1059.000, -1742.000},
                    {1034.167, -1757.833},
                    {1016.667, -1768.500},
                    {999.833, -1780.167},
                    {976.917, -1798.417},
                    {972.500, -1802.000},
                    {968.667, -1805.667},
                    {960.667, -1812.500},
                    {953.250, -1820.000},
                    {949.417, -1823.250},
                    {945.667, -1827.167},
                    {942.250, -1830.250},
                    {937.500, -1833.917},
                    {937.500, -1834.500},
                    {950.250, -1831.083},
                    {964.917, -1827.167},
                    {985.000, -1823.000},
                    {1005.917, -1819.083},
                    {1011.750, -1818.917},
                    {1027.750, -1818.250},
                    {1043.000, -1818.750},
                    {1059.750, -1819.250},
                    {1067.000, -1819.250},
                    {1074.000, -1820.250},
                    {1083.500, -1822.750},
                    {1091.500, -1824.250},
                    {1104.000, -1827.000},
                    {1113.500, -1828.500},
                    {1124.250, -1829.000},
                    {1132.500, -1828.833},
                    {1133.333, -1827.667},
                    {1133.500, -1820.833},
                    {1133.500, -1815.333},
                    {1133.667, -1809.833},
                    {1134.833, -1798.333},
                    {1136.000, -1789.667},
                    {1137.500, -1777.667},
                    {1139.500, -1765.875},
                    {1140.000, -1757.250},
                    {1139.375, -1750.500},
                    {1137.500, -1745.750},
                    {1133.250, -1737.625},
                    {1128.000, -1729.125},
                    {1121.312, -1720.562},
                    {1114.812, -1714.812},
                    {1111.250, -1712.500},
                    {1109.312, -1712.062},
                    {1106.562, -1711.688},
                    {1101.062, -1711.688},
                    {1096.875, -1712.062},
                    {1091.750, -1714.000},
                    {1086.000, -1715.667},
                    {1077.833, -1717.250},
                    {1072.750, -1718.000},
                    {1054.750, -1717.833},
                    {1050.000, -1717.250},
                    {1044.500, -1715.750},
                    {1038.000, -1713.583},
                    {1034.167, -1711.583},
                    {1028.583, -1708.083},
                    {1023.750, -1704.750},
                    {1019.583, -1701.083},
                    {1016.250, -1698.250},
                    {1013.667, -1697.833},
                    {1009.583, -1697.917},
                    {1005.333, -1699.667},
                    {999.500, -1702.833},
                    {993.583, -1706.000},
                    {990.333, -1708.583},
                    {987.667, -1710.000},
                    {986.417, -1710.833},
                    {984.250, -1710.500},
                    {977.833, -1708.583},
                    {971.750, -1707.083},
                    {962.583, -1705.083},
                    {955.917, -1703.500},
                    {949.083, -1703.167},
                    {938.958, -1703.000},
                    {936.000, -1704.208},
                    {933.125, -1705.792},
                    {935.375, -1705.917},
                    {939.000, -1706.125},
                    {943.792, -1707.083},
                    {948.750, -1709.000},
                    {952.542, -1711.125},
                    {959.417, -1715.375},
                    {961.833, -1717.125},
                    {964.833, -1719.250},
                    {968.125, -1721.833},
                    {969.500, -1723.750},
                    {969.875, -1725.125},
                    {927.583, -1724.750},
                    {925.167, -1723.667},
                    {921.417, -1722.000},
                    {916.417, -1719.833},
                    {913.667, -1718.750},
                    {908.833, -1718.083},
                    {895.375, -1717.875},
                    {891.438, -1716.812},
                    {887.938, -1715.375},
                    {883.375, -1712.938},
                    {881.438, -1711.500},
                    {880.062, -1710.812},
                    {881.625, -1709.562},
                    {888.562, -1707.625},
                    {896.188, -1705.062},
                    {904.688, -1701.625},
                    {909.562, -1699.312},
                    {910.281, -1698.344}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 253, 231, 185);
        }
        //elCover el4affaf elle fe nos elLight
        {
            //elgoz2 el4emal
            {
                double vertices[][2] = {
                        { 929.375, -1705.875 },
                        { 913.125, -1699.750 },
                        { 883.000, -1710.625 },
                        { 893.000, -1715.000 },
                        { 903.375, -1716.375 },
                        { 912.750, -1715.500 },
                        { 919.125, -1719.625 },
                        { 928.250, -1722.375 },
                        { 954.125, -1723.875 },
                        { 966.167, -1724.167 },
                        { 967.083, -1723.750 },
                        { 959.000, -1717.083 },
                        { 949.417, -1711.583 },
                        { 940.500, -1709.917 },
                        { 934.833, -1710.000 },
                        { 932.333, -1709.083 },
                        { 930.333, -1707.417 }
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                drawConcavePolygon(vertices, size, 180, 100, 49);
            }
            //elgoz2 elymeen men fou2
            {
                double vertices[][2] = {
                        { 1054.667, -1772.167 },
                        { 1071.667, -1765.667 },
                        { 1100.833, -1754.500 },
                        { 1118.000, -1748.000 },
                        { 1123.500, -1746.333 },
                        { 1127.000, -1750.000 },
                        { 1130.167, -1756.167 },
                        { 1129.667, -1758.167 },
                        { 1127.000, -1759.667 },
                        { 1122.167, -1760.833 },
                        { 1118.500, -1760.833 },
                        { 1112.167, -1761.500 },
                        { 1106.167, -1763.167 },
                        { 1099.000, -1765.000 },
                        { 1094.667, -1766.167 },
                        { 1090.500, -1767.833 },
                        { 1085.833, -1770.167 },
                        { 1082.000, -1771.167 },
                        { 1077.667, -1772.167 },
                        { 1073.333, -1772.333 }
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                drawConcavePolygon(vertices, size, 180, 100, 49);
                glLineWidth(3);
                glBegin(GL_LINE_LOOP);
                glColor4f(253/255.0f,231/255.0f,185/255.0f,0.1);
                for (int i = 0; i <size ; ++i)
                    glVertex2dv(vertices[i]);
                glEnd();
            }
            //elgoz2 elymeen men ta7t
            {
                double vertices[][2] = {
                        { 1032.500, -1796.167 },
                        { 1035.667, -1795.167 },
                        { 1060.333, -1795.667 },
                        { 1070.167, -1796.500 },
                        { 1085.333, -1798.667 },
                        { 1098.500, -1800.000 },
                        { 1107.667, -1801.000 },
                        { 1114.667, -1800.333 },
                        { 1122.167, -1800.500 },
                        { 1125.167, -1802.000 },
                        { 1126.500, -1807.000 },
                        { 1124.167, -1809.000 },
                        { 1114.167, -1810.500 },
                        { 1109.167, -1811.833 },
                        { 1103.667, -1813.333 },
                        { 1093.500, -1813.500 },
                        { 1087.333, -1813.000 },
                        { 1080.167, -1812.167 },
                        { 1068.833, -1809.500 },
                        { 1056.333, -1806.667 },
                        { 1047.167, -1803.500 },
                        { 1039.167, -1800.833 },
                        { 1034.833, -1798.167 }
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                drawConcavePolygon(vertices, size, 180, 100, 49);
                glLineWidth(3);
                glBegin(GL_LINE_LOOP);
                glColor4f(253/255.0f,231/255.0f,185/255.0f,0.1);
                for (int i = 0; i <size ; ++i)
                    glVertex2dv(vertices[i]);
                glEnd();
            }

        }
        //elLine light elly 2abl el3 Lights elly 3and elJewel
        {
            double vertices[][2]={
                    {800.167 , -1117.5},
                    {799.5 , -1115.17},
                    {764.5 , -1087.25},
                    {757.667 , -1081.67},
                    {756.5 , -1081.17},
                    {757.333 , -1084.08},
                    {762.667 , -1091.25}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 239, 202, 117,1,true,252,231,168);
        }
        //elLight elly 3and elJewel (L1)
        {
            double vertices[][2]={
                    {793.75 , -1098.25},
                    {789 , -1093.5},
                    {784.5 , -1090},
                    {777.5 , -1084.25},
                    {770.25 , -1079},
                    {767.5 , -1076.25},
                    {763.5 , -1071.75},
                    {761.25 , -1067.5},
                    {765.25 , -1068.75},
                    {771.25 , -1071.75},
                    {776 , -1074},
                    {780.5 , -1077},
                    {782 , -1077},
                    {779.5 , -1074.25},
                    {775.5 , -1070.25},
                    {771.25 , -1066.25},
                    {767 , -1061.5},
                    {762.75 , -1056},
                    {759.25 , -1049},
                    {763 , -1052},
                    {769.25 , -1056.75},
                    {776.5 , -1061.5},
                    {787.5 , -1069.25},
                    {787.5 , -1077},
                    {788.75 , -1085.5},
                    {790.75 , -1092.5}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 248, 226, 162,1,true,248, 220, 147);
        }
        //elLight elly 3and elJewel (L2)
        {
            double vertices[][2]={
                    {757 , -1043.62},
                    {757.5 , -1045.12},
                    {787.125 , -1066.88},
                    {787.375 , -1054},
                    {780.125 , -1045},
                    {773.5 , -1038.38},
                    {765.5 , -1030.38}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 248, 228, 169,1,true,248, 227, 162);
        }
        //elLight elly 3and elJewel (L3)
        {
            double vertices[][2]={
                    {766.312 , -1027.88},
                    {767.75 , -1025.5},
                    {768.875 , -1021.81},
                    {769.688 , -1017.69},
                    {770.562 , -1012.5},
                    {771.438 , -1005.19},
                    {771.688 , -1000.5},
                    {771.438 , -996.938},
                    {775 , -1003.5},
                    {779.25 , -1011.62},
                    {782.625 , -1019.19},
                    {786 , -1027.56},
                    {788.562 , -1035.69},
                    {789.25 , -1042.25},
                    {789.438 , -1051.19},
                    {789.438 , -1054.62},
                    {783.812 , -1047.25},
                    {779.125 , -1041.62},
                    {775 , -1037.19},
                    {771.938 , -1033.75},
                    {768.438 , -1030.19}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 250, 229, 170,1,true,255, 237, 169);
        }
        //elLight elly 3and elJewel men elYmeen
        {
            {
                double vertices[][2]={
                        {791.438 , -1023.69},
                        {790.875 , -1018.94},
                        {790 , -1013.69},
                        {788.938 , -1010.88},
                        {787.188 , -1006.44},
                        {785.25 , -1003.81},
                        {782.562 , -1000.75},
                        {781.688 , -998.75},
                        {781.812 , -997.375},
                        {782.5 , -995.938},
                        {786 , -993},
                        {786.875 , -993.5},
                        {789.688 , -997.188},
                        {791.312 , -999.938},
                        {792.5 , -1002.88},
                        {793.062 , -1006},
                        {793 , -1015.06},
                        {792.562 , -1021}
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                glLineWidth(3);
                glBegin(GL_LINE_LOOP);
                glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
                for (int i = 0; i <size ; ++i)
                    glVertex2dv(vertices[i]);
                glEnd();
                drawConcavePolygon(vertices, size, 251, 222, 144,0.4,true,251, 222, 144);
            }
            {
                double vertices[][2]={
                        {823.833 , -1073},
                        {817.25 , -1066.92},
                        {814.083 , -1063.33},
                        {810.25 , -1057.08},
                        {807.417 , -1052.83},
                        {804.833 , -1047.08},
                        {804.333 , -1045.08},
                        {802.167 , -1049.17},
                        {793.5 , -1056.75},
                        {794.25 , -1014.58},
                        {795.333 , -1007.25},
                        {806.75 , -1039.81},
                        {811.583 , -1051.42},
                        {816.25 , -1060.67}
                };
                int size = sizeof(vertices) / sizeof(vertices[0]);
                glLineWidth(2);
                glBegin(GL_LINE_LOOP);
                glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
                for (int i = 0; i <size ; ++i)
                    glVertex2dv(vertices[i]);
                glEnd();
                drawConcavePolygon(vertices, size, 245, 187, 113,1,true,251, 226, 168);
            }
        }
        //elLight elly 3and el3asaya beta3 el4amseyya
        {
            double vertices[][2]={
                    {834.667 , -1065.88},
                    {829.5 , -1053.67},
                    {825.25 , -1045.75},
                    {822.125 , -1039.88},
                    {812.875 , -1026.62},
                    {804.375 , -1014.88},
                    {800.25 , -1008.75},
                    {795.5 , -1003},
                    {792.125 , -999.625},
                    {794.25 , -1005.38},
                    {798.375 , -1010.75},
                    {804.75 , -1019.75},
                    {813.625 , -1032.12},
                    {821.375 , -1044},
                    {824.125 , -1049},
                    {828.5 , -1056.08},
                    {833.167 , -1063.75}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(121/55.0f,62/255.0f,30/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 202, 133, 68,1,true,233,181,107);
        }
        //elLight elly ta7toh
        {
            double vertices[][2]={
                    {850.917 , -1099.83},
                    {846.5 , -1091.5},
                    {841.417 , -1083.5},
                    {831 , -1067.42},
                    {823.083 , -1055.42},
                    {815.5 , -1042.42},
                    {811.25 , -1036.17},
                    {808.25 , -1031.17},
                    {805.25 , -1024.75},
                    {798.917 , -1015.17},
                    {803.75 , -1028.17},
                    {810.25 , -1044.92},
                    {814.083 , -1054.67},
                    {819.583 , -1064.25},
                    {824 , -1071.5},
                    {827.25 , -1075.83},
                    {831 , -1079.67},
                    {837.917 , -1087.08},
                    {845.25 , -1093.92}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(166/55.0f,93/255.0f,44/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 238, 174, 101,1,true,245,180,97);
        }
    }
    //elBase elDark ta7t elJewel men elymeen (eltaraf elly nazel men elJewel elawwal men elymeen)
    {
        //elbase
        {
            double vertices[][2] = {
                    {842.000, -1110.167},
                    {851.167, -1119.333},
                    {866.500, -1138.333},
                    {881.167, -1160.167},
                    {889.750, -1184.000},
                    {894.750, -1201.250},
                    {896.250, -1214.750},
                    {897.750, -1230.500},
                    {903.167, -1253.333},
                    {906.250, -1264.417},
                    {916.000, -1296.375},
                    {918.125, -1300.125},
                    {919.125, -1297.750},
                    {922.500, -1287.000},
                    {925.000, -1276.875},
                    {926.500, -1267.000},
                    {926.875, -1259.125},
                    {925.875, -1253.500},
                    {922.417, -1245.167},
                    {918.333, -1238.000},
                    {912.167, -1228.667},
                    {906.083, -1221.500},
                    {899.333, -1213.417},
                    {896.583, -1211.333},
                    {895.708, -1210.750},
                    {895.333, -1207.292},
                    {898.333, -1209.333},
                    {902.750, -1213.750},
                    {907.833, -1219.875},
                    {917.750, -1232.083},
                    {924.833, -1241.333},
                    {928.167, -1249.083},
                    {931.333, -1259.333},
                    {931.500, -1271.167},
                    {929.667, -1283.917},
                    {927.000, -1294.250},
                    {922.917, -1305.500},
                    {922.917, -1307.333},
                    {923.167, -1309.917},
                    {924.167, -1316.500},
                    {927.333, -1328.750},
                    {930.417, -1338.833},
                    {932.167, -1343.250},
                    {932.250, -1344.167},
                    {922.917, -1344.167},
                    {921.750, -1334.000},
                    {919.833, -1321.500},
                    {917.167, -1310.833},
                    {914.500, -1302.750},
                    {913.625, -1301.750},
                    {913.375, -1301.750},
                    {912.625, -1303.750},
                    {898.375, -1256.625},
                    {891.500, -1236.000}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 181, 114, 54);
            glLineWidth(1);
            glBegin(GL_LINE_LOOP);
            glColor4f(151/255.0f,92/255.0f,46/255.0f,0.5);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
        }
        //elLight elly fou2oh
        {
            double vertices[][2] = {
                    { 913.250, -1303.625 },
                    { 913.500, -1297.000 },
                    { 912.875, -1291.000 },
                    { 909.875, -1282.500 },
                    { 907.500, -1276.125 },
                    { 905.000, -1265.625 },
                    { 903.125, -1255.125 },
                    { 899.000, -1239.125 },
                    { 898.000, -1235.375 },
                    { 897.125, -1230.875 },
                    { 896.000, -1221.375 },
                    { 895.000, -1213.250 },
                    { 895.250, -1207.500 },
                    { 894.250, -1200.750 },
                    { 890.250, -1187.625 },
                    { 886.500, -1178.500 },
                    { 882.625, -1168.750 },
                    { 879.375, -1162.125 },
                    { 879.125, -1160.750 },
                    { 882.375, -1165.500 },
                    { 881.125, -1160.875 },
                    { 866.250, -1141.125 },
                    { 861.250, -1138.375 },
                    { 855.250, -1135.250 },
                    { 851.125, -1132.625 },
                    { 848.375, -1132.250 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 240, 177, 86,0.4,true,240, 177, 86,0.8);
        }
    }
    //elBase elDark ta7t elJewel men elymeen (eltaraf elly nazel men elJewel eltany men elymeen)
    {
        //elbase
        {
            double vertices[][2]={
                    {847.5 , -1164.67},
                    {838.333 , -1138.17},
                    {846.167 , -1121.5},
                    {849.667 , -1129.17},
                    {853 , -1136.12},
                    {857 , -1141.33},
                    {865.833 , -1152},
                    {872.333 , -1162.17},
                    {878 , -1171.62},
                    {884.333 , -1182.33},
                    {888.667 , -1192.17},
                    {890.833 , -1206},
                    {890.625 , -1215.5},
                    {891.5 , -1227.5},
                    {893.25 , -1237.12},
                    {896.333 , -1248},
                    {908.667 , -1286},
                    {912.667 , -1304.33},
                    {912.667 , -1311.83},
                    {910.5 , -1316.83},
                    {907.833 , -1324.83},
                    {905 , -1334.33},
                    {905.833 , -1339.17},
                    {907.5 , -1347.5},
                    {903.333 , -1333},
                    {903 , -1320.33},
                    {901.167 , -1303},
                    {897.5 , -1287},
                    {893.5 , -1267.5},
                    {890.167 , -1250.5},
                    {888 , -1240.5},
                    {885.5 , -1234.62},
                    {881.25 , -1228.88},
                    {876 , -1223},
                    {871.75 , -1217.67},
                    {868.833 , -1213.58},
                    {866.5 , -1209.5},
                    {864.75 , -1207},
                    {862 , -1203.17},
                    {861.25 , -1199.42},
                    {860.917 , -1195}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 144, 84, 32);
        }
        //elLight elly fou2oh
        {
            double vertices[][2] = {
                    { 890.125, -1247.375 },
                    { 912.562, -1311.500 },
                    { 909.750, -1320.250 },
                    { 907.375, -1325.750 },
                    { 905.062, -1334.625 },
                    { 907.583, -1347.750 },
                    { 903.333, -1333.167 },
                    { 903.167, -1320.083 },
                    { 902.583, -1314.500 },
                    { 901.583, -1303.167 },
                    { 900.250, -1297.250 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 191, 127, 63,0.4,true,191, 127, 63);
        }
    }
    //elBase elDark ta7t elJewel men el4emal
    {
        double vertices[][2]={
                {810 , -1121.5},
                {816.5 , -1245.25},
                {861.5 , -1275.75},
                {864.5 , -1241},
                {864.25 , -1207.5},
                {844.5 , -1152},
                {812.5 , -1118.5}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 134,68,21);
    }
    //elLight elly fou2 elBse elDark elly ta7t elJewel
    {
        //elLight elly fe el4emal elle fe elgoz2 elymeen men elfyonka
        {
            double vertices[][2]={
                    {867.333 , -1192.33},
                    {865.167 , -1187.17},
                    {864 , -1182.33},
                    {861.833 , -1175},
                    {859.333 , -1168.83},
                    {857.5 , -1165.33},
                    {854.5 , -1159.5},
                    {852.5 , -1156.33},
                    {851.667 , -1154.5},
                    {850.333 , -1148.33},
                    {856.667 , -1156.67},
                    {862 , -1168.17},
                    {871.667 , -1187.5},
                    {880.833 , -1207.67},
                    {884.667 , -1217.5},
                    {888.167 , -1225.83},
                    {883.333 , -1219.67},
                    {879.5 , -1214},
                    {875.333 , -1207.5},
                    {872.167 , -1202.67},
                    {868.667 , -1196}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(136/55.0f,79/255.0f,33/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 245, 216, 136);
        }
        //elLight elly fe elymeen elle fe elgoz2 elymeen men elfyonka
        {
            double vertices[][2]={
                    {853.188 , -1138.31},
                    {865.5 , -1162.25},
                    {878.125 , -1187.12},
                    {885.125 , -1203},
                    {888.5 , -1211.75},
                    {887.625 , -1194.75},
                    {886.375 , -1190.88},
                    {870.125 , -1161.94},
                    {860.25 , -1146.38}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(136/55.0f,79/255.0f,33/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 245, 216, 136);
        }
        //elLight elle fe elmiddle elle fe elgoz2 el4emal men elfyonka
        {
            double vertices[][2]={
                    {859.125 , -1234.75},
                    {857.5 , -1226.25},
                    {854.75 , -1217.38},
                    {850.125 , -1206},
                    {846.375 , -1197},
                    {843.875 , -1191.12},
                    {840.75 , -1183.88},
                    {837.125 , -1176.12},
                    {833.625 , -1170},
                    {829.25 , -1162.12},
                    {830.5 , -1172.75},
                    {837.125 , -1189},
                    {844.25 , -1203.88},
                    {848 , -1212.5},
                    {851.25 , -1218.62},
                    {853.625 , -1222.88},
                    {855.75 , -1227},
                    {857.875 , -1232}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(136/55.0f,79/255.0f,33/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 244, 185, 100,1,true,246,221,144);
        }
        //elCover (tamweh) elly ganb elLight elKebeer fe el4emal
        {
            double vertices[][2]={
                    {819 , -1167.75},
                    {820.375 , -1183.38},
                    {823 , -1198},
                    {826.5 , -1206.75},
                    {830 , -1212.25},
                    {834.25 , -1218},
                    {838.875 , -1223.25},
                    {845.25 , -1228.75},
                    {840.75 , -1222.88},
                    {839 , -1220.12},
                    {836.5 , -1216.25},
                    {833.25 , -1211.12},
                    {829.5 , -1203},
                    {826.875 , -1196.62},
                    {824.25 , -1187.62},
                    {821.75 , -1178},
                    {820.25 , -1172.38}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(158/55.0f,90/255.0f,42/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 196, 122, 62);
        }
        //elTamweh elfate7 been elTwo lights
        {
            double vertices[][2]={
                    {837 , -1171.17},
                    {847.5 , -1186.58},
                    {849.583 , -1192.42},
                    {853 , -1202.5},
                    {856.667 , -1217.17},
                    {858.5 , -1225.25},
                    {853.083 , -1211.75},
                    {847.667 , -1199.25},
                    {842 , -1183.25},
                    {839.583 , -1176.83}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(133/55.0f,67/255.0f,22/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 171, 106, 46);
        }
    }

    //elLight elly fe el4emal fe tanyet elfeyonka el4emal
    {
        double vertices[][2]={
                {808 , -1118.58},
                {811.167 , -1120.83},
                {818.167 , -1246.5},
                {817.5 , -1246.67},
                {816.167 , -1246.33},
                {815 , -1244.67},
                {813.833 , -1241.83},
                {812.5 , -1236.5},
                {812 , -1232.67},
                {810.5 , -1219.5},
                {809.667 , -1202.67},
                {808.833 , -1189.17},
                {807.75 , -1162.62},
                {808 , -1139.75}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 248, 210, 133,1,true,247,215,134);
    }
    //elLight elly fe el4emal men ta7t fe tanyet elfeyonka el4emal
    {
        double vertices[][2]={
                {822.167 , -1243.92},
                {823.417 , -1232.67},
                {823.667 , -1227.08},
                {824.833 , -1241.42},
                {853.083 , -1262},
                {853.333 , -1264.5},
                {852.5 , -1265.5},
                {848.25 , -1263.83},
                {852.333 , -1267.17},
                {858.917 , -1270.75},
                {861.25 , -1277.25},
                {853.917 , -1272},
                {846.083 , -1265.25},
                {834 , -1255.25},
                {824.167 , -1246.5}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 240, 193, 111);
    }
    //elLight elly fe elymeen men ta7t fe tanyet elfeyonka el4emal
    {
        double vertices[][2]={
                {856.062 , -1271.31},
                {859.938 , -1275.94},
                {861.625 , -1277.38},
                {863 , -1276.19},
                {865.312 , -1271.94},
                {867.125 , -1265.94},
                {867.083 , -1247.83},
                {865.75 , -1238.58},
                {863.917 , -1230.75},
                {862.583 , -1233.75},
                {863.833 , -1243.33},
                {863.083 , -1255.5},
                {860.833 , -1267.83},
                {859.833 , -1271.42},
                {858.406 , -1271.62},
                {856.719 , -1271.16}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 248, 184, 107);
    }
    //elLight elly fe elymeen fe tanyet elfeyonka el4emal
    {
        double vertices[][2]={
                {862.333 , -1233.67},
                {863.25 , -1230.58},
                {862.125 , -1214.62},
                {861.375 , -1202.12},
                {860.833 , -1194.58},
                {858.625 , -1184.75},
                {854.875 , -1176.25},
                {851.125 , -1167.88},
                {849.125 , -1162.75},
                {846.25 , -1155.12},
                {837 , -1149.38},
                {832.5 , -1146.38},
                {829.125 , -1144.25},
                {829.125 , -1148.75},
                {830.375 , -1153.75},
                {833.125 , -1158.88},
                {836 , -1162.75},
                {841 , -1167.5},
                {846.25 , -1170.75},
                {850.875 , -1173.38},
                {853.5 , -1174.62},
                {853.875 , -1175.46},
                {853.458 , -1175.88},
                {852.042 , -1175.79},
                {849.417 , -1174.96},
                {846.417 , -1173.08},
                {842.917 , -1170.71},
                {841.167 , -1168.88},
                {839.917 , -1167.79},
                {841.833 , -1172.96},
                {848 , -1185.83},
                {850.917 , -1194.92},
                {854.25 , -1206},
                {856.5 , -1214.58},
                {859.083 , -1223.75},
                {861.667 , -1231.67}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 251, 231, 162);
    }

    //eline elly ganboh
    {
        double vertices[][2]={
                {813 , -1134.25},
                {812.875 , -1146.75},
                {815.25 , -1170.25},
                {820.5 , -1229.25},
                {821.75 , -1242.75},
                {822.25 , -1244.5},
                {823.25 , -1232.25},
                {823 , -1220.08},
                {822.167 , -1206.83},
                {818.375 , -1176.5},
                {815.375 , -1151.62},
                {814.125 , -1137.12}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 248, 210, 133,0.5,true,240,193,111);
    }

    //elLayer elly ta7t elJewel
    {
        double vertices[][2]={
                {836.375 , -1107.75},
                {839.75 , -1101.88},
                {837.625 , -1093.25},
                {834.875 , -1087.5},
                {829.625 , -1082.12},
                {823.375 , -1076.25},
                {811.5 , -1062.38},
                {808.438 , -1058.06},
                {805.688 , -1053.81},
                {804.562 , -1050.88},
                {793.875 , -1059.12},
                {791.125 , -1061.5},
                {789.875 , -1065.88},
                {789.625 , -1071},
                {789.583 , -1076.83},
                {791 , -1080.67},
                {793.5 , -1086.25},
                {796.5 , -1092.33},
                {799.5 , -1097.75},
                {802.938 , -1104.69},
                {805.125 , -1109.38},
                {807.438 , -1115.25},
                {808.125 , -1118.75},
                {811.312 , -1120.81},
                {810.812 , -1115.5}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 244, 195, 110,0.8,true,248,210,133);
    }


    //134
    {
        glLineWidth(1);
        glColor4f(169/255.0f, 115/255.0f, 68/255.0f, 0.8);
        glBegin(GL_LINE_STRIP);
        glVertex2f(867.667, -1250.333);
        glVertex2f(878.333, -1272.000);
        glVertex2f(888.667, -1295.667);
        glVertex2f(897.000, -1316.333);
        glVertex2f(902.000, -1331.333);
        glVertex2f(906.000, -1343.333);
        glEnd();
    }
    //135
    {
        double vertices[][2] = {
                { 923.188, -1306.438 },
                { 923.625, -1311.312 },
                { 925.188, -1314.188 },
                { 929.562, -1319.062 },
                { 937.750, -1328.375 },
                { 942.125, -1334.125 },
                { 946.125, -1340.125 },
                { 950.000, -1347.250 },
                { 952.125, -1354.250 },
                { 954.000, -1361.000 },
                { 955.625, -1365.375 },
                { 957.375, -1371.250 },
                { 959.125, -1379.125 },
                { 958.875, -1369.250 },
                { 957.250, -1357.875 },
                { 954.250, -1346.875 },
                { 950.500, -1339.250 },
                { 945.500, -1331.875 },
                { 939.250, -1323.750 },
                { 928.500, -1312.375 },
                { 924.500, -1309.000 }
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 190, 129, 69,1,true,187,137,92);
    }
    //136
    {
        glLineWidth(1);
        glColor4f(231/255.0f, 176/255.0f, 121/255.0f, 1);
        glBegin(GL_LINE_STRIP);
        glVertex2f(926.938, -1302.188);
        glVertex2f(933.312, -1309.000);
        glVertex2f(939.000, -1315.938);
        glVertex2f(943.000, -1321.250);
        glVertex2f(945.875, -1326.125);
        glVertex2f(947.812, -1330.250);
        glEnd();
    }
    //137
    {
        glLineWidth(1);
        glColor4f(168/255.0f, 123/255.0f, 85/255.0f, 1);
        glBegin(GL_LINE_STRIP);
        glVertex2f(898.250, -1232.750);
        glVertex2f(908.750, -1245.500);
        glVertex2f(920.250, -1259.250);
        glVertex2f(933.500, -1275.500);
        glVertex2f(943.000, -1287.750);
        glVertex2f(950.250, -1298.500);
        glVertex2f(954.000, -1306.250);
        glVertex2f(958.750, -1319.000);
        glColor4f(168/255.0f, 123/255.0f, 85/255.0f, 0.5);
        glVertex2f(962.750, -1331.250);
        glColor4f(168/255.0f, 123/255.0f, 85/255.0f, 0.1);
        glVertex2f(965.000, -1343.000);
        glEnd();
    }
    //138
    {
        glLineWidth(1);
        glColor4f(176/255.0f, 121/255.0f, 85/255.0f, 1);
        glBegin(GL_LINE_STRIP);
        glVertex2f(922.667, -1240.167);
        glVertex2f(937.000, -1256.167);
        glVertex2f(948.167, -1270.333);
        glVertex2f(954.833, -1279.333);
        glColor4f(176/255.0f, 121/255.0f, 85/255.0f, 0.5);
        glVertex2f(960.667, -1288.000);
        glColor4f(176/255.0f, 121/255.0f, 85/255.0f, 0.1);
        glVertex2f(965.333, -1295.333);
        glEnd();
    }


    //elJewel
    {
        //jewel base
        {
            double vertices[][2]={
                    {819.125 , -1122.83},
                    {814 , -1118.33},
                    {811.375 , -1115},
                    {808.625 , -1109.88},
                    {803 , -1098.75},
                    {799.375 , -1091.88},
                    {794.75 , -1081.38},
                    {793 , -1076.12},
                    {792.667 , -1069.83},
                    {792.917 , -1067.5},
                    {793.833 , -1064.58},
                    {797.917 , -1060.92},
                    {802.5 , -1057.42},
                    {803.333 , -1058.17},
                    {803 , -1059.5},
                    {798.75 , -1062.5},
                    {805.188 , -1064.06},
                    {818.5 , -1078.58},
                    {827.125 , -1089.38},
                    {831.375 , -1133.44},
                    {826.688 , -1129.06},
                    {822.042 , -1125.54}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 128, 73, 15);
        }
        //jewel lower light (ta7t eljewel)
        {
            double vertices[][2]={
                    {850 , -1144.88},
                    {846.062 , -1142.81},
                    {842.083 , -1140},
                    {838.688 , -1136.56},
                    {837.812 , -1134.88},
                    {836.417 , -1107.83},
                    {839.417 , -1101.58},
                    {844.167 , -1119.83},
                    {845.5 , -1125.92},
                    {846.417 , -1131.83},
                    {846.917 , -1136.58},
                    {847.75 , -1140.08},
                    {848.5 , -1142.08}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 201, 168, 61,1,true,244,195,110,0.8);
        }
        //jewel lower light (3ala eljewel)
        {
            double vertices[][2]={
                    {837.125 , -1136.62},
                    {837.938 , -1134.75},
                    {838.125 , -1128.12},
                    {838.062 , -1126.25},
                    {823.312 , -1112.06},
                    {818.062 , -1112.56},
                    {825.812 , -1123.75},
                    {832.438 , -1133.12},
                    {833.5 , -1134.44},
                    {834.5 , -1135.5},
                    {836.25 , -1136.31}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 155, 145, 39,1,true,110,112,29,0.5);
        }

        //jewel base layer1
        {
            double vertices[][2]={
                    {814.833 , -1112.75},
                    {809.083 , -1101.42},
                    {803.833 , -1087.08},
                    {824.583 , -1112}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 115, 79, 17);
        }
        //jewel base layer2
        {
            double vertices[][2]={
                    {814.938 , -1112.75},
                    {820.062 , -1121},
                    {822.938 , -1124.25},
                    {826.5 , -1128.19},
                    {829.938 , -1131.56},
                    {833.25 , -1134.94},
                    {831.188 , -1131.12},
                    {828.688 , -1127.62},
                    {825.688 , -1123.5},
                    {823.188 , -1120.38},
                    {820.125 , -1115.75},
                    {817.812 , -1112.69}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 92, 79, 22);
        }
        //jewel base layer3
        {
            double vertices[][2]={
                    {812.792 , -1101.88},
                    {822.562 , -1114.38},
                    {827.625 , -1120.75},
                    {832.438 , -1124.69},
                    {835.625 , -1126.62},
                    {837.125 , -1127},
                    {838.5 , -1126.06},
                    {838.75 , -1120.69},
                    {837.812 , -1112.94},
                    {835.75 , -1106.06},
                    {832.688 , -1099.81},
                    {829.375 , -1093.31},
                    {825.938 , -1088.44},
                    {819 , -1080.19},
                    {810.75 , -1070.96},
                    {805.75 , -1065.46},
                    {803.417 , -1064.29},
                    {800.708 , -1063.62},
                    {798.25 , -1063.38},
                    {797.292 , -1063.62},
                    {796.042 , -1065.21},
                    {795.75 , -1067.33},
                    {797.083 , -1071},
                    {803.708 , -1087.12}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 88, 94, 21);
        }
        //jewel base layer4
        {
            double vertices[][2]={
                    {817.833 , -1091.58},
                    {815.75 , -1101.58},
                    {820.667 , -1106.92},
                    {826.5 , -1114.17},
                    {831 , -1118.67},
                    {834.083 , -1120.83},
                    {836.417 , -1120.67},
                    {836.75 , -1114.83},
                    {831.917 , -1101.25},
                    {828.25 , -1094.67},
                    {824.417 , -1088.75},
                    {820.167 , -1083.42}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 100, 107, 25,0.1,true,100, 107, 25);
        }
        //jewel base layer5
        {
            double vertices[][2]={
                    {818.833 , -1081.33},
                    {816.583 , -1090.42},
                    {814.25 , -1099.67},
                    {810 , -1094.58},
                    {806.75 , -1090.58},
                    {803.75 , -1086.33},
                    {799.917 , -1077.08},
                    {797.5 , -1070.58},
                    {796.833 , -1067.67},
                    {796.833 , -1065.42},
                    {797.75 , -1064.08},
                    {799.083 , -1063.75},
                    {802 , -1064.08},
                    {805.417 , -1065.5},
                    {808.583 , -1069.08},
                    {813.667 , -1075},
                    {818.25 , -1080.58}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 116, 118, 32,0.1,true,142,127,35);
        }
        //jewel base layer 6
        {
            double vertices[][2]={
                    {804.188 , -1066},
                    {805.5 , -1078.38},
                    {806.438 , -1080.88},
                    {807.875 , -1081.62},
                    {811.375 , -1083.5},
                    {814.812 , -1083.94},
                    {816.062 , -1082.69},
                    {816.25 , -1079.06},
                    {813.5 , -1075.12},
                    {805.188 , -1066},
                    {804.438 , -1065.5}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 130, 134, 36);
        }
        //jewel base layer 7
        {
            double vertices[][2]={
                    {804.188 , -1066},
                    {805.5 , -1078.38},
                    {806.969 , -1080.34},
                    {808.906 , -1081.22},
                    {811.469 , -1082.09},
                    {813.688 , -1082},
                    {814.125 , -1081.09},
                    {814.062 , -1077.72},
                    {814.062 , -1075.5},
                    {805.188 , -1066},
                    {804.438 , -1065.5}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 159, 160, 56,0.1,true,159, 160, 56);
        }
        //jewel base upper layer
        {
            double vertices[][2]={
                    {804.188 , -1066},
                    {805.5 , -1078.38},
                    {806.312 , -1079.97},
                    {808.062 , -1079.94},
                    {808.688 , -1077.47},
                    {810.875 , -1077.28},
                    {813.219 , -1080.41},
                    {814.062 , -1077.72},
                    {814.062 , -1075.5},
                    {805.188 , -1066},
                    {804.438 , -1065.5}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 190, 179, 73,0.2,true,226,232,115);
        }
        //jewel lights
        {
            glLineWidth(2);
            glBegin(GL_LINE_STRIP);
            glColor4f(155/255.0f, 151/255.0f,61/255.0f, 0.8);
            glVertex2f(808.083, -1093.417);
            glColor4f(155/255.0f, 151/255.0f,61/255.0f, 1);
            glVertex2f(810.792, -1097.375);
            glColor4f(197/255.0f, 199/255.0f,91/255.0f, 1);
            glVertex2f(813.167, -1100.458);
            glVertex2f(815.583, -1103.292);
            glColor4f(155/255.0f, 151/255.0f,61/255.0f, 1);
            glVertex2f(818.167, -1106.042);
            glColor4f(155/255.0f, 151/255.0f,61/255.0f, 0.8);
            glVertex2f(824.583, -1111.667);
            glEnd();
        }

        //elLight elly gowwa elFuonka beta3 elJewel men el4emal
        {
            double vertices[][2]={
                    {823.5 , -1200.17},
                    {825.833 , -1239.83},
                    {853.667 , -1260.33},
                    {853.333 , -1245.5},
                    {852.5 , -1242.67},
                    {851.167 , -1239.17},
                    {849.333 , -1236.17},
                    {847 , -1232.83},
                    {843.667 , -1229},
                    {838.5 , -1223.83},
                    {835 , -1220.17},
                    {831.833 , -1216.83},
                    {829.5 , -1213.17},
                    {827.833 , -1210.67},
                    {825.333 , -1205.33}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);
            glColor4f(253/55.0f,231/255.0f,185/255.0f,0.1);
            for (int i = 0; i <size ; ++i)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 251, 232, 173);
        }
    }

    //eltamweh beta3 eltaraf elle nazel men elfyonka men el4emal
    {
        //base
        {
            double vertices[][2] = {
                    { 756.000, -1047.667 },
                    { 761.500, -1057.833 },
                    { 771.167, -1068.000 },
                    { 776.667, -1073.167 },
                    { 761.167, -1065.333 },
                    { 758.667, -1064.333 },
                    { 759.000, -1066.667 },
                    { 760.500, -1075.333 },
                    { 781.750, -1090.875 },
                    { 798.500, -1104.500 },
                    { 801.500, -1112.500 },
                    { 801.667, -1114.667 },
                    { 802.167, -1121.333 },
                    { 805.833, -1124.667 },
                    { 806.500, -1129.500 },
                    { 807.500, -1185.500 },
                    { 808.750, -1206.688 },
                    { 810.833, -1231.667 },
                    { 812.333, -1239.917 },
                    { 814.333, -1244.917 },
                    { 815.667, -1247.417 },
                    { 826.875, -1258.250 },
                    { 824.333, -1253.500 },
                    { 822.167, -1251.500 },
                    { 820.333, -1248.833 },
                    { 820.167, -1247.667 },
                    { 852.333, -1274.167 },
                    { 839.625, -1342.125 },
                    { 835.667, -1371.000 },
                    { 835.167, -1376.667 },
                    { 837.125, -1395.875 },
                    { 837.625, -1409.250 },
                    { 837.875, -1414.875 },
                    { 831.000, -1421.625 },
                    { 827.250, -1423.750 },
                    { 823.875, -1426.375 },
                    { 819.750, -1383.500 },
                    { 819.250, -1376.000 },
                    { 818.000, -1374.000 },
                    { 817.875, -1370.375 },
                    { 826.500, -1345.333 },
                    { 832.500, -1325.000 },
                    { 833.667, -1311.333 },
                    { 833.833, -1269.333 },
                    { 805.500, -1270.333 },
                    { 792.000, -1241.000 },
                    { 793.833, -1240.583 },
                    { 794.750, -1239.917 },
                    { 796.167, -1238.500 },
                    { 797.333, -1235.667 },
                    { 797.917, -1234.250 },
                    { 800.833, -1119.667 },
                    { 800.667, -1111.500 },
                    { 800.333, -1113.000 },
                    { 800.000, -1113.500 },
                    { 775.417, -1094.000 },
                    { 757.250, -1079.500 },
                    { 756.375, -1062.500 },
                    { 755.875, -1054.125 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 176, 106, 55,0.1,true,176, 106, 55,0.7);
        }
        //elLight elly fe elganb elymeen
        {
            double vertices[][2] = {
                    { 846.500, -1270.500 },
                    { 844.250, -1288.750 },
                    { 836.000, -1317.500 },
                    { 828.750, -1340.000 },
                    { 838.500, -1340.250 },
                    { 843.750, -1314.500 },
                    { 845.500, -1301.750 },
                    { 848.000, -1287.750 },
                    { 851.250, -1274.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 231, 166, 89,0.7,true,234,180,109,1);
        }
        //elLine light elly men ta7t
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(238/255.0f, 175/255.0f, 103/255.0f, 0.6);
            glVertex2f(820.125, -1374.750);
            glColor4f(238/255.0f, 175/255.0f, 103/255.0f, 0.8);
            glVertex2f(826.250, -1372.812);
            glColor4f(238/255.0f, 175/255.0f, 103/255.0f, 0.6);
            glVertex2f(834.438, -1370.625);
            glEnd();
        }
    }
    //elfat7a elle fe elblouse men fou2
    {
        double vertices[][2] = {
                { 575.167, -918.250 },
                { 572.667, -915.667 },
                { 571.250, -913.583 },
                { 571.000, -912.417 },
                { 574.250, -910.583 },
                { 575.917, -910.583 },
                { 579.250, -913.083 },
                { 581.083, -915.333 },
                { 579.000, -916.917 },
                { 576.917, -918.167 }
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 224, 150, 77);
    }

    //elShadows welLines
    {
        //outlines elblouse
        {
            double vertices[][2]={
                    {400 , -1240.5},
                    {400 , -1253.5},
                    {400.667 , -1321.17},
                    {401.75 , -1356.5},
                    {404.5 , -1378.88},
                    {410.25 , -1413.88},
                    {415.25 , -1440.75},
                    {420.167 , -1467},
                    {425 , -1486.83},
                    {418.167 , -1518.5},
                    {414.667 , -1528.17},
                    {408.667 , -1545.17},
                    {403 , -1558.5},
                    {401.708 , -1560.58},
                    {401.25 , -1563.58},
                    {402.083 , -1566.96},
                    {413.438 , -1591.75},
                    {402.667 , -1607.83},
                    {398.167 , -1615.83},
                    {393.333 , -1626.17},
                    {389 , -1636.67},
                    {384.333 , -1648.83},
                    {379.833 , -1663.5},
                    {373.667 , -1685.42},
                    {372.583 , -1691.17},
                    {370.833 , -1698.17},
                    {370.333 , -1703},
                    {370.833 , -1712.58},
                    {372 , -1716.21},
                    {374.292 , -1720.04},
                    {376.125 , -1723},
                    {381.333 , -1729.75},
                    {387.75 , -1736.83},
                    {406.417 , -1754.83},
                    {411.583 , -1759.25},
                    {415.417 , -1763},
                    {423 , -1770.33},
                    {436 , -1783.33},
                    {447.25 , -1794.67},
                    {455.167 , -1801.42},
                    {463.583 , -1808.33},
                    {466.5 , -1810.58},
                    {470.167 , -1813},
                    {473.5 , -1814.67},
                    {476.5 , -1815.75},
                    {478.75 , -1816},
                    {486.125 , -1816.25},
                    {500.75 , -1816.5},
                    {518.125 , -1817.75},
                    {534.458 , -1819.88},
                    {542.917 , -1821},
                    {550.958 , -1822.67},
                    {550 , -1829.46},
                    {548.167 , -1838.04},
                    {546.125 , -1843.44},
                    {545.875 , -1845.38},
                    {546.75 , -1846.25},
                    {557.562 , -1853.06},
                    {564.875 , -1847.06},
                    {565.25 , -1845.81},
                    {565.188 , -1844.75},
                    {564 , -1839.62},
                    {563.812 , -1838.88},
                    //flag1
                    {565.188 , -1840.5},
                    {565.875 , -1840.62},
                    {567.375 , -1840.19},
                    {582.625 , -1828.19},
                    {602.75 , -1832.5},
                    {611.75 , -1834.25},
                    {623 , -1838},
                    {647.25 , -1848.75},
                    {660.25 , -1848.25},
                    {689.667 , -1860.33},
                    {696.5 , -1877.67},
                    {699.833 , -1884},
                    {702.833 , -1888.5},
                    {707.667 , -1895},
                    {711.25 , -1898.75},
                    {713 , -1900},
                    {716.583 , -1900.5},
                    {725.583 , -1900.75},
                    {737.083 , -1900.33},
                    {744.083 , -1899.42},
                    {756 , -1897},
                    {765.167 , -1894.33},
                    {807 , -1883},
                    {828 , -1876.75},
                    {843.25 , -1872.5},
                    {850.688 , -1872},
                    {847.25 , -1872.12},
                    {849.75 , -1873.62},
                    {855 , -1874.88},
                    {863.875 , -1875.38},
                    {875.875 , -1876.12},
                    {897.25 , -1877.25},
                    {910.875 , -1877.25},
                    {929.5 , -1877.25},
                    {938.125 , -1877},
                    {953.75 , -1875},
                    {961.5 , -1874.67},
                    {972.75 , -1872.67},
                    {985.583 , -1870.25},
                    {1012 , -1865.83},
                    {1027 , -1862.67},
                    {1036.5 , -1860.17},
                    {1037.5 , -1859.17},
                    {1066.17 , -1861.17},
                    {1090.67 , -1862.33},
                    {1131.5 , -1862.83},
                    {1136.25 , -1859.25},
                    {1139.5 , -1852.62},
                    {1144.25 , -1842},
                    {1147.5 , -1829.38},
                    {1148.25 , -1823},
                    {1141 , -1755},
                    {1140.25 , -1751.25},
                    {1136.75 , -1744.75},
                    {1133.88 , -1738.62},
                    {1126.88 , -1727.88},
                    {1121.62 , -1719.88},
                    {1117.75 , -1715.75},
                    {1112 , -1711.75},
                    {1108.88 , -1710.5},
                    {1102.62 , -1710.25},
                    {1095.17 , -1711.5},
                    {1088.5 , -1713.5},
                    {1080.83 , -1715.33},
                    {1075.33 , -1716.5},
                    {1069 , -1716.83},
                    {1056.5 , -1716.83},
                    {1049.5 , -1715.67},
                    {1042.33 , -1714.17},
                    {1033.83 , -1710.17},
                    {1025.25 , -1704.38},
                    {1018.38 , -1699.38},
                    {1015.88 , -1697.5},
                    {1015.17 , -1697},
                    {1012.83 , -1691.83},
                    {1010 , -1683.67},
                    {1007.83 , -1671.17},
                    {1006 , -1656},
                    {1004.17 , -1636.83},
                    {1003.33 , -1624.83},
                    {1005 , -1566.67},
                    {1004.33 , -1553.67},
                    {1005.38 , -1542.88},
                    {1006.38 , -1536.12},
                    {1007.62 , -1527.62},
                    {1009.12 , -1520.38},
                    {1010.62 , -1513.25},
                    {1010.75 , -1502},
                    {1013.75 , -1424.5},
                    {1013.88 , -1395.75},
                    {1013.38 , -1379.5},
                    {1012.88 , -1371.12},
                    {1011.5 , -1365.75},
                    {1006.12 , -1350.88},
                    {991.5 , -1321.62},
                    {987.667 , -1310.33},
                    {980.833 , -1294},
                    {972.833 , -1279},
                    {963 , -1263.83},
                    {954.5 , -1253},
                    {941.875 , -1236.5},
                    {935.5 , -1229.12},
                    {928.375 , -1221.75},
                    {921.375 , -1214.62},
                    {914.5 , -1209.12},
                    {914.625 , -1199.12},
                    {912.75 , -1188.75},
                    {909.25 , -1177},
                    {905.5 , -1172.5},
                    {893.25 , -1165},
                    {895 , -1171},
                    {900.5 , -1178.75},
                    {894.75 , -1173.5},
                    {897.5 , -1179.5},
                    {900.75 , -1183},
                    {902.5 , -1186.5},
                    {894.5 , -1176.75},
                    {891.75 , -1173.5},
                    {887.25 , -1166.75},
                    {878.5 , -1154.75},
                    {872.25 , -1146.75},
                    {863 , -1132.75},
                    {845.833 , -1113.33},
                    {838.5 , -1100.83},
                    {825 , -1072.83},
                    {821.5 , -1067.5},
                    {818.833 , -1063},
                    {814 , -1054.5},
                    {811.333 , -1048.83},
                    {809.667 , -1044.17},
                    {807.167 , -1038.33},
                    {798.667 , -1014},
                    {795 , -1003.67},
                    {793.833 , -1001.5},
                    {790.667 , -997.5},
                    {787.667 , -994.333},
                    {786 , -992.25},
                    {785.5 , -989.5},
                    {784.417 , -986.417},
                    {780.75 , -982.833},
                    {775.583 , -978.583},
                    {773.5 , -976.25},
                    {772.25 , -970},
                    {773.75 , -960.75},
                    {774.75 , -954},
                    {774.75 , -944.25},
                    {774 , -940},
                    {771.917 , -942.167},
                    {770.75 , -944},
                    //flag2
                    {587.125 , -881.625},
                    {579.625 , -883.875},
                    {578 , -886},
                    {579 , -891.375},
                    {580.375 , -898.75},
                    {582.375 , -903.375},
                    {569.25 , -911.125},
                    {569.625 , -913.375},
                    {572.5 , -919.25},
                    {572.625 , -920.75},
                    {549.25 , -936},
                    {548.958 , -937.125},
                    {549.042 , -938.583},
                    {555.875 , -953.125},
                    {550.25 , -964.917},
                    {548.583 , -969.417},
                    {546.667 , -974.75},
                    {545.167 , -980.833},
                    {544.417 , -988.5},
                    {544.75 , -989.667},
                    {535.5 , -997.25},
                    {533 , -999.75},
                    {532.375 , -1001.5},
                    {532.375 , -1002.62},
                    {512.5 , -1029.12},
                    {511.25 , -1032.75},
                    {505.125 , -1038.62},
                    {493.375 , -1048.25},
                    {489.625 , -1051.62},
                    {488.875 , -1054.5},
                    {488.875 , -1059.75},
                    {486.75 , -1066.69},
                    {482.375 , -1075.94},
                    {478.438 , -1083.25},
                    {470 , -1096.75},
                    {454.75 , -1125.62},
                    {444.125 , -1145.62},
                    {433.375 , -1166.62},
                    {408 , -1215.75},
                    {404.5 , -1224.5},
                    {402.75 , -1229.88},
                    {401.25 , -1235.12},
                    {400.25 , -1238.88}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(1);
            glBegin(GL_LINE_LOOP);
            //Color flag
            glColor4f(94/255.0f,36/255.0f,15/255.0f,1);
            for (int i = 0; i < size; i++) {
                glVertex2dv(vertices[i]);
            }
            glEnd();
        }

        //124
        {
            double vertices[][2] = {
                    { 554.917, -1787.333 },
                    { 524.500, -1776.000 },
                    { 499.000, -1767.000 },
                    { 471.000, -1753.000 },
                    { 454.500, -1744.000 },
                    { 440.500, -1735.500 },
                    { 433.000, -1730.500 },
                    { 430.750, -1726.500 },
                    { 433.000, -1725.250 },
                    { 437.750, -1724.000 },
                    { 444.000, -1723.500 },
                    { 453.000, -1723.500 },
                    { 462.250, -1725.500 },
                    { 482.750, -1733.500 },
                    { 491.250, -1737.500 },
                    { 503.500, -1743.500 },
                    { 520.250, -1752.500 },
                    { 529.750, -1756.500 },
                    { 531.667, -1754.833 },
                    { 534.667, -1753.000 },
                    { 536.917, -1751.917 },
                    { 541.250, -1752.417 },
                    { 545.667, -1754.417 },
                    { 562.333, -1764.000 },
                    { 576.625, -1766.625 },
                    { 588.250, -1770.000 },
                    { 594.875, -1769.625 },
                    { 599.000, -1767.000 },
                    { 597.500, -1764.125 },
                    { 595.250, -1761.375 },
                    { 592.250, -1757.000 },
                    { 591.875, -1756.125 },
                    { 602.875, -1763.250 },
                    { 611.750, -1769.000 },
                    { 621.875, -1772.375 },
                    { 627.375, -1773.375 },
                    { 632.250, -1773.750 },
                    { 637.000, -1775.125 },
                    { 641.875, -1777.750 },
                    { 642.875, -1778.125 },
                    { 640.250, -1773.125 },
                    { 636.500, -1770.000 },
                    { 633.125, -1768.625 },
                    { 631.000, -1766.000 },
                    { 629.500, -1762.125 },
                    { 628.000, -1757.875 },
                    { 638.000, -1768.000 },
                    { 641.625, -1772.125 },
                    { 642.750, -1773.000 },
                    { 644.500, -1770.125 },
                    { 647.875, -1768.125 },
                    { 651.875, -1766.375 },
                    { 656.125, -1765.250 },
                    { 659.625, -1763.625 },
                    { 661.375, -1762.000 },
                    { 665.500, -1766.500 },
                    { 671.833, -1759.167 },
                    { 675.833, -1755.167 },
                    { 681.167, -1750.833 },
                    { 686.333, -1743.167 },
                    { 688.333, -1740.000 },
                    { 691.667, -1736.833 },
                    { 696.833, -1732.833 },
                    { 702.333, -1727.500 },
                    { 706.333, -1725.000 },
                    { 711.625, -1716.625 },
                    { 716.250, -1711.125 },
                    { 718.000, -1705.750 },
                    { 719.375, -1697.875 },
                    { 720.375, -1692.125 },
                    { 722.250, -1687.500 },
                    { 725.500, -1679.875 },
                    { 726.000, -1690.875 },
                    { 724.000, -1706.875 },
                    { 722.250, -1718.875 },
                    { 717.375, -1726.750 },
                    { 706.250, -1742.375 },
                    { 698.500, -1761.125 },
                    { 699.000, -1745.000 },
                    { 684.500, -1766.375 },
                    { 670.625, -1788.000 },
                    { 662.875, -1795.375 },
                    { 659.750, -1799.375 },
                    { 660.750, -1800.625 },
                    { 664.000, -1800.750 },
                    { 680.625, -1786.250 },
                    { 695.500, -1768.875 },
                    { 697.750, -1769.125 },
                    { 712.000, -1763.125 },
                    { 721.875, -1757.375 },
                    { 731.250, -1754.000 },
                    { 744.667, -1748.500 },
                    { 755.333, -1745.333 },
                    { 766.500, -1742.000 },
                    { 779.333, -1738.500 },
                    { 761.833, -1746.833 },
                    { 738.500, -1757.500 },
                    { 722.333, -1765.833 },
                    { 717.667, -1768.667 },
                    { 715.167, -1773.167 },
                    { 714.500, -1776.667 },
                    { 726.000, -1777.500 },
                    { 742.167, -1779.833 },
                    { 756.500, -1783.667 },
                    { 771.333, -1788.500 },
                    { 778.833, -1794.000 },
                    { 783.875, -1800.750 },
                    { 784.375, -1802.875 },
                    { 781.125, -1802.375 },
                    { 772.125, -1796.750 },
                    { 759.250, -1789.500 },
                    { 748.500, -1786.750 },
                    { 738.750, -1783.875 },
                    { 755.625, -1793.250 },
                    { 735.875, -1785.500 },
                    { 722.250, -1783.500 },
                    { 711.000, -1783.250 },
                    { 697.000, -1785.333 },
                    { 683.500, -1788.667 },
                    { 674.333, -1794.333 },
                    { 672.167, -1795.500 },
                    { 664.500, -1802.000 },
                    { 660.000, -1802.500 },
                    { 657.833, -1800.333 },
                    { 659.000, -1798.333 },
                    { 657.417, -1795.167 },
                    { 653.083, -1791.667 },
                    { 648.250, -1789.083 },
                    { 639.833, -1785.667 },
                    { 628.750, -1782.333 },
                    { 623.750, -1781.375 },
                    { 618.500, -1781.875 },
                    { 616.250, -1782.875 },
                    { 632.625, -1790.375 },
                    { 631.875, -1791.625 },
                    { 624.875, -1789.375 },
                    { 617.375, -1786.125 },
                    { 612.500, -1784.500 },
                    { 600.125, -1783.375 },
                    { 590.875, -1783.250 },
                    { 581.750, -1784.250 },
                    { 571.167, -1786.667 },
                    { 560.083, -1788.333 },
                    { 557.417, -1788.917 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 73, 36, 23,0.7);
        }
        //125
        {
            double vertices[][2] = {
                    { 617.500, -1783.000 },
                    { 633.750, -1791.000 },
                    { 632.500, -1792.000 },
                    { 625.500, -1792.750 },
                    { 610.250, -1791.500 },
                    { 598.250, -1790.750 },
                    { 592.250, -1790.250 },
                    { 583.750, -1790.500 },
                    { 594.000, -1797.000 },
                    { 603.750, -1800.250 },
                    { 618.000, -1804.000 },
                    { 633.250, -1806.500 },
                    { 643.250, -1808.000 },
                    { 652.000, -1806.000 },
                    { 656.750, -1802.750 },
                    { 658.250, -1800.000 },
                    { 657.500, -1796.250 },
                    { 654.750, -1792.750 },
                    { 649.250, -1788.750 },
                    { 639.250, -1785.250 },
                    { 628.500, -1781.750 },
                    { 622.500, -1781.250 },
                    { 620.750, -1781.250 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 73, 36, 23,0.5);
        }
        //126
        {
            double vertices[][2] = {
                    { 651.750, -1807.500 },
                    { 633.250, -1804.500 },
                    { 626.250, -1799.750 },
                    { 619.750, -1793.750 },
                    { 626.250, -1792.500 },
                    { 633.250, -1792.000 },
                    { 630.500, -1789.250 },
                    { 620.250, -1786.750 },
                    { 609.250, -1783.750 },
                    { 605.500, -1782.000 },
                    { 602.750, -1779.000 },
                    { 598.250, -1774.750 },
                    { 592.250, -1772.250 },
                    { 590.250, -1769.750 },
                    { 594.000, -1769.750 },
                    { 599.500, -1768.000 },
                    { 597.750, -1764.750 },
                    { 592.250, -1756.750 },
                    { 607.500, -1766.750 },
                    { 619.250, -1772.250 },
                    { 635.000, -1775.250 },
                    { 646.000, -1777.250 },
                    { 651.250, -1781.750 },
                    { 654.000, -1786.250 },
                    { 656.250, -1792.000 },
                    { 659.750, -1794.000 },
                    { 667.250, -1786.250 },
                    { 677.750, -1770.000 },
                    { 687.750, -1752.250 },
                    { 688.500, -1750.250 },
                    { 682.000, -1771.750 },
                    { 669.250, -1790.000 },
                    { 661.000, -1798.750 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 73, 36, 23,0.5);
        }
        //127
        {
            glColor4f(73/255.0f, 36/255.0f, 23/255.0f, 0.3);
            glBegin(GL_POLYGON);
            glVertex2f(658.500, -1811.500);
            glVertex2f(647.500, -1807.000);
            glVertex2f(641.000, -1794.000);
            glVertex2f(646.000, -1783.500);
            glVertex2f(654.500, -1779.000);
            glVertex2f(667.000, -1780.000);
            glVertex2f(675.500, -1784.000);
            glVertex2f(672.000, -1799.500);
            glVertex2f(667.500, -1806.000);
            glEnd();
        }
        //128
        {
            double vertices[][2] = {
                    { 772.500, -1713.500 },
                    { 787.000, -1693.500 },
                    { 796.250, -1682.250 },
                    { 803.000, -1673.500 },
                    { 812.500, -1665.000 },
                    { 827.500, -1650.000 },
                    { 832.750, -1645.250 },
                    { 835.000, -1646.250 },
                    { 821.750, -1670.500 },
                    { 804.750, -1690.250 },
                    { 791.750, -1703.500 },
                    { 780.250, -1712.250 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 107, 56, 32,0.8);
        }

        //73
        {
            glLineWidth(1);
            glColor4f(94/255.0f,36/255.0f,15/255.0f,1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(580.500, -905.167);
            glVertex2f(583.167, -911.667);
            glVertex2f(586.500, -917.667);
            glVertex2f(592.167, -924.167);
            glEnd();
        }
        //74
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(576.188, -940.312);
            glVertex2f(582.062, -944.000);
            glVertex2f(586.875, -946.250);
            glVertex2f(592.125, -948.500);
            glVertex2f(596.562, -950.812);
            glVertex2f(598.188, -951.625);
            glEnd();
        }
        //75
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(562.375, -951.500);
            glVertex2f(578.125, -956.125);
            glVertex2f(583.500, -957.875);
            glVertex2f(589.375, -960.375);
            glVertex2f(601.125, -965.500);
            glVertex2f(607.750, -969.125);
            glEnd();
        }
        //76
        {
            double vertices[][2] = {
                    { 543.000, -991.000 },
                    { 549.000, -987.125 },
                    { 554.875, -984.250 },
                    { 564.500, -981.375 },
                    { 571.250, -981.000 },
                    { 582.125, -981.625 },
                    { 592.625, -984.125 },
                    { 604.000, -987.000 },
                    { 609.750, -988.625 },
                    { 600.875, -984.500 },
                    { 592.000, -981.250 },
                    { 580.750, -978.250 },
                    { 574.000, -976.750 },
                    { 570.125, -976.000 },
                    { 562.500, -980.875 },
                    { 553.125, -983.812 },
                    { 549.688, -985.375 },
                    { 545.375, -987.812 },
                    { 543.500, -989.625 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 61, 28, 20);
        }
        //76 line
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(543.000, -991.000);
            glVertex2f(549.000, -987.125);
            glVertex2f(554.875, -984.250);
            glVertex2f(564.500, -981.375);
            glVertex2f(571.250, -981.000);
            glVertex2f(582.125, -981.625);
            glVertex2f(592.625, -984.125);
            glVertex2f(604.000, -987.000);
            glVertex2f(609.750, -988.625);
            glEnd();
        }
        //77
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(590.500, -1019.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glVertex2f(588.500, -1026.500);
            glVertex2f(583.500, -1045.500);
            glVertex2f(579.750, -1062.250);
            glVertex2f(576.750, -1081.500);
            glVertex2f(573.250, -1105.250);
            glVertex2f(571.500, -1129.750);
            glVertex2f(570.875, -1144.875);
            glVertex2f(570.875, -1151.250);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(570.750, -1155.000);
            glEnd();
        }
        //78
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(547.375, -1162.375);
            glVertex2f(561.125, -1162.250);
            glVertex2f(573.875, -1165.125);
            glVertex2f(592.167, -1169.500);
            glEnd();
        }
        //79
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.3);
            glVertex2f(544.667, -1162.500);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glVertex2f(538.833, -1163.833);
            glVertex2f(530.167, -1167.333);
            glVertex2f(520.333, -1173.000);
            glVertex2f(510.333, -1180.667);
            glVertex2f(502.500, -1187.500);
            glVertex2f(491.667, -1200.000);
            glVertex2f(482.500, -1212.333);
            glVertex2f(471.250, -1228.750);
            glVertex2f(465.625, -1239.500);
            glVertex2f(456.250, -1258.500);
            glVertex2f(449.375, -1276.250);
            glVertex2f(445.250, -1293.500);
            glVertex2f(442.375, -1309.000);
            glVertex2f(442.000, -1316.500);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(441.875, -1328.625);
            glEnd();
        }
        //81
        {
            double vertices[][2] = {
                    { 432.500, -1328.583 },
                    { 431.083, -1310.917 },
                    { 430.833, -1291.167 },
                    { 430.667, -1276.000 },
                    { 430.500, -1238.750 },
                    { 430.000, -1218.875 },
                    { 429.500, -1214.375 },
                    { 428.000, -1212.750 },
                    { 426.375, -1212.875 },
                    { 425.125, -1215.500 },
                    { 422.625, -1227.250 },
                    { 419.875, -1243.250 },
                    { 419.125, -1262.125 },
                    { 420.250, -1275.000 },
                    { 421.125, -1279.625 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 89, 43, 23,1,true,89, 43, 23,0.7);
        }
        //82
        {
            double vertices[][2] = {
                    { 469.500, -1495.500 },
                    { 463.750, -1487.250 },
                    { 457.250, -1477.250 },
                    { 453.500, -1471.500 },
                    { 447.250, -1459.750 },
                    { 442.750, -1448.250 },
                    { 436.250, -1431.750 },
                    { 430.750, -1419.000 },
                    { 426.375, -1399.500 },
                    { 423.750, -1383.125 },
                    { 422.375, -1374.750 },
                    { 420.875, -1366.750 },
                    { 419.000, -1359.375 },
                    { 415.333, -1344.167 },
                    { 425.750, -1365.917 },
                    { 432.833, -1380.167 },
                    { 438.333, -1392.833 },
                    { 442.333, -1402.167 },
                    { 455.000, -1437.833 },
                    { 458.000, -1449.667 },
                    { 461.833, -1460.667 },
                    { 466.167, -1472.833 },
                    { 468.000, -1483.333 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 70, 33, 23,1,true,70, 33, 23,0.5);
        }
        //80
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.2);
            glVertex2f(421.625, -1280.000);
            glVertex2f(423.750, -1290.125);
            glVertex2f(427.125, -1306.542);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.9);
            glVertex2f(432.625, -1329.875);
            glVertex2f(437.917, -1348.167);
            glVertex2f(440.583, -1359.667);
            glVertex2f(450.167, -1416.167);
            glVertex2f(453.000, -1436.667);
            glVertex2f(455.750, -1454.083);
            glVertex2f(457.583, -1463.083);
            glVertex2f(459.167, -1470.750);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glVertex2f(461.417, -1475.500);
            glEnd();
        }
        //83
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.3);
            glVertex2f(426.583, -1440.167);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.8);
            glVertex2f(426.333, -1455.667);
            glVertex2f(426.333, -1465.500);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.3);
            glVertex2f(426.333, -1474.583);
            glEnd();
        }
        //84
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.1);
            glVertex2f(407.125, -1549.250);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glVertex2f(410.875, -1542.750);
            glVertex2f(415.875, -1536.125);
            glVertex2f(421.875, -1526.625);
            glVertex2f(427.750, -1517.125);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.2);
            glVertex2f(431.750, -1509.500);
            glVertex2f(434.000, -1504.875);
            glVertex2f(437.375, -1500.125);
            glEnd();
        }
        //85
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.1);
            glVertex2f(506.667, -1318.667);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(519.000, -1292.667);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glVertex2f(527.667, -1273.333);
            glVertex2f(540.333, -1252.333);
            glVertex2f(552.000, -1231.667);
            glVertex2f(558.667, -1216.000);
            glVertex2f(565.333, -1195.667);
            glVertex2f(568.250, -1187.000);
            glVertex2f(571.250, -1181.250);
            glVertex2f(573.000, -1190.750);
            glVertex2f(573.000, -1197.750);
            glVertex2f(561.750, -1222.000);
            glVertex2f(551.250, -1248.500);
            glVertex2f(541.750, -1270.750);
            glVertex2f(536.500, -1288.000);
            glVertex2f(529.000, -1313.750);
            glVertex2f(517.250, -1363.250);
            glVertex2f(510.750, -1391.000);
            glVertex2f(501.167, -1431.167);
            glVertex2f(497.333, -1444.333);
            glVertex2f(492.833, -1459.833);
            glVertex2f(489.000, -1470.667);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(484.833, -1481.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.1);
            glVertex2f(481.750, -1488.750);
            glEnd();
        }
        //86
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.2);
            glVertex2f(511.000, -1331.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glVertex2f(503.250, -1358.250);
            glVertex2f(496.000, -1383.500);
            glVertex2f(489.000, -1406.750);
            glVertex2f(483.250, -1427.000);
            glVertex2f(479.250, -1449.000);
            glVertex2f(476.250, -1464.250);
            glVertex2f(473.000, -1483.500);
            glVertex2f(471.500, -1490.000);
            glVertex2f(467.500, -1503.167);
            glVertex2f(461.833, -1517.167);
            glVertex2f(455.000, -1531.500);
            glVertex2f(446.167, -1547.333);
            glVertex2f(435.333, -1562.500);
            glVertex2f(425.167, -1577.000);
            glVertex2f(411.167, -1594.167);
            glEnd();
        }
        //87
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(485.000, -1504.500);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.2);
            glVertex2f(481.000, -1519.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.8);
            glVertex2f(470.500, -1547.500);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glVertex2f(461.750, -1566.750);
            glVertex2f(449.000, -1604.750);
            glVertex2f(446.250, -1616.250);
            glVertex2f(443.000, -1629.000);
            glVertex2f(439.750, -1644.750);
            glVertex2f(438.000, -1658.500);
            glVertex2f(436.500, -1673.250);
            glVertex2f(436.750, -1683.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.8);
            glVertex2f(437.250, -1695.750);
            glEnd();
        }
        //88
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(573.500, -1198.000);
            glVertex2f(573.750, -1204.750);
            glVertex2f(573.000, -1214.750);
            glVertex2f(570.000, -1227.250);
            glVertex2f(565.500, -1242.000);
            glVertex2f(561.750, -1256.000);
            glVertex2f(556.750, -1278.250);
            glVertex2f(550.500, -1308.250);
            glVertex2f(545.000, -1340.250);
            glVertex2f(541.500, -1358.750);
            glVertex2f(538.750, -1374.750);
            glVertex2f(534.500, -1396.750);
            glVertex2f(531.000, -1409.750);
            glVertex2f(519.750, -1446.250);
            glVertex2f(514.000, -1465.750);
            glVertex2f(511.750, -1475.250);
            glVertex2f(510.750, -1480.250);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.6);
            glVertex2f(510.000, -1487.250);
            glEnd();
        }
        //89
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.6);
            glVertex2f(510.000, -1486.875);
            glVertex2f(507.000, -1497.500);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glVertex2f(501.250, -1513.125);
            glVertex2f(499.375, -1517.938);
            glVertex2f(490.333, -1543.333);
            glVertex2f(481.667, -1568.500);
            glVertex2f(475.500, -1588.500);
            glVertex2f(472.000, -1608.250);
            glVertex2f(467.000, -1635.250);
            glVertex2f(464.625, -1654.250);
            glVertex2f(463.167, -1672.000);
            glVertex2f(463.000, -1684.500);
            glVertex2f(465.875, -1693.500);
            glVertex2f(470.250, -1702.250);
            glVertex2f(480.750, -1715.250);
            glVertex2f(500.250, -1732.833);
            glVertex2f(525.000, -1752.500);
            glVertex2f(539.500, -1763.167);
            glVertex2f(556.500, -1771.333);
            glVertex2f(574.833, -1779.000);
            glVertex2f(587.000, -1783.125);
            glVertex2f(583.875, -1784.000);
            glVertex2f(578.625, -1785.000);
            glVertex2f(571.167, -1786.667);
            glVertex2f(564.375, -1787.625);
            glVertex2f(554.125, -1789.375);
            glVertex2f(546.125, -1790.000);
            glVertex2f(532.000, -1791.125);
            glVertex2f(519.250, -1791.500);
            glVertex2f(509.375, -1791.125);
            glVertex2f(499.250, -1790.000);
            glVertex2f(490.333, -1788.417);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(484.000, -1787.250);
            glVertex2f(477.333, -1785.333);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.1);
            glVertex2f(473.583, -1784.583);
            glEnd();
        }
        //90
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(587.167, -1783.167);
            glVertex2f(593.167, -1783.333);
            glVertex2f(603.667, -1783.333);
            glVertex2f(610.667, -1784.167);
            glVertex2f(617.667, -1785.667);
            glVertex2f(625.333, -1788.667);
            glVertex2f(635.833, -1792.833);
            glVertex2f(648.125, -1800.125);
            glVertex2f(634.500, -1791.750);
            glVertex2f(622.375, -1787.000);
            glVertex2f(615.500, -1783.750);
            glVertex2f(611.875, -1781.250);
            glVertex2f(606.000, -1777.500);
            glVertex2f(601.500, -1775.750);
            glVertex2f(588.667, -1771.000);
            glVertex2f(573.667, -1764.500);
            glVertex2f(559.667, -1758.000);
            glVertex2f(549.500, -1750.333);
            glVertex2f(535.500, -1738.000);
            glVertex2f(524.333, -1725.000);
            glVertex2f(514.333, -1710.333);
            glVertex2f(510.333, -1703.167);
            glVertex2f(507.333, -1695.500);
            glVertex2f(506.333, -1687.500);
            glVertex2f(506.000, -1676.500);
            glVertex2f(508.167, -1661.500);
            glVertex2f(511.167, -1642.667);
            glVertex2f(518.500, -1605.500);
            glVertex2f(527.750, -1566.750);
            glVertex2f(535.000, -1539.250);
            glVertex2f(540.625, -1521.125);
            glVertex2f(548.875, -1496.125);
            glVertex2f(554.125, -1479.625);
            glVertex2f(557.875, -1464.375);
            glVertex2f(561.875, -1446.000);
            glVertex2f(567.000, -1413.250);
            glVertex2f(571.333, -1380.000);
            glVertex2f(573.167, -1351.000);
            glVertex2f(573.500, -1328.500);
            glVertex2f(573.333, -1309.333);
            glVertex2f(573.000, -1291.667);
            glVertex2f(571.500, -1261.500);
            glVertex2f(572.000, -1240.500);
            glVertex2f(572.000, -1226.500);
            glEnd();
        }
        //91
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(565.000, -1292.000);
            glVertex2f(563.500, -1318.500);
            glVertex2f(559.500, -1355.500);
            glVertex2f(553.000, -1405.500);
            glVertex2f(545.000, -1436.500);
            glVertex2f(531.500, -1478.000);
            glVertex2f(521.000, -1511.000);
            glVertex2f(515.000, -1531.000);
            glVertex2f(507.000, -1564.750);
            glVertex2f(500.250, -1596.250);
            glVertex2f(493.500, -1620.250);
            glVertex2f(489.500, -1634.250);
            glVertex2f(484.000, -1665.667);
            glVertex2f(483.333, -1679.000);
            glVertex2f(485.000, -1689.333);
            glVertex2f(488.667, -1699.333);
            glVertex2f(501.000, -1716.333);
            glVertex2f(523.000, -1739.333);
            glVertex2f(536.333, -1751.667);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(545.000, -1757.833);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.1);
            glVertex2f(571.333, -1768.500);
            glEnd();
        }
        //92
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(573.000, -1205.000);
            glVertex2f(580.000, -1231.000);
            glVertex2f(585.000, -1254.000);
            glVertex2f(589.000, -1313.000);
            glVertex2f(586.000, -1347.000);
            glVertex2f(580.000, -1405.000);
            glVertex2f(566.000, -1488.000);
            glVertex2f(559.000, -1523.000);
            glVertex2f(551.000, -1572.000);
            glVertex2f(542.000, -1623.000);
            glVertex2f(535.000, -1668.000);
            glVertex2f(534.000, -1688.000);
            glVertex2f(535.000, -1695.000);
            glVertex2f(541.000, -1705.000);
            glVertex2f(558.000, -1725.000);
            glVertex2f(580.000, -1746.000);
            glVertex2f(595.000, -1759.000);
            glVertex2f(607.000, -1766.000);
            glVertex2f(618.000, -1771.000);
            glVertex2f(628.000, -1775.000);
            glEnd();
        }
        //93
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.4);
            glVertex2f(559.333, -1641.333);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glVertex2f(561.000, -1628.000);
            glVertex2f(566.000, -1604.667);
            glVertex2f(570.000, -1579.333);
            glVertex2f(571.333, -1558.333);
            glVertex2f(573.000, -1537.000);
            glVertex2f(574.000, -1510.333);
            glVertex2f(574.667, -1496.000);
            glVertex2f(576.667, -1466.000);
            glVertex2f(578.500, -1448.250);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(579.625, -1435.625);
            glVertex2f(581.000, -1421.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.1);
            glVertex2f(581.500, -1414.625);
            glEnd();
        }
        //94
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.9);
            glBegin(GL_LINE_STRIP);
            glVertex2f(587.875, -1352.875);
            glVertex2f(588.500, -1379.000);
            glVertex2f(588.333, -1435.000);
            glVertex2f(588.000, -1459.500);
            glVertex2f(589.333, -1475.333);
            glColor4f(154/255.0f, 113/255.0f, 70/255.0f, 1);
            glVertex2f(597.333, -1509.667);
            glVertex2f(605.667, -1545.167);
            glVertex2f(612.875, -1577.000);
            glVertex2f(614.750, -1594.250);
            glVertex2f(616.375, -1610.000);
            glVertex2f(617.375, -1622.500);
            glVertex2f(619.750, -1637.625);
            glColor4f(154/255.0f, 113/255.0f, 70/255.0f, 0.1);
            glVertex2f(625.500, -1655.333);
            glEnd();
        }
        //95
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.3);
            glVertex2f(595.500, -1287.333);
            glVertex2f(594.667, -1308.333);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glVertex2f(594.500, -1343.667);
            glVertex2f(594.500, -1384.000);
            glVertex2f(594.000, -1399.250);
            glVertex2f(595.500, -1412.500);
            glEnd();
        }
        //96
        {
            glLineWidth(1);
            glColor4f(154/255.0f, 113/255.0f, 70/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(609.000, -1451.667);
            glVertex2f(605.333, -1442.667);
            glVertex2f(603.000, -1432.333);
            glVertex2f(599.667, -1412.333);
            glColor4f(154/255.0f, 113/255.0f, 70/255.0f, 0.0);
            glVertex2f(600.667, -1355.000);
            glColor4f(154/255.0f, 113/255.0f, 70/255.0f, 1);
            glVertex2f(605.000, -1392.333);
            glVertex2f(612.667, -1413.000);
            glVertex2f(633.500, -1468.000);
            glVertex2f(651.833, -1503.500);
            glVertex2f(662.667, -1530.000);
            glVertex2f(668.333, -1545.500);
            glVertex2f(676.250, -1562.000);
            glVertex2f(685.000, -1575.500);
            glVertex2f(692.750, -1588.000);
            glVertex2f(701.500, -1602.250);
            glVertex2f(708.000, -1612.250);
            glEnd();
        }
        //97
        {
            glLineWidth(1);
            glColor4f(154/255.0f, 113/255.0f, 70/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(650.000, -1452.000);
            glVertex2f(642.667, -1440.000);
            glVertex2f(635.000, -1426.667);
            glVertex2f(627.333, -1409.333);
            glVertex2f(617.667, -1384.333);
            glVertex2f(611.333, -1359.667);
            glVertex2f(605.000, -1340.000);
            glVertex2f(602.000, -1321.000);
            glVertex2f(599.500, -1297.500);
            glVertex2f(600.000, -1294.000);
            glVertex2f(595.500, -1283.000);
            glVertex2f(591.750, -1272.750);
            glVertex2f(588.250, -1261.750);
            glVertex2f(583.500, -1245.750);
            glVertex2f(591.500, -1272.750);
            glVertex2f(595.750, -1283.500);
            glColor4f(154/255.0f, 113/255.0f, 70/255.0f, 0.5);
            glVertex2f(604.250, -1304.500);
            glVertex2f(613.375, -1324.125);
            glVertex2f(620.875, -1340.125);
            glVertex2f(627.625, -1349.875);
            glVertex2f(640.500, -1372.333);
            glVertex2f(645.167, -1381.667);
            glVertex2f(651.500, -1394.833);
            glVertex2f(657.667, -1410.167);
            glVertex2f(663.833, -1423.333);
            glEnd();
        }
        //98
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glVertex2f(574.333, -1202.000);
            glVertex2f(584.000, -1220.333);
            glVertex2f(592.667, -1240.333);
            glVertex2f(603.333, -1267.000);
            glVertex2f(620.333, -1310.333);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(638.000, -1351.667);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.2);
            glVertex2f(667.333, -1414.333);
            glEnd();
        }
        //99
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(592.333, -1233.000);
            glVertex2f(603.333, -1252.667);
            glVertex2f(610.000, -1266.667);
            glVertex2f(619.333, -1286.333);
            glVertex2f(629.333, -1312.333);
            glVertex2f(636.000, -1329.667);
            glVertex2f(644.333, -1345.667);
            glVertex2f(652.333, -1363.000);
            glVertex2f(659.333, -1380.333);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(669.500, -1406.250);
            glVertex2f(674.750, -1419.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.3);
            glVertex2f(686.083, -1439.000);
            glVertex2f(699.000, -1455.500);
            glVertex2f(702.167, -1460.167);
            glEnd();
        }
        //100
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(573.500, -1194.000);
            glVertex2f(587.250, -1213.000);
            glVertex2f(603.000, -1237.500);
            glVertex2f(617.125, -1262.750);
            glVertex2f(626.750, -1281.250);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.8);
            glVertex2f(636.250, -1301.375);
            glVertex2f(645.000, -1318.375);
            glVertex2f(655.375, -1338.375);
            glVertex2f(667.250, -1356.125);
            glVertex2f(684.250, -1379.750);
            glVertex2f(709.500, -1410.750);
            glVertex2f(731.625, -1434.875);
            glVertex2f(744.812, -1446.125);
            glVertex2f(748.167, -1450.167);
            glVertex2f(752.417, -1458.083);
            glVertex2f(755.917, -1463.167);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(766.667, -1477.000);
            glVertex2f(778.917, -1490.583);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.1);
            glVertex2f(791.000, -1503.125);
            glEnd();
        }
        //101
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.8);
            glBegin(GL_LINE_STRIP);
            glVertex2f(628.167, -1250.500);
            glVertex2f(636.833, -1264.333);
            glVertex2f(647.167, -1280.667);
            glVertex2f(657.667, -1300.833);
            glVertex2f(668.167, -1320.333);
            glVertex2f(678.000, -1341.333);
            glVertex2f(681.667, -1347.500);
            glVertex2f(689.417, -1359.083);
            glVertex2f(698.667, -1372.167);
            glVertex2f(722.583, -1403.583);
            glVertex2f(731.625, -1414.625);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(739.875, -1422.625);
            glVertex2f(744.625, -1427.750);
            glVertex2f(751.250, -1434.375);
            glVertex2f(755.125, -1439.250);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.2);
            glVertex2f(757.125, -1443.375);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.1);
            glVertex2f(759.250, -1450.875);
            glEnd();
        }
        //102
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(651.667, -1355.333);
            glVertex2f(657.000, -1367.000);
            glVertex2f(666.000, -1381.000);
            glVertex2f(682.333, -1398.667);
            glVertex2f(701.667, -1416.333);
            glVertex2f(723.667, -1435.000);
            glVertex2f(735.333, -1444.333);
            glVertex2f(744.000, -1452.000);
            glEnd();
        }
        //103
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.4);
            glBegin(GL_LINE_STRIP);
            glVertex2f(736.000, -1466.250);
            glVertex2f(745.250, -1477.750);
            glVertex2f(751.750, -1485.750);
            glVertex2f(757.500, -1494.500);
            glEnd();
        }
        //104
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.4);
            glBegin(GL_LINE_STRIP);
            glVertex2f(763.333, -1496.000);
            glVertex2f(783.667, -1516.333);
            glVertex2f(804.667, -1536.667);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.8);
            glVertex2f(818.333, -1551.333);
            glVertex2f(826.000, -1560.667);
            glVertex2f(831.000, -1570.333);
            glVertex2f(833.333, -1580.667);
            glVertex2f(834.000, -1592.000);
            glVertex2f(829.000, -1607.667);
            glVertex2f(819.333, -1627.000);
            glVertex2f(811.000, -1637.000);
            glVertex2f(796.667, -1653.000);
            glVertex2f(777.000, -1669.000);
            glVertex2f(759.000, -1684.667);
            glVertex2f(743.000, -1698.000);
            glVertex2f(731.333, -1709.833);
            glVertex2f(724.000, -1718.833);
            glVertex2f(721.833, -1725.833);
            glVertex2f(718.500, -1736.667);
            glVertex2f(713.667, -1749.833);
            glVertex2f(711.333, -1755.667);
            glVertex2f(698.750, -1767.000);
            glVertex2f(688.500, -1777.250);
            glVertex2f(677.000, -1789.000);
            glVertex2f(667.750, -1797.750);
            glVertex2f(694.500, -1771.250);
            glVertex2f(702.500, -1762.250);
            glVertex2f(710.750, -1755.750);
            glVertex2f(722.500, -1745.000);
            glVertex2f(747.000, -1727.667);
            glVertex2f(767.667, -1716.333);
            glVertex2f(784.000, -1710.667);
            glVertex2f(799.333, -1708.667);
            glVertex2f(834.000, -1708.333);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.2);
            glVertex2f(847.667, -1708.333);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.1);
            glVertex2f(859.333, -1707.333);
            glEnd();
        }
        //105
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.6);
            glVertex2f(666.000, -1233.000);
            glVertex2f(673.000, -1257.000);
            glVertex2f(687.000, -1298.000);
            glVertex2f(703.000, -1337.000);
            glVertex2f(736.500, -1385.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.8);
            glVertex2f(752.000, -1408.500);
            glVertex2f(762.750, -1434.750);
            glVertex2f(773.500, -1462.750);
            glVertex2f(782.000, -1477.750);
            glVertex2f(788.875, -1487.750);
            glVertex2f(799.250, -1498.875);
            glVertex2f(823.000, -1518.333);
            glVertex2f(843.833, -1533.333);
            glVertex2f(863.250, -1550.250);
            glVertex2f(873.333, -1561.083);
            glVertex2f(876.500, -1567.167);
            glVertex2f(879.333, -1574.833);
            glVertex2f(881.375, -1580.125);
            glVertex2f(882.375, -1586.000);
            glVertex2f(882.375, -1600.125);
            glVertex2f(880.125, -1612.000);
            glVertex2f(875.875, -1625.250);
            glVertex2f(869.000, -1638.833);
            glVertex2f(860.667, -1651.333);
            glVertex2f(851.667, -1663.000);
            glVertex2f(839.333, -1676.667);
            glVertex2f(831.667, -1687.667);
            glVertex2f(824.167, -1697.167);
            glVertex2f(818.667, -1703.500);
            glVertex2f(813.333, -1708.667);
            glEnd();
        }
        //106
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.1);
            glVertex2f(635.500, -1173.500);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.2);
            glVertex2f(649.250, -1177.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.3);
            glVertex2f(663.500, -1185.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.4);
            glVertex2f(677.750, -1195.250);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.6);
            glVertex2f(698.333, -1211.000);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glVertex2f(710.667, -1223.333);
            glVertex2f(725.333, -1246.667);
            glVertex2f(734.000, -1263.167);
            glVertex2f(739.667, -1278.000);
            glVertex2f(749.000, -1308.750);
            glVertex2f(755.250, -1327.500);
            glVertex2f(760.000, -1340.750);
            glVertex2f(764.000, -1357.000);
            glVertex2f(766.250, -1365.750);
            glVertex2f(765.500, -1371.333);
            glVertex2f(763.917, -1378.167);
            glVertex2f(760.500, -1390.917);
            glVertex2f(757.750, -1402.000);
            glVertex2f(756.000, -1414.500);
            glEnd();
        }
        //107
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.6);
            glBegin(GL_LINE_STRIP);
            glVertex2f(703.000, -1450.000);
            glVertex2f(717.500, -1460.000);
            glVertex2f(731.000, -1471.500);
            glVertex2f(746.000, -1490.000);
            glVertex2f(761.000, -1507.500);
            glVertex2f(773.500, -1524.000);
            glVertex2f(791.500, -1545.000);
            glVertex2f(802.500, -1556.000);
            glVertex2f(812.000, -1570.500);
            glVertex2f(817.667, -1579.000);
            glVertex2f(820.000, -1587.000);
            glVertex2f(820.667, -1592.333);
            glVertex2f(820.667, -1600.667);
            glVertex2f(818.333, -1612.333);
            glVertex2f(814.000, -1629.000);
            glVertex2f(810.000, -1637.667);
            glVertex2f(804.333, -1645.667);
            glVertex2f(789.333, -1659.000);
            glVertex2f(781.333, -1665.333);
            glVertex2f(783.667, -1659.333);
            glVertex2f(791.500, -1648.000);
            glVertex2f(797.875, -1638.375);
            glVertex2f(802.125, -1628.250);
            glVertex2f(805.750, -1615.625);
            glVertex2f(806.625, -1609.000);
            glVertex2f(806.750, -1602.000);
            glVertex2f(804.125, -1594.000);
            glVertex2f(798.750, -1583.875);
            glVertex2f(790.625, -1572.000);
            glVertex2f(783.875, -1562.875);
            glVertex2f(773.000, -1550.250);
            glVertex2f(760.375, -1535.750);
            glVertex2f(740.500, -1513.250);
            glVertex2f(727.750, -1498.000);
            glVertex2f(714.750, -1483.250);
            glVertex2f(706.000, -1471.750);
            glVertex2f(703.000, -1467.250);
            glEnd();
        }
        //108
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.8);
            glBegin(GL_LINE_STRIP);
            glVertex2f(761.500, -1683.000);
            glVertex2f(774.000, -1671.500);
            glVertex2f(779.000, -1661.000);
            glVertex2f(784.500, -1646.000);
            glVertex2f(788.000, -1632.500);
            glVertex2f(789.000, -1616.500);
            glVertex2f(786.500, -1607.500);
            glVertex2f(782.500, -1597.500);
            glVertex2f(775.000, -1585.000);
            glVertex2f(768.000, -1573.500);
            glVertex2f(758.000, -1562.500);
            glVertex2f(745.000, -1546.000);
            glVertex2f(731.500, -1531.500);
            glVertex2f(717.000, -1515.000);
            glVertex2f(707.333, -1503.667);
            glVertex2f(693.333, -1484.000);
            glVertex2f(687.333, -1476.000);
            glVertex2f(678.000, -1456.667);
            glVertex2f(667.333, -1437.667);
            glVertex2f(661.000, -1426.667);
            glVertex2f(656.333, -1418.667);
            glVertex2f(650.000, -1407.333);
            glVertex2f(642.000, -1394.000);
            glVertex2f(636.667, -1385.333);
            glVertex2f(632.000, -1378.667);
            glVertex2f(625.333, -1359.667);
            glVertex2f(635.333, -1386.333);
            glVertex2f(642.000, -1406.333);
            glVertex2f(653.667, -1430.667);
            glVertex2f(660.000, -1445.000);
            glVertex2f(666.667, -1460.667);
            glVertex2f(676.000, -1483.000);
            glVertex2f(686.667, -1503.667);
            glVertex2f(697.000, -1523.333);
            glVertex2f(707.667, -1540.333);
            glVertex2f(720.333, -1557.667);
            glVertex2f(736.333, -1577.333);
            glVertex2f(751.000, -1591.333);
            glVertex2f(760.250, -1601.500);
            glVertex2f(763.250, -1607.000);
            glVertex2f(765.000, -1611.750);
            glVertex2f(765.250, -1615.250);
            glVertex2f(763.750, -1621.500);
            glVertex2f(760.750, -1628.000);
            glVertex2f(755.250, -1645.750);
            glVertex2f(751.500, -1660.000);
            glVertex2f(743.500, -1686.000);
            glVertex2f(739.500, -1697.250);
            glVertex2f(737.000, -1700.500);
            glVertex2f(725.000, -1717.750);
            glVertex2f(727.250, -1708.750);
            glVertex2f(730.250, -1700.750);
            glVertex2f(734.000, -1691.500);
            glVertex2f(737.000, -1682.250);
            glVertex2f(739.500, -1673.250);
            glVertex2f(742.000, -1661.250);
            glVertex2f(742.750, -1649.750);
            glVertex2f(741.500, -1619.500);
            glVertex2f(740.250, -1611.000);
            glVertex2f(734.000, -1601.000);
            glVertex2f(726.250, -1591.250);
            glVertex2f(719.500, -1583.750);
            glVertex2f(712.750, -1574.750);
            glVertex2f(704.250, -1561.500);
            glVertex2f(696.250, -1549.250);
            glVertex2f(689.500, -1537.500);
            glVertex2f(681.500, -1523.000);
            glVertex2f(674.000, -1505.833);
            glVertex2f(666.833, -1490.500);
            glVertex2f(661.167, -1480.667);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(656.500, -1472.333);
            glVertex2f(649.833, -1458.167);
            glEnd();
        }
        //109
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(722.667, -1623.667);
            glVertex2f(725.333, -1646.333);
            glVertex2f(726.000, -1676.333);
            glVertex2f(724.667, -1709.000);
            glVertex2f(718.667, -1738.000);
            glVertex2f(710.333, -1757.000);
            glEnd();
        }
        //110
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.6);
            glBegin(GL_LINE_STRIP);
            glVertex2f(700.333, -1627.333);
            glVertex2f(704.667, -1641.000);
            glVertex2f(707.667, -1656.333);
            glVertex2f(710.333, -1670.333);
            glVertex2f(712.667, -1690.333);
            glVertex2f(714.333, -1705.333);
            glVertex2f(713.667, -1713.667);
            glVertex2f(710.833, -1721.000);
            glVertex2f(705.500, -1727.833);
            glEnd();
        }
        //111
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(697.667, -1764.667);
            glVertex2f(698.667, -1751.000);
            glVertex2f(700.667, -1741.667);
            glVertex2f(701.333, -1735.000);
            glVertex2f(701.000, -1729.000);
            glVertex2f(700.833, -1721.000);
            glVertex2f(698.500, -1708.500);
            glVertex2f(695.167, -1692.500);
            glVertex2f(687.833, -1663.000);
            glVertex2f(677.250, -1625.750);
            glVertex2f(672.000, -1610.750);
            glVertex2f(664.000, -1585.000);
            glVertex2f(654.500, -1556.500);
            glVertex2f(647.250, -1537.500);
            glVertex2f(639.500, -1519.250);
            glVertex2f(628.667, -1498.667);
            glVertex2f(622.000, -1486.000);
            glEnd();
        }
        //112
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(584.000, -1547.000);
            glVertex2f(583.000, -1593.250);
            glVertex2f(582.667, -1605.333);
            glVertex2f(580.333, -1627.000);
            glVertex2f(579.333, -1638.667);
            glVertex2f(579.333, -1650.667);
            glVertex2f(579.500, -1663.333);
            glVertex2f(580.667, -1677.167);
            glVertex2f(582.667, -1690.000);
            glVertex2f(584.500, -1697.167);
            glVertex2f(588.000, -1703.833);
            glVertex2f(593.333, -1712.167);
            glVertex2f(601.333, -1724.167);
            glVertex2f(608.833, -1734.167);
            glVertex2f(616.833, -1743.167);
            glVertex2f(622.167, -1750.167);
            glVertex2f(627.333, -1756.333);
            glVertex2f(633.333, -1763.833);
            glVertex2f(634.625, -1765.500);
            glVertex2f(640.500, -1772.000);
            glVertex2f(644.125, -1775.875);
            glVertex2f(646.875, -1778.750);
            glVertex2f(650.875, -1782.000);
            glVertex2f(654.333, -1785.917);
            glVertex2f(655.417, -1789.000);
            glVertex2f(656.833, -1792.667);
            glVertex2f(658.417, -1796.167);
            glVertex2f(660.000, -1798.417);
            glVertex2f(668.875, -1789.125);
            glVertex2f(669.750, -1783.250);
            glVertex2f(666.500, -1774.500);
            glVertex2f(662.000, -1761.750);
            glVertex2f(655.500, -1746.250);
            glVertex2f(648.500, -1730.250);
            glVertex2f(641.250, -1715.250);
            glVertex2f(635.750, -1703.250);
            glVertex2f(629.750, -1689.000);
            glVertex2f(627.000, -1680.500);
            glVertex2f(625.000, -1673.500);
            glEnd();
        }
        //113
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(686.667, -1740.333);
            glVertex2f(684.667, -1728.333);
            glVertex2f(679.667, -1705.667);
            glVertex2f(672.667, -1681.000);
            glVertex2f(665.333, -1654.333);
            glVertex2f(658.667, -1635.000);
            glVertex2f(638.500, -1576.000);
            glVertex2f(629.250, -1550.750);
            glVertex2f(620.500, -1526.500);
            glVertex2f(613.750, -1509.750);
            glVertex2f(607.750, -1490.750);
            glVertex2f(603.667, -1474.167);
            glVertex2f(599.000, -1453.500);
            glVertex2f(596.833, -1437.000);
            glVertex2f(594.000, -1394.333);
            glVertex2f(594.500, -1365.667);
            glEnd();
        }
        //114
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(640.500, -1667.000);
            glVertex2f(657.500, -1705.000);
            glVertex2f(667.500, -1726.500);
            glVertex2f(679.500, -1754.000);
            glEnd();
        }
        //115
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(644.500, -1751.333);
            glVertex2f(638.500, -1744.333);
            glVertex2f(632.167, -1735.333);
            glVertex2f(623.667, -1723.500);
            glVertex2f(617.333, -1713.667);
            glVertex2f(611.667, -1701.667);
            glVertex2f(607.667, -1689.333);
            glVertex2f(605.333, -1679.333);
            glVertex2f(604.333, -1670.333);
            glVertex2f(604.333, -1659.333);
            glVertex2f(604.833, -1645.667);
            glVertex2f(605.333, -1636.667);
            glVertex2f(605.167, -1626.500);
            glVertex2f(605.500, -1619.000);
            glVertex2f(605.667, -1610.500);
            glVertex2f(606.167, -1605.333);
            glVertex2f(606.000, -1597.333);
            glVertex2f(603.500, -1586.000);
            glEnd();
        }
        //116
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.8);
            glBegin(GL_LINE_STRIP);
            glVertex2f(559.000, -1692.250);
            glVertex2f(564.500, -1704.000);
            glVertex2f(571.750, -1714.500);
            glVertex2f(582.250, -1727.750);
            glVertex2f(591.000, -1738.250);
            glVertex2f(603.000, -1750.750);
            glVertex2f(613.500, -1761.750);
            glVertex2f(625.000, -1770.000);
            glVertex2f(637.000, -1775.750);
            glVertex2f(644.000, -1777.000);
            glVertex2f(635.750, -1769.375);
            glVertex2f(630.375, -1764.500);
            glVertex2f(625.250, -1758.875);
            glVertex2f(620.250, -1754.375);
            glVertex2f(614.000, -1749.625);
            glVertex2f(605.500, -1743.750);
            glVertex2f(597.000, -1738.875);
            glVertex2f(589.125, -1735.625);
            glEnd();
        }
        //117
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glBegin(GL_LINE_STRIP);
            glVertex2f(583.500, -1790.625);
            glVertex2f(596.250, -1790.500);
            glVertex2f(609.625, -1791.250);
            glVertex2f(618.500, -1792.125);
            glVertex2f(626.875, -1794.500);
            glEnd();
        }
        //118
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glBegin(GL_LINE_STRIP);
            glVertex2f(608.250, -1771.375);
            glVertex2f(614.000, -1775.500);
            glVertex2f(622.500, -1779.875);
            glVertex2f(630.625, -1783.000);
            glVertex2f(640.250, -1785.375);
            glVertex2f(647.000, -1787.750);
            glVertex2f(653.000, -1791.000);
            glVertex2f(655.667, -1793.167);
            glVertex2f(658.333, -1796.667);
            glVertex2f(658.833, -1801.000);
            glEnd();
        }
        //119
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(668.250, -1790.000);
            glVertex2f(674.250, -1782.750);
            glVertex2f(681.750, -1771.250);
            glVertex2f(688.250, -1759.750);
            glVertex2f(693.750, -1752.000);
            glVertex2f(698.750, -1744.750);
            glEnd();
        }
        //120
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(702.250, -1767.750);
            glVertex2f(711.250, -1762.750);
            glVertex2f(721.250, -1757.500);
            glVertex2f(730.500, -1753.250);
            glVertex2f(741.750, -1749.500);
            glVertex2f(755.750, -1745.000);
            glVertex2f(778.333, -1739.000);
            glEnd();
        }
        //121
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(706.250, -1777.750);
            glVertex2f(711.250, -1776.750);
            glVertex2f(716.750, -1776.750);
            glVertex2f(725.750, -1777.250);
            glVertex2f(735.250, -1779.250);
            glVertex2f(744.500, -1781.000);
            glVertex2f(759.000, -1783.750);
            glVertex2f(769.250, -1787.500);
            glVertex2f(775.250, -1791.250);
            glVertex2f(781.000, -1796.000);
            glVertex2f(784.500, -1801.500);
            glEnd();
        }
        //122
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(670.250, -1796.250);
            glVertex2f(679.000, -1792.500);
            glVertex2f(689.250, -1788.500);
            glVertex2f(697.750, -1786.000);
            glVertex2f(707.250, -1785.000);
            glVertex2f(718.250, -1785.000);
            glVertex2f(729.250, -1786.000);
            glVertex2f(736.000, -1787.000);
            glVertex2f(744.000, -1789.250);
            glVertex2f(752.250, -1792.250);
            glEnd();
        }
        //123
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.7);
            glBegin(GL_LINE_STRIP);
            glVertex2f(703.333, -1747.333);
            glVertex2f(709.333, -1737.333);
            glVertex2f(717.333, -1726.333);
            glVertex2f(725.000, -1718.000);
            glVertex2f(736.000, -1704.667);
            glVertex2f(744.000, -1698.667);
            glVertex2f(749.333, -1689.667);
            glVertex2f(757.333, -1675.000);
            glVertex2f(765.000, -1661.333);
            glVertex2f(771.000, -1647.000);
            glVertex2f(781.000, -1623.333);
            glEnd();
        }
        //130
        {
            double vertices[][2] = {
                    { 985.750, -1708.500 },
                    { 975.000, -1705.500 },
                    { 967.125, -1703.375 },
                    { 964.250, -1699.000 },
                    { 959.750, -1684.625 },
                    { 958.000, -1665.000 },
                    { 957.500, -1649.875 },
                    { 957.333, -1612.167 },
                    { 957.833, -1600.333 },
                    { 962.333, -1586.500 },
                    { 969.500, -1564.500 },
                    { 989.250, -1504.000 },
                    { 989.000, -1525.333 },
                    { 986.667, -1545.333 },
                    { 982.000, -1566.000 },
                    { 983.000, -1580.500 },
                    { 976.000, -1607.250 },
                    { 975.750, -1617.250 },
                    { 975.250, -1619.250 },
                    { 981.500, -1623.500 },
                    { 986.250, -1624.250 },
                    { 984.750, -1664.000 },
                    { 985.500, -1668.250 },
                    { 988.583, -1671.833 },
                    { 992.833, -1674.917 },
                    { 1000.333, -1677.667 },
                    { 1002.417, -1677.083 },
                    { 1000.667, -1616.333 },
                    { 1017.000, -1698.333 },
                    { 1012.500, -1697.167 },
                    { 1007.000, -1697.667 },
                    { 1002.000, -1699.000 },
                    { 995.833, -1702.500 },
                    { 991.000, -1705.500 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 157, 83, 43,0.8,true,111,58,35,0.8);
        }
        //131
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.4);
            glVertex2f(959.000, -1471.667);
            glVertex2f(957.333, -1489.667);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.6);
            glVertex2f(956.667, -1508.000);
            glVertex2f(958.000, -1523.333);
            glVertex2f(959.667, -1535.000);
            glVertex2f(960.333, -1551.667);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glVertex2f(959.333, -1573.333);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.2);
            glVertex2f(958.000, -1594.000);
            glEnd();
        }
        //132
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glBegin(GL_LINE_STRIP);
            glVertex2f(948.000, -1609.333);
            glVertex2f(942.000, -1624.333);
            glVertex2f(935.000, -1643.000);
            glVertex2f(928.667, -1658.667);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.2);
            glVertex2f(923.667, -1677.000);
            glEnd();
        }
        //133
        {
            glLineWidth(1);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.5);
            glBegin(GL_LINE_STRIP);
            glVertex2f(960.833, -1442.000);
            glVertex2f(959.000, -1449.667);
            glVertex2f(958.333, -1455.167);
            glVertex2f(957.667, -1461.833);
            glVertex2f(954.833, -1470.000);
            glVertex2f(951.667, -1476.833);
            glEnd();
        }
        //138
        {
            double vertices[][2] = {
                    { 798.000, -1482.000 },
                    { 798.000, -1469.667 },
                    { 801.500, -1458.167 },
                    { 806.833, -1441.500 },
                    { 813.167, -1423.667 },
                    { 815.167, -1419.000 },
                    { 819.000, -1415.167 },
                    { 820.333, -1409.833 },
                    { 820.000, -1420.167 },
                    { 813.833, -1440.500 },
                    { 808.000, -1457.333 },
                    { 803.167, -1470.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 154, 84, 50,0.7);
        }
        //139
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.05);
            glVertex2f(1134.250, -1826.750);
            glColor4f(62/255.0f, 24/255.0f, 9/255.0f, 0.3);
            glVertex2f(1133.500, -1834.250);
            glVertex2f(1132.500, -1845.750);
            glVertex2f(1132.167, -1851.667);
            glVertex2f(1132.250, -1856.750);
            glVertex2f(1133.000, -1860.250);
            glEnd();
        }
    }
    //elGloves
    {
        double vertices[][2]={
                {1133.33 , -1827.17},
                {1149.17 , -1823.67},
                {1165.17 , -1816.33},
                {1180.67 , -1810.17},
                {1204.33 , -1799.67},
                {1223.67 , -1800.67},
                {1237.33 , -1800.67},
                {1243.67 , -1800.33},
                {1262.25 , -1793.75},
                {1279 , -1786.5},
                {1289.5 , -1780.75},
                {1292.25 , -1778.5},
                {1297.5 , -1774.75},
                {1300 , -1772.5},
                {1304.25 , -1770},
                {1308.5 , -1768.25},
                {1314.25 , -1766.25},
                {1316.5 , -1765.75},
                {1320.25 , -1765.5},
                {1324.25 , -1766},
                {1326.83 , -1768.75},
                {1328.58 , -1763.25},
                {1330 , -1758.83},
                {1331.25 , -1756},
                {1332.92 , -1752.42},
                {1334 , -1749.58},
                {1334.17 , -1748.17},
                {1333.33 , -1745.92},
                {1331.42 , -1741.58},
                {1330.08 , -1739.5},
                {1329 , -1738.42},
                {1330.5 , -1738.42},
                {1331.5 , -1735.92},
                {1332.58 , -1731.83},
                {1332.75 , -1729.5},
                {1332.42 , -1726.42},
                {1331.42 , -1723.25},
                {1329.5 , -1720.17},
                {1327 , -1716.5},
                {1323.58 , -1711.5},
                {1323.67 , -1707.92},
                {1323.67 , -1704.58},
                {1323.5 , -1701.67},
                {1322.83 , -1700.25},
                {1321.67 , -1698.42},
                {1321.33 , -1697.58},
                {1322.5 , -1694.62},
                {1322.75 , -1692.75},
                {1322.38 , -1689.5},
                {1321 , -1687.5},
                {1317.75 , -1684.38},
                {1315.75 , -1682.25},
                {1314 , -1681},
                {1311.75 , -1678.12},
                {1311 , -1676.38},
                {1310.25 , -1670.75},
                {1309.62 , -1665.75},
                {1307.38 , -1662.5},
                {1304.25 , -1659.75},
                {1300.5 , -1657.12},
                {1298.75 , -1656.25},
                {1298 , -1656},
                {1298.5 , -1652.25},
                {1298.5 , -1645.5},
                {1297.38 , -1637.38},
                {1295 , -1629.62},
                {1292.62 , -1625.62},
                {1288.88 , -1621},
                {1285.12 , -1617.25},
                {1284.12 , -1616.75},
                {1276.5 , -1616.38},
                {1270.75 , -1617.12},
                {1261.25 , -1618.12},
                {1252.75 , -1619.12},
                {1249.38 , -1620.12},
                {1242.62 , -1621},
                {1237.62 , -1621.88},
                {1235.62 , -1622.25},
                {1232.83 , -1625},
                {1228.42 , -1632.17},
                {1223.33 , -1638.83},
                {1215.08 , -1646.58},
                {1185 , -1667.67},
                {1178.38 , -1673.12},
                {1178 , -1673.75},
                {1178.12 , -1676.12},
                {1177.88 , -1682.88},
                {1177.12 , -1688.62},
                {1174.75 , -1697.5},
                {1171.12 , -1706.25},
                {1166.5 , -1713.62},
                {1165 , -1715.12},
                {1160.67 , -1712.33},
                {1157.17 , -1710},
                {1155 , -1709.5},
                {1152.33 , -1709.58},
                {1149.42 , -1711.75},
                {1146.33 , -1714.83},
                {1144.75 , -1715.5},
                {1141.58 , -1713.17},
                {1140.42 , -1712.08},
                {1138.92 , -1712.58},
                {1136.92 , -1713.42},
                {1126.75 , -1720.33},
                {1123.38 , -1717.62},
                {1120.75 , -1716.38},
                {1116.12 , -1713.62},
                {1113 , -1711.62},
                {1112 , -1710.62},
                {1114.25 , -1703.75},
                {1116 , -1695.75},
                {1117 , -1685},
                {1117.5 , -1680},
                {1124.5 , -1676},
                {1135.75 , -1668.75},
                {1142 , -1664.17},
                {1147.67 , -1658.25},
                {1152.42 , -1652.08},
                {1160.42 , -1642},
                {1167 , -1635.58},
                {1173 , -1632},
                {1069.5 , -1472},
                {1065.33 , -1474.5},
                {1065 , -1481.17},
                {1065.67 , -1488.5},
                {1067 , -1496.83},
                {1070.17 , -1507.17},
                {1070.5 , -1512.5},
                {1069.83 , -1521.83},
                {1065 , -1537.17},
                {1060.12 , -1551.88},
                {1056.62 , -1563.88},
                {1053 , -1574.88},
                {1051.38 , -1580.25},
                {1050.88 , -1584.88},
                {1051 , -1591.88},
                {1051.75 , -1595.75},
                {1054.5 , -1604.12},
                {1056 , -1609.38},
                {1057 , -1613.38},
                {1056.12 , -1616.75},
                {1050 , -1620.75},
                {1051.62 , -1627.12},
                {1050.33 , -1630.33},
                {1026.33 , -1645.83},
                {1025.17 , -1645.67},
                {1023.67 , -1644.5},
                {1021.17 , -1636.33},
                {1020.17 , -1629.5},
                {1019 , -1621.5},
                {1017.67 , -1614.5},
                {1016.5 , -1607},
                {1014.67 , -1600.67},
                {1011 , -1593.17},
                {1008.17 , -1588.5},
                {1004.25 , -1582.5},
                {1002.42 , -1579.58},
                {1000.67 , -1575.75},
                {999.917 , -1574.92},
                {999.167 , -1574.33},
                {998.333 , -1574.67},
                {997.667 , -1575.75},
                {996.083 , -1577.92},
                {995.083 , -1579.83},
                {994.25 , -1581},
                {994.083 , -1581.92},
                {993.75 , -1582.25},
                {992.583 , -1580.67},
                {992 , -1578.75},
                {992.083 , -1576.25},
                {993.333 , -1574.42},
                {995.083 , -1571.42},
                {999.833 , -1567.33},
                {1001.83 , -1567.17},
                {1003.75 , -1567.42},
                {1005.33 , -1568.08},
                {1003 , -1565.42},
                {1001.5 , -1564.42},
                {1000.33 , -1563.67},
                {998 , -1563},
                {995.917 , -1562.75},
                {993.417 , -1563.17},
                {990.25 , -1565.08},
                {988.083 , -1568},
                {986.083 , -1572.67},
                {984.5 , -1578.08},
                {982.5 , -1583.17},
                {976.417 , -1606.33},
                {975.917 , -1607.42},
                {975.417 , -1619.08},
                {975.417 , -1619.67},
                {980.5 , -1622.92},
                {981.75 , -1623.5},
                {985.75 , -1624.08},
                {985 , -1665.5},
                {985.833 , -1669},
                {990.333 , -1674},
                {996.5 , -1677.17},
                {1000.67 , -1678},
                {1002.33 , -1677.5},
                {1000.83 , -1617.5},
                {1004.33 , -1644.17},
                {1005.5 , -1656.33},
                {1006.33 , -1667.5},
                {1008.83 , -1680},
                {1012 , -1691.83},
                {1014.67 , -1697.83},
                {1018.5 , -1699.17},
                {1023.17 , -1703.33},
                {1027.17 , -1706.83},
                {1033.67 , -1711.33},
                {1043.33 , -1715.67},
                {1052.83 , -1718.17},
                {1061.83 , -1718.67},
                {1074.83 , -1718.5},
                {1088.17 , -1715.67},
                {1095.5 , -1713},
                {1098.5 , -1711.83},
                {1104.33 , -1711.33},
                {1109.5 , -1711.83},
                {1112.5 , -1713.33},
                {1119 , -1718.17},
                {1125 , -1725.33},
                {1130.5 , -1732.83},
                {1140.25 , -1750.5},
                {1141.25 , -1756.12},
                {1140.88 , -1763.25},
                {1139 , -1777.88},
                {1136.62 , -1797.75},
                {1135 , -1812},
                {1134.5 , -1820.33}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 92, 39, 17);
    }
    //fingers
    {
        double vertices[][2]={
                {1124.75 , -1485.25},
                {1139 , -1472},
                {1146 , -1466.5},
                {1155.5 , -1459.75},
                {1161.5 , -1457},
                {1164.75 , -1456.75},
                {1169 , -1457.5},
                {1174.75 , -1463.75},
                {1179.5 , -1472.5},
                {1180.75 , -1476.75},
                {1181 , -1480},
                {1179.75 , -1485.75},
                {1172.75 , -1502.25},
                {1181.25 , -1500.5},
                {1189 , -1499.25},
                {1192.5 , -1500},
                {1197 , -1502.75},
                {1199 , -1506.25},
                {1200.17 , -1508.67},
                {1201 , -1512.83},
                {1201 , -1515.83},
                {1201.25 , -1521.58},
                {1200.83 , -1526.5},
                {1200 , -1531},
                {1199.25 , -1533.58},
                {1201.67 , -1534.5},
                {1204.17 , -1536.5},
                {1206.17 , -1540.17},
                {1207.83 , -1545.17},
                {1208.17 , -1551},
                {1207.5 , -1556.67},
                {1206.83 , -1563.67},
                {1205.5 , -1568.5},
                {1204.83 , -1570.67},
                {1209.5 , -1571},
                {1214.83 , -1572.33},
                {1220 , -1575.5},
                {1222.67 , -1577.83},
                {1224.33 , -1580.5},
                {1224.83 , -1583},
                {1224.88 , -1597.25},
                {1224 , -1604.25},
                {1221.75 , -1610.25},
                {1219.5 , -1613.38},
                {1215 , -1617.38},
                {1210.12 , -1612.38},
                {1194.25 , -1616.5},
                {1111 , -1501.5}
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 92, 39, 17);
    }
    //hand's middle shadow
    {
        double vertices[][2] = {
                { 1103.333, -1529.333 },
                { 1090.667, -1548.333 },
                { 1083.333, -1569.333 },
                { 1078.000, -1588.333 },
                { 1077.333, -1609.667 },
                { 1082.333, -1627.667 },
                { 1094.000, -1666.333 },
                { 1109.333, -1658.333 },
                { 1121.333, -1650.333 },
                { 1134.000, -1640.333 },
                { 1147.333, -1630.333 },
                { 1162.333, -1617.667 },
                { 1136.333, -1579.667 },
                { 1117.333, -1550.667 }
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 74, 36, 17,0.18);
    }
    //elLight beta3 elHand el4emal
    {
        double vertices[][2] = {
                {1056.000, -1716.333},
                {1046.667, -1714.667},
                {1037.000, -1711.000},
                {1028.667, -1706.667},
                {1024.000, -1702.667},
                {1017.333, -1697.667},
                {1013.667, -1679.667},
                {1011.000, -1660.333},
                {1014.667, -1652.667},
                {1026.667, -1648.333},
                {1039.667, -1645.667},
                {1059.333, -1646.667},
                {1079.667, -1653.333},
                {1096.333, -1660.000},
                {1107.333, -1667.667},
                {1113.333, -1672.667},
                {1117.000, -1679.000},
                {1116.000, -1687.333},
                {1114.333, -1699.333},
                {1111.333, -1708.667},
                {1110.000, -1711.333},
                {1100.000, -1710.000},
                {1092.667, -1711.667},
                {1083.333, -1714.333},
                {1075.667, -1716.333},
                {1068.000, -1716.333}

        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size,145,69,34,1 ,true,92, 39, 17,0.1);
    }
    //light elfingers
    {
        //144
        {
            glColor4f(119/255.0f, 57/255.0f, 26/255.0f, 1);
            glBegin(GL_POLYGON);
            glVertex2f(1177.500, -1482.125);
            glVertex2f(1173.625, -1468.250);
            glVertex2f(1161.500, -1459.750);
            glColor4f(92/255.0f, 39/255.0f, 17/255.0f, 1);
            glVertex2f(1137.375, -1475.375);
            glVertex2f(1167.500, -1504.000);
            glEnd();
        }
        //145
        {
            glBegin(GL_POLYGON);
            glColor4f(119/255.0f, 57/255.0f, 26/255.0f, 1);
            glVertex2f(1198.125, -1519.875);
            glVertex2f(1196.000, -1510.750);
            glVertex2f(1178.750, -1502.250);
            glColor4f(92/255.0f, 39/255.0f, 17/255.0f, 1);
            glVertex2f(1162.875, -1509.375);
            glVertex2f(1190.500, -1547.250);
            glEnd();
        }
        //146
        {
            glBegin(GL_POLYGON);
            glColor4f(119/255.0f, 57/255.0f, 26/255.0f, 1);
            glVertex2f(1205.333, -1561.667);
            glVertex2f(1205.500, -1546.833);
            glVertex2f(1189.000, -1539.333);
            glColor4f(92/255.0f, 39/255.0f, 17/255.0f, 1);
            glVertex2f(1178.167, -1543.833);
            glVertex2f(1197.000, -1577.500);
            glEnd();
        }
        //174
        {
            glBegin(GL_POLYGON);
            glColor4f(119/255.0f, 57/255.0f, 26/255.0f, 1);
            glVertex2f(1222.167, -1602.667);
            glVertex2f(1222.833, -1589.333);
            glVertex2f(1211.167, -1574.667);
            glColor4f(92/255.0f, 39/255.0f, 17/255.0f, 1);
            glVertex2f(1195.500, -1580.833);
            glVertex2f(1212.500, -1615.000);
            glEnd();
        }

        //148
        {
            double vertices[][2] = {
                    { 1143.417, -1470.667 },
                    { 1147.333, -1469.667 },
                    { 1152.833, -1468.167 },
                    { 1160.667, -1466.667 },
                    { 1164.833, -1466.167 },
                    { 1168.667, -1467.167 },
                    { 1171.667, -1470.000 },
                    { 1173.000, -1473.500 },
                    { 1173.833, -1479.500 },
                    { 1172.667, -1487.667 },
                    { 1172.000, -1494.167 },
                    { 1172.333, -1497.667 },
                    { 1174.667, -1494.500 },
                    { 1178.333, -1486.000 },
                    { 1179.750, -1480.417 },
                    { 1179.250, -1475.417 },
                    { 1176.500, -1468.583 },
                    { 1170.833, -1461.167 },
                    { 1167.083, -1458.583 },
                    { 1161.167, -1458.167 },
                    { 1157.167, -1459.833 },
                    { 1150.417, -1464.417 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 212, 134, 64);
        }
        //149
        {
            glColor4f(212/255.0f,134 /255.0f, 64/255.0f, 0.7);
            glBegin(GL_POLYGON);
            glVertex2f(1146.000, -1505.375);
            glVertex2f(1161.875, -1501.750);
            glVertex2f(1161.875, -1497.125);
            glEnd();
        }
        //150
        {
            double vertices[][2] = {
                    { 1148.375, -1516.625 },
                    { 1153.000, -1513.250 },
                    { 1154.625, -1512.000 },
                    { 1189.500, -1511.375 },
                    { 1192.250, -1512.125 },
                    { 1193.625, -1514.000 },
                    { 1194.750, -1516.125 },
                    { 1194.000, -1533.625 },
                    { 1199.000, -1532.625 },
                    { 1200.125, -1528.500 },
                    { 1200.375, -1519.375 },
                    { 1199.625, -1510.625 },
                    { 1198.375, -1507.000 },
                    { 1193.875, -1501.875 },
                    { 1190.375, -1500.500 },
                    { 1181.750, -1501.125 },
                    { 1172.000, -1503.250 },
                    { 1161.625, -1505.250 },
                    { 1157.750, -1506.125 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 212, 134, 64);
        }
        //151
        {
            double vertices[][2] = {
                    { 1199.500, -1550.250 },
                    { 1166.083, -1549.750 },
                    { 1168.833, -1547.250 },
                    { 1172.333, -1544.000 },
                    { 1176.583, -1541.500 },
                    { 1181.750, -1539.333 },
                    { 1188.333, -1537.500 },
                    { 1193.500, -1535.833 },
                    { 1197.083, -1534.917 },
                    { 1200.167, -1535.250 },
                    { 1203.333, -1538.083 },
                    { 1205.333, -1541.250 },
                    { 1206.500, -1545.750 },
                    { 1206.750, -1549.667 },
                    { 1206.833, -1557.250 },
                    { 1205.500, -1564.750 },
                    { 1203.750, -1569.667 },
                    { 1200.500, -1569.833 },
                    { 1201.500, -1566.167 },
                    { 1201.917, -1561.333 },
                    { 1201.583, -1556.250 },
                    { 1200.917, -1551.750 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 212, 134, 64);
        }
        //152
        {
            double vertices[][2] = {
                    { 1188.250, -1578.250 },
                    { 1191.333, -1575.250 },
                    { 1194.583, -1573.333 },
                    { 1198.250, -1571.833 },
                    { 1201.667, -1571.417 },
                    { 1205.000, -1571.417 },
                    { 1209.417, -1572.250 },
                    { 1212.417, -1573.000 },
                    { 1216.250, -1574.750 },
                    { 1219.417, -1576.667 },
                    { 1221.500, -1578.917 },
                    { 1223.333, -1581.167 },
                    { 1224.083, -1582.750 },
                    { 1223.917, -1597.500 },
                    { 1222.917, -1605.417 },
                    { 1220.917, -1610.167 },
                    { 1218.250, -1613.500 },
                    { 1215.000, -1616.333 },
                    { 1211.417, -1612.667 },
                    { 1214.500, -1610.000 },
                    { 1217.750, -1606.083 },
                    { 1219.417, -1603.000 },
                    { 1220.167, -1600.250 },
                    { 1220.417, -1597.417 },
                    { 1220.500, -1594.750 },
                    { 1220.250, -1592.500 },
                    { 1219.917, -1590.333 },
                    { 1218.833, -1588.583 },
                    { 1217.083, -1587.417 },
                    { 1213.917, -1586.083 },
                    { 1209.583, -1585.583 },
                    { 1206.833, -1585.750 },
                    { 1203.250, -1586.083 },
                    { 1199.500, -1586.083 },
                    { 1194.333, -1584.000 },
                    { 1191.917, -1582.000 },
                    { 1189.750, -1580.333 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 212, 134, 64);
        }
        //elPoint light
        {
            glPointSize(1);
            glColor4f(93/255.0f,48/255.0f,28/255.0f,1);
            glBegin(GL_POINTS);
            glVertex2d(1176,-1603);
            glEnd();
        }
        //elLine light 153
        {
            glLineWidth(1);
            glColor4f(107/255.0f, 69/255.0f, 46/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(1169.375, -1609.000);
            glVertex2f(1166.250, -1611.750);
            glVertex2f(1163.875, -1614.000);
            glEnd();
        }

        //154
        {
            double vertices[][2] = {
                    { 1256.667, -1639.833 },
                    { 1253.167, -1640.000 },
                    { 1248.333, -1642.500 },
                    { 1241.833, -1646.083 },
                    { 1236.500, -1649.000 },
                    { 1232.000, -1649.417 },
                    { 1226.250, -1648.917 },
                    { 1221.833, -1648.167 },
                    { 1217.250, -1647.167 },
                    { 1216.417, -1646.500 },
                    { 1220.250, -1643.583 },
                    { 1223.333, -1641.250 },
                    { 1226.500, -1637.250 },
                    { 1229.250, -1633.667 },
                    { 1231.750, -1629.083 },
                    { 1234.167, -1625.667 },
                    { 1235.583, -1624.083 },
                    { 1237.000, -1623.583 },
                    { 1238.833, -1623.000 },
                    { 1243.083, -1622.667 },
                    { 1244.917, -1622.417 },
                    { 1231.417, -1635.083 },
                    { 1231.167, -1636.250 },
                    { 1231.250, -1637.167 },
                    { 1232.583, -1637.500 },
                    { 1233.750, -1637.167 },
                    { 1249.250, -1621.917 },
                    { 1253.000, -1620.750 },
                    { 1265.083, -1619.500 },
                    { 1279.750, -1617.875 },
                    { 1284.125, -1618.750 },
                    { 1287.500, -1621.375 },
                    { 1291.500, -1626.188 },
                    { 1292.562, -1628.812 },
                    { 1293.625, -1631.312 },
                    { 1294.688, -1633.875 },
                    { 1295.875, -1637.812 },
                    { 1296.812, -1642.562 },
                    { 1297.375, -1648.250 },
                    { 1297.500, -1650.562 },
                    { 1297.500, -1652.875 },
                    { 1295.000, -1651.125 },
                    { 1291.938, -1649.125 },
                    { 1289.500, -1646.875 },
                    { 1288.125, -1644.938 },
                    { 1286.312, -1642.312 },
                    { 1284.938, -1640.188 },
                    { 1283.688, -1638.188 },
                    { 1282.875, -1636.438 },
                    { 1281.875, -1634.875 },
                    { 1281.188, -1633.438 },
                    { 1280.250, -1632.625 },
                    { 1279.500, -1632.500 },
                    { 1278.562, -1633.125 },
                    { 1278.750, -1634.875 },
                    { 1280.562, -1641.062 },
                    { 1282.312, -1644.250 },
                    { 1284.375, -1646.500 },
                    { 1286.812, -1649.000 },
                    { 1288.562, -1651.125 },
                    { 1291.375, -1653.062 },
                    { 1293.312, -1655.125 },
                    { 1297.833, -1657.667 },
                    { 1302.000, -1659.833 },
                    { 1305.083, -1662.667 },
                    { 1307.083, -1664.667 },
                    { 1308.417, -1666.167 },
                    { 1308.500, -1667.667 },
                    { 1308.583, -1670.750 },
                    { 1308.667, -1672.583 },
                    { 1309.792, -1675.958 },
                    { 1310.458, -1678.042 },
                    { 1311.250, -1679.542 },
                    { 1312.208, -1680.875 },
                    { 1313.458, -1681.750 },
                    { 1317.312, -1685.500 },
                    { 1321.042, -1690.000 },
                    { 1321.083, -1690.708 },
                    { 1321.125, -1692.083 },
                    { 1320.875, -1693.208 },
                    { 1320.625, -1693.875 },
                    { 1304.500, -1672.208 },
                    { 1304.375, -1670.188 },
                    { 1304.125, -1669.000 },
                    { 1303.500, -1668.250 },
                    { 1302.625, -1667.875 },
                    { 1302.062, -1667.625 },
                    { 1301.125, -1667.500 },
                    { 1300.312, -1667.875 },
                    { 1284.000, -1682.438 },
                    { 1282.625, -1683.062 },
                    { 1281.938, -1683.125 },
                    { 1282.125, -1682.500 },
                    { 1282.812, -1681.250 },
                    { 1284.688, -1679.000 },
                    { 1288.062, -1674.375 },
                    { 1290.438, -1670.375 },
                    { 1291.000, -1669.375 },
                    { 1278.250, -1656.312 },
                    { 1269.333, -1649.333 },
                    { 1265.083, -1645.833 },
                    { 1261.750, -1642.250 },
                    { 1259.083, -1640.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 212, 134, 64);
        }
        //155
        {
            double vertices[][2] = {
                    { 1322.917, -1710.667 },
                    { 1318.667, -1705.417 },
                    { 1318.083, -1703.750 },
                    { 1318.250, -1701.833 },
                    { 1318.500, -1699.917 },
                    { 1319.167, -1699.500 },
                    { 1320.167, -1699.500 },
                    { 1321.500, -1701.417 },
                    { 1322.833, -1704.583 },
                    { 1323.250, -1706.750 },
                    { 1323.083, -1713.667 },
                    { 1326.000, -1717.833 },
                    { 1330.167, -1723.417 },
                    { 1330.917, -1725.750 },
                    { 1331.500, -1729.417 },
                    { 1330.917, -1732.417 },
                    { 1330.083, -1735.833 },
                    { 1329.583, -1737.750 },
                    { 1327.333, -1735.083 },
                    { 1324.500, -1732.667 },
                    { 1321.417, -1730.500 },
                    { 1318.000, -1728.333 },
                    { 1314.833, -1726.500 },
                    { 1314.417, -1726.333 },
                    { 1318.500, -1725.833 },
                    { 1320.167, -1725.083 },
                    { 1320.750, -1722.667 },
                    { 1320.500, -1717.583 },
                    { 1320.083, -1711.250 },
                    { 1319.333, -1708.833 },
                    { 1322.833, -1713.667 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 201, 113, 47);
        }



    }
    //156
    {
        double vertices[][2] = {
                { 1129.667, -1729.000 },
                { 1136.250, -1733.250 },
                { 1142.750, -1738.750 },
                { 1147.750, -1746.000 },
                { 1153.000, -1753.500 },
                { 1155.500, -1758.000 },
                { 1157.250, -1759.500 },
                { 1159.667, -1759.083 },
                { 1164.167, -1754.917 },
                { 1164.417, -1753.000 },
                { 1159.500, -1738.000 },
                { 1158.333, -1734.000 },
                { 1157.167, -1730.000 },
                { 1156.833, -1724.583 },
                { 1155.292, -1725.583 },
                { 1153.708, -1726.500 },
                { 1151.625, -1727.042 },
                { 1148.750, -1727.208 },
                { 1147.083, -1726.625 },
                { 1145.958, -1725.542 },
                { 1144.542, -1723.583 },
                { 1144.000, -1722.500 },
                { 1143.500, -1721.292 },
                { 1143.417, -1720.708 },
                { 1143.833, -1720.750 },
                { 1145.458, -1722.292 },
                { 1146.542, -1723.500 },
                { 1148.750, -1725.000 },
                { 1151.792, -1725.000 },
                { 1154.708, -1724.125 },
                { 1158.625, -1722.833 },
                { 1161.125, -1721.208 },
                { 1163.000, -1719.708 },
                { 1164.208, -1718.500 },
                { 1155.125, -1711.083 },
                { 1153.750, -1710.917 },
                { 1145.167, -1718.375 },
                { 1139.688, -1713.812 },
                { 1128.625, -1721.625 },
                { 1126.500, -1721.667 },
                { 1124.333, -1722.000 },
                { 1127.250, -1726.500 }
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 244, 168, 87,0.9);
    }
    //157
    {
        double vertices[][2] = {
                { 1128.917, -1730.500 },
                { 1141.500, -1752.500 },
                { 1142.583, -1764.917 },
                { 1142.083, -1770.750 },
                { 1155.500, -1757.667 },
                { 1144.833, -1741.667 },
                { 1143.083, -1738.667 },
                { 1136.583, -1733.417 },
                { 1131.333, -1730.000 }
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 244, 168, 87,0.2,true,244, 168, 87,0.1);
    }

    //elfyonka elle 3and elkom
    {
        double vertices[][2] = {
                { 563.500, -1839.250 },
                { 565.250, -1843.750 },
                { 567.750, -1847.750 },
                { 571.750, -1849.750 },
                { 579.750, -1849.750 },
                { 587.750, -1846.500 },
                { 598.500, -1838.250 },
                { 602.250, -1833.000 },
                { 606.750, -1832.500 },
                { 612.000, -1833.750 },
                { 648.250, -1817.250 },
                { 648.000, -1828.750 },
                { 646.250, -1846.000 },
                { 645.750, -1856.250 },
                { 644.500, -1868.250 },
                { 643.750, -1875.750 },
                { 644.500, -1883.750 },
                { 648.250, -1887.250 },
                { 652.750, -1887.750 },
                { 656.000, -1880.000 },
                { 659.000, -1868.500 },
                { 661.500, -1852.250 },
                { 661.500, -1841.500 },
                { 657.750, -1821.250 },
                { 657.000, -1813.750 },
                { 665.333, -1826.667 },
                { 672.333, -1839.000 },
                { 677.667, -1849.667 },
                { 681.667, -1856.333 },
                { 694.500, -1873.000 },
                { 688.667, -1857.167 },
                { 681.500, -1839.500 },
                { 675.500, -1827.667 },
                { 667.833, -1814.333 },
                { 662.833, -1809.167 },
                { 667.500, -1806.167 },
                { 669.500, -1805.000 },
                { 681.833, -1811.167 },
                { 699.000, -1821.167 },
                { 709.000, -1830.333 },
                { 720.667, -1842.000 },
                { 729.833, -1852.333 },
                { 734.833, -1859.500 },
                { 734.500, -1866.667 },
                { 742.667, -1865.167 },
                { 748.167, -1862.333 },
                { 749.333, -1860.667 },
                { 743.167, -1847.167 },
                { 738.167, -1840.000 },
                { 730.500, -1830.667 },
                { 719.167, -1820.667 },
                { 707.833, -1812.667 },
                { 695.167, -1805.500 },
                { 688.000, -1802.167 },
                { 679.167, -1798.500 },
                { 673.167, -1797.333 },
                { 669.500, -1796.167 },
                { 662.667, -1801.000 },
                { 661.333, -1801.583 },
                { 660.167, -1801.083 },
                { 660.083, -1798.500 },
                { 657.500, -1802.833 },
                { 650.500, -1807.583 },
                { 641.917, -1811.083 },
                { 624.250, -1815.938 },
                { 612.938, -1819.500 },
                { 603.167, -1823.000 },
                { 595.917, -1825.583 },
                { 587.750, -1827.667 },
                { 584.833, -1828.500 },
                { 583.250, -1828.750 },
                { 572.500, -1836.833 },
                { 568.167, -1839.500 },
                { 565.917, -1839.917 }
        };
        int size = sizeof(vertices) / sizeof(vertices[0]);
        drawConcavePolygon(vertices, size, 56, 26, 16);
    }

}
void drawSkirt()
{
    //elskirt
    {
        //elLight elle fe elganb el4emal (line)
        {
            glLineWidth(2);
            glColor4f(228/255.0f, 150/255.0f, 80/255.0f, 1);
            glBegin(GL_LINE_STRIP);
            glVertex2f(537.833, -1913.500);
            glVertex2f(534.667, -1920.000);
            glVertex2f(533.667, -1926.500);
            glVertex2f(533.333, -1931.500);
            glVertex2f(507.833, -1967.833);
            glVertex2f(494.000, -1986.667);
            glVertex2f(470.833, -2018.000);
            glVertex2f(463.167, -2028.667);
            glVertex2f(452.333, -2042.667);
            glVertex2f(438.500, -2062.500);
            glVertex2f(427.833, -2080.167);
            glVertex2f(415.375, -2099.125);
            glVertex2f(407.750, -2111.500);
            glVertex2f(397.500, -2128.875);
            glVertex2f(387.250, -2146.000);
            glVertex2f(379.375, -2161.500);
            glVertex2f(372.667, -2172.833);
            glVertex2f(363.000, -2191.833);
            glVertex2f(355.500, -2208.167);
            glVertex2f(346.833, -2227.000);
            glVertex2f(340.833, -2241.500);
            glVertex2f(332.500, -2262.500);
            glVertex2f(321.667, -2289.167);
            glVertex2f(315.167, -2305.667);
            glVertex2f(306.667, -2325.333);
            glVertex2f(296.250, -2349.500);
            glVertex2f(280.667, -2388.333);
            glVertex2f(267.333, -2422.333);
            glVertex2f(254.000, -2455.000);
            glVertex2f(221.000, -2539.000);
            glVertex2f(203.167, -2586.333);
            glVertex2f(197.333, -2602.500);
            glVertex2f(192.667, -2616);
            glEnd();
        }
        //elLight elly fe elganb elymeen (line) (6)
        {
            glPushMatrix();
            glTranslated(7,0,0);
            glLineWidth(15);
            glColor4f( 222/255.0f, 159/255.0f, 66/255.0f, 0.2);
            glBegin(GL_LINE_STRIP);
            glVertex2d(1158.000, -2616);
            glVertex2d(1153.667, -2597.000);
            glVertex2d(1143.667, -2557.667);
            glVertex2d(1135.333, -2528.000);
            glVertex2d(1128.333, -2502.667);
            glVertex2d(1123.333, -2484.667);
            glVertex2d(1119.333, -2473.333);
            glVertex2d(1117.667, -2467.000);
            glVertex2d(1115.000, -2459.667);
            glVertex2d(1112.333, -2447.000);
            glVertex2d(1101.333, -2409.333);
            glVertex2d(1090.625, -2372.250);
            glVertex2d(1073.750, -2314.750);
            glVertex2d(1064.750, -2284.750);
            glVertex2d(1055.750, -2259.250);
            glVertex2d(1048.000, -2234.750);
            glVertex2d(1039.500, -2211.250);
            glVertex2d(1034.667, -2178.667);
            glVertex2d(1026.333, -2141.000);
            glVertex2d(1020.000, -2115.333);
            glVertex2d(1005.750, -2069.750);
            glVertex2d(991.250, -2024.000);
            glVertex2d(988.000, -2016.750);
            glVertex2d(984.750, -2013.000);
            glVertex2d(980.250, -2009.875);
            glVertex2d(979.000, -2009.125);
            glVertex2d(979.125, -2005.750);
            glVertex2d(980.500, -2001.750);
            glVertex2d(980.500, -1998.250);
            glEnd();
            glPopMatrix();
        }

        //elbase
        {
            double vertices[][2] = {
                    { 537.833, -1913.500 },
                    { 534.667, -1920.000 },
                    { 533.667, -1926.500 },
                    { 533.333, -1931.500 },
                    { 507.833, -1967.833 },
                    { 494.000, -1986.667 },
                    { 470.833, -2018.000 },
                    { 463.167, -2028.667 },
                    { 452.333, -2042.667 },
                    { 438.500, -2062.500 },
                    { 427.833, -2080.167 },
                    { 415.375, -2099.125 },
                    { 407.750, -2111.500 },
                    { 397.500, -2128.875 },
                    { 387.250, -2146.000 },
                    { 379.375, -2161.500 },
                    { 372.667, -2172.833 },
                    { 363.000, -2191.833 },
                    { 355.500, -2208.167 },
                    { 346.833, -2227.000 },
                    { 340.833, -2241.500 },
                    { 332.500, -2262.500 },
                    { 321.667, -2289.167 },
                    { 315.167, -2305.667 },
                    { 306.667, -2325.333 },
                    { 296.250, -2349.500 },
                    { 280.667, -2388.333 },
                    { 267.333, -2422.333 },
                    { 254.000, -2455.000 },
                    { 221.000, -2539.000 },
                    { 203.167, -2586.333 },
                    { 197.333, -2602.500 },
                    { 192.667, -2616 },

                    { 1158.000, -2616 },
                    { 1153.667, -2597.000 },
                    { 1143.667, -2557.667 },
                    { 1135.333, -2528.000 },
                    { 1128.333, -2502.667 },
                    { 1123.333, -2484.667 },
                    { 1119.333, -2473.333 },
                    { 1117.667, -2467.000 },
                    { 1115.000, -2459.667 },
                    { 1112.333, -2447.000 },
                    { 1101.333, -2409.333 },
                    { 1090.625, -2372.250 },
                    { 1073.750, -2314.750 },
                    { 1064.750, -2284.750 },
                    { 1055.750, -2259.250 },
                    { 1048.000, -2234.750 },
                    { 1039.500, -2211.250 },
                    { 1034.667, -2178.667 },
                    { 1026.333, -2141.000 },
                    { 1020.000, -2115.333 },
                    { 1005.750, -2069.750 },
                    { 991.250, -2024.000 },
                    { 988.000, -2016.750 },
                    { 984.750, -2013.000 },
                    { 980.250, -2009.875 },
                    { 979.000, -2009.125 },
                    { 979.125, -2005.750 },
                    { 980.500, -2001.750 },
                    { 980.500, -1998.250 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glEnable(GL_STENCIL_TEST);          // enable stencil test
            glEnable(GL_DEPTH_TEST);

            // PASS 1: draw to stencil buffer only
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
            glStencilFunc(GL_ALWAYS, 1, 1);
            glStencilOp(GL_KEEP, GL_INVERT, GL_KEEP);

            glBegin(GL_POLYGON);
            for (int i = 0; i < size; ++i)
                glVertex2dv(vertices[i]);
            glEnd();

            // PASS 2: draw color buffer
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
            glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1) (check if it inside the polygon)
            glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
            glDisable(GL_DEPTH_TEST);

            glBegin(GL_POLYGON);
            for (int i = 0; i < size; ++i) {
                if (i>32)
                    glColor4d(33/255.0f,24/255.0f,16/255.0f,1);
                    // glColor4d(57/255.0f,32/255.0f,17/255.0f,1);
                else
                    glColor4d(32/255.0f,21/255.0f,10/255.0f,1);
                glVertex2dv(vertices[i]);
            }
            glEnd();
            glDisable(GL_STENCIL_TEST);
        }
        //elShadow ew elight elle fe elganb el4emal
        {
            double vertices[][2] = {
                    { 537.833, -1913.500 },
                    { 534.667, -1920.000 },
                    { 533.667, -1926.500 },
                    { 533.333, -1931.500 },
                    { 507.833, -1967.833 },
                    { 494.000, -1986.667 },
                    { 470.833, -2018.000 },
                    { 463.167, -2028.667 },
                    { 452.333, -2042.667 },
                    { 438.500, -2062.500 },
                    { 427.833, -2080.167 },
                    { 415.375, -2099.125 },
                    { 407.750, -2111.500 },
                    { 397.500, -2128.875 },
                    { 387.250, -2146.000 },
                    { 379.375, -2161.500 },
                    { 372.667, -2172.833 },
                    { 363.000, -2191.833 },
                    { 355.500, -2208.167 },
                    { 346.833, -2227.000 },
                    { 340.833, -2241.500 },
                    { 332.500, -2262.500 },
                    { 321.667, -2289.167 },
                    { 315.167, -2305.667 },
                    { 306.667, -2325.333 },
                    { 296.250, -2349.500 },
                    { 280.667, -2388.333 },
                    { 267.333, -2422.333 },
                    { 254.000, -2455.000 },
                    { 221.000, -2539.000 },
                    { 203.167, -2586.333 },
                    { 197.333, -2602.500 },
                    { 192.667, -2616.000 },

                    { 315.000, -2616.000 },
                    { 378.000, -2416.000 },
                    { 438.000, -2252.000 },
                    { 512.000, -2104.000 },
                    { 548.000, -2036.000 },
                    { 574.000, -1982.000 },
                    { 596.000, -1934.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glEnable(GL_STENCIL_TEST);          // enable stencil test
            glEnable(GL_DEPTH_TEST);

            // PASS 1: draw to stencil buffer only
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
            glStencilFunc(GL_ALWAYS, 1, 1);
            glStencilOp(GL_KEEP, GL_INVERT, GL_KEEP);

            glBegin(GL_POLYGON);
            for (int i = 0; i < size; ++i)
                glVertex2dv(vertices[i]);
            glEnd();

            // PASS 2: draw color buffer
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
            glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1) (check if it inside the polygon)
            glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
            glDisable(GL_DEPTH_TEST);

            glBegin(GL_POLYGON);
            for (int i = 0; i < size; ++i) {
                if (i>32)
                    glColor4d(33/255.0f,24/255.0f,16/255.0f,0.1);
                else
                    glColor4d(75/255.0f,30/255.0f,9/255.0f,0.3);
                glVertex2dv(vertices[i]);
            }
            glEnd();
            glDisable(GL_STENCIL_TEST);
        }
        //elShadow ew elight elle fe elganb elyemeen
        {
            double vertices[][2] = {
                    { 1158.000, -2616 },
                    { 1153.667, -2597.000 },
                    { 1143.667, -2557.667 },
                    { 1135.333, -2528.000 },
                    { 1128.333, -2502.667 },
                    { 1123.333, -2484.667 },
                    { 1119.333, -2473.333 },
                    { 1117.667, -2467.000 },
                    { 1115.000, -2459.667 },
                    { 1112.333, -2447.000 },
                    { 1101.333, -2409.333 },
                    { 1090.625, -2372.250 },
                    { 1073.750, -2314.750 },
                    { 1064.750, -2284.750 },
                    { 1055.750, -2259.250 },
                    { 1048.000, -2234.750 },
                    { 1039.500, -2211.250 },
                    { 1034.667, -2178.667 },
                    { 1026.333, -2141.000 },
                    { 1020.000, -2115.333 },
                    { 1005.750, -2069.750 },
                    { 991.250, -2024.000 },
                    { 988.000, -2016.750 },
                    { 984.750, -2013.000 },
                    { 980.250, -2009.875 },
                    { 979.000, -2009.125 },
                    { 979.125, -2005.750 },
                    { 980.500, -2001.750 },
                    { 980.500, -1998.250 },

                    { 820.000, -2022.000 },
                    { 795.000, -2169.000 },
                    { 747.000, -2161.000 },
                    { 708.000, -2162.000 },
                    { 688.000, -2181.000 },
                    { 656.000, -2284.000 },
                    { 607.000, -2496.000 },
                    { 586.000, -2616.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glEnable(GL_STENCIL_TEST);          // enable stencil test
            glEnable(GL_DEPTH_TEST);

            // PASS 1: draw to stencil buffer only
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
            glStencilFunc(GL_ALWAYS, 1, 1);
            glStencilOp(GL_KEEP, GL_INVERT, GL_KEEP);

            glBegin(GL_POLYGON);
            for (int i = 0; i < size; ++i)
                glVertex2dv(vertices[i]);
            glEnd();

            // PASS 2: draw color buffer
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
            glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1) (check if it inside the polygon)
            glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
            glDisable(GL_DEPTH_TEST);

            glBegin(GL_POLYGON);
            for (int i = 0; i < size; ++i) {
                if (i>28)
                    glColor4d(75/255.0f,30/255.0f,9/255.0f,0.01);
                else
                    glColor4d(75/255.0f,30/255.0f,9/255.0f,0.99999);
                glVertex2dv(vertices[i]);
            }
            glEnd();
            glDisable(GL_STENCIL_TEST);
        }
        //10
        {
            double vertices[][2] = {
                    { 949.000, -2615.000 },
                    { 915.000, -2533.000 },
                    { 903.000, -2485.000 },
                    { 899.000, -2414.000 },
                    { 904.000, -2335.000 },
                    { 910.000, -2301.000 },
                    { 918.000, -2266.000 },
                    { 917.000, -2240.000 },
                    { 905.000, -2196.000 },
                    { 885.000, -2115.000 },
                    { 886.000, -2081.000 },
                    { 894.000, -2074.000 },
                    { 976.000, -2005.000 },
                    { 1151.000, -2613.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 75, 30, 9,0.2);
//            drawConcavePolygon(vertices, size, 76, 39, 15,0.1);
        }
    }
    //el7ezam
    {
        //elbase
        {
            double vertices[][2] = {
                    { 557.000, -1853.667 },
                    { 578.000, -1803.667 },
                    { 944.000, -1858.500 },
                    { 949.250, -1876.000 },
                    { 955.500, -1884.000 },
                    { 951.125, -1892.000 },
                    { 950.875, -1896.125 },
                    { 951.125, -1905.875 },
                    { 952.000, -1916.333 },
                    { 954.167, -1929.500 },
                    { 959.833, -1949.833 },
                    { 967.500, -1968.167 },
                    { 975.167, -1986.667 },
                    { 980.167, -1998.667 },
                    { 968.625, -2020.250 },
                    { 958.000, -2053.500 },
                    { 951.000, -2106.500 },
                    { 958.500, -2190.500 },
                    { 949.000, -2152.500 },
                    { 939.000, -2116.000 },
                    { 927.000, -2087.000 },
                    { 907.000, -2072.000 },
                    { 863.500, -2047.500 },
                    { 811.000, -2021.500 },
                    { 762.000, -1997.500 },
                    { 718.000, -1975.500 },
                    { 666.500, -1954.500 },
                    { 637.000, -1943.500 },
                    { 585.500, -1929.500 },
                    { 554.250, -1922.500 },
                    { 551.000, -1922.250 },
                    { 545.750, -1919.250 },
                    { 538.000, -1913.750 },
                    { 540.750, -1907.000 },
                    { 543.750, -1900.750 },
                    { 546.750, -1889.000 },
                    { 548.500, -1877.000 },
                    { 550.500, -1868.000 },
                    { 552.000, -1862.000 },
                    { 554.250, -1857.750 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 49, 23, 14);
        }
        //elShadow
        {
            double vertices[][2] = {
                    { 958.333, -2190.000 },
                    { 948.000, -2148.333 },
                    { 940.667, -2120.000 },
                    { 933.000, -2100.667 },
                    { 926.333, -2089.000 },
                    { 908.333, -2074.667 },
                    { 880.667, -2058.667 },
                    { 847.000, -2041.333 },
                    { 769.000, -2003.667 },
                    { 736.833, -1989.333 },
                    { 712.500, -1978.500 },
                    { 682.000, -1966.000 },
                    { 656.000, -1955.250 },
                    { 632.000, -1947.000 },
                    { 543.500, -1924.500 },
                    { 577.500, -1853.500 },
                    { 740.333, -1911.333 },
                    { 841.667, -1952.667 },
                    { 898.333, -1990.000 },
                    { 934.000, -2034.333 },
                    { 944.667, -2082.333 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glEnable(GL_STENCIL_TEST);          // enable stencil test
            glEnable(GL_DEPTH_TEST);

            // PASS 1: draw to stencil buffer only
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
            glStencilFunc(GL_ALWAYS, 1, 1);
            glStencilOp(GL_KEEP, GL_INVERT, GL_KEEP);

            glBegin(GL_POLYGON);
            for (int i = 0; i < size; ++i)
                glVertex2dv(vertices[i]);
            glEnd();

            // PASS 2: draw color buffer
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
            glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1) (check if it inside the polygon)
            glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
            glDisable(GL_DEPTH_TEST);

            glBegin(GL_POLYGON);
            for (int i = 0; i < size; ++i) {
                if (i>=14)
                    glColor4d(49/255.0f,23/255.0f,14/255.0f,1);
                else
                    glColor4d(0/255.0f,0/255.0f,0/255.0f,1);

                glVertex2dv(vertices[i]);
            }
            glEnd();
            glDisable(GL_STENCIL_TEST);
        }
        //eline
        {
            glLineWidth(1);
            glBegin(GL_LINE_STRIP);
            glColor4f(0/255.0f, 0/255.0f, 0/255.0f, 0.5-0.3);
            glVertex2f(852.500, -1894.000);
            glVertex2f(874.500, -1913.500);
            glColor4f(0/255.0f, 0/255.0f, 0/255.0f, 0.6-0.3);
            glVertex2f(891.500, -1934.000);
            glColor4f(0/255.0f, 0/255.0f, 0/255.0f, 0.8-0.3);
            glVertex2f(901.000, -1953.000);
            glVertex2f(910.500, -1981.000);
            glVertex2f(914.000, -1996.500);
            glColor4f(0/255.0f, 0/255.0f, 0/255.0f, 0.7-0.3);
            glVertex2f(917.500, -2015.500);
            glVertex2f(917.500, -2039.500);
            glColor4f(0/255.0f, 0/255.0f, 0/255.0f, 0.5-0.3);
            glVertex2f(912.500, -2075.500);
            glEnd();
        }
        //elLight elly fe elganb
        {
            double vertices[][2] = {
                    { 949.500, -1908.750 },
                    { 943.500, -1913.000 },
                    { 939.000, -1918.000 },
                    { 937.250, -1921.500 },
                    { 937.000, -1929.250 },
                    { 937.500, -1935.000 },
                    { 940.750, -1944.250 },
                    { 946.500, -1956.000 },
                    { 952.750, -1967.000 },
                    { 958.000, -1978.000 },
                    { 960.000, -1985.500 },
                    { 961.000, -2000.000 },
                    { 959.500, -2035.000 },
                    { 978.750, -2000.250 },
                    { 978.000, -1995.875 },
                    { 966.667, -1968.500 },
                    { 963.833, -1961.167 },
                    { 958.167, -1946.500 },
                    { 953.500, -1931.500 },
                    { 951.000, -1918.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 224, 134, 58);
        }
    }
    //elShadows
    {
        //14
        {
            double vertices[][2] = {
                    { 762.000, -2351.000 },
                    { 756.000, -2294.000 },
                    { 756.000, -2230.000 },
                    { 765.000, -2147.000 },
                    { 770.000, -2087.000 },
                    { 780.000, -2045.000 },
                    { 786.000, -2087.000 },
                    { 792.000, -2138.000 },
                    { 795.000, -2117.000 },
                    { 798.000, -2096.000 },
                    { 802.000, -2074.000 },
                    { 804.000, -2061.000 },
                    { 805.000, -2052.000 },
                    { 807.000, -2040.000 },
                    { 808.000, -2033.000 },
                    { 811.000, -2055.000 },
                    { 813.000, -2076.000 },
                    { 813.000, -2105.000 },
                    { 811.000, -2136.000 },
                    { 800.000, -2193.000 },
                    { 793.000, -2235.000 },
                    { 787.000, -2272.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 0, 0, 0,0.15);
        }
        //15
        {
            double vertices[][2] = {
                    { 675.000, -2150.000 },
                    { 655.000, -2200.000 },
                    { 647.000, -2253.000 },
                    { 632.000, -2356.000 },
                    { 620.000, -2428.000 },
                    { 609.000, -2538.000 },
                    { 631.000, -2452.000 },
                    { 647.000, -2387.000 },
                    { 659.000, -2317.000 },
                    { 668.000, -2257.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 0, 0, 0,0.01,true,0, 0, 0,0.15);
        }
        //16
        {
            double vertices[][2] = {
                    { 555.000, -2122.000 },
                    { 503.000, -2342.000 },
                    { 497.000, -2307.000 },
                    { 496.000, -2268.000 },
                    { 501.000, -2215.000 },
                    { 506.000, -2196.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 0, 0, 0,0.01,true,0, 0, 0,0.1);
        }
        //17
        {
            double vertices[][2] = {
                    { 505.667, -2372.333 },
                    { 525.333, -2482.333 },
                    { 535.000, -2520.000 },
                    { 538.333, -2547.667 },
                    { 538.000, -2575.333 },
                    { 523.667, -2512.333 },
                    { 509.000, -2475.333 },
                    { 488.333, -2423.667 },
                    { 480.333, -2398.667 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 0, 0, 0,0.01,true,0, 0, 0,0.09);
        }
        //18
        {
            double vertices[][2] = {
                    { 473.667, -2178.333 },
                    { 470.000, -2204.000 },
                    { 447.667, -2242.333 },
                    { 433.667, -2254.333 },
                    { 437.000, -2232.000 },
                    { 441.333, -2209.333 },
                    { 446.000, -2195.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 0, 0, 0,0.01,true,0, 0, 0,0.09);
        }
        //19
        {
            double vertices[][2] = {
                    { 424.000, -2291.250 },
                    { 417.000, -2320.750 },
                    { 408.500, -2362.500 },
                    { 402.500, -2395.250 },
                    { 399.750, -2417.750 },
                    { 392.500, -2474.250 },
                    { 388.750, -2504.500 },
                    { 381.500, -2549.750 },
                    { 377.667, -2583.000 },
                    { 374.167, -2614.667 },
                    { 363.167, -2614.833 },
                    { 366.000, -2595.500 },
                    { 370.333, -2569.833 },
                    { 375.750, -2542.750 },
                    { 382.000, -2506.333 },
                    { 388.667, -2473.500 },
                    { 391.333, -2459.333 },
                    { 394.167, -2443.667 },
                    { 396.167, -2429.667 },
                    { 398.000, -2416.167 },
                    { 401.167, -2394.167 },
                    { 407.500, -2362.625 },
                    { 416.000, -2320.583 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 0, 0, 0,0.2,true,0, 0, 0,0.6);
        }
        //20
        {
            double vertices[][2] = {
                    { 647.000, -2244.000 },
                    { 647.000, -2265.000 },
                    { 641.000, -2303.000 },
                    { 625.000, -2389.000 },
                    { 592.000, -2560.000 },
                    { 583.000, -2615.000 },
                    { 598.000, -2614.000 },
                    { 614.000, -2518.000 },
                    { 620.000, -2456.000 },
                    { 620.000, -2424.000 },
                    { 627.000, -2389.000 },
                    { 643.000, -2304.000 },
                    { 649.000, -2265.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 0, 0, 0,0.4,true,0, 0, 0,0.6);
        }
        //21
        {
            glLineWidth(1);
            glColor4f(0/255.0f, 0/255.0f, 0/255.0f, 0.4);
            glBegin(GL_LINE_STRIP);
            glVertex2f(779.500, -2008);
            glVertex2f(781.500, -2045.833);
            glVertex2f(786.500, -2095.000);
            glVertex2f(790.500, -2121.000);
            glVertex2f(792.500, -2141.625);
            glVertex2f(794.000, -2164.500);
            glEnd();
        }
        //22
        {
            glColor4f(0/255.0f,0 /255.0f, 0/255.0f, 1);
            glBegin(GL_POLYGON);
            glVertex2f(719, -2613);
            glVertex2f(723, -2574);
            glVertex2f(730, -2529);
            glVertex2f(741, -2473);
            glVertex2f(755, -2407);
            glColor4f(0/255.0f,0 /255.0f, 0/255.0f, 0.5);
            glVertex2f(768, -2348);
            glColor4f(0/255.0f,0 /255.0f, 0/255.0f, 0.2);
            glVertex2f(780, -2299);
            glEnd();
        }
        //23
        {
            double vertices[][2] = {
                    { 496.000, -2354.000 },
                    { 533.000, -2189.000 },
                    { 577.000, -2042.000 },
                    { 627.000, -1943.000 },
                    { 597.000, -1931.000 },
                    { 576.000, -1975.000 },
                    { 566.000, -1998.000 },
                    { 559.000, -2030.000 },
                    { 554.000, -2050.000 },
                    { 542.000, -2067.000 },
                    { 518.000, -2128.000 },
                    { 504.000, -2196.000 },
                    { 496.000, -2278.000 },
                    { 494.000, -2317.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 0, 0, 0,0.01,true,0, 0, 0,0.1);
        }


    }
    //elLights
    {
        //9
        {
            double vertices[][2] = {
                    { 795.000, -2615.000 },
                    { 796.000, -2581.000 },
                    { 796.000, -2555.000 },
                    { 796.000, -2527.000 },
                    { 800.000, -2489.000 },
                    { 800.000, -2455.000 },
                    { 795.000, -2418.000 },
                    { 788.000, -2378.000 },
                    { 793.000, -2339.000 },
                    { 802.000, -2303.000 },
                    { 818.000, -2271.000 },
                    { 830.000, -2250.000 },
                    { 837.000, -2243.000 },
                    { 844.000, -2241.000 },
                    { 864.000, -2253.000 },
                    { 882.000, -2289.000 },
                    { 896.000, -2365.000 },
                    { 894.000, -2409.000 },
                    { 894.000, -2447.000 },
                    { 892.000, -2476.000 },
                    { 883.000, -2617.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 75, 30, 9,0.25);
        }

        //12
        {
            glColor4f(76/255.0f, 39/255.0f, 15/255.0f, 0.5);
            glBegin(GL_POLYGON);
            glVertex2f(1086.000, -2614.500);
            glVertex2f(1051.000, -2303.500);
            glVertex2f(1149.500, -2614.500);
            glEnd();
        }
        //13
        {
            glColor4f(76/255.0f, 39/255.0f, 15/255.0f, 0.3);
            glBegin(GL_POLYGON);
            glVertex2f(919, -2116);
            glVertex2f(982, -2017);
            glVertex2f(1039, -2221);
            glVertex2f(1040, -2455);
            glVertex2f(985, -2302);
            glEnd();
        }

        //8
        {
            double vertices[][2]={
                    {822 , -2616},
                    {828 , -2480},
                    {828 , -2452},
                    {828 , -2435},
                    {825 , -2422},
                    {816 , -2390},
                    {816 , -2368},
                    {829 , -2289},
                    {838 , -2254},
                    {843 , -2252},
                    {855 , -2282},
                    {865 , -2324},
                    {871 , -2370},
                    {877 , -2418},
                    {886 , -2452},
                    {889 , -2468},
                    {887 , -2524},
                    {879 , -2616}
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(6);
            glColor4f(75/255.0f, 30/255.0f, 9/255.0f, 0.5);
            glBegin(GL_LINE_LOOP);
            for (int i = 0; i < size; i++)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 222, 159, 66);
        }
        //11
        {
            double vertices[][2] = {
                    { 1054.000, -2616 },
                    { 1045.000, -2570.000 },
                    { 1023.000, -2486.000 },
                    { 1008.000, -2438.000 },
                    { 994.000, -2391.000 },
                    { 981.000, -2356.000 },
                    { 974.000, -2315.000 },
                    { 964.000, -2271.000 },
                    { 945.000, -2217.000 },
                    { 926.000, -2172.000 },
                    { 918.000, -2149.000 },
                    { 912.000, -2127.000 },
                    { 908.000, -2101.000 },
                    { 909.000, -2091.000 },
                    { 918.000, -2101.000 },
                    { 939.000, -2152.000 },
                    { 968.000, -2227.000 },
                    { 988.000, -2278.000 },
                    { 1000.000, -2317.000 },
                    { 1008.000, -2359.000 },
                    { 1018.000, -2387.000 },
                    { 1030.000, -2415.000 },
                    { 1076.000, -2615.000 },
                    { 1061.000, -2536.000 },
                    { 1041.000, -2449.000 },
                    { 1031.000, -2413.000 },
                    { 1029.000, -2398.000 },
                    { 1027.000, -2381.000 },
                    { 1026.000, -2358.000 },
                    { 1022.000, -2324.000 },
                    { 1019.000, -2303.000 },
                    { 1011.000, -2264.000 },
                    { 1004.000, -2229.000 },
                    { 997.000, -2195.000 },
                    { 991.000, -2165.000 },
                    { 983.000, -2136.000 },
                    { 978.000, -2117.000 },
                    { 973.000, -2098.000 },
                    { 970.000, -2087.000 },
                    { 968.000, -2076.000 },
                    { 967.000, -2071.000 },
                    { 967.000, -2065.000 },
                    { 967.000, -2059.000 },
                    { 968.000, -2056.000 },
                    { 969.000, -2053.000 },
                    { 970.000, -2053.000 },
                    { 974.000, -2063.000 },
                    { 987.000, -2095.000 },
                    { 994.000, -2113.000 },
                    { 1001.000, -2126.000 },
                    { 1006.000, -2135.000 },
                    { 1007.000, -2136.000 },
                    { 1005.000, -2114.000 },
                    { 1000.000, -2086.000 },
                    { 993.000, -2059.000 },
                    { 985.000, -2032.000 },
                    { 983.000, -2028.000 },
                    { 980.000, -2021.000 },
                    { 981.000, -2019.000 },
                    { 983.000, -2018.000 },

                    { 988.000, -2017 },
                    { 991.250, -2024.000 },
                    { 1005.750, -2069.750 },
                    { 1020.000, -2115.333 },
                    { 1026.333, -2141.000 },
                    { 1034.667, -2178.667 },
                    { 1039.500, -2211.250 },
                    { 1048.000, -2234.750 },
                    { 1055.750, -2259.250 },
                    { 1064.750, -2284.750 },
                    { 1073.750, -2314.750 },
                    { 1090.625, -2372.250 },
                    { 1101.333, -2409.333 },
                    { 1112.333, -2447.000 },
                    { 1115.000, -2459.667 },
                    { 1117.667, -2467.000 },
                    { 1119.333, -2473.333 },
                    { 1123.333, -2484.667 },
                    { 1128.333, -2502.667 },
                    { 1135.333, -2528.000 },
                    { 1143.667, -2557.667 },
                    { 1153.667, -2597.000 },
                    { 1158.000, -2616 },

                    { 1132.000, -2616.000 },
                    { 1126.000, -2584.000 },
                    { 1114.000, -2529.000 },
                    { 1089.000, -2428.000 },
                    { 1065.000, -2351.000 },
                    { 1058.000, -2328.000 },
                    { 1055.000, -2306.000 },
                    { 1050.000, -2271.000 },
                    { 1045.000, -2242.000 },
                    { 1049.000, -2278.000 },
                    { 1055.000, -2320.000 },
                    { 1057.000, -2337.000 },
                    { 1062.000, -2381.000 },
                    { 1067.000, -2427.000 },
                    { 1075.000, -2491.000 },
                    { 1085.000, -2566.000 },
                    { 1089.000, -2605.000 },
                    { 1090.000, -2616 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(6);
            glColor4f(75/255.0f, 30/255.0f, 9/255.0f, 0.5);
            glBegin(GL_LINE_LOOP);
            for (int i = 0; i < 60; i++)
                glVertex2dv(vertices[i]);
            glEnd();
            glLineWidth(1.5);
            glColor4f(75/255.0f, 30/255.0f, 9/255.0f, 0.5);
            glBegin(GL_LINE_LOOP);
            for (int i = 60; i < 83; i++)
                glVertex2dv(vertices[i]);
            glEnd();
            glLineWidth(6);
            glColor4f(75/255.0f, 30/255.0f, 9/255.0f, 0.5);
            glBegin(GL_LINE_LOOP);
            for (int i = 83; i < size; i++)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 222, 159, 66);
        }
        //24
        {
            double vertices[][2] = {
                    { 921.500, -2616.000 },
                    { 915.500, -2557.250 },
                    { 914.500, -2545.000 },
                    { 913.750, -2534.250 },
                    { 919.500, -2552.500 },
                    { 928.250, -2571.500 },
                    { 936.000, -2590.500 },
                    { 941.750, -2608.250 },
                    { 944.000, -2616.000 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            glLineWidth(6);
            glColor4f(75/255.0f, 30/255.0f, 9/255.0f, 0.4);
            glBegin(GL_LINE_LOOP);
            for (int i = 0; i < size; i++)
                glVertex2dv(vertices[i]);
            glEnd();
            drawConcavePolygon(vertices, size, 222, 159, 66);
        }
        //28
        {
            double vertices[][2] = {
                    { 996.000, -2615.583 },
                    { 979.542, -2615.625 },
                    { 964.333, -2580.667 },
                    { 960.000, -2558.667 },
                    { 939.000, -2526.500 },
                    { 940.000, -2508.500 },
                    { 945.333, -2500.667 },
                    { 941.000, -2496.000 },
                    { 936.333, -2493.000 },
                    { 934.333, -2489.333 },
                    { 933.000, -2477.333 },
                    { 929.667, -2444.333 },
                    { 929.333, -2420.333 },
                    { 934.667, -2429.333 },
                    { 941.000, -2427.000 },
                    { 950.333, -2429.000 },
                    { 951.333, -2424.333 },
                    { 950.333, -2419.000 },
                    { 952.667, -2416.333 },
                    { 957.667, -2419.000 },
                    { 967.000, -2435.333 },
                    { 968.000, -2440.000 },
                    { 973.667, -2451.000 },
                    { 977.000, -2454.667 },
                    { 980.250, -2463.750 },
                    { 980.750, -2468.375 },
                    { 986.500, -2472.875 },
                    { 986.125, -2478.250 },
                    { 986.750, -2485.000 },
                    { 988.375, -2491.625 },
                    { 989.375, -2494.125 },
                    { 988.750, -2515.000 },
                    { 996.250, -2523.000 },
                    { 999.750, -2529.500 },
                    { 1001.250, -2535.500 },
                    { 1004.250, -2542.750 },
                    { 1012.500, -2547.750 },
                    { 1016.625, -2615.625 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 0, 0, 0,0.05, true,0, 0, 0,0.15);
        }
        //29
        {
            double vertices[][2] = {
                    { 1001.333, -2465.000 },
                    { 1013.833, -2526.667 },
                    { 1019.750, -2564.625 },
                    { 1024.167, -2590.667 },
                    { 1026.333, -2604.333 },
                    { 1027.500, -2615.750 },
                    { 1018.375, -2615.500 },
                    { 1013.500, -2563.000 },
                    { 1010.750, -2539.750 }
            };
            int size = sizeof(vertices) / sizeof(vertices[0]);
            drawConcavePolygon(vertices, size, 0, 0, 0,0.3);
        }
    }
}

void drawConcavePolygon(double vertices[][2], int size, double r1, double g1, double b1, double alfa1, bool RGBA2, double r2,double g2, double b2, double alfa2)
{
    glEnable(GL_STENCIL_TEST);          // enable stencil test
    glEnable(GL_DEPTH_TEST);

    // PASS 1: draw to stencil buffer only
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); // disable writing to color buffer
    glStencilFunc(GL_ALWAYS, 1, 1);
    glStencilOp(GL_KEEP, GL_INVERT, GL_KEEP);

    glBegin(GL_POLYGON);
    for (int i = 0; i < size; ++i)
        glVertex2dv(vertices[i]);
    glEnd();

    // PASS 2: draw color buffer
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);    // enable writing to color buffer
    glStencilFunc(GL_EQUAL, 1, 1);                  // test if it is odd(1) (check if it inside the polygon)
    glStencilOp(GL_KEEP, GL_KEEP, GL_INVERT);
    glDisable(GL_DEPTH_TEST);

    glBegin(GL_POLYGON);
    glColor4d(r1/255.0f,g1/255.0f,b1/255.0f,alfa1);
    glVertex2dv(vertices[0]);
    if (RGBA2)
        glColor4d(r2/255.0f,g2/255.0f,b2/255.0f,alfa2);
    for (int i = 1; i < size; ++i)
        glVertex2dv(vertices[i]);
    glEnd();
    glDisable(GL_STENCIL_TEST);
}

void OnDisplay()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    SetTransformations();

    //Drawing Code
    glEnable (GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); // Ensure smooth lines look better

    switch (layer) {
        case 0: {
            drawBackground();
            drawUmbrella();
            drawSkirt();
            drawBlouse();
            drawVioletFace();
            violetHair();
            violetLeftEyebrowOutline();
            violetEar();
        }
            break;
        case 1:
            violetHair();
            break;
        case 2: {
            drawSkirt();
            drawBlouse();
        }
            break;
        case 3: {
            drawVioletFace();
            violetLeftEyebrowOutline();
        }
            break;
        case 4:
            drawUmbrella();
            break;
        case 5:
            drawBackground();
            break;
        default:;

    }
    glutSwapBuffers();
}