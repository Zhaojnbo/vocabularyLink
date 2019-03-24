#include "DebugInfo.h"
#include "InputParser.h"
#include "WordGraph.h"
#include "readFile.h"
#include "findAllWordList.h"
#include "DebugTime.h"
#include "WordMost.h"

using namespace std;

int doCalc(char *ret, std::vector <std::string> &words, const char *argv[]) {
	DebugTime t;

	// parse input
	InputParser inputParser(argv);
	inputParser.parse();
	t.printTimeAndRestart("Parse Input");
#ifndef NDEBUG
	cout << endl << "------args information-------" << endl;
	inputParser.print(cout) << endl;
#endif

	// create graph
	WordGraph graph;
	for (const auto &s : words) graph.createArc(s);
	graph.setRevArc();
	t.printTimeAndRestart("Create Graph");
#ifndef NDEBUG
	cout << endl << "------graph information------" << endl;
	graph.print(cout) << endl;
	cout << endl << "--reverse graph information--" << endl;
	graph.printrev(cout) << endl;
#endif

	// calculate
	if (inputParser.getWordNum() != -1) {
#ifndef NDEBUGTIME
		cout << endl << "Detail Time For Calculate: " << endl;
#endif
		findAllWordList(
			ret, 
			graph, 
			inputParser.getWordNum(), 
			inputParser.getFirstChar(), 
			inputParser.getLastChar()
		);
	} else {
		// no word number limit
		WordMost mostSearch(
			graph, 
			inputParser.maximumChar(),
			inputParser.getFirstChar(), 
			inputParser.getLastChar()
		);
		mostSearch.setTimeLimit(2000);
		mostSearch.exec();
		for (int i = 0; i < mostSearch.maxQlist.size(); i++)
		{
			strcat(ret, mostSearch.maxQlist[i].value.c_str());
			strcat(ret, "\n");
		}
	}
	t.printTime("\nCalculate Total");
	return 0;
}
