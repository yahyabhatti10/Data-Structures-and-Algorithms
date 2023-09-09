#include<iostream>
using namespace std;
void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;

}
void bubbleSort(int arr[],int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
void displayArray(int arr[],int size)
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
	displayArray(arr,12);
	bubbleSort(arr,12);
	displayArray(arr,12);
	return 0;
}

	