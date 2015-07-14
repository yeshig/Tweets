/* 
Lists words and their counts as they are read from an input file 
that imulates tweeted words. The code also calculates the median
of the total number of uniques words as each line in the file is
read.
*/
#include "TweetedWords.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>

//Calculates the median of tweeted words as they come in and 
//returns the median value
double TweetedWords::median(map<string, int> & tweeted_words)
{
	double d_median;
	m_numberofwords_per_tweet.push_back(tweeted_words.size());
	
	//sorts the number of tweeted words that are accumulated in a map variable
	sort(m_numberofwords_per_tweet.begin(), m_numberofwords_per_tweet.end());

	//calculates the median based on an even or odd numbers of the list in the map 
	if (m_numberofwords_per_tweet.size() % 2 == 0)
	{
		d_median = (m_numberofwords_per_tweet.at(m_numberofwords_per_tweet.size() / 2 - 1)
			+ m_numberofwords_per_tweet.at(m_numberofwords_per_tweet.size() / 2)) / 2.0;
	}
	else
	{
		d_median = m_numberofwords_per_tweet.at((m_numberofwords_per_tweet.size() + 1) / 2 - 1);
	}
       
        return d_median;
}

//accumulates words and the corresponding word count in a member map member variable 
void TweetedWords::addWord(string word)
{
	m_words[word]++;
}

//Displays sample output to the standard output for easy assessing
// nHead sets the number of words to be printed to the screen
void TweetedWords::sampleWordsDisplay(int nHead)
{
	map<string, int>::iterator it;
	int count = 0;
	
	for (it = m_words.begin(); it != m_words.end(); it++)
	{
		cout << setw(30) << left << it->first << it->second <<endl;
		count++;
		// If the number is greater than the selected 'nHead' skip the loop.
		if (count > nHead)
			break;
	}

}

//prints the words and the corresponding word count that are accumulated 
//in the member map variable into a file
void TweetedWords::printWordsToFile(string file)
{
	ofstream fout;
	fout.open(file);
	map<string, int>::iterator it;
	for (it = m_words.begin(); it != m_words.end(); it++)
	{
		fout << setw(30) << left << it->first << it->second << endl;
	}
	fout.close();
}

int main(int argc, char* argv[])
{
	int nHead = 10;

	string inputFile = argv[1]; 
	string firstoutputFile = argv[2]; 
	string secondoutputFile = argv[3]; 
      
	TweetedWords *tw = new TweetedWords();

	//If the file exists, open file for reading. Otherwise, demand
	//the user to enter the correct file name or exit after few attempts.
	ifstream fin;
	fin.open(inputFile);
	int nAttempts = 0;
	while (!fin.is_open())
	{
		cout << "Unable to open file: " << inputFile <<endl;
		cout << "Enter filename, e.g., ./tweet_input/tweets.txt : ";
		cin >> inputFile;
		fin.open(inputFile);
		if (nAttempts == 2)
		{
			cout << "Sorry, unable to open the file. ";  
                        cout << "Check the file name and the path." << endl;
			exit(0);
		}
		nAttempts++;
	}

        //opens output file to append the calculated median value
        ofstream fout;
        fout.open(secondoutputFile); 
	
	//Read the file line by line and add words to a member map variable
	//and calculate the median on the fly as new lines come in.
	string line;
	while (getline(fin, line))
	{
		istringstream ss(line);
		string a_word;
		map <string, int> words_per_tweet;
		while (ss >> a_word)
		{
			tw->addWord(a_word);
			words_per_tweet[a_word]++;
		}

		//calls a function that calculates the median as each "tweet" comes in
		//and appends the  median to a file 
                fout << tw->median(words_per_tweet) <<endl;
               
	}
	fin.close();
        fout.close();

	//Diplays the top 'nHead' of tweeted words that are ordered according to 
	//the ASCII code.
	tw->sampleWordsDisplay(nHead);

	//Saves the list of tweeted words into a file
	tw->printWordsToFile(firstoutputFile);

	return 0;
}
