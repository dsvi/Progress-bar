#include <coformat.h>
#include <cassert>
#include "progress_bar.h"

using namespace std;
using namespace coformat;

Progress_bar::Progress_bar()
{
}

static
void append(std::string &to, const std::string &from, unsigned times){
	while (times--)
		to += from;	
}

void Progress_bar::update(uint64_t progress)
{
	if (!is_colorized())
		return;
	if (progress == 0){
		current_percent = 0;
		percent_str = "0";
		bar.clear();
		show();		
		return;
	}
	assert(min < max); // since progress is non 0
	assert(min <= progress and progress <= max);
	auto new_percent = (progress - min)*100/(max - min);
	if (current_percent == new_percent)
		return;
	current_percent = new_percent;
	percent_str = to_string(current_percent);
	bar.clear();	
	auto bar_progress_len = (progress - min)*width/(max - min);
	append(bar, bar_filled, bar_progress_len);
	append(bar, bar_empty,  width - bar_progress_len);
	show();
}

void Progress_bar::show()
{
	if (!is_colorized())
		return;
	if (bar.empty())
		append(bar, bar_empty, width);
	cprintln("{fy}{}{fd} {}%", bar, percent_str);
	clear_previous_line();
}
