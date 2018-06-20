#include "User.h"

User::~User()
{
	for (auto it = u_entry.begin(); it != u_entry.end(); it++)
		delete it->second;
}
list<string> User::u_get_entry_list()
{
	list<string> l;
	for (auto it = u_entry.begin(); it != u_entry.end(); it++)
		l.push_back(it->first);
	return l;
}
double User::u_calculate_entry(string name)
{
	if (!u_entry.count(name))
		return 0.0;
	else
		return u_entry[name]->e_calculate_value();
}
double User::u_get_entry_value(string name)
{
	if (!u_entry.count(name))
		return 0.0;
	else
		return u_entry[name]->e_get_value();
}
EntryType User::u_get_entry_type(string name)
{
	if (!u_entry.count(name))
		return EntryType::NA;
	else
		return u_entry[name]->e_get_type();
}
EntryTime User::u_get_entry_time(string name)
{
	if (!u_entry.count(name))
		return EntryTime::NA;
	else
		return u_entry[name]->e_get_time();
}
time_t User::u_get_entry_start_date(string name)
{
	if (!u_entry.count(name))
		return 0;
	else
		return u_entry[name]->e_get_start_date();
}
time_t User::u_get_entry_end_date(string name)
{
	if (!u_entry.count(name))
		return 0;
	else
		return u_entry[name]->e_get_end_date();
}
void User::u_modify_entry_name(string old_name, string new_name)
{
	// Does nothing if name specifed by old_name doesn't exist in the map
	// or new_name is the same os old_name
	if (!u_entry.count(old_name) || old_name == new_name)
		return;
	else
		u_modify_entry_name_private(old_name, new_name);
}
void User::u_modify_entry_name_private(string old_name, string new_name)
{
	u_entry[new_name] = u_entry[old_name];
	u_entry.erase(old_name);
	u_entry[new_name]->e_modify_name(new_name);
}
void User::u_modify_entry_type(string name, EntryType type)
{
	if (!u_entry.count(name))
		return;
	else
		return u_entry[name]->e_modify_type(type);
}
void User::u_modify_entry_time(string name, EntryTime time)
{
	if (!u_entry.count(name))
		return;
	else
		return u_entry[name]->e_modify_time(time);
}
void User::u_modify_entry_value(string name, double value)
{
	if (!u_entry.count(name))
		return;
	else
		return u_entry[name]->e_modify_value(value);
}
void User::u_modify_entry_start(string name, time_t start)
{
	if (!u_entry.count(name))
		return;
	else
		return u_entry[name]->e_modify_start_date(start);
}
void User::u_modify_entry_end(string name, time_t end)
{
	if (!u_entry.count(name))
		return;
	else
		return u_entry[name]->e_modify_end_date(end);
}
void User::u_insert_entry(string name, EntryType type, EntryTime time, double value, time_t start, time_t end)
{
	if (u_entry.count(name))
		return;

	Entry* e = new Entry(name, type, time, value, start, end);
	u_entry.insert(std::pair<string, Entry*>(name, e));
	e = NULL;
}
void User::u_remove_entry(string name)
{
	auto it = u_entry.find(name);
	if (it == u_entry.end())
		return;

	delete it->second;
	u_entry.erase(it);
}
bool User::u_entry_exists(string name)
{
	if (u_entry.count(name))
		return true;
	else
		return false;
}