/**
 *@file part2.cpp
 *@author Anish Dey, Anish Walia, Shikhar Dhawale
 *@brief This is the file containing functions
*/

#include "part2.h"

Part2::Part2(){
valid=1;           //initialising valid to 1
}

void Part2::invalid(){
valid=0;           //setting valid to 0 if proof is invalid
}

string Part2::doubleNegation(string s1){
string s2;         /**<s2 is s1 without double negation sign*/
if(s1[0]=='~'&&s1[1]=='~'){  //detects presence of ~~ sign in s1
s2=s1.substr(2);
}
else{
    s2=s1;
}
return s2;
}

bool Part2::isValid(int n){
string temp;       ///<stores the line of proof entered
    int backind;   /**<stores the position of / in entered line*/
    list <string> premises;   /**<stores all entered premises and valid lines of proof*/
    for(int i=0;i<n;i++){
       cin>>temp;
       backind=temp.find('/');
       if(temp[backind+1]=='P'){       //pushes entered premise in premises list
            premises.push_back(temp.substr(0,backind));
       }
        else{
            int backind2;     /**<stores position of second / in entered line of proof*/
            int l1;           /**<stores first line number associated with proof rule*/
            int l2;           /**<stores second line number(if exists) associated with proof rule*/
            temp[backind]='0';
            backind2=temp.find('/');  // finds position of second /
            //^i rule
            if(temp[backind+1]=='^'&&temp[backind+2]=='i'){
                string str1;  ///<stores p if entered line is of form (p^q)
                string str2;  /**<stores q if entered line is of form (p^q)*/
                l1=(int)temp[backind2+1];
                l2=(int)temp[backind2+3];
                l1-=48;
                l2-=48;
                list<string>::iterator it1=premises.begin();
                advance(it1,l1-1);  //getting str1
                str1=*it1;
                it1=premises.begin();
                advance(it1,l2-1);  //getting str2
                str2=*it1;
                if(("("+str1+"^"+str2+")").compare(temp.substr(0,backind))!=0){  //if given line of proof is invalid
                    invalid();
                    break;
                }
            }

            //^e rule
            if(temp[backind+1]=='^'&&temp[backind+2]=='e'){
                int indand;       /**<stores position of ^ symbol*/
                string tempstr;   /**<stores premise from which elemination is done*/
                string tempstr2;  /**<stores the entered line of proof*/
                l1=(int)temp[backind+3];
                l1-=48;
                l2=(int)temp[backind+5];
                l2-=48;
                list<string>::iterator it1=premises.begin();
                advance(it1,l2-1);
                tempstr=*it1;
                tempstr2=temp.substr(0,backind);
                if(l1==1){      //if rule is ^e1
                    if(tempstr.find(tempstr2+"^")==string::npos){   //checks validity of entered line
                        invalid();
                        break;
                    }
                    indand=tempstr.find(tempstr2+"^");
                    for(int y=0;y<indand;y++){
                        if(tempstr[y]!='('){
                            invalid();
                            break;}}
                }
                else{    //if rule is ^e2
                    if(tempstr.find("^"+tempstr2)==string::npos){ //checks validity of proof
                        invalid();
                        break;
                    }
                    indand=tempstr.find("^"+tempstr2);
                    for(int y=indand+1+tempstr2.length();y<tempstr.length();y++){
                        if(tempstr[y]!=')'){
                            invalid();
                            break;}}
                }
            }

            //Vi rule
            if(temp[backind+1]=='V'){
                l1=(int)temp[backind+3];
                l1-=48;
                l2=(int)temp[backind+5];
                l2-=48;
                list<string>::iterator it1=premises.begin();
                string tempstr;  /**<stores the premise used for Vi*/
                advance(it1,l2-1);
                tempstr=*it1;
            if(l1==1){ //checks validity if rule is Vi1
                if(temp.substr(0,backind).find("("+tempstr+"V")!=0){
                    invalid();
                    break;}
            }
            else{   //checks validity if rule is Vi2
                if(temp.substr(0,backind).find("V"+tempstr+")")!=0){
                    invalid();
                    break;}
            }
            }

            //>e rule
            if(temp[backind+1]=='>'){
                l1=(int)temp[backind2+1];
                l2=(int)temp[backind2+3];
                l1-=48;
                l2-=48;
                string impli;    /**<stores the string containing implication*/
                string phi;      /**<stores the line used as p in entered string of form (p>q)*/
                string si;       /**<stores q if entered string is of form (p>q)*/
                list<string>::iterator it1=premises.begin();
                advance(it1,l1-1);
                impli=*it1;
                it1=premises.begin();
                advance(it1,l2-1);
                phi=*it1;
                si=temp.substr(0,backind);
                if(("("+phi+">"+si+")").compare(impli)!=0){  //checks validity
                    invalid();
                    break;
                }
            }

            //MT
            if(temp[backind+1]=='M'&&temp[backind+2]=='T'){
                string str1;       /**<stores line containing implication in Modus Tolens rule*/
                string str2;       /**<stores premises which is ~q if implication line is of form (p>q)*/
                string tempstr1;   /**<stores entered line with ~~ sign removed(if present)*/
                string tempstr2;   /**<stores str2 with removed ~~ sign (if present)*/
                l1=(int)temp[backind2+1];
                l2=(int)temp[backind2+3];
                l1-=48;
                l2-=48;
                list<string>::iterator it1=premises.begin();
                advance(it1,l1-1);
                str1=*it1;
                it1=premises.begin();
                advance(it1,l2-1);
                str2=*it1;
                tempstr1=doubleNegation("~"+temp.substr(0,backind));  //removes ~~ from entered line
                tempstr2=doubleNegation("~"+str2);                    //removes ~~ from ~q if implication line is of form (p>q)
                if(("("+tempstr1+">"+tempstr2+")").compare(str1)){ //checks validity
                    invalid();
                    break;
                }
            }

        premises.push_back(temp.substr(0,backind));   //pushes every valid entered line in list of premises
        }
    }
return valid;
}
