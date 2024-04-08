// FINDING TIME COMPLEXITY USING INTUITION
// TIME COMPLEXITY:(1 call ka time)*total no of calls
// SPACE COMPLEXITY:total depth of the tree OR (1 call ka space)*total no of calls
// 1)Counting
void printArray(int all, int n){
        if(n== 0) return;  //}
        cout<<*a<<" ";     //}takes k time to process both combined 
        printArray(a+1, n-1);
      ｝
time complexity:O(k*(n+1));
