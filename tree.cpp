#include "tree.h"
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
// Constructor
tree::tree(std::string _s) {
    s = _s;
    left = nullptr;
    right = nullptr;
}
tree::tree(tree* _node){
    s = _node->getData();
    left = _node->getLeft();
    right = _node->getRight();
}

// Getter for data
std::string tree::getData() {
    return s;
}

void tree::setData(std::string _s) {
    s = _s;
}

// Getter for left child
tree* tree::getLeft() {
    return left;
}

// Getter for right child
tree* tree::getRight() {
    return right;
}

std::string tree::serialize(tree *root)
{
if(!root){
    return "";
}        
        std::string s ="";
        std::queue<tree*> q;
        q.push(root);
        while(!q.empty()) {
           tree* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append((curNode->getData())+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;
}

tree *tree::deserialize(std::string data)
{
if(data.size() == 0){ 
return NULL;
}
        std::stringstream s(data);
        std::string str; 
        getline(s, str, ',');
        tree *root = new tree(str);
        std::queue<tree*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            tree *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#" || str.empty()) {
                node->left = NULL; 
            }
            else {
                tree* leftNode = new tree(str); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                tree* rightNode = new tree(str); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
}

// Setter for left child
void tree::setLeft(tree* _left) {
    left = _left;
}

// Setter for right child
void tree::setRight(tree* _right) {
    right = _right;
}
int tree::size(){
if(left && right){
    return 1 + left->size() + right->size();
}else if(left){
    return 1 + left->size();
}else if(right){
    return 1+ right -> size();
}
else{
    return 1;
}
}
