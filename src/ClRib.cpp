#include <ClRib.h>

ClRib::ClRib()
{
    //ctor
}
ClRib::ClRib(int a, int b, int c, int d,int w):ClLine(a,b,c,d), num(new char[4]){
//cout <<"clRib(int, int, int, int, int);\n";
itoa(w,num,10);
}
ClRib::ClRib(int a, int b, int c, int d):ClLine(a,b,c,d){
//cout <<"clRib(int, int, int, int);\n";
}
ClRib::~ClRib()
{
    //dtor
}
