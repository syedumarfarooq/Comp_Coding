*//Tries
// It is a data structure which excist in a form  multi way tree(multiple children) it is mostly used in pattern search
// This pattern search thing using tries will give time complexity directly propotional to the pattern length so it is used
// Eg;umar,syed,love,lovely,car,care,caring
        //       Root 
        //   /  /  \   \
        // u   s   l    c
        // |   |    |    |
        // m   y   o    a
        // |   |    |    |
        // a   e    v    r        //marking r as termial node for car
        // |   |    |    | \
        // r   d    e    e  i     //marking r d and e as terminal node fro umar syed and care string
        //          |       |
        //          l       n
        //          |       |
        //          y       g     //marking y and g as terminal node for lovely and caring 
//-and generally tree can have only one parent
// -this is how multi way tree looks the root will create child if there staring index is different
//-to find out if a string is present or not with the help of terminal char, u can find out only if the terminal character is not 
        // present then there is no string only if there is a terminal char then that is a string
//if u want to delete a string u only delete the terminal character not the node for eg;if u want to delete car u just remove terminal
// character at r thats it
*//Insertion
#include <iostream>
using namespace std;


class TrieNode{
        public:
        char data;
        TrieNode* children[26];//26 as char range from a-z 
        bool isTerminal;

        TrieNode(char d) {
                this->data = d;
                for(int i=0; i<26 ; i++) {
                        children[i] = NULL;
                }
                this->isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word) {
   //base case
        //if the word length becomes 0 then mark the root as null
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //char is present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->children[index] = child;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
                return root->isTerminal;//if there is a string already present it will be marked as termianl 
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else{
                return false;
        }
        //rec call
        return searchWord(child, word.substr(1));

}
*//delete code was given as hw so self written 
void DeleteWord(TrieNode* root, string word) {
   //base case
        //if the word length becomes 0 then mark the root as null
        if(word.length() == 0) {
                if(root->isTerminal ){
                        root->isTerminal=false;//marking the terminal  character false 
                }
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //char is present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->children[index] = child;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}
int main() {
  TrieNode* root = new TrieNode('-');

  insertWord(root, "coding");
  insertWord(root, "code");
  insertWord(root, "coder");
  insertWord(root, "codehelp");
  insertWord(root, "baba");
  insertWord(root, "baby");
  insertWord(root, "babu");
  insertWord(root, "shona");
  cout << "Searching " << endl;
  if(searchWord(root,"cod")) {
          cout << "present" << endl;
  }
  else {
          cout << "absent" << endl;//=>false as no termainal character at d
  }

  return 0;
}

