#ifndef DEF_DATE
#define DEF_DATE

#include<string>
#include<vector>
#include <algorithm>

class Date {
    private:
        unsigned _day;
        unsigned _month;
        unsigned _year;
        std::vector<unsigned> _monthsWith30days;
        
    public:
        Date();
        Date(unsigned day, unsigned month, unsigned year);
        Date( std::string date);
		void addDateFromString( std::string date );	   
		void addDate(unsigned day, unsigned month, unsigned year);
		std::string toString() const;
        
};

#endif
