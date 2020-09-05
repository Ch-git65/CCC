class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index = m + n - 1;
        int i, j;
        for (i = m - 1, j = n - 1; i >= 0 && j >= 0; )
        {
            if (A[i] >= B[j])
                A[index--] = A[i--];
            else if (A[i] < B[j])
                A[index--] = B[j--];
        }


        while (j >= 0)
            A[index--] = B[j--];
    }
};