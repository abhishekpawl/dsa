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

void permutations(vvi &ans, vi &ds, vi &picked, vi &nums) {
  if(ds.size() == nums.size()) {
    ans.push_back(ds);
    return;
  }
  for(int i = 0; i < nums.size(); i++) {
    if(!picked[i]) {
      ds.push_back(nums[i]);
      picked[i] = !picked[i];
      permutations(ans, ds, picked, nums);
      picked[i] = !picked[i];
      ds.pop_back();
    }
  }
}

void permutationsBySwap(vvi &ans, vi &nums, int ind) {
  if(ind == nums.size()) {
    ans.push_back(nums);
    return;
  }
  repi(i, ind, nums.size()) {
    swap(nums[i], nums[ind]);
    permutationsBySwap(ans, nums, ind+1);
    swap(nums[i], nums[ind]);
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
  vvi ans;
  vi ds, picked(n, 0);
  /* permutations(ans, ds, picked, nums); */
  permutationsBySwap(ans, nums, 0);
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