//Find prime array in the given range is we use normal method we might have to create from 2 to r where r can go up to 10^9
//Question a range is given L and R which can start from 0-10^9 so u cannot practically create a array of size 10^9 so we create an array of range R-L so that it can be created 
// vector<bool> sieve(int n) {
//         if(n==0||n==1) return 0;
//         vector<bool> prime(n,true);
//         prime[0]=prime[1]=false;
//         for(int i=2;i*i<=n;i++){
//             if(prime[i]==true){
//                 int j=i*i;
//                 while(j<n){
//                     prime[j]=false;
//                     j=j+i;
//                 }
//             }
//         }
//         return prime;
//     }
vector<bool> segSieve(int L,int R){//segment Sieve block
  //first get a base prime array which are used as initial prime eg:for 25 the base primes are 2,3,5 i.e primes √n after this they are marked false based on the multiples of these primes and also this can be proved from above sieve tabel for finding primes it starts from i*i so before than are all base primes
    vector<bool>sieve =sieve(sqrt(R));
    vector<int>basePrimes;
    for(int i=0;i<sieve.size();i++){
        if(sieve[i]){
          basePrimes.push_back(i);//this contains all the base primes
        }
    }
   vector<bool>segSieve(R-L+1,true);
  if(L==0||L==1){
    segSieve[L]=false;
  }
  for(auto prime:basePrimes){
    int firstmul=(L/prime)*prime;//this formula gives u the first multiple of the prime within the range for exxample 110 is first multiple of 2 in range
    if(firstmul<L){
      firstmul+=prime//if first mul is less than l from previous formula then add prime for example (110/3)*3=36.6*3=36*3=108 so 3 is added to make it 111
        }
    int j=max(firstmul,prime*prime);//we do this to start marking prime as false so we start from first multiple or the i*i ,method from sieve method which is showed in count primes ,if the firstmul is less than means it can be marked by other previous multiples so we can start from i*i
    while(j<R){
      segSieve[j-L]=false;
      j+=prime;
    }
  }
  return segsieve;
}

