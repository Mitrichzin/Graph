#ifndef CLRIB_H
#define CLRIB_H

#include <ClLine.h>


class ClRib : public ClLine
{
    public:
        ClRib();
        ClRib(int a, int b, int c, int d, int w);
        ClRib(int a, int b, int c, int d);
        virtual ~ClRib();

        char Getnum() { return *num; }
        void Setnum(int val) { itoa(val,num,10); }
        void Draw_val(){line(Getx1(),Gety1(),Getx2(),Gety2()); outtextxy((Getx1()+Getx2())/2-5,(Gety1()+Gety2())/2-10,num) ;}
        void Draw(){line(Getx1(),Gety1(),Getx2(),Gety2());}

        void Draw_align(int r){
            line(Getx1(),Gety1(),Getx2(),Gety2());
            double arc=0;
            if(Getx2()-Getx1()){
                    if((Getx2()-Getx1())>0)
                        {arc=3*M_PI_2-atan(double((Gety2()-Gety1()))/(Getx2()-Getx1()));}
                    else {arc=-atan(double(Gety2()-Gety1())/(Getx2()-Getx1()))+M_PI_2;}
            }
            else if((Gety2()-Gety1())>0) arc=M_PI;
                else arc=0;
            line(Getx2(),Gety2(),Getx2()+int(r*sin(arc+0.1)),Gety2()+int(r*cos(arc+0.1)));
            line(Getx2(),Gety2(),Getx2()+int(r*sin(arc-0.1)),Gety2()+int(r*cos(arc-0.1)));
            }

        void Draw_align_val(int r){
            line(Getx1(),Gety1(),Getx2(),Gety2());
            double arc=0;
            if(Getx2()-Getx1()){
                    if((Getx2()-Getx1())>0)
                        {arc=3*M_PI_2-atan(double((Gety2()-Gety1()))/(Getx2()-Getx1()));}
                    else {arc=-atan(double(Gety2()-Gety1())/(Getx2()-Getx1()))+M_PI_2;}
            }
            else if((Gety2()-Gety1())>0) arc=M_PI;
                else arc=0;
            line(Getx2(),Gety2(),Getx2()+int(r*sin(arc+0.1)),Gety2()+int(r*cos(arc+0.1)));
            line(Getx2(),Gety2(),Getx2()+int(r*sin(arc-0.1)),Gety2()+int(r*cos(arc-0.1)));
            outtextxy((Getx1()+2*Getx2())/3-5,(Gety1()+2*Gety2())/3-10,num) ;
            }

    protected:

    private:
        char* num;
};

#endif // CLRIB_H
