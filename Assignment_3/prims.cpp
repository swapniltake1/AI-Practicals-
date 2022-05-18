#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;
void addEdge(vector <pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void primMST(vector<pair<int,int> > adj[], int V)
{

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    int src = 0;

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
          if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true;
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (inMST[v] == false && key[v] > weight)
            {

                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}
int main()
{
    int vertex;
    cout << "Enter number of vertices" << endl;
    cin >> vertex;
    int edges;
    cout << "Enter number of edges" << endl;
    cin>> edges;
    vector<pair<int,int> > adj[vertex];
    while(edges--){
        int fir,sec,wei;
        cout << "Enter initial vertex" << endl;
        cin>>fir;
        cout << "Enter end vertex"<< endl;
        cin>>sec;
        cout << "Enter distance between two vertices" << endl;
        cin>>wei;
        addEdge(adj,fir,sec,wei);

    }
    primMST(adj,vertex);
    return 0;
}
