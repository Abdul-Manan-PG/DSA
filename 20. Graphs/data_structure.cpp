#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph (int V){
        this->V = V;
        l = new list<int> [V];
    }
    void addEgde (int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for (int i = 0; i < V; i++){
            cout << i << ": ";
            for (int neigh : l[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    void BFS(){
        queue<int> q;
        vector<bool> vis(V, false);

        cout << "BFS traversal: ";
        q.push(0);
        vis[0] = true;
        while (!q.empty()){
            int u = q.front();
            q.pop();

            cout << u << ' ';

            for (int v : l[u]){
                if (!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEgde(0, 1);
    g.addEgde(1, 2);
    g.addEgde(1, 3);
    g.addEgde(2, 3);
    g.addEgde(2, 4);

    g.print();

    g.BFS();
    return 0;
}