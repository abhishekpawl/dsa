#include <bits/stdc++.h>
using namespace std;

void subsequence(int i, vector<int> &a, vector<int> &subseq) {
	if(i == a.size()) {
		for(auto it: subseq) {
			cout<<it<<" ";
		}
		cout<<endl;
		return;
	}
	subseq.push_back(a[i]);
	subsequence(i+1, a, subseq);
	subseq.pop_back();
	subsequence(i+1, a, subseq);
}

int main () {
	int n;
	cin>>n;
	vector<int> a(n), subseq;
	for(int temp, i = 0; i < n; i++) {
		cin>>a[i];
	}
	subsequence(0, a, subseq);
	return 0;
}