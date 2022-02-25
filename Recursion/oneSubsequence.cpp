#include <bits/stdc++.h>
using namespace std;

bool oneSubsequence(vector<int> &subseq, int arr[], int n, int i, int sum, int reqSum) {
  if(i == n) {
    if(sum == reqSum) {
      return true;
    }
    return false;
  }
  subseq.push_back(arr[i]);
  if(oneSubsequence(subseq, arr, n, i+1, sum+arr[i], reqSum)) {
    return true;
  }
  subseq.pop_back();
  if(oneSubsequence(subseq, arr, n, i+1, sum, reqSum)) {
    return true;
  }
  return false;
}

int main() {
  int n;
  cin>>n;
  int* arr = new int[n];
  for(int i = 0; i < n; i++) {
    cin>>arr[i];
  }
  int sum;
  cin>>sum;
  vector<int> subseq;
  oneSubsequence(subseq, arr, n, 0, 0, sum);
  for(int i = 0; i < subseq.size(); i++) {
    cout<<subseq[i]<<" ";
  }
}