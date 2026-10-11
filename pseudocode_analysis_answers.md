
# Lab 8 — Part D Pseudocode Analysis

## D1 — Search and scan pseudocode

**Answer:**

n represents the number of activities.

The first section uses binary search to find a target ID in a sorted array. Its representative operation is comparing the middle ID with the target. Each iteration eliminates approximately half of the remaining elements, so its time complexity is O(log n).

The second section checks every activity to count how many are active. Its representative operation is checking isActive[index]. Since it visits all n activities, its time complexity is O(n).

The overall time complexity is O(n), because O(log n) + O(n) is dominated by O(n).

The costs are added rather than multiplied because the two sections execute sequentially, not as nested loops.

## D2 — Potential-conflict pseudocode

**Answer:**

n represents the number of activities.

The variable second starts at first + 1 to avoid comparing an activity with itself and to prevent counting the same pair twice.

The representative operation is comparing startTimes[first] with startTimes[second] to check whether two activities have the same starting time.

The time complexity is O(n^2) because the nested loops examine every distinct pair of activities.

The number of comparisons is n(n - 1) / 2.

For example, with 4 activities there are 6 comparisons, and with 8 activities there are 28 comparisons.

When n doubles, the number of comparisons grows approximately four times, demonstrating quadratic growth.
