class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // // code here
        // if(n==1){
        //     return 0;
        // }
        // sort(arr, arr+n);
        
        // //Initialize the answer
        // int ans = arr[n-1]-arr[0];
        
        // int small = arr[0]+k;
        // int big = arr[n-1]-k;
        
        // if(small>big){
        //     swap(small, big);
        // }
        
        // for(int i=1;i<n-1;i++){
        //     int add = arr[i]+k;
        //     int sub = arr[i]-k;
            
        //     if(sub>=small || add<=big){
        //         continue;
        //     }
            
            
        //     //Otherwise apply greedy approach
        //     if(big-sub <= add-small){
        //         small = sub;
        //     }
        //     else{
        //         big = add;
        //     }
        // }
        // return min(ans, big-small);


        //Base Case
        if(n==1){
            return 0;
        }
        sort(arr, arr+n);

        int temp_ans = arr[n-1]-arr[0];

        int maxElement = arr[n-1]-k;
        int minElement = arr[0]+k;

        for(int i=1;i<n-1;i++){
            if(arr[i]>k){
               
               maxElement = max(arr[i-1]+k, maxElement);
               minElement = min(arr[i]-k, minElement); 
               temp_ans = min(temp_ans, max-min)
            }
            else{
                continue;
            }
            
        }
        return temp_ans;
    }
};