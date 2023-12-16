#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications needed
// to multiply a chain of matrices using dynamic programming
int matrixChainMultiplication(int p[], int n)
{
    int m[n][n];

    // Cost is 0 when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];
}

int main()
{
    int n;

    // Get the number of matrices in the chain
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions[n + 1];

    // Get the dimensions of each matrix
    printf("Enter the dimensions of each matrix:\n");
    for (int i = 0; i <= n; i++)
        scanf("%d", &dimensions[i]);

    // Calculate the minimum number of scalar multiplications
    int result = matrixChainMultiplication(dimensions, n + 1);

    // Display the result
    printf("The minimum number of scalar multiplications is: %d\n", result);

    return 0;
}
