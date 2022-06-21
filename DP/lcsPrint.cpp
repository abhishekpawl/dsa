#include <bits/stdc++.h>

vector<vector<int>> lcs(string s, string t)
{
    int m = s.length();
    int n = t.length();

    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    return solve(m, n, s, t, dp);

    vector<vector<int>> tab(m+1, vector<int> (n+1, 0));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1]) {
                tab[i][j] = 1 + tab[i-1][j-1];
            } else {
                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
            }
        }
    }

    return tab;
}

int main() {
  string a, b;
  cout<<"Enter two strings: "<<endl;
  cin>>a>>b;

  vector<vector<int>> tab = lcs(a, b);

  int i = a.length();
  int j = b.length();

  string res = '';

  while(i != 0 || j != 0) {
    if(a[i-1] == b[j-1]) {
      s += a[i-1];
      i--;
      j--;
    } else {
      if(tab[i-1][j] > tab[i][j-1]) {
        i--;
      } else {
        j--;
      }
    }
  }

  reverse(res.begin(), res.end());

  cout<<res<<endl;

  return 0;
}