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

    EXPECT_EQ((m2[0,0]), 1.0) << "[] setter fail";

}