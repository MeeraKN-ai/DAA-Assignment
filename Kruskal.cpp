#include <iostream>
using namespace std;
#define MAX 100
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
        if (edges[i].u < 0 || edges[i].u >= V || edges[i].v < 0 || edges[i].v >= V ||
            edges[i].u == edges[i].v){
            cout << "Invalid edge. Create the graph again.\n";
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
        cout << edges[i].u << " - "
             << edges[i].v << " : "
             << edges[i].w << "\n";
    }
}
int find(int parent[], int x){
    while (parent[x] != x)
        x = parent[x];
    return x;
}
void unionSet(int parent[], int a, int b){
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    parent[rootB] = rootA;
}
void kruskalMST(){
    if (!created){
        cout << "Create the graph first";
        return;
    }
    Edge temp;
    for (int i = 0; i < E - 1; i++){
        for (int j = 0; j < E - i - 1; j++){
            if (edges[j].w > edges[j + 1].w){
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    int parent[MAX];
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int count = 0;
    int totalWeight = 0;
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < E && count < V - 1; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int rootU = find(parent, u);
        int rootV = find(parent, v);
        if (rootU != rootV){
            cout << u << " - " << v
                 << " : " << edges[i].w << "\n";
            unionSet(parent, rootU, rootV);
            totalWeight += edges[i].w;
            count++;
        }
    }
    if (count != V - 1){
        cout << "Graph is disconnected. MST does not exist.";
        return;
    }
    cout << "Total weight of MST: " << totalWeight;
}
int main(){
    int choice;
    cout << "\n\n1. Create the weighted graph";
    cout << "\n2. Display the edges";
    cout << "\n3. Find MST using Kruskal's algorithm";
    cout << "\n4. Quit";
    do{
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:createGraph();break;
        case 2:displayEdges();break;
        case 3:kruskalMST();break;
        case 4:cout << "Exiting program";break;
        default:cout << "Invalid choice";
        }
    } while (choice != 4);
    return 0;
}
