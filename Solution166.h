#pragma once
#include <string>
#include <unordered_map>
#include <cstdlib> // for llabs
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)  return "0";
        string result = "";
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        long long divisor = llabs(denominator);
        long long dividend = llabs(numerator);
        result += to_string(dividend / divisor);
        long long remain = dividend % divisor;
        if (remain == 0) return result;
        result += ".";
        unordered_map< long long, int> storage;
        while (remain != 0) {
            if (storage.count(remain)) {
                result.insert(storage[remain], "(");
                result += ")";
                break;
            }
            storage[remain] = result.size();
            remain *= 10;
            result += to_string(remain / divisor);
            remain %= divisor;
        }
        return result;
    }
};