#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Create L ? A[p..q] and M ? A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void generateArray(int arr[], int n) {
	srand((unsigned int)time(0));	//seed to generate random integers

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10000+1 ; //random integer from 0 to 10.000
	}
}

// Driver program
int main() 
{
	int n;
	cout << "Merge Sort" << endl;
	cout << "Enter total number of integers to sort: ";
	cin >> n;
	
	//array to hold integers
	int arr[n];
	generateArray(arr, n);
	
    
    int a = sizeof(arr) / sizeof(arr[0]);
      
    
    //clock to measure execution time
	clock_t begin = clock();
	mergeSort(arr, 0, a - 1);
	//printf("Sorted array: \n");
    //printArray(arr, a);
	clock_t end = clock();
	cout << "Sorting execution time (Average Case): " << (end - begin) / 1000.0 << "s" << endl;
	
	//already sorted array for best case
	begin = clock();
	mergeSort(arr, 0, a - 1);
	//printf("Sorted array: \n");
    //printArray(arr, a);
	end = clock();
	cout << "Sorting execution time (Best Case): " << (end - begin) / 1000.0 << "s" << endl;
	

}
