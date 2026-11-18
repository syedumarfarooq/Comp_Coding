*//HINT: the subarray size(number of partition) does not matter as   taking 2-2 size  will give u the  right answer
   // as the question only says find the changes in even length so partitioning it into size of 2 will gie the same answer, if the question had 
   // asked to keep the length of the subarray maximum(the more the 
   // length of subarray the better) and minimum changes
   //to make it beautiful then we should consider size of 4,6,8 
*//my solutions dp not needed as the constraint is long so tle will occur
    *//recursion
class Solution {
public:
    string st;
    int n;
    int Cost(int i,int j){
        int len=j-i+1;
        int zerocount=0;
        int cost=0;
        for(int start=i;start<=j;start++){
            if(st[start]=='0'){
                zerocount++;
            }
        }
        if(zerocount<=len/2){
            //one domination or equal;
            cost+=zerocount;
        }else{
            cost+=(len-zerocount);
        }
        return cost;
    }
    int solve(int start){
        if(start>n){
            return INT_MAX;
        }
        if(start==n){
            return 0;
        }

        int result=INT_MAX;
        for(int end=start+1;end<n;end+=2){
            int remainCost=solve(end+1);
            if(remainCost==INT_MAX)continue;
             result=min(result,remainCost+Cost(start,end));
        }
        return result;
    }
    int minChanges(string s) {
        st=s;
        n=s.length();
        return solve(0);
    }
};


//Buttom up still tle
*//***************************************************************''
  // ***************************************************************
  
*//***************************************************************''
  // ***************************************************************
*//***************************************************************''
  // ***************************************************************
class Solution {
public:
    string st;
    int n;
    vector<int> mem;
    vector<vector<int>> costmem;
    int Cost(int i,int j){
        // if(costmem[i][j]!=-1)return costmem[i][j];
        int len=j-i+1;
        int zerocount=0;
        int cost=0;
        for(int start=i;start<=j;start++){
            if(st[start]=='0'){
                zerocount++;
            }
        }
        if(zerocount<=len/2){
            //one domination or equal;
            cost+=zerocount;
        }else{
            cost+=(len-zerocount);
        }
        return costmem[i][j]=cost;
    }
    
    int minChanges(string s) {
        st=s;
        n=s.length();
        costmem.assign(n+1, vector<int>(n+1, -1)); //n*n
        mem.assign(n+1,INT_MAX);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                costmem[i][j]=Cost(i,j);
            }
        }
        
        mem[n]=0;
        for(int start=n;start>=0;start-=2){

            int result=INT_MAX;

            if(start>=n)continue;
            for(int end=start+1;end<n;end+=2){
            int remainCost=mem[end+1];
            if(remainCost==INT_MAX)continue;
             result=min(result,remainCost+costmem[start][end]);

        }
        mem[start]=result;
        }
        
        return mem[0];
    }
};

*//using traversing of array mY solution
class Solution {
public:
    int minChanges(string s) {
        int currchar=-1;
        int change=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(currchar!=-1&&s[i]!=s[currchar]){

                if((count+1)%2==0){
                    change++;
                    count++;
                    continue;
                }
                
                if(count%2==0 ){
                    currchar=-1;
                    count=0;
                }
            }
           
            if(currchar!=-1 &&s[i]==s[currchar]){
                count++;
            }
            if(currchar==-1){
                currchar=i;

                count++;
            }
            
        }
        return change;
    }
};
*//second approach even more simpler
class Solution {
public:
    int minChanges(string s) {
        int count=1;
        int change=0;
        for(int i=1;i<s.length();i++){
            if((i+1)%2==0){
                if(s[i]!=s[i-1]){
                    change++;
                }
            }
        }
        return change;
    }
};

*// author answer
/**************************************************************** C++ ****************************************************************/
//Approach-1 (Simple iterate and count and keep track)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minChanges(string s) {
        char curr = s[0];

        int count = 0;
        int changes = 0;
        int n = s.length();

        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {

            if (s[i] == curr) {
                count++;
                continue;
            }

            if (count % 2 == 0) { //Even
                count = 1;
            } else { //Odd
                count = 0;
                changes++;
            }
            
            curr = s[i];
        }

        return changes;
    }
};


//Approach-2 (Simple iterate and count and keep track)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        int n = s.length();

        for (int i = 0; i < n; i += 2) {

            if (s[i] != s[i + 1]) {
                changes++;
            }
        }

        return changes;
    }
};

