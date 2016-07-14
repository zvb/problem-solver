import org.junit.Test;
import static org.junit.Assert.*;

public class RGBTreeTest {
	
	@Test(timeout=2000)
	public void test0() {
		String[] G = new String[] {".RGB",
 "R...",
 "G...",
 "B..."};
		assertEquals("Exist", new RGBTree().exist(G));
	}
	
	@Test(timeout=2000)
	public void test1() {
		String[] G = new String[] {".RRB",
 "R...",
 "R...",
 "B..."};
		assertEquals("Does not exist", new RGBTree().exist(G));
	}
	
	@Test(timeout=2000)
	public void test2() {
		String[] G = new String[] {".R..BG..G..RG","R...GG..BR.G.","...G.GG.RR.BB","..G.RR.B..GRB","BG.R.G.BRRR.G","GGGRG.R....RR","..G..R.BGRR..","...BB.B.RB.G.","GBR.R.GR.B.R.",".RR.R.RBB.BRB","...GR.R..B...","RGBR.R.GRR...","G.BBGR...B..."}
;
		assertEquals("Exist", new RGBTree().exist(G));
	}
	
	@Test(timeout=2000)
	public void test3() {
		String[] G = new String[] {".............",".......BB.R..",".......RR....",".....G.G....R","........BB...","...G.........","........B...R",".BRG.......G.",".BR.B.B...GB.","....B......GR",".R......G....",".......GBG..B","...R..R..R.B."}
;
		assertEquals("Does not exist", new RGBTree().exist(G));
	}
	
	@Test(timeout=2000)
	public void test4() {
		String[] G = new String[] {"..B.BB...RB..","......R..B.G.","B.......BB...",".......R...G.","B....GRB..R..","B...G.RG.R...",".R..RR..B.RB.","...RBG...G...","..B...B......","RBB..R.G....R","B...R.R......",".G.G..B.....R",".........R.R."}
;
		assertEquals("Exist", new RGBTree().exist(G));
	}
	
	@Test(timeout=2000)
	public void test5() {
		String[] G = new String[] {"....",
 "....",
 "....",
 "...."}
;
		assertEquals("Does not exist", new RGBTree().exist(G));
	}
}
