#pragma once
#include"L.h"
//8
class chartosigninterger {
public:
    int myAtoi(string s) {
        long result = 0;
        int signsecond = 1;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case '0':
                result = result * 10;
                count++;
                break;
            case '1':
                result = result * 10 + 1;
                count++;
                break;
            case '2':
                result = result * 10 + 2;
                count++;
                break;
            case '3':
                result = result * 10 + 3;
                count++;
                break;
            case '4':
                result = result * 10 + 4;
                count++;
                break;
            case '5':
                result = result * 10 + 5;
                count++;
                break;
            case '6':
                result = result * 10 + 6;
                count++;
                break;
            case '7':
                result = result * 10 + 7;
                count++;
                break;
            case '8':
                result = result * 10 + 8;
                count++;
                break;
            case '9':
                result = result * 10 + 9;
                count++;
                break;
            case ' ':
                if (count > 0) return result * signsecond;
                break;
            case '+':
                if (count != 0) {
                    return result * signsecond;
                }
                count++;
                break;
            case '-':
                if (count == 0) {
                    signsecond = -1;
                }
                else {
                    return result * signsecond;
                }
                count++;
                break;
            default:
                return result * signsecond;
            }
            if (result * signsecond < INT_MIN) return INT_MIN;
            if (result * signsecond > INT_MAX) return INT_MAX;
        }
        return result * signsecond;
    }
// code short 
class chartosigninterger1 {
public:
    int myAtoi(string s) {
        long ans = 0;
        int sign = 1;
        int i = 0;

        while (s[i] == ' ') i++;//ignore whitesapce to while 2 can run

        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < s.length() && isdigit(s[i])) { // while 2, isdigit return vd '2'->true will return 0.
            ans = ans * 10 + (s[i] - '0'); // watch ascii 
            if (ans * sign <= INT_MIN) return INT_MIN;
            if (ans * sign >= INT_MAX) return INT_MAX;
            i++;
        }
        return ans * sign;
    }
};