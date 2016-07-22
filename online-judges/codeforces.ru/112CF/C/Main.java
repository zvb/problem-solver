import java.io.*;
import java.util.*;

public class Main {

    // Returns the index of the smallest element that is >= val or to if all elements are less than val
    int lowerBound(long arr[], int from, int to, long val) {
        int lo = from, hi = to;
        while (hi > lo) {
            int mid = lo + (hi-lo)/2;
            if (arr[mid] < val)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
    long prefSum[];
    public void solve() throws IOException {
        int k = nextInt();
        String s = next();
        int n = s.length();

        prefSum = new long [n+1];
        for (int i = 1 ; i <= n ; i++) {
            prefSum[i] = prefSum[i-1] + (s.charAt(i-1) - '0');
        }


        long result = 0;
        for (int i = 1; i <= n ; i ++) {
            long target = prefSum[i-1] + k;
            int start = lowerBound(prefSum, i, n+1, target); 
            int end = lowerBound(prefSum, i, n+1, target+1);
            result += end - start;
        }
        out.println(result);

    }

    public void solve2() throws IOException {
        int k = nextInt();
        String s = next();
        int n = s.length();

        long result = 0;
        
        int startIdx = -1, endIdx = 0, count = 0;

        for (int i = 0; i < n ; i ++) {

            // Move startIdx pointer
            while ( count < k && startIdx + 1 < n ) {
                if (s.charAt(startIdx + 1) == '1') 
                    count ++;
                startIdx ++;
            }

            if (count < k)
                break;

            

            endIdx = startIdx;

            while (endIdx + 1 < n && s.charAt(endIdx + 1) != '1') {
                endIdx ++;
            }

            out.println(i + " " + startIdx + " " + endIdx);
            // Now endIdx at the next '1' or at the end of the string
            result += endIdx - startIdx;
            if (s.charAt(i) == '1')
                count --;
        }
        out.println(result);

    }
    

    
    
    BufferedReader bf;
    StringTokenizer st;
    PrintWriter out;
    
    public String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) 
            st = new StringTokenizer(bf.readLine());
        return st.nextToken();
    }
    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    
    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public Main() throws IOException {
        bf = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));		
        solve2();
        bf.close();
        out.close();
    }
    
    public static void main(String args[]) throws IOException {
        new Main();
    }
}