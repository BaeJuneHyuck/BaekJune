import java.util.Scanner;
import java.math.BigInteger;
import java.io.IOException;

public class Main {
	static int N, M;
	static BigInteger[][] DP;
	public static void main(String[] args) throws IOException {
		DP = new BigInteger[101][101];
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				DP[i][j] = BigInteger.valueOf(0);
			}
		}
		Scanner scan = new Scanner(System.in);

		N = scan.nextInt();
		M = scan.nextInt();
		System.out.println(dp(N, M));
	}

	//nCr = n-1Cr + n-1Cr-1
	static BigInteger dp(int n, int m) {
		// System.out.println(n+", "+m);
		if (n == m) DP[n][m] = BigInteger.valueOf(1);
		if (m == 1) DP[n][m] = BigInteger.valueOf(n);
		else if (DP[n][m] != BigInteger.valueOf(0)) return DP[n][m];
		else {
			DP[n][m] = dp(n - 1, m).add(dp(n - 1, m - 1));
		}
		return DP[n][m];
	}
}
