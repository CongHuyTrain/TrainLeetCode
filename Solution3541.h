#pragma once
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> storage;
        int maxVowel = 0, maxConsonant = 0;
        for (auto c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                storage[c]++;
                maxVowel = max(maxVowel, storage[c]);
            }
            else {
                storage[c]++;
                maxConsonant = max(maxConsonant, storage[c]);
            }
        }
        return maxVowel + maxConsonant;
    }
};