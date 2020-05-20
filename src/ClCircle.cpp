#include <ClCircle.h>
ClCircle::ClCircle(){
//cout <<"ClCircle();\n";
}
ClCircle::ClCircle(int a, int b, int c){
//cout <<"ClCircle(int, int, int);\n";
Setx(a);
Sety(b);
Setr(c);
}
ClCircle::~ClCircle()
{
    //dtor
}
