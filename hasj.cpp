#include<bits/stdc++.h>

using namespace std;

int r,c,rStart,cStart,rEnd,cEnd;
string peta[102];
bool ans;
string answer;

void dfs(int y,int x,string jwb) {
  if ((x>-1) && (x<c) && (y>-1) && (y<r)) {
    if (peta[y][x] != 'X') {
      if (peta[y][x] == 'E') {
        ans = true;
        answer = jwb;
      }
      else if (peta[y][x] == '.' || peta[y][x] == 'S') {
        peta[y][x] = '0';
        dfs(y+1,x,jwb + "D");
        dfs(y-1,x,jwb + "U");
        dfs(y,x+1,jwb + "R");
        dfs(y,x-1,jwb + "L");
      }
    }
  }
}

int main () {

  cin >> r >> c;
  getline(cin, peta[0]);
  for (int i=0;i<r;i++) {
    getline(cin,peta[i]);
  }

  for (int i=0;i<r;i++) {
    for (int j=0;j<r;j++) {
      if (peta[i][j] == 'S') {
        rStart = i;
        cStart = j;
      } else if (peta[i][j] == 'E') {
        rEnd = i;
        cEnd = j;
      }
    }
  }

  dfs(rStart,cStart,"");
  cout << answer << endl;
}