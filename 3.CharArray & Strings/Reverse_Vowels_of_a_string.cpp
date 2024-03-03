// https://leetcode.com/problems/reverse-vowels-of-a-string/description/
// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
// Example 1:

// Input: s = "hello"
// Output: "holle"
// Example 2:

// Input: s = "leetcode"
// Output: "leotcede"
class Solution {
public:
    bool isvowel(char ch){
        ch=tolower(ch);
        return ch=='a'||ch=='o'||ch=='i'||ch=='e'||ch=='u';
    }
    string reverseVowels(string s) {
        int l=0;
        int h=s.length()-1;
        while(l<=h){
            if(isvowel(s[l])&&isvowel(s[h])){
                swap(s[l],s[h]);
                l++,h--;
            }else if(!isvowel(s[l])){
                l++;
            }else{
                h--;
            }
        }
        return s;
    }
};
