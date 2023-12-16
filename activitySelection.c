#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
struct Activity
{
    int start;
    int finish;
};

// Comparison function to sort activities by their finish times in non-decreasing order
int compare(const void *a, const void *b)
{
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

// Function to print the selected activities
void printSelectedActivities(struct Activity activities[], int n)
{
    // Sort activities based on finish times
    qsort(activities, n, sizeof(activities[0]), compare);

    // The first activity is always selected
    printf("Selected activity: (%d, %d)\n", activities[0].start, activities[0].finish);

    // Consider the rest of the activities
    int i = 1;
    for (int j = 1; j < n; j++)
    {
        // If this activity has a start time greater than or equal to the finish time of the previously selected activity,
        // then select it
        if (activities[j].start >= activities[i - 1].finish)
        {
            printf("Selected activity: (%d, %d)\n", activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main()
{
    int n;

    // Get the number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    // Get the start and finish times of each activity
    printf("Enter the start and finish times of each activity:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &activities[i].start, &activities[i].finish);

    // Print the selected activities
    printf("Selected activities:\n");
    printSelectedActivities(activities, n);

    return 0;
}
