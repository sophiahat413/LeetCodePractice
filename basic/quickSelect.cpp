#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*b = *a;
	*a = tmp;
}
int partition(vector<int>& a, int low, int high){
	int pivot = a[high], i = low-1;
	for(int q = low; q <= high-1; q++){
		if(a[q] <= pivot){
			i++;
			swap(&a[i], &a[q]);
		}	
	}
	swap(&a[i], &a[high]);
	return i; 
}

class quickSelect{
	public:
	int select(vector<int>& a, int k, int low, int high){
		if(k > 0 && k <= high-low+1){
			int index = partition(a, low, high);
			cout<<"index: "<<index<<endl;
			if(index - low == k - 1)
				return a[index];
			if(index - low > k-1)
				return select(a, k, low, index - 1);
			if(index - low <  k-1)
				return select(a, k-index+low-1, index+1, high);
		}
		return INT_MAX;
	}

};

int main(){
	vector<int> a;
	a.push_back(10);
	a.push_back(4);
	a.push_back(5);
	a.push_back(8);
	a.push_back(6);
	a.push_back(11);
	a.push_back(26);
	int k = 3;
	cout<<"Kth Smallest Element: "<<quickSelect().select(a, k, 0, a.size()-1)<<endl;
	return 0;
}
