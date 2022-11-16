#include <iostream>
#include <unordered_map>
#include <vector>
#include <iterator>

using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
	{
		int n = 0;
		int m = 0;
		int l = 0;
		int r = 0;

		int target = (nums1.size() + nums2.size()) / 2;

		while ((n + m) <= target)
		{
			l = r;
			if (n >= nums1.size())
			{
				r = nums2[m];
				m++;
			}
			else if (m >= nums2.size())
			{
				r = nums1[n];
				n++;
			}
			else if (nums1[n] < nums2[m])
			{
				r = nums1[n];
				n++;
			}
			else
			{
				r = nums2[m];
				m++;
			}
		}

		if ((nums1.size() + nums2.size()) % 2) // If total size is odd
		{
			return double(r);
		}
		else
		{
			return double(l + r) / 2;
		}

		return double{0};
	}
};

int main()
{
	vector<int> nums1 = {};
	vector<int> nums2 = {2, 3};

	Solution solution;
	double sol = solution.findMedianSortedArrays(nums1, nums2);

	cout << sol;
	return 0;
}