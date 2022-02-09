//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"CPU:", "sensors | awk '/^Package id 0/ { print $4}' | sed s/i//g",     5,             0},

	{"GPU:+", "nvidia-settings -q gpucoretemp -t | sed 2d",    		 5,             0},

	{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},

	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},

	{"", "xkblayout-state print %e",                                      0,              11}
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
