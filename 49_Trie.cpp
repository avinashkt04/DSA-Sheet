#include<iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word) {
            // base case
            if(word.length() == 0){
                root->isTerminal = true;
                return ;
            }

            // assumption, word will be in CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            // present
            if(root->children[index] != NULL) {
                child = root->children[index];
            } else {
                // absent
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            // RECURSION
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }

        bool searchWordUtil(TrieNode* root, string word){
            // base case
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // present
            if(root->children[index] != NULL){
                child = root->children[index];
            } else {
                return false;
            }

            // RECURSION
            return searchWordUtil(child, word.substr(1));
        }

        bool searchWord(string word) {
            return searchWordUtil(root, word);
        }

        void deleteWordUtil(TrieNode* root, string word){
            if(word.length() == 0) {
                root->isTerminal = false;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL) {
                child = root->children[index];
            } else {
                return;
            }

            deleteWordUtil(child, word.substr(1));
        }

        void deleteWord(string word) {
            deleteWordUtil(root, word);
        }
};

int main() {
    Trie *t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout << "Present or Not " << t->searchWord("TIME") << endl;

    cout << "Present or Not " << t->searchWord("DO") << endl;
    t->deleteWord("DO");
    cout << "Present or Not " << t->searchWord("DO") << endl;

    return 0;
}