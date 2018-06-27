#include<iostream>
#include<cstring>

using namespace std;
void removeduplicates(char arr[]){
	int stkptr=-1;
	int i = 0;
	int size= strlen(arr);
	while(i< size){
		if( stkptr== -1 || arr[stkptr] != arr[i] ){
			stkptr++;
			arr[stkptr]=arr[i];
			i++;
		}
		while(arr[i]==arr[stkptr]){
			i++;
			if(stkptr>=0){
				stkptr--;
			}
		}
	}
	arr[stkptr+1]='\0';
	cout<<arr<<endl;
	return;
}
int main(){
	char in[]="careexxeeeeeerac";
	// cout<< len << endl;
	removeduplicates(in);
	// cout<< in <<endl;
}