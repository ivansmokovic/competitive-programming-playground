package arrays;

import java.util.HashMap;

public class PalindromePermutation {

    public static void main(String[] args) {
        var query = "Tcat aco";
        query = query.toLowerCase();

        var counter = new HashMap<Character, Integer>();

        for (char c : query.toCharArray()) {
            if (c == ' ') continue;
            var count = counter.getOrDefault(c, 0);
            counter.put(c, ++count);

        }

        int num_odd = 0;
        for (var value : counter.values()) {
            if (value % 2 == 1) ++num_odd;
            if (num_odd > 1) {
                System.out.println("False");
                return;
            }
        }

        System.out.println("True");
        return;
    }
}