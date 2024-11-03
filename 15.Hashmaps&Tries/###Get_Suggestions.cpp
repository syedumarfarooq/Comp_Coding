// get all the possible suggestions for the given input
//eg:["lover","love","loving","lane","last","lost","lord"] input-"lovi"
// =>[["lover","love","loving","lane","last","lost","lord"], //for l suggestion
//   ["lover","love","loving","lost","lord"],                //for lo suggestion
//   ["lover","love","loving"],                              //for lov suggestion
//   ["loving"]]                                             //for lovi suggestion
#include <iostream>
#include<vector>
using namespace std;


class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;//this is just a marker to show a end of one word explained in detail in tries

        TrieNode(char d) {
                this->data = d;
                for(int i=0; i<26 ; i++) {
                        children[i] = NULL;
                }
                this->isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word) {
        //cout << "Inserting " << word << endl;
   //base case
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //present
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


void storeSuggestions(TrieNode* curr, vector<string>& temp, string &prefix) {
	if(curr -> isTerminal)//if we find terminal store word
	{
		temp.push_back(prefix);//not returning because there can be a word with this prefix if there are two words love and lovely
		//if we return at love then we will not be able access lovely
	}

	//a to z tak choices dedo
        //if there is a word present then 
	for(char ch ='a'; ch<='z'; ch++) {
		int index = ch-'a';

		TrieNode* next = curr->children[index];

		if(next != NULL) {
			//if child exists
			prefix.push_back(ch);
			storeSuggestions(next, temp, prefix);
			prefix.pop_back();
		}
	}
	
}

vector<vector<string> > getSuggestions(TrieNode* root, string input) {

	//var/DS
	TrieNode* prev = root;
	vector<vector<string> > output;
	string prefix="";
	
	for(int i=0; i<input.length(); i++) {
		char lastch = input[i];

		int index = lastch - 'a';
		TrieNode* curr = prev->children[index];

		if(curr == NULL)
			break;
		else {
			//iske andar main saare suggestion store krke launga
			vector<string> temp;
			prefix.push_back(lastch);
			storeSuggestions(curr, temp, prefix);
			output.push_back(temp);
			prev = curr;//i may forget
		}
	}
	return output;
}






int main() {
	vector<string> v;
	v.push_back("love");
	v.push_back("lover");
	v.push_back("loving");
	v.push_back("last");
	v.push_back("lost");
	v.push_back("lane");
	v.push_back("lord");

	string input = "lovi";

	TrieNode* root = new TrieNode('-');
	for(int i=0; i<v.size(); i++) {
		insertWord(root, v[i]);
	}

	vector<vector<string> > ans  = getSuggestions(root, input);

	cout << "Printing the answer: " << endl;

	for(int i=0; i<ans.size(); i++) {

		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j]<<", ";
		}
		cout << endl;
	}




	
 

  return 0;
}
  
