#include<bits/stdc++.h>
using namespace std;
///Contains additional functions that are reqiured to manipulate and extract information from statements
class Helper{
public:
	///Returns the statement number on which the rule is applied
	static int findpar(int n, string s){
		int par=0,p=0;
		if(n==1){ //Returns First Statement Number
			int i=s.length()-1;
			while(s[i--]!='/');
			while(s[i]!='/')
				par=pow(10,p++)*(s[i--]-48)+par;
		}
		else if(n==2){ //Returns Second Statement Number
			int i=s.length()-1;
			while(s[i]!='/')
				par=pow(10,p++)*(s[i--]-48)+par;
		}
		return par;
	}

	///Extracts the propositional formula from the input statement
	static string crop(string s){ 
		string s1;
		for(int i=0;i<s.length();i++){
			if(s[i]=='/')
				break;
			s1=s1+s[i];
		}
		return s1;
	}
};