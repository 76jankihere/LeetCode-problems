class Solution {
    public String makeLargestSpecial(String s) {
        List<String> parts = new ArrayList<>();
        int count = 0, start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') count++;
            else count--;

            // When count == 0, we've found a top-level special substring
            if (count == 0) {
                // Recursively sort the inner part (strip leading '1' and trailing '0')
                String inner = makeLargestSpecial(s.substring(start + 1, i));
                parts.add("1" + inner + "0");
                start = i + 1;
            }
        }

        // Sort in descending order for lexicographically largest result
        parts.sort(Collections.reverseOrder());
        StringBuilder sb = new StringBuilder();
        for (String part : parts) sb.append(part);
        return sb.toString();
    }
}
