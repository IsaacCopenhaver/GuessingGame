#include "tree.h"
#include <iostream>
#include <fstream>

using namespace std;
int main(){
    ifstream read;
    read.open("AnimalTree.txt");
    string data;
    getline(read, data);
    read.close();
    tree* root = new tree(tree::deserialize(data));
    tree* useLater = root;
    string choice;
    do{
    cout << "Think of an animal, and then type start when you have one. Use y for yes and n for no.";
    cin >> choice;
    }while(choice!="start");
    do{
        if(choice == "y"){
            root = root->getRight();
        }else if(choice == "n"){
            root = root->getLeft();
        }
        cout << root->getData();
        cin >> choice;
    }while((root->getLeft() != NULL && root->getRight() != NULL) || (root->getRight() == NULL && choice == "y") || (root->getLeft() == NULL && choice == "n"));
    
    cout << choice;
    if(choice == "n"){
        cout << "What was your animal?";
        string animal;
        cin >> animal;
        cout << "What is a question to ask to identify the animal?";
        string question;
        tree* anotherTree;
        cin.ignore();
        getline(cin, question);
        anotherTree = new tree(question);
        root->setRight(anotherTree);
        root = root->getRight();
        tree* animalTree = new tree("Is your animal a " + animal + "?");
        root->setRight(animalTree);
        }
        else
        {
        cout << "Thanks for playing!";
        }
    data = root->serialize(useLater);

    ofstream write;
    write.open("AnimalTree.txt", ofstream::out | ofstream::trunc);
    write << data;
    write.close();
}
