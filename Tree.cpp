#include<bits/stdc++.h>
using namespace std;

static string inord;
///Contains functions required for creating and for inorder traversal of the tree
class Tree{
public:
	struct node{
		char val;
		node * l;
		node * r;
	};

	///Creates new node
	static node * create_node(char x){
		node *t = new node;
		t->val=x;
		t->l=t->r=NULL;
		return t;
	}

	///Checks if character is an operator
	static bool isoperator(char z){
		if(z=='^' || z=='V' || z=='~' || z=='>'){
			return true;
		}
		return false;
	}

	///Forms the Parse Tree for a Propositional Formula in Postfix notation
	static node * getTree(string y){
		stack <node *> x;
		node* t;
		for(int i=0; i<y.size(); i++){
			if(!isoperator(y[i])){
				t = create_node(y[i]);
				x.push(t);
			}
			else if(y[i]=='~'){ //If character is ~, then left subtree is NULL
				t=create_node(y[i]);
				t->r=x.top();
				x.pop();
				x.push(t);
			}
			else{ 
				t=create_node(y[i]);
				t->r=x.top();
				x.pop();
				t->l=x.top();
				x.pop();
				x.push(t);
			}
		}
		t=x.top();
		x.pop();
		return t;
	}

	///Traverses the Tree, but contains reduntant Paranthesis
	static string traverse(node * x){
		if(x!=NULL){
			inord+='(';
			inorder(x->l);
			inord+=(x->val);
			inorder(x->r);
			inord+=')';
		}
		return inord;
	}

	///Returns fully paranthesised Inorder Traversal of a Parse Tree
	static string inorder(node *x){
		string s=traverse(x);
		string parfixed;
		for(int i=0;i<s.length();i++){
			if(!(s[i]=='(' && s[i+2]==')') && !(s[i]==')' && s[i-2]=='('))
				parfixed+=s[i];
		}
		return parfixed;
	}

	///Returns Inorder Traversal of a subtree in either direction
	static string tree(string s, string direction){
		if(direction=="left"){
			string inord2=inorder(getTree(s)->l);
			inord="";
			return inord2;
		}
		else if(direction=="right"){
			string inord2=inorder(getTree(s)->r);
			inord="";
			return inord2;
		}
	}
};
