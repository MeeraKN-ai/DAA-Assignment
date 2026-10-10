#include <iostream>
using namespace std;
#define MAX 100
#define INF 999999
int graph[MAX][MAX];
int V, E;
bool created = false;
void createGraph(){
    int u, v, w;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    if (V <= 0 || V > MAX || E < 0){
        cout << "Invalid number of vertices or edges";
        created = false;
        return;
    }
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++){
        cin >> u >> v >> w;
        if (u < 0 || u >= V || v < 0 || v >= V || u == v){
            cout << "Invalid edge. Create the graph again.\n";
            created = false;
            return;
        }
        graph[u][v] = w;
        graph[v][u] = w;
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
    for (int i = 0; i < V; i++){
        for (int j = i + 1; j < V; j++){
            if (graph[i][j] != INF){
                cout << i << " - " << j
                     << " : " << graph[i][j] << "\n";
            }
        }
    }
}
void primMST(){
    if (!created){
        cout << "Create the graph first";
        return;
    }
    int parent[MAX];
    int key[MAX];
    bool inMST[MAX] = {false};
    for (int i = 0; i < V; i++){
        key[i] = INF;
        parent[i] = -1;
    }
    key[0] = 0;  
    for (int count = 0; count < V; count++){
    	 int min = INF;
    	 int u = -1;
    	 for (int i = 0; i < V; i++){
            if (!inMST[i] && key[i] < min){
                min = key[i];
                u = i;
            }
        }
        if (u == -1){
            cout << "Graph is disconnected. MST cannot be found";
            return;
        }
    	 inMST[u] = true;
        for (int v = 0; v < V; v++){
            if (graph[u][v] != INF && !inMST[v] &&
                graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
    	 }
    }




    int totalWeight = 0;
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < V; i++){
        cout << parent[i] << " - " << i
             << " : " << graph[parent[i]][i] << "\n";
        totalWeight += graph[parent[i]][i];
    }
    cout << "Total weight of MST: " << totalWeight;
}
int main(){
    int choice;
    cout << "\n\n1. Create the weighted graph";
    cout << "\n2. Display the edges";
    cout << "\n3. Find MST using Prim's algorithm";
    cout << "\n4. Quit";
    do{
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:createGraph();break;
            case 2:displayEdges();break;
            case 3:primMST();break;
            case 4:cout << "Exiting program";break;
            default:cout << "Invalid choice";
        }
    } while (choice != 4);
    return 0;
}
