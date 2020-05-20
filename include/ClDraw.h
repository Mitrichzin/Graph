#ifndef CLDRAW_H
#define CLDRAW_H
#include <graphics.h>
#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<locale>

using namespace std;

class ClDraw
{
    public:
        void virtual Draw()=0;
};

#endif // CLDRAW_H
