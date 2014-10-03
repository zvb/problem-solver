// BEGIN CUT HERE

// END CUT HERE
#line 5 "RainyRoad.cpp"
#include <string>
#include <vector>
#include <cstring>

bool r[2][55];
class RainyRoad {
	public:
	string isReachable(vector <string> road) {
		memset(r, 0, sizeof(r));
        int n = road[0].length();
        r[0][0] = road[0][0] == '.';
        r[1][0] = road[1][0] == '.';
        for (int i = 1 ; i < n ; i ++) {
            if (road[0][i] != 'W') {
                r[0][i] = r[0][i] || r[1][i];
            }
            if (road[1][i] != 'W') {
                r[1][i] = r[0][i] || r[1][i];
            }
        }
        return (r[0][n-1] || r[1][n-1]) ? "YES" : "NO";
	}
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string road[]             = {".W.."
,"...."};
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string road[]             = {".W.."
,"..W."};
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string road[]             = {".W..W.."
,"...WWW."};
			string expected__         = "NO";

			std::clock_t start__      = std::clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string road[]             = {".."
,"WW"};
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string road[]             = {".WWWW."
,"WWWWWW"};
			string expected__         = "NO";

			std::clock_t start__      = std::clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string road[]             = {".W.W.W."
,"W.W.W.W"};
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string road[]             = {".............................................W."
,".............................................W."};
			string expected__         = "NO";

			std::clock_t start__      = std::clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string road[]             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string road[]             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string road[]             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
