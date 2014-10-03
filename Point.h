#ifndef POINT_H
#define POINT_H

namespace shapes {

    class Point
    {
    public:
        Point( int x = 0, int y = 0 );

        void setX( int x );
        void setY( int y );

        int x() const;
        int y() const;

    private:
        int m_x;
        int m_y;
    };

}

#endif // POINT_H
