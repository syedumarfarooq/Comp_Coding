class Solution {
public:
    vector<vector<int>> mem;
    int solve(int n,vector<vector<int>>& items, int budget,vector<int> &counts,int minP){
        if(n==0)return budget/minP;
        if(mem[n][budget]!=-1){
            return mem[n][budget];
        }
        int take=0;
        int price=items[n-1][1];
        if(price<=budget){
            take=1+counts[n-1]+solve(n-1,items,budget-price,counts,minP);
        }
        int skip=solve(n-1,items,budget,counts,minP);
        return mem[n][budget]=max(skip,take);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        mem.assign(items.size()+1,vector<int>(budget+1,-1));
        int minPrice=INT_MAX;
        vector<int> counts(items.size(),0);
        for(int i=0;i<items.size();i++){
            int count=0;
            minPrice=min(minPrice,items[i][1]);
            for(int j=0;j<items.size();j++){
                if(i==j)continue;
                if(items[j][0]%items[i][0]==0){
                    count++;
                }

            }
            counts[i]=count;
        }
        int n=items.size();
        int ans=solve(n,items,budget,counts,minPrice);
        return ans;
    }
};


*////bottom up
class Solution {
public:
    vector<vector<int>> mem;
   
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        mem.assign(items.size()+1,vector<int>(budget+1,-1));
        int minPrice=INT_MAX;
        vector<int> counts(items.size(),0);
        for(int i=0;i<items.size();i++){
            int count=0;
            minPrice=min(minPrice,items[i][1]);
            for(int j=0;j<items.size();j++){
                if(i==j)continue;
                if(items[j][0]%items[i][0]==0){
                    count++;
                }

            }
            counts[i]=count;
        }
        int n=items.size();

        for(int j=0;j<=budget;j++){
            mem[0][j]=j/minPrice;
        }
        for(int i=1;i<=items.size();i++){
            for(int j=0;j<=budget;j++){
                int take=0;
                int price=items[i-1][1];
                if(price<=j){
                    take=1+counts[i-1]+mem[i-1][j-price];
                }
                int skip=mem[i-1][j];
                mem[i][j]=max(take,skip);
            }

        }
        return mem[items.size()][budget];
    }
};
