#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>

using namespace std;

bool apply_query(vector<int> &target, pair<int, int> segment, int ma, int mi)
{
  if(segment.first <= ma && ma <= segment.second){
    return false;
  }
  if(segment.first <= mi && mi <= segment.second)
  {
    for(int i = segment.first; i <= segment.second; i++)
    {
      target[i]--;
    }
    return true;
  }
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m; 
  vector<int> a(n);
  int amin = 1e6;
  int amax = -1e6;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    amin = min(amin, a[i]);
    amax = max(amax, a[i]);
  }
  vector<pair<int, int>> q(m);
  for(int i = 0; i < m; i++)
  {
    int l, r;
    cin >> l >> r;
    q[i] = {l - 1, r - 1};
  }
  if(m == 0){
    cout << amax - amin << endl;
    cout << 0 << endl;
    return 0;
  }
  int result = amax - amin;
  vector<int> result_query;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(i == j) continue;
      vector<int> applied;
      vector<int> temp_a = a;
      int temp = a[i] - a[j];
      for(int k = 0; k < m; k++)
      {
        if(apply_query(temp_a, q[k], i, j))
        {
          temp++;
          applied.push_back(k);
        }
      }
      if(temp > result)
      {
        result = temp;
        result_query = applied;
      }
    }
  }
  cout << result << endl;
  cout << result_query.size() << endl;
  for(auto e : result_query){
    cout << e + 1 << " ";
  }
  cout << endl;
}
