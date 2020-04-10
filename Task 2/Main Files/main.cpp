/**
 *@file Task-2.cpp
 *@author Anish Dey, Anish Walia, Shikhar Dhawale
 *@date October 15,2018
 *@brief This is the second task of the assignment
 *
 *\mainpage Description
 *This code is the second task of the assignmnet. A tool for verifying whether a certain proof of a given sequent is valid or not.
 *
 *\section func_sec Allowed proof rules are :
 *\subsection
 *1. Premise
 *2. AND introduction/elimination
 *3. OR introduction
 *4. IMPLIES elimination
 *5. Modus Tollens
 *
 *\subsection Definitions:
 *<statement> ::= p | (~p) | ~(<statement>) | (<statement> ^ <statement>) | (<statement> V <statement>) |
 *(<statement> > <statement>)
 *<rule> ::= ^i | ^e1 | ^e2 | Vi1 | Vi2 | >e |P
 *
 *\section Input
 *\subsection
 *First line:
 *n (number of statements)
 *Next n lines:
 *<statement>/<rule>[ /line1[ /line2 ] ] (parameter in [] is optional whose existence will be determined by <rule>)
 *\section Output
 *\subsection
 *Valid Proof (or) Invalid Proof
 *\section Assumptions
 *\subsection
 *1. Line number starts from 1.
 *2. <statement> should be perfectly parenthesized, e.g. ((a ^ b) ^ c) is valid, (a ^ b) ^ c is invalid, ((a ^ b)) is invalid, (a ^ b) is valid, (a ^ b ^ c) is invalid, p is valid, (p) is invalid, (~p) is invalid, ~p is invalid.
 *3. ~ can be succeeded ( only.
*/

#include <iostream>
#include "part2.h"

using namespace std;

int main(){
        int n;
        cout<<"Enter n followed by lines of proof:"<<endl;
        cin>>n;
        Part2 obj;
        if(obj.isValid(n)) cout<<"Valid Proof"<<endl;
        else cout<<endl<<"Invalid Proof"<<endl;
    return 0;
}
