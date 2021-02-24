//Template
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int testCase; cin >> testCase;
  while (testCase--) {
    int n; cin >> n;
    int k; cin >> k;
    while (k % 2 == 0) {
      k = k / 2;
    }
    //cout<<k<<endl;
    int arr[n];
    int data;
    int flag = 1;
    for (int i = 0; i < n; i++) {
      cin >> data;
      if (data % k != 0) {
        flag = 0;
      }
    }
    if (flag == 1) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }

  }
  return 0;
}