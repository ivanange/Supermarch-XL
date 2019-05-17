#include "../Headers/Date.h"
using namespace std;


    Date::Date() {
        _day = _month = _year = 0;
        _monthsWith30days = {9, 4, 6, 11};
    }
    Date::Date(unsigned day, unsigned month, unsigned year) {
		addDate(day, month, year);
    }
    Date::Date( string date) {
		addDateFromString(date );
	}
	
	void Date::addDateFromString( string date ) {
		try {
        	unsigned day = stoi( date.substr (0, date.find("/") ) );
        	date = date.substr(date.find("/") +1);
        	unsigned month = stoi( date.substr (0, date.find("/") ));
        	date = date.substr(date.find("/") +1);
        	unsigned year = stoi( date.substr (0));
        	addDate(day, month, year);
    	}
    	catch(char const* const& err) {
			throw err;
		}
    	catch(...){ throw("Date parse Error");		}
	}	
        
	void Date::addDate(unsigned day, unsigned month, unsigned year) {
    	
    	if( !(year >= 1000 ) ) { throw("Error in Date : Invalid value for  Year");}
    	if( !(month >= 1 && month <= 12) ) { throw("Error in Date : Invalid value for  Month");}
    	if( !(day >= 1) ) {	throw(" Error in Date :Invalid value for day"); }
		if( ( day > 30 && find(_monthsWith30days.begin(), _monthsWith30days.end(), month) == _monthsWith30days.end() ) || (month == 2 && ( (day > 29) || (day == 29 && year%4 != 0) ) ) ){  throw(" Error in Date : Invalid value for day"); }
		
        _day = day;
        _month = month;
        _year = year;
	}
	
	string Date::toString() const {
		string seperator = "/";
		return to_string(_day) + seperator + to_string(_month) +  seperator + to_string(_year) ;
	}
        


