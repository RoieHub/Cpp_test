//
// Created by roie on 21/04/2020.
//
#include "Fnode.hpp"

bool Fnode::setFather(Fnode* Father)
{
    if(this->_father == NULL) {
        this->_father = Father;
        return true;
    }
    else
    {
        cout<< "I allready have a father and its not you!" << endl;
        return false;
    }

}

bool Fnode::setMother(Fnode* Mother)
{
    if(this->_mother == NULL) {
        this->_mother = Mother;
        return true;
    }
    else
    {
        cout<< "I allready have a mother and its not you!" << endl;
        return false;
    }
}

int Fnode::getID()
{
    return this->_id;
}
/*string Fnode::to_string()
{
    string ans;
    ans << "I am:"<this->_name<"\nMy Id is :"<this->_id<endl;
    return ans;
}*/
string Fnode::myFather() {return this->_father->_name;}





