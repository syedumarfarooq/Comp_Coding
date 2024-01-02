// *Time and space Complexity
  // O(1)<O(logN)<O(√ N)<O(N)<O(NlogN)<O(N^2)<O(N^3)<O(2^n)<O(N!)<O(N^n)
  // least complex---->most complex
// CLASS 1
//*Creating an array
  //declare
    int arr[10];//10 continous integer space is allocated to arr and base address is assigned to arr
  //initialise
    int arr[]={1,2,3,4,5};
    int arr1[5]={1,2,3,4,5};
    int arr2[5]={1,2,3};//=>1,2,3,0,0
    int arr[10]={0}//initialize the array to zero where all 10 elements are zero
    //int arr3[3]={1,2,3,4,5}//error
// index and accessing in array
  int arr[]={1,2,3,4,5};
  cout<<arr[4]<<endl;//=>5
  // taking input
  int arr[0]=5;
int arr[n];//Bad practise use dynamic array instead
arr[0]//=>value at base address +(0*4(int size is 4 bytes))
//whenever array is passed into a function its size should also be passed and it is passed by address(reference)
//CLASS 2
// Vector
  #include<vector>
  //declare
    vector<int> arr;
  //initialise
    vector<int> arr{10,20,30};
    vector<int> arr(10,-1);//it will create a vector of size 10 and initialize with -1
    vector<int> arr(n);
  // inserting element
    arr.push_back(5);
  //removing element
    arr.pop_back();
  //checking size
    arr.size();//size of vector means the number of elements stored in it
    arr.capacity();//capacity means the number of elements that can be stored 
  //checking if empty
    arr.empty();//=>true or false
  //for each loop 
    for(auto value:auto){
      cout<<value<<" ";
    }
  

    




