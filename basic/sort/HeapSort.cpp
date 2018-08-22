#include<iostream>
using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void heapify(int arr[], int n, int i){
	cout<<i<<endl;
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if(left < n && arr[left] > arr[largest])
		largest = left;
	if(right < n && arr[right] > arr[largest])
		largest = right;
	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n){
	for(int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for(int i = n - 1; n >= 0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int arr[] = {3,8,4,7,3,8,1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<n<<endl;
	heapSort(arr, n);
	cout<<"Sorted Array is:\n ";
	printArray(arr, n);
}
