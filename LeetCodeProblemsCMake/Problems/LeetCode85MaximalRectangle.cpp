//
// Created by saeed on 1/7/25.
//

#include "LeetCode85MaximalRectangle.h"

#include <iostream>
#include <ostream>
#include <stack>

int LeetCode85MaximalRectangle::maximalRectangle(std::vector<std::vector<char> > &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    if (rows == 1 && cols == 1) {
        return matrix[0][0] == '1' ? 1 : 0;
    }
    std::vector<std::vector<int> > heights;
    heights.reserve(rows);
    std::stack<std::pair<int, int> > stack;
    for (int i = 0; i < rows; i++) {
        heights.emplace_back(cols, 0);
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[i][j] = i == 0 ? 1 : 1 + heights[i - 1][j];
            }
        }
    }

    int maxArea = 0;
    int area = 0;
    int right = 0;
    int left = 0;
    for (int i = 0; i < rows; i++) {
        stack = {};
        std::vector<int> lesserLeftRow(cols, -1);
        for (int j = 0; j < cols; j++) {
            while (!stack.empty() && stack.top().first >= heights[i][j]) {
                stack.pop();
            }
            if (!stack.empty()) {
                lesserLeftRow[j] = stack.top().second;
            }
            stack.emplace(heights[i][j], j);
        }
        stack = {};
        std::vector<int> lesserRightRow(cols, -1);
        for (int j = cols - 1; j >= 0; j--) {
            while (!stack.empty() && stack.top().first >= heights[i][j]) {
                stack.pop();
            }
            if (!stack.empty()) {
                lesserRightRow[j] = stack.top().second;
            }
            stack.emplace(heights[i][j], j);
        }
        for (int j = 0; j < cols; j++) {
            right = lesserRightRow[j] == -1 ? cols - 1 : lesserRightRow[j] - 1;
            left = lesserLeftRow[j] == -1 ? 0 : lesserLeftRow[j] + 1;
            area = heights[i][j] * (right - left + 1);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    return maxArea;
}

void LeetCode85MaximalRectangle::Run() {
    // std::vector<std::vector<char> > matrix = {
    //     {'1', '1', '1', '1', '1'},
    //     {'1', '1', '1', '1', '1'},
    //     {'1', '1', '1', '1', '1'},
    //     {'1', '1', '1', '1', '1'},
    //     {'1', '1', '1', '1', '1'}
    // };
    // {{'0', '1'}};
    int rows = 500;
    int cols = 500;

    std::vector<std::vector<char> > matrix(rows, std::vector<char>(cols, '1'));

    std::cout << maximalRectangle(matrix) << std::endl;
}
