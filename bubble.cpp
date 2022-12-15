#include <iostream>
#include <ctime>
using namespace std;
#include <stdlib.h>

//bubble sorting
void bubbleSort(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {

		for (int j = 0; j < size - i - 1; j++) {

			if (array[j] > array[j + 1]) {  // > for ascending order sorting, < for descending
				//swapping elements
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

			}

		}

	}

}

//bubble sort in descending order
void bubbleSortD(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {

		for (int j = 0; j < size - i - 1; j++) {

			if (array[j] < array[j + 1]) {  // > for ascending order sorting, < for descending

				//swapping elements
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

			}

		}

	}

}

//printing the sorted array
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}

//generate random integers
void generateArray(int array[], int size) {
	srand((unsigned int)time(0));	//seed to generate random integers

	for (int i = 0; i < size; i++) {
		array[i] = rand() % 10000+1 ; //random integer from 0 to 10.000
	}
}

int main() {

	
	int size;
	cout << "Bubble Sort" << endl;
	cout << "Enter total number of integers to sort: ";
	cin >> size;

	//array to hold integers
	int array[size];
	generateArray(array, size);
	

	//clock to measure execution time
	clock_t begin = clock();
	bubbleSort(array, size);
	clock_t end = clock();
	cout << "Sorting execution time (Average Case): " << (end - begin) / 1000.0 << "s" << endl;
	

	//already sorted array for best case
	begin = clock();
	bubbleSort(array, size);
	end = clock();
	cout << "Sorting execution time (Best Case): " << (end - begin) / 1000.0 << "s" << endl;


	//sorted ascending order array
	begin = clock();
	bubbleSortD(array, size); //sort in desc order
	end = clock();
	cout << "Sorting execution time (Worst Case): " << (end - begin) / 1000.0 << "s" << endl;
	
	
}
