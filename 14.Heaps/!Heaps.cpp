*//Heaps***
// It is a complete binary tree that satifies the heap property
// A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes in the last 
// level are as far left as possible.
#include <iostream>
using namespace std;

class Heap{
        public:
        int arr[101];//use dynamic array vector
        int size ;

        Heap() {
                size = 0;
        }
  
        void insert(int value) {
                ///value insert karo end me 
                size = size + 1;
                int index = size;
                arr[index] = value;

                //iss value ko place at right{correct position} position
                while(index > 1) {
                        int parentIndex = index/2;
                        if(arr[index] > arr[parentIndex]) {
                                swap(arr[index] , arr[parentIndex]);
                                index = parentIndex;
                        }
                        else {
                                break;
                        }
                }
        }

        int delete() {
                //in heap only the first element gets deleted
                int ans  = arr[1];
                //replace root node value with last node data
                arr[1] = arr[size];
                size--;

                //place root node ka data on its correct position
                int index = 1;
                while(index < size) {
                        int left = 2*index;
                        int right = 2*index+1;
                        
                        int largest = index;

                        if(left < size && arr[largest] < arr[left] ) {
                                largest = left;
                        }
                        if(right < size && arr[largest] < arr[right] ) {
                                largest = right;
                        }

                        if(largest == index) {
                                //value is atr correct position
                                break; 
                        }
                        else {
                                swap(arr[index], arr[largest]);
                                index = largest;
                        } 
                }
                return ans;
        }
};

int main() {
  Heap h;

   h.insert(50);
    h.insert(30);
     h.insert(70);
      h.insert(40);
       h.insert(80);
        h.insert(100);

  cout << "printing the heap " << endl;
  for(int i=0; i<=h.size; i++) {
          cout << h.arr[i] << " ";
  }cout << endl;

  return 0;
}
*//Heapify****
//convert any array into heap we use heapify function
//a element whose index is given should be placed in its correct position
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
        int index = i;
        int leftIndex = 2*i;
        int rightIndex = 2*i+1;
        int largest = index;

        if(leftIndex <= n && arr[largest] < arr[leftIndex]) {
                largest = leftIndex;
        }
        if(rightIndex <= n && arr[largest] < arr[rightIndex]) {
                largest = rightIndex;
        }

        if(index != largest) {
                //left ya right child me se koi > hogya currentNode se
                swap(arr[index], arr[largest]);
                index = largest;
                heapify(arr, n, index);
        }
}

void buildHeap(int arr[], int n) {//TC:O(n)???H.W but the loop is n/2 and the heapify TC is logn
        //n/2 because the leaf node is always considered heap as they have no children to compare with 
        //from n/2+1 to n all are leaf nodes
        for(int i = n/2; i>0; i--) {
                heapify(arr,n, i);
        }
}
void heapSort(int arr[], int n) {
        while(n != 1) {
                swap(arr[1], arr[n--]);//the largest number is put at the back and then heapified excluding the number put at the back
                // then the root will again contain the larget number then repeat the process
                heapify(arr,n,1);
        }
}

int main() {
  int arr[] = {-1,12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
  int n = 11;
  buildHeap(arr, n);

  cout << "printint the heap "<< endl;
  for(int i=0; i<=n; i++) {
          cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr, n);

  cout << endl << "printint the heap "<< endl;
  for(int i=1; i<=n; i++) {
          cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
