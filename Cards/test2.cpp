#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void InsertSort(vector<int> nums)
{
	int i, j;
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])    //如果第i个元素比已排序元素还大就没必要管了，继续下一个
        {
			//int tmp = nums[i];
            nums[0] = nums[i];    //哨兵，就是待排序的那个元素，数组中一般用nums[0]
            for (j = i - 1; nums[j] > nums[0]; j--)
                nums[j + 1] = nums[j];    //比哨兵大就要向后移动
            nums[j] = nums[0];    //找到合适的位置了
        }
    }
	for (auto it = nums.begin(); it != nums.end(); it++){
		cout<<*it<<" ";
	}
}

int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++){
		int d = rand()%20;
		vec.push_back(d);
	}
	InsertSort(vec);
	
	return 0;
}