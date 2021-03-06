// WordCounter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "SheetRow.h"

// forward references
int readFile(std::string filename, std::vector<SheetRow>& vector);
bool splitLine(std::string text, std::vector<std::string>& vector, int lineNumber, char delimiter = '\t');
std::string removeQuotes(std::string text, int lineNumber);


// tryFeatures
// Somewhere to try out syntax and exercise objects.
void tryFeatures() {

	std::vector<SheetRow> clues;

	SheetRow firstRow{ "24-01-2019", "Mon", "First clue", "Solution1", 'a' };
	SheetRow secondRow{ "24-01-2019", "Mon", "Second clue", "Solution2", 'd' };
	SheetRow thirdRow{ "24-01-2019", "Mon", "Third clue", "Solution1", 'd' };

	clues.insert(clues.end(), { firstRow, secondRow, thirdRow });


	if (clues[0] == clues[1])
		std::cout << "[0] equals [1]: " << clues[1].getAnswer() << "\n";

	if (clues[0] == clues[2])
		std::cout << "[0] equals [2]: " << clues[2].getAnswer() << "\n";


	for (SheetRow row : clues)
		std::cout << row.getClue() << "\n";

}

// Build a list of unique answers with a frequency count.
void countUniqueAnswers(std::vector<SheetRow> rows, std::map<std::string, int>& answers){

	// for each row in rows
	//     if row.answer is in the answers
	//         add one to the answers.int
	//     else
	//         add new item to answers, with count of one
	//     endif
	// endfor

	//auto iterator = find(rows.begin(), rows.end(), )
}

int main(int argc, char *argv[])
{
	//tryFeatures();
	//return 0;

	// validate the command line arguments
	if (argc <= 1) {
		std::cout << "Usage: WordCounter <text-filename>";
		exit(1);
	}

	// read in the crossword data from the file given on the command line
	std::vector<SheetRow> clues;
	std::string filename(argv[1]);
	readFile(filename, clues);
	std::cout << clues.size() << " lines read from file." << std::endl;

	// analyze the data
	std::map<std::string, int> uniqueAnswers {};
	countUniqueAnswers(clues, uniqueAnswers);

	// TODO printout the results

    return 0;
}

int readFile(std::string filename, std::vector<SheetRow>& vector) {

	std::cout << "Filename is " << filename << std::endl;

	std::ifstream incoming(filename);
	if (incoming.is_open()) {
		std::string titles;
		getline(incoming, titles);
		std::cout << "Column titles are \"" << titles << "\"" << std::endl;

		int lineNumber = 1;
		while (!incoming.eof()) {
			std::string line;
			getline(incoming, line);
			lineNumber++;

			// split on tab boundaries
			std::vector<std::string> parts;
			if ( splitLine(line, parts, lineNumber) ) {
				if (parts.size() == 5) {
					SheetRow row{ parts[0], parts[1], parts[2], parts[3], parts[4][0] };
					vector.push_back(row);
				}
				else {
					std::cout << "There are not 5 fields on line " << lineNumber << std::endl;
				}
			}
		}
		incoming.close();
	}
	else {
		std::cout << "Unable to open the file " << filename;
	}
	return 0;
}

// Split the given line of text at the delimiters. Return the parts in the vector.
bool splitLine(std::string text, std::vector<std::string>& vector, int lineNumber, char delimiter) {

	int startOfField = 0;
	for (unsigned int i = 0; i < text.size(); i++) {

		if (text[i] == delimiter) {
			std::string field = text.substr(startOfField, i - startOfField);
			std::string bareField = removeQuotes(field, lineNumber);
			vector.push_back(bareField);
			startOfField = i + 1;
		}
	}
	std::string lastField = text.substr(startOfField, text.size() - startOfField);
	vector.push_back(lastField);

	return true;
}

// Remove leading and trailing double quotes from the given string, if present.
std::string removeQuotes(std::string text, int lineNumber) {
	if (text.size() >= 2) {

		unsigned int first = 0;
		unsigned int last = text.size() - 1;

		if (text[first] == '"') {
			first++;
			if (text[last] == '"') {
				last--;
			}
			else {
				std::cout << "Leading quote but no trailing quote on line "
					<< lineNumber << std::endl;
			}
			return text.substr(first, last);
		}
	}
	return text;
}

