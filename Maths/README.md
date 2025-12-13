# ➗ Mathematics Cheatsheet (C++)

A comprehensive guide to Number Theory, Modular Arithmetic, and common mathematical algorithms used in competitive programming.

## 🛠 1. Basic Number Theory

### GCD & LCM
```cpp
#include <numeric>
int g = std::gcd(a, b);
int l = std::lcm(a, b);
```

### Prime Checking O(sqrt(N))
```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) 
        if (n % i == 0) return false;
    return true;
}
```

### Sieve of Eratosthenes
Generates primes up to N in $O(N \log \log N)$.
```cpp
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    return is_prime;
}
```

---

## 🔢 2. Modular Arithmetic
Important: `(A - B) % M` becomes `((A % M) - (B % M) + M) % M`.

### Binary Exponentiation (Fast Power)
Calculates $(base^{exp}) \% mod$ in $O(\log exp)$.

```cpp
long long binpow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
```

---

## 🎲 3. Combinatorics (nCr)

### Simple Iterative (No Modulo)
```cpp
long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r > n / 2) r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; i++) res = res * (n - i + 1) / i;
    return res;
}
```

### Pascal's Triangle (DP)
Good for multiple queries with Modulo.
```cpp
// C[n][r] stores nCr
for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
        C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
}
```

---

## 📐 4. Prime Factorization
```cpp
vector<int> getPrimeFactors(int n) {
    vector<int> factors;
    // Check 2 separately
    while (n % 2 == 0) { factors.push_back(2); n /= 2; }
    // Check odds
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) { factors.push_back(i); n /= i; }
    }
    if (n > 2) factors.push_back(n);
    return factors;
}
```

---

## ⚡ Complexity Cheatsheet

| Algorithm | Time Complexity |
| :--- | :--- |
| **Primality Test** | $O(\sqrt{N})$ |
| **Sieve** | $O(N \log \log N)$ |
| **GCD** | $O(\log(\min(A, B)))$ |
| **BinPow** | $O(\log \text{exp})$ |