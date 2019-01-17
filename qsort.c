#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

qsort(int arr[], int left, int right);
int compare(int, int);

int main() 
{
	int i,j, temp;
	int arr[] = { 2,1,5,9,7,3 };
	
	return 0;
}

qsort(int arr[], int left, int right) 
{
	if (left > right)
		return;

	int pivot = arr[(left + right) / 2];
	int from = left;
	int to = right;

	while (1)
	{
		/*
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;

		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		

		while(arr[left] > pivot) left++;
		while(arr[right] < pivot) right--;

		if (left > right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}	
		*/

		while (compare(arr[left], pivot)) left++;
		while (compare(pivot, arr[right])) right--;

		if (compare(left, right))
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}


		else
		{
			int i;
			for(i = from; i < to+1;i++)
				printf("%d ",arr[i]);

			printf("\nleft: %d, right:%d\n", left, right);
			break;
		}
	}

	qsort(arr, from, left - 1);
	qsort(arr, right + 1, to);
}

int compare(int a, int b)
{
	return a - b;
}