package Problems;

public class LeetCode1967NumberOfStringsThatAppearAsSubstringsInWord {
    public int numOfStrings(String[] patterns, String word) {
        int result=0;
        for(var pattern:patterns){
            if(word.contains(pattern)){
                result++;
            }
        }
        return result;
    }
}
