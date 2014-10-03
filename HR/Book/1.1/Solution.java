import java.util.*;
import java.io.*;
public class Solution {
    // 1.1
    public static boolean hasAllUniqueChars(String s) {
        HashSet<Character> set = new HashSet<>();
        for (int i = 0 ; i < s.length() ; i ++) {
            if (set.contains(s.charAt(i)))
                return false;
            set.add(s.charAt(i));
        }
        return true;
    }
    public static boolean hasAllUniqueChars2(String s) {
        boolean [] map = new boolean[256];
        for (int i = 0 ; i < s.length() ; i ++) {
            if (map[(int)s.charAt(i)])
                return false;
            map[(int)s.charAt(i)] = true;
        }
        return true;
    }
    
    // 1.2 Reverse C-string
    
    // 1.3
    public static String removeDuplicateChars(String s) {
        char previous = '#';
        String result = "";
        for (int i = 0 ; i < s.length() ; i ++) {
            if (i == 0 || s.charAt(i) != s.charAt(i-1))
                result += s.charAt(i); //use string builder.
            else
                ;
        }
        return result;
        
    }
    //1.4
    public static boolean areAnagrams(String a, String b) {
        return false;
    }
    // 1.5
    public static int urlEncode(char s[], int length) {
        if (length < 1) return 0;
        int spaceCount = 0;
        for (int i = 0 ; i < length ; i ++)
            if (s[i] == ' ')
                spaceCount ++;
        int newLength = spaceCount*2 + length;
        int curPos = newLength - 1; //where new string should end
        for (int i = length - 1 ; i >= 0 ; i --) {
            if (s[i] == ' ') {
                s[curPos --] = '0';
                s[curPos --] = '2';
                s[curPos --] = '%';
            } else {
                s[curPos --] = s[i];
            }
        }
        return newLength;
        
    }
    
    //1.6
    public static void rotateCCW90(int [][] mat, int n) {
        // (i, j) -> (j, -i) -> (-i, -j) -> (-j, i)
        // (i, j) -> (n - j - 1, i) -> (n - i - 1, n - j - 1) -> (j , n - i - 1)
        // (0, 0) -> (n - 1, 0)
        // (0, n - 2) -> (1, 0) ->
        int center = n / 2;
        for (int i = 0 ; i <= center ; i ++) {
            for (int j = i ; j < n - i - 1 ; j ++) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][n-i-1];
                mat[j][n-i-1] = mat[n-i-1][n-j-1];
                mat[n-i-1][n-j-1] = mat[n-j-1][i];
                mat[n-j-1][i] = temp;
            }
        }
        
    }
    //1.7
    public static void zero(int [][] a, int n, int m) {
        boolean [] rows = new boolean [n];// should row[i] be zeroed?
        boolean [] cols = new boolean [m]; // should cols[i] be zeroed;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (a[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (rows[i] || cols[j])
                    a[i][j] = 0;
            }
        }
    }
    
    //1.8
    public static boolean isRotation(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        String ds1 = s1 + s1;
        //if (s2.isSubstring(ds1)) return true;
        return false;
    }
    
    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), m = scanner.nextInt();
        int [][] a = new int [n][m];
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                a[i][j] = scanner.nextInt();
            }
        }
        zero(a, n, m);
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ;j ++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
        scanner.close();
    }
}