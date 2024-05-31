#include <iostream>
#include <string>
using namespace std;

class Similarity {
public:
    const int MAX_LENGTH_POINT = 60;
    int checker(string str1, string str2) {
        int result = getLengthPoint(str1.length(), str2.length());
        return result;
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