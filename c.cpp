#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

pair<int, string> check(string s, char x, char y, char z)
{
  int count = 0;
  for(int i = 0; i < s.size(); i++)
  {
    int pos = i % 3;
    if(pos == 0)
    {
      if(s[i] != x)
      {
        s[i] = x; count++;
      }
    }else if(pos == 1)
    {
      if(s[i] != y){
        s[i] = y; count++;
      }
    }else{
      if(s[i] != z)
      {
        s[i] = z; count++;
      }
    }
  }
  return {count , s};
}

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  pair<int, string> result = check(s, 'R', 'G', 'B');
  result = min(result, check(s, 'R', 'B', 'G'));
  result = min(result, check(s, 'B', 'R', 'G'));
  result = min(result, check(s, 'B', 'G', 'R'));
  result = min(result, check(s, 'G', 'B', 'R'));
  result = min(result, check(s, 'G', 'R', 'B'));
  cout << result.first << endl;
  cout << result.second << endl;
}
