#include <iostream>
using namespace std;
int main()
{
    int n, e, source;
    int graph[10][10] = {0};
    int distance[10], visited[10];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges and weights:\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;  
    }
    cout << "Enter source vertex: ";
    cin >> source;
    source--;
    for (int i = 0; i < n; i++)
    {
        distance[i] = 999;
        visited[i] = 0;
    }
    distance[source] = 0;
    for (int count = 0; count < n; count++)
    {
        int min = 999;
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && distance[i] < min)
            {
                min = distance[i];
                u = i;
            }
        }
        if (u == -1)
            break;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
    cout << "\nShortest distances:\n";
    for (int i = 0; i < n; i++)
    {
        cout << source + 1 << " -> " << i + 1
             << " = " << distance[i] << endl;
    }
    return 0;
}
