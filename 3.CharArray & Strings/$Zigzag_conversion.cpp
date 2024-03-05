// https://leetcode.com/problems/zigzag-conversion/description/
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> zigzag(numRows);
        int row=0,i=0;
        bool direction=1;
        if(numRows==1)return s;
        while(true){
            if(direction){
                while(row<numRows&&i<s.size()){
                    zigzag[row++].push_back(s[i++]);
                }
                row=numRows-2;//as the row might have gone more than numRows so we have to start from -2
            }
            else{
                while(row>=0&&i<s.size()){
                    zigzag[row--].push_back(s[i++]);
                }
                row=1;
            }
            if(i>=s.size())break;
            direction=!direction;

        }
        string ans="";
        for(int i=0;i<zigzag.size();i++){
            ans+=zigzag[i];
        }
        return ans;
    }
};
