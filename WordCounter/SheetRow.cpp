#include "stdafx.h"
#include "SheetRow.h"

SheetRow::SheetRow(std::string date, std::string day, std::string clue, std::string answer, char orientation)
{
	date_ = date;
	day_ = day;
	clue_ = clue;
	answer_ = answer;
	orientation_ = orientation;
}

std::string SheetRow::getDate() const
{
	return std::string(date_);
}

std::string SheetRow::getDay() const
{
	return std::string();
}

std::string SheetRow::getClue() const
{
	return std::string(clue_);
}

std::string SheetRow::getAnswer() const
{
	return std::string(answer_);
}

char SheetRow::getOrientation() const
{
	return char(orientation_);
}

bool SheetRow::operator==(SheetRow& row) const
{
	return (answer_ == row.answer_);
}


SheetRow::~SheetRow()
{
}
