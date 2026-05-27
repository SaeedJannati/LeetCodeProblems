package Problems;

import java.util.*;

public class LeetCode629MinimumJumpstoReachEndviaPrimeTeleportation extends BaseProblem {
    public int minJumps(int[] nums) {
        int length = nums.length;
        if (length == 1) return 0;
        int max = 0;
        for (int k : nums) {
            max = Math.max(max, k);
        }
        int[] sieve = new int[max + 1];
        for (int i = 2; i <= max; i++) {
            sieve[i] = i;
        }
        for (int i = 2; i <= max; i++) {
            if (sieve[i] == i) {
                for (long j = (long) i * (long) i; j <= max; j += i) {
                    if (sieve[(int) j] == j) {
                        sieve[(int) j] = i;
                    }
                }
            }
        }
        HashSet<Integer> allPrimes = new HashSet<>();
        for (int i = 1; i <= max; i++) {
            if (sieve[i] == i) {
                allPrimes.add(i);
            }
        }
        HashSet<Integer> primes = new HashSet<>();
        for (var num : nums) {
            if (allPrimes.contains(num)) {
                primes.add(num);
            }
        }

        HashMap<Integer, ArrayList<Integer>> links = new HashMap<>();
        int numToCheck = 0;
        int sieveNum = 0;
        for (int i = 0; i < length; i++) {
            numToCheck = nums[i];
            while (numToCheck > 1) {
                sieveNum = sieve[numToCheck];
                links.putIfAbsent(sieveNum, new ArrayList<>());
                links.get(sieveNum).add(i);
                while (numToCheck > 1 && numToCheck % sieveNum == 0) {
                    numToCheck /= sieveNum;
                }
            }
        }
        int distance = 0;
        boolean[] visited = new boolean[length];
        Queue<Integer> currentQueue = new LinkedList<>();
        Queue<Integer> nextQueue = new LinkedList<>();
        HashMap<Integer, Integer> primeJumps = new HashMap<>();
        currentQueue.add(0);
        visited[0] = true;
        int nodeToAdd = 0;
        int next = -1;
        int befor = -1;
        while (!currentQueue.isEmpty()) {
            distance++;
            while (!currentQueue.isEmpty()) {
                int node = currentQueue.poll();
                if (primes.contains(nums[node])) {
                    for (var newNode : links.get(nums[node])) {
                        if (visited[newNode]) {
                            continue;
                        }
                        if (newNode == length - 1) {
                            return distance;
                        }
                        visited[newNode] = true;
                        if (primeJumps.containsKey(nums[newNode])) {
                            int current = primeJumps.get(nums[newNode]);
                            primeJumps.put(current, Math.max(current, newNode));
                        } else {
                            primeJumps.put(nums[newNode], newNode);
                        }
                    }
                }
                nodeToAdd = node + 1;
                if (nodeToAdd == length - 1) {
                    return distance;
                }
                if (nodeToAdd < length) {
                    if (!visited[nodeToAdd]) {
                        visited[nodeToAdd] = true;
                        nextQueue.add(nodeToAdd);

                    }
                }
                nodeToAdd = node - 1;
                if (nodeToAdd >= 0) {
                    if (!visited[nodeToAdd]) {
                        visited[nodeToAdd] = true;
                        nextQueue.add(nodeToAdd);
                    }
                }

            }
            for (var entry : primeJumps.entrySet()) {
                nextQueue.add(entry.getValue());
            }
            primeJumps.clear();
            while (!nextQueue.isEmpty()) {
                currentQueue.add(nextQueue.poll()) ;
            }
        }
        return distance;
    }


    @Override
    public void Run() {
        int[] nums = new int[]{1, 2, 4, 6};
        System.out.println(minJumps(nums));

    }
}
