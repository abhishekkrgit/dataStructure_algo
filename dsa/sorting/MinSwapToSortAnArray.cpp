/**

[Approach]: Cycle Decomposition
    This is a classic problem in sorting theory:
    Given an array of n elements, the minimum number of swaps required to sort it is equal to the sum of (cycle size - 1) over all cycles in the permutation.

🧠 Intuition:
    Each cycle in the unsorted array can be sorted using cycle_size - 1 swaps.
    The total minimum swaps is the sum of all such cycle costs.

🔧 Steps:
    1. Create a vector of pairs {value, original_index}.

    2. Sort this vector by value to get the desired final position.

    3. Traverse each element; if it's not visited and not in the right place, follow the cycle.

    4.  Count how many elements are in the cycle and add cycle_size - 1 to the result.



Question:
https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/

**/


class Solution {
public:
    using pii = pair<int, int>;
    int countMinSwapsToSort(const vector<int>& arr) {
        int n = arr.size();
        vector<pii> indexedArr(n);
        for (int i = 0; i < n; ++i) {
            indexedArr[i] = {arr[i], i};
        }

        sort(indexedArr.begin(), indexedArr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || indexedArr[i].second == i) continue;

            int cycleSize = 0, j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = indexedArr[j].second;
                cycleSize++;
            }

            swaps += (cycleSize - 1);
        }

        return swaps;
    }
 }