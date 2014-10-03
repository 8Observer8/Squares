
#include "Square.h"

namespace shapes {

    Square::Square( const Point &p1,
                    const Point &p2,
                    float r,
                    float g,
                    float b )
    {
        setPoints( p1, p2 );
        setColor( r, g, b );
    }

    void Square::setPoints(const Point &p1, const Point &p2)
    {
        m_p1 = p1;
        m_p3 = p2;

        float x0 = ( (float) p1.x() + (float) p2.x() ) / 2.0f;
        float y0 = ( (float) p1.y() + (float) p2.y() ) / 2.0f;

        float x3 = x0 + ( (float) p2.y() - (float) p1.y() ) / 2.0f;
        float y3 = y0 + ( (float) p1.x() - (float) p2.x() ) / 2.0f;
        m_p4.setX( (int) x3 );
        m_p4.setY( (int) y3 );

        float x4 = x0 - ( (float) p2.y() - (float) p1.y() ) / 2.0f;
        float y4 = y0 - ( (float) p1.x() - (float) p2.x() ) / 2.0f;
        m_p2.setX( (int) x4 );
        m_p2.setY( (int) y4 );
    }

    Point Square::point1() const
    {
        return m_p1;
    }

    Point Square::point2() const
    {
        return m_p2;
    }

    Point Square::point3() const
    {
        return m_p3;
    }

    Point Square::point4() const
    {
        return m_p4;
    }

    float Square::r() const
    {
        return m_r;
    }

    float Square::g() const
    {
        return m_g;
    }

    float Square::b() const
    {
        return m_b;
    }

    void Square::setColor( float r, float g, float b )
    {
        // Set red
        if ( r < 0.0f ) {
            m_r = 0.0f;
        } else if ( r > 1.0f ) {
            m_r = 1.0f;
        } else {
            m_r = r;
        }

        // Set green
        if ( g < 0.0f ) {
            m_g = 0.0f;
        } else if ( g > 1.0f ) {
            m_g = 1.0f;
        } else {
            m_g = g;
        }

        // Set blue
        if ( b < 0.0f ) {
            m_b = 0.0f;
        } else if ( b > 1.0f ) {
            m_b = 1.0f;
        } else {
            m_b = b;
        }
    }

}
