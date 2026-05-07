struct Matrix {
    int n, m;
    vector<vector<ll>> matrix;
 
    Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        matrix.assign(n, vector<ll>(m, 0));
    }
 
    Matrix mult(const Matrix& other) {
        Matrix res(n, other.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                for (int k = 0; k < m; k++) {
                    res.matrix[i][j] =
                        (res.matrix[i][j]
                        + (matrix[i][k] * other.matrix[k][j])%MOD) % MOD;
                }
            }
        }
        return res;
    }
 
    void mult_line(int line, ll v) {
        for (int i = 0; i < m; i++) {
            matrix[line][i] = matrix[line][i] * v % MOD;
        }
    }

    Matrix fexp_matrix(Matrix base, ll p) {
        Matrix ans(base.n, base.n); 
        for(int i = 0; i < base.n; i++) ans.matrix[i][i] = 1;
        while (p) {
            if (p & 1) ans = ans.mult(base);
            base = base.mult(base);
            p >>= 1;
        }
        return ans;
    }
};