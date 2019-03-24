#include "findAllWordList.h"
#include "DebugInfo.h"

using namespace std;
#define OUTPUT_FILE "solution.txt"
static vector<const string *>::size_type depthLimit;
static vector<const string *> wordlist;
static char *buf;
static ptrdiff_t off = 0;
static int num = 0;
static char endc;

static DebugTime t_writefile;

static inline void openFile() {
	off += sprintf(buf + off, "           \n");
}

static inline void closeFile() {
	off = sprintf(buf, "%d", num);
	buf[off] = ' ';
}

static inline void writeListToFile(const char *s) {	// s is the last string 
	t_writefile.continueAfterPause();
	++num;
	for (const auto *s : wordlist) {
		off += sprintf(buf + off, "%s\n", s->c_str());
	}
	off += sprintf(buf + off, "%s\n\n", s);
	t_writefile.pause();
}

static inline void revWriteListToFile(const char *s) {	// s is the first string 
	t_writefile.continueAfterPause();
	++num;
	off += sprintf(buf + off, "%s\n", s);
	for (auto it = wordlist.cend(); it != wordlist.cbegin(); --it) {
		off += sprintf(buf + off, "%s\n", (*(it - 1))->c_str());
	}
	off += sprintf(buf + off, "\n");
	t_writefile.pause();
}

static void DLS(const Vertex &v) {
	if (wordlist.size() == depthLimit) {
		for (const auto &arc : v.adjArcs()) {
			if (arc.isStar() == false) {
				writeListToFile(arc.getName().c_str());
			}
		}
	} else {
		for (const auto &arc : v.adjArcs()) {
			if (arc.isStar() == false) {
				arc.setStar();
				wordlist.push_back(&arc.getName());
				DLS(arc.adjVex());
				wordlist.pop_back();
				arc.clearStar();
			}
		}
	}
}

static void DLSWithEnd(const Vertex &v) {
	if (wordlist.size() == depthLimit) {
		for (const auto &arc : v.adjArcs()) {
			if (arc.adjVexName() == endc && arc.isStar() == false) {
				writeListToFile(arc.getName().c_str());
			}
		}
	} else {
		for (const auto &arc : v.adjArcs()) {
			if (arc.isStar() == false) {
				arc.setStar();
				wordlist.push_back(&arc.getName());
				DLSWithEnd(arc.adjVex());
				wordlist.pop_back();
				arc.clearStar();
			}
		}
	}
}

static void revDLS(const Vertex &v) {
	if (wordlist.size() == depthLimit) {
		for (const auto *arc : v.revAdjArcsPtr()) {
			if (arc->isStar() == false) {
				revWriteListToFile(arc->getName().c_str());	
			}
		}
	} else {
		for (const auto *arc : v.revAdjArcsPtr()) {
			if (arc->isStar() == false) {
				arc->setStar();
				wordlist.push_back(&arc->getName());
				revDLS(arc->revAdjVex());
				wordlist.pop_back();
				arc->clearStar();
			}
		}
	}
}

void findAllWordList(char *ret, const WordGraph &graph, int wordnum, char b, char e) {

	DebugTime t;
	buf = ret;
	openFile();
	depthLimit = wordnum - 1;
	t.printTimeAndRestart("\tOpen File And Preprocessing");

	t_writefile.restartAndPause();
	if (b == '\0' && e == '\0') {
		for (const auto &v : graph.getAllVertex()) 
			DLS(v);
	} else if (b && e == '\0') {
		DLS(graph.getVertex(b));
	} else if (b == '\0' && e) {
		revDLS(graph.getVertex(e));
	} else {
		endc = e;
		DLSWithEnd(graph.getVertex(b));
	}
	t.printTimeAndRestart("\tDLS", cout, t_writefile.getSeconds());
	t_writefile.printTime("\tWrite File");

	closeFile();
	t.printTime("\tClose File");
}
