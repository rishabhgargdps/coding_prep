//Kadane's algorithm
int Solution::maxSubArray(const vector<int> &A) {
    int end = 0;
    int curr_sum = 0;
    int max_sum = INT_MIN;
    for(end = 0; end < A.size(); end++) {
        curr_sum += A[end];
        if(A[end] > curr_sum) {
            curr_sum = A[end];
        }
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}
