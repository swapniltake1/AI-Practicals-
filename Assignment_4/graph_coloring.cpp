#include<bits/stdc++.h>
#define v 1001
using namespace std;
int n,e,i,j;
vector<vector<int> > graph;
vector<int> color;
bool visited[v];
void graphColoring()
{
    color[0]  = 0;
    for (i=1;i<n;i++)
        color[i] = -1;
 
    bool unused[n];
 
    for (i=0;i<n;i++)
        unused[i]=0;
 
 
    for (i = 1; i < n; i++)
    {
        for (j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                unused[color[graph[i][j]]] = true;
        int cr;
        for (cr=0;cr<n;cr++)
            if (unused[cr] == false)
                break;
 
        color[i] = cr; 
 
        for (j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                unused[color[graph[i][j]]] = false;
    }
}
 
int main()
{
    int x,y;
    cout<<"Enter number of vertices:" << endl;
    cin>>n;
    graph.resize(n);
    color.resize(n);
    cout<<"Enter number of edges:"<<endl;
    cin>>e;
    color.resize(n);
    memset(visited,0,sizeof(visited));
    while(e--)
    {
        cout<<"Enter edge vertices of edge "<<i+1<<" :"<<endl;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    graphColoring();
    for(i=0;i<n;i++)
    {
        cout<<"Vertex "<<i<<" is coloured "<<color[i]+1<<"\n";
    }
}