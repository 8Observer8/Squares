
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include "Scene.h"
#include "freeFunctions.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent ),
    isSecondPoint( false )
{
    std::srand( std::time( NULL ) );
}

void Scene::initializeGL()
{
    // Set drawing color
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );

    // Set color shading model to flat
    glShadeModel( GL_FLAT );
}

void Scene::paintGL()
{
    // Clear the window with current clearing color
    glClear( GL_COLOR_BUFFER_BIT );

    // Set current drawing color to red
    //		   R	 G	   B
    glColor3f( 0.0f, 0.5f, 0.5f );

//    // Axis
//    glPointSize( 1.0f );
//    glBegin( GL_LINES );
//    // X
//    glVertex2i( -300, 0 );
//    glVertex2i( 300, 0 );

//    // Y
//    glVertex2i( 0, -300 );
//    glVertex2i( 0, 300 );
//    glEnd();

//    // Points on axis
//    glPointSize( 3.0f );
//    glBegin( GL_POINTS );
//    // Points on X
//    for ( int x = -300; x < 300; x+=50 ) {
//        glVertex2i( x, 0 );
//    }

//    // Points on Y
//    for ( int y = -300; y < 300; y+=50 ) {
//        glVertex2i( 0, y );
//    }
//    glEnd();

    // Draw a filled rectangle with current color
    glPointSize( 2.0f );
    glBegin( GL_QUADS );
    for ( std::size_t i = 0; i < m_squares.size(); i++ ) {
        // Set color
        float r = m_squares[i].r();
        float g = m_squares[i].g();
        float b = m_squares[i].b();

        // Draw square
        int x1 = m_squares[i].point1().x();
        int y1 = m_squares[i].point1().y();
        int x2 = m_squares[i].point2().x();
        int y2 = m_squares[i].point2().y();
        int x3 = m_squares[i].point3().x();
        int y3 = m_squares[i].point3().y();
        int x4 = m_squares[i].point4().x();
        int y4 = m_squares[i].point4().y();

        glVertex2i( x1, y1 );
        glColor3f( r, g, b );
        glVertex2i( x2, y2 );
        glColor3f( r, g, b );
        glVertex2i( x3, y3 );
        glColor3f( r, g, b );
        glVertex2i( x4, y4 );
        glColor3f( r, g, b );
    }
    glEnd();

    glColor3f( 0.0f, 0.5f, 0.5f );
}

void Scene::resizeGL( int w, int h )
{
    m_w = w;
    m_h = h;

    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Reset coordinate system
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    GLfloat aspectRatio = ( GLfloat ) w / ( GLfloat ) h;

    int windowWidth;
    int windowHeight;
    int size = 250;

    if ( w <= h ) {
        windowWidth = size;
        windowHeight = size / aspectRatio;
        glOrtho( -size, size, -windowHeight, windowHeight,
                 1.0, -1.0 );
    } else {
        windowWidth = size * aspectRatio;
        windowHeight = size;
        glOrtho( -windowWidth, windowWidth, -size, size,
                 1.0, -1.0 );
    }

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Scene::mousePressEvent( QMouseEvent *pe )
{
    int x = pe->pos().x() - m_w / 2;
    int y = -( pe->pos().y() - m_h / 2 );

    if ( isSecondPoint ) {
        m_p2.setX( x );
        m_p2.setY( y );
        float r = ( float ) random( 0, 1 );
        float g = ( float ) random( 0, 1 );
        float b = ( float ) random( 0, 1 );
        shapes::Square s( m_p1, m_p2 );
        s.setColor( r, g, b );
        m_squares.push_back( s );
        isSecondPoint = false;
    } else {
        m_p1.setX( x );
        m_p1.setY( y );
        isSecondPoint = true;
    }

    updateGL();
}
