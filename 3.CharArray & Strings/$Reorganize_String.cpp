// https://leetcode.com/problems/reorganize-string/description/
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

// Example 1:

// Input: s = "aab"
// Output: "aba"
// Example 2:

// Input: s = "aaab"
// Output: ""
// ----------CAN  BE SOLVED USING PRIORITY QUEUE----------------  
class Solution {
public:
    string reorganizeString(string s) {
        //1.place the most occurence char in non adjacent manner in one go that is go and then place the rest
        int hash[26]={0};
        for(int i=0;i<s.length();i++){
            hash[s[i]-'a']++;
        }
        //find the most occurent/frequent char
        char most_freq_char;
        int max_freq=INT_MIN;
        for(int i=0;i<26;i++){
            if(hash[i]>max_freq){
                max_freq=hash[i];
                most_freq_char=i+'a';
            }
        }
        //placing most occurent
        int index=0;
        while(max_freq>0 && index<s.size()){//index<size to place in one go
            s[index]=most_freq_char;
            max_freq--;
            index+=2;
        }
        if(max_freq!=0){
            return "";
        }

        hash[most_freq_char - 'a']=0;
        //if the code has reached here without returning " " then the most frequent char is placed so we have to update the value in hash
        //placing remaining character;
        for(int i=0;i<26;i++){
            while(hash[i]>0){
                index=index>=s.size() ? 1 : index;//if index more than size then wrap out to 1
                s[index]=i+'a';
                hash[i]--;
                index+=2;
            }
        }
        return s;

    }
};
