#include<iostream>
#include<vector>
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

void bubbleSort(int A[], int n){
	for(bool sorted = false; sorted = !sorted; n--){ //sorted==True时，进入循环; sorted==False时，退出循环
		for(int i = 1; i < n; i++){
			if(A[i-1] > A[i]){
				swap(&A[i-1], &A[i]);
				sorted = false;
			}
		}
	}
	return;
}

int main(){
	int A[] = {10, 2, 3, 5, 7, 12, 6, 2};
	int len = getArrayLen(A);
	bubbleSort(A, len);
	for(int i = 0; i < len; i++){
		cout<<A[i]<<' ';
	}
	cout<<endl;
	return 0;
}