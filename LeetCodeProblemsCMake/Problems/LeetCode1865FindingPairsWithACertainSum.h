//
// Created by saeed on 7/6/25.
//

#ifndef LEETCODE1865FINDINGPAIRSWITHACERTAINSUM_H
#define LEETCODE1865FINDINGPAIRSWITHACERTAINSUM_H
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <bits/ranges_algo.h>


class LeetCode1865FindingPairsWithACertainSum {
    class FindSumPairs {
    private:
        std::unordered_map<int, int> _nums2Dict{};
        std::vector<int> _nums1{};
        std::vector<int> _nums2{};
    public:
        FindSumPairs(std::vector<int> &nums1, std::vector<int> &nums2) {
            _nums1 = nums1;
            _nums2 = nums2;
            std::ranges::sort(_nums1);
            for (auto num: nums2) {
                _nums2Dict[num]++;
            }
        }

        void add(int index, int val) {
            _nums2Dict[ _nums2[index]]--;
            _nums2[index]+=val;
            _nums2Dict[ _nums2[index]]++;
        }

        int count(int tot) {
            int result{};
            for (auto num:_nums1) {
                if (num>=tot)
                    break;
                if (!_nums2Dict.contains(tot-num))
                    continue;
                result += _nums2Dict[tot-num];
            }
            return result;
        }
    };
};


#endif //LEETCODE1865FINDINGPAIRSWITHACERTAINSUM_H
