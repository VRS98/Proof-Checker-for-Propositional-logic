#include<bits/stdc++.h>
#include"Logic.cpp"
using namespace std;

///Main function for checking validity of Propositional Logic Proof
int main(){
	int n;
	cout<<"Enter number of lines: ";
	cin>>n;
	int f=Logic::valCheck(n);
	if(f==0)
		cout<<"Valid Proof";
	else
		cout<<"Invalid Proof";
	return 0;
}