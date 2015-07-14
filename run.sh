#!/bin/bash
g++ -O3 ./src/TweetedWords.cpp -o ./tweetedwords 
./tweetedwords ./tweet_input/tweets.txt ./tweet_output/ft1.txt ./tweet_output/ft2.txt
