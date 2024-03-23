// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".
// Example 2:

// Input: s = "axxxxyyyyb", part = "xy"
// Output: "ab"
// Explanation: The following operations are done:
// - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
// - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
// - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
// - s = "axyb", remove "xy" starting at index 1 so s = "ab".
// Now s has no occurrences of "xy".
class Solution {
public:
    void removeOccRE(string& s,string& part){
        int pos=s.find(part);
        if(pos!=string::npos){
            //part found and removing
            string left_part=s.substr(0,pos);//substr(starting index,length);
            string right_part=s.substr(pos+part.size(),s.size());
            s=left_part+right_part;
            removeOccRE(s,part);
        }else{
            return;
        }
    }
    string removeOccurrences(string s, string part) {
        removeOccRE(s,part);
        return s;
    }
};
Time Complexity:O(NM * N/M)//where N is length of string and m is the part of string
// find TC:O(NM)
// left and right part TC:O(N)
//and the recursion time Complexity:O(N/M)// in worst case the string containes only substring eg;ababab part=ab so it will have 6/2=3 i.e e substring
Space Complexity:O(N/M)
