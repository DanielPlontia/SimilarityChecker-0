#include <iostream>
#include <string>
using namespace std;

class Similarity {
public:
    const int MAX_LENGTH_POINT = 60;
    const int MAX_ALPHABET_POINT = 40;
    const int MAX_ALPHABET_COUNT = 26;
    const bool SET = true;
    const bool UN_SET = false;
    int checker(string str1, string str2) {
        return getLengthPoint(str1.length(), str2.length()) + getAlphabetPoint(str1, str2);
    }

private:
    int totalCnt = 0;
    int sameCnt = 0;
    bool alphabetstr1[26]{ UN_SET };
    bool alphabetstr2[26]{ UN_SET };
    int getLengthPoint(int length1, int length2)
    {
        if (isSameLength(length1, length2)) return MAX_LENGTH_POINT;
        if (isDiffAboveTwice(length1, length2)) return 0;
        return partialLengthPoint(length1, length2);
    }

    bool isSameLength(int lengthOfStr1, int lengthOfStr2) {
        return lengthOfStr1 == lengthOfStr2;
    }

    bool isDiffAboveTwice(int lengthOfStr1, int lengthOfStr2) {
        return (lengthOfStr1 >= lengthOfStr2 * 2) || (lengthOfStr2 >= lengthOfStr1 * 2);
    }

    int partialLengthPoint(int lengthOfStr1, int lengthOfStr2) {
        if (lengthOfStr1 > lengthOfStr2)
            return (lengthOfStr2 * 2 - lengthOfStr1) * MAX_LENGTH_POINT / lengthOfStr2;
        return (lengthOfStr1 * 2 - lengthOfStr2) * MAX_LENGTH_POINT / lengthOfStr1;
    }

    int getAlphabetPoint(string str1, string str2) {
        setAlphabet(str1, str2);
        calcTotalCntAndSameCnt();
        return sameCnt * MAX_ALPHABET_POINT / totalCnt;
    }

    void setAlphabet(std::string& str1, std::string& str2)
    {
        for (int i = 0; i < str1.length(); i++) {
            int index = str1[i] - 'A';
            if (alphabetstr1[index] == UN_SET) alphabetstr1[index] = SET;
        }
        for (int j = 0; j < str2.length(); j++) {
            int index = str2[j] - 'A';
            if (alphabetstr2[index] == UN_SET) alphabetstr2[index] = SET;
        }
    }

    void calcTotalCntAndSameCnt()
    {
        for (int charIndex = 0; charIndex < MAX_ALPHABET_COUNT; charIndex++)
        {
            if (alphabetstr1[charIndex] == 1 || alphabetstr2[charIndex] == 1) {
                totalCnt++;
                if (alphabetstr1[charIndex] == 1 && alphabetstr2[charIndex] == 1) sameCnt++;
            }
        }
    }
};