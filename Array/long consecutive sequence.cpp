int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
  sort(arr, arr+N);
  vector<int> arr2;
  arr2.push_back(arr[0]);
  for(int i=1;i<N;i++){
      if(arr[i]!=arr[i-1]){
        arr2.push_back(arr[i]);
      }
  }
  int ans = 0;
  int count=0;
  
  for(int i=0;i<N;i++){
      if((arr2[i] == arr2[i-1] + 1) && i>0){
        count++;
      }
      else{
          count = 1;
      }
      ans = max(ans, count);
  }
  return ans;
}