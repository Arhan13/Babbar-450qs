//Template
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int data; int eve_counter = 0, odd_counter = 0;
    while (n--) {
      cin >> data;
      if (data % 2 != 0) {
        eve_counter++;
      }
    }
    if(odd_counter%2==0){
      cout<<"1"<<endl;
    }
    else{
      cout<<"2"<<endl;
    }
  }
  return 0;
}