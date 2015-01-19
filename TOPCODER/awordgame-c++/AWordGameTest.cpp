#include "AWordGame.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class AWordGameTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    AWordGame solution;

    void testCase0() {
        string wordList_[] = {"pascal program programmer task tree", "treacherous treachery tread trace"};
        vector<string> wordList(wordList_, wordList_ + (sizeof(wordList_) / sizeof(wordList_[0])));
		string expected_ = "treacherous";
        assertEquals(0, expected_, solution.outcome(wordList));
    }

    void testCase1() {
        string wordList_[] = {"pascal programmer task tree", "treacherous treachery tread trace"};
        vector<string> wordList(wordList_, wordList_ + (sizeof(wordList_) / sizeof(wordList_[0])));
		string expected_ = "programmer";
        assertEquals(1, expected_, solution.outcome(wordList));
    }

    void testCase2() {
        string wordList_[] = {"academic", "base", "board", "cola", "code", "cute", "hack"};
        vector<string> wordList(wordList_, wordList_ + (sizeof(wordList_) / sizeof(wordList_[0])));
		string expected_ = "code";
        assertEquals(2, expected_, solution.outcome(wordList));
    }

    void testCase3() {
        string wordList_[] = {"lxxatbwhoh tooj lgwlu xiub lgwdinr rjjmufijoom", "vfdx toskry xhttofxo rkgqmb xiyyvyo qwbcpjcz", "lgquy ruyyptjv vazlfwy ruyypguoofimw qwbaarpfkukk", "xinhekafyi laehdkt lxxyerjt torxi lxxatijcg rkys", "xpktuvhcxhbg xiyyddlmf vazlfkxp xhf qwbaivq", "tookxlfs xiyydvil lxxatbng qwgzkvt rjlmcuwdug", "tdjlbbsr lxtoivq lwevhyms vfdo tfci lwevhyxmmm", "xpun qexfaistucs xinhgfyv qexxjfg xvljvc", "qwgzgina ruyqzuxbyovm ladihus rjjmufie", "qwgzgif xhnqem lwevhner xpuedqzd lpmedevkt", "vzefddtid lpmeji tfcypcvkqa tdjlbbcrm rjltci", "xhttofxfb xvljve xliwbcyxwg tookxf xhnqnw lgqvnh", "qwbqiu tdjlbbcz laehdycq lgqul qwbcpr lwevhyxi", "xpktuvhyc tdly rntxz xpanwsck laehdycz", "qwgzkva ruyypguj ruyqvsz rntg xibyr qwc xhnss", "xltrqddu vzcsdu qwbaijk lwevhymb xinhgfyo qwgzgf", "xhnqnggu toskrtau rjlmcums toskwaks xiyydvgx", "xiut qwbaartdb qexo rjlquefm xinl rjjifftthu", "rkyb lpmvbfn tfcpmbo rjlmczay rpt xltennu", "lgwdirzi lpmtvbija xpanwscbh tfur xhnqngrnhci", "xltrqbwdbl xlbwe rkghbk qwgzkk tdjw tdjry xvlfztz", "qwbaarpuyyse toswj xhttozvtv qwgc lxy toskrtawp", "rkgqx lgwdings xinhgfx lxtjtipnoy tfcpmbawxv", "vazlfwlo lpmvbxcct tfcpo lgqvnq lgkxgg rjlmczrm", "xpke rnte vajnf tfuwqdp qom xinhgcmsbmi tookxlfu", "xibyd xpatx lwevhnbn ladihuxw xpuep lxxaq vui", "lgkwbgs xvv tfuariim vazb xhva xinjovn xltrqdnqwy", "rjlmil xinhgcmk vzyvo lgwdplzpcon xiyydvgge ladp", "tdjlbudh lxxb lxxyerjynyx qwf xliwgsno lxtjetr", "xhttoftrvcabo xiyyddlqf xinheijxf rkghbn tfcype", "vfk xvayc xvlfzti laey rjltgh lgkmp rql vltqmow", "vzcsm qwbaivjn lpmvbxcwj qexxjfh lxtoivjrd", "lxxydxb xltl toskway xuyf tdlu tfuwhkp lxxatbwp", "lgkxgt qexfaiku xpktgyllgg vaq xlbiv lpmtvbikk", "lpmtvbgfo xiyphm tfcpmbau ruyd xlbil rkykcbf", "xpktgiusyzg lwevhnesh tdjrfy xhnsqe vzcq lgkmk", "lgwdirzsec vzefddtdbx lxtoii rjlmczau torak", "lpmtvbgoavjeq lxtjtipmhy xltrqddg vltqmytw", "rlxnh laehr xhtfmxvjn vltqmycl lgkwe qwbaijhx", "rjlmczro rkiaj xpktgia lwevuwow ruyqvsln lxtjtihl", "tdssjxz xiyydvie qwbaartk torax xlbwa xinheiha", "xvsmy vzcsds ruyqzuykr toskwakl tdjrfg vflz lxta", "xhnqnggj lxtoivjw tfuwhr lxtjetdp qexxjtg", "rnm xiue xpj vazlfwlfdg xhttozqr rkykcbo", "qwbcpjcmv tfuardg qwgzginklo tdssjd tfuardti lxl", "rlxb xhttye lwevuwl lgwiw rkykcmhltv qwgbsrgo", "tfuwqdgbh ruyqzxw lwemx xiypf xltrqbwm", "lpmedevcfkt"};
        vector<string> wordList(wordList_, wordList_ + (sizeof(wordList_) / sizeof(wordList_[0])));
		string expected_ = "tfcpmbawxv";
        assertEquals(3, expected_, solution.outcome(wordList));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 4; i++) {
        AWordGameTest test;
        test.runTest(i);
    }
}
