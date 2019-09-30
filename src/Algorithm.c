/*
 ============================================================================
 Name        : Algorithm.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include"Algorithm.h"


int main(void) {
	/* insertion sort  */
	int index=0,i;
	int arr[] = {64, 34, 25, 12, 22, 11, 90},arr2[]={4, 3, 2, 1, 22, 11, 90},
			arr3[]={4, 33, 21, 1, 22, 11, 90},
			arr4[]={14, 43, 2, 1, 22, 15, 90},
			arr5[]={2, 43, 7, 1, 22, 15, 11};
	int z = sizeof(arr) / sizeof(arr[0]);

	/*insertion_sort(arr,9);
	index=binarySearch(arr, 0, z-1, 22);
	printf("the index is:  %d ",index);

	printf("\n");*/


	mergeSort(arr2, 0, 6);
	for (i = 0; i < 7; i++) {
		printf("%d\t", arr2[i]);
	}
	printf("\n");

	Bubble_Sort(arr3,7);
	for (i = 0; i < 7; i++) {
		printf("%d\t", arr3[i]);
	}

	printf("\n");

	Selection_Sort(arr4,7);
	for (i = 0; i < 7; i++) {
		printf("%d\t", arr4[i]);
	}


	Linear_search(arr5,7,2,&index);
	printf("the index is :  %d ",index);



	return 0;

}

/**************************************************************************************************/

void insertion_sort(int* arr, int size) {
	int j, i = 0, key, temp;             //1T
	for (i = 0; i < 9; i++)                //2n  i=0 & check size
			{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			temp = arr[j + 1];
			arr[j + 1] = arr[j];
			arr[j] = temp;

			j--;

		}

		arr[j + 1] = key;

	}

}

void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	 are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	 are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void Bubble_Sort(int* arr, int z) {
	int i, j,temp;
	   for (i = 0; i <= z-1; i++){

	       // Last i elements are already in place
	       for (j = 0; j <= z-1-i; j++)
	           if (arr[j] > arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;

				}

			}
}

void Selection_Sort(int* arr,int z)
{
	int i=0,min,j,temp;

	for (i=0; i < z-1; i++)
	{
		min = i;
	  for (j = i+1; j < z; j++)
	    {
		if (arr[j] < arr[min])
			min = j;

        }
	    temp=arr[min];
	  	arr[min]=arr[i];
	  	arr[i]=temp;

     }

}

void Linear_search(int* arr,int z,int key,int*index){
	int i=0;
	for(i=0;i<z;i++){
		if (key==arr[i]){
			*index=i;
			break;
		}
	}


}

int binarySearch(int* arr, int left, int right, int x)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }

     return -1;
}
