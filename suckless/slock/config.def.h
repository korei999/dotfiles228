/* user and group to drop privileges to */
static const char *user  = "korei";
static const char *group = "wheel";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#c6a280",   /* during input */
	[FAILED] = "#cb565d",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
