// You have an array with n positions (or slots) and m stacks. You need to place these m stacks inside the array, one stack per position.
// If the number of positions n is less than the number of stacks m, it is impossible to place all the stacks.
//performing push and pop and be efficient
#include<iostream>
using namespace std;
class NStack{
    int *a,*top,*next;
    int n;//no of stacks
    int size;//size of array
    int freeSpot;//tells free space in main array
    public:
    NStack(int _n,int _s):n(_n),size(_s){
        freeSpot=0;
        a=new int[size];
        top=new int[n];
        next=new int[size];//this does two things first it keeps the next available corresponding to the index
        //then after any element(a) is placed on that index in main array it will keep the next element of the element
        //i.e is element(a) is top then the next element to it; so that we can keep track of the next element in the stack
        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        for(int i=0;i<size;i++){
            next[i]=i+1;//for an array of 6 the next will 1,2,3,4,5,-1 as the  element stores the next freespace
        }
        next[size-1]=-1;//end -1 because there is no next available space for the last element
    }
    bool push(int X,int m){
        if(freeSpot==-1){
            return false;//stack overflow
        }
        int index=freeSpot;
        freeSpot=next[index];
        a[index]=X;
        next[index]=top[m-1];//this stores the previous top element into the next before making the present element the top
        top[m-1]=index;
        return true;
    }
    int pop(int m){
        if(top[m-1]==-1){
            return -1;//stack underflow
        }
        int index=top[m-1];
        top[m-1]=next[index];
        int poppedElement=a[index];
        next[index]=freeSpot;
        freeSpot=index;
        return poppedElement;
    }
    ~NStack(){
        delete[] a;
        delete[] top;
        delete[] next;
        
    }
};
int main(){
    NStack s(3,6);
    cout<<s.push(10,1)<<endl;
    cout<<s.pop(1);
    return 0;
}
