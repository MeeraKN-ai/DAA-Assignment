#include <iostream>
using namespace std;
struct Edge
{
    int u, v, w;
};
int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Edge edge[100];
    cout << "Enter source, destination and weight:\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    int d[100];
    for (int i = 1; i <= V; i++)
    {
        d[i] = 999;
    }
    d[source] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;
            if (d[u] != 999 && d[u] + w < d[v])
            {
                d[v] = d[u] + w;
            }
        }
    }
    for (int j = 0; j < E; j++)
    {
        int u = edge[j].u;
        int v = edge[j].v;
        int w = edge[j].w;
        if (d[u] != 999 && d[u] + w < d[v])
        {
            cout << "Negative weight cycle exists.";
            return 0;
        }
    }
    cout << "\nShortest distances:\n";
    for (int i = 1; i <= V; i++)
    {
        cout << "Vertex " << i << " = " << d[i] << endl;
    }
    return 0;
}
