#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <QGLWidget>
#include <QMouseEvent>
#include "Square.h"

class Scene : public QGLWidget
{
public:
    Scene( QWidget *parent = 0 );

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );
    void mousePressEvent( QMouseEvent* pe );

private:
    std::vector<shapes::Square> m_squares;
    bool isSecondPoint;
    int m_h;
    int m_w;
    shapes::Point m_p1;
    shapes::Point m_p2;
};

#endif // SCENE_H
