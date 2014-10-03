#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"

namespace shapes {

    class Square
    {
    public:
        Square( const Point &p1,
                const Point &p2,
                float r = 0.0f,
                float g = 0.0f,
                float b = 1.0f );

        void setPoints( const Point &p1,
                        const Point &p2 );

        Point point1() const;
        Point point2() const;
        Point point3() const;
        Point point4() const;

        float r() const;
        float g() const;
        float b() const;

        void setColor( float r, float g, float b );

    private:
        Point m_p1;
        Point m_p2;
        Point m_p3;
        Point m_p4;
        float m_r;
        float m_g;
        float m_b;
    };

}

#endif // SQUARE_H
