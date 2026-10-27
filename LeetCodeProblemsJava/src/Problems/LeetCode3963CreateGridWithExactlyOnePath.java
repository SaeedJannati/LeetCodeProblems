package Problems;

public class LeetCode3963CreateGridWithExactlyOnePath {
    public String[] createGrid(int m, int n) {
          String[] grid = new String[m];
          StringBuilder firstRow = new StringBuilder();
          StringBuilder secondRow = new StringBuilder();
          firstRow.append(".");
          for(int i=0;i<n-1;i++){
              firstRow.append(".");
              secondRow.append("#");
          }
          secondRow.append(".");
          String firstRowStr = firstRow.toString();
          String secondRowStr = secondRow.toString();
          grid[0]=firstRowStr;
          for(int i=1;i<m;i++){
              grid[i]=secondRowStr;
          }
          return grid;
    }
}
