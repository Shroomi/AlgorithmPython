#include<iostream>
using namespace std;

template<class T>
int getArrayLen(T &array){
	return sizeof(array) / sizeof(array[0]);
}

int sum(int A[], int n){
	return (n < 1) ? 0 : sum(A, n-1) + A[n-1];
}

int main(){
	int A[] = {1, 2, 3, 4, 5};
	cout<<sum(A, getArrayLen(A))<<endl;
}