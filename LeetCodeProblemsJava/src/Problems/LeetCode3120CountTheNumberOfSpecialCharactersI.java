package Problems;

import java.util.HashSet;

public class LeetCode3120CountTheNumberOfSpecialCharactersI extends BaseProblem {
    public int numberOfSpecialChars(String word) {
        HashSet<Integer> usedChars = new HashSet<Integer>();
        HashSet<Integer> specialChars = new HashSet<>();
        for (int i = 0, e = word.length(); i < e; i++) {
            char c = word.charAt(i);
            if (c > 'Z') {
                if (usedChars.contains(c +'A' - 'a')) {
                    specialChars.add((int)c);
                }
            }
            else{
                if(usedChars.contains(c +'a' - 'A')){
                    specialChars.add(c +'a' - 'A');
                }
            }
            usedChars.add((int) (c));
        }
        return specialChars.size();
    }

    @Override
    public void Run() {
        String s="zZ";
        IO.println(numberOfSpecialChars(s));
    }
}
