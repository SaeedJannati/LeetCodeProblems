package Problems;

import java.util.Arrays;
import java.util.Comparator;

public class LeetCode1665MinimumInitialEnergyToFinishTasks {
    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks,
                Comparator
                        .<int[]>comparingInt(a -> a[0] - a[1])
                        .thenComparing((a, b) -> Integer.compare(b[1], a[1]))
        );
        int used=0;
        int current=0;
        int delta=0;
        for( var task : tasks ) {
            delta=task[1]-current;
            if(delta>0){
                used+=delta;
                current+=delta;
            }
            current-=task[0];
        }
        return used;
    }
}
