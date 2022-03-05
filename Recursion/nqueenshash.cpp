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

void nqueenshash(vector<vector<string>> &ans, vi &leftrow, vi &lowerdiagonal, vi &upperdiagonal, vector<string> &board, int col, int n) {
  if(col == n) {
    ans.push_back(board);
    return;
  }

  repi(row, 0, n) {
    if(leftrow[row] == 0 && lowerdiagonal[row + col] == 0 && upperdiagonal[n - 1 + col - row] == 0) {
      board[row][col] = 'Q';
      leftrow[row] = 1;
      lowerdiagonal[row + col] = 1;
      upperdiagonal[n - 1 + col - row] = 1;
      nqueenshash(ans, leftrow, lowerdiagonal, upperdiagonal, board, col+1, n);
      board[row][col] = '.';
      leftrow[row] = 0;
      lowerdiagonal[row + col] = 0;
      upperdiagonal[n - 1 + col - row] = 0;
    }
  }
}

void solve() {
  int n;
  cin>>n;
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');
  repi(i, 0, n) {
    board[i] = s;
  }
  vi leftrow(n, 0), lowerdiagonal(2*n-1, 0), upperdiagonal(2*n-1, 0);
  nqueenshash(ans, leftrow, lowerdiagonal, upperdiagonal, board, 0, n);
  repi(i, 0, ans.size()) {
    repi(j, 0, ans[i].size()) {
      cout<<ans[i][j]<<endl;
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