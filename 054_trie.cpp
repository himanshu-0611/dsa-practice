#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*> children;
        bool isTerminal;

        TrieNode(char data) {
            this->data = data;
            isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word) {
    if(word.length() == 0) {
        root->isTerminal = 1;
        return;
    }
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    } else {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }

    insertWord(child, word.substr(1));
}

void storeSuggestions(TrieNode* root, vector<string>& output, string prefix) {
    //ans store terminal node ke case me krna tha
    if(root->isTerminal) {
        output.push_back(prefix);
    }
    
    //current node se har jaga move krna h
    // i.first = ch
    // i.second = address of node
    for(auto i : root->children) {124
        char ch = i.first;
        TrieNode* next = i.second;
        if(next != NULL) {
            prefix.push_back(ch);
            storeSuggestions(next, output, prefix);
            //backtrack
            prefix.pop_back();
        }
    }
}

vector<string> getSuggestions(TrieNode* root, string prefix) {
    //travel prfix tak
    // dummy root ke niche jitne bhi stirng h
    // un sabhi ko leke aate the
    // merge krke ans create krte the

    //travel the trie using prefix and give the dummy node
    for(int i=0; i<prefix.length(); i++) {
        char ch = prefix[i];
        root = root->children[ch];
    }

    if(root == NULL) {
        cout << "there is no answer";
        return {};
    }
    //jab me iss loop se bahar aunga toh mera root
    //ban chuka h as per prefix
    //ab mujhe dummy root ke under jitni bhi string possble h unko create krna h
    vector<string> temp;
    storeSuggestions(root, temp, prefix);
    return temp;
}

int main() {
    vector<string> arr;
    arr.push_back("love");
    arr.push_back("lover");
    arr.push_back("loving");
    arr.push_back("lost");
    arr.push_back("lane");
    arr.push_back("lord");
    string input = "lanee";
    TrieNode* root = new TrieNode('-');

    for(int i=0; i<arr.size(); i++) {
        insertWord(root, arr[i]);
    }

    vector<string> ans = getSuggestions(root, input);

    cout << "printing ans: " << endl;

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;;
    }
}