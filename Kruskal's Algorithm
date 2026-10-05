#include <iostream>
using namespace std;
struct Edge
{
    int u, v, weight;
};
int findParent(int parent[], int vertex)
{
    while (parent[vertex] != vertex)
    {
        vertex = parent[vertex];
    }
    return vertex;
}
void unionSet(int parent[], int u, int v)
{
    int parentU = findParent(parent, u);
    int parentV = findParent(parent, v);
    parent[parentV] = parentU;
}
int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Edge edges[100];
    cout << "\nEnter edges (source destination weight):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    int parent[100];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    int totalCost = 0;
    int edgeCount = 0;
    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);
        if (parentU != parentV)
        {
            cout << u << " - " << v << " : " << weight << endl;
            totalCost = totalCost + weight;
            edgeCount++;
            unionSet(parent, u, v);
            if (edgeCount == V - 1)
            {
                break;
            }
        }
    }
    cout << "\nMinimum Cost = " << totalCost << endl;
    return 0;
}
