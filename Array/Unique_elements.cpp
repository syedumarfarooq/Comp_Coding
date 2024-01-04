 // Unique element question
    // example:[1,2,1,2,3,4,4]=>3 because it is the only element which is unique
    int findUnique(vector<int> arr){
      int ans=0;
      for(int i=0;i<arr.size();i++){
        ans=ans^arr[i];
      }
      return ans;
    }
    int main(){
  
      int n;
      cout<<"enter the size of array"<<endl;
      cin>>n;
      vector<int> arr(n);
      cout<<"enter the elements"<<endl;
      for(int i=0;i<arr.size();i++){
        cin>>arr[i];
      }
      int uniqueElement =findUnique(arr);
      cout<<uniqueElement;
    }
