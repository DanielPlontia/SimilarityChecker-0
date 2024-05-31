#include "pch.h"
#include "../SimilarityChecker/similarityChecker.cpp"
class SimilarityFixture : public testing::Test {
public:
    Similarity similarity;
};

TEST_F(SimilarityFixture, MatchedLengthAndNotSameAlpha) {
    EXPECT_EQ(similarity.checker("ABC", "DEF"), 60);
}

TEST_F(SimilarityFixture, diffDoubleLength1AndPartialAlpha) {
    EXPECT_EQ(similarity.checker("ABCDEF", "DEF"), 20);
}

TEST_F(SimilarityFixture, diffDoubleLength2AndNotSameAlpha) {
    EXPECT_EQ(similarity.checker("ABC", "DEFGHI"), 0);
}

TEST_F(SimilarityFixture, diffLength1AndNotSameAlpha) {
    EXPECT_EQ(similarity.checker("ABC", "DEFGH"), 20);
}

TEST_F(SimilarityFixture, diffLength2AndPartialAlpha) {
    EXPECT_EQ(similarity.checker("ABCDE", "CDE"), 44);
}

TEST_F(SimilarityFixture, sameLengthAndSameAlpha) {
    EXPECT_EQ(similarity.checker("ASD", "DSA"), 100);
}

TEST_F(SimilarityFixture, diffDoubleLengthAndNotSameAlpha) {
    EXPECT_EQ(similarity.checker("A", "BB"), 0);
}

TEST_F(SimilarityFixture, diffDoubleLengthAndSameAlpha2) {
    EXPECT_EQ(similarity.checker("AAABB", "BA"), 40);
}

TEST_F(SimilarityFixture, diffLengthAndPartialSameAlpha) {
    EXPECT_EQ(similarity.checker("AA", "AAE"), 50);
}
