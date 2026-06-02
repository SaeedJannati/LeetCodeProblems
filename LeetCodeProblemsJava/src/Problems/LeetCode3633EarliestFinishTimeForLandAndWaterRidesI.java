package Problems;

import java.util.Arrays;

public class LeetCode3633EarliestFinishTimeForLandAndWaterRidesI {

    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int minEndTime = Integer.MAX_VALUE;
        int currentEndTimeLandFirst = 0;
        int currentEndTimeWaterFirst = 0;
        for (int i = 0, e = landStartTime.length; i < e; i++) {
            for (int j = 0, f = waterStartTime.length; j< f; j++) {
                currentEndTimeLandFirst = landStartTime[i] + landDuration[i];
                currentEndTimeLandFirst = currentEndTimeLandFirst > waterStartTime[j] ? currentEndTimeLandFirst + waterDuration[j] : waterStartTime[j] + waterDuration[j];
                minEndTime = Math.min(minEndTime, currentEndTimeLandFirst);
                currentEndTimeWaterFirst = waterStartTime[j] + waterDuration[j];
                currentEndTimeWaterFirst = currentEndTimeWaterFirst > landStartTime[i] ? currentEndTimeWaterFirst + landDuration[i] : landStartTime[i] + landDuration[i];
                minEndTime = Math.min(minEndTime, currentEndTimeWaterFirst);
            }
        }
        return minEndTime;


    }
}
