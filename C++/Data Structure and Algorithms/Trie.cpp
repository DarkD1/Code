#include <bits/stdc++.h>
using namespace std;

struct trieNode{
    int terminating;
    struct trieNode *trieNodes[26];
};

struct trieNode *getNode(){
    struct trieNode * parent = new trieNode;
    parent->terminating = 0;
    for(int i = 0; i < 26; i++){
        parent->trieNodes[i] = NULL;
    }
    return parent;
}

void insertNode(struct trieNode *root, string s){
    struct trieNode * current = root;
    for(int i = 0; i < s.length(); i++){
        int idx = s[i] - 'a';
        if(current->trieNodes[idx] == NULL){
            current->trieNodes[idx] = getNode();
        }
        current = current->trieNodes[idx];
    }
    current->terminating++;
}
int query(struct trieNode *root, string s){
    struct trieNode *current = root;
    for(int i = 0; i < s.length(); i++){
        int idx = s[i] - 'a';
        if(current->trieNodes[idx] == NULL){
            return 0;
        }
        current = current->trieNodes[idx];
    }
    return current->terminating;
}
void deleteNode(struct trieNode *root, string s){
    struct trieNode * current = root;
    for(int i = 0; i < s.length(); i++){
        int idx = s[i] - 'a';
        if(current->trieNodes[idx] == NULL){
            assert(false);
        }
        current = current->trieNodes[idx];
    }
    if(current->terminating != 0){
        current->terminating--;
    }
    else{
        assert(false);
    }
}
void del(node* cur){
    for (int i = 0; i < 26; i++)
        if (cur->trieNodes[i])
            del(cur->trieNodes[i]);

    delete (cur);
}
void updateNode(struct trieNode* root, string oldString, string newString){
    deleteNode(root, oldString);
    insertNode(root, newString);
}
int main(){
    vector<string> keys = {"sazzad", "hossain", "shopno"};
    struct trieNode * root = getNode();
    for(string key: keys){
        insertNode(root, key);
    }
    insertNode(root, "sazzad");
    cout << query(root, "sazzad") << endl;
    deleteNode(root, "sazzad");
    cout << query(root, "sazzad") << endl;
    updateNode(root, "sazzad", "hossain");
    cout << query(root, "hossain");
    return 0;
}
