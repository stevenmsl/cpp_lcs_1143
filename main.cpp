#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1143;

/*
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
*/

tuple<string, string, int>
testFixture1()
{
  return make_tuple("abcde", "ace", 3);
}

/*
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
*/

tuple<string, string, int>
testFixture2()
{
  return make_tuple("abc", "abc", 3);
}

/*
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/
tuple<string, string, int>
testFixture3()
{
  return make_tuple("abc", "def", 0);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.findLCS(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.findLCS(get<0>(f), get<1>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.findLCS(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}