#include <bits/stdc++.h>
using namespace std;

void lcs(string &s, string &t, vector<vector<int>> &tab)
{
    int m = s.length();
    int n = t.length();

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1]) {
                tab[i][j] = 1 + tab[i-1][j-1];
            } else {
                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
            }
        }
    }
}

int main() {
  string a, b;
  cout<<"Enter two strings: "<<endl;
  cin>>a>>b;

  int i = a.length();
  int j = b.length();

  vector<vector<int>> tab(i+1, vector<int> (j+1, 0));
  lcs(a, b, tab);

  string res = "";

  while(i != 0 && j != 0) {
    if(a[i-1] == b[j-1]) {
      res += a[i-1];
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