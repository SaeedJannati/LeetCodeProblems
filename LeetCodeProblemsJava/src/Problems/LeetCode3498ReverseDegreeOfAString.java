package Problems;

public class LeetCode3498ReverseDegreeOfAString {
    public int reverseDegree(String s) {
        var charArray = s.toCharArray();
        int result = 0;
        for(int i=0,e=charArray.length;i<e;i++){
            result+= (26-charArray[i]+'a')*(i+1);
        }
        return result;
    }
}
