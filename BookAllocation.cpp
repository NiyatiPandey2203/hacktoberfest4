You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the student with the most books allocated to him gets the minimum number of pages, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.

Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:32
Explanation: Allocation is done as
{15,17} and {20}
Your Task:
You don't need to read input or print anything. Your task is to complete the function findPages() which takes 2 Integers N, and m and an array A[] of length N as input and returns the expected answer.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)


Constraints:
1 <= N <= 105
1 <= A [ i ] <= 106
1 <= M <= 105


!!!HERE IS SOLUTION!!!

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution {
public:
     bool isPossible(std::vector<int>& books, int numStudents, int maxPages) {
        int students = 1;
        int currPages = 0;
        for (int i = 0; i < books.size(); i++) {
            if (books[i] > maxPages) {
                return false;  // If any book has more pages than the maximum, it is not possible
            }
            if (currPages + books[i] <= maxPages) {
                currPages += books[i];
            } else {
                students++;
                currPages = books[i];
            }
            if (students > numStudents) {
                return false;  // If the number of students exceeds the limit, it is not possible
            }
        }
        return true;
    }

    int findPages(int A[], int N, int M) {
        std::vector<int> books(A, A + N);

        if (N < M) {
            return -1;  // If the number of books is less than the number of students, it is not possible
        }

        int left = *std::max_element(books.begin(), books.end());  // Lower bound
        int right = std::accumulate(books.begin(), books.end(), 0);  // Upper bound
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(books, M, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
