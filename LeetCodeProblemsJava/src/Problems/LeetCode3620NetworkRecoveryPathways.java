package Problems;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

public class LeetCode3620NetworkRecoveryPathways {
    public int findMaxPathScore(int[][] edges, boolean[] online, long k) {
        int maxEdge = 0;
        int n = 0;
        HashMap<Integer, ArrayList<Integer[]>> adjPlus = new HashMap<>();
        for (var edge : edges) {
            if (!online[edge[0]] || !online[edge[1]])
                continue;
            if (!adjPlus.containsKey(edge[0])) {
                adjPlus.put(edge[0], new ArrayList<>());
            }
            adjPlus.get(edge[0]).add(new Integer[]{edge[1], edge[2]});
            maxEdge = Math.max(maxEdge, edge[2]);
        }
        n= online.length;
        int begin = 0;
        int end = maxEdge;
        int mid = 0;
        int result = -1;
        boolean[] visited = new boolean[n];
        long[] distances = new long[n];
        int answer = -1;
        while (begin <= end) {
            mid = (begin + end) >> 1;
            result = checkIfPathExists(adjPlus, n, k, visited, distances, mid);
            if (result != -1) {
                answer = Math.max(answer, result);
                begin = mid + 1;
                continue;
            }
            end = mid - 1;
        }
        return answer;
    }

    private int checkIfPathExists(HashMap<Integer, ArrayList<Integer[]>> adjPlus, int n, long k, boolean[] visited, long[] distances, int minCost) {
        for (int i = 0; i < n; i++) {
            visited[i] = false;
            distances[i] = -1;
        }
        PriorityQueue<int[]> dijkstraHeap = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        int minUsed = Integer.MAX_VALUE;
        dijkstraHeap.add(new int[]{0, 0,minUsed});
        while (!dijkstraHeap.isEmpty()) {
            var current = dijkstraHeap.poll();
            if (visited[current[1]])
                continue;
            visited[current[1]] = true;
            distances[current[1]] = current[0];
            minUsed = Math.min(minUsed, current[2]);
            if (!adjPlus.containsKey(current[1]))
                continue;
            for (var edge : adjPlus.get(current[1])) {
                if (visited[edge[0]])
                    continue;
                if (edge[1] < minCost)
                    continue;
                dijkstraHeap.add(new int[]{current[0] + edge[1],edge[0] , edge[1]});
            }
        }
        if (distances[n - 1] == -1) {
            return -1;
        }
        if (distances[n - 1] > k) {
            return -1;
        }
        return minUsed;
    }
}
