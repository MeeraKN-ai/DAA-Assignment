#include <iostream>
using namespace std;
#define MAX 100
#define INF 999999
struct Edge{
    int u, v, w;
};
Edge edges[MAX];
int V, E;
bool created = false;
void createGraph(){
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    if (V <= 0 || V > MAX || E < 0 || E > MAX){
        cout << "Invalid number of vertices or edges";
        created = false;
        return;
    }
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        if (edges[i].u < 0 || edges[i].u >= V || edges[i].v < 0 || edges[i].v >= V){
            cout << "Invalid vertex. Create the graph again.\n";
            created = false;
            return;
        }
    }
    created = true;
    cout << "Graph created successfully";
}
void displayEdges(){
    if (!created){
        cout << "Create the graph first";
        return;
    }
    cout << "\nEdges of the graph:\n";
    for (int i = 0; i < E; i++){
        cout << edges[i].u << " -> "<< edges[i].v << " : " << edges[i].w << "\n";
    }
}
void bellmanFord(){
    if (!created){
        cout << "Create the graph first";
        return;
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    if (source < 0 || source >= V){
        cout << "Invalid source vertex";
        return;
    }
    int dist[MAX];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[source] = 0;
    for (int i = 1; i < V; i++){
        bool changed = false;
        for (int j = 0; j < E; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                changed = true;
            }
        }
        if (!changed)
            break;
    }
    for (int i = 0; i < E; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (dist[u] != INF && dist[u] + w < dist[v]){
            cout << "Negative-weight cycle detected";
            return;
        }
    }
    cout << "\nShortest distances from vertex " << source << ":\n";
    for (int i = 0; i < V; i++){
        cout << source << " -> " << i << " : ";
        if (dist[i] == INF)
            cout << "Unreachable";
        else
            cout << dist[i];
        cout << "\n";
    }
}
int main(){
    int choice;
    cout << "\n\n1. Create the weighted directed graph";
    cout << "\n2. Display the edges";
    cout << "\n3. Find shortest paths using Bellman-Ford";
    cout << "\n4. Quit";
    do{
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:createGraph();break;
        case 2:displayEdges();break;
        case 3:bellmanFord();break;
        case 4:cout << "Exiting program";break;
        default:cout << "Invalid choice";
        }
    } while (choice != 4);
    return 0;
}
