#include "pch.h"
#include "../SimilarityChecker/similarityChecker.cpp"
class SimilarityFixture : public testing::Test {
public:
    Similarity similarity;
};

TEST_F(SimilarityFixture, MatchedLength) {
    int actual = 0;
    actual = similarity.checker("ABC", "DEF");
    EXPECT_EQ(actual, 60);
}

TEST_F(SimilarityFixture, diffDoubleLength1) {
    int actual = 0;
    actual = similarity.checker("ABCDEF", "DEF");
    EXPECT_EQ(actual, 0);
}

TEST_F(SimilarityFixture, diffDoubleLength2) {
    int actual = 0;
    actual = similarity.checker("ABC", "DEFGHI");
    EXPECT_EQ(actual, 0);
}

TEST_F(SimilarityFixture, diffLength1) {
    int actual = 0;
    actual = similarity.checker("ABC", "DEFGH");
    EXPECT_EQ(actual, 20);
}

TEST_F(SimilarityFixture, diffLength2) {
    int actual = 0;
    actual = similarity.checker("ABCDE", "CDE");
    EXPECT_EQ(actual, 20);
}

TEST_F(SimilarityFixture, sameAlpha) {
    int actual = 0;
    actual = similarity.alphachecker("ASD", "DSA");
    EXPECT_EQ(actual, 40);
}

TEST_F(SimilarityFixture, NotSameAlpha) {
    int actual = 0;
    actual = similarity.alphachecker("A", "BB");
    EXPECT_EQ(actual, 0);
}

TEST_F(SimilarityFixture, sameAlpha2) {
    int actual = 0;
    actual = similarity.alphachecker("AAABB", "BA");
    EXPECT_EQ(actual, 40);
}

TEST_F(SimilarityFixture, partialSameAlpha) {
    int actual = 0;
    actual = similarity.alphachecker("AA", "AAE");
    EXPECT_EQ(actual, 20);
}
