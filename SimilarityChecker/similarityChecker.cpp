#include <iostream>
#include <string>
using namespace std;

class Similarity {
public:
    int checker(string str1, string str2) {
        if (str1.length() == str2.length()) return 60;
        if (str1.length() * 2 <= str2.length()) return 0;
        if (str1.length() >= str2.length() * 2) return 0;
    }
};