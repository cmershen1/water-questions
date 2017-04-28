import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int n = s.length();
		int m = sc.nextInt();

		long[][] dp = new long[100][100];
		for(int i=0;i<n;i++) {
			dp[i][1]=Long.valueOf(s.substring(0,i+1));
			for(int j=2;j<=Math.min(i+1, m);j++) {
				for(int k=0;k<i;k++) {
					long num = Long.valueOf(s.substring(k+1, i+1));
					dp[i][j]=Math.max(dp[i][j], dp[k][j-1]*num);
				}
			}
		}
		System.out.println(dp[n-1][m]);
    }
}
