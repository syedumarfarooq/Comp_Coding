//Time and space Complexity of Recursive Solution
  //1) Time Complexity:O(n)
      // eg:
      void printArray(int all, int n){
        if(n== 0) return;  //}
        cout<<*a<<" ";     //}takes k time to process both combined 
        printArray(a+1, n-1);
      ｝
      // T(n)=k+T(n-1)
      // T(n-1)=k+T(n-2)
      // T(n-2)=k+T(n-3)
      // T(n-3)=k+T(n-4)
      //   .
      //   .
      //   .
      //   .
      // T(1)=k+T(0)
      // T(0)=k1       }as k1 is the time to process only the if(n==0) as it does not process cout line so different process time
      // -----------------
      // T(n)=nK+k1 }   as t(n-1),T(n-2)... will all get cancelled
      // =>O(nK+k1)
      // =>O(n)
  //Space Complexity:O((n+1)*m)=O(n)}where is m is constant space
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
  // 2)Time Complexity:O(n)
      // eg:
      int fact(int n)
        if (n == 1)  //}takes k time to process
        return 1;
        return n * fact(n - 1);
        ｝
      // T(n)=k+T(n-1)
      // T(n-1)=k+T(n-2)
      // T(n-2)=k+T(n-3)
      // T(n-3)=k+T(n-4)
      //   .
      //   .
      //   .
      //   .
      // T(1)=k+T(0)
      // T(0)=k      
      // -----------------
      // T(n)=nK }   as t(n-1),T(n-2)... will all get cancelled
      // =>O(nK)
      // =>O(n)
  //Space Complexity:O(n*m)=O(n)}where is m is constant space
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
  // 3)Time Complexity:O(n)
      // eg:
          int BS(int a[], int k, int start, int end){
            if (start › end)
            return -1;
            int mid = start + (end - start) / 2;
            if (a[mid] = k)
            return mid;
            else if (k › a [mid])
            {
              return BS( a,k, mid + 1, end);
            }
            else
            {
              return BS( a,k, start, mid-1);
            }
          }
          // T(n)=k+T(n/2)
          // T(n/2)=k+T(n/4)
          // T(n/4)=k+T(n/8)
          //   .
          //   .
          //   .
          //   .
          // T(2)=k+T(1)
          // T(1)=k      
          // -----------------
          // T(n)=k }   as t(n/2),T(n/4)... will all get cancelled
          // =>O(a*K)}where a is log n  and k is constant as n/2^a=1 so a=logn i.e n iterates till it becomes 1
          // =>O(logn)
      //Space Complexity:O(k*logn)=O(logn)}where k is constant space
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
  // 4)Time Complexity:O(2^n) very high complexity not OPTIMAL can be solved more optimally using dynamic programming
      // eg:
        int fib(int n){
        if(n = 0|| n == 1) return n;
        return fib(n - 1) + fib(n - 2);
        }
        // T(n)<=2^0*c+2^1*c........}where c is the processing time of addition in return statement and this is derived by tree where fib(n)=>fib(n-1)+fib(n-2) i.e it increases by 2^1,2^2,2^3
        // T(n)<=c[2^0+2^1+2^2.........+2^n-1]
        // T(n)<=c[2^n-1]=>2^n
