#include<iostream>
using namespace std;
struct TrieNode
{
    TrieNode*  children[26];
    bool isTerminal; 
};
TrieNode* create(){
    TrieNode* result = new TrieNode;
    for (int i = 0; i < 26; i++)
    {
        result -> children[i] = NULL;
    }
    result -> isTerminal = false;
    return result;
}
void insert(TrieNode* root, string key){
    // insert node if not exist
    TrieNode* temp = root;
    for (size_t i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(!temp -> children[index]){
            temp -> children[index] = create();
        }
        temp = temp -> children[index];
    }
    temp -> isTerminal = true;
}

bool search(TrieNode* root, string key){
    // traverse trough the trie until children not found, and check if isTerminal for last char
    TrieNode* temp = root;
    for (size_t i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(temp -> children[index]){
            temp = temp -> children[index];
        }else{
            return false;
        }
    }
    return temp && temp->isTerminal;
}
void destroy(TrieNode* root){
    // recursively delete all children existed, and then delete the root   
    for (int i = 0; i < 26; i++)
    {
        if (root -> children[i])
        {
            destroy(root -> children[i]);
        }
        
    }
    delete(root);
}



int main(){

    string keys[] = {"trie", "there", 
                    "three", "apple", "app", 
                     "apples", "bananas" }; 
    int n = 7; 
  
    struct TrieNode *root = create(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    if(search(root, "trie")){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
                        
    if(search(root, "hello")){
        cout << "Yes\n";
    }else{
        cout << "No\n"; 
    }   
    destroy(root);
    return 0; 

}