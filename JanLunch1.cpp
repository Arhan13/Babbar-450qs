//Template
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
  int testCases; cin >> testCases;
  while (testCases--) {
    int n; cin >> n;
    int even_count = 0, odd_count = 0;
    int data;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> data;
      if (data % 2 == 0) {
        even_count++;
      }
      else {
        odd_count++;
      }
    }
    cout << min(odd_count, even_count) << endl;
  }
  return 0;
}