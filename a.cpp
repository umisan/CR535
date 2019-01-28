#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
  int q;
  cin >> q;
  for(int i = 0; i < q; i++)
  {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if(l1 < l2)
    {
      cout << l1 << " " << r2 << endl;
    }else{
      cout << r1 << " " << l2 << endl;
    }
  }
}
