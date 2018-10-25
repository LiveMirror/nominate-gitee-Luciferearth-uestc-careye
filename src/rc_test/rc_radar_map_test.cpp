//
// Created by PulsarV on 18-10-26.
//

#include <GL/glut.h>
#include <projects.h>

#define GL_WIDTH 480
#define RADAR_STEP 0.01
float p1_x=0,p1_y=0;
float p2_x=0,p2_y=0;
float p1step = 1.75f;
//float p1step = 0.0f;
float p2step = 2.25f;
void draw_line(float x1,float y1,float x2,float y2){
    GLfloat line_size=3;
    glLineWidth(line_size);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}
void draw_point(float x,float y, float R,float G,float B, float alpha){
    GLfloat point_size=5;
    glPointSize(point_size);
    glColor4f(R,G,B,alpha);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}
void draw_rader() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);
    glColor4f(0,1,0,0);
    int n=1000;
    for (float scale=1;scale>0.1;scale-=0.1){
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<n;i++)
        {
            glVertex2f(scale*cos(2*PI*i/n),scale*sin(2*PI*i/n));   //定义顶点
        }
        glEnd();
    }
    glColor4f(1,0,0,0);
    draw_line(0,0,0,1);
    draw_line(0,0,1,1);
    draw_line(0,0,-1,1);
    draw_line(0,0,1,-1);
    draw_line(0,0,-1,-1);
    draw_line(0,0,0,-1);
    draw_line(0,0,1,0);
    draw_line(0,0,-1,0);
    draw_point(p1_x,p1_y,1,1,1,0);
    draw_point(p2_x,p2_y,1,1,1,0);
    draw_line(0,0,p1_x,p1_y);
    draw_line(0,0,p2_x,p2_y);
    glFlush();
    glutSwapBuffers();
}
float get_angle(float x,float y){
    float trangel=atan(x/y)*180/PI;
    if(y<0 && x>0 || y<0 && x<0)
        trangel=trangel+180;
    if(x<0 && y>0)
        trangel=trangel+360;
    trangel=trangel==360?0:trangel;
}
void TimerFunction(int value) {
    p1_x = sin(PI*p1step);
    p1_y = cos(PI*p1step);
    p2_x = sin(PI*p2step);
    p2_y = cos(PI*p2step);
    if (p1step==2.5+1.75)
        p1step=1.75;
    if (p2step==2.5+2.25)
        p2step=2.25;
    p1step+=RADAR_STEP;
    p2step+=RADAR_STEP;
//    std::cout<<"当前角度1: "<<get_angle(p1_x,p1_y)<<" 当前角度2: "<<get_angle(p2_x,p2_y)<<std::endl;
    glutPostRedisplay(); //标志重新绘制
    glutTimerFunc(1,TimerFunction,1);
}
int main(int argc, char **argv) {


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowPosition(100, 100);
    glutInitWindowSize(GL_WIDTH, GL_WIDTH);
    glMatrixMode(GL_PROJECTION);//设定投影方式
    glutCreateWindow("radar map");
    glutDisplayFunc(draw_rader);
    glutTimerFunc(50,TimerFunction,1);
    glutMainLoop();
    return 0;
}