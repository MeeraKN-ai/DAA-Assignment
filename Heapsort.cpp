#include <iostream>
using namespace std;
int a[100], n = 0;
bool entered = false;
void readArray(){
    cout << "Enter number of elements: ";
    cin >> n;
    if (n == 0){
        cout << "Array is empty\n";
        entered = false;
        return;
    }
    else if (n<0){
    	 cout<< "Invalid number of elements\n";
    }
    else{
    	 cout << "Enter array elements:\n";
    	 for (int i = 0; i < n; i++)
            cin >> a[i];
            entered = true;
    }
}
void heapify(int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest]){
        largest = left;
    }
    if (right < n && a[right] > a[largest]){
        largest = right;
    }
    if (largest != i){
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(n, largest);
    }
}
void sortArray(){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(n, i);
    }
    for (int i = n - 1; i > 0; i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(i, 0);
    }
}
void displayArray(){
    if (!entered){
        cout << "Array is empty" << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    int choice;
    cout << "\n--- HEAP SORT MENU ---" << endl;
    cout << "1. Read array" << endl;
    cout << "2. Sort array" << endl;
    cout << "3. Display array" << endl;
    cout << "4. Quit" << endl;
    do{
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:readArray();break;
            case 2:
                if (entered){
                    sortArray();
                    cout << "Array sorted successfully" << endl;
                }
                else{
                    cout << "Please read the array first" << endl;
                }break;
            case 3:displayArray();break;
            case 4:cout << "Exiting program" << endl;break;
            default:cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
    return 0;
}
