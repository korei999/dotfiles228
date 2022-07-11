//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {"", "pulseaudio-control --icons-volume \" , \" --icon-muted \" \" --node-nicknames-from \"device.description\" --node-nickname \"alsa_output.usb-Focusrite_Scarlett_Solo_USB-00.analog-stereo: Speakers\" --node-nickname \"alsa_output.pci-0000_00_1f.3.analog-stereo: Mobo\" --node-nickname \"alsa_output.pci-0000_03_00.1.hdmi-stereo: Mon\" output",       3,             12},

	// {"﨏CPU:", "sensors | awk '/^Package id 0/ { print $4}' | sed s/i//g",     1,             0},

	{"﨏GPU:", "sensors | awk '/^junction/ { print $2}'",    		         1,             0},

	// {"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	    30,     		0},

	{"", "date '+%b %d (%a) %I:%M%p'",				                    	 1,	        	0},

	{" ", "xkblayout-state print %e",                                         0,             11}
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
