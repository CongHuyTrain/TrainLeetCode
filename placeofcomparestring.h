#pragma once
#include"L.h"
class placeofcomparestring {
    public:
        int strStr(string haystack, string needle) {
            string comparee = ""; //doan cat ra tu haystack de so sanh
            for (int i = 0; i < haystack.size(); i++) {
                if (needle[0] == haystack[i]) {  //ki tu dau giong ko
                    //copy ko du chuoi con lai
                    if (haystack.size() - i >= needle.size()) { 
                        comparee = haystack.substr(i, needle.size()); // sao chep chuoi tu vi tri va kich co
                        if (needle == comparee)   return i; //tra ve vi tri 
                    }
                    else {
                        return -1;
                    }
                }

            }
            return -1;
        }
};
//java cua ngf khac
//class Solution {
//    public int strStr(String haystack, String needle) {
//        int haylength = haystack.length();
//        int needlelength = needle.length();
//        if (haylength < needlelength)
//            return -1;
//        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
//            int j = 0;
//            while (j < needle.length() && haystack.charAt(i + j) == needle.charAt(j))
//                j++;
//            if (j == needle.length()) {
//                return i;
//            }
//        }
//        return -1;
//    }
//}
