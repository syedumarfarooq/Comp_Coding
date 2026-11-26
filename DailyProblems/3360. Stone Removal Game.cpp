*//my sol 
class Solution {
public:
    bool canAliceWin(int n) {
        int count=10;
        bool flag=false;
        while(n!=0){
            if(count%2==0){
            if(count>n){
                return false;
            }else{
                flag=true;
                n-=count;
                count--;
            }
            
        }else{
            if(count>n){
                return true;
            }
            else{
                flag=false;
                n-=count;
                count--;
            }
        }
        }
        if(flag) return true;
        return false;
    }
};
*//*******************f\author
class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int steps = 0;

        while (n >= take) {
            n -= take;
            take--;
            steps++;
        }

        return steps % 2 == 1;
    }
};
