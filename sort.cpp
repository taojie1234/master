#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		vector<char> vec;
		string str;
		cin>>str;
		int i;
		for (i = 0; i < str.length(); i++)
		{
			vec.push_back(str[i]);
		}
		sort(vec.begin(), vec.end());
		
		for(vector<char>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	return 0;
}