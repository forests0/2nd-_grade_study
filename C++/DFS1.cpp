#include <iostream>
using namespace std;

int arr[8][8] = {
	{ 0, 1, 1, 0, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 0, 1, 0},
	{ 1, 0, 0, 1, 1, 0, 0, 0},
	{ 0, 0, 1, 0, 1, 0, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 1, 0},
	{ 0, 1, 0, 0, 0, 1, 0, 1},
	{ 1, 0, 0, 0, 0, 0, 1, 0}
	};

int check[8];

int DFS(int x)
{
  if(check[x] == 1)  return;
  check[x] = 1;
  cout << x << " ";
  for (int i = 0; i < 8; i++)
  {
    if (arr[x][i] == 1 && check[i] == 0)
      DFS(i);
  }
  return 1;
}

int main()
{
  DFS(0);
}