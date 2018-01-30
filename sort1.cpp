#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int m, n;
	cin>>m;
	cin>>n;
	while(m--)
	{
		vector<string> vec;
		string tmp = "\n";
		getline(cin, tmp);
		while(n--)
		{
			string st;
			getline(cin, st);
			if (find(vec.begin(), vec.end(), st) == vec.end())
			{
				vec.push_back(st);
			}
		}
		sort(vec.begin(), vec.end());
		for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			cout<<*it<<endl;
		}
	}
	
	return 0;
}