#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i >= b; i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define printv(v) for(int i = 0; i < v.size(); i++) cout<<v[i];
#define printvv(v) for(int i = 0; i < v.size(); i++) {for(int j = 0; j < v[i].size(); j++) {cout<<v[i][j];} cout<<endl;}

ll recursion(int n, int d, vector<vector<long long>> &dp) {
  if(n - d == 0) return 0;
  if(dp[n][d] != -1) return dp[n][d];
  int temp = n - d;
  vi digits;
  while(temp) {
    int d = temp % 10;
    if(d) digits.push_back(d);
    temp /= 10;
  }
  ll steps = LLONG_MAX;
  repi(i, 0, digits.size()) {
    if(dp[n-d][digits[i]] == -1) dp[n-d][digits[i]] = recursion(n-d, digits[i], dp);
    steps = min(steps, dp[n-d][digits[i]]);
  }
  return dp[n][d] = 1 + steps;
}

void solve() {
  int n;
  cin>>n;
  int temp = n;
  vector<vector<long long>> dp(n+1, vector<long long> (10, -1));
  cout<<recursion(n, 0, dp)<<endl;
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