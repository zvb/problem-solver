import org.junit.Test;
import static org.junit.Assert.*;

public class BracketSequenceDiv2Test {
	
	@Test(timeout=2000)
	public void test0() {
		String s = "(())(";
		assertEquals(2, new BracketSequenceDiv2().count(s));
	}
	
	@Test(timeout=2000)
	public void test1() {
		String s = "())";
		assertEquals(1, new BracketSequenceDiv2().count(s));
	}
	
	@Test(timeout=2000)
	public void test2() {
		String s = ")(((";
		assertEquals(0, new BracketSequenceDiv2().count(s));
	}
	
	@Test(timeout=2000)
	public void test3() {
		String s = "()()()()()()()()(())))(()()()()))())";
		assertEquals(364675, new BracketSequenceDiv2().count(s));
	}
	
	@Test(timeout=2000)
	public void test4() {
		String s = "()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()";
		assertEquals(122826009, new BracketSequenceDiv2().count(s));
	}
}
