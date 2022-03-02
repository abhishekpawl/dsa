#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i >= b; i--)
#define vi vector<int>
#define vvi vector<vector<int>>

void subsetSum(int i, vector<int> &subset, vector<int> &arr, int sum, int n) {
  if(i == n) {
    subset.push_back(sum);
    return;
  }
  subsetSum(i+1, subset, arr, sum + arr[i], n);
  subsetSum(i+1, subset, arr, sum , n);
}

void solve() {
  vector<int> subset;
  int n;
  cin>>n;
  vector<int> arr(n);
  repi(i, 0, n) {
    int temp;
    cin>>temp;
    arr[i] = temp;
  }
  sort(arr.begin(), arr.end());
  subsetSum(0, subset, arr, 0, n);
  sort(subset.begin(), subset.end());
  repi(i, 0, (int)pow(2, n)) {
    cout<<subset[i]<<" ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll test=1;
  //cin>>test;
  while(test--) {
    solve();
  }
  return 0;
}