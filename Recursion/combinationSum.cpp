#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define vi vector<int>
#define vvi vector<vector<int>>

void combinationSum(int i, vi &arr, vvi &ans, vi &ds, int n, int sum) {
  if(i == n) {
    if(sum == 0) {
      ans.push_back(ds);
    }
    return;
  }
  if(arr[i] <= sum) {
    ds.push_back(arr[i]);
    combinationSum(i, arr, ans, ds, n, sum - arr[i]);
    ds.pop_back();
  }
  combinationSum(i+1, arr, ans, ds, n, sum);
  return;
}

void solve() {
  vvi ans;
  vi ds;
  int n;
  cin>>n;
  vi arr(n);
  rep(i, 0, n-1) {
    int temp;
    cin>>temp;
    arr[i] = temp;
  }
  int sum;
  cin>>sum;
  combinationSum(0, arr, ans, ds, n, sum);
  for(int i = 0; i < ans.size(); i++) {
    for(int j = 0; j < ans[i].size(); j++) {
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
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