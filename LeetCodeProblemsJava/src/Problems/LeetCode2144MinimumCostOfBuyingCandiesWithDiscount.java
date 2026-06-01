package Problems;

import java.util.Arrays;

public class LeetCode2144MinimumCostOfBuyingCandiesWithDiscount {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int totalSpent = 0;
        int index = cost.length - 1;
        while (index >= 0) {
            totalSpent += cost[index];
            index--;
            if (index < 0)
                break;
            totalSpent += cost[index];
            index--;
            if (index < 0)
                break;
            index--;
        }
        return totalSpent;
    }
}
