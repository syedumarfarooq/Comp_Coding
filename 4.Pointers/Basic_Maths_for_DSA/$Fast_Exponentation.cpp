//Fast exponentation
    //a^b 
    //if b is even=>(a^b/2)^2
    //if b is odd=>(a^b/2)^2.a
    // eg:2^5=>(2^4).2=>(2*2*2*2)*2
    int fastexponentation(int a,int b){
        int ans=1;
        while(b>0){
            if(b&1){//as odd numbers have 1 in the last bit and 1&1 is 1 
                ans*=a;
            }
            a=a*a;
            b>>=1;/
        }
        return ans;
    }
