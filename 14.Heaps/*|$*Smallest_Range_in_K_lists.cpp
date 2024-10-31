// if we take all elements a from from every k list and make a min and maximum range then all the number  of every row will lie
// in that range so we have to find that range and the minimum difference is the output
//in the end we have to get smallest range for making the minimum and maximum range smaller we have to either increase the minimum or decrease
//the maximum but as the question say non descending order if we go to next element(as linked list cannot go back)
//it increase and there is no chance of decreasing or going back i.e  we are increasing the minimum that is why we are using min heap so that
// we can delete the minimum number and go further(as the number increases)to create new range which keeps on decreasing the range what if we
// chosse max heap this will update min as we go then the range would keep increasing as the maximum will keep increasing through out the list
//as it is non decreasing order but we want minimum range so that we why we use minimum number and keep on increasing in
