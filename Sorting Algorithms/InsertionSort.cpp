#include<iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
	int temp = NULL;
	int i,j = NULL;

	for (i = 0; i < size; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > temp)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = temp;
		
	}
}
void displayArray(int arr[], int size)
{
	cout << "\nArray : [ ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]";
}
int main()
{
	int arr[12] = { 55,64,32,11,19,27,36,48,9,86,5,73 };
	displayArray(arr, 12);
	insertionSort(arr, 12);
	displayArray(arr, 12);
	return 0;
}