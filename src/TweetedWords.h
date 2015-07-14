#include <map>
#include <vector>
#include <string>

using namespace std;

class TweetedWords
{
public:
	
	double median(map<string, int> &);
	void addWord(string);
	void sampleWordsDisplay(int);
	void printWordsToFile(string);
	
private:
	map <string, int> m_words;
	vector< int > m_numberofwords_per_tweet;
};
