#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Similarity {
public:
    const int MAX_LENGTH_POINT = 60;
    int checker(string str1, string str2) {
        int result = getLengthPoint(str1.length(), str2.length());
        return result;
    }

    int alphachecker(string str1, string str2) {
        int totalCnt = 0;
        int sameCnt = 0;
        int alphabetstr1[26]{ 0 };
        int alphabetstr2[26]{ 0 };
        for (int i = 0; i < str1.length(); i++) {
            int index = str1[i] - 'A';
            if (alphabetstr1[index] == 0) {
                alphabetstr1[index] = 1;
            }
        }
        for (int j = 0; j < str2.length(); j++) {
            int index = str2[j] - 'A';
            if (alphabetstr2[index] == 0) {
                alphabetstr2[index] = 1;
            }
        }

        for (int alphabetIndex = 0; alphabetIndex < 26; alphabetIndex++)
        {
            if (alphabetstr1[alphabetIndex] == 1 || alphabetstr2[alphabetIndex] == 1) {
                totalCnt++;
                if (alphabetstr1[alphabetIndex] == 1 && alphabetstr2[alphabetIndex] == 1)
                {
                    sameCnt++;
                }
            }

        }
        return sameCnt * 40 / totalCnt;
    }
private:
    int getLengthPoint(int length1, int length2)
    {
        if (isSameLength(length1, length2)) return MAX_LENGTH_POINT;
        if (isDiffAboveTwice(length1, length2)) return 0;
        return partialPoint(length1, length2);
    }

    bool isSameLength(int lengthOfStr1, int lengthOfStr2) {
        return lengthOfStr1 == lengthOfStr2;
    }

    bool isDiffAboveTwice(int lengthOfStr1, int lengthOfStr2) {
        return (lengthOfStr1 >= lengthOfStr2 * 2) || (lengthOfStr2 >= lengthOfStr1 * 2);
    }

    int partialPoint(int lengthOfStr1, int lengthOfStr2) {
        if (lengthOfStr1 > lengthOfStr2)
            return (lengthOfStr2 * 2 - lengthOfStr1) * MAX_LENGTH_POINT / lengthOfStr2;
        return (lengthOfStr1 * 2 - lengthOfStr2) * MAX_LENGTH_POINT / lengthOfStr1;
    }
};