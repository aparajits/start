// 1 stack aux
// 1 array o/p
/*
^  *  /  +  -
5  4  3  2  1
*/
// input char array
#include<iostream>
#include<stack>
#include<cstring>
#define MAX 100
using namespace std;

int prec(char a){
	if(a== '^')
		return 5;
	if(a== '*')
		return 4;
	if(a== '/')
		return 3;
	if(a== '+')
		return 2;
	if(a== '-')
		return 1;
	if(a== '(')
		return 0;
	if(a== ')')
		return 0;
	return -1;
}

void intopostfix(char arr[]){
	int size=strlen(arr);
	int i=0, j=0;
	stack<char> stk;
	char out[MAX];
	while( i < size ){
		if(prec(arr[i])!=-1){
			// cout<<"Encountered an operator "<< arr[i]<<endl;
			if(stk.empty())
			{
				stk.push(arr[i]);
				// cout<<"Pushed the first element "<<arr[i]<<" into the stack"<<endl;
			}
			if(arr[i]==')'){
				// cout<<"Encountered )"<<endl;
				// char tmp=stk.top();
				while(stk.top()!='('){
					out[j]=stk.top();
					j++;
					stk.pop();
				}
				if(stk.top()=='('){
					stk.pop();
				}
			}
			else if (arr[i]=='('){
				// cout<<"pushed ( into the stack"<<endl;
				stk.push(arr[i]);
				// cout<<out<<endl;
				// cout<<"current top element "<< stk.top() <<endl;
			}
			else if ( prec(stk.top()) < prec(arr[i])  ){
				stk.push(arr[i]);
				// cout<<"pushed the operator "<<arr[i]<<" into the stack"<<endl;
			}
			else if (prec(stk.top()) > prec(arr[i]) ){
				out[j]=stk.top();
				// cout<<"pushed the operator  "<<arr[i]<<" into the output array by removing the top element from the stack"<<endl;
				// cout<<"currently the output is "<<out<<endl;
				j++;
				stk.pop();
				stk.push(arr[i]);
			}
		}
		else if(prec(arr[i])==-1 ){
			// cout<<"Encountered a character  "<<arr[i]<<" "<<endl;
			out[j]=arr[i];
			j++;
			// cout<<"current output "<< out <<endl;
		}
		i++;
	}
	// cout<<j<<endl;
	while(!stk.empty()){
		out[j]=stk.top();
		stk.pop();
		j++;
	}
	cout <<out<<endl;
	return;
}


int main(){
	char arr[]="a+(b*c)";
	intopostfix(arr);
	return 0;
}