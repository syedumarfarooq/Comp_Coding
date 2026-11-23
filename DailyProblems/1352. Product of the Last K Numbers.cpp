*//this solution takes O(1) TC
// we are solving this by calculating the cumulative product from 0 to ith index so when we wan tthe product of last k element we will use the 
// product[n-1]/product[n-k-1] eg: the num array is 2,3,5 then the product array will be 2,6,30 if we want k=2 i.e last two element we will take 
// last cumulate sum i.e 2*3*5/2 as 2 will cancel the 2 in numerator we will get the product of last to so we divide the product of n-1 with product
// of n-k-1 If we get a zero in our nums array we will make the whole nums array empty by nums.clear() bcz it will mess up our product array as  next 
// element are multiple by zero and if the k last element include that zero the whole answer is zero so we start new product array after zero
class ProductOfNumbers {
    
public:
    vector<int> nums;
    int n;
    ProductOfNumbers() {
        nums.clear();
        n=0;
    }
    
    void add(int num) {
        if(num==0){
            nums.clear();
            n=0;
        }else{
            if(nums.empty()){
                nums.push_back(num);
            }else{
                nums.push_back(num*nums[n-1]);
                
            }
            n++;
        }
        
        
    }
    
    int getProduct(int k) {
        if(k>n)return 0;//this is because we are reseting the numbs when we find 0
        if(k==n)return nums[n-1];

        return nums[n-1]/nums[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */


*//O(k) TC solution
class ProductOfNumbers {
public:
    vector<int> nums;
    int n;
    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        int n = nums.size();
        
        for(int i = n-k; i < n; i++) {
            prod *= nums[i];
        }

        return prod;
    }
};
