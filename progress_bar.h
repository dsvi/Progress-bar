#pragma once
#include <string>

/// draws progress bar in terminal.
/// does nothing if redirected to a file.
/// disappears when something else is printed to the terminal.
/// appears again on update() or show()
///
/// ████████████████████████████████░░░░░░░░░░░░░░░░░░ 63%
///
/// all parameters can be changed even after the first update() or show()
class Progress_bar
{
public:
	Progress_bar();
	std::string bar_filled = "█";
	std::string bar_empty  = "░";
	/// min should always be <= #max
	uint64_t min = 0;
	uint64_t max = 100;
	/// width of the bar in characters.
	unsigned width = 60;
	/// updates progress. if percentage has changed, calls show()
	/// @param progress #min <= progress <= #max
	void update(uint64_t progress);
	/// draws indicator to terminal.
	void show();
private:
	uint64_t current_percent = 0;
	std::string bar;
	std::string percent_str = "0";
};

