package Problems;

import java.util.ArrayList;
import java.util.List;

public class LeetCode797AllPathsFromSourcetoTarget {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
       int length = graph.length;
       List<List<Integer>> result = new ArrayList<>();
       boolean[] visited = new boolean[length];
       List<Integer> path = new ArrayList<>(List.of(0));
       dfs(graph,result,path,length,visited,0);
       return result;
    }
    void dfs(int[][] graph,List<List<Integer>> res,List<Integer> currentPath,int length,boolean[] visited,int node){
        if(node==length-1){
            List<Integer> newPath = new ArrayList<>(currentPath);
            res.add(newPath);
            return;
        }
        for (int neighbour:graph[node]){
            if(visited[neighbour])
                continue;
            visited[neighbour]=true;
            currentPath.add(neighbour);
            dfs(graph,res,currentPath,length,visited,neighbour);
            currentPath.remove(Integer.valueOf(neighbour));
            visited[neighbour]=false;
        }


    }
}
