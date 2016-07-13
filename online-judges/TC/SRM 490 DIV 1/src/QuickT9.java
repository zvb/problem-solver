import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class QuickT9 {
  public final static String dig[] = new String[]
      {   "", "", "abc", "def",
          "ghi", "jkl", "mno",
          "pqrs", "tuv", "wxyz"
      };
  int getDigitForChar(char c) {
    int ans = 0;
    for (int i = 0 ; i < dig.length; i++) {
      if (dig[i].indexOf(c) > -1)
        return i;
    }
    return -1;
  }
  String getDigits(String word) {
    StringBuilder sb = new StringBuilder();
    for (int i = 0 ; i < word.length(); i++) {
      char c = word.charAt(i);
      int digit = getDigitForChar(c);
      if (digit == -1)
        throw new RuntimeException("digit is -1");
      sb.append(digit);
    }
    return sb.toString();
  }
  public boolean matches(String word, String digitSeq) {
    if (word.length() != digitSeq.length())
      return false;
    for (int i = 0 ; i < word.length(); i++) {
      char c = word.charAt(i);
      int digit = digitSeq.charAt(i) - '0';
      if (!dig[digit].contains("" + c))
        return false;
    }
    return true;
  }

  int  ceiling(String w, String[] dict) {
    for (int i = 0 ; i < dict.length; i++) {
      if (w.compareTo(dict[i]) >= 0)
        return i;
    }
    return -1;
  }

  int countSteps(String dictWord, String[] dict) {
    String D = getDigits(dictWord);
    for (int i = 0 ; i < dict.length; i++) {
      if (dict[i].startsWith(dict))
    }
  }

	public int minimumSingle(String [] dict, String word) {

    String D = getDigits(word);

    ArrayList<String> matching = new ArrayList<>();
    for (String dictWord : dict) {
      if (dictWord.length() < word.length())
        continue;
      String prefix = dictWord.substring(0, word.length());
      if (matches(prefix, D) ) {
        matching.add(dictWord);
      }
    }
    int result = Integer.MAX_VALUE / 2;
    for (int i = 0; i < matching.size(); i++) {
      String good = matching.get(i);
      // Count how to convert good to word
      if (good.startsWith(word)) {

      }
    }


    return 0;
	}
	public int minimumPressings(String[] t9, String word) {
		TreeSet<String> sortedDict = new TreeSet<>(Arrays.asList(t9));
    int N = word.length();
    int [][] dp = new int[N+1][N+1];
    for (int i = 0 ; i <= N ;i++) {
      Arrays.fill(dp[i], 1 << 29);
    }
    for (int length = 0 ; length <= N ; length ++) {

      for (int beginningIdx = 0; beginningIdx < N ; beginningIdx ++) {
        int endingIdx = beginningIdx + length;
        if (endingIdx > N)
          break;

        if (length == 0) {
          dp[0][beginningIdx] = 0;
          continue;
        }
        dp[length][beginningIdx] = minimumSingle(sortedDict, word.substring(beginningIdx, beginningIdx + length));
        for (int separator = beginningIdx + 1; separator < endingIdx; separator ++) {
          int result = dp[separator - beginningIdx][beginningIdx] + dp[endingIdx - separator][separator];
          if (dp[length][beginningIdx] > result)
            dp[length][beginningIdx] = result;
        }
      }
    }

    return dp[N][0];
	}
}
