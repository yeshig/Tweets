The application in this repository provides a solution to the Insight
Data Engineering Coding Challenge. The Code Challenge involves the development
of a code that emulates word count and median of tweeted words as each tweet 
comes in. For this challenge the task of reading tweets from tweeter.com is simplified by
reading lines of words saved in an input text file. The requirement of the 
challenge is to read the lines of codes in the input file and print the list of
"tweeted" words and their corresponding word count as a key-value pair in
an output file. Additionally, the code challenge asks the programmer to update 
the median of the total number of unique words as each "tweet" comes in. The 
files in this repository are designed to accomplish this task. 

The current directory consists source codes in the 'src/' subdirectory. The 
input file that represents incoming tweets is found in the 'tweet_input/' 
subdirectory. The outputs from running the code are found in two files within
the 'tweet_output' directory under the file name 'ft1.txt' and 'ft2.txt'. The 
former contains the list of words and their count in all "tweets". The later
consists data for the median of total words per tweet as that is updated as 
each tweet comes in. The directory also consists of a shell script 'run.sh' 
for compiling and running the code. The program takes three parameters as an
input and output file names. You may use the script to compile and run 
the program.
