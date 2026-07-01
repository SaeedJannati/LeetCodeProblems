package Problems;

import java.util.*;

public class LeetCode2812FindTheSafestPathInAGrid extends BaseProblem {
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        if (grid.get(0).get(0) == 1)
            return 0;
        int length = grid.size();
        if (grid.get(length - 1).get(length - 1) == 1)
            return 0;
        boolean[][] visited = new boolean[length][length];
        int[][] manhattan = new int[length][length];
        Queue<Integer> currentLayer = new LinkedList<>();
        Queue<Integer> nextLayer = new LinkedList<>();
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (grid.get(i).get(j) == 1) {
                    currentLayer.add(i * length + j);
                    visited[i][j] = true;
                }
            }
        }
        int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int distance = 1;
        while (!currentLayer.isEmpty()) {
            while (!currentLayer.isEmpty()) {
                var next = currentLayer.poll();
                int row = next / length;
                int col = next % length;
                int newRow, newCol;
                for (var direction : directions) {
                    newRow = row + direction[0];
                    if (newRow < 0 || newRow >= length)
                        continue;
                    newCol = col + direction[1];
                    if (newCol < 0 || newCol >= length)
                        continue;
                    if (visited[newRow][newCol])
                        continue;
                    visited[newRow][newCol] = true;
                    manhattan[newRow][newCol] = distance;
                    nextLayer.add(newRow * length + newCol);
                }
            }
            distance++;
            while (!nextLayer.isEmpty()) {
                currentLayer.add(nextLayer.poll());
            }
        }
        visited = new boolean[length][length];
        int[][] maxDistances = new int[length][length];
        PriorityQueue<int[]> dijkstraQueue = new PriorityQueue<>((a, b) -> Integer.compare(b[0], a[0]));
        maxDistances[0][0] = manhattan[0][0];
        dijkstraQueue.add(new int[]{manhattan[0][0], 0});
        int row, col, newRow, newCol;
        while (!dijkstraQueue.isEmpty()) {
            var current = dijkstraQueue.poll();
            row = current[1] / length;
            col = current[1] % length;
            if (visited[row][col])
                continue;
            maxDistances[row][col] = current[0];
            visited[row][col] = true;
            for (var direction : directions) {
                newRow = row + direction[0];
                if (newRow < 0 || newRow >= length)
                    continue;
                newCol = col + direction[1];
                if (newCol < 0 || newCol >= length)
                    continue;
                if (visited[newRow][newCol])
                    continue;
                distance = Math.min(current[0], manhattan[newRow][newCol]);
                dijkstraQueue.add(new int[]{ distance,newRow * length + newCol,});
            }
        }

        return maxDistances[length - 1][length - 1];
    }


    @Override
    public void Run() {
        List<List<Integer>> grid = List.of(
                List.of(0, 0, 0, 1),
                List.of(0, 0, 0, 0),
                List.of(0, 0, 0, 0),
                List.of(1, 0, 0, 0)
        );
        System.out.println(maximumSafenessFactor(grid));
    }
}
