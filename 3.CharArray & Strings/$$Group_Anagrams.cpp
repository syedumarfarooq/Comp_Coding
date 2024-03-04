// https://leetcode.com/problems/group-anagrams/description/
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]//N=6 and k=3
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]
// By sorting and that into a map
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         map<string,vector<string>> mp;
//         for(auto str:strs){
//             string s=str;
//             sort(s.begin(),s.end());//O(klogK) for sorting and k is the length of largest string
//             mp[s].push_back(str);
//         }
//         vector<vector<string>> ans;
//         for(auto i=mp.begin();i!=mp.end();i++){
//             ans.push_back(i->second);//->second is used to access values of the map
//         }
//         return ans;
//     }
// };
// Time complexity:O(Nklogk)
// Space complexity:O(NK);
// By using hashing where char are marked 1 in the array and then that hash is mapped this reducing the complexity by not sorting
class Solution {
public:
    std::array<int, 256> hashing(string s){//this returns a array of type int of size 256 just a way of returning array
        std::array<int,256>hash={0};
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int,256>,vector<string>> mp;//std::array<int,256> it is creating an array of 256 just another way of writing
        for(auto str:strs){
           mp[hashing(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto i=mp.begin();i!=mp.end();i++){
            ans.push_back(i->second);//->second is used to access values of the map
        }
        return ans;
    }
};
//TimeComplexity:O(NK)
//SpaceComplexity:O(NK)
