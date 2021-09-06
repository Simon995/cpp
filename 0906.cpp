//求数组中比左边元素都大同时比右边元素都小的元素，返回这些元素的索引
//要求时间复杂度O(N)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> find(vector<int> nums) {
    vector<int> res;
    int n = nums.size();
    vector<int> left_max(n, INT_MIN);
    vector<int> right_min(n, INT_MAX);
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i - 1], nums[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        right_min[i] = min(right_min[i + 1], nums[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        if (left_max[i] < nums[i] && nums[i] < right_min[i]) {
            res.push_back(i);
        }
    }
    return res;
}
int main()
{
    vector<int> arr = {2,3,1,8,9,20,12};
    auto res = find(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
}