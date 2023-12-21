// LeetCode_problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    for (int i = m; i < nums1.size(); ++i)
    {
        nums1[i] = nums2[i-m];
    }

    std::sort(nums1.begin(), nums1.end());
}

int removeElement_2(std::vector<int>& nums1, const int& val)
{
    //std::remove_if(nums1.begin(), nums1.end(), [val](int& m) {return val == m; });
    auto it = std::remove(nums1.begin(), nums1.end(), val);
    return it - nums1.begin();
}

int removeElement(std::vector<int>& nums1, const int& val)
{
    //std::remove_if(nums1.begin(), nums1.end(), [val](int& m) {return val == m; });
    auto it = std::remove_if(nums1.begin(), nums1.end(), [val](int n) {return val == n; });
    return it - nums1.begin();
}

int removeDuplicates_2(std::vector<int>& nums)
{
    int m = nums[0];
    auto it = std::remove_if(nums.begin() + 1, nums.end(), [&m](int& n) {bool ret = n == m; m = n; return ret; });
    std::unordered_set<int> s( nums.begin(), nums.end() );
    int length = s.size();
    return length;
}

int removeDuplicates_3(std::vector<int>& nums)
{
    std::set<int> s(nums.begin(), nums.end());
    int i = 0;
    for (auto it : s)
    {
        nums[i++] = it;
    }
    return s.size();
}


int removeDuplicates(std::vector<int>& nums)
{
    int curPos = 0;
    for(int i = 1; i < nums.size(); ++i)
    {
        if (nums[curPos] != nums[i])
        {
            nums[++curPos] = nums[i];
        }
    }
    return curPos + 1;
}


int removeDuplicates_twice_2(std::vector<int>& nums)
{
    int currentPos = 0;

    for (int i = 1; i < nums.size(); ++i)
    {
        if (currentPos == 0 || nums[currentPos] != nums[i])
        {
            nums[++currentPos] = nums[i];

            if ((i < nums.size() - 1) && (nums[i] == nums[i + 1]))
            {
                currentPos++;
                nums[currentPos] = nums[i];
                i++;
            }
        }
    }
    return currentPos + 1;
}

int removeDuplicates_twice(std::vector<int>& nums) {
    int currentPos = -1;

    for (int i = 0; i < nums.size(); i++) 
    {
        if (currentPos == -1 || nums[currentPos] != nums[i]) 
        {
            nums[++currentPos] = nums[i];

            if ((i < nums.size() - 1) && (nums[i] == nums[i + 1])) {
                currentPos++;
                nums[currentPos] = nums[i];
                i++;
            }
        }
    }
    return currentPos + 1;
}

int majorityElement_2(std::vector<int>& nums) {
    std::unordered_map<int,int> count;
    int max = -9999;
    int maj_elem =0;

    for (int& n : nums)
    {
        count[n]++;
    }

    for (auto& c : count)
    {
        if (c.second > max)
        {
            max = c.second;
            maj_elem = c.first;
        }
    }
    return maj_elem;
}


void rotate_2(std::vector<int>& nums, int k) {
    std::vector<int> m(nums.size(), 0);

    for (int i = 0; i < nums.size(); ++i)
    {
        m[(i+k) % nums.size()] = nums[i];
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        nums[i] = m[i];
    }
}

// slow !!!
void rotate_3(std::vector<int>& nums, int k) {    

    int temp;
    int temp_2;

    for (int j = 0; j < k; ++j)
    {
        temp_2 = nums[nums.size() - 1];
        for (int i = 0; i < nums.size(); ++i)
        {
            temp = nums[i];
            nums[i] = temp_2;
            temp_2 = temp;
        }
    }
}

int maxProfit_2(std::vector<int>& prices)
{
    int max = -9999;
    int buy = 0;
    int sell = 0;

    for (int i = 0; i < prices.size(); ++i)
    {
        for (int j = i + 1; j < prices.size(); ++j)
        {
            int profit = prices[j] - prices[i];
            if (profit > max)
            {
                max = profit;
                buy = i;
                sell = j;
            }
        }
    }
    //std::cout << "profit: " << prices[sell] - prices[buy] << std::endl;

    int profit = prices[sell] - prices[buy];
    if (profit < 0) return 0;
    return  profit;
}

//better solution
// The idea is that if there is a negative profit then there is a smaller prize, so move the buy pointer to that position.
// If there is no higher selling prize, we found the max profit already.
// We don't need the min/max buy/sell positions, only the max profit
int maxProfit(std::vector<int>& prices)
{
    int buy = 0;
    int sell = 1;
    int profit = 0;

    while (sell < prices.size())
    {
        int current_profit = prices[sell] - prices[buy];
        if (current_profit < 0) // there is a smaller number than current 
        {
            buy = sell;
        }
        else
        {
            if (current_profit > profit)
            {
                profit = current_profit;
            }
        }
        sell++;

    }

    return  profit;
}

