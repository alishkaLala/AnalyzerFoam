#ifndef OPENGLGRAPH_H
#define OPENGLGRAPH_H


#include <QMouseEvent>
#include <QGLWidget>
#include <QColorDialog>
#include <QTimer>
#include <QtOpenGL>
#include <QtGui>
#include <imageprocessing.h>
#include <QEvent>

const int max_cnt = 200;

struct myPoints {
        double x;
        double y;
};

class OpenglGraph : public QGLWidget
{

public:
        myPoints * pol;
        GLfloat jjj;
        OpenglGraph(ImageProcessing *worker, QWidget *parent = 0);
        void showEvent(QShowEvent *event);
protected:
        virtual void initializeGL();
        virtual void resizeGL(int width, int height);
        virtual void paintGL();
        virtual void mousePressEvent(QMouseEvent *event);
        virtual void mouseMoveEvent(QMouseEvent *event);
        virtual void wheelEvent(QWheelEvent* pe);
        virtual  void keyPressEvent(QKeyEvent* pe);


private:
        ImageProcessing *worker;
        QPoint ptrMousePosition;
        GLfloat xRot; // переменна€ хранит угол поворота вокруг оси X
        GLfloat yRot; // переменна€ хранит угол поворота вокруг оси Y
        GLfloat zRot; // переменна€ хранит угол поворота вокруг оси Z

        void scale_plus();     // приблизить сцену
        void scale_minus();    // удалитьс€ от сцены
        void rotate_up();      // повернуть сцену вверх
        void rotate_down();    // повернуть сцену вниз
        void rotate_left();    // повернуть сцену влево
        void rotate_right();   // повернуть сцену вправо
        void translate_down(); // транслировать сцену вниз
        void translate_up();   // транслировать сцену вверх
        void defaultScene();   // наблюдение сцены по умолчанию
        void drawAxis();
        void draw();

        GLfloat zTra; // переменна€ хранит величину трансл€ции оси Z
        GLfloat nSca; // переменна€ отвечает за масштабирование обьекта


        QPoint lastPos;

public slots:
        void genCoords(double k,double m);
};

#endif // OPENGLGRAPH_H
