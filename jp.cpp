#include<bits/stdc++.h>

using namespace std;

int main () {
  string jamPasir[11],status;
  int n;

  cin >> n;
  for (int i=0;i<n*2+1;i++) { // Draw a Template of Jam Pasir
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

  if (status == "KOSONG") { // IF the input is KOSONG then draw it originally
    for (int i=0;i<n*2+1;i++) cout << jamPasir[i] << endl;
  } else { // IF the input is PENUH then draw it from Flipped bottom to top
    for (int i=n*2;i>=0;i--) cout << jamPasir[i] << endl;
  }
}