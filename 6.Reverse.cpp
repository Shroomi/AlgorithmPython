#include<iostream>
using namespace std;

template <class T>
int getArrayLen(T &array){
	return sizeof(array) / sizeof(array[0]);
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void reverse(int A[], int lo, int hi){
	if(lo < hi){
		swap(&A[lo], &A[hi]);
		reverse(A, ++lo, --hi);
	}
}

int main(){
	int A[] = {1, 2, 3, 4, 5, 6, 7};
	int len = getArrayLen(A);
	reverse(A, 0, len-1);
	for(int i = 0; i < len; i++){
		cout<<A[i]<<' ';
	}
	cout<<endl;
}