#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// brute force. T.C-> O(n); S.C-> O(1)
int getMinSubArrSum(vector<int> &v)
{
  int sum = 0;
  for (int i = 0; i < v.size(); i++)
  {
    int minimum = v[i];
    for (int j = i; j < v.size(); j++)
    {
      minimum = min(minimum, v[j]);
      sum += minimum;
    }
  }
  return sum;
};

int getMinSubArrSumOptimal(vector<int> &arr)
{
  stack<int> s;
  vector<int> pse(arr.size()), nse(arr.size());
  for (int i = 0; i < arr.size(); i++)
  {
    while (!s.empty() && arr[i] <= arr[s.top()])
    {
      s.pop();
    }
    pse[i] = s.empty() ? -1 : s.top();
    s.push(i);
  }
  while (!s.empty())
  {
    s.pop();
  }
  for (int i = arr.size() - 1; i >= 0; i--)
  {
    while (!s.empty() && arr[i] < arr[s.top()])
    {
      s.pop();
    }
    nse[i] = s.empty() ? arr.size() : s.top();
    s.push(i);
  }
  const long long MOD = 1000000007LL;
  long long sum = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    int left = i - pse[i];
    int right = nse[i] - i;
    long long contribution = (1LL * arr[i] * left * right);
    sum = (sum + contribution);
  }
  return sum % MOD;
}
int main()
{
  vector<int> v = {3, 1, 2, 4};
  cout << getMinSubArrSum(v) << endl;
  cout << getMinSubArrSumOptimal(v) << endl;
  return 0;
}