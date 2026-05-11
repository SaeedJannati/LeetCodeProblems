package Problems;

public class LeetCode23259MaximumEnergyBoostFromTwoDrinks {
    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
        int length = energyDrinkA.length;
        long[] dpA = new long[length];
        long[] dpB = new long[length];
        dpA[0] = energyDrinkA[0];
        dpB[0] = energyDrinkB[0];
        for (int i = 1; i < length; i++) {
            dpA[i] = Math.max(dpA[i - 1], i > 1 ? dpB[i - 2] : 0) + energyDrinkA[i];
            dpB[i] = Math.max(dpB[i - 1], i > 1 ? dpA[i - 2] : 0) + energyDrinkB[i];
        }
        return Math.max(dpA[length - 1], dpB[length - 1]);
    }
}
