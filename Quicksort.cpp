#include <iostream> 
using namespace std; 
int a[100], n; 
bool read = false, sorted = false; 
int partition(int a[], int low, int high){ 
	int pivot = a[high]; 
	int i = low - 1; 
	for (int j = low; j < high; j++){ 
		if (a[j] < pivot){ 
 			 i++; 
            		int temp = a[i]; 
            		a[i] = a[j]; 
            		a[j] = temp; 
       		 } 
   	 } 
    	int temp = a[i + 1]; 
    	a[i + 1] = a[high]; 
    	a[high] = temp; 
    	return i + 1; 
} 
void quickSort(int a[], int low, int high){ 
	if (low < high){ 
        	int p = partition(a, low, high); 
        	quickSort(a, low, p - 1); 
        	quickSort(a, p + 1, high); 
   	 } 
} 
void readArray(){ 
	cout <<"Enter number of elements: "; 
 	cin >> n; 
	if (n == 0){ 
        	cout << "Array is empty\n"; 
        	read = false; 
        	return; 
   	 } 
    	else if (n<0 || n>100){ 
      		cout<< "Invalid number of elements\n"; 
			read = false;
	  		sorted = false;
			return;

   	} 
    	else{ 
      		cout << "Enter array elements:\n"; 
      		for (int i = 0; i < n; i++) 
            		cin >> a[i]; 
            		read = true; 
          		    sorted = false; 
    	} 
} 
void displayArray(){ 
	if (!read){ 
        	cout << "Array is empty\n"; 
        	return; 
    	} 
    	cout << "Array elements: "; 
    	for (int i = 0; i < n; i++) 
       		cout << a[i] << " "; 
    	cout << "\n"; 
} 
int main(){ 
	int choice; 
    	cout << "\n1. Read the array"; 
    	cout << "\n2. Sort using Quick Sort"; 
    	cout << "\n3. Display the array"; 
    	cout << "\n4. Quit"; 
    	do{ 
        	cout << "\nEnter your choice: "; 
        	cin >> choice; 
        	switch (choice){ 
            	case 1:readArray();break; 
            	case 2: 
                	if (!read) 
                		cout << "Please read the array first\n"; 
            		else{ 
                		quickSort(a, 0, n - 1); 
                		sorted = true; 
                	cout << "Array sorted successfully\n"; 
           		}break; 
            	case 3:displayArray();break; 
            	case 4:cout << "Exiting program\n";break; 
            	default:cout << "Invalid choice\n"; 
	} 
 } while (choice != 4); 
 return 0;} 
