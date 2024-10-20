class KQueue{
    public:
    int n,k,freeSpot;
    int *arr,*front,*next,*rear;
    KQueue(int _n,int _k):n(_n),k(_k),freeSpot(0)
    {
        arr=new int[n];
        next=new int[n];//this does two things at first keeps the index of next free available spot and then after it is occupied it keep the index of next element of the queue if it is the last element it keeps -1
        front=new int[k];
        rear=new int[k];
        for(int i=0;i<n;i++){
            next[i]=i+1;//for an array of 6 the next will 1,2,3,4,5,-1 as the  element stores the next freespace
        }
        next[n-1]=-1;//end -1 because there is no next available space for the last element
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
    }
    bool push(int X,int qi){
        if(freeSpot==-1){
            return false;
        }
        int index=freeSpot;
        freeSpot=next[index];
        if(front[qi]==-1){
            front[qi]=index;
        }else{
            next[rear[qi]]=index;//this stores the current index into the last elements index in  next[] array
        }
        next[index]=-1;
        rear[qi]=index;
        arr[index]=X;
        return true;
    }
    int pop(int qi){
        if(front[qi]==-1){
            return -1;
        }
        int index=front[qi];
        front[qi]=next[index];
        next[index]=freeSpot;
        freeSpot=index;
        return arr[index];
    }
    ~KQueue(){
        delete[] arr;
        delete[] next;
        delete[] front;
        delete[] rear;
    }
};
int main(){
  KQueue kq(8,3);
  cout<<kq.push(1,0);
  cout<<kq.push(2,1);
  kq.pop(1);
}
