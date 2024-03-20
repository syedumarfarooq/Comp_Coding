// CLASS 1
// // RECURSION: when a function call itself
//       When is recursion used
//         when a bigger problem solution depends on small and same type of problem solution
    // --Recursive code conditions:
    // 1.Base condition
    // 2.Recursive relation// (f(n)=n+f(n-1) i.e bigger problem depends on smaller problem)
    // 3.processing(optional)//(printing or calcutaion)
    // -----Head Recursion
    // 1.Base condition
    // 2.Recursive relation// (f(n)=n+f(n-1) i.e bigger problem depends on smaller problem)
    // 3.processing(optional)//(printing or calcutaion)
    // -----Tail Recursion
    // 1.Base condition
    // 2.Recursive relation// (f(n)=n+f(n-1) i.e bigger problem depends on smaller problem)
    // 3.processing(optional)//(printing or calcutaion)
    // --Magical line to ace recursion
       // solve 1 case and recursion will take care of other cases
_________________IMP_______________    
WHENEVER YOU PASS A VARIABLE IN A FUNCTION AND U WANT TO STORE THAT DATA PASS IT BY REFERENCE&
//if it is not passed by reference it will create a new variable of same name at different address so the intial variable will not be changed and after completion of that function that variable is deleted
// CLASS 3
    // Whenever a expression is passed in pass by reference it gives error
    int binarySearch(vector<int>& arr,int& s,int& e,int& key){
        if(s>e)return -1;
        int mid=(s+e)/2;
        if(arr[mid]==key)return mid;
        if(arr[mid]<key){
            s=mid+1;
____IMP_____            return binarySearch(arr,s,e,key);//binarySearch(arr,mid+1,e,key);//if you give expression(a+b) in pass by reference it gives error so we have used s=mid+1 to avoid this
        }
        else{
            e=mid-1;
            return binarySearch(arr,s,e,key);
        }
