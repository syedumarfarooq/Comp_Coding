https://leetcode.com/problems/longest-happy-string/description/
// A string s is called happy if it satisfies the following conditions:

// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.
class node {
    public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

class compare {
    public:
    bool operator()(node a, node b) {
        return a.count < b.count;
    }
};


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<node, vector<node>, compare> maxHeap;

        if(a > 0) {
            node temp('a', a);
            maxHeap.push(temp);
        }

        if(b > 0) {
            node temp('b', b);
            maxHeap.push(temp);
        }


        if(c > 0) {
            node temp('c', c);
            maxHeap.push(temp);
        }

        string ans = "";

        while(maxHeap.size() > 1) {
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();

            if(first.count >= 2) {
                ans += first.data;
                ans += first.data;
                first.count -= 2;
            }
            else {
                ans += first.data;
                first.count--;
            }
          *//second condition if there are perfect number of first then only we can add 2 second or else once
            // eg:b-8 c-11 without the second condition we would place it ccbbccbbccbbccbbccc which is incorrect i.e three ccc at the end
            //if we place it ccbccbbccbbccbbccbc
            if(second.count >= 2 && second.count >= first.count) {
                ans += second.data;
                ans += second.data;
                second.count -= 2;
            }
            else {
                ans += second.data;
                second.count--;
            }

            if(first.count > 0) {
                maxHeap.push(first);
            }

            if(second.count > 0) {
                maxHeap.push(second);
            }
        }

        if(maxHeap.size() == 1) {
            node temp = maxHeap.top();
            maxHeap.pop();

            if(temp.count >= 2) {
                ans += temp.data;
                ans += temp.data;
                temp.count -= 2;
            }
            else {
                ans += temp.data;
                temp.count--;
            }

        }
        return ans;
    }
};
















