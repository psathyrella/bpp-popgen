/*
 * File Date.cpp
 * Author : Sylvain Gaillard <yragael2001@yahoo.fr>
 * Last modification : Thursday April 22 2004
 */

// From Utils
#include <Utils/TextTools.h>

//From Local
#include "Date.h"

//** Class constructor: *******************************************************/
Date::Date(const int day, const int month, const int year) {
	_day = day;
	_month = month;
	_year = year;
}

Date::Date(const Date & date) {
	this->_day = date.getDay();
	this->_month = date.getMonth();
	this->_year = date.getYear();
}
//** Class destructor: ********************************************************/
Date::~Date() {}

//** Other methodes: **********************************************************/
Clonable * Date::clone() const {
	return new Date(* this);
}

Date & Date::operator= (const Date & date) {
	this->_day = date.getDay();
	this->_month = date.getMonth();
	this->_year = date.getYear();
	return * this;
}

void Date::setDate(const int day, const int month, const int year) {
	_day = day;
	_month = month;
	_year = year;
}

void Date::setYear(const int year) {
	_year = year;
}

void Date::setMonth(const int month) {
	_month = month;
}

void Date::setDay(const int day) {
	_day = day;
}

string Date::getDate() const {
	string date, uDay="", uMonth="";
	if (_day < 10) uDay="0";
	if (_month < 10) uMonth="0";
	date = uDay + TextTools::toString(_day) + uMonth + TextTools::toString(_month) + TextTools::toString(_year);
	return date;
}

int Date::getYear() const {
	return _year;
}

int Date::getMonth() const {
	return _month;
}

int Date::getDay() const {
	return _day;
}

bool Date::operator==(const Date & date) const {
	if (_day == date.getDay() && _month == date.getMonth() && _year == date.getYear())
		return true;
	else
		return false;
}

bool Date::operator<(const Date & date) const {
	if (_year < date.getYear() || (_month < date.getMonth() && _year == date.getYear()) || (_day < date.getDay() && _month == date.getMonth() && _year == date.getYear()))
		return true;
	else
		return false;
}
