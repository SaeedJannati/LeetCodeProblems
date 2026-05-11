package Problems;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Stack;

public class LeetCode2553SeparateTheDigitsInAnArray extends BaseProblem {
    public int[] separateDigits(int[] nums) {
        ArrayList<Integer> list = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        for (int num : nums) {
            stack.clear();
            while (num > 0) {
                stack.push(num % 10);
                num /= 10;
            }
            while (!stack.isEmpty()) {
                list.add(stack.pop());
            }
        }
        return list.stream().mapToInt(Integer::intValue).toArray();
    }

    @Override
    public void Run() {
        int[] nums = {13, 25, 83, 77};
        Auxileries.Print(separateDigits(nums));
    }
}
