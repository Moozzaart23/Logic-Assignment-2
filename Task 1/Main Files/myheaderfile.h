#include <stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[100001];			/**<To store the characters for the expression sent*/
char post[100001];			/**<To store the characters for the postfix notation */
char tree[10001];   		/**<To get the parse rooted tree*/
int top1=-1;				/**<The top value for the node used in push1() and pop1()*/
int count=0;				/**<To count the numbr of charcters in the postfix notation*/

/**
 *\struct node
 *\brief This is a node struct
 *This struct contains a character variable and to pointers of struct type for left and right node
*/
struct node 					
{
    char value;								/**<A chracter variable*/
    struct node* left;						/**<A struct variable to store the contents of left node*/
	struct node *right;        					/**<A struct variable to store the contents of right node*/
};

/**
 *\brief Push1() method
 * This function is mainly used to push a character into the stack[]array.
 *Call this function as follow:
 *@code
 push1(c);
 *@endcode
 *@note 
 * c must be a character variable
*/
 void push1(char ch)					
{
   	top1++;                 //Increase the top value by 1
	stack[top1]=ch;			//Enter the character sent to the stack[] array
}

/**
 *@brief Pop1() method
 * This function is mainly used to pop a character from the stack[]array.
 *Call this function as follow:
 *@code
 char c=pop();
 *@endcode
 @return The character from the end of the stack[] array
*/

char pop1()							
{   
	return stack[top1--];			//pop and return the character and also decrese top by 1
}

/**
 *@brief infixtopostfix() method
 * This function is mainly used to convert an infix notation to its postfix form.
 *Here first we go through all the elemnts of the stack[] array.
 *And then we check whether the elemnt is '>' o '^' or '(' or '~'.
 *If so we call the push1 method
 *If the element is ')' , we traverse through all the elemnts to get the postfix form of that expression
 *Call this function as follow:
 *@code
 infixtopostfix(expression);
 *@endcode
*/



void infixtopostfix(char c[])					
{  int i;
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]=='>'||c[i]=='^'||c[i]=='V'||c[i]=='('||c[i]=='~')			//If any one of the following
			push1(c[i]);													//push the character into the stack[] array
		else if(c[i]==')')													//f ')' 
		{
			while(post[count-1]!='(')										//Traverse through all the elments 
			{
				post[count]=pop1();											//Insert every element into the post[] array
				count++;													//Increase count by 1
			}
			
			count--;														//Decrese count after getting out of the for loop
		}
		else
		{
			post[count]=c[i];
			count++;
		}
	}
	for(int j=0;j<count;j++)
	{
		printf("%c",post[j]);
            tree[j]=post[j];
	}
 printf("\n");
}



struct node* arr[5000];							/**<An array of struct node*/
int top2=-1;									/**<The variable for push2 and pop2 method*/

/**
 *@brief Push2() method
 * This function is mainly used to push a character into the arr[] array.
 *Call this function as follow:
 *@code
 push2(a);
 *@endcode
 *@note a should be a variable of struct node
*/ 


void push2(struct node* a)						
{
 	top2+=1;						//Increase top2 by 1
    arr[top2]=a;					//Enter the node into the arr[] array
}


/**
 *@brief Pop2() method
 * This function is mainly used to decrease the value of top2 by 1.
 *Call this function as follow:
 *@code
 pop2();
 *@endcode
 
*/


void pop2()										
{
    top2--;					//Reducing the value of top2 by 1
}

/**
 *@brief Newnode() method
 * This function is mainly used to create a new node of struct node type and then initialise its member elemnts.
 *value is initialised with the character value sent
 *left and right nodes are initialised with NULL value
 *Call this function as follow:
 *@code
 struct node *a=newnode(c);
 *@endcode
 @note c is a character variable
 @return The function returns the new node that has been created inside it.
*/


struct node* newnode(char value)		
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->value=value;			//Initialise value with the chracter sent
    temp->left=NULL;			//Initialise left with NULL
    temp->right=NULL;			//Initiaise right with NULL
    return temp;
}

/**
 *@brief BuildParseTree() method
 *This function is mainly used to build the parse tree in terms of the root.
 *It's main function is to return the root after carrying out the operation on the postfix form of the expression entered.
 *Here if '~' is encountered, we initialise left node with NULL and right node with the character next to it.
 *For dual noded operators, left and right both nodes are initialised.
 *
 *Call this function as follow:
 *@code
 struct node *root=BuildParseTree(tree);
 *@endcode
 @note tree is a character array
 @return The function returns the root node.
*/


struct node* BuildParseTree(char expression[])			//returns root
{

    struct node* a;
    int b,c;
    int i;
    for(i=0;i<strlen(expression);i++)
    {
        if(expression[i]=='~')				//For ~ operation there is no right arm and the left arm is the character next to it.
        {
            a=newnode(expression[i]);		//Create a new node
            b=top2;							//Initialise b with top2
            pop2();							//Reduce the value of top2 by 1 
            a->left=NULL;					//Initialise the left node with NULL
            a->right=arr[b];				//Initialise the right node with b'th index of the arr node
            push2(a);						//push the new node created into the arr[] array
        }
        else if(expression[i]=='V' || expression[i]=='^'|| expression[i]=='>')  //For dual operators there is a right arm initialise with the before character and the left arm is the character next to it.
        {
            a=newnode(expression[i]);		//Create a new node
            b=top2;							//Initialise b with top2
            a->right=arr[b];				//Initialise the right node with b'th index of arr[] array
            pop2();							//Reduce the value of top2 by 1 
            c=top2;							//Initialise c with top2
            pop2();							//Reduce the value of top2 by 1 
            a->left=arr[c];					//Initialise the left node with c'th index of arr[] array
            push2(a);						//push the new node created into the arr[] array
        }
        else
    	{
      		a=newnode(expression[i]);		//Create a new node
      		push2(a);						//push the new node created into the arr[] array
    	}
    }
    a=arr[top2];					//a is initialised with the top value of the arr[] array 
    pop2();							//Reduce the value of top2 by 1
    return a;						//Returning the root
}

/**
 *@brief inorder() method
 *This function is used to go through the rooted parse tree and get the notation by in-order traversal of the 
 *rooted binary parse tree
 *Call this function as follow:
 *@code
 inorder(root);
 *@endcode
 @note tree is a character array
 
*/


void inorder(struct node *t)
{   
    
    if(t!=NULL && t->value!='~')
    {  if(t!=NULL&&(t->value=='>'||t->value=='^'||t->value=='V'||t->value=='~'))
        printf("(");               //If matches then print '('
        inorder(t->left);			//Recursively call inorder function with the left node
        printf("%c",t->value );		//Print the value of the node
        inorder(t->right);			//Recursively call the inorder function with the right node
     if(t!=NULL&&(t->value=='>'||t->value=='^'||t->value=='V'||t->value=='~'))
     printf(")");					//Print ')'
    }
    else if(t!=NULL)
    {    printf("(");
         printf("%c",t->value );   
        inorder(t->right);
       printf(")");
       
    }
}

