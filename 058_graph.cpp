#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

/*
class Graph{
    public:
        unordered_map<int, vector<pair<int, int>>> adjList;

        void addEdge(int u, int v, int wt, bool direction) {
            if(direction == 1) {
                //directed edge
                //u->v
                adjList[u].push_back(make_pair(v, wt));
            } else {
                //undirected edge
                //u--v
                //u->(v, wt) and v->(u, wt)
                adjList[u].push_back(make_pair(v, wt));
                adjList[v].push_back(make_pair(u, wt));
            }
        }

        void printAdjacencyList() {
            for(auto i : adjList) {
                //i -> record or pair
                //i.first -> int
                //i.second -> vector<pair<int, int>>
                cout << i.first << " : ";
                cout << "{";
                for(auto j : i.second) {
                    //j -> pair of int, int
                    //j.first represents "v"
                    //j.second represents "wt"
                    cout << "(" << j.first << ", " << j.second << "), ";
                }
                cout << "}" << endl;
            }
        }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 10, 1);
    g.addEdge(1, 2, 20, 1);
    g.addEdge(2, 3, 30, 1);
    g.addEdge(3, 4, 40, 1);
    
    g.printAdjacencyList();
}
*/


class Graph{
    public:
        //adjacency list
        unordered_map<int, vector<int>> adjList;
        
        //direction = 1 -> directed edge
        //direction = 0 -- undirected edge
        void addEdge(int u, int v, bool direction) {
            if(direction == 1) {
                adjList[u].push_back(v);
            }
            else {
                //undirected edge
                //u -- v equivalent to u->v, v->u
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        void printAdjacencyList() {
            for(auto i : adjList) {
                //i -> record or pair of key and value
                //i.first -> integer
                //i.second -> vector<int>
                cout << i.first << ": ";
                cout << "{";
                for(auto j : i.second) {
                    cout << j << ", ";
                }
                cout << "}" << endl;
            }
        }

        void bfsTraversal(int src) {
            queue<int> q;
            unordered_map<int, bool> visited;
            
            //initial state
            q.push(src);
            visited[src] = true;

            //main logic
            while(!q.empty()) {
                int frontNode = q.front();
                q.pop();

                cout << frontNode << ", ";
                for(auto nbr : adjList[frontNode]) {
                    //hr ek nbr ko queue me insert krna h
                    //but insert tabhi krna h agar unvisited ho
                    if(!visited[nbr]) {
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
        }

        //entire dfs logic resides inside dfsHelper function
        void dfsHelper(int src, unordered_map<int, bool>& visited) {
            //jaise hi call aayi sabse pehele
            //ans print karo
            //visited true mark kro
            cout << src << ", ";
            visited[src] = true;

            //abb current node se iske nbr ki taraf call mrni h
            for(auto nbr : adjList[src]) {
                //agar nbr visited nahi h to uske liye
                //dfs call krna h
                if(!visited[nbr]) {
                    dfsHelper(nbr, visited);
                }
            }
        }

        void dfsTraversal(int src, int n) {
            unordered_map<int, bool> visited;

            //function call for src node
            for(int src=0; src<n; src++) {
                if(!visited[src]) {
                    dfsHelper(src, visited);
                }
            }
        }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 8, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(8, 4, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(4, 7, 0);
    g.addEdge(5, 6, 0);
    g.addEdge(7, 6, 0);
    
    //graph looks list 0->1->2->3->4
    g.printAdjacencyList();

    g.bfsTraversal(0);

    cout << "DFS: " << endl;

    g.dfsTraversal(0, 10);
    return 0;
}
