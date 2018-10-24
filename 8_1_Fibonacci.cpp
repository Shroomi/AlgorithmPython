#include<iostream>
using namespace std;

int fib(int n) {
	return (n < 2) ? n : fib(n-1) + fib(n-2);
}

int main(){
	int n;
	cout<< "please input a number: ";
	cin >> n;
	cout<< "fib("<< n <<")="<<fib(n)<<endl;
}