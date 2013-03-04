#include "openglgraph.h"


#include <sys/types.h>
#include <stdio.h>

#include <QtGui>

const static float pi=3.141593, k=pi/180; // глобальна€ переменна€

OpenglGraph::OpenglGraph(ImageProcessing *worker, QWidget *parent): QGLWidget(parent)
{
        this->worker = worker;
        setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
        xRot=0; yRot=0; zRot=0; zTra=-2; nSca=1;


        pol = (myPoints *) malloc(max_cnt*sizeof(myPoints));
        for (int i = 0; i < max_cnt; i++) {
                pol[i].x =40;
                pol[i].y = 40;
        }

}

void OpenglGraph::showEvent (QShowEvent *event)
{
        this->defaultScene ();
        for (int i=0; i < max_cnt-1; i++) {
                pol[i].x = 0.0;
                pol[i].y = 0.0;
        }
}

void OpenglGraph::initializeGL()
{
        qglClearColor(Qt::black);
        //   glClearColor(0.36, 0.61, 0.86, 1.0);
        glEnable(GL_DEPTH_TEST);
        //glShadeModel(GL_FLAT);
      //  glEnable(GL_CULL_FACE) ;
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_COLOR_MATERIAL);


}

void OpenglGraph::resizeGL(int width, int height)
{
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glTranslatef(0.2, 0.0, 0.0);
        GLfloat x = GLfloat(width)/height;
        glFrustum(-x, x, -1.0, 1.0, 4.0, 100.0);
        glMatrixMode(GL_MODELVIEW);
}

void OpenglGraph::paintGL()
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(-5, zTra, -15);    // трансл€ци€
        glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
        glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
        glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
        glScalef(nSca, nSca, nSca);        // масштабирование


        //  glTranslatef(-5, -2, -15.0);
        //    glRotatef(rotationX, 1.0, 0.0, 0.0);
        //    glRotatef(rotationY, 0.0, 1.0, 0.0);
        //   glRotatef(rotationZ, 0.0, 0.0, 1.0);
        //  glScalef(nSca, nSca, nSca);        */

        glLineWidth(2.0);
        this->drawAxis ();
        glLineWidth(4.0);

        //  draw();
}

void OpenglGraph::drawAxis ()
{
        float bb = 1.0/8.0;
        float ll;
        for (int i = 0; i <40; i++) // красные вертикальные
                {
                        //  glColor3f(1.0, bb*(8-i), 0.0);
                        glColor3f(255,255, 255);
                        glBegin(GL_LINES);
                        glVertex3f(-0.5, (i+1)*0.3, 0.0);
                        glVertex3f(20.0, (i+1)*0.3, 0.0);
                        glEnd();
                }
        for (int i = 0; i < 64; i++)  // красные горизонтальные
                {
                        glBegin(GL_LINES);
                        //   glColor3f(1.0, 1.0, 0.0);
                        glColor3f(255,255, 255);
                        if ((i+1) % 3 == 0)
                                ll = -0.3;
                        else
                                ll = 0.0;
                        glVertex3f((i+1)*0.3, ll, 0.0);
                        //   glColor3f(1.0, 0.0, 0.0);
                        glColor3f(255,255, 255);
                        glVertex3f((i+1)*0.3, 12.0, 0.0);
                        glEnd();
                }

        bb = 1.0/8.0;   //зеленые Yz
        for (int i = 0; i < 40; i++)
                {
                        // glColor3f((8-i)*bb, 1.0, 0.0);
                        glColor3f(255,255, 255);
                        glBegin(GL_LINES);
                        glVertex3f(0.0, (i+1)*0.3, 0.0);
                        glVertex3f(0.0, (i+1)*0.3, 12.0);
                        glEnd();
                }
        for (int i = 0; i < 40; i++) {
                glBegin(GL_LINES);
                //   glColor3f(1.0, 1.0, 0.0);
                glColor3f(255,255, 255);
                glVertex3f(0.0, 0.0, (i+1)*0.3);
                //glColor3f(0.0, 1.0, 0.0);
                glColor3f(255,255, 255);
                glVertex3f(0.0, 12.0, (i+1)*0.3);
                glEnd();
        }

        for (int i = 0; i < 64; i++) //Xy
                {
                        glBegin(GL_LINES);
                        //   glColor3f(0.0, 1.0, 1.0);
                        glColor3f(255,255, 255);
                        glVertex3f((i+1)*0.3, 0.0, 0.0);
                        //    glColor3f(0.0, 0.0, 1.0);
                        glColor3f(255,255, 255);
                        glVertex3f((i+1)*0.3, 0.0, 12.0);
                        glEnd();
                }
        bb = 1.0/8.0;
        for (int i = 0; i < 40; i++)  //синии xY
                {
                        // glColor3f(0.0, (8-i)*bb, 1.0);
                        glColor3f(255,255, 255);
                        glBegin(GL_LINES);
                        glVertex3f(0.0, 0.0, (i+1)*0.3);
                        glVertex3f(20.0, 0.0, (i+1)*0.3);
                        glEnd();
                }

        glLineWidth(3.0);  // вправо
        glColor3f(255,255, 255);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(20.0, 0.0, 0.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(19.8, 0.2, 0.0);
        glVertex3f(20.0, 0.0, 0.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(20.0, 0.0, 0.0);
        glVertex3f(20, -0.2, 0.0);
        glEnd();

        glColor3f(255,255, 255); //стрелка вверх
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 12.0, 0.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(0.0, 11.8, -0.2);
        glVertex3f(0.0, 12.0, 0.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(0.0, 12.0, 0.0);
        glVertex3f(0.0, 12.0, 0.2);
        glEnd();


        glColor3f(255,255, 255);// к пользователю
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 12.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(-0.2, 0.0, 11.8);
        glVertex3f(0.0, 0.0, 12.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 12);
        glVertex3f(0.2, 0.0, 11.8);
        glEnd();

        glLineWidth(2.0);
        for (int i=0; i < max_cnt-1; i++) {
                glBegin(GL_QUADS);
                glColor4f(0.0, 0.7, 0.1, 0.75);
                glVertex3f(i*0.1, pol[i].x*0.3, pol[i].y*0.3);
                glVertex3f((i+1)*0.1, pol[i+1].x*0.3, pol[i+1].y*0.3);
                glColor4f(0.69, 0.9, 0.0, 0.75);
                glVertex3f((i+1)*0.1, pol[i+1].x*0.3, 0.0);
                glVertex3f(i*0.1, pol[i].x*0.3, 0.0);
                glEnd();
        }
}

void OpenglGraph::draw()
{
        // glClear(GL_COLOR_BUFFER_BIT);
        /*  glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(-5, -2, -15.0);
        glRotatef(rotationX, 1.0, 0.0, 0.0);
        glRotatef(rotationY, 0.0, 1.0, 0.0);
        glRotatef(rotationZ, 0.0, 0.0, 1.0);

        glLineWidth(1.0);
        float bb = 1.0/8.0;
        float ll;
        for (int i = 0; i < 10; i++) {
                glColor3f(1.0, bb*(8-i), 0.0);
                glBegin(GL_LINES);
                glVertex3f(-0.5, (i+1)*0.3, 0.0);
                glVertex3f(10.0, (i+1)*0.3, 0.0);
                glEnd();
        }
        for (int i = 0; i < 32; i++) {
                glBegin(GL_LINES);
                glColor3f(1.0, 1.0, 0.0);
                if ((i+1) % 3 == 0)
                        ll = -0.3;
                else
                        ll = 0.0;
                glVertex3f((i+1)*0.3, ll, 0.0);
                glColor3f(1.0, 0.0, 0.0);
                glVertex3f((i+1)*0.3, 3.0, 0.0);
                glEnd();
        }

        bb = 1.0/8.0;
        for (int i = 0; i <20; i++) {
                glColor3f((8-i)*bb, 1.0, 0.0);
                glBegin(GL_LINES);
                glVertex3f(0.0, (i+1)*0.3, 0.0);
                glVertex3f(0.0, (i+1)*0.3, 3.0);
                glEnd();
        }
        for (int i = 0; i < 10; i++) {
                glBegin(GL_LINES);
                glColor3f(1.0, 1.0, 0.0);
                glVertex3f(0.0, 0.0, (i+1)*0.3);
                glColor3f(0.0, 1.0, 0.0);
                glVertex3f(0.0, 3.0, (i+1)*0.3);
                glEnd();
        }

        for (int i = 0; i < 32; i++) {
                glBegin(GL_LINES);
                glColor3f(0.0, 1.0, 1.0);
                glVertex3f((i+1)*0.3, 0.0, 0.0);
                glColor3f(0.0, 0.0, 1.0);
                glVertex3f((i+1)*0.3, 0.0, 3.0);
                glEnd();
        }
        bb = 1.0/8.0;
        for (int i = 0; i < 10; i++) {
                glColor3f(0.0, (8-i)*bb, 1.0);
                glBegin(GL_LINES);
                glVertex3f(0.0, 0.0, (i+1)*0.3);
                glVertex3f(10.0, 0.0, (i+1)*0.3);
                glEnd();
        }

        glLineWidth(3.0);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(10.0, 0.0, 0.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(9.8, 0.2, 0.0);
        glVertex3f(10.0, 0.0, 0.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(10.0, 0.0, 0.0);
        glVertex3f(9.8, -0.2, 0.0);
        glEnd();

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 3.0, 0.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(0.0, 2.8, -0.2);
        glVertex3f(0.0, 3.0, 0.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(0.0, 3.0, 0.0);
        glVertex3f(0.0, 2.8, 0.2);
        glEnd();

        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 3.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(-0.2, 0.0, 2.8);
        glVertex3f(0.0, 0.0, 3.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 3.0);
        glVertex3f(0.2, 0.0, 2.8);
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        this->renderText(10.0, 0.0, 0.0, "Time");
        int int_val = 0;
        float float_val = 0.0;
        char str[5];
        glColor3f(0.0, 0.0, 0.0);
        for (int i = 0; i < 11; i++) {
                int_val = (i+1)*900;
                float_val = int_val/1000.0;

        }

        glColor3f(0.0, 1.0, 0.0);
        this->renderText(0.0, 3.0, 0.0, "count");

        bb = 1.0/9.0;
        for (int i = 0; i < 10; i++) {
                glColor3f((9-i)*bb, 1.0, 0.0);


        }

        glColor3f(0.0, 0.0, 1.0);
        this->renderText(0.0, 0.0, 3.0, "diametr");

        bb = 1.0/9.0;
        for (int i = 0; i < 10; i++) {
                glColor3f(0.0, (9-i)*bb, 1.0);


        }

        glLineWidth(1.0);
        for (int i=0; i < max_cnt-1; i++) {
                glBegin(GL_QUADS);
                glColor4f(0.0, 0.7, 0.1, 0.75);
                glVertex3f(i*0.1, pol[i].x*0.3, pol[i].y*0.3);
                glVertex3f((i+1)*0.1, pol[i+1].x*0.3, pol[i+1].y*0.3);
                glColor4f(0.69, 0.9, 0.0, 0.75);
                glVertex3f((i+1)*0.1, pol[i+1].x*0.3, 0.0);
                glVertex3f(i*0.1, pol[i].x*0.3, 0.0);
                glEnd();
        }
*/
}

void OpenglGraph::mousePressEvent(QMouseEvent *event)
{
        //  lastPos = event->pos();
        ptrMousePosition = event->pos();
}

void OpenglGraph::mouseMoveEvent(QMouseEvent *pe)
{
        xRot += 180/nSca*(GLfloat)(pe->y()-ptrMousePosition.y())/height(); // вычисление углов поворота
        yRot += 180/nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width();
        ptrMousePosition = pe->pos();
        updateGL(); // обновление изображени€

}

void OpenglGraph::wheelEvent (QWheelEvent *pe)
{
        if ((pe->delta())>0) scale_plus();
        else if ((pe->delta())<0) scale_minus();
        updateGL(); // обновление изображени€
}

void OpenglGraph::keyPressEvent (QKeyEvent *pe)
{
        switch (pe->key())
                {
        case Qt::Key_Plus:
                        scale_plus();     // приблизить сцену
                        break;

                case Qt::Key_Equal:
                        scale_plus();     // приблизить сцену
                        break;

                case Qt::Key_Minus:
                        scale_minus();    // удалитьс€ от сцены
                        break;

                case Qt::Key_Up:
                        rotate_up();      // повернуть сцену вверх
                        break;

                case Qt::Key_Down:
                        rotate_down();    // повернуть сцену вниз
                        break;

                case Qt::Key_Left:
                        rotate_left();     // повернуть сцену влево
                        break;

                case Qt::Key_Right:
                        rotate_right();   // повернуть сцену вправо
                        break;

                case Qt::Key_Z:
                        translate_down(); // транслировать сцену вниз
                        break;

                case Qt::Key_X:
                        translate_up();   // транслировать сцену вверх
                        break;

                case Qt::Key_Space:  // клавиша пробела
                        defaultScene();   // возвращение значений по умолчанию
                        break;

                case Qt::Key_Escape: // клавиша "эскейп"
                        this->close();    // завершает приложение
                        break;
                }

        updateGL(); // обновление изображени€
}

int r(int max)
{
        return (int)(((float)max)*(rand()/(RAND_MAX+1.0)));
}

void OpenglGraph::genCoords(double k,double m)
{
        for (int i=max_cnt-1; i>0; i--) {
                pol[i] = pol[i-1];
        }
        pol[0].x = k;
        pol[0].y = m;
        updateGL();
}

void OpenglGraph::scale_plus() // приблизить сцену
{
        nSca = nSca*1.1;
}

void OpenglGraph::scale_minus() // удалитьс€ от сцены
{
        nSca = nSca/1.1;
}


void OpenglGraph::rotate_up() // повернуть сцену вверх
{
        xRot += 1.0;
}

void OpenglGraph::rotate_down() // повернуть сцену вниз
{
        xRot -= 1.0;
}

void OpenglGraph::rotate_left() // повернуть сцену влево
{
        zRot += 1.0;
}

void OpenglGraph::rotate_right() // повернуть сцену вправо
{
        zRot -= 1.0;
}

void OpenglGraph::translate_down() // транслировать сцену вниз
{
        zTra -= 0.05;
}

void OpenglGraph::translate_up() // транслировать сцену вверх
{
        zTra += 0.05;
}

void OpenglGraph::defaultScene() // наблюдение сцены по умолчанию
{

          xRot=0; yRot=0; zRot=0; zTra=-2; nSca=1;
}
