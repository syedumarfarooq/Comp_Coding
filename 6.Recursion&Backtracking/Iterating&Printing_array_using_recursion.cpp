1)// Printing array using recursion
//MY METHOD
// #include <iostream>
// using namespace std;
// void fib(int arr[],int n){
//     if(n==0){
//         cout<<arr[n]<<"end";
//         return;
//     }
//     fib(arr,n-1);
//     cout<<arr[n]<<" ";
    
// }
// int main()
// {
//     int arr[]={10,20,30,40,50};
//     int n=5;
//     fib(arr,5);

//     return 0;
// }
int i=0
void print(int arr[], int n, int i) {
//base case
  if(i>=n){
    return;
}
cout<<arr[i];
//baaki recursion sambhal lega
print(arr, n, i+1);
｝
2)//Finding maximum number in an array
    findMax(int arr[], int n, int i, int& maxi) {//if we dont use & then it is passed by value and after completion of that function erases it local variable so we have to pass by reference
    
        if(i>=n){
    return;
        }
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    findMax(arr,n,i+1,maxi);
}
https://drive.google.com/file/d/1kSCKNrCWWg4zXFH7NE76XITWBps3y9aP/view?usp=drive_link
