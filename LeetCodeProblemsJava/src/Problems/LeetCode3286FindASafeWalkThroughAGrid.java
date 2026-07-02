package Problems;

import java.util.List;
import java.util.PriorityQueue;

public class LeetCode3286FindASafeWalkThroughAGrid extends  BaseProblem {
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int height = grid.size();
        int width = grid.get(0).size();
        int[][] distances = new int[height][width];
        int[][] directions = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        boolean[][] visited = new boolean[height][width];
        PriorityQueue<int[]> dijkstraHeap = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        dijkstraHeap.add(new int[]{grid.get(0).get(0), 0});
        int row, col, newRow, newCol, distance;
        while (!dijkstraHeap.isEmpty()) {
            var current = dijkstraHeap.poll();
            distance = current[0];
            row = current[1] / width;
            col = current[1] % width;
            if(visited[row][col]){
                continue;
            }
            visited[row][col] = true;
            distances[row][col] = distance;
            for (var direction : directions) {
                newRow =row + direction[0];
                if (newRow < 0 || newRow >= height){
                    continue;
                }
                newCol = col + direction[1];
                if (newCol < 0 || newCol >= width){
                    continue;
                }
                if(visited[newRow][newCol]){
                    continue;
                }
                distance= current[0]+grid.get(newRow).get(newCol);
                dijkstraHeap.add(new int[]{distance,newRow*width+newCol});
            }
        }
        return distances[height-1][width-1] < health;
    }

    @Override
    public void Run() {
        List<List<Integer>> grid = List.of(
                List.of(0, 1, 1, 0, 0, 0),
                List.of(1, 0, 1, 0, 0, 0),
                List.of(0, 1, 1, 1, 0, 1),
                List.of(0, 0, 1, 0, 1, 0)
        );
        int health=3;
        System.out.println(findSafeWalk(grid, health));
    }
}
