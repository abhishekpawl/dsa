#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define vi vector<int>
#define vvi vector<vector<int>>

void combination(int ind, int target, vi &arr, vvi &ans, vi &ds) {
  if(target == 0) {
    ans.push_back(ds);
    return;
  }
  rep(i, ind, arr.size()-1) {
    if(i > ind && arr[i] == arr[i-1])
      continue;
    if(arr[i] > target)
      break;
    ds.push_back(arr[i]);
    combination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
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
  sort(arr.begin(), arr.end());
  int target;
  cin>>target;
  combination(0, target, arr, ans, ds);
  rep(i, 0, ans.size()-1) {
    rep(j, 0, ans[i].size()-1) {
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