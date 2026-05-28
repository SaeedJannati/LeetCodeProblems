package Problems;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class LeetCode3093LongestCommonSuffixQueries extends BaseProblem {
    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        var trie=new Trie(wordsContainer);
        int queryLen=wordsQuery.length;
        int[] res=new int[queryLen];
        for(int i=0;i<queryLen;i++){
            res[i]=trie.findLongestCommonSuffix(wordsQuery[i]);
        }
        return res;
    }
    class TrieNode{
        public Character value;
        public Map<Character,TrieNode> children;
        public boolean end;
        public int depth;
        public int index;
        public int nearestWordIndex=-1;
        public int nearestWordDepth=-1;
        public TrieNode(){
            children=new HashMap<>();
        }
        public TrieNode(Character value,int depth,int index){
            this.value = value;
            this.depth = depth;
            this.index = index;
            this.children = new HashMap<Character,TrieNode> ();
            this.end = true;
        }
        public TrieNode(char value,int depth){
            this.value = value;
            this.depth = depth;
            this.children = new HashMap<Character,TrieNode> ();
        }
    }
    class Trie{
        Set<String> words=new HashSet<>();
        public TrieNode root;
        public Trie(){
            root = new TrieNode();
        }
        public Trie(String[] words){
            root = new TrieNode();
            for(int i=0;i<words.length;i++){
                this.insert(words[i],i);
            }
        }
        public void insert(String word,int index){
            if(words.contains(word)){
                return;
            }
            words.add(word);
            var node = root;
            TrieNode newNode=null;
            for(int i=word.length()-1;i>=0;i--){
                if(!node.children.containsKey(word.charAt(i))){
                    newNode = new TrieNode(word.charAt(i),node.depth+1);
                    node.children.put(word.charAt(i),newNode);
                }
                node = node.children.get(word.charAt(i));
            }
            node.end = true;
            node.index = index;
        }
        public int findLongestCommonSuffix(String word){
                var node = root;
                for(int i=word.length()-1;i>=0;i--){
                    if(!node.children.containsKey(word.charAt(i))){
                        break;
                    }
                    node = node.children.get(word.charAt(i));
                }
                findFirstWord(node);
                return node.nearestWordIndex;
        }
        private void findFirstWord(TrieNode node){
            if(node.nearestWordIndex!=-1){
                    return;
            }
            if(node.end){
                node.nearestWordDepth=node.depth;
                node.nearestWordIndex=node.index;
                return;
            }
            int minDepth=Integer.MAX_VALUE;
            int minIndex=-1;
            for(var child:node.children.values()){
                findFirstWord(child);
                if(child.nearestWordDepth<minDepth){
                    minDepth=child.nearestWordDepth;
                    minIndex=child.nearestWordIndex;
                }else if(child.nearestWordDepth==minDepth){
                    minIndex= Math.min(minIndex,child.nearestWordIndex);
                }
            }
            node.nearestWordIndex=minIndex;
            node.nearestWordDepth=minDepth;
        }
    }

    @Override
    public void Run() {
        String[] wordsContainer={"abcd","bcd","xbcd"};
        String[] wordsQuery={"cd","bcd","xyz"};
        Auxileries.Print(stringIndices(wordsContainer, wordsQuery));
    }
}
