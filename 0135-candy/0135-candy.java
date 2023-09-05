class Solution {
    public int candy(int[] arr) {
        // Step 1: Check for empty input
        if (arr == null || arr.length == 0) {
            return 0;
        }

        // Step 2: Initialize chocolates array
        int[] chocolates = new int[arr.length];
        chocolates[0] = 1; // First person always gets 1 chocolate

        // Step 3: First pass (Left to Right)
        // Start from the second person
        for (int i = 1; i < arr.length; i++) {
            // If this person has a higher rating than the one before
            if (arr[i] > arr[i - 1]) {
                // Give one more chocolate than the person on the left
                chocolates[i] = chocolates[i - 1] + 1;
            } else {
                // If not, just give one chocolate
                chocolates[i] = 1;
            }
        }

        // Step 4: Second pass (Right to Left)
        // Initialize result with the last person's chocolates
        int result = chocolates[arr.length - 1];

        // Start from the second last person
        for (int i = arr.length - 2; i >= 0; i--) {
            // Assume 1 chocolate for current person initially
            int cur = 1;

            // If this person has a higher rating than the one after
            if (arr[i] > arr[i + 1]) {
                // Give one more chocolate than the person on the right
                cur = chocolates[i + 1] + 1;
            }

            // Add to result the max chocolates for this person
            // considering both neighbors
            result += Math.max(cur, chocolates[i]);

            // Update the chocolates for this person
            chocolates[i] = cur;
        }

        // Step 5: Return Result
        return result;
    }
}
