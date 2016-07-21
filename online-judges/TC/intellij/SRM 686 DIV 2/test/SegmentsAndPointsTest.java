import org.junit.Test;
import static org.junit.Assert.*;

public class SegmentsAndPointsTest {
	
	@Test(timeout=2000)
	public void test0() {
		int[] p = new int[] {1, 2};
		int[] l = new int[] {0, 0};
		int[] r = new int[] {1, 3};
		assertEquals("Possible", new SegmentsAndPoints().isPossible(p, l, r));
	}
	
	@Test(timeout=2000)
	public void test1() {
		int[] p = new int[] {0};
		int[] l = new int[] {2};
		int[] r = new int[] {3};
		assertEquals("Impossible", new SegmentsAndPoints().isPossible(p, l, r));
	}
	
	@Test(timeout=2000)
	public void test2() {
		int[] p = new int[] {0, 1, 2};
		int[] l = new int[] {0, 0, 1};
		int[] r = new int[] {1, 2, 1};
		assertEquals("Possible", new SegmentsAndPoints().isPossible(p, l, r));
	}
	
	@Test(timeout=2000)
	public void test3() {
		int[] p = new int[] {0, 1};
		int[] l = new int[] {-1, 0};
		int[] r = new int[] {0, 0};
		assertEquals("Impossible", new SegmentsAndPoints().isPossible(p, l, r));
	}
	
	@Test(timeout=2000)
	public void test4() {
		int[] p = new int[] {434, 63, 241, 418, -380, -46, 397, -205, -262, -282, 260, -106, -389, -286, 422, -75, 127, 382, 52, -383};
		int[] l = new int[] {-447, -226, -411, 287, -83, -228, -390, 358, 422, 395, -461, -112, 49, 75, -160, -152, 372, -447, -337, -362};
		int[] r = new int[] {-102, 348, -70, 466, 168, -61, -389, 469, 433, 471, -75, -41, 52, 236, 299, -48, 383, -353, 346, -217};
		assertEquals("Possible", new SegmentsAndPoints().isPossible(p, l, r));
	}
}
