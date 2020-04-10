/**
 *@file part2.cpp
 *@author Anish Dey, Anish Walia, Shikhar Dhawale
 *@brief This is the file containing functions
*/
#ifndef PART2_H_INCLUDED
#define PART2_H_INCLUDED
#include<iostream>
#include<stack>
#include<list>
#include<map>
#include <iterator>

using namespace std;

class Part2{
private:
    int valid;                         /**<used to return whether the proof is valid or not*/
    /**
    *\brief invalid() method
    * This function is used to set valid to 0 which means given proof is invalid.
    *Call this function as follow:
    *@code
    *invalid();
    *@endcode
    */
    void invalid();
    /**
    *\brief doubleNegation() method
    * This function is mainly used to remove double negation in provided string.
    *Call this function as follow:
    *@code
    *doubleNegation(s1);
    *@endcode
    *@note
    *@param s1 must be a string variable
    @return string with no double negation signs
    */
    string doubleNegation(string s1);
public:
    /**
    *\brief Part2() method
    * This function is a constructor which initialises valid variable to 0
    *This function is called automatically which object of corresponding class is made:
    *@endcode
    */
    Part2();
    /**
    *\brief isValid() method
    * This function is mainly used to return the validity of the given proof.
    *Call this function as follow:
    *@code
    *isValid(n);
    *@endcode
    *@note
    *@param n must be a integer variable
    @return 1 if given proof is valid, else 0
    */
    bool isValid(int n);
};

#endif // PART2_H_INCLUDED
