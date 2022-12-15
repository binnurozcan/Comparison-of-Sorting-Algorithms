#include <bits/stdc++.h>
using namespace std;
 
//Swap function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int array[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (array[j] < array[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            swap(&array[min_idx], &array[i]);
    }
}

void selectionSortD(int array[], int n)
{

    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (array[j] > array[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            swap(&array[min_idx], &array[i]);
    }
}
 
//Function to print an array
void printArray(int array[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void generateArray(int array[], int n) {
	srand((unsigned int)time(0));	//seed to generate random integers

	for (int i = 0; i < n; i++) {
		array[i] = rand() % 10000+1 ; //random integer from 0 to 10.000
	}
}

 
// Driver program to test above functions
int main()
{

	int n;
	cout << "Selection Sort" << endl;
	cout << "Enter total number of integers to sort: ";
	cin >> n;

	//array to hold integers
	int array[n];
	generateArray(array, n);
	
	//clock to measure execution time
	clock_t begin = clock();
	selectionSort(array, n);
	clock_t end = clock();
	cout << "Sorting execution time (Average Case): " << (end - begin) / 1000.0 << "s" << endl;

	//already sorted array for best case
	begin = clock();
	selectionSort(array, n);
	end = clock();
	cout << "Sorting execution time (Best Case): " << (end - begin) / 1000.0 << "s" << endl;

	//sorted ascending order array
	begin = clock();
	selectionSortD(array, n); //sort in desc order
	end = clock();
	cout << "Sorting execution time (Worst Case): " << (end - begin) / 1000.0 << "s" << endl;
}
// This is code is contributed by rathbhupendra
