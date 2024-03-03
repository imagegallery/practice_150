//Time complexity: O(V+E)
//Space complexity: O(V)
#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int v;
        vector<list<int>> adj;
    public:
        Graph(int v);
        void addEdge(int u, int v);
        void BFS(int s);
};

Graph::Graph(int v){
    this->v = v;
    adj.resize(v);
}
void Graph:: addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::BFS(int s){
    vector<bool> visited(v, false);
    
    list<int> q;
    visited[s] = true;
    q.push_back(s);
    while(!q.empty()){
        int temp = q.front();
        cout << temp << " ";
        q.pop_front();

        for(auto adjacent:adj[temp]){
            if(visited[adjacent] == false){
                visited[adjacent] = true;
                q.push_back(adjacent);
            }
        }
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS of given graph strating from node 2 " <<endl;
    g.BFS(2);
    return 0;
}