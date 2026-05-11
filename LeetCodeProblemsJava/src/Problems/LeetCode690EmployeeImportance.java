package Problems;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LeetCode690EmployeeImportance {

    public class Employee {
        public int id;
        public int importance;
        public List<Integer> subordinates;
    }

    ;

    public int getImportance(List<Employee> employees, int id) {
        HashMap<Integer, Integer> importanceMap = new HashMap<>();
        HashMap<Integer, List<Integer>> subordinates = new HashMap<>();
        for (Employee employee : employees) {
            importanceMap.put(employee.id, employee.importance);
            if (employee.subordinates == null)
                continue;
            subordinates.put(employee.id, employee.subordinates);
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.add(id);
        int aggregatedImportance = 0;
        while (!queue.isEmpty()) {
            var employee = queue.poll();
            aggregatedImportance += importanceMap.get(employee);
            if (!subordinates.containsKey(employee)) {
                continue;
            }
            queue.addAll(subordinates.get(employee));
        }
        return aggregatedImportance;
    }

}
