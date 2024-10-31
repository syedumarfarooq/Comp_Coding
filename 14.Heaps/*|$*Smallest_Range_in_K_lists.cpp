// if we take all elements a from from every k list and make a min and maximum range then all the number  of every row will lie
// in that range so we have to find that range and the minimum difference is the output
//in the end we have to get smallest range for making the minimum and maximum range smaller we have to either increase the minimum or decrease
//the maximum but as the question say non descending order if we go to next element(as linked list cannot go back)
//it increase and there is no chance of decreases or going back i.e  we are increasing the minimum that is why we are using min heap so that
// we can delete the minimum number and go further i.e next element to create range by adding the element from the same list u deleted earlier
