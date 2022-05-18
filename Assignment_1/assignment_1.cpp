#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs_recursive(vector <int> graph[],int s,bool visited[]){
    visited[s] = true;
    cout<<s<<"  ";
    for (auto current:graph[s]){
        if (visited[current] == false){
            dfs_recursive(graph,current,visited);
        }
    }
}
void search_recursive(vector <int> graph[],int s,bool visited[],int x){
    visited[s] = true;
    cout<<s<<"  ";
    for (auto current:graph[s]){
        if (current == x){
            cout << "Vertex found !!!" << endl;
            return;
        }
        if (visited[current] == false){
            dfs_recursive(graph,current,visited);
        }
    }

}
void dfs(vector <int> graph[],int v,int s){
    bool visited[v];
    for (int i{0};i<v;++i){
        visited[i] = false;
    }
    dfs_recursive(graph,s,visited);

}
void search(vector <int> graph[],int v,int s,int x){
    bool visited[v];
    for (int i{0};i<v;++i){
        visited[i] = false;
    }
    search_recursive(graph,s,visited,x);

}
void recursiveBFS(vector <int> graph[], queue<int> &q, vector<bool> &discovered)
{
    if (q.empty()) {
        return;
    }
 
    int v = q.front();
    q.pop();
    cout << v << " ";
    for (int u: graph[v])
    {
        if (!discovered[u])
        {
            discovered[u] = true;
            q.push(u);
        }
    }
 
    recursiveBFS(graph, q, discovered);
}
int main(){
    cout << "Enter total number of vertices" << endl;
	int size;
	cin>>size;
	vector <int> g[size];
	int edges;
	cout << "Enter number of edges" << endl;
	cin >> edges;
	for (int i=0;i<edges;i++){
		int w,x;
		cout << "Enter Edge Vertices" << endl;
		cin>> w >> x;
		g[w].push_back(x);
		g[x].push_back(w);
	}
        vector <bool> d;
        for (int i=0;i<size;i++) d.push_back(false);
        d[0] = true;
        queue <int> qu;
        qu.push(0);
        cout << "DFS" << endl;
	    dfs(g,size,0);
        cout << endl;
        cout << "BFS" << endl;
        recursiveBFS(g,qu,d);
        cout << endl;
        cout << "Enter a vertex to search for" << endl;
        int ver; 
        cin>>ver;
        search(g,size,0,ver);
	return 0;
}

