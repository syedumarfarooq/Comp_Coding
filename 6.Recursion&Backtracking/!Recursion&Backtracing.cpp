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
