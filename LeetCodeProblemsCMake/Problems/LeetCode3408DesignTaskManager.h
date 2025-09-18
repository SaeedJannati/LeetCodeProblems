//
// Created by saeed on 9/18/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE3408DESIGNTASKMANAGER_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE3408DESIGNTASKMANAGER_H
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class LeetCode3408DesignTaskManager {
    class TaskManager {
    private:
        unordered_map<int, int> taskPersonMap{};
        unordered_map<int, int> taskPriorityMap{};
        map<int, set<int> > orderedTasks{};

    public:
        TaskManager(vector<vector<int> > &tasks) {
            for (auto &task: tasks) {
                add(task[0], task[1], task[2]);
            }
        }

        void add(int userId, int taskId, int priority) {
            if (!orderedTasks.contains(priority)) {
                orderedTasks[priority] = {};
            }
            orderedTasks[priority].insert(taskId);
            taskPersonMap[taskId] = userId;
            taskPriorityMap[taskId] = priority;
        }

        void edit(int taskId, int newPriority) {
            auto personId = taskPersonMap[taskId];
            rmv(taskId);
            add(personId, taskId, newPriority);
        }

        void rmv(int taskId) {
            auto priority = taskPriorityMap[taskId];
            orderedTasks[priority].erase(taskId);
            if (orderedTasks[priority].empty()) {
                orderedTasks.erase(priority);
            }
            taskPersonMap.erase(taskId);
            taskPriorityMap.erase(taskId);
        }

        int execTop() {
            if (orderedTasks.empty()) {
                return -1;
            }
            auto taskId = *orderedTasks.rbegin()->second.rbegin();
            auto personId = taskPersonMap[taskId];
            rmv(taskId);
            return personId;
        }
    };
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE3408DESIGNTASKMANAGER_H
