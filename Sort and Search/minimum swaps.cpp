//Template
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define endl "\n"
#define vi vector<int>
#define se set<char>
#define pb push_back
#define um unordered_map
typedef long long ll;
using namespace std;


int minSwaps(vector<int>&nums) {
  // Code here

  //Storing the values
  pair<int , int > arrPos[nums.size()];
  for (int i = 0; i < nums.size(); i++) {
    arrPos[i].first = nums[i];
    arrPos[i].second = i;
  }
  //Sorting and getting the positions
  sort(arrPos, arrPos + nums.size());

  vector<bool> vis(nums.size(), false);

  int ans = 0;

  //Traversing the array
  for (int i = 0; i < nums.size(); i++) {
    //If the node is visited or is swapped at the right position
    if (vis[i] || arrPos[i].second == i) {
      continue;
    }
    int cycle_size = 0;
    int j = i;
    while (!vis[j]) {
      vis[j] = 1;
      j = arrPos[j].second;
      cycle_size++;
    }
    if (cycle_size > 0) {
      ans += cycle_size - 1;
    }
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int arr[] = {5, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  minimumswaps(arr, size);
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;




  return 0;
}