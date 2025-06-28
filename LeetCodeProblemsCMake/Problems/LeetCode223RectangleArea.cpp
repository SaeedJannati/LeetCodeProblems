//
// Created by saeed on 6/28/25.
//

#include "LeetCode223RectangleArea.h"

#include <algorithm>

int LeetCode223RectangleArea::computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area {0};
    area+=(ax2-ax1)*(ay2-ay1);
    area+=(bx2-bx1)*(by2-by1);
    int startX=std::max(ax1,bx1);
    int endX=std::min(ax2,bx2);
    if (endX<startX)
        return area;
    int startY=std::max(ay1,by1);
    int endY=std::min(ay2,by2);
    if (endY<startY)
        return area;
    int overlapArea = (endX-startX)*(endY-startY);
    if (overlapArea>0)
        area-=overlapArea;
    return area;
}
