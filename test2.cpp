#include<ClGraph.h>
int main()
{
    setlocale(LC_ALL,"Rus");
    ClGraph Graf;
    Graf.SetGraph();
    int w=1600,h=900;
    int gd=CUSTOM, gm=CUSTOM_MODE(w,h);
    cout <<"���������� ��������������� ����, � ���� ����������� �������� �������� ������������ ��������� �������"<<endl<<"������� ����� ������� ";
    int n;
    cin>>n;
    initgraph(&gd,&gm," ");
    Graf.Draw(1,1);
    Graf.Dejkstra(n-1);
    readkey();
    readkey();
    readkey();
    closegraph();
    return 0;
}
