#include<iostream>
#define MAX 100
using namespace std;


class stack{
	int stackptr;
	int arr[MAX];
public:
	stack(){
		stackptr=-1;
	}
	void push(int data);
	void pop();
	bool empty();
	bool full();
	int top();
	void display();
};

bool stack::empty(){
	if(stackptr == -1 ){
		return true;
	}
	return false;
}

bool stack::full(){
	if(stackptr==MAX-1){
		return true;
	}
	return false;
}

void stack::push(int data){
	if(!full())
	{
		stackptr++;
		arr[stackptr]=data;
		return;
	}
	cout<<"stack is full"<<endl;
	return;
}

void stack::pop(){
	if(empty()){
		cout<<"Stack is already empty"<<endl;
		return;
	}
	stackptr--;
	return;
}

void stack::display(){
	int ind=stackptr;
	while(ind >= 0){
		cout<<arr[ind]<<" ";
		ind--;
	}
	cout<<endl;
}


int main()
{
	stack my_stack;
	// cout<<my_stack.empty()<<endl;
	my_stack.pop();
	// my_stack.push(100);
	// my_stack.push(200);
	// my_stack.push(300);
	// my_stack.push(400);
	// cout<<my_stack.empty()<<endl;
	// my_stack.display();
	return 0;
}