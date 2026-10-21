this question has n going up until 10^5 so our tice complexity should be around o(n) to O(nlogn)
This Question is solved in 3 steps
  1.find all the divisor which is divisible by n (it takes O(√n) time complexity as we check for 1 to k*k<=n)
  2.we are checking we a sub array can be sorted after rotating by placing the same subarray twice if we find a sorted subarray in that 2 subarray whose size is >=k then we can say it is sorted if rotated eg: 675, 675675 in this the 567 is sorted so this is possible
  3.then to check if all the subarray are sorted after the step 2 we take two subarray and save both min and max of the subarray if the max of 1st subarray is less than min of 2nd subarray then it is sorted
