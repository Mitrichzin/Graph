#ifndef CLCIRCLE_H
#define CLCIRCLE_H
#include"ClDraw.h"

class ClCircle: public ClDraw
{
    public:
        ClCircle();
        ClCircle(int a, int b, int c);
        virtual ~ClCircle();

         int Getx() { return x; }
        void Setx( int val) { x = val; }
         int Gety() { return y; }
        void Sety( int val) { y = val; }
         int Getr() { return r; }
        void Setr( int val) { r = val; }
        void Draw(){circle(x,y,r);}

    protected:

    private:
         int x;
         int y;
         int r;
};
#endif // CLCIRCLE_H
