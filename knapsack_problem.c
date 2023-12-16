#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main()
{
    int n, W;

    // Get the number of items and the knapsack capacity from the user
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    int wt[n], val[n];

    // Get the weight and value of each item from the user
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &wt[i], &val[i]);
    }

    // Solve the 0/1 Knapsack problem
    int result = knapsack(W, wt, val, n);

    // Display the result
    printf("\nThe maximum value that can be obtained is: %d\n", result);

    return 0;
}
