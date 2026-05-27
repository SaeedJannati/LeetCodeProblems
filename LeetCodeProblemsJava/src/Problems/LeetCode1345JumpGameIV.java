package Problems;

import java.util.*;

public class LeetCode1345JumpGameIV extends BaseProblem {
    public int minJumps(int[] arr) {
        HashMap<Integer, ArrayList<Integer>> links = new HashMap<>();
        int length = arr.length;
        for (int i = 0; i < length; i++) {
            if(i>0 && i<length-1){
                if(arr[i]==arr[i+1] && arr[i]==arr[i-1]){
                    continue;
                }
            }
            links.putIfAbsent(arr[i], new ArrayList<>());
            links.get(arr[i]).add(i);
        }
        boolean[] visited = new boolean[length];
        Queue<Integer> current = new LinkedList<>();
        Queue<Integer> next = new LinkedList<>();
        visited[0] = true;
        current.add(0);
        int step = 1;
        int nodeToCheck = 0;
        while (!current.isEmpty()) {
            while (!current.isEmpty()) {
                var node = current.poll();
                nodeToCheck = node + 1;
                if (nodeToCheck < length) {
                    if (!visited[nodeToCheck]) {
                        visited[nodeToCheck] = true;
                        if (nodeToCheck == length - 1) {
                            return step;
                        }
                        next.add(nodeToCheck);
                    }
                }
                nodeToCheck = node - 1;
                if (nodeToCheck >= 0) {
                    if (!visited[nodeToCheck]) {
                        visited[nodeToCheck] = true;
                        if (nodeToCheck == length - 1) {
                            return step;
                        }
                        next.add(nodeToCheck);
                    }
                }
                if(!links.containsKey(arr[node]))
                    continue;
                for (var toCheck : links.get(arr[node])) {
                    if (!visited[toCheck]) {
                        visited[toCheck] = true;
                        if (toCheck == length - 1) {
                            return step;
                        }
                        next.add(toCheck);
                    }
                }
                links.remove(arr[node]);

            }
            ++step;
            while (!next.isEmpty()) {
                current.add(next.poll());
            }
        }
        return length - 1;
    }

    @Override
    public void Run() {
        int[] arr={7,6,9,6,9,6,9,7};
        System.out.println(minJumps(arr));
    }
}
