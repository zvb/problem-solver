import org.junit.Test;

import java.util.Arrays;
import java.util.TreeSet;

import static org.junit.Assert.*;

public class QuickT9Test {

	@Test
  public void test_minimumSingle() {
    String[] t9 = new String[] {"aae", "bab", "cbad", "bdbd", "beta"};
    String word = "cba";
    TreeSet<String> dict = new TreeSet<>(Arrays.asList(t9));
    assertEquals(5, new QuickT9().minimumSingle(dict, word));
  }

	@Test(timeout=2000)
	public void test0() {
		String[] t9 = new String[] {"aae", "bab", "abad", "bdbd", "beta"};
		String word = "babe";
		assertEquals(9, new QuickT9().minimumPressings(t9, word));
	}
	
	@Test(timeout=2000)
	public void test1() {
		String[] t9 = new String[] {"ann","ie"};
		String word = "annie";
		assertEquals(7, new QuickT9().minimumPressings(t9, word));
	}
	
	@Test(timeout=2000)
	public void test2() {
		String[] t9 = new String[] {"ann","amm"};
		String word = "annie";
		assertEquals(-1, new QuickT9().minimumPressings(t9, word));
	}
	
	@Test(timeout=2000)
	public void test3() {
		String[] t9 = new String[] {"aaa aab","aac aba abb ccca"};
		String word = "aba";
		assertEquals(6, new QuickT9().minimumPressings(t9, word));
	}
	
	@Test(timeout=2000)
	public void test4() {
		String[] t9 = new String[] {"acac aba aaab","aab aa baa","bba bacade abb","baba"};
		String word = "abbaca";
		assertEquals(10, new QuickT9().minimumPressings(t9, word));
	}
	
	@Test(timeout=2000)
	public void test5() {
		String[] t9 = new String[] {"aaa aab aac","aba abb","ccca"};
		String word = "ccc";
		assertEquals(5, new QuickT9().minimumPressings(t9, word));
	}
}
