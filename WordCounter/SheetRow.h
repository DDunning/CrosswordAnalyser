#pragma once
#include <string>

class SheetRow
{
public:
	~SheetRow();

	// constructor
	SheetRow(std::string inDate, std::string day, std::string inClue, std::string inAnswer, char inOrientation);

	std::string getDate() const;
	std::string getDay() const;
	std::string getClue() const;
	std::string getAnswer() const;
	char getOrientation() const;

	bool operator==(SheetRow& row) const;

private:
	std::string date_;
	std::string day_;
	std::string clue_;
	std::string answer_;
	char orientation_;

};

