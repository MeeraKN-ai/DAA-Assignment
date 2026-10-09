#include <iostream>
using namespace std;
#define MAX 100
int adj[MAX][MAX];
int degree[MAX];
int V, E;
bool created = false;
void createGraph()
{
    int u, v;
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
        degree[i] = 0;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        if (u < 0 || u >= V || v < 0 || v >= V)
        {
            cout << "Invalid vertex. Enter the graph again.\n";
            created = false;
            return;
        }
        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;
    }
    created = true;
    cout << "Graph created successfully";
}
void displayGraph()
{
    if (!created)
    {
        cout << "Create the graph first";
        return;
    }
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < degree[i]; j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
}
void BFS(int start)
{
    if (!created)
    {
        cout << "Create the graph first";
        return;
    }
    if (start < 0 || start >= V)
    {
        cout << "Invalid starting vertex";
        return;
    }
    bool visited[MAX] = {false};
    int queue[MAX];
    int front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;
    cout << "BFS Traversal: ";
    while (front < rear)
    {
        int current = queue[front++];
        cout << current << " ";
        for (int i = 0; i < degree[current]; i++)
        {
            int next = adj[current][i];
            if (!visited[next])
            {
                visited[next] = true;
                queue[rear++] = next;
            }
        }
    }
}
int main()
{
    int choice, start;
    cout << "\n\n1. Create the graph";
    cout << "\n2. Display the adjacency list";
    cout << "\n3. Breadth-First Search";
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
            displayGraph();
            break;
        case 3:
            cout << "Enter starting vertex: ";
            cin >> start;
            BFS(start);
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
