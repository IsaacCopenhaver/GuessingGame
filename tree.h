#ifndef TREE_H
#define TREE_H
#include <string>

class tree{
    private:
        tree* left;
        tree* right;
        std::string s;
    public:
        tree(std::string _s);
        tree(tree* _node);
        void setData(std::string _s);
        std::string getData();
        tree* getLeft();
        tree* getRight();
        std::string serialize(tree *root);
        static tree* deserialize(std::string data);
        void setLeft(tree* _left);
        void setRight(tree* _right);
        int size();
};
#endif