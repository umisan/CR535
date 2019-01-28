#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

char choose(char x, char y, char z)
{
  bool r = false;
  bool g = false;
  bool b = false;
  if(x == 'R') r = true;
  if(x == 'G') g = true;
  if(x == 'B') b = true;
  if(z == 'R') r = true;
  if(z == 'G') g = true;
  if(z == 'B') b = true;
  if(!r) return 'R';
  if(!g) return 'G';
  if(!b) return 'B';
  return 'R';
}

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count = 0;
  for(int i = 0; i < n - 1; i++)
  {
    if(i == n - 2 && s[i] == s[i + 1])
    {
      s[i + 1] = choose(s[i], s[i + 1], 'a');
      count++;
      i++;
    }else{
      if(s[i] == s[i + 1])
      {
        s[i + 1] = choose(s[i], s[i + 1], s[i + 2]);
        count++;
        i++;
      }
    }
  }
  cout << count << endl;
  cout << s << endl;
}
