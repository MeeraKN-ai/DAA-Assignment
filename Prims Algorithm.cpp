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
    int selected[100];
    for (int i = 1; i <= V; i++)
        selected[i] = 0;
    selected[1] = 1;
    int count = 0;
    int cost = 0;
    cout << "\nEdges in Minimum Spanning Tree:\n";
    while (count < V - 1)
    {
        int min = 999;
        int x = -1;
        int y = -1;
        for (int i = 0; i < E; i++)
        {
            int u = edge[i].u;
            int v = edge[i].v;
            int w = edge[i].w;
            if ((selected[u] == 1 && selected[v] == 0) ||
                (selected[v] == 1 && selected[u] == 0))
            {
                if (w < min)
                {
                    min = w;
                    x = u;
                    y = v;
                }
            }
        }
        if (x == -1)
        {
            cout << "Graph is not connected.";
            return 0;
        }
        cout << x << " - " << y << " = " << min << endl;
        cost = cost + min;
        if (selected[x] == 0)
            selected[x] = 1;
        else
            selected[y] = 1;
        count++;
    }
    cout << "\nMinimum Cost = " << cost << endl;
    return 0;
}
