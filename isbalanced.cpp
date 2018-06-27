#include<iostream>
#include<stack>
using namespace std;



bool isbalanced(char arr[], int len){
	stack<char> stk;
	char x='x';
	// cout<<arr<<endl;
	// int len= sizeof(arr)/sizeof(arr[0]);
	// cout<<"calculated length of the string is "<<len<<endl;
	for(int i=0; i< len; i++){
		if( arr[i] == '(' ||  arr[i] == '[' ||  arr[i] == '{'){
			// cout<<"Pushed ";
			stk.push(arr[i]);
			// cout<<stk.top()<<endl;
		}
		else if( (arr[i] == ')' ||  arr[i] == ']' ||  arr[i] == '}' )  ) {
			// cout<<"check 1"<<endl;
			x=arr[i];
			if(stk.empty())
				return false;
			switch(x){
				case ')':	if(stk.top()=='('){
								stk.pop();
							
								// cout<<"case ( checked"<<endl;
							}
							else 
								return false;
							break;
				case ']':	if(stk.top()=='['){
								stk.pop();
							
								// cout<<"case [ checked"<<endl;
							}
							else 
								return false;
							break;
				case '}':	if(stk.top()=='{'){
								stk.pop();
							
								// cout<<"case { checked"<<endl;
							}
							else 
								return false;
							break;
				default:	break;
			}
		}
	}
	if(stk.empty()){
		return true;
	}
	return false;
}
int main(){
	char arr[]="({)}";
	int len= sizeof(arr)/sizeof(arr[0]);
	// cout<<"length from main fucntion "<<len<<endl;
	if(isbalanced(arr, len)){
		cout<<"balanced"<<endl;
	}
	else{
		cout<<"not balanced"<<endl;
	}
	return 0;
}