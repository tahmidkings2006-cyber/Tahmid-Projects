//Sets all the functions and variables for the program
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>


using namespace std;

//Constants that stay the same throughout the program
const int MAX_CANDIDATES = 5;
const int MAX_VOTES = 100;

//Function prototypes defined later in the program
string getFileName();
bool loadVotes(const string &fileName, string candidates[], int votes[], int &candidateCount);
int findCandidateIndex(const string& name, const string candidates[], int candidateCount);
string toLower(const string& str);
string toTitle(const string& str);
void printVoteCounts(const string candidates[], const int votes[], int candidateCount);
void printHistogram(const string candidates[], const int votes[], int candidateCount);

//Main function that runs the program and calls the other functions
//The main functions displays the vote counts and histogram
int main() {
    string candidates[MAX_CANDIDATES];
    int votes[MAX_CANDIDATES] = {0};
    int candidateCount = 0;
    string fileName;
    bool loadedFile = false;
    //Loop that runs until the file is loaded successfully
    do {
        fileName = getFileName();
        loadedFile = loadVotes(fileName, candidates, votes, candidateCount);
        if (!loadedFile) {
            cout << "Failed to open file" << endl;
        }
    } //Loop that runs until the file is loaded successfully
        while (!loadedFile);

    if (candidateCount > 0) {
        printVoteCounts(candidates, votes, candidateCount);
        cout << endl;
        printHistogram(candidates, votes, candidateCount);
    }
    return 0;
}

//Takes input from the user and returns the file name
string getFileName() {
    string filename;
    cout << "What is the file name? " << endl;
    cin >> filename;
    return filename;
}

//Loads the votes from the file and stores them in the candidates and votes arrays
bool loadVotes(const string& filename, string candidates[], int votes[], int &candidateCount) {
    ifstream file(filename);
    if (!file) {
        return false;
    }

    string vote;
    candidateCount = 0;

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        votes[i] = 0;
    }

    // read each vote from the file and process it
    while (getline(file, vote)) {
        if (vote != "") {
            string normalizedVote = toLower(vote);
            int index = findCandidateIndex(normalizedVote, candidates, candidateCount);
            if (index == -1) {
                if (candidateCount < MAX_CANDIDATES) {
                    candidates[candidateCount] = toTitle(vote);
                    votes[candidateCount] = 1;
                    candidateCount++;
                }
            } else {
                votes[index]++;
            }
        }
    }
    file.close();
    return true;
}

// find the index of a candidate in the candidates array
int findCandidateIndex(const string& name, const string candidates[], int candidateCount) {
    // iterate through each candidate in the candidates array
    for (int i = 0; i < candidateCount; i++) {
        if (toLower(candidates[i]) == name) {
            return i;
        }
    }
    return -1;
}

// convert entire string to lowercase
string toLower(const string& str) {
    string result = str;
    // iterate through each character in the string
    for (int i = 0; i < (int)result.length(); i++) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] - 'A' + 'a';
        }
    }
    return result;
}

// convert string to Title Case (capitalize each word)
string toTitle(const string& str) {
    string result = str;
    bool newWord = true;
// iterate through each character in the string
    for (int i = 0; i < (int)result.length(); i++) {
        if (newWord && ((result[i] >= 'a' && result[i] <= 'z') || (result[i] >= 'A' && result[i] <= 'Z'))) {
            // uppercase first letter of new word
            if (result[i] >= 'a' && result[i] <= 'z') {
                result[i] = result[i] - 'a' + 'A';
            }
            newWord = false;
        } else if (isspace(result[i])) {
            newWord = true;  // next character starts a new word
        } else {
            // lowercase letters inside words
            if (result[i] >= 'A' && result[i] <= 'Z') {
                result[i] = result[i] - 'A' + 'a';
            }
            newWord = false;
        }
    }

    return result;
}

//Prints the vote counts for each candidate in the candidates array
void printVoteCounts(const string candidates[], const int votes[], int candidateCount) {
    cout << "Vote Counts:" << endl;
    // print each candidate's name and vote count
    for (int i = 0; i < candidateCount; i++) {
        cout << candidates[i] << ": " << votes[i] << endl;
    }
}

//Prints the histogram for each candidate in the candidates array
void printHistogram(const string candidates[], const int votes[], int candidateCount) {
    cout << "Histogram:" << endl;
    // print each candidate's name and histogram
    for (int i = 0; i < candidateCount; i++) {
        cout << candidates[i] << ": ";
        // print histogram for each candidate
        for (int j = 0; j < votes[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
