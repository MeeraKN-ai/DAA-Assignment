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
void insertionSort()
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
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
    do
    {
        cout << "\n--- INSERTION SORT MENU ---" << endl;
        cout << "1. Read array" << endl;
        cout << "2. Sort array" << endl;
        cout << "3. Display array" << endl;
        cout << "4. Quit" << endl;
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
                    insertionSort();
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
