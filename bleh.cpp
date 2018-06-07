#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// using namespace algorithm;

// # define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
bool contains_Duplicate(vector<int>& nums) {
	// int a[]={1,2,3,4,5,6};
	// cout<<a.length();
	sort(nums.begin(),nums.end());
	for(int i=0;i<nums.size()-1;i++)
		if(nums[i]==nums[i+1])
			return true;
	// for (int i=0;i<nums.size();i++)
		// cout<<nums[i]<<"\t";
	return false;
}
bool containsDuplicate(vector<int>& nums) {
	// cout<<nums[1];
	for(int i=0;i<nums.size();i++)
	{
		// cout<<nums[i];
		for(int j=i+1;j<nums.size();j++){
			// cout<<nums[j];
			if(nums[i]==nums[j])
				return true;
		}
	}
	// cout<<nums.size()<<"in\n";
	return false;        
}
vector<int> construct(vector<int> a)
{
	a.push_back(51);
	a.push_back(2);
	a.push_back(23);
	a.push_back(12);
	a.push_back(6);
	a.push_back(6);
	a.push_back(6);
	return a;
}
int main()
{
	vector<int> a;
	a=construct(a);
	
	cout<<"-------\n";
	// cout<<a[0];
	// cout<<containsDuplicate(a)<<"\ncheck";
	cout<<contains_Duplicate(a);
	// cout<<"hello"<<a[0];
	return 0;
}