https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m, where both arrays may contain duplicate elements. The task is to determine whether array a2 is a subset of array a1. It's important to note that both arrays can be sorted or unsorted. Additionally, each occurrence of a duplicate element within an array is considered as a separate element of the set.

// Example 1:

// Input:
// a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
// a2[] = {11, 3, 7, 1, 7}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]

// Example 2:

// Input:
// a1[] = {1, 2, 3, 4, 4, 5, 6}
// a2[] = {1, 2, 4}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>map;
    string ans="Yes";
    //map hashing using a1
    for(int i=0;i<n;i++){
        map[a1[i]]++;
    }
    //check whether all elements of a2 are present in a1
    for(int i=0;i<m;i++){
        if(map.find(a2[i])==map.end()){
            ans="No";
            break;
        }else{
            //present
            if(map[a2[i]]>0){
                map[a2[i]]--;
            }else{
                ans="No";
                break;
            }
        }
    }
    return ans;
}
