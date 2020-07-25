#pragma once
#include <stdbool.h>
#include <iostream>
#include <string>

using namespace std;
namespace family
{
    class Tree;
}
/**
 * This class Implemintation is inspired by Shiras work, as I found my desing very flawed
 * yet her work used no Node classes , and each family member is a sub tree of its own
 */
class family::Tree {
public:
    string _root;
    int _depth;
    Tree * _father,*_mother;

    // Tree Constructor//
        Tree(string name)
        {
        //cout << name << endl;//For debugging
            this->_root = name;
            this->_depth = 0;
            this->_mother = nullptr;
            this->_father = nullptr;
        }


        Tree& addFather(string child, string father);

        Tree& addMother(string child, string mother);

        string relation(string name);

        string find(string name);

        void display();

        void remove(string name);

     // Tree Destructor //
        ~Tree()
        {
            if( this->_father != nullptr)
                 delete this->_father;
            if( this->_mother != nullptr)
                 delete this->_mother;
        }

private:
    bool addFather(Tree *tree, string root, string father);
    bool addMother(Tree *tree, string root, string mother);
    void display(Tree *tree,string* myFamily,int depth);
    bool remove(Tree *root,string toRemove);
    string relation(Tree *tree,string name,int depth,int gender);
    string whatTheRelation(int depth,int gender);
    string find(Tree *tree,string relation,int depth,int gender);

};

