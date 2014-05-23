/*
   Little Elephant from Zoo of Lviv likes medians so much. Let us define median term for some array A. Let B be the same array A, but sorted in non-decreasing order. Median of A is Bm (1-based indexing), where m equals to (n div 2)+1. Here 'div' is an integer division operation. So, for a sorted array with 5 elements, median is the 3rd element and for a sorted array with 6 elements, it is the 4th element.
   Little Elephant has an array A with n integers. In one turn he can apply the following operation to any consecutive subarray A[l..r]: assign to all Ai (l <= i <= r) median of subarray A[l..r].
   Let max be the maximum integer of A. Little Elephant wants to know the minimum number of operations needed to change A to an array of n integers each with value max.
   For example, let A = [1, 2, 3]. Little Elephant wants to change it to [3, 3, 3]. He can do this in two operations, first for subarray A[2..3] (after that A equals to [1, 3, 3]), then operation to A[1..3].
   Input

   First line of the input contains single integer T - the number of test cases. Then T test cases follow, each of such format: first line - integer n, second line - array A consisted of n integers.
   Output

   In T lines print the results for each test case, one per line.
   Constraints

   1 <= T <= 100
   1 <= n <= 30
   1 <= A[i] <= 10^9

 */

 #include <iostream>
 using namespace std;

/*

Any state of the array can be represented as a binary mask with each bit 1 means that corresponding number is equal to the max and 0 otherwise. You can run DP with state R[mask] and O(n) transits. You can proof (or just believe) that the number of statest will be not big, of course if you run good DP. The state of our DP will be the mask of numbers that are equal to max. Of course, it makes sense to use operation only for such subarray [l; r] that number of 1-bits is at least as much as number of 0-bits in submask [l; r], because otherwise nothing will change. Also you should notice that if the left bound of your operation is l it is good to make operation only with the maximal possible r (this gives number of transits equal to O(n)). It was also useful for C++ coders to use map structure to represent all states.

*/

