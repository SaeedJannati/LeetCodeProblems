package Problems;

import java.util.Arrays;

public class LeetCode1386CinemaSeatAllocation extends  BaseProblem {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Arrays.sort(reservedSeats, (a, b) -> Integer.compare(a[0], b[0]));
        int[] row=new int[11];
        int result= n<<1;
        int currentRow=1;
        int delta=0;
        for(var coor:reservedSeats){

            if(coor[0]==currentRow){
                row[coor[1]]=1;
                continue;
            }


            delta=calcDelta(row);
            currentRow=coor[0];

            result-= (2-delta);
            for(int j=1;j<=10;j++){
                row[j]=0;
            }
            row[coor[1]]=1;
        }
        delta= calcDelta(row);
        result-= (2-delta);
        return result;
    }
private int calcDelta(int[] row){
        int delta=0;
    boolean[] groupInRow={true,true,true};
    if(row[2]==1 || row[3]==1){
        groupInRow[0]=false;
    }
    if(row[4]==1 || row[5]==1){
        groupInRow[1]=false;
        groupInRow[0]=false;
    }
    if(row[6]==1 || row[7]==1){
        groupInRow[2]=false;
        groupInRow[1]=false;
    }
    if(row[8]==1 || row[9]==1){
        groupInRow[2]=false;
    }
    if(groupInRow[0]&&groupInRow[1]){
        groupInRow[1]=false;
    }
    if(groupInRow[2]&&groupInRow[1]){
        groupInRow[1]=false;
    }
    for(var group: groupInRow){
        if(group){
            delta++;
        }
    }
    return delta;
}
    @Override
    public void Run() {
        int n=3;
        int[][] reservedSeats = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
        System.out.println(maxNumberOfFamilies(n,reservedSeats));
    }
}
