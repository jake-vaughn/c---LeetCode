#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		map<int, int> m;
		int i = 0;
		for (auto &num : nums)
		{
			if (m.count(num))
			{
				return {m[num], i};
			}
			m[target - num] = i;
			i++;
		}
		return {};
	}
};

int main()
{
	Solution solution;
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;

	vector<int> sol = solution.twoSum(nums, target);

	std::copy(sol.begin(), sol.end(),
			  std::ostream_iterator<int>(std::cout, " "));

	return 0;
}