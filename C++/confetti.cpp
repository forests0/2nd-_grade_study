#include <iostream>
using namespace std;

int whiteCount;
int blueCount;
int n;
int board[128][128];

void FindColorPaper(int x, int y, int size);

int main() {
   cin >> n;
  
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cin >> board[i][j];
      }
   }

  FindColorPaper(0, 0, n);
  
  cout << whiteCount << endl << blueCount;
   return 0;
}

void FindColorPaper(int x, int y, int size) {
   int color = board[x][y];
  int i;
  for(i = x; i < x + size; i++) {
    int j;
    for(j = y; j < y + size; j++) {
      if(color != board[i][j])
        break;
    }
    if(j < y + size)
      break;
  }
  if(i == x + size) {
    if(color == 1)
      blueCount++;
    else if(color == 0)
      whiteCount++;
    return;
  }
  else {
    FindColorPaper(x, y, size / 2);
    FindColorPaper(x, y + size / 2, size / 2);
    FindColorPaper(x + size / 2, y, size / 2);
    FindColorPaper(x + size / 2, y + size / 2, size / 2);
  }
}