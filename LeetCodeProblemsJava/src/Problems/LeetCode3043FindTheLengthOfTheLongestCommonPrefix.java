package Problems;

import java.util.HashMap;

public class LeetCode3043FindTheLengthOfTheLongestCommonPrefix {

    class TrieNode {
        char value;
        HashMap<Character, TrieNode> children;
        int depth;

        TrieNode() {
            this.value = 0;
            this.depth = 0;
            children = new HashMap<>();
        }

        TrieNode(char value, int depth) {
            this.value = value;
            this.depth = depth;
            children = new HashMap<>();
        }
    }

    class Trie {
        TrieNode root;

        public Trie() {
            root = new TrieNode();
        }

        Trie(int[] values) {
            root = new TrieNode();
            for (var value : values) {
                insert(getDigits(value));
            }
        }

        void insert(String key) {
            var node = root;
            var newNode = new TrieNode();
            for (char c : key.toCharArray()) {
                if (!node.children.containsKey(c)) {
                    newNode = new TrieNode(c, node.depth + 1);
                    node.children.put(c, newNode);
                }
                node = node.children.get(c);
            }
        }

        int search(String key) {
            var node = root;
            for (char c : key.toCharArray()) {
                if (!node.children.containsKey(c)) {
                    return node.depth;
                }
                node = node.children.get(c);
            }
            return key.length();
        }
    }

    public int longestCommonPrefix(int[] arr1, int[] arr2) {

        var trie = new Trie(arr1);
        int maxPrefixLength = 0;
        for (var value : arr2) {
            maxPrefixLength= Math.max(trie.search(getDigits(value)), maxPrefixLength);
        }
        return maxPrefixLength;
    }

    String getDigits(int a) {
        StringBuilder sb = new StringBuilder();
        while (a > 0) {
            sb.append(a % 10);
            a /= 10;
        }
        return sb.reverse().toString();
    }
}
