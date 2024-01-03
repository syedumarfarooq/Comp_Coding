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
    arr[0]//=>value at base address +(0*4(int size is 4 bytes)) this is to know the address of first index same to any another index
  // taking input
  int arr[0]=5;
  int arr[n];//Bad practise use dynamic array instead
  //whenever array is passed into a function its size should also be passed and it is passed by address(reference)
//CLASS 2
  // Vector
    #include<vector>
    #include<limits.h>//for INT_MIN and INT_MAX 
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
// CLASS 3
  // 2D ARRAY
    // declaring
      // int arr[100][100];
      // 2D array is stored in linear form inside data but for our easy visualization we vizualize it as a matrix
      // eg:1 2 3
      //    4 5 6 =>[1,2,3,4,5,6,7,8,9] 
      //    7 8 9
      // arr[2][1]=c*i+j=>7 arr[7]=8; where c is no of columns i.e 3 and i=2,j=1
      // u cannot access 2d array using arr[] it is just for our understading
    // initialise
      int arr[][]={{1,2},{3,4}};
    //while passing a 2d array into a function u have to pass the row,colum and give value after  1st bracket i.e first bracket can be empty
      // eg:void printarray(int arr[][3],int row,int column){
      // }
  // 2D VECTOR
    //declare
      vector<vector<int> > v;//space after first > is necessary
      // eg:
      // vector<vector<int> > arr;
      // vector<int> a{1,2,3};
      // vector<int> b{4,5,6};
      // vector<int> c{7,8,9};
      // arr.push_back(a);
      // arr.push_back(b);
      // arr.push_back(c);
      // for(int i=0;i<arr.size();i++){
      //   for(int j=0;j<arr[i].size();j++{
      //       cout<<arr[i][j];
      //   }
      // cout<<endl;
      // }
      vector<vector<int> >arr(rows,vector<int>(column,0));


  

    




