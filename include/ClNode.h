#ifndef CLNODE_H
#define CLNODE_H

#include <ClCircle.h>


class ClNode : public ClCircle
{
    public:
        ClNode();
        ClNode( int x, int y, int r, int i);
        virtual ~ClNode();

        char Getnum() { return *num; }
        void Setnum(int val) { itoa(val,num,10); }
        void Draw(){circle(Getx(),Gety(),Getr()); outtextxy(Getx()-4,Gety()-8,num) ;}
    protected:

    private:
        char *num;
};

#endif // CLNODE_H
