class Solution {
public:
	int climbStairs(int n) {
		if (n < 3) return n;
		n -= 2;
		int a = 1, b = 2, t;
		while (n--) {
			t = a + b;
			a = b;
			b = t;
		}
		return b;
	}
};
