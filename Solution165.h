#pragma once
#include<string>
using namespace std;
//165. Compare Version Numbers
//Solved
//Medium
//Given two version strings, version1 and version2, compare them.A version string consists of revisions separated by dots '.'.
//The value of the revision is its integer conversion ignoring leading zeros.
//To compare version strings, compare their revision values in left - to - right order.
//If one of the version strings has fewer revisions, treat the missing revision values as 0.
//Return the following :
//If version1 < version2, return -1.
//    If version1 > version2, return 1.
//    Otherwise, return 0.
//   Example 1:
//Input: version1 = "1.2", version2 = "1.10"
//Output : -1
//Explanation :
//    version1's second revision is "2" and version2's second revision is "10" : 2 < 10, so version1 < version2.
//    Example 2 :
//    Input : version1 = "1.01", version2 = "1.001"
//   Output : 0
//    Explanation :
//    Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
//    Example 3 :
//    Input : version1 = "1.0", version2 = "1.0.0.0"
//    Output : 0
//    Explanation :
//    version1 has less revisions, which means every missing revision are treated as "0".
//Constraints:
//
//1 <= version1.length, version2.length <= 500
//version1 and version2 only contain digits and '.'.
//version1 and version2 are valid version numbers.
//All the given revisions in version1 and version2 can be stored in a 32 - bit integer.
class Solution {
public:
    int compareVersion(string version1, string version2) {
        const int n1 = version1.size(), n2 = version2.size();
		int v1 = 0, v2 = 0; // storage the current revision number
		for (int i = 0, j = 0; i < n1 || j < n2; i++, j++) { // loop for each revision( declare )
			while (i < n1 && version1[i] != '.') { // loop vs1 till end or '.'
				v1 = 10 * v1 + (version1[i++] - '0'); // calculate the revision number
            }
			while (j < n2 && version2[j] != '.') { // loop vs2 till end or '.'
                v2 = 10 * v2 + (version2[j++] - '0'); // //
            }
            if (v1 < v2)    return -1;
            else if (v1 > v2)   return 1;
			// if equal, continue to next revision( reset v1 and v2 to 0 )
            v1 = 0; 
            v2 = 0;
        }
        return 0;
    }
};