#include<iostream>
#include<stack>
// #include<string.h>
#include<cstring>
using namespace std;

int eval(int op1, int op2, char ope){
	switch(ope){
		case '*': 	return op1*op2;
		case '/':	return op1/op2;
		case '+':	return op1+op2;
		case '-':	return op1-op2;

	}
}

int posteval(char arr[]){
	int i=0;
	int op1=0, op2=0;
	int size= strlen(arr);
	stack<char> stk;
	while( i<size){
		if(isdigit(arr[i])){
			stk.push(arr[i]- '0');
		}
		else{
			cout<<"checkpoint 1"<<endl;
			op1 = stk.top(); 
			cout<<"op1 :"<<op1<<endl; //check operator 1
			stk.pop();
			op2 = stk.top();
			cout<<"op2 :"<<op2<<endl; //check operator 2
			stk.pop();
			cout<<arr[i]<<endl;
			stk.push( eval( op1,op2,arr[i]) );
		}
		i++;

	}


	return stk.top();
}

int main (){
	char arr[]="632*+";
	int output = posteval(arr);
	cout<< "result :" <<output<<endl ;
	return 0;
}