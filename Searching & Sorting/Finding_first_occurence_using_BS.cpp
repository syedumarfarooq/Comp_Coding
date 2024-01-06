// Finding first occurence of an element in a sorted array using binary search
// Example:[1,3,4,4,4,5]
//         target:4
// Output:2
int firstOccurence(vector<int> v,int target){
  int s=0;
  int ans=-1;
  int e=v.size()-1;
  int mid=s+(e-s)/2;
  while(s<=e){
    if(target==v[mid]){
      ans=mid;
      e=mid-1;
    }
    else if(target<v[mid]){
      e=mid-1;
    }
    else{
      s=mid+1;
    }
    mid=s+(e-s)/2;
  }
  return ans;
}
