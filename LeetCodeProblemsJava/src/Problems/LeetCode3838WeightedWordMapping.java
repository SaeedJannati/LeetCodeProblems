package Problems;

public class LeetCode3838WeightedWordMapping {
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder sb = new StringBuilder();
        int currentWeight = 0;
        for (String word: words) {
            currentWeight = 0;
            for (var c: word.toCharArray()) {
                currentWeight += weights[c - 'a'];
            }
            currentWeight%=26;
            currentWeight=25-currentWeight;
            char res=(char)('a'+currentWeight);
            sb.append(res );
        }
        return sb.toString();
    }
}
