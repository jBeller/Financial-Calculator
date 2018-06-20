#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <string>
#include <ctime>
#include <cmath>

using std::string;

enum class EntryType {INCOME, EXPENSE, NA};
enum class EntryTime {WEEKLY, MONTHLY, BIANNUALLY, ANNUALLY, NA};

class Entry
{
private:
	string e_name;
	EntryType e_type;
	EntryTime e_time;
	double e_value;
	time_t e_start_date;
	time_t e_end_date;   // Optional field (Indefinite if unspecified)
public:
	Entry(string name, EntryType type, EntryTime time, double value, time_t start)
		: e_name(name), e_type(type), e_time(time), e_value(value), e_start_date(start), e_end_date(0) {}
	Entry(string name, EntryType type, EntryTime time, double value, time_t start, time_t end)
		: e_name(name), e_type(type), e_time(time), e_value(value), e_start_date(start), e_end_date(end) {}
	string e_get_name() { return e_name; }
	EntryType e_get_type() { return e_type; }
	EntryTime e_get_time() { return e_time; }
	double e_get_value() { return e_value; }
	time_t e_get_start_date() { return e_start_date; }
	time_t e_get_end_date() { return e_end_date; }
	double e_calculate_value();
	void e_modify_name(string name) { e_name = name; }
	void e_modify_type(EntryType type) { e_type = type; }
	void e_modify_time(EntryTime time) { e_time = time; }
	void e_modify_value(double value) { e_value = value; }
	void e_modify_start_date(time_t start) { e_start_date = start; }
	void e_modify_end_date(time_t end) { e_end_date = end; }
};

#endif  // __ENTRY_H__