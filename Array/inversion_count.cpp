typedef long long ll;

// arr[]: Input Array
// N : Size of the Array arr[]

//Merge Sort Helper Function
ll _mergeSort(ll arr[], ll temp[], ll left, ll right);

//Merge Function
ll merge(ll arr[], ll left, ll mid, ll right);

ll mergeSort(ll arr[], ll arr_size){
    ll temp[arr_size];
    return _mergeSort(arr, temp, 0, arr_size-1);
}

ll merge(ll arr[], ll temp[], ll left, ll mid, ll right){
    ll i,j,k;
    ll inv_count=0;
    
    i = left; // index of left array
    j = mid; // index of right array
    k = left; //index of new array
    while((i<=(mid-1))&&(j<=right)){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            //If arr[i]>arr[j] then it is bigger than mid-i elements
            //As the left array elements should be less than right array elements
            inv_count += (mid-i);
        }
        
    }
    while(i<=(mid-1)){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(int i=left;i<=right;i++){
        arr[i] = temp[i];
    }
    return inv_count;
}

ll _mergeSort(ll arr[], ll temp[], ll left, ll right){
    ll mid, inv_count=0;
    if(right>left){
        mid = (left+right)/2;
        //Sum the left array inversions recursively
        inv_count += _mergeSort(arr, temp, left, mid);
        
        //Sum the right array invesrions recursively
        inv_count += _mergeSort(arr, temp, mid+1, right);
        
        //Merging the two parts
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}



ll inversionCount(ll arr[], ll N)
{

    return mergeSort(arr, N);
}