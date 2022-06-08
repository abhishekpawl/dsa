/* https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0 */
int frogJump(int n, vector<int> &heights)
{
  vector<int> dp(n, -1);
  int c1 = 0;
  int c2 = abs(heights[1] - heights[0]);
  if(n == 2) {
      return c2;
  }
  int i = 2;
  int res;
  while(i != n) {
    res = min(c1 + abs(heights[i] - heights[i-2]), c2 + abs(heights[i] - heights[i-1]));
    c1 = c2;
    c2 = res;
    i++;
  }
  return res;
}