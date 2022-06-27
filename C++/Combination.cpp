#include <iostream>
#include <vector>
using namespace std;
void printPicked(vector<int> picked)
{
  for(int i = 0 ; i < picked.size() ; i++)
    cout << picked[i] << " ";
  cout << endl;
}
void pick(int n, vector<int> picked, int toPick)
{
  if(toPick==0) { printPicked(picked); return; }
  int smallest = picked.empty()? 1 : picked.back() + 1;
  for(int next = smallest; next <= n ; next++)
  {
    picked.push_back(next);
    pick(n, picked, toPick-1);
    picked.pop_back();
  }
}
int main(void)
{
  int n = 5;
  int r = 2;
  pick(n, vector<int>(), r);
  return 0;
}