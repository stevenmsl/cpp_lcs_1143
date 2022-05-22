#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol1143;
using namespace std;

/*takeaways
  - using DP
  - DP[i][j] stores the length of LCS between the first
    i chars from text1 and the first j chars from text2
      a  b  c  d  e
    a 1  1  1  1  1
    c 1  1  2  2  2
    e 1  1  2  2  3
*/

int Solution::findLCS(string text1, string text2)
{
  int m = text1.size(), n = text2.size();

  auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1));
  for (auto i = 1; i <= m; i++)
    for (auto j = 1; j <= n; j++)
      /* we are using 1-based array for dp
         - so dp[i][j] is the LCS between text1[0..i-1]
           and text2[0..j-1]
      */
      if (text1[i - 1] == text2[j - 1])
        /* extend the LCS by 1 after adding this char */
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        /* no contribution but carries over from before
           but which one?
           - two possibilities
             - walking right from left in the same row
             - walking down from above in the same col
             - we will pick the max one
        */
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

  return dp[m][n];
}