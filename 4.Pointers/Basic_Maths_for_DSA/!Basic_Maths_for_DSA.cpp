//LCM
    // Formula:lcm(a,b)*gcd(a,b)=a*b
    // LCM(a,b)=a*b/GCD(a,b) 
    // gcd code is written in another file
//Modulo arithmetic
    // Generally, to avoid overflow while storing Integer we do modulo with a Large number.
    // 1. (a + b) % M=a % M+ % M
    // 2. a % M - b% M= (a - b) %M
    // 3. ((а % М) % М) % М= a % М
    // 4. а % M*b% M=(a*b) %M
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
            b>>=1;
        }
        return ans;
    }
