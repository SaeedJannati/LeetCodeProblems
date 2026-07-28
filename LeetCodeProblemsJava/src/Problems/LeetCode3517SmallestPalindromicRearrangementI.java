package Problems;

import java.util.ArrayList;

public class LeetCode3517SmallestPalindromicRearrangementI {
    public String smallestPalindrome(String s) {
        int len = s.length();
        char[] arr = s.toCharArray();
        ArrayList<Character> list = new ArrayList<>(len/2+1);
        for(int i=0;i<len/2;i++){
            list.add(arr[i]);
        }
        list.sort(Character::compareTo);
        StringBuilder sb = new StringBuilder();
        for(var c:list){
            sb.append(c);
        }
        if (len%2==1){
            sb.append(arr[len/2]);
        }
        for(int i=list.size()-1;i>=0;i--){
            sb.append(list.get(i));
        }
        return sb.toString();
    }
}
