#ifndef KORNI_H
#define KORNI_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "korni.h"
}

TEST(korniTest, num0) {
    ASSERT_EQ(korni(0), 0);
    ASSERT_EQ(korni(1), 1);
    ASSERT_EQ(korni(2), 2);
}

TEST(fibonachiTest, negative) {
    ASSERT_EQ(korni(-1), 0);
}

TEST(fibonachiTest, inputFile) {
    val = 2;
    char *filename = (char *)malloc(sizeof(char) * 1024);
    sprintf(filename, "%s/input321.txt", INPUTDIR);

    int fd = open(filename, O_RDONLY);
    free(filename);
    if (fd < 0) {
        ASSERT_EQ(errno, 0);
    }

    char *buf = (char *)malloc(sizeof(char) * 512);
    int readcount = read(fd, buf, 512);
    ASSERT_TRUE(readcount > 0);
    close(fd);

    int input = 0;
    int output =0;
    int ret = sscanf(buf, "%d %d", &input, &output);
    free(buf);
    ASSERT_EQ(ret, 2);

    ret = korni(input);
    ASSERT_EQ(ret, output);
}

#endif // KORNI_H
