package Problems;

import java.util.ArrayList;

public class LeetCode3499MaximizeActiveSectionWithTradeI {
    public int maxActiveSectionsAfterTrade(String s) {
        ArrayList<Integer> sections = new ArrayList<>();
        char lastChar = 0;
        int sectionLength = 0;
        var charArray = s.toCharArray();
        int maxLength = 0;
        int currentLength = 0;
        for (var c : charArray) {
            if (c == '1') {
                maxLength++;
            }
            if (lastChar == c) {
                sectionLength++;
            } else {
                if (sectionLength > 0) {
                    sections.add(sectionLength);
                }
                sectionLength = 1;
            }
            lastChar = c;

        }
        sections.add(sectionLength);
        int length = sections.size();
        boolean startsWithZero = charArray[0] == '0';
        int maxDelta = 0;
        for (int i = startsWithZero ? 1 : 2, e = length - 1; i < e; i = i + 2) {
            currentLength = (i > 0 ? sections.get(i - 1) : 0) + (i < length - 1 ? sections.get(i + 1) : 0);
            maxDelta = Math.max(maxDelta, currentLength);
        }
        maxLength += maxDelta;
//        if (startsWithZero) {
//            currentLength = sections.get(0) + (length > 1 ? sections.get(1) : 0);
//            maxLength = Math.max(maxLength, currentLength);
//        }
//        if (charArray[charArray.length - 1] == '0') {
//            currentLength= sections.get(length-1) + (length>1?sections.get(length-2) : 0);
//            maxLength = Math.max(maxLength, currentLength);
//        }
        return maxLength;
    }
}
