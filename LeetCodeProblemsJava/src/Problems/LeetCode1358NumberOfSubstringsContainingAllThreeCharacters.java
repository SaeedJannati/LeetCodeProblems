package Problems;

import java.util.HashMap;

public class LeetCode1358NumberOfSubstringsContainingAllThreeCharacters extends BaseProblem {
    public int numberOfSubstrings(String s) {
        int[] occurrences = new int[3];
        int result = 0;
        int secondPointer = 0;
        int length = s.length();
        char[] chars = s.toCharArray();
        occurrences[chars[0] - 'a']++;
        for (int i = 0; i < length - 2; i++) {
            if (i > 0) {
                occurrences[chars[i - 1] - 'a']--;
            }
            while ((secondPointer < length - 1) && (occurrences[0] == 0 || occurrences[1] == 0 || occurrences[2] == 0)) {
                secondPointer++;
                occurrences[chars[secondPointer] - 'a']++;
            }
            if (occurrences[0] > 0 && occurrences[1] > 0 && occurrences[2] > 0)
                result += length - secondPointer;
        }
        return result;
    }

    @Override
    public void Run() {
        String s = "abcabc";
        int result = numberOfSubstrings(s);
        System.out.println(result);
    }
}
