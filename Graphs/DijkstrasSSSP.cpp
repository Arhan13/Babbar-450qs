#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

class Graph

{

    //V is the number o vertexes
    int V;
    //In a weighted graph we will store vertex and the weight pair of each edge
    //vertex, weight
    list<pair<int, int>> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    //Prints shortest path from s
    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src)
{
    set<pair<int, int>> setds;
    vector<int> dist(V, INF);
    //Inside set we have weight, vertex
    setds.insert(make_pair(0, src));
    dist[src] = 0;

    while (!setds.empty())
    {
        //First vertex in the set is the minimum distance vertex
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        for (auto x : adj[u])
        {
            //Searching in the adj list
            int v_vertex = x.first;
            int w_weight = x.second;

            if (dist[v_vertex] > dist[u] + w_weight)
            {
                if (dist[v_vertex] != INF)
                {
                    setds.erase(setds.find(make_pair(dist[v_vertex], v_vertex)));
                }
                //Else
                dist[v_vertex] = dist[u] + w_weight;
                setds.insert(make_pair(dist[v_vertex], v_vertex));
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}