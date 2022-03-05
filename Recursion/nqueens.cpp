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

bool isSafe(vector<string> board, int row, int col, int n) {
  int temp_row = row;
  int temp_col = col;

  while(row >= 0 && col >= 0) {
    if(board[row][col] == 'Q') return false;
    row--;
    col--;
  }

  row = temp_row;
  col = temp_col;

  while(col >= 0) {
    if(board[row][col] == 'Q') return false;
    col--;
  }

  col = temp_col;

  while(row < n && col >= 0) {
    if(board[row][col] == 'Q') return false;
    row++;
    col--;
  }

  return true;
}

void nqueens(vector<vector<string>> &ans, vector<string> &board, int col, int n) {
  if(col == n) {
    ans.push_back(board);
    return;
  }

  repi(row, 0, n) {
    if(isSafe(board, row, col, n)) {
      board[row][col] = 'Q';
      nqueens(ans, board, col+1, n);
      board[row][col] = '.';
    }
  }
}

void solve() {
  int n;
  cin>>n;
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');
  nqueens(ans, board, 0, n);
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