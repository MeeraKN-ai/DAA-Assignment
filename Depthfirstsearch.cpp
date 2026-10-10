#include <iostream>
using namespace std;
#define MAX 100
int adj[MAX][MAX];
int degree[MAX];
int V, E;
bool created = false;
void createGraph(){
    int u, v;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    if (V <= 0 || V > MAX || E < 0){
        cout << "Invalid number of vertices or edges";
        created = false;
        return;
    }
    for (int i = 0; i < V; i++)
        degree[i] = 0;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++){
        cin >> u >> v;
        if (u < 0 || u >= V || v < 0 || v >= V){
            cout << "Invalid vertex. Create the graph again.\n";
            created = false;
            return;
        }
        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;
    }
    created = true;
    cout << "Graph created successfully";
}
void displayGraph(){
    if (!created){
        cout << "Create the graph first";
        return;
    }
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; i++){
        cout << i << " -> ";
        for (int j = 0; j < degree[i]; j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
}
void DFSRecursive(int vertex, bool visited[]){
    visited[vertex] = true;
    cout << vertex << " ";
    for (int i = 0; i < degree[vertex]; i++){
        int next = adj[vertex][i];
        if (!visited[next])
            DFSRecursive(next, visited);
    }
}
void recursiveDFS(){
    if (!created){
        cout << "Create the graph first";
        return;
    }
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    if (start < 0 || start >= V){
        cout << "Invalid starting vertex";
        return;
    }
    bool visited[MAX] = {false};
    cout << "DFS using recursion: ";
    DFSRecursive(start, visited);
}
void iterativeDFS(){
    if (!created){
        cout << "Create the graph first";
        return;
    }
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    if (start < 0 || start >= V){
        cout << "Invalid starting vertex";
        return;
    }
    bool visited[MAX] = {false};
    int stack[MAX];
    int top = -1;
    stack[++top] = start;
    cout << "DFS using iteration: ";
    while (top != -1){
        int vertex = stack[top--];
        if (!visited[vertex]){
            visited[vertex] = true;
            cout << vertex << " ";
            for (int i = degree[vertex] - 1; i >= 0; i--){
                int next = adj[vertex][i];
                if (!visited[next])
                    stack[++top] = next;
            }
        }
    }
}
int main(){
    int choice;
    cout << "\n\n1. Create the graph";
    cout << "\n2. Display the adjacency list";
    cout << "\n3. DFS using recursion";
    cout << "\n4. DFS using iteration";
    cout << "\n5. Quit";
    do{
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:createGraph();break;
            case 2:displayGraph();break;
            case 3:recursiveDFS();break;
            case 4:iterativeDFS();break;
            case 5:cout << "Exiting program";break;
            default:cout << "Invalid choice";
        }
    } while (choice != 5);
    return 0;
}
