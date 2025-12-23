//
// Created by saeed on 12/23/25.
//

#include "LeetCode2054TwoBestNonOverlappingEvents.h"

#include <algorithm>
using namespace std;

void buildSegment(vector<vector<int> > &events, vector<int> &segmentTree, int node, int start, int end) {
    if (start == end) {
        segmentTree[node] = events[start][2];
        return;
    }
    int mid = (end + start) >> 1;
    buildSegment(events, segmentTree, node * 2, start, mid);
    buildSegment(events, segmentTree, node * 2 + 1, mid + 1, end);
    segmentTree[node] = max(segmentTree[node * 2], segmentTree[node * 2 + 1]);
}

int query(vector<int> &segmentTree, int start, int end, int left, int right, int node) {
    if (right < start || left > end)
        return 0;
    if (left <= start && end <= right) {
        return segmentTree[node];
    }
    int mid = (start + end) >> 1;
    return max(query(segmentTree, start, mid, left, right, node * 2),
               query(segmentTree, mid + 1, end, left, right, node * 2 + 1));
}

int LeetCode2054TwoBestNonOverlappingEvents::maxTwoEvents(vector<vector<int> > &events) {
    ranges::sort(events, [](const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });
    int length = static_cast<int>(events.size());
    vector<int> segmentTree(length * 4, 0);
    buildSegment(events, segmentTree, 1, 0, length - 1);
    int result = 0;
    for (int i = 0; i < length - 1; i++) {
        int begin = i + 1;
        int end = length - 1;
        int mid{};
        int res = length;
        while (begin <= end) {
            mid = (begin + end) >> 1;
            if (events[mid][0] > events[i][1]) {
                res = min(res, mid);
                end = mid - 1;
                continue;
            }
            begin = mid + 1;
        }
        result=max(result, events[i][2]);
        if (res != length) {
            result=max(result, events[i][2] + query(segmentTree, 0, length - 1, res, length - 1, 1));
        }
    }
    result=max(result, events[length-1][2]);
    return result;
}
