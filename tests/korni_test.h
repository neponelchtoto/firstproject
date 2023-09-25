#ifndef KORNI_TEST_H
#define KORNI_TEST_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "korni.h"
}

float x1, x2;
int flag;


TEST(Discr, num1) {
    korni(1, -3, 4, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);    
}

TEST(Discr, num2) {
    korni(1, 2, 1, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-1, x1);
    ASSERT_FLOAT_EQ(-1, x2);
    ASSERT_EQ(0, flag);
}

TEST(Discr, num3) {
    korni(1, -4, 3, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(3, x1);
    ASSERT_FLOAT_EQ(1, x2);
    ASSERT_EQ(0, flag);
}

TEST(Discr, num4) {
    korni(1, 5, 3, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-0.69722402, x1);
    ASSERT_FLOAT_EQ(-4.30278, x2);
    ASSERT_EQ(0, flag);
}

TEST(Koefzero, num5) {
    korni(0, 4, 3, &x1, &x2, &flag);
    ASSERT_EQ(flag, 0);
}

TEST(Koefzero, num6) {
    korni(1, 0, -9, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(3, x1);
    ASSERT_FLOAT_EQ(-3, x2);
    ASSERT_EQ(flag, 0);
}

#endif // QVADR_H
