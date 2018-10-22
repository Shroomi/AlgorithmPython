//邓俊辉 数据结构课程 p24 01-E-7 例-MAX2
//视频：https://www.bilibili.com/video/av22774520/?p=24

#include<iostream>
using namespace std;

template <class T>
int getArrayLen(T &array){
	return sizeof(array) / sizeof(array[0]);
}

void swap(int *x1, int *x2){
	int temp = *x1;
	*x1 = *x2;
	*x2 = temp;
}

void max2(int A[], int lo, int hi, int &x1, int &x2){
	if(lo + 2 == hi){
		x1 = lo;
		x2 = lo + 1;
		if(A[x1] < A[x2]) swap(&x1, &x2);
		return;
	}

	if(lo + 3 == hi){
		x1 = lo;
		x2 = lo+1;
		if(A[x1] < A[x2]) swap(&x1, &x2); 
		if(A[lo+2] > A[x2]){
			if(A[x1] < A[x2 = (lo+2)]){
				swap(&x1, &x2);
			}
		}
		return;
	}

	int mi = (lo + hi) >> 1;
	int x1L, x2L; max2(A, lo, mi, x1L, x2L);
	int x1R, x2R; max2(A, mi, hi, x1R, x2R);
	if(A[x1L] > A[x1R]){
		x1 = x1L; x2 = (A[x2L] > A[x1R]) ? x2L : x1R;
	}
	else{
		x1 = x1R; x2 = (A[x2R] > A[x1L]) ? x2R : x1L;
	}
	
}

int main(){
	int A[] = {2, 3, 89, 0, 4, 6, 9};
	int hi = getArrayLen(A);
	int x1, x2;
	max2(A, 0, hi, x1, x2);
	cout << A[x1] << ' ' << A[x2] << endl;
}