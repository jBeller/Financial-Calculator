#include "stdafx.h"
#include "Entry.h"

double Entry::e_calculate_value()
{
	double time_gap;            // In seconds
	double time_gap_converted;  // In weeks, months, or years depending on e_time
	time_t temp_end = e_start_date;
	struct tm* d;

	// If end date has not been specified (i.e. indefinite), set it to the end
	// of the same year as the start date (e.g. Dec 31, 2018 at 23:59:59)
	if (e_end_date == 0)
	{
		d = localtime(&temp_end);
		d->tm_sec = 59;
		d->tm_min = 59;
		d->tm_hour = 23;
		d->tm_mday = 31;
		d->tm_mon = 11;
		d->tm_yday = 365;
		temp_end = mktime(d);
		time_gap = difftime(temp_end, e_start_date);
	}
	else
		time_gap = difftime(e_end_date, e_start_date);

	switch (e_time)
	{
	case EntryTime::WEEKLY:
		// Convert time_gap to weeks (rounded down)
		time_gap_converted = floor(((((time_gap / 60) / 60) / 24) / 7));
		break;
	case EntryTime::MONTHLY:
		// Convert time_gap to months (rounded down)
		time_gap_converted = floor(((((time_gap / 60) / 60) / 24) / 30));
		break;
	case EntryTime::BIANNUALLY:
		// Convert time_gap to months (rounded down) then convert it to the
		// number of times 6 months have passed (also rounded down)
		time_gap_converted = floor(((((time_gap / 60) / 60) / 24) / 30));
		time_gap_converted = floor(time_gap_converted / 6);
		break;
	case EntryTime::ANNUALLY:
		// If end date was unspecified while ANNUALLY was specified, count 
		// the time gap as one year
		if (e_end_date == 0)
			time_gap_converted = 1;
		else
			// Convert time_gap to years (rounded down)
			time_gap_converted = floor(((((time_gap / 60) / 60) / 24) / 365));
		break;
	default: // Program should never get to this branch
		return -1.0;
		break;
	}

	if (e_type == EntryType::INCOME)
		return e_value * time_gap_converted;
	else if (e_type == EntryType::EXPENSE)
		return -(e_value * time_gap_converted);
	else // Program should never get to this branch here too
		return -1.0;
}
