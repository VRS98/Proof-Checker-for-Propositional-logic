#include<bits/stdc++.h>
#include"Checking.cpp"
#include"Postfix.cpp"
#include"Tree.cpp"
#include"Helper.cpp"
using namespace std;
#define postfix(string) Postfix::postfix(string) 
#define findpar(int,string) Helper::findpar(int,string)
#define crop(string) Helper::crop(string)
///Implements the main algorithm for Part 2

class Logic{
public:

	/// This method checks the validity of each statement
	static int valCheck(int n){
		vector <string> l;
		int f=0;
		l.push_back("$");
		for(int i=1;i<=n;i++){
			cout<<i<<". ";
			string a;
			cin>>a;
			
			if(a[a.length()-1]=='P' || a[a.length()-1]=='p') //If statement is a premise
				l.push_back(crop(a));

			else if(Checking::andcheck(a)==1){ //If statement is AND Intro
				int l1=findpar(1,a); //extracts first parameter
				int l2=findpar(2,a); //extracts second parameter

				a=crop(a);
			
				if(postfix(Tree::tree(postfix(a),"left"))==postfix(l[l1]) && postfix(Tree::tree(postfix(a),"right"))==postfix(l[l2]))
					l.push_back(a);
				/*
				This expression of postfix(Tree::tree(postfix() is used many times in the following code as follows: First the postfix of the expression is formed so we can form the parse tree.
				After traversing the tree by inorder traversal, we again convert it to postfix just to make sure that the comparison is right even when the entered 
				expression is not fully paranthesized but is logically equivalent to the other expression.
				*/

				else{
					f=1;
					l.push_back(a);
				}
			}

			else if(Checking::andcheck(a)==2){ //If statement is AND elimination
				int l0=findpar(2,a);
				int p;
				for(int i=0;i<a.length();i++){ //If statement is E1 or E2
					if(a[i]=='/' && a[i+3]=='1')
						p=1;
					else if(a[i]=='/' && a[i+3]=='2')
						p=2;
				}
				a=crop(a);
				if(p==1){
					if(postfix(Tree::tree(postfix(l[l0]),"left"))==postfix(a) && postfix(l[l0])[postfix(l[l0]).length()-1]=='^') //Comparing strings and checking if the root of the parse tree is ^
						l.push_back(a);
					else{
						f=1;
						l.push_back(a);
					}
				}
				else if(p==2){
					if(postfix(Tree::tree(postfix(l[l0]),"right"))==postfix(a) && postfix(l[l0])[postfix(l[l0]).length()-1]=='^') 
						l.push_back(a);
					else{
						f=1;
						l.push_back(a);
					}
				}
			}

			else if(Checking::implcheck(a)){ //If statement is IMPLICATION elimination
				int l1=findpar(1,a);
				int l2=findpar(2,a);
				a=crop(a);
				if(postfix(Tree::tree(postfix(l[l1]),"left"))==postfix(l[l2]) && postfix(Tree::tree(postfix(l[l1]),"right"))==postfix(a) && postfix(l[l1])[postfix(l[l1]).length()-1]=='>')
					l.push_back(a);
				else{
					f=1;
					l.push_back(a);
				}
			}

			else if(Checking::orcheck(a)){ //If statement is OR Introduction
				int l0=findpar(2,a);
				int p;
				for(int i=0;i<a.length();i++){ //If statement is I1 or I2
					if(a[i]=='/' && a[i+3]=='1')
						p=1; //I1
					else if(a[i]=='/' && a[i+3]=='2')
						p=2; //I2
				}
				a=crop(a);
				if(p==1){ 
					if(postfix(Tree::tree(postfix(a),"left"))==postfix(l[l0]))
						l.push_back(a);
					else{
						f=1;
						l.push_back(a);
					}
				}
				if(p==2){
					if(postfix(Tree::tree(postfix(a),"right"))==postfix(l[l0]))
						l.push_back(a);
					else{
						f=1;
						l.push_back(a);
					}
				}
			}

			else if(Checking::MTcheck(a)){ //IF statement is MT
				int l1=findpar(1,a);
				int l2=findpar(2,a);
				a=crop(a);
				if(postfix(Tree::tree(postfix(l[l1]),"right"))==postfix(Tree::tree(postfix(l[l2]),"right")) && postfix(Tree::tree(postfix(a),"right"))==postfix(Tree::tree(postfix(l[l1]),"left")))
					l.push_back(a);
				else{
					f=1;
					l.push_back(a);	
				}
			}
			else
				f=1;
		}
		return f;
	}
};