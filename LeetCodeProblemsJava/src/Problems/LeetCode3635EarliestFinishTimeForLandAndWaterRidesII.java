package Problems;

public class LeetCode3635EarliestFinishTimeForLandAndWaterRidesII {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int minLandTime= Integer.MAX_VALUE;
        int minLandActivity= Integer.MAX_VALUE;
        for(int i=0,e=landStartTime.length; i<e;i++) {
            minLandActivity=Math.min(minLandActivity,landStartTime[i]+landDuration[i]);
        }
        for(int i=0,e=waterStartTime.length; i<e;i++) {
            if(waterStartTime[i]<=minLandActivity){
                minLandTime= Math.min(minLandTime,minLandActivity+waterDuration[i]);
                continue;
            }
            minLandTime=Math.min(minLandTime,waterStartTime[i]+waterDuration[i]);
        }
        int minWaterActivity=Integer.MAX_VALUE;
        int minWaterTime=Integer.MAX_VALUE;
        for(int i=0,e=waterDuration.length; i<e;i++) {
            minWaterActivity=Math.min(minWaterActivity,waterStartTime[i]+waterDuration[i]);
        }
        for(int i=0,e=landStartTime.length; i<e;i++) {
            if(landStartTime[i]<=minWaterActivity){
                minWaterTime= Math.min(minWaterTime,minWaterActivity+landDuration[i]);
                continue;
            }
            minWaterTime=Math.min(minWaterTime,landStartTime[i]+landDuration[i]);
        }
        return Math.min(minLandTime,minWaterTime);
    }
}
