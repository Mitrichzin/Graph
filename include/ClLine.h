#ifndef CLLINE_H
#define CLLINE_H
#include<ClDraw.h>

class ClLine: public ClDraw
{
    public:
        ClLine();
        ClLine(int a,int b,int c, int d);
        virtual ~ClLine();

        int Getx1() { return x1; }
        void Setx1(int val) { x1 = val; }
        int Gety1() { return y1; }
        void Sety1(int val) { y1 = val; }
        int Getx2() { return x2; }
        void Setx2(int val) { x2 = val; }
        int Gety2() { return y2; }
        void Sety2(int val) { y2 = val; }
        void Draw(){line(x1,y1,x2,y2);}

    protected:

    private:
        int x1;
        int y1;
        int x2;
        int y2;
};

#endif // CLLINE_H
