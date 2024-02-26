// exponential search
int exposearch(int a[],int n,int target){
  if(a[0]==target){
    return 0;
  }
  int i=1;
  while(i<n && a[i]<target){
    i=i*2;//or i=i<<1;
  }
return binarysearch(a,i/2`(start position)`,min(i,n-1)`(if i goes outside the n it takes n)`,target);
}
// Time complexity:O(logm)   where m is till where i goes for example if the i goes till 16 index then m is 16

