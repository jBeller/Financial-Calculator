#pragma once
#include <unordered_map>
#include <list>
#include "Entry.h"

using std::unordered_map;
using std::list;

class User
{
private:
	string u_name;
	double u_balance;
	unordered_map<string, Entry*> u_entry;
	void u_modify_entry_name_private(string old_name, string new_name);
public:
	User(string name) : u_name(name), u_balance(0.00) {}
	User(string name, double balance) : u_name(name), u_balance(balance) {}
	~User();
	string u_get_name() { return u_name; }
	double u_get_balance() { return u_balance; }
	list<string> u_get_entry_list();
	double u_get_entry_value(string name);
	double u_calculate_entry(string name);
	EntryType u_get_entry_type(string name);
	EntryTime u_get_entry_time(string name);
	time_t u_get_entry_start_date(string name);
	time_t u_get_entry_end_date(string name);
	void u_modify_entry_name(string old_name, string new_name);
	void u_modify_entry_type(string name, EntryType type);
	void u_modify_entry_time(string name, EntryTime time);
	void u_modify_entry_value(string name, double value);
	void u_modify_entry_start(string name, time_t start);
	void u_modify_entry_end(string name, time_t end);
	void u_change_user_name(string name) { u_name = name; }
	void u_change_balance(double value) { u_balance = value; }
	void u_insert_entry(string name, EntryType type, EntryTime time, double value, time_t start, time_t end);
	void u_remove_entry(string name);
	bool u_entry_exists(string name);
};

