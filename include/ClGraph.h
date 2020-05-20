#ifndef CLGRAPH_H
#define CLGRAPH_H
#include <vector>
#include <ClDraw.h>
#include <ClNode.h>
#include <ClRib.h>
class ClGraph : public ClDraw
{
    public:
        ClGraph();
        virtual ~ClGraph();
        void Draw(int k,int l);
        void Draw();
        void SetGraph();
        int Getn() { return n; }
        void Setn( int val) { n = val; }
        int Getm() { return m; }
        void Setm( int val) { m = val; }
        void Dejkstra(int k);
    protected:

    private:
        int n;
        int m;
        vector <int> matrix;
        vector <int> nodes;
        vector <int> weights;
};

#endif // CLGRAPH_H