std::vector<int> twoSum_2(std::vector<int>& numbers, int target)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                std::vector<int> temp{ i + 1, j + 1 };
                return temp;
            }
        }
    }
    return std::vector<int>();
}


std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                std::vector<int> temp{ i + 1, j + 1 };
                return temp;
            }
            while (numbers[i] == numbers[j])
            {
                j++;
                i++;
            }
        }
    }
    return std::vector<int>();
}

// too slow
int maxArea_2(std::vector<int>& height) 
{
    int max_area = 0;

    for (int l = 0; l < height.size(); ++l)
    {
        for (int r = 1; r < height.size(); ++r)
        {
            int area = (r - l) * std::min(height[l], height[r]);
            if (area > max_area)
            {
                max_area = area;
            }
        }
    }

    return max_area;
}

// 
int maxArea(std::vector<int>& height)
{
    int max_area = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right)
    {
        int area = (right - left) * std::min(height[left], height[right]);
        max_area = std::max(max_area, area);

        if (height[left] < height[right])
        {
            left++;
        }
        else if (height[left] > height[right])
        {
            right--;
        }
        else
        {
            left++;
            right--;
        }
    }

    return max_area;
}

int sum(std::vector<int> nums, int start, int end)
{
    int sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += nums[i];
    }
    return sum;
}

int minSubArrayLen_2(int target, std::vector<int>& nums)
{
    for (int length = 1; length < nums.size(); ++length)
    {
        for (int start_pos = 0; (start_pos + length) < nums.size() + 1; ++start_pos)
        {
            int part_sum = sum(nums, start_pos, start_pos + length);
            if (part_sum >= target)
            {
                return length;
            }
        }
    }
    return 0;
}


int minSubArrayLen_tooslow(int target, std::vector<int>& nums)
{
    for (int length = 1; length < nums.size(); ++length)
    {
        for (int start_pos = 0; (start_pos + length) < nums.size() + 1; ++start_pos)
        {
            int part_sum = sum(nums, start_pos, start_pos + length);
            if (part_sum >= target)
            {
                return length;
            }
        }
    }
    return 0;
}


//start left with two pointer at pos 0
//increase one pointer till sum > target
//if greater target safe size
//move left one step to the right
//repeat
int minSubArrayLen(int target, std::vector<int>& nums)
{
    int index_left = 0;
    int index_right = 1;
    int shortest = 0;
    int temp_sum = 9999999;

    while (index_right != nums.size() - 1 && temp_sum > target)
    {
        temp_sum = sum(nums, index_left, index_right);
        if (temp_sum < target)
        {
            index_right++;
        }
        else
        {
            if ((index_right - index_left) > shortest)
            {
                shortest = (index_right - index_left);
            }
            index_left++;
        }
    }

    return shortest;
}


int main()
{
    /*
    std::vector<int> nums1 = { 1, 3, 7, 0, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = { 1, 2, 2, 9};
    int n = 4;

    //merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
    {
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl << nums1.size();
    */
    /*
    std::vector<int> nums1 = { 1, 3, 7, 3, 4};
    int val = 3;
    int length = removeElement(nums1, val);
    std::cout << "length: " << length << nums1.size();
    */
    /*
    std::vector<int> nums = { 1, 3, 3, 7, 7, 7, 7, 9,9,9,9};
    int length = removeDuplicates(nums);
    std::cout << "length: " << length << std::endl;
    */

    //    std::vector<int> nums = {0,0,1,1,1,1,2,3,3};
    //    int length = removeDuplicates_twice(nums);
    //    std::vector<int> nums = { 1,1,1,2,3 };
    //    int length = removeDuplicates_twice(nums);
    //    std::cout << "length: " << length << std::endl;

    //    std::vector<int> nums = { 0,0,1,1,1,1,1,3,3 };
    //    int maj_elem = majorityElement(nums);
    //    std::cout << "maj_elem: " << maj_elem << std::endl;

        //std::vector<int> nums = { 1,2,3,4,5,6,7 };
    //    std::vector<int> nums = { -1, -100, 3, 99 };

    //    rotate(nums, 2);
     //   for (int i = 0; i < nums.size(); i++)
     //   {
     //       std::cout << nums[i] << " ";
     //   }

        //std::vector<int> prices = { 7, 1, 5, 3, 6, 4 };
        //std::vector<int> prices = { 1 };
    //std::vector<int> prices = { 2, 1, 2, 1, 0, 1, 2 };
    //std::cout << maxProfit(prices) << std::endl;

    //std::vector<int> nums = { 0, 0, 0, 1, 2, 3, 5, 8, 9, 21 };
    //std::vector<int> nums = { 0, 0, 3, 4 };
    //std::vector<int> temp = twoSum(nums, 7);
    //for (int i = 0; i < temp.size(); i++)
    //{
    //   std::cout << temp[i] << " ";
    //}

    std::vector<int> nums = { 2, 3, 1, 2, 4, 3 };
    std::cout <<  minSubArrayLen(7, nums ) << std::endl;
}
