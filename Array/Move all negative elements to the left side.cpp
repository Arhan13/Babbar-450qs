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


void rearrange(int arr[], int n) {
  // int j;
  // for(int i=0;i<n;i++){
  //   //When its negative
  //   if(arr[i]<0){
  //     if(i!=j){
  //       swap(arr[i], arr[j]);
  //     }
  //     j++;
  //   }
  // }

  int j;
  for(int i=0;i<n;i++){
    if(arr[i]<0){
      if(i!=j){
        swap(arr[i], arr[j]);
      }
      j++;
    }
  }
}


int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
  int n = sizeof(arr) / sizeof(arr[0]);
  rearrange(arr, n);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}