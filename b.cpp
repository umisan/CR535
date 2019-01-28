#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> d(n);
  vector<int> flag(10000 + 1, 0);
  for(int i = 0; i < n; i++)
  {
    cin >> d[i];
    flag[d[i]]++;
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  int x, y;
  x = d.front();
  for(int i = 1; i * i <= x; i++)
  {
    if(x % i == 0)
    {
      flag[i]--;
      flag[x / i]--;
    }
  }
  for(int i = 1; i < n; i++)
  {
    if(flag[d[i]] > 0)
    {
      y = d[i];
      break;
    }
  }
  cout << x << " " << y << endl;
  return 0;
}
