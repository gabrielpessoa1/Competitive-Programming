// La Salle-Pui Ching Programming Challenge 培正喇沙編程挑戰賽 2018
// L - Labyrinth
// https://codeforces.com/gym/101807/problem/L

#include <bits/stdc++.h>
using namespace std;

const int ms = 105;

char grid[3][ms];

void lose() {
  cout << "Impossible\n";
  exit(0);
}

int main() {
  int w, a, b;
  cin >> w >> a >> b;
  a--; b--;
  bool swp = false;
  if(a > b) {
    swp = true;
    swap(a, b);
  }
  if((b - a) % 2 != 0) {
    lose();
  }
  if(a == 0 && a != b) {
    lose();
  }
  if(a == 1 && b - a == 2) {
    lose();
  }
  cout << "Possible\n";
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < w; j++) {
      if(i == 0 && j == a) grid[i][j] = 'A';
      else if(i == 2 && j == b) grid[i][j] = 'B';
      else if(i == 1 && j == 0) grid[i][j] = 'X';
      else grid[i][j] = '.';
    }
  }
  if(swp) {
    grid[0][a] = 'B';
    grid[2][b] = 'A';
  }
  if(a != b) {
    grid[0][a-1] = '*';
    if(b - a == 2) {
      grid[1][a-1] = '*';
    } else {
      grid[1][a] = '*';
      int dif = (b-a - 4)/2;
      for(int i = 0; i < dif; i++) {
        grid[1][a+i+1] = '*';
      }
    }
  }
  
  if(swp) {
    for(int i = 0; i < w; i++) swap(grid[0][i], grid[2][i]);
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < w; j++ ){
      cout << grid[i][j];
    }
    cout << '\n';
  }
}