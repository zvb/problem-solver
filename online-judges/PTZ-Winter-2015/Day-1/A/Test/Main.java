import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        BigInteger n = in.nextBigInteger();
        BigInteger k = in.nextBigInteger();
        
        BigInteger ans = BigInteger.ONE;
        BigInteger one = BigInteger.ONE;
        
        for (BigInteger i = n.subtract(k).add(one) ; i.compareTo(n) <= 0 ; i = i.add(one) )
        {
            ans = ans.multiply(i);
        }
        for (BigInteger i = one ; i.compareTo(k) <= 0 ; i = i.add(one) )
        {
            ans = ans.divide(i);
        }
        
        out.println(ans.mod(one.shiftLeft(32)));
        
        out.close();
        
    }
}