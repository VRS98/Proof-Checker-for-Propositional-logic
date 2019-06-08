#include<bits/stdc++.h>
#include"Postfix.cpp"
#include"Tree.cpp"
using namespace std;

///Main function for Postfix and Inorder Traversal
int main(){
	string s;
	cout<<"Enter expression: ";
	cin>>s;
	//auto start = chrono::steady_clock::now();
	cout<<"The postfix is: "<<Postfix::postfix(s);
	cout<<"\nThe infix by traversing the formed Parse tree is: "<<Tree::inorder(Tree::getTree(Postfix::postfix(s)));
	//auto end = chrono::steady_clock::now();
	//auto diff = end - start;
	//cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
	return 0;
}

