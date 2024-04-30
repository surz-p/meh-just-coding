/**
Problem Statement:

Given a string, find the length of the longest substring in it with no more than K distinct characters.

You can assume that K is less than or equal to the length of the given string.

Example 1:
Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".

Example 2:
Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".

Example 3:
Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".

also available at: https://www.naukri.com/code360/problems/longest-substring-with-at-most-k-distinct-characters_2221410
with non-self gmail account log in
**/

int kDistinctChars(int k, string &str)
{
    int windowStart = 0, windowEnd = 0, maxLength = 0;
        unordered_map<char, int> freq;
        int distinctElements = 0;

        for (windowEnd = 0; windowEnd < str.size(); windowEnd++) {
            if (freq[str[windowEnd]] == 0) {
                distinctElements++;
            }
            freq[str[windowEnd]]++;
            if (distinctElements <= k)
                maxLength = max(maxLength, windowEnd - windowStart + 1);

            while (distinctElements > k) {
                freq[str[windowStart]]--;
                if (freq[str[windowStart]] == 0) {
                    distinctElements--;
                }
                windowStart++;
            }

        }
        return maxLength;
}
