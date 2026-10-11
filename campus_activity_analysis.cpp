/*
 * Course: COEN 2220 - Programming 2
 * Name: [Joewel Maldonado]
 * Lab: Lab 8 - Big-O / Time Complexity
 * Description: Resolved code for time-complexity analysis
 * Due date: [October 11 2026]
 */

#include <iostream>
using namespace std;

/* Returns the ID stored at a valid position already known by the caller. */
int getActivityIdAt(const int activityIds[], int activityIndex)
{
    return activityIds[activityIndex]; // Read one known array position.
}

/* Returns how many activities have an active status. */
int countActiveActivities(const bool isActive[], int activityCount)
{
    int activeCount = 0;

    for (int index = 0; index < activityCount; index++)
    {
        if (isActive[index])
        {
            activeCount++;
        }
    }

    return activeCount;
}

/*
 * Returns how many middle IDs binary search compares before finding targetId.
 * Precondition: activityIds is sorted in ascending order and contains targetId.
 */
int countBinaryComparisons(const int activityIds[], int activityCount, int targetId)
{
    int first = 0;
    int last = activityCount - 1;
    int comparisons = 0;

    while (first <= last)
    {
        int middle = (first + last) / 2;
        comparisons++;

        if (activityIds[middle] == targetId)
        {
            break;
        }
        else if (activityIds[middle] < targetId)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    return comparisons;
}

/* Returns how many times a positive count can be reduced by half before reaching 1. */
int countHalvingSteps(int itemCount)
{
    int steps = 0;

    while (itemCount > 1)
    {
        itemCount = itemCount / 2; // Remove approximately half of the remaining items.
        steps++;
    }

    return steps;
}

/* Returns the number of distinct activity pairs visited by two nested loops. */
int countPossiblePairs(int activityCount)
{
    int pairCount = 0;

    for (int first = 0; first < activityCount; first++)
    {
        for (int second = first + 1; second < activityCount; second++)
        {
            pairCount++; // One distinct pair would be compared here.
        }
    }

    return pairCount;
}

int main()
{
    // These activity IDs are sorted so binary search is valid.
    int activityIds[] = {101, 104, 108, 115, 130, 136, 140, 155};
    bool isActive[] = {true, false, true, true, false, false, true, false};
    int activityCount = 8;

    cout << "Activity at index 2: "
         << getActivityIdAt(activityIds, 2) << endl;
    cout << "Active activities: "
         << countActiveActivities(isActive, activityCount) << endl;
    cout << "Binary comparisons for 140: "
         << countBinaryComparisons(activityIds, activityCount, 140) << endl;
    cout << "Halving steps for 8: " << countHalvingSteps(8) << endl;
    cout << "Halving steps for 16: " << countHalvingSteps(16) << endl;
    cout << "Halving steps for 32: " << countHalvingSteps(32) << endl;
    cout << "Possible pairs for 4 activities: " << countPossiblePairs(4) << endl;
    cout << "Possible pairs for 8 activities: " << countPossiblePairs(8) << endl;

    return 0;
}

/*
 * Analysis Answers
 *
 * C1 — Direct access
 * Answer:
 * n is the number of activities in the array.
 * The representative operation is reading one array element.
 * The time complexity is O(1) because accessing a known
 * index requires one operation regardless of array size.
 *
 * C2 — Count active activities
 * Answer:
 * n is the number of activities.
 * The representative operation is checking isActive[index].
 * The time complexity is O(n) because the loop checks
 * every activity once.
 *
 * C3 — Binary search
 * Answer:
 * n is the number of activity IDs.
 * The representative operation is comparing the middle
 * ID with the target ID.
 * The time complexity is O(log n) because each iteration
 * eliminates approximately half of the remaining IDs.
 * The IDs must be sorted in ascending order so the
 * algorithm can correctly discard one half.
 *
 * C4 — Halving steps
 * Answer:
 * Starting with 16, the values are 16, 8, 4, 2, 1.
 * The repeated operation divides itemCount by 2.
 * There are 4 steps for 16 and 5 steps for 32.
 * The time complexity is O(log n).
 *
 * C5 — Distinct pairs
 * Answer:
 * The second loop starts at first + 1 to avoid comparing
 * an activity with itself or counting the same pair twice.
 * Starting at 0 would include self-comparisons and
 * duplicate pairs.
 * The time complexity is O(n^2) because the nested loops
 * compare a quadratic number of pairs.
 *
 * C6 — Compare the observed patterns
 * Answer:
 * Direct access uses O(1) because it reads one known index.
 * Counting active activities uses O(n) because it checks
 * all 8 activities and finds 4 active ones.
 * Halving uses O(log n): 8 needs 3 steps, 16 needs 4,
 * and 32 needs 5.
 * Pair comparison uses O(n^2): 4 activities produce
 * 6 pairs, while 8 activities produce 28 pairs.
 *
 * C7 — Sorting decision
 * Answer:
 * I would use linear search for a small unsorted list
 * or when only a few searches are needed.
 * If many searches are required, sorting the data once
 * could justify using binary search afterward.
 * Selection sort has O(n^2) time complexity, while
 * binary search has O(log n) time complexity.
 */