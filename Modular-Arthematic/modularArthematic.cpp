// (a+b)%M=((a%M)+(b%M))%M
// (a*b)%M=((a%M)*(b%M))%M
// (a-b)%M=((a%M)-(b%M)+M)%M
// (a/b)%M=((a%M)*((b^-1)%M))%M,(b^-1)=b^M-2 fermat’s little theorem
// let,modular inverse of b and M=p;
// then (b*p)%M=1, this brute force approach to find p(mod inverse) which is the b^-1 but b^-1)=b^M-2 fermat’s little theorem helps to find 
// the p without brute force


// why 1e9+7
// 1.this number is very close to int max capacity,u may have one more doubt that there are more prime number( 2.why prime number bcz in division
// of modolo it helps)which come under the range of int greater than this, bcz  we have the value in mind of int is arount 10^9 so we go with it

// why prime number
// (b*p)%M=1, in this we need to find p which will give us 1 as result but when b is even b and p will be even and if M is also even u wont get 1
// in any caseso we take prime number so that we have no common divisor
// We use a prime number for the modulus M because we need to find a modular inverse p such that (b * p) % M = 1. For this inverse to exist, b and M
// must have no common divisor other than 1 (their GCD must be 1). If they have a common divisor greater than 1, finding such a p may be impossible. 
//   For example, if b = 4 and M = 10, both are divisible by 2, so multiplying 4 by any integer will never give a remainder of 1 when divided by 10.
//   By choosing a prime number for M, we guarantee that every number from 1 to M-1 has no common divisor with M other than 1. Therefore, every such 
// number has a modular inverse. For example, let b = 6 and M = 9. We need to find p such that (6 * p) % 9 = 1. However, if we try different values 
// of p, the remainders will keep repeating as 6, 3, 0, and we will never get 1. This happens because 6 and 9 have a common divisor, 3 (GCD = 3). 
//   Since both numbers are divisible by 3, multiplying 6 by any integer will always produce a multiple of 3, so its remainder when divided by 9 can 
// never be 1. Therefore, the modular inverse of 6 modulo 9 does not exist.Whenever we divide a number, we can write it as
// Number = (Divisor × Quotient) + Remainder. For example, 30 = (9 × 3) + 3. Now, if the original number is a multiple of 3 and the divisor is 
// also a multiple of 3 (like 9), then both the original number and the divisor multiplied by the quotient are divisible by 3. Therefore, 
//   their difference (the remainder) must also be divisible by 3. That's why when we divide multiples of 3 by 9, the remainder can only be 
// 0, 3, or 6, never 1.
