using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode212WordSearchII : BaseProblemClass
{
    public IList<string> FindWords(char[][] board, string[] words)
    {
        var result = new List<string>();
        var root = BuildTrie(words);
        int height = board.Length, width = board[0].Length;

        bool[,] visited = new bool[height, width];

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Backtrack(board, i, j, root, visited, result);
            }
        }

        return result;
    }

    private void Backtrack(char[][] board, int i, int j, TrieNode node, bool[,] visited, IList<string> result)
    {
        if (i < 0 || i >= board.Length || j < 0 || j >= board[0].Length || visited[i, j] ||
            !node.Children.TryGetValue(board[i][j],out var nextNode))
        {
            return;
        }
        if (nextNode.Word != null)
        {
            result.Add(nextNode.Word);
            nextNode.Word = null; 
        }
        visited[i, j] = true;
        Backtrack(board, i + 1, j, nextNode, visited, result);
        Backtrack(board, i - 1, j, nextNode, visited, result);
        Backtrack(board, i, j + 1, nextNode, visited, result);
        Backtrack(board, i, j - 1, nextNode, visited, result);
        visited[i, j] = false;
    }

    private TrieNode BuildTrie(string[] words)
    {
        var root = new TrieNode();
        foreach (var word in words)
        {
            var current = root;
            foreach (var c in word)
            {
                if (!current.Children.ContainsKey(c))
                {
                    current.Children[c] = new TrieNode();
                }

                current = current.Children[c];
            }

            current.Word = word; 
        }

        return root;
    }

    public class TrieNode
    {
        public readonly Dictionary<char, TrieNode> Children = new();
        public string? Word;
    }

    public override void Run()
    {
        char[][] board =
        [
            ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b']
        ];
        // [['o', 'a', 'a', 'n'], ['e', 't', 'a', 'e'], ['i', 'h', 'k', 'r'], ['i', 'f', 'l', 'v']]
        string[] words =
        [
            "aababababa", "abbabababa", "acbabababa", "adbabababa", "aebabababa", "afbabababa", "agbabababa",
            "ahbabababa", "aibabababa", "ajbabababa", "akbabababa", "albabababa", "ambabababa", "anbabababa",
            "aobabababa", "apbabababa", "aqbabababa", "arbabababa", "asbabababa", "atbabababa", "aubabababa",
            "avbabababa", "awbabababa", "axbabababa", "aybabababa", "azbabababa", "bababababa", "bbbabababa",
            "bcbabababa", "bdbabababa", "bebabababa", "bfbabababa", "bgbabababa", "bhbabababa", "bibabababa",
            "bjbabababa", "bkbabababa", "blbabababa", "bmbabababa", "bnbabababa", "bobabababa", "bpbabababa",
            "bqbabababa", "brbabababa", "bsbabababa", "btbabababa", "bubabababa", "bvbabababa", "bwbabababa",
            "bxbabababa", "bybabababa", "bzbabababa", "cababababa", "cbbabababa", "ccbabababa", "cdbabababa",
            "cebabababa", "cfbabababa", "cgbabababa", "chbabababa", "cibabababa", "cjbabababa", "ckbabababa",
            "clbabababa", "cmbabababa", "cnbabababa", "cobabababa", "cpbabababa", "cqbabababa", "crbabababa",
            "csbabababa", "ctbabababa", "cubabababa", "cvbabababa", "cwbabababa", "cxbabababa", "cybabababa",
            "czbabababa", "dababababa", "dbbabababa", "dcbabababa", "ddbabababa", "debabababa", "dfbabababa",
            "dgbabababa", "dhbabababa", "dibabababa", "djbabababa", "dkbabababa", "dlbabababa", "dmbabababa",
            "dnbabababa", "dobabababa", "dpbabababa", "dqbabababa", "drbabababa", "dsbabababa", "dtbabababa",
            "dubabababa", "dvbabababa", "dwbabababa", "dxbabababa", "dybabababa", "dzbabababa", "eababababa",
            "ebbabababa", "ecbabababa", "edbabababa", "eebabababa", "efbabababa", "egbabababa", "ehbabababa",
            "eibabababa", "ejbabababa", "ekbabababa", "elbabababa", "embabababa", "enbabababa", "eobabababa",
            "epbabababa", "eqbabababa", "erbabababa", "esbabababa", "etbabababa", "eubabababa", "evbabababa",
            "ewbabababa", "exbabababa", "eybabababa", "ezbabababa", "fababababa", "fbbabababa", "fcbabababa",
            "fdbabababa", "febabababa", "ffbabababa", "fgbabababa", "fhbabababa", "fibabababa", "fjbabababa",
            "fkbabababa", "flbabababa", "fmbabababa", "fnbabababa", "fobabababa", "fpbabababa", "fqbabababa",
            "frbabababa", "fsbabababa", "ftbabababa", "fubabababa", "fvbabababa", "fwbabababa", "fxbabababa",
            "fybabababa", "fzbabababa", "gababababa", "gbbabababa", "gcbabababa", "gdbabababa", "gebabababa",
            "gfbabababa", "ggbabababa", "ghbabababa", "gibabababa", "gjbabababa", "gkbabababa", "glbabababa",
            "gmbabababa", "gnbabababa", "gobabababa", "gpbabababa", "gqbabababa", "grbabababa", "gsbabababa",
            "gtbabababa", "gubabababa", "gvbabababa", "gwbabababa", "gxbabababa", "gybabababa", "gzbabababa",
            "hababababa", "hbbabababa", "hcbabababa", "hdbabababa", "hebabababa", "hfbabababa", "hgbabababa",
            "hhbabababa", "hibabababa", "hjbabababa", "hkbabababa", "hlbabababa", "hmbabababa", "hnbabababa",
            "hobabababa", "hpbabababa", "hqbabababa", "hrbabababa", "hsbabababa", "htbabababa", "hubabababa",
            "hvbabababa", "hwbabababa", "hxbabababa", "hybabababa", "hzbabababa", "iababababa", "ibbabababa",
            "icbabababa", "idbabababa", "iebabababa", "ifbabababa", "igbabababa", "ihbabababa", "iibabababa",
            "ijbabababa", "ikbabababa", "ilbabababa", "imbabababa", "inbabababa", "iobabababa", "ipbabababa",
            "iqbabababa", "irbabababa", "isbabababa", "itbabababa", "iubabababa", "ivbabababa", "iwbabababa",
            "ixbabababa", "iybabababa", "izbabababa", "jababababa", "jbbabababa", "jcbabababa", "jdbabababa",
            "jebabababa", "jfbabababa", "jgbabababa", "jhbabababa", "jibabababa", "jjbabababa", "jkbabababa",
            "jlbabababa", "jmbabababa", "jnbabababa", "jobabababa", "jpbabababa", "jqbabababa", "jrbabababa",
            "jsbabababa", "jtbabababa", "jubabababa", "jvbabababa", "jwbabababa", "jxbabababa", "jybabababa",
            "jzbabababa", "kababababa", "kbbabababa", "kcbabababa", "kdbabababa", "kebabababa", "kfbabababa",
            "kgbabababa", "khbabababa", "kibabababa", "kjbabababa", "kkbabababa", "klbabababa", "kmbabababa",
            "knbabababa", "kobabababa", "kpbabababa", "kqbabababa", "krbabababa", "ksbabababa", "ktbabababa",
            "kubabababa", "kvbabababa", "kwbabababa", "kxbabababa", "kybabababa", "kzbabababa", "lababababa",
            "lbbabababa", "lcbabababa", "ldbabababa", "lebabababa", "lfbabababa", "lgbabababa", "lhbabababa",
            "libabababa", "ljbabababa", "lkbabababa", "llbabababa", "lmbabababa", "lnbabababa", "lobabababa",
            "lpbabababa", "lqbabababa", "lrbabababa", "lsbabababa", "ltbabababa", "lubabababa", "lvbabababa",
            "lwbabababa", "lxbabababa", "lybabababa", "lzbabababa", "mababababa", "mbbabababa", "mcbabababa",
            "mdbabababa", "mebabababa", "mfbabababa", "mgbabababa", "mhbabababa", "mibabababa", "mjbabababa",
            "mkbabababa", "mlbabababa", "mmbabababa", "mnbabababa", "mobabababa", "mpbabababa", "mqbabababa",
            "mrbabababa", "msbabababa", "mtbabababa", "mubabababa", "mvbabababa", "mwbabababa", "mxbabababa",
            "mybabababa", "mzbabababa", "nababababa", "nbbabababa", "ncbabababa", "ndbabababa", "nebabababa",
            "nfbabababa", "ngbabababa", "nhbabababa", "nibabababa", "njbabababa", "nkbabababa", "nlbabababa",
            "nmbabababa", "nnbabababa", "nobabababa", "npbabababa", "nqbabababa", "nrbabababa", "nsbabababa",
            "ntbabababa", "nubabababa", "nvbabababa", "nwbabababa", "nxbabababa", "nybabababa", "nzbabababa",
            "oababababa", "obbabababa", "ocbabababa", "odbabababa", "oebabababa", "ofbabababa", "ogbabababa",
            "ohbabababa", "oibabababa", "ojbabababa", "okbabababa", "olbabababa", "ombabababa", "onbabababa",
            "oobabababa", "opbabababa", "oqbabababa", "orbabababa", "osbabababa", "otbabababa", "oubabababa",
            "ovbabababa", "owbabababa", "oxbabababa", "oybabababa", "ozbabababa", "pababababa", "pbbabababa",
            "pcbabababa", "pdbabababa", "pebabababa", "pfbabababa", "pgbabababa", "phbabababa", "pibabababa",
            "pjbabababa", "pkbabababa", "plbabababa", "pmbabababa", "pnbabababa", "pobabababa", "ppbabababa",
            "pqbabababa", "prbabababa", "psbabababa", "ptbabababa", "pubabababa", "pvbabababa", "pwbabababa",
            "pxbabababa", "pybabababa", "pzbabababa", "qababababa", "qbbabababa", "qcbabababa", "qdbabababa",
            "qebabababa", "qfbabababa", "qgbabababa", "qhbabababa", "qibabababa", "qjbabababa", "qkbabababa",
            "qlbabababa", "qmbabababa", "qnbabababa", "qobabababa", "qpbabababa", "qqbabababa", "qrbabababa",
            "qsbabababa", "qtbabababa", "qubabababa", "qvbabababa", "qwbabababa", "qxbabababa", "qybabababa",
            "qzbabababa", "rababababa", "rbbabababa", "rcbabababa", "rdbabababa", "rebabababa", "rfbabababa",
            "rgbabababa", "rhbabababa", "ribabababa", "rjbabababa", "rkbabababa", "rlbabababa", "rmbabababa",
            "rnbabababa", "robabababa", "rpbabababa", "rqbabababa", "rrbabababa", "rsbabababa", "rtbabababa",
            "rubabababa", "rvbabababa", "rwbabababa", "rxbabababa", "rybabababa", "rzbabababa", "sababababa",
            "sbbabababa", "scbabababa", "sdbabababa", "sebabababa", "sfbabababa", "sgbabababa", "shbabababa",
            "sibabababa", "sjbabababa", "skbabababa", "slbabababa", "smbabababa", "snbabababa", "sobabababa",
            "spbabababa", "sqbabababa", "srbabababa", "ssbabababa", "stbabababa", "subabababa", "svbabababa",
            "swbabababa", "sxbabababa", "sybabababa", "szbabababa", "tababababa", "tbbabababa", "tcbabababa",
            "tdbabababa", "tebabababa", "tfbabababa", "tgbabababa", "thbabababa", "tibabababa", "tjbabababa",
            "tkbabababa", "tlbabababa", "tmbabababa", "tnbabababa", "tobabababa", "tpbabababa", "tqbabababa",
            "trbabababa", "tsbabababa", "ttbabababa", "tubabababa", "tvbabababa", "twbabababa", "txbabababa",
            "tybabababa", "tzbabababa", "uababababa", "ubbabababa", "ucbabababa", "udbabababa", "uebabababa",
            "ufbabababa", "ugbabababa", "uhbabababa", "uibabababa", "ujbabababa", "ukbabababa", "ulbabababa",
            "umbabababa", "unbabababa", "uobabababa", "upbabababa", "uqbabababa", "urbabababa", "usbabababa",
            "utbabababa", "uubabababa", "uvbabababa", "uwbabababa", "uxbabababa", "uybabababa", "uzbabababa",
            "vababababa", "vbbabababa", "vcbabababa", "vdbabababa", "vebabababa", "vfbabababa", "vgbabababa",
            "vhbabababa", "vibabababa", "vjbabababa", "vkbabababa", "vlbabababa", "vmbabababa", "vnbabababa",
            "vobabababa", "vpbabababa", "vqbabababa", "vrbabababa", "vsbabababa", "vtbabababa", "vubabababa",
            "vvbabababa", "vwbabababa", "vxbabababa", "vybabababa", "vzbabababa", "wababababa", "wbbabababa",
            "wcbabababa", "wdbabababa", "webabababa", "wfbabababa", "wgbabababa", "whbabababa", "wibabababa",
            "wjbabababa", "wkbabababa", "wlbabababa", "wmbabababa", "wnbabababa", "wobabababa", "wpbabababa",
            "wqbabababa", "wrbabababa", "wsbabababa", "wtbabababa", "wubabababa", "wvbabababa", "wwbabababa",
            "wxbabababa", "wybabababa", "wzbabababa", "xababababa", "xbbabababa", "xcbabababa", "xdbabababa",
            "xebabababa", "xfbabababa", "xgbabababa", "xhbabababa", "xibabababa", "xjbabababa", "xkbabababa",
            "xlbabababa", "xmbabababa", "xnbabababa", "xobabababa", "xpbabababa", "xqbabababa", "xrbabababa",
            "xsbabababa", "xtbabababa", "xubabababa", "xvbabababa", "xwbabababa", "xxbabababa", "xybabababa",
            "xzbabababa", "yababababa", "ybbabababa", "ycbabababa", "ydbabababa", "yebabababa", "yfbabababa",
            "ygbabababa", "yhbabababa", "yibabababa", "yjbabababa", "ykbabababa", "ylbabababa", "ymbabababa",
            "ynbabababa", "yobabababa", "ypbabababa", "yqbabababa", "yrbabababa", "ysbabababa", "ytbabababa",
            "yubabababa", "yvbabababa", "ywbabababa", "yxbabababa", "yybabababa", "yzbabababa", "zababababa",
            "zbbabababa", "zcbabababa", "zdbabababa", "zebabababa", "zfbabababa", "zgbabababa", "zhbabababa",
            "zibabababa", "zjbabababa", "zkbabababa", "zlbabababa", "zmbabababa", "znbabababa", "zobabababa",
            "zpbabababa", "zqbabababa", "zrbabababa", "zsbabababa", "ztbabababa", "zubabababa", "zvbabababa",
            "zwbabababa", "zxbabababa", "zybabababa", "zzbabababa"
        ];
        // ["oath", "pea", "eat", "rain", "hklf", "hf"];
        Console.WriteLine(JsonSerializer.Serialize(FindWords(board, words)));
    }
}