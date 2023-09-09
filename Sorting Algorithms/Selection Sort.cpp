#include<iostream>
using namespace std;
int minimumIndex(int arr[], int start, int sizeOfArray)
{
	int minIndex = start;
	for (int i = start+1; i < sizeOfArray; i++)
	{
		if (arr[i] < arr[minIndex])
			minIndex = i;
	}
	return minIndex;
}
void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;

}
void selectionSort(int arr[],int sizeOfArray)
{
	int minIndex = NULL;
	int temp = NULL;
	for (int i = 0; i < sizeOfArray; i++)
	{
		// Finding the Minimum Index
		minIndex = minimumIndex(arr, i,sizeOfArray);

		swap(arr[i], arr[minIndex]);
	}
}
void displayArray(int arr[], int sizeOfArray)
{
	cout << "\nArray : [ ";
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << "]";
}
int main()
{
	int arr[12] = {55,64,32,11,19,27,36,48,9,86,5,73};
	displayArray(arr,12);
	selectionSort(arr,12);
	displayArray(arr,12);
	cout << endl;
	return 0;
}