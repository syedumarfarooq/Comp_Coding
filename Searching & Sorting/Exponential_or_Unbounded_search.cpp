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
// Time complexity:O(log(2^logm-1))or O(log(2^logm/2))
// example:2^4-2^3=>2^log₂16-2^log₂16-1=>2^log4(as base 2 and 2 from 2^4=16 will be cancelled)=>2^logm-2^logm-1
//         =>2^logm(1-2^-1)
//         =>O(logn)=>O(log(2^logm-1))

