Print all subarrays using recursion
eg:input:1,2,3,4,5
  output:
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
2 
2 3 
2 3 4 
2 3 4 5 
3 
3 4 
3 4 5 
4 
4 5 
5 


...Program finished with exit code 0
Press ENTER to exit console.
#include <iostream>
#include<vector>
using namespace std;
void printSubarr_util(vector<int>& num,int start,int end){
    if(end>=num.size()){
        return;
    }
    for(int i=start;i<=end;i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
    printSubarr_util(num,start,end+1);
}
void printSubArr(vector<int> &num){
    for(int start=0;start<=num.size();start++){
        int end=start;
        printSubarr_util(num,start,end);
    }
    return;
}
int main()
{
    vector<int> num{1,2,3,4,5};
    printSubArr(num);

    return 0;
}
