#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "PhoneticFinder.hpp"
using namespace std;

namespace phonetic
{
    bool equals2(char a, char b, const char x, const char y) {
        return (a == x || a == y) && (b == x || b == y);
    }

    bool equals2(char a, char b, const char x, const char y, const char z) {
        return (a == x || a == y || a == z) && (b == x || b == y || b == z);
    }

    /**
 *
 * @param ft char from temp
 * @param fw char from word
 * @return true if the letters match
 */
    bool equals2(char ft, char fw) {
        // Decapitelize the chars for easier match checks
        if ('A' <= ft && ft <= 'Z')
            ft = ft - 'A' + 'a';
        if ('A' <= fw && fw <= 'Z')
            fw = fw - 'A' + 'a';
        return ft == fw || // Genius and clean!
                equals2(ft, fw, 'v', 'w') ||
                equals2(ft, fw, 'b', 'f', 'p') ||
                equals2(ft, fw, 'g', 'j') ||
                equals2(ft, fw, 'c', 'k', 'q') ||
                equals2(ft, fw, 's', 'z') ||
                equals2(ft, fw, 'd', 't') ||
                equals2(ft, fw, 'u', 'o') ||
                equals2(ft, fw, 'i', 'y');
    }


/**
 *
 * @param temp is a string extracted from the text to be mached with word
 * @param word we gave the find() method
 * @return  true : if both are the same length , and every letter match.
 */

    bool equals2(string temp, string word) {
// Check if words match Length
        if (temp.length() != word.length())
            return false;
// They are the same Len , check char by char if they match
        for (size_t i = 0; i < word.length(); i++) {
            if ( !equals2( temp.at(i), word.at(i) ) )
                return false;
        }
// No mistakes found! return true!
        return true;
    }

/**
 * @param text : string type text, ,must contain only english alphabet and whitespaces (otherwise undefined) , throws exception if empty .
 * @param word : string type word , must contain only english alphabet and whitespaces (otherwise throws exeption) , that is to be found in the text,throws exception if empty.
 * This function finds the first occurrence of a given "word" in a given "text" , and return it as is from the text. 
 * The function is not case sensetive.
 * The function allows certian typos being made in the text , as described in the assingment:
 *  https://github.com/RoieJinx/phonetic-search-a/blob/master/README.md
 * @return : returns a string , which is the first
 */
    string find(string text, string word) {


        if (word.length() == 0) // Check empty word
        {
            string errorMessage1 = string("No words found in text");
            throw runtime_error(errorMessage1);
        }
        /** Roies Ver 2
         * A new version inspired by a shorter implemintaion that I found on gitHub
         */
        string temp = ""; // Empty string to containe words to procces.
        for (int i = 0; i <= text.length(); i++) { // Itr over the text
            // 1) If "whiteSpace" or "\0" is checked ,  it means we have a whole word in temp;
            if (  i == text.length() || text.at(i) == ' '  ) {
                if (equals2(temp, word)) // Check if the temp word match our word
                    return temp; // If so , return it =)
                // Empty the temp word, for new word to come;
                temp = "";

            } else  temp += text.at(i);  // Add to temp, chars from the current word we iterate over
        }
        // If no word found a match ,  throw;
        throw runtime_error(" Your word  ''" + word + "'' is not found in the text");
    }
}
