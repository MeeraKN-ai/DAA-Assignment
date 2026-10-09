#include <iostream>
using namespace std;
#define MAX 100
#define INF 999999
int graph[MAX][MAX];
int V, E;
bool created = false;
void createGraph()
{
    int u, v, w;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    if (V <= 0 || V > MAX || E < 0)
    {
        cout << "Invalid number of vertices or edges";
        created = false;
        return;
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        if (u < 0 || u >= V || v < 0 || v >= V || w < 0)
        {
            cout << "Invalid edge or negative weight";
            created = false;
            return;
        }
        graph[u][v] = w;
    }
    created = true;
    cout << "Graph created successfully";
}
void displayEdges()
{
    if (!created)
    {
        cout << "Create the graph first";
        return;
    }
    cout << "\nEdges of the graph:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j && graph[i][j] != INF)
            {
                cout << i << " -> " << j
                     << " : " << graph[i][j] << "\n";
            }
        }
    }
}
void dijkstra()
{
    if (!created)
    {
        cout << "Create the graph first";
        return;
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    if (source < 0 || source >= V)
    {
        cout << "Invalid source vertex";
        return;
    }
    int dist[MAX];
    bool visited[MAX] = {false};
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[source] = 0;
    for (int count = 0; count < V; count++)
    {
        int minDist = INF;
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1)
            break;
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "\nShortest distances from vertex "
         << source << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << source << " -> " << i << " : ";
        if (dist[i] == INF)
            cout << "Unreachable";
        else
            cout << dist[i];
        cout << "\n";
    }
}
int main()
{
    int choice;
    cout << "\n\n1. Create the weighted directed graph";
    cout << "\n2. Display the edges";
    cout << "\n3. Find shortest paths using Dijkstra's algorithm";
    cout << "\n4. Quit";
    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            createGraph();
            break;
        case 2:
            displayEdges();
            break;
        case 3:
            dijkstra();
            break;
        case 4:
            cout << "Exiting program";
            break;
        default:
            cout << "Invalid choice";
        }
    } while (choice != 4);
    return 0;
}
