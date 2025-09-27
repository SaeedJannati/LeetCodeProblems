//
// Created by saeed on 9/27/25.
//

#include "LeetCode812LargestTriangleArea.h"

#include <cmath>
#include <complex>
using namespace std;



double LeetCode812LargestTriangleArea::largestTriangleArea(vector<vector<int> > &points) {
    double maxArea{};
    double area{};
    int length = points.size();
    pair<double,double> first{};
    pair<double,double> second{};
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < length; k++) {
                first=make_pair(points[i][0]-points[j][0],points[i][1]-points[j][1]);
                second=make_pair(points[i][0]-points[k][0], points[i][1]-points[k][1]);
                area=.5*fabs(first.first*second.second-first.second*second.first);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }
    return maxArea;
}
