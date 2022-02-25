#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define vi vector<int>
#define vvi vector<vector<int>>

int countSubsequences(int arr[], int n, int i, int sum, int reqSum) {
  if(i == n) {
    if(sum == reqSum) {
      return 1;
    }
    return 0;
  }
  int l = countSubsequences(arr, n, i+1, sum, reqSum);
  int r = countSubsequences(arr, n, i+1, sum+arr[i], reqSum);
  return l + r;
}

void solve() {
  int n;
  cin>>n;
  int* arr = new int[n];
  rep(i, 0, n-1) {
    cin>>arr[i];
  }
  int sum;
  cin>>sum;
  int count = countSubsequences(arr, n, 0, 0, sum);
  cout<<count;
  return;
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