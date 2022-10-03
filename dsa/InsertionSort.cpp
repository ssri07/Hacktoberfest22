#include <bits/stdc++.h>
using namespace std;

void insertionSort (int *array, int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        j = i;
        temp = array [i];
        while (j > 0 && temp < array [j - 1]) {
            array [j] = array [j - 1];
            j--;
        }
        array [j] = temp;
    }
}

void display(int *array, int size) {
    for(int i = 0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n]; 
   cout << "Enter elements:" << endl;

   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }

   cout << "Array before Sorting: ";
   display(arr, n);
   insertionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
   return 0;
}