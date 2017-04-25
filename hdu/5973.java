
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	static BigDecimal gold = new BigDecimal("1.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939113748475408807538689175212663386222353693179318006076672635443338908659593958290563832266131992829026788");

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			BigDecimal a = new BigDecimal(sc.next());
			BigDecimal b = new BigDecimal(sc.next());
			if(a.compareTo(b)==1) {
				BigDecimal c=a;
				a=b;
				b=c;
			}
			BigDecimal temp = b.subtract(a).multiply(gold).subtract(a);
			//if(a!=floor(k*gold)

			if(temp.compareTo(BigDecimal.ONE)==-1 && temp.compareTo(BigDecimal.ZERO)==1)
				System.out.println(0);
			else
				System.out.println(1);

		}
	}

}
