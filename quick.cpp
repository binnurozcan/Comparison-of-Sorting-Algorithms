#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;
  
// This function takes last element
// as pivot, places
// the pivot element at its correct
// position in sorted array, and 
// places all smaller (smaller than pivot)
// to left of pivot and all greater 
// elements to right of pivot
int partition(int arr[], int low, int high)
{
    // pivot
    int pivot = arr[high]; 
    
    // Index of smaller element
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    {
        // If current element is smaller
        // than or equal to pivot
        if (arr[j] <= pivot) {
  
            // increment index of 
            // smaller element
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
  
// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
  
    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);
  
    return partition(arr, low, high);
}
  
/* The main function that implements
QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
  
        /* pi is partitioning index,
        arr[p] is now
        at right place */
        int pi = partition_r(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


  
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout<<arr[i]<<" "; 
}
  
void generateArray(int arr[], int n) {
	srand((unsigned int)time(0));	//seed to generate random integers

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10000+1 ; //random integer from 0 to 10.000
	}
}

// Driver Code
int main()
{
	int n;
	cout << "Quick Sort" << endl;
	cout << "Enter total number of integers to sort: ";
	cin >> n;
	
	//array to hold integers
	int arr[n];
	generateArray(arr, n);
	
    
    int a = sizeof(arr) / sizeof(arr[0]);
      
    
    //clock to measure execution time
	clock_t begin = clock();
	quickSort(arr, 0, a - 1);
	//printf("Sorted array: \n");
    //printArray(arr, a);
	clock_t end = clock();
	cout << "Sorting execution time (Average Case): " << (end - begin) / 1000.0 << "s" << endl;
	
	//already sorted array for best case
	begin = clock();
	quickSort(arr, 0, a - 1);
	//printf("Sorted array: \n");
    //printArray(arr, a);
	end = clock();
	cout << "Sorting execution time (Best Case): " << (end - begin) / 1000.0 << "s" << endl;
	

}
