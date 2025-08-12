#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_map>
#include<algorithm>
using namespace std;

class TrieNode{
    public:
        char ch;
        unordered_map<char, TrieNode*> children;
        int childCount;
        bool isTerminal;

        TrieNode(char ch) {
            this->ch = ch;
            isTerminal = false;
            childCount = 0;
        }
};

void insertWord(TrieNode* root, string word) {

    if(word.size() == 0) {
        root->isTerminal = true;
        return;
    }
    
    TrieNode* child; //created the pointer of TrieNode type
    char ch = word[0]; //character to insert

    if(root->children.find(ch) != root->children.end()) {
        //present - we just udpate the child pointer for next recursive call
        child = root->children[ch];
        root->childCount++;
    } else {
        //absent - we assign TrieNode DS to child and point root to it
        child = new TrieNode(ch);
        root->children[ch] = child;
    }

    insertWord(child, word.substr(1));
}

vector<string> completeSuggestions(TrieNode* root, string str) {
    for(auto it : root->children) {
        if(it.second != NULL) {
            str.push_back(root->ch);
            completeSuggestions(root->children[it.first]);
        }
    }
}

vector<string> getSuggestions(TrieNode* root, string input) {
    //iterate the input until childCount is 1
    //when childCount > 1 we pass the root to completeSuggestions
    // completeSuggestions will return us will return vector<string> will return all the completed strings

    for(int i=0; i<input.size(); i++) {
        if(root->childCount > 1) {
            vector<int> compSugg = completeSuggestions(root);
        }
    }

    for(int i=0; i<compSugg.size(); i++) {
        int string = input + compSugg;
        ans.push_back(string);
    }

    return ans;
}

int main() {
    vector<int> database;;
    database.push_back("lover");
    database.push_back("love");
    database.push_back("loving");
    database.push_back("lord");
    database.push_back("lane");
    database.push_back("lake");
    database.push_back("lucid");

    string input = "lov"

    TrieNode* root = new TrieNode('-');

    for(int i=0; i<database.size(); i++) {
        insertWord(root, database[i]);
    }

    vector<string> ans = getSuggestions(root, input);

    cout << "Printing Suggestions: " << endl;
    
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}