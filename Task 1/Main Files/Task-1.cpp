#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myheaderfile.h"

/**
 *@file Task-1.c
 *@author Anish Dey, Anish Walia, Shikhar Dhawale
 *@date October 15,2018
 *@brief This is the first task of the assignment
 *
 *\mainpage Description
 *This code is the first task of the assignmnet. Through his code,we should be able to verify that a given formula is well formed.
 *
 *\section func_sec Functionalities of this code
 *\subsection func1 infixtopostfix() 
 *Function to convert the infix propositional logic expression into a postfix propositional logic expression. 
 *\subsection func2 BuildParseTree()
 *Function to convert the postfix expression into a rooted binary parse tree.
 *\subsection func3 inorder()
 *Function to traverse the parse tree to output the infix expression back by in-order traversal of the parse tree.
 *
 *\subsection Definitions:
 *<statement> ::= p | (~p) | ~(<statement>) | (<statement> ^ <statement>) | (<statement> V <statement>) | (<statement> > <statement>)
 *<statement> should be perfectly parenthesized, e.g. ((a ^ b) ^ c) is valid, (a ^ b) ^ c is invalid, ((a ^ b)) is invalid, (a ^ b) is valid, (a ^ b ^ c) is invalid, p is valid, (p) is invalid, (~p) is valid, ~p is invalid.
*/


/**
 *@brief main() method
 *This function is used to enter the expression from the user and call the methods.
  
*/

int main(void) 
{
    char expression[100001];
	scanf("%s",expression);                   //Entering the expression
	infixtopostfix(expression);					//Calling function to get the postfix notation
	struct node *root=BuildParseTree(tree);		//Calling function to get the root
	inorder(root);								//Calling function to get the in=order traversal of the parse tree formed
	return 0;
}

