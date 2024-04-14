#include "matrix.hpp"
#include <gtest/gtest.h>
#include <iostream>

typedef std::tuple<int, int> tup_int;

class MatrixTest : public testing::Test {
protected:
    Matrix m1, m2, m3, m4;

    void SetUp() override {

        m1 = Matrix();
        m2 = Matrix(2);
        m3 = Matrix(2, 2);
        m4 = Matrix(m3);


        m2.fill(0.0);
        m3.fill(0.0);
        m4.fill(0.0);
    }

};

TEST_F(MatrixTest, Creation){
    EXPECT_EQ(m1.size(), tup_int(0,0)) << "Empty constructor shape fail";
    EXPECT_EQ(m2.size(), tup_int(1, 2)) << "Vector constructor shape fail";
    EXPECT_EQ(m3.size(), tup_int(2, 2)) << "Matrix constructor shape fail";
    EXPECT_EQ(m4.size(), tup_int(2, 2)) << "Copy constructor shape fail";

    EXPECT_EQ(m3, m4) << "Copy constructor fail";

}

TEST_F(MatrixTest, SettersGetters){
    EXPECT_EQ((m2[0,0]), 0.0) << "[] getter fail";

    m2[0,0] = 1.0;

    EXPECT_EQ((m2[0,0]), 1.0) << "[] setter or fill fail";


}

TEST_F(MatrixTest, Dimensions) {
    m2[0,0] = 1.0;

    EXPECT_EQ(m2.max(), 1.0) << "Max method fail";
    EXPECT_EQ(m2.min(), 0.0) << "Min method fail";
}

TEST_F(MatrixTest, Booleams) {
    EXPECT_EQ(m3, m4) << "Equal operator fail";
    EXPECT_NE(m2, m3) << "Equal operator fail";

    GTEST_EXPECT_TRUE(m2 != m3) << "Not equal operator fail";
    GTEST_EXPECT_FALSE(m3 != m4) << "Not equal operator fail";
}

TEST_F(MatrixTest, MathOps) {
    m3[0,1] = 1.0;
    m3.transpose();
    m4[1,0] = 1.0;
    EXPECT_EQ(m3, m4) << "Transpose method fail";

    m4.fill(2.0);
    m3.fill(0.0);
    m3[0,0] = 1.0;
    m3[1,1] = 1.0;

    Matrix m5 = Matrix(m4);
    m5 *= m3;

    EXPECT_EQ(m5, m4) << "Multiply by matrix operation fail";

    m5 *= 2.0;
    Matrix m6 = Matrix(2, 2);
    m6.fill(4.0);

    EXPECT_EQ(m5, m6) << "Multiply by double operation fail";

    m5 += m6;
    m6.fill(8.0);
    EXPECT_EQ(m5, m6) << "Add matrixes operation fail";

    m5 -= m6;
    m6.fill(0.0);
    EXPECT_EQ(m5, m6) << "Subtract matrixes operation fail";

}