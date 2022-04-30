//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {"", "pulseaudio-control --icons-volume \" , \" --icon-muted \" \" --sink-nicknames-from \"device.description\" --sink-nickname \"alsa_output.usb-Focusrite_Scarlett_Solo_USB-00.analog-stereo: Speakers\" --sink-nickname \"alsa_output.pci-0000_00_1f.3.analog-stereo: Mobo\" output",       3,             12},

	{"CPU:", "sensors | awk '/^Package id 0/ { print $4}' | sed s/i//g",     1,             0},

	{"GPU:+", "nvidia-settings -q gpucoretemp -t | sed 2d",    		         1,             0},

	{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	    30,     		0},

	{"", "date '+%b %d (%a) %I:%M%p'",				                    	 1,	        	0},

	{"", "xkblayout-state print %e",                                         0,             11}
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
