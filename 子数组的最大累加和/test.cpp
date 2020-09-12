class Solution {
public:
    /**
     * max sum of the subarray
     * @param arr int����vector the array
     * @return int����
     */
    int maxsumofSubarray(vector<int>& arr) {
        // write code here
        int i, sum = 0;
        int max = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (max < sum)
            {
                max = sum;
            }
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
};