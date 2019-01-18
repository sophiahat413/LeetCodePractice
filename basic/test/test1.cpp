#include <iostream>
using namespace std;

int main(){
	int a = 8;
	int *b = &a;
	*b = 10;
	cout<<a<<endl;
	return 0;
}
