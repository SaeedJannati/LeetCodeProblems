//
// Created by saeed on 5/19/25.
//

#ifndef GEEKSFORGEEKSTRAVELLINGSALESMANPROBLEM_H
#define GEEKSFORGEEKSTRAVELLINGSALESMANPROBLEM_H
#include <vector>

#include "BaseProblem.h"


class GeeksForGeeksTravellingSalesmanProblem: BaseProblem {
private:
    int tsp(std::vector<std::vector<int>>& cost);
    public:
    void Run() override;
};



#endif //GEEKSFORGEEKSTRAVELLINGSALESMANPROBLEM_H
