//
// Created by CyberLab on 7/21/2020.
//
#include "PhoneticFinder.hpp"

using namespace std;

bool equals(char a, char b, const char x, const char y){
    return (a == x || a == y) && (b == x || b == y);
}

bool equals(char a, char b, const char x, const char y, const char z){
    return (a == x || a == y || a == z) && (b == x || b == y || b == z);
}

bool equals(char a, char b){
    if('A' <= a && a <= 'Z')
        a = a - 'A' + 'a';
    if('A' <= b && b <= 'Z')
        b = b - 'A' + 'a';

    return a == b ||
           equals(a, b, 'v', 'w') ||
           equals(a, b, 'b', 'f', 'p') ||
           equals(a, b, 'g', 'j') ||
           equals(a, b, 'c', 'k', 'q') ||
           equals(a, b, 's', 'z') ||
           equals(a, b, 'd', 't') ||
           equals(a, b, 'u', 'o') ||
           equals(a, b, 'i', 'y');
}

bool equals(string s, string t){
    if(s.length() != t.length())
        return false;

    for(size_t i = 0; i < s.length(); i++)
        if(!equals(s.at(i), t.at(i)))
            return false;
    return true;
}

string phonetic::find(string s, string word){

    if(word == "" || word == " ")
        throw runtime_error("Can't search for an empty word");

    string tmp = "";
    for(size_t i = 0; i <= s.length(); i++){
        if(i == s.length() || s.at(i) == ' '){
            if(equals(tmp, word))
                return tmp;

            tmp = "";
        } else
            tmp += s.at(i);
    }
    throw runtime_error("Did not find the word '"+word+"' in the text");
}


