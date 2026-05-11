class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] < 10) {
                result.push_back(nums[i]);
            }
            else {

                vector<int> temp;
                int n = nums[i];

                while (n > 0) {
                    temp.push_back(n % 10);
                    n /= 10;
                }

                reverse(temp.begin(), temp.end());

                for (int digit : temp) {
                    result.push_back(digit);
                }
            }
        }

        return result;
    }
};