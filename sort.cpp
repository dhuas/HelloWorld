#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class my_sort {
public:
	//冒泡排序
	void buddle_sort(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++) {
				if (nums[j] > nums[j + 1]) {
					int tmp = nums[j + 1];
					nums[j + 1] = nums[j];
					nums[j] = tmp;
				}
			}
		}
	}

	//选择排序
	void select_sort(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n - 1; i++) {
			int min_pos = i;
			for (int j = i + 1; j < n; j++) {
				if (nums[j] < nums[min_pos]) {
					min_pos = j;
				}
			}
			int tmp = nums[i];
			nums[i] = nums[min_pos];
			nums[min_pos] = nums[i];
		}
	}

	//插入排序
	void insert_sort(vector<int>& nums) {
		int n = nums.size();
		for (int i = 1; i < n; i++) {
			int pos = i - 1;
			int cur = nums[i];
			while (pos >= 0 && cur < nums[pos]) {
				nums[pos + 1] = nums[pos];
				pos--;
			}
			nums[pos + 1] = cur;
		}
	}

	//快速排序
	void fast_sort(vector<int>& nums, int start, int end) {
		int n = nums.size();
		int left = start;
		int right = end;
		int temp = nums[left];
		while (left < right) {
			while (left<right && nums[right]>temp) {
				right--;
			}
			nums[left] = nums[right];
			while (left < right && nums[left] < temp) {
				left++;
			}
			nums[right] = nums[left];
		}
		nums[left] = temp;
		fast_sort(nums, start, left - 1);
		fast_sort(nums, left + 1, end);
	}

	//归并排序
	void merge_sort(vector<int>& nums, int left, int right) {
		//递归划分
		if (left < right) {
			int mid = left + (right - left) / 2;
			//划分左右区间
			merge_sort(nums, left, mid);
			merge_sort(nums, mid + 1, right);
			//合并划分区间
			merge(nums, left, right);
		}
		return;
	}
	//归并排序合并函数
	void merge(vector<int>& nums, int left, int right) {
		vector<int> temp(nums.size());//临时记录数组
		int mid = left + (right - left) / 2;
		int l = left;//左边未排序第一个元素
		int r = mid + 1;//右边未排序第一个元素
		int k = left;//临时记录数组的下标
		while (l <= mid && r <= right) {
			if (nums[l] < nums[r]) {
				temp[k++] = nums[l++];
			}
			else temp[k++] = nums[r++];
		}
		while (l <= mid)temp[k++] = nums[l++];
		while (r <= right)temp[k++] = nums[r++];

		//拷贝回原数组
		while (left <= right) {
			nums[left] = temp[left];
			left++;
		}
	}


	//堆排序
	void stack_sort(vector<int>& nums) {
		int a = nums.size();
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < a; i++) {
			q.push(nums[i]);
		}
		for (int i = 0; i < a; i++) {
			nums[i] = q.top();
			q.pop();
		}
	}

};





int main() {
	vector<int> nums = { 1,33,445,23,12,234,4,333,447 };
	my_sort s;
	for (int num : nums) {
		cout << " " << num;
	}
	cout << "排序前" << endl;
	//s.buddle_sort(nums);
	//s.merge_sort(nums, 0, nums.size() - 1);
	s.stack_sort(nums);
	for (int num : nums) {
		cout << " " << num;
	}
	cout << "排序后" << endl;
	return 0;
}