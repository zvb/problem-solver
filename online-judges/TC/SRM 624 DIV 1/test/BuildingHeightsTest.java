import org.junit.Test;
import static org.junit.Assert.*;

public class BuildingHeightsTest {
	
	@Test(timeout=2000)
	public void test0() {
		int[] heights = new int[] {1, 5, 4, 3, 8};
		assertEquals(22, new BuildingHeights().minimum(heights));
	}
	
	@Test(timeout=2000)
	public void test1() {
		int[] heights = new int[] {1, 2, 3};
		assertEquals(2, new BuildingHeights().minimum(heights));
	}
	
	@Test(timeout=2000)
	public void test2() {
		int[] heights = new int[] {3, 4, 1, 6, 8, 1};
		assertEquals(21, new BuildingHeights().minimum(heights));
	}
	
	@Test(timeout=2000)
	public void test3() {
		int[] heights = new int[] {990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
 2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
 929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
 1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
 1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
 1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888};
		assertEquals(56068, new BuildingHeights().minimum(heights));
	}
}
