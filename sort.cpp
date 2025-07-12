#include<iostream>
#include<vector>

using namespace std;

class my_sort {
public:
	//√∞≈›≈≈–Ú
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

	//—°‘Ò≈≈–Ú
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

	//≤Â»Î≈≈–Ú
	void insert_sort(vector<int> nums) {
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

	//øÏÀŸ≈≈–Ú
	void fast_sort(vector<int> nums, int start, int end) {
		int n = nums.size();
		int left = start;
		int right = end;
		int temp = nums[left];
		while (left < right) {
			while (left<right && nums[right]>nums[left]) {
				right--;
				nums[left] = nums[right];
			}
			while (left < right && nums[left] < nums[right]) {
				left++;
				nums[right] = nums[left];
			}
		}
		nums[left] = temp;
		fast_sort(nums, start, left - 1);
		fast_sort(nums, left + 1, end);
	}

};



int main() {
	vector<int> nums = { 1,33,445,23,12,234,4,333,447 };
	my_sort s;
	for (int num : nums) {
		cout << " " << num;
	}
	cout << "≈≈–Ú«∞" << endl;
	s.buddle_sort(nums);
	for (int num : nums) {
		cout << " " << num;
	}
	cout << "≈≈–Ú∫Û" << endl;
	return 0;
}