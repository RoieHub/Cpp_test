//
// Created by roie on 21/04/2020.
//
/**
 * This node class named "Fnode"(family node)  is desined for easy working with the Tree class.
 * Every Fnode containes a UNIQE id , that is used for many Algorithems in the Tree class.
 * Also containing a name of the relative, this names is used to store the Fnode in a map of the Tree class.
 * And also two pointers of Fnode , which point at mother and father of this node.
 */

#pragma once
#include <cstddef>
#include <stdbool.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Fnode{
public: // all method and mombers are public for easy acsess in my first CPP class.
    Fnode* _father;
    Fnode* _mother;
    string _name;
    int _id;
    /////Constructors/////
    // Default constructor , may be usefull?
    Fnode()
    {
        _father = NULL;
        _mother = NULL;
        _name = "Empty Root Constructor";
        _id = 1;

    }
    // This constructor is used to init the root of the Tree class.
    Fnode(string Name)
    {
        this->_name=Name;
        this->_father=NULL;
        this->_mother=NULL;
        this->_id = 1; // Uniqe ID for root
    }
    Fnode(string Name,int id) // This constructor is used to build
    {
        this->_name=Name;
        this->_father=NULL;
        this->_mother=NULL;
        this->_id = id;
    }
    //string to_string();
    bool setFather(Fnode* Father);
    string myFather();
    int getID();


    bool setMother(Fnode*  mother);
    //Fnode * getFather();
    // Fnode * getMother();
   // string getName();
    //int getId();
};
