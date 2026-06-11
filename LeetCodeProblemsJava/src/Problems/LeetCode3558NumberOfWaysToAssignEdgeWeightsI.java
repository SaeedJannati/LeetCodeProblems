package Problems;

import java.util.ArrayList;
import java.util.HashMap;

public class LeetCode3558NumberOfWaysToAssignEdgeWeightsI extends  BaseProblem {
    public int assignEdgeWeights(int[][] edges) {
        HashMap<Integer, ArrayList<Integer>> adjPlus=new HashMap<>(){};
        for(var edge:edges){
            if(!adjPlus.containsKey(edge[0])){
                adjPlus.put(edge[0], new ArrayList<>());
            }
            adjPlus.get(edge[0]).add(edge[1]);
            if (!adjPlus.containsKey(edge[1])){
                adjPlus.put(edge[1], new ArrayList<>());
            }
            adjPlus.get(edge[1]).add(edge[0]);
        }
        int[] maxDepth=new int[]{0};
        boolean[] visited=new boolean[adjPlus.size()+1];
        visited[1]=true;
        dfs(adjPlus,visited,maxDepth,1,0);
        long mod = 1000000007;
        long ans=1;
        for (int  i = 0; i < maxDepth[0]-1; i++) {
            ans*=2;
            ans%=mod;
        }
        return (int)ans;
    }
    private void dfs(HashMap<Integer, ArrayList<Integer>> adjPlus,boolean[] visited,int[] maxDepth,int node,int depth){
        maxDepth[0]=Math.max(maxDepth[0],depth);
        if(!adjPlus.containsKey(node)){
            return;
        }
        for(var neighbour:adjPlus.get(node)){
            if(visited[neighbour]){
                continue;
            }
            visited[neighbour]=true;
            dfs(adjPlus,visited,maxDepth,neighbour,depth+1);
        }
    }

    @Override
    public void Run() {

        int[][] edges=new int[][]{{1,2},{1,3},{3,4},{3,5}};
        System.out.println(assignEdgeWeights(edges));
    }
}
