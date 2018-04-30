#include<bits/stdc++.h>

using namespace std;

int r,c,rStart,cStart,rEnd,cEnd;
string peta[102];
string answer;

void dfs(int y,int x,string jwb) {
  if ((x>-1) && (x<c) && (y>-1) && (y<r)) { // to check if the coordinate is inside the map
    if (peta[y][x] != 'X') { // to check if the coordinate isn't a wall
      if (peta[y][x] == 'E') { // to check if the coordinate is the end
        answer = jwb;
      }
      else if (peta[y][x] == '.' || peta[y][x] == 'S') {
        peta[y][x] = '0';
        dfs(y+1,x,jwb + "D"); // go DOWN
        dfs(y-1,x,jwb + "U"); // go UP
        dfs(y,x+1,jwb + "R"); // go RIGHT
        dfs(y,x-1,jwb + "L"); // go LEFT
      }
    }
  }
}

int main () {

  cin >> r >> c;
  getline(cin, peta[0]); // getline in C++ will get the line as an input, this is the dummy input
  for (int i=0;i<r;i++) {
    getline(cin,peta[i]);
  }

  for (int i=0;i<r;i++) { // to check where is the Start point
    for (int j=0;j<r;j++) {
      if (peta[i][j] == 'S') {
        rStart = i;
        cStart = j;
      }
    }
  }

  dfs(rStart,cStart,""); // Start searching from the STARTING point
  cout << answer << endl;
}