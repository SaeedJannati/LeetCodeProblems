package Problems;

import java.util.Arrays;


public class LeetCode2126DestroyingAsteroids {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long currentMass = mass;
        for (int asteroid : asteroids) {
            if (asteroid > currentMass) {
                return false;
            }
            currentMass += asteroid;
        }
        return true;
    }
}
