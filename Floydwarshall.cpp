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
    cin >> V
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
        if (u < 0 || u >= V || v < 0 || v >= V)
        {
            cout << "Invalid vertex. Create the graph again.\n";
            created = false;
            return;
        }
        if (w < graph[u][v])
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
void floydWarshall()
{
    if (!created)
    {
        cout << "Create the graph first";
        return;
    }
    int dist[MAX][MAX];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    }
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] =dist[i][k] + dist[k][j];
                }
            }
        }
    }
    cout << "\nAll-Pairs Shortest Distance Matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }
    for (int i = 0; i < V; i++)
    {
        if (dist[i][i] < 0)
        {
            cout << "Warning: Negative-weight cycle detected.";
            return;
        }
    }
}
int main()
{
    int choice;
    cout << "\n\n1. Create the weighted directed graph";
    cout << "\n2. Display the edges";
    cout << "\n3. Compute all-pairs shortest distances";
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
            floydWarshall();
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
