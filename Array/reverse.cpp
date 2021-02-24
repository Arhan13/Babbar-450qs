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

// void insertionSort(int arr[], int n)
// {
//   int key;
//   for (int i = 1; i < n; i++)
//   {
//     key = arr[i];
//     int j = i - 1;


//     while (j >= 0 && arr[j] > key)
//     {
//       arr[j + 1] = arr[j];
//       j = j - 1;
//     }
//     arr[j + 1] = key;
//   }
// }

void reverse_arr(int arr[], int n){
  int start=0, end=n-1;
  int temp;
  while(start<end){
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}






int main() {
  ios::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int arr[] = {5, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  reverse_arr(arr, size);

  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}