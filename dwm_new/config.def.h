/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 24;       /* snap pixel */

static const unsigned int gappih    = 0;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 0;       /* vert inner gap between windows */
static const unsigned int gappoh    = 0;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 0;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */

static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Ubuntu Nerd Font:size=15" };
static const char dmenufont[]       = "Ubuntu Nerd Font:size=15";
static const int user_bh            = 27;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */

static const char norm_fg[] = "#dfdfdf";
static const char norm_bg[] = "#000000";
static const char norm_border[] = "#000000";

static const char sel_fg[] = "#dfdfdf";
static const char sel_bg[] = "#674ea7";
static const char sel_border[] = "#674ea7";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Sxiv",     NULL,       NULL,       0,            1,           -1 },
	{ "mpv",      NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *rofi2[] = { "rofi", "-show", "run"};
static const char *rofi[] = { "rofi", "-show", "drun"};
static const char *termcmd[]  = { "tabbed", "-r", "2", "st", "-w", "\'\'", NULL };
static const char *scrotcmd[]  = { "scrot", "/home/korei/Pictures/Screens/%Y-%m-%d-%T-screenshot.png", NULL };
static const char *scrotscmd[]  = { "scrot", "/home/korei/Pictures/Screens/%Y-%m-%d-%T-screenshot.png", "-s", "-f", NULL };
static const char *scrotucmd[]  = { "scrot", "/home/korei/Pictures/Screens/%Y-%m-%d-%T-screenshot.png", "-u", NULL };
static const char *keeb[] = {"pkill", "-RTMIN+11", "dwmblocks", NULL };
static const char *AudioUpdate[] = {"pkill", "-RTMIN+12", "dwmblocks", NULL };
static const char *pcmanfm[] = {"pcmanfm", NULL};
static const char *AudioPlay[] = {"playerctl", "play-pause", NULL};
static const char *AudioNext[] = {"playerctl", "next", NULL};
static const char *AudioPrev[] = {"playerctl", "previous", NULL};
static const char *AudioLower[] = {"pulseaudio-control", "--volume-max", "100", "down", NULL};
static const char *AudioRaise[] = {"pulseaudio-control", "--volume-max", "100", "up", NULL};

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier                     key        function        argument */
    { 0,                XF86XK_AudioPlay,	   spawn,	       {.v = AudioPlay} },
    { 0,                XF86XK_AudioPause,	   spawn,	       {.v = AudioPlay} },
    { 0,	    	    XF86XK_AudioNext,	   spawn,	       {.v = AudioNext} },
    { 0,    			XF86XK_AudioPrev,	   spawn,	       {.v = AudioPrev} },
    { 0,          XF86XK_AudioLowerVolume,	   spawn,	       {.v = AudioLower} },
    { 0,          XF86XK_AudioRaiseVolume,	   spawn,	       {.v = AudioRaise} },
    { 0,          XF86XK_AudioLowerVolume,	   spawn,	       {.v = AudioUpdate} },
    { 0,          XF86XK_AudioRaiseVolume,	   spawn,	       {.v = AudioUpdate} },
	{ MODKEY,			            XK_e,	   spawn,	       {.v = pcmanfm} },
	{ MODKEY,		            	XK_space,  spawn,	       {.v = keeb} },
	{ MODKEY,                       XK_Print,  spawn,          {.v = scrotcmd} },
	{ MODKEY|ShiftMask,             XK_Print,  spawn,          {.v = scrotscmd} },
	{ MODKEY|ControlMask,           XK_Print,  spawn,          {.v = scrotucmd} },
    { MODKEY,                       XK_p,      spawn,          {.v = rofi } },
    { MODKEY|ShiftMask,             XK_p,      spawn,          {.v = rofi2 } },
	// { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_k,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_i,      focusstack,     {.i = -1 } },
	// { MODKEY|ControlMask,           XK_i,      incnmaster,     {.i = +1 } },
	// { MODKEY|ControlMask,           XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_j,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_g,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_w,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_s,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_f,      togglefullscr,  {0} },
	// { MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_grave,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                XK_bracketleft,   rotatetags,     {.i = -1 } },
	{ MODKEY,                XK_bracketright,  rotatetags,     {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
    TAGKEYS(                        XK_0,                      9)
	{ MODKEY|Mod1Mask,              XK_q,      quit,           {0} },
   	{ MODKEY|Mod1Mask,              XK_r,      quit,           {1} }
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {

	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,	        MODKEY,	    	Button4,    	rotatetags,	{.i = -1 } },
	{ ClkTagBar,		    MODKEY,	    	Button5,    	rotatetags,	{.i = +1 } },
 	{ ClkLtSymbol,		    MODKEY,	    	Button4,    	rotatetags,	{.i = -1 } },
	{ ClkLtSymbol,		    MODKEY,	    	Button5,    	rotatetags,	{.i = +1 } },
 	{ ClkStatusText,        MODKEY,	    	Button4,    	rotatetags,	{.i = -1 } },
	{ ClkStatusText,        MODKEY,	    	Button5,    	rotatetags,	{.i = +1 } },
 	{ ClkWinTitle,	    	MODKEY,	    	Button4,    	rotatetags,	{.i = -1 } },
	{ ClkWinTitle,	    	MODKEY,	    	Button5,    	rotatetags,	{.i = +1 } },
 	{ ClkClientWin,	        MODKEY,	    	Button4,    	rotatetags,	{.i = -1 } },
	{ ClkClientWin,         MODKEY,	    	Button5,    	rotatetags,	{.i = +1 } },
 	{ ClkRootWin,	        MODKEY,	    	Button4,    	rotatetags,	{.i = -1 } },
	{ ClkRootWin,		    MODKEY,	    	Button5,    	rotatetags,	{.i = +1 } },
};
