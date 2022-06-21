/* https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 */
#include <bits/stdc++.h>

int lcs(string &a, string &b) {
    int n = a.length();
    vector<vector<int>> tab(n+1, vector<int> (n+1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i-1] == b[j-1]) {
                tab[i][j] = 1 + tab[i-1][j-1];
            } else {
                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
            }
        }
    }
    
    return tab[n][n];
}

int minInsertion(string &str)
{
    string s1 = str;
    reverse(s1.begin(), s1.end());
    int l = lcs(str, s1);
    return str.length() - l;
}