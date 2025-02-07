//
// Created by saeed on 2/7/25.
//

#include "LeetCode3160FindTheNumberOfDistinctColorsAmongTheBalls.h"

#include <unordered_map>

#include "../Auxilary/Auxilaries.h"

std::vector<int> LeetCode3160FindTheNumberOfDistinctColorsAmongTheBalls::queryResults(int limit,
                                                                                      std::vector<std::vector<int> > &queries) {
    std::unordered_map<int, int> map{};
    std::unordered_map<int, int> colours{};
    std::vector<int> results{};
    results.reserve(queries.size());
    for (int i = 0; i < queries.size(); i++) {
        if (!map.contains(queries[i][0])) {
            map[queries[i][0]]=queries[i][1];
            if (!colours.contains(queries[i][1]))
                colours[queries[i][1]] = 0;
            colours[queries[i][1]]++;
            results.push_back(colours.size());
            continue;
        }
        colours[map[queries[i][0]]]--;
        if (colours[map[queries[i][0]]] == 0)
            colours.erase(map[queries[i][0]]);
        if (!colours.contains(queries[i][1]))
            colours[queries[i][1]] = 0;
        colours[queries[i][1]]++;
        map[queries[i][0]]=queries[i][1];
        results.push_back(colours.size());
    }
    return results;
}

void LeetCode3160FindTheNumberOfDistinctColorsAmongTheBalls::Run() {
    int limit=4;
     std::vector<std::vector<int> > queries={{1,4},{2,5},{1,3},{3,4}};
    Auxilaries::PrintVector(queryResults(limit, queries));
}
