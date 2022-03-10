#include "exercises.h"

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum = INT_MIN;
    for (int l = 0; l < n-1; l++)
    {
        for (int m = l+1; m < n; m++)
        {
            int aux=l;
            int sum = 0;
            while (aux<=m)
            {
                sum += A[aux];
                aux++;
            }
            if (sum>maxSum)
            {
                maxSum=sum;
                i = l;
                j = m;
            }
        }
    }
    return maxSum;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}