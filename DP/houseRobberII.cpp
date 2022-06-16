/* https://www.codingninjas.com/codestudio/problems/house-robber_839733 */
/*
  just maximum without picking adjacent elements but now 2 cases (since, first and last are adjacent):
  1. array[0,... n-1]
  2. array[1,... n]
  maximum of the two
*/
#include <bits/stdc++.h>
#define ll long long int

ll max(ll a, ll b) {
    return a > b ? a : b;
}

ll solve(int s, int e, vector<int> &valueInHouse) {
    ll prevRobbed, prevNotRobbed;
    prevNotRobbed = 0;
    prevRobbed = valueInHouse[s];
    ll i = s + 1;
    while(i <= e) {
        ll cur;
        if(i > 1) {
            cur = max(prevNotRobbed + valueInHouse[i], prevRobbed);
        } else {
            cur = valueInHouse[i];
        }
        prevNotRobbed = prevRobbed;
        prevRobbed = cur;
        i++;
    }
    return prevRobbed;
}

ll houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    if(valueInHouse.size() <= 3) {
        ll money = 0;
        for(auto it : valueInHouse) {
            money = max(money, it);
        }
        return money;
    }
    int e = valueInHouse.size() - 1;
    return max(solve(0, e-1, valueInHouse), solve(1, e, valueInHouse));
}