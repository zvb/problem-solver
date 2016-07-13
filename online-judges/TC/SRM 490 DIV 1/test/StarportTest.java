import org.junit.Test;
import static org.junit.Assert.*;

public class StarportTest {
	
	@Test(timeout=2000)
	public void test0() {
		int N = 4;
		int M = 2;
		assertEquals(1.0, new Starport().getExpectedTime(N, M), 1e-9);
	}
	
	@Test(timeout=2000)
	public void test1() {
		int N = 5;
		int M = 3;
		assertEquals(2.0, new Starport().getExpectedTime(N, M), 1e-9);
	}
	
	@Test(timeout=2000)
	public void test2() {
		int N = 6;
		int M = 1;
		assertEquals(2.5, new Starport().getExpectedTime(N, M), 1e-9);
	}
	
	@Test(timeout=2000)
	public void test3() {
		int N = 12345;
		int M = 2345;
		assertEquals(6170.0, new Starport().getExpectedTime(N, M), 1e-9);
	}
}
