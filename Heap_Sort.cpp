#include <iostream>
using namespace std;
void heapify(int A[], int idx, int n)
{
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int largest = idx;
    if (l < n && A[l] > A[largest])
    {
        largest = l;
    }
    if (r < n && A[r] > A[largest])
    {
        largest = r;
    }
    if (largest != idx)
    {
        int temp = A[idx];
        A[idx] = A[largest];
        A[largest] = temp;
        heapify(A, largest, n);
    }
}
void buildheap(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(A, i, n);
    }
}
void Sort(int A[], int n)
{
    buildheap(A, n);
    for (int i = n - 1; i >= 1; i--)
    {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, 0, i);
    }
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    Sort(A, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
