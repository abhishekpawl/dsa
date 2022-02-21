#include <bits/stdc++.h>
using namespace std;

void recReverse(int a[], int i, int n) {
	if(i >= n/2) {
		return;
	}

	swap(a[i], a[n-i-1]);

	recReverse(a, i+1, n);
}

int main() {
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	recReverse(a, 0, n);
	for(int i = 0; i < n; i++) {
		cout<<a[i]<<" ";
	}
	delete[] a;
}