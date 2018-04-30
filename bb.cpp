#include<bits/stdc++.h>

using namespace std;

map<string, int> pocket{ };
string inStr[101];

void parseInput(string strInput) { // a Parse the Input from String to Variable

  string character,count;
  bool isPassed = false;

  for (int i=0;i<strInput.length();i++) {
    if (strInput[i] != ':' && !isPassed) {
      character += strInput[i];
    } else if (strInput[i] == ':') {
      isPassed = true;
    } else {
      if ( (strInput[i] == ',')  || (i == strInput.length()-1) ) {
        if (i == strInput.length()-1) {
          count += strInput[i];
        }
        stringstream parseInt(count);
        int x = 0;
        parseInt >> x;

        pocket[character] = x;
        character = "";
        count = "";
        isPassed = false;
      } else {
        count += strInput[i];
      }
    }
  }
}

void addPocket(string addingPocket) { // add the pocket color
  pocket[addingPocket]++;
}

void popPocket(string poppingPocket) { // delete the pocket color
  pocket[poppingPocket]--;
}

int main () {
  string words,input;

  cin >> words;
  cin >> input;

  parseInput(input); // parse the input

  string action;
  while (cin >> action) { // while not eof then input
    if (action == "SELIP") {
      string color;
      int index;
      inputSelip : // if the input is just SELIP then input again (like the testcase)
        cin >> color;
      if (color == "SELIP") goto inputSelip;
        cin >> index;
      if ((pocket[color] > 0) && ((index < words.length()+1) && (index > -1))) {
        words.insert(index, color);
        popPocket(color);
      }
    } else if (action == "AMBIL") {
      int index;
      cin >> index;
      if ( (index > -1) && (index < words.length()) ) {
        string temp(1, words[index]);
        addPocket(temp);
        words.erase(index, 1);
      }
    }
  }

  cout << words << endl;
  string ans;

  map<string, int>::iterator ii;
  for (ii = pocket.begin(); ii != pocket.end(); ii++ ) {
    if (ii->second > 0) { // to seperate the zero pocket color
      ans += ii->first;
      ans += ":";
      ans += to_string(ii->second);
      ans += ",";
    }
  }

  for (int j=0;j<ans.length()-1;j++) cout << ans[j]; // output the color left inside the pocket
  cout << endl;
}