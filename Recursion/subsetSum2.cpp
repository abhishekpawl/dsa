#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i >= b; i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define printv(v) for(int i = 0; i < v.size(); i++) cout<<v[i];
#define printvv(v) for(int i = 0; i < v.size(); i++) {for(int j = 0; j < v[i].size(); j++) {cout<<v[i][j];} cout<<endl;}

void subsetSum2(vvi &ans, int ind, vi &ds, vi &nums, int n) {
  ans.push_back(ds);
  repi(i, ind, n) {
    if(i > ind && nums[i] == nums[i-1]) {
      continue;
    }
    ds.push_back(nums[i]);
    subsetSum2(ans, i+1, ds, nums, n);
    ds.pop_back();
  }
  return;
}

void solve() {
  int n;
  cin>>n;
  vi nums(n);
  repi(i, 0, n) {
    cin>>nums[i];
  }
  sort(nums.begin(), nums.end());
  vvi ans;
  vi ds;
  subsetSum2(ans, 0, ds, nums, nums.size());
  printvv(ans);
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