package Problems;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class LeetCode2196CreateBinaryTreeFromDescriptions {

    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> set = new HashMap<>();
        Set<Integer> parentSet = new HashSet<>();
        Set<Integer> childrenSet = new HashSet<>();
        for (var description : descriptions) {
            if (!set.containsKey(description[0])) {
                var parent = new TreeNode(description[0]);
                set.put(description[0], parent);
            }
            var parent = set.get(description[0]);
            parentSet.add(description[0]);
            if (!set.containsKey(description[1])) {
                var child = new TreeNode(description[1]);
                set.put(description[1], child);
            }
            var child = set.get(description[1]);
            parentSet.remove(description[1]);
            childrenSet.add(description[1]);
            if (description[2] == 1) {
                parent.left = child;
                continue;
            }
            parent.right = child;
        }
        for (Integer i : parentSet) {
            if (!childrenSet.contains(i))
                return set.get(i);
        }
        return null;
    }


    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

}
