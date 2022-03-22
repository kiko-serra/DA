#include "exercises.h"
using namespace std;

bool changeMakingUnlimitedDP(unsigned int C[], unsigned int n, unsigned int T, unsigned int usedCoins[])
{
    INF = numeric_limits<int>;
    unsigned int m[max] = INF;
    unsigned int l[max] = {0};
    m[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int k = C[i]; k < T; k++)
        {
            if (1 + m[i, k - C[i]] < m[i - 1, k])
            {
                m[k] = 1 + m[i, k - C[i]];
                l[k] = C[i];
            }
        }
    }
    if (m[T] == INF)
        return false;
    for (int i = 0; i < n; i++)
    {
        usedCoins[i] = 0;
        int remT = T;
        while (remT > 0)
        {
            usedCoins[l[remT]]++;
            remT -= C[l[remT]];
        }
    }
    return true;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex2, hasChangeCanonical)
{
    unsigned int C[] = {1, 2, 5, 10};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingUnlimitedDP(C, n, 13, usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    EXPECT_EQ(changeMakingUnlimitedDP(C, n, 38, usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 1);
    EXPECT_EQ(usedCoins[3], 3);

    EXPECT_EQ(changeMakingUnlimitedDP(C, n, 10, usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);
}

TEST(TP4_Ex2, hasChangeNonCanonical)
{
    unsigned int C[] = {1, 4, 5};
    unsigned int n = 3;
    unsigned int usedCoins[3];

    EXPECT_EQ(changeMakingUnlimitedDP(C, n, 6, usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingUnlimitedDP(C, n, 8, usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);

    EXPECT_EQ(changeMakingUnlimitedDP(C, n, 7, usedCoins), true);
    EXPECT_EQ(usedCoins[0], 2);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);
}

TEST(TP4_Ex2, hasNoChange)
{
    unsigned int C[] = {5, 10};
    unsigned int n = 2;
    unsigned int usedCoins[2];

    EXPECT_EQ(changeMakingUnlimitedDP(C, n, 1, usedCoins), false);
}