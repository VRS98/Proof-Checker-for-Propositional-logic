#include<bits/stdc++.h>
using namespace std;
///Contains functions that check which rule of natural deduction is applied for a particular proof line
class Checking{
public:
	///Checks if the statement is a proposition statement deduced using AND
	static int andcheck(string s){
		for(int i=s.length()-1;i>=2;i--){
			if(s[i]=='i' && s[i-1]=='^' && s[i-2]=='/') //check if this is AND intro
				return 1;
			else if(s[i]=='e' && s[i-1]=='^' && s[i-2]=='/') //check if this is AND elim
				return 2;
		}
		return 0;
	}
	
	///Checks if the statement is a proposition statement deduced using IMPLICATION Elimination
	static bool implcheck(string s){
		for(int i=s.length()-1;i>=2;i--){
			if(s[i]=='>' && s[i-1]=='/')
				return true;
		}
		return false;
	}

	///Checks if the statement is a proposition statement deduced using OR Elimination
	static bool orcheck(string s){
		for(int i=s.length()-1;i>=2;i--){
			if(s[i]=='V' && s[i-1]=='/')
				return true;
		}
		return false;
	}

	///Checks if the statement is a proposition statement deduced using MODUS TOLLENS
	static bool MTcheck(string s){
		for(int i=s.length();i>=2;i--){
			if(s[i]=='T' && s[i-1]=='M' && s[i-2]=='/')
				return true;
		}
		return false;
	}
};