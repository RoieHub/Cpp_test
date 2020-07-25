#include "FamilyTree.hpp"
#include <string>
#include <iostream>

using namespace family;
using namespace std;


/**
 * Inspired by Shira's workm the way she expressed relations was just too beautifull !
 */
 static string relationM[][2] = { {"me"},{"father","mother"},{"grandfather","grandmother"}  };
 /**
  * This method is a shell method to add a father in the right place , it passes the child and his Father, to be correctly added ;
  * @param child : name of _root who is supposed to get a Father
  * @param Father : name of a new father subtree to be created and appended
  * @return  a pointer to "Me" , the main root of the whole tree
  */
 Tree& Tree::addFather(string child, string Father)
{
if(Tree::addFather(this,child,Father) ) return *this;
else throw runtime_error("Could not add father");
}
/**
 * This method desinged by shira is very good, the method travese throught the tree ,
 * untill it finds the subtree with child as root, it create and append a father to the child, and updates child depth
 * if it does not have a mother.
 * @param tree  current subtree root
 * @param child the name of the root we are looking for
 * @param father the name of the father to be created and appended to child
 * @return true if father was added to the child
 */
bool Tree::addFather(Tree *tree , string child , string father){
     if(tree == nullptr) return false; // Check if the tree is legit
     if(tree->_root == child){// Is this the child Node where I need to add a father?
       if(tree->_father == nullptr) {// Is "_father" empty ?
            tree->_father = new Tree(father) ; // Create and add father subtree
            if(tree->_mother == nullptr)
            {// Check if mother exist to update the depth to the main root.
              this->_depth++;
            }
            return true;
       }
       else {// Father allready exist! trow error
           throw runtime_error(child+" allready have a father!");
       }
     }
     return addFather(tree->_father , child , father) || addFather(tree->_mother,child , father);
 }

Tree& Tree::addMother(string Child, string Mother)
{
    if( addMother(this , Child , Mother) ) return *this;
    else throw runtime_error("Could not add mother to "+Child);
}
/**
 * Same as add father above
 * @param tree
 * @param Child
 * @param Mother
 * @return
 */
bool Tree::addMother(Tree *tree,string Child, string Mother)
{
    if( tree == nullptr) return false;// Is the tree node legit?
    if(tree->_root == Child) // If this is the Node I am looking for
    {
        if (tree->_mother == nullptr){ // If no mother assinged yet
            tree->_mother = new Tree(Mother); // Create and assing a mother
            if (tree->_father == nullptr) ++(this->_depth) ;// If there is no father to this node, update main root depth
                return true; // Mother sucsessfully added!

    }else{ // There is allready a mother!
         throw runtime_error("Node "+Child+" allready have a mother!" );
         }
    }
    // If we got here, this is not the child node we are looking for, keep diggind deeper
    return addMother(tree->_father , Child , Mother) || addMother(tree->_mother , Child ,Mother);
}

/**
 * This method finds a relation between "me" (the main root) and the node named "name"
 * if no such node exist, return "unrelated" else returns the relation.
 */
string Tree::relation( string name )
{
    string ans = relation (this,name,0,0);
    if( ans != "")
        return ans;
    else
        return "unrelated";
}
////////// Need to learn more about display and find and remove//////////
string Tree::relation( Tree *tree , string name , int depth , int gender)
{
    string ans ="";
    if(tree->_root == name) // Is this the node I am looking for?
        return whatTheRelation(depth , gender); // It is! return relation please!
    if(tree->_father != nullptr) // I is not the root I am looking for ,does he have a father?
        ans = relation(tree->_father , name , ++depth , 0); // Maybe its his father?
    else depth++; // What? why here?
    if(ans == "" && tree-> _mother != nullptr)
        ans = relation(tree->_mother , name , depth , 1);
        return ans;
}

string Tree::whatTheRelation(int depth ,int gender)
{
    int numOfGrate = depth -2; // Determine how many "grate" I need to print
    if(numOfGrate >= 1) // If there more then 0 , need to add them to my asnwere
    {
        string ans = "";
        for( int i = 0 ; i < numOfGrate ; ++i)
        {
            ans += "great-";
        }
        return ans += relationM[2][gender];
    }
    return relationM[depth][gender];
}

string Tree::find(Tree *tree , string relation , int depth , int gender)
{
    string ans = "";
    if( relation == whatTheRelation(depth,gender))
        return tree->_root;
    if( tree->_father != nullptr)
        ans = find(tree->_father , relation , ++depth, 0);
    else
        depth++;
    if( ans == "" && tree->_mother != nullptr)
        ans = find(tree->_mother , relation , depth , 1);
    return ans;
}

string Tree::find(string relation)
{
    string ans = find(this,relation,0,0);
    if( ans != "")
        return ans;
    else
    throw runtime_error("Cound not find the relation you looking for");
}


void Tree::display()
{
    int size = this->_depth + 1;
    string myFamily[size];
    display(this,myFamily,0);
    for( int i = 0 ; i < size ; ++i)
    {
        for(int j = 0 ; j <(size*4) - (i*5) ; j++) // For spaces
        {
            cout << " "; // Spaces in prints
        }
        cout << myFamily[i].substr(0,myFamily[i].size()-3) << "\n";
    }
}

void Tree::display(Tree *tree , string* myFamily, int depth)
{
    if(tree != nullptr)
    {
        myFamily[depth] += tree->_root + " _ ";
        display(tree->_father, myFamily,++depth);
        display(tree->_mother ,myFamily , depth);
    }
}

void Tree::remove(string toRemove)
{
    if(this->_root == toRemove)
        throw runtime_error("remove() throw - The root cannot be deleted");
    if(!remove(this,toRemove))
        throw runtime_error("This name do not exist in tree: "+toRemove);
}
bool Tree::remove(Tree* tree , string toRemove)
{
    if( tree == nullptr) return false;
    if( tree->_father != nullptr && tree->_father->_root == toRemove)
    {
        delete tree->_father;
        tree->_father = nullptr;
        return true;
    }
    if( tree->_mother != nullptr && tree->_mother->_root == toRemove)
    {
        delete tree->_mother;
        tree->_mother = nullptr;
        return true;
    }
    return remove(tree->_father,toRemove) || remove(tree->_mother , toRemove);
}