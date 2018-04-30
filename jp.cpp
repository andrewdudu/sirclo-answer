#include<bits/stdc++.h>

using namespace std;

int main () {
  string jamPasir[11],status;
  int n;

  cin >> n;
  for (int i=0;i<n*2+1;i++) {
    for (int j=0;j<n*2+1;j++) {
      if (i==0 || i==n*2) {
        jamPasir[i] += "*";
      } else {
        if (j==i || i==n*2-j) {
          jamPasir[i] += "*";
        } else {
          if (j>i && j<n*2-i) jamPasir[i] += "*";
          else jamPasir[i] += " ";
        }
      }
    }
  }

  cin >> status;

  if (status == "KOSONG") {
    for (int i=0;i<n*2+1;i++) cout << jamPasir[i] << endl;
  } else {
    for (int i=n*2;i>=0;i--) cout << jamPasir[i] << endl;
  }
}