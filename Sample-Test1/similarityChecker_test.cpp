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