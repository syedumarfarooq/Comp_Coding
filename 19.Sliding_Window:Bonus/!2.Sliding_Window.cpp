*//as person in chat asked about system design LB told about System design primer (he mentioned it is in github)
topics he told
  cache,proxy,reverse proxy,design patterns in low level design, ngin x,loader balancer ,server,scaling ,horizontal scaling,vertical scaling
schema creation ,how to set keyys,hash key ,partion key,nosql vs sql
*//Question 4:Smallest window containing all characters of another string
https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/0
// Given two strings s1 and s2. Find the smallest window in the string s1 consisting of all the characters(including duplicates) of the string s2. Return "" in case no such window is present. If there are multiple such windows of the same length, return the one with the least starting index.
// Note: All characters are in lowercase letters. 
// Examples:
// Input: s1 = "timetopractice", s2 = "toc"
// Output: "toprac"
// Explanation: "toprac" is the smallest substring in which "toc" can be found.
*//logic
//   in this we are first creating a window from the start to a point which has all the characters of s2 then we try to minimise the length
// of the window by checking every char of s1 
// we are keeping track of chars by using unordered_map <char,int> 
  //eg: s:ttooccto ,p:tocwe first create a window for tooc we store the answer for tooc
              //then we keep on increasing the window  and the start is at t(s[1]) and another c and then t 
  //when the 6th index t is added the frequency is increased and p requires only 1 so in while loop it moves the start forward
  //then it will add another o index 7 and and it will enter the while and it will remove one 'o' index 2 at the start then the second 'o'
  //is also removed as frequecy was more and start is  incremented then remove one c, increment start and stop at last cto and store the answer

  
  *//code
  class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        int len1 = s.length();
        int len2 = p.length();
        int start = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;
        
        if(len1 < len2) {
            return "";
        }
        
        unordered_map<char, int> strMap;
        unordered_map<char, int> patMap;
        //to keep track of all characters of P string
        for(int i=0; i<p.length(); i++) {//marking all the characters of p and their frequency
            char ch = p[i];
            patMap[ch]++;
        }
        
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            
            strMap[ch]++;//adding freq for s string
            
            //if the current char is also a character in p then we increment the count
            if(strMap[ch] <= patMap[ch] ) {
                count++;//if we match a character which are in both string then we add cound
            }
            
            if(count == len2) {//check if all the character in p are present in the window , by checking the count as we increment the count
              //only if we find same character 
                
                //window is readyv
                //minimise the window -> freq decrement, ans update , start ko aage badhana h 
                
                while(strMap[s[start]] > patMap[s[start]] ||patMap[s[start]] == 0 ) {
                  //we start from 0 i.e the starting point of the window
                    //if start character freq in s is more than p then we can skip that character (minimize the window)and 
                    //decrease the frequency of it or if the start character is not present in p
                    //then in both case we increment start i.e we minimize the window as we want minimum window size
                    if(strMap[s[start]] > patMap[s[start]])//decrement only if the freq is higher
                        strMap[s[start]]--;
                        
                    start++;
                }//this will end at a point where we find a character in s if removed then it will not match all the character in p 
              //this is the least the window can be minimised 
                
                //ans update; we have found the window which has all the character of p in s
                //so we save the answer and check further by adding the next character 
              //we keep on increasing the window and also minimize
              
                int lengthOfWindow = i - start + 1;
                if(lengthOfWindow < ansLen ) {
                    ansLen = lengthOfWindow;
                    ansIndex = start;
                }
                
                
            }
        }
        
        if(ansIndex == -1)
            return "";
        else
            return s.substr(ansIndex, ansLen);
    }
};

