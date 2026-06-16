package Problems;

import java.util.ArrayDeque;
import java.util.Deque;

public class LeetCode3612ProcessStringWithSpecialOperationsI {
    public String processStr(String s) {
        Deque<Character> deque = new ArrayDeque<>();
        boolean forward = true;
        for (char c : s.toCharArray()) {
            switch (c) {
                case '*':
                    if (forward) {
                        deque.pollLast();
                    } else {
                        deque.pollFirst();
                    }
                    break;
                case '%':
                    forward = !forward;
                    break;
                case '#':
                    Deque<Character> copy = new ArrayDeque<>(deque);
                    deque.addAll(copy);
                    break;
                default:
                    if (forward) {
                        deque.addLast(c);
                    } else {
                        deque.addFirst(c);
                    }
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!deque.isEmpty()) {
            if (forward) {
                sb.append(deque.pollFirst());
            } else {
                sb.append(deque.pollLast());
            }
        }
        return sb.toString();
    }
}
