//
// Created by saeed on 8/28/25.
//

#include "LeetCode3446SortMatrixByDiagonals.h"

#include <algorithm>

#include "../Auxilary/Auxilaries.h"
using namespace std;

vector<vector<int> > LeetCode3446SortMatrixByDiagonals::sortMatrix(vector<vector<int> > &grid) {
    vector<int> nums{};
    int length = static_cast<int>(grid.size());
    for (int i = 0; i < length; i++) {
        if (i > 0) {
            nums = {};
            for (int j = 0; j < length - i; j++) {
                nums.push_back(grid[j][j + i]);
            }
            ranges::sort(nums);
            for (int j = 0; j < length - i; j++) {
                grid[j][j + i] = nums[j];
            }
        }
        nums = {};
        for (int j = 0; j < length - i; j++) {
            nums.push_back(grid[j + i][j]);
        }
        ranges::sort(nums, [](int a, int b) {return a>b;});
        for (int j = 0; j < length - i; j++) {
            grid[j + i][j] = nums[j];
        }
    }
    return grid;
}

void LeetCode3446SortMatrixByDiagonals::Run() {
    vector<vector<int> > grid =
        // {{8,2,3},{9,1,7},{4,5,6}};
         {{-1,-2,-3},{-3,-3,-2},{-4,-4,0}};
    sortMatrix(grid);
    Auxilaries::PrintVector2D(grid);

}
