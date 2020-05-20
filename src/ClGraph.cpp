#include <ClGraph.h>
#include <ClNode.h>
#include <ClRib.h>
ClGraph::ClGraph()
{

}

ClGraph::~ClGraph()
{
    //dtor
}

void ClGraph::Draw(int align, int val)
{
    for (int i=0;i<n;i++)
    {
        int x=800+300*cos((2*M_PI*i)/n);
        int y=400+300*sin((2*M_PI*i)/n);
        ClNode Base(x,y,20,nodes[i]);
        Base.Draw();
    }
    int st,fin;

    for (int i=0;i<m;i++)
    {
        st=fin=0;
        for(int j=0;j<n;j++)
        {
            if ((matrix[j*m+i]==1)&&st)
                fin=j;
            if ((matrix[j*m+i]==1)&&!st)
                st=j;
            if (matrix[j*m+i]==(-1))
                {
                    fin=j;
                }
        }
        if (align&&val)
        {
            ClRib Rebro(int(800+300*cos((2*M_PI*st)/n))-20,int(400+300*sin((2*M_PI*st)/n)),int(800+300*cos((2*M_PI*fin)/n))-20,int(400+300*sin((2*M_PI*fin)/n)),weights[i]);
            Rebro.Draw_align_val(30);
        }
        else
         if(align)
         {
            ClRib Rebro(int(800+300*cos((2*M_PI*st)/n))-20,int(400+300*sin((2*M_PI*st)/n)),int(800+300*cos((2*M_PI*fin)/n))-20,int(400+300*sin((2*M_PI*fin)/n)));
            Rebro.Draw_align(30);
        }
        else
            if(val)
                {
            ClRib Rebro(int(800+300*cos((2*M_PI*st)/n))-20,int(400+300*sin((2*M_PI*st)/n)),int(800+300*cos((2*M_PI*fin)/n))-20,int(400+300*sin((2*M_PI*fin)/n)),weights[i]);
            Rebro.Draw_val();
            }
        else
        {
             ClRib Rebro(int(800+300*cos((2*M_PI*st)/n))-20,int(400+300*sin((2*M_PI*st)/n)),int(800+300*cos((2*M_PI*fin)/n))-20,int(400+300*sin((2*M_PI*fin)/n)));
             Rebro.Draw();
        }
    }
}
void ClGraph::Draw()
{
    for (int i=0;i<n;i++)
    {
        int x=800+300*cos((2*M_PI*i)/n);
        int y=400+300*sin((2*M_PI*i)/n);
        ClNode Base(x,y,20,nodes[i]);
        Base.Draw();
    }
    int st,fin,align;

    for (int i=0;i<m;i++)
    {
        align=st=fin=0;
        for(int j=0;j<n;j++)
        {
            if ((matrix[j*m+i]==1)&&st)
                fin=j;
            if ((matrix[j*m+i]==1)&&!st)
                st=j;
            if (matrix[j*m+i]==(-1))
                {
                    fin=j;
                    align=1;
                }
        }
        if (align)
        {
            ClRib Rebro(int(800+300*cos((2*M_PI*st)/n))-20,int(400+300*sin((2*M_PI*st)/n)),int(800+300*cos((2*M_PI*fin)/n))-20,int(400+300*sin((2*M_PI*fin)/n)));
            Rebro.Draw_align(30);
        }
        else
        {
             ClRib Rebro(int(800+300*cos((2*M_PI*st)/n))-20,int(400+300*sin((2*M_PI*st)/n)),int(800+300*cos((2*M_PI*fin)/n))-20,int(400+300*sin((2*M_PI*fin)/n)));
             Rebro.Draw();
        }
    }
}
void ClGraph::SetGraph()
{
    ifstream fin;
    fin.open("input.txt",ios_base::in);
    fin>>n;
    m=0;
    int temp,counter=0;
    vector <int> tmp_matrix;
    tmp_matrix.reserve(n*n);
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
            fin>>tmp_matrix[i*n+j];
            if(tmp_matrix[i*n+j])
                m++;
            }
    }

    matrix.reserve(m*n);
    weights.reserve(m);
    for(int i=0; i<m;i++)
        for(int j=0;j<n;j++)
          matrix[j*m+i]=0;
    cout<<"Количество ребер="<<m<<endl;
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
            {

            if(tmp_matrix[i*n+j]){

                matrix[i*m+counter]=1;
                matrix[j*m+counter]=-1;
                weights[counter]=tmp_matrix[i*n+j];
                counter++;

                }
            }
    }
    nodes.reserve(n);

    for(int i=0; i<n;i++)
        nodes[i]=i+1;
        //for(int i=0; i<m;i++)
        //fin>>weights[i];
}
void ClGraph::Dejkstra(int k)
{
    vector<int> watch,dist,last,add_dist;
    watch.reserve(n);
    dist.reserve(n);
    add_dist.reserve(n*n);
    last.reserve(n);
    for(int j=0;j<n;j++)
        for(int i=0;i<n;i++)
            add_dist[j*n+i]=10000;
    for (int i=0;i<m;i++)
    {
        int st=0,fin=0;
        for(int j=0;j<n;j++)
        {
            if ((matrix[j*m+i]==1)&&!st)
                st=j;
            if (matrix[j*m+i]==(-1))
                {
                    fin=j;
                }
        }
        add_dist[st*n+fin]=weights[i];
        //cout<<"{"<<st+1<<" "<<fin+1<<"|"<<add_dist[st*n+fin]<<"}"<<endl;
    }
    for(int i=0; i<n;i++)
    {
        watch[i]=0;
        last[i]=k;
        dist[i]=add_dist[k*n+i];
    }
    last[k]=-1;
    watch[k]=1;
    dist[k]=0;
    int sum=1;
    while(sum!=n)
    {
    int minim=10000;
    int minim_i=0;
    for(int j=0;j<n;j++)
        if (!watch[j])
            if (dist[j]<minim)
                {
                    minim=dist[j];
                    minim_i=j;
                }
    watch[minim_i]=1;
    for(int j=0;j<n;j++)
        if((add_dist[minim_i*n+j]+dist[minim_i])<dist[j])
        {
            dist[j]=(add_dist[minim_i*n+j]+dist[minim_i]);
            last[j]=minim_i;
            //cout<<"["<<dist[j]<<"]"<<endl;
        }

    sum++;
    };
    for(int i=0;i<n;i++)
    {
        if(dist[i]<10000)
            {
                cout<<"\nКратчайшее расстояние от "<<k+1<<" до "<<i+1<<" вершины = "<<dist[i]<<"\nА путь идет через вершины "<<i+1<<" ";
                int c=i;
        while(last[c]!=-1)
        {
            cout<<last[c]+1<<" ";
            c=last[c];
        }
            }
        else
            cout<<"\nКратчайшее расстояние от "<<k+1<<" до "<<i+1<<" вершины не существует";

    }
}
