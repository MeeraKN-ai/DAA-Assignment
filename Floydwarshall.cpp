#include <iostream>
using namespace std;
int main()
{
    int n, e;
    int distance[10][10];
    cout << "Enter number of vertices: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                distance[i][j] = 0;
            else
                distance[i][j] = 999;
        }
    }
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges and weights:\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        distance[u - 1][v - 1] = w;
        distance[v - 1][u - 1] = w;   
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] =
                        distance[i][k] + distance[k][j];
                }
            }
        }
    }
    cout << "\nShortest distance matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << distance[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
