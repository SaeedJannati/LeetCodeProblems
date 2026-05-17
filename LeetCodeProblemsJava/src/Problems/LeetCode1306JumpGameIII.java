package Problems;

public class LeetCode1306JumpGameIII {
    void dfs(int[] arr, boolean[] visited, int length, int index, boolean[] reached) {
        if (reached[0])
            return;
        int next = index + arr[index];
        if (next < length && next >= 0) {
            if (!visited[next]) {
                if (arr[next] == 0) {
                    reached[0] = true;
                    return;
                }
                visited[next] = true;
                dfs(arr, visited, length, next, reached);
                visited[next] = false;
            }
        }
        next = index - arr[index];
        if (next < length && next >= 0) {
            if (!visited[next]) {
                if (arr[next] == 0) {
                    reached[0] = true;
                    return;
                }
                visited[next] = true;
                dfs(arr, visited, length, next, reached);
                visited[next] = false;
            }
        }
    }

    public boolean canReach(int[] arr, int start) {
        if (arr[start] == 0)
            return true;
        int length = arr.length;
        boolean[] visited = new boolean[length];
        boolean[] reached = new boolean[1];
        visited[start] = true;
        dfs(arr, visited, length, start, reached);
        return reached[0];
    }
}
