#include <iostream>
using namespace std;
int a[100], n = 0;
bool entered = false;
void readArray()
{
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0 || n > 100)
    {
        cout << "Invalid size!" << endl;
        n = 0;
        entered = false;
        return;
    }
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    entered = true;
}
void merge(int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}
void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}
void displayArray()
{
    if (!entered)
    {
        cout << "Please read the array first!" << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int choice;
    cout << "\n--- MERGE SORT MENU ---" << endl;
    cout << "1. Read array" << endl;
    cout << "2. Sort array" << endl;
    cout << "3. Display array" << endl;
    cout << "4. Quit" << endl;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                readArray();
                break;
            case 2:
                if (entered)
                {
                    mergeSort(0, n - 1);
                    cout << "Array sorted successfully!" << endl;
                }
                else
                {
                    cout << "Please read the array first!" << endl;
                }
                break;
            case 3:
                displayArray();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}
