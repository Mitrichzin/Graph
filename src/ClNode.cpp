#include <ClNode.h>

ClNode::ClNode():ClCircle(), num(new char[4]){
//cout <<"ClNode();\n";
}
ClNode::ClNode(int a, int b, int c, int i):ClCircle(a,b,c), num(new char[4]){
//cout <<"clNode(int, int, int, int);\n";
itoa(i,num,10);
}
ClNode::~ClNode()
{
    //dtor
}
