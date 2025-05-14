class Solution {
private:
    int MOD = 1e9 + 7;
    using Matrix = array<array<int, 26>, 26>;

    inline Matrix matrixMultiplication(Matrix& A, Matrix& B) {
        Matrix res{};
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    res[i][j] =
                        (res[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }

    inline Matrix matrixExponentiation(Matrix& transformation_matrix, int t) {
        Matrix res{};

        // create identity matrix to multiply
        for (int i = 0; i < 26; ++i) {
            res[i][i] = 1;
        }

        while (t) {
            if (t & 1) {
                res = matrixMultiplication(transformation_matrix, res);
            }

            // square the base and half the exponent
            transformation_matrix = matrixMultiplication(transformation_matrix,
                                                         transformation_matrix);
            t/=2;
        }
        return res;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        array<int,26> initial_freq{};
        for(char ch: s){
            initial_freq[ch-'a']++;
        }

        Matrix transformation_matrix{};
        for(int i=0;i<26;++i){
            //update column for each transformation
            for(int j=i+1;j<=i+nums[i];++j){
                transformation_matrix[j%26][i]++;
            }
        }

        Matrix res = matrixExponentiation(transformation_matrix,t);

        //Now calculate res*intial_freq
        array<int,26> final_array{};
        for(int i=0;i<26;++i){
            for(int j=0;j<26;++j){
                final_array[i]= (final_array[i]+ (1LL*res[i][j]*initial_freq[j])%MOD)%MOD;
            }
        }

        int string_size =0;
        for(int i=0;i<26;++i){
            string_size = (string_size + final_array[i]) % MOD;
        }
        return string_size;


    }
};