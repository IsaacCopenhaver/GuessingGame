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
    tree* root = new tree("Think of an animal, and enter y when you have one. To answer a question type y for yes and n for no.");
    
    root->setRight(tree::deserialize(data));
    cout << root->getData();
    string choice;
    cin >> choice;
    do{
        cout << root->getData();
        cin >> choice;
        if(choice == "y"){
            root = root->getRight();
        }else if(choice == "n"){
            root = root->getLeft();
        }else{
            cout<< "You didn't enter a valid option";
        }
    }while(root->getLeft() != NULL && root->getRight() != NULL);
    if(choice == "n"){
        cout << "What was your animal?";
        string animal;
        cin >> animal;
        cout << "What is a question to ask to identify the animal?";
        string* question;
        cin >> *question;
        tree* anotherTree = new tree(*question);
        root->setRight(anotherTree);
        root =root->getRight();
        tree* animalTree = new tree("Is your animal a " + animal + "?");
        root->setRight(animalTree);
        }
    if(choice == "y")
    {
        cout << "Thanks for playing!";
    }
    data = root->serialize(root);
    ofstream write;
    write.open("AnimalTree.txt", ofstream::out | ofstream::trunc);
    write << data;
    write.close();
}
