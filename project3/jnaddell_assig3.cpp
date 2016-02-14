#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <Windows.h>

using namespace std;



typedef struct {
	LARGE_INTEGER start;
	LARGE_INTEGER stop;
} stopWatch;

void startTimer(stopWatch *timer) {
	QueryPerformanceCounter(&timer->start);
}
void stopTimer(stopWatch *timer) {
	QueryPerformanceCounter(&timer->stop);
}
double LIToSecs(LARGE_INTEGER * L) {
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	return ((double)L->QuadPart / (double)frequency.QuadPart);
}
double getElapsedTime(stopWatch *timer) {
	LARGE_INTEGER time;
	time.QuadPart = timer->stop.QuadPart - timer->start.QuadPart;
	return LIToSecs(&time);
}
void insertion_sort(int arr[], int);
void  quicksort(int arr[], int, int);
void maxHeapify(int array[], int i, int heap_size);
void buildMaxHeap(int A[], int length);
void heapSort(int A[], int length);



int main()
{
	int A[6][1001], B[1001] , C[1001], D[1001];
	stopWatch S;
	double avg[11] = { 0 };
	double avg2[11] = { 0 };
	double avg3[11] = { 0 };

	for (int i = 1; i <= 5; i++)
	{


		for (int j = 1; j <= 1000; j++)
		{
			A[i][j] = rand();


		}

	}





	for (int j = 1; j <= 5; j++)
	{

		for (int i = 100; i <= 1000; i += 100)
		{

			for (int k = 1; k <= i; k++)
			{

				B[k] = A[j][k];
				C[k] = A[j][k];
				D[k] = A[j][k];
			}


			startTimer(&S);
			insertion_sort(B, i);
			stopTimer(&S);

			double timeInsert = getElapsedTime(&S) * 1000000;
			avg[i / 100] = avg[i / 100] + timeInsert;

			startTimer(&S);
			quicksort(C, 0, i);
			stopTimer(&S);

			double timeInsert2 = getElapsedTime(&S) * 1000000;
			avg2[i / 100] = avg2 [i/ 100] + timeInsert2;


			startTimer(&S);
			heapSort(D, i);
			stopTimer(&S);


			double timeInsert3 = getElapsedTime(&S) * 1000000;
			avg3[i / 100] = avg3[i / 100] + timeInsert3;

		}



	}

	cout << " Average time for InsertionSort" << endl;

	cout << endl;

	for (int j = 100; j <= 1000; j += 100)
	{
		
		 cout << j << ": "<< "element: "  << avg[j / 100] / 5 << " microseconds" << endl;

		
		
	}

	cout << endl;

	cout << " Average time for QuickSort"<< endl;

	cout << endl;

	for (int j = 100; j <= 1000; j += 100)
	{
		
		cout << j << ": " << "element: " << " " << avg2[j / 100] / 5 << " microseconds" << endl;

		
	}

	cout << endl;


	cout << " Average time for HeapSort" << endl;

	cout << endl;

	for (int j = 100; j <= 1000; j += 100)
	{
		
		cout << j << ": " << "element: " << " " << avg3[j / 100] / 5 << " microseconds" << endl;

		
	}
	cout << endl;

	return 0;

}













void insertion_sort(int arr[], int length)
{

	int key;
	int i;


	for (int j = 1; j < length; ++j)
	{
		key = arr[j];
		i = j - 1;

		while (i > 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
}






int partition(int* input, int p, int r)
{
	int x = input[r];

	int i = p - 1;

	for (int j = p; j <= (r - 1); ++j)
	{
		if (input[j] <= x)
		{
			i = i + 1;

			int temp = input[i];
			input[i] = input[j];
			input[j] = temp;
		}
		
			
		
	int temp = input[i + 1];
	input[i + 1] = input[r];
	input[r] = temp;

		
	}
	return i + 1;
}

		

	void quicksort(int* input, int p, int r)
{
	if (p < r)
	{
		int j = partition(input, p, r);
		quicksort(input, p, j - 1);
		quicksort(input, j + 1, r);
	}
}



int LeftSide(int i)
{
	return 2 * i;
}

int RightSide(int i)
{
	return 2 * i + 1;
}
void maxHeapify(int array[], int j, int heap_size)
{
	int l = LeftSide(j);
	int r = RightSide(j);
	int greatest;

	if (l <= heap_size && array[l] > array[j])
	{
		greatest = l;
	}
	else
		greatest = j;

	if (r <= heap_size && array[r] > array[greatest])
		greatest = r;

	if (greatest != j)
	{
		int tempVar = array[greatest];
		array[greatest] = array[j];
		array[j] = tempVar;
		maxHeapify(array, greatest, heap_size);
	}

}

void buildMaxHeap(int array[], int n)
{
	for (int i = (int)floor(n / 2); i >= 1; --i)
	{
		maxHeapify(array, i, n);
	}
}

void heapSort(int array[], int n)
{
	int heap_size = n;
	buildMaxHeap(array, heap_size);

	for (int i = n; i >= 2; --i)
	{
		int tempVar = array[i];
		array[i] = array[heap_size - 1];
		array[heap_size - 1] = tempVar;
		--heap_size;
		maxHeapify(array, 1, heap_size);
	}
}