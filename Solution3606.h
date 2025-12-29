#pragma once
#include <algorithm>
#include<vector>
using namespace std;
//3606. Coupon Code Validator
//Solved
//Easy
//Topics
//premium lock icon
//Companies
//Hint
//You are given three arrays of length n that describe the properties of n coupons : code, businessLine, and isActive.
// The ith coupon has :
//
//code[i] : a string representing the coupon identifier.
//businessLine[i] : a string denoting the business category of the coupon.
//isActive[i] : a boolean indicating whether the coupon is currently active.
//A coupon is considered valid if all of the following conditions hold :
//
//code[i] is non - empty and consists only of alphanumeric characters(a - z, A - Z, 0 - 9) and underscores(_).
//businessLine[i] is one of the following four categories : "electronics", "grocery", "pharmacy", "restaurant".
//isActive[i] is true.
//Return an array of the codes of all valid coupons, sorted first by their businessLine in the order : "electronics",
// "grocery", "pharmacy", "restaurant", and then by code in lexicographical(ascending) order within each category.
//Example 1 :
//	Input : code = ["SAVE20", "", "PHARMA5", "SAVE@20"], businessLine = ["restaurant", "grocery", "pharmacy", "restaurant"], 
// isActive = [true, true, true, true]
//	Output : ["PHARMA5", "SAVE20"]
//	Explanation :
//	First coupon is valid.
//	Second coupon has empty code(invalid).
//	Third coupon is valid.
//	Fourth coupon has special character @ (invalid).
//	Example 2:
//Input: code = ["GROCERY15", "ELECTRONICS_50", "DISCOUNT10"], businessLine = ["grocery", "electronics", "invalid"], 
// isActive = [false, true, true]
//Output : ["ELECTRONICS_50"]
//Explanation :
//	First coupon is inactive(invalid).
//	Second coupon is valid.
//	Third coupon has invalid business line(invalid).
//	Constraints :
//	n == code.length == businessLine.length == isActive.length
//	1 <= n <= 100
//	0 <= code[i].length, businessLine[i].length <= 100
//	code[i] and businessLine[i] consist of printable ASCII characters.
//	isActive[i] is either true or false.

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> result;
        vector<string> ele;
        vector<string> gro;
        vector<string> pha;
        vector<string> res;
        for (int i = 0; i < code.size(); i++) {
            if (isActive[i] == false)   continue;
            string c = code[i];
            bool invalid = false;
            if (c.empty())    invalid = true;
            for (int j = 0; j < c.size(); j++) {
                if ((c[j] < 'a' || c[j] > 'z') && (c[j] < 'A' || c[j] > 'Z')
                    && (c[j] < '0' || c[j] > '9') && c[j] != '_') {
                    invalid = true;
                    break;
                }
            }
            if (invalid) continue;
            if (businessLine[i] == "electronics")    ele.push_back(code[i]);
            else if (businessLine[i] == "grocery") gro.push_back(code[i]);
            else if (businessLine[i] == "pharmacy") pha.push_back(code[i]);
            else if (businessLine[i] == "restaurant") res.push_back(code[i]);
        }
        sort(ele.begin(), ele.end());
        sort(gro.begin(), gro.end());
        sort(pha.begin(), pha.end());
        sort(res.begin(), res.end());
        if (!ele.empty()) result.insert(result.end(), ele.begin(), ele.end());
        if (!gro.empty()) result.insert(result.end(), gro.begin(), gro.end());
        if (!pha.empty()) result.insert(result.end(), pha.begin(), pha.end());
        if (!res.empty()) result.insert(result.end(), res.begin(), res.end());
        return result;
    }
};