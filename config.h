/* appearance */
static const unsigned int borderpx			= 2;
static const unsigned int snap				= 32;
static const unsigned int systraypinning	= 0;
static const unsigned int systrayspacing	= 2;
static const int systraypinningfailfirst	= 1;
static const int showsystray				= 1;
static const int showbar					= 1;
static const int topbar						= 0; 
static const char *fonts[]					= { "monospace:size=16" };
static const char dmenufont[]				= "monospace:size=16";
static const unsigned int gappih			= 10;       /* horiz inner gap between windows */
static const unsigned int gappiv			= 10;       /* vert inner gap between windows */
static const unsigned int gappoh			= 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov			= 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps					= 0;        /* 1 means no outer gap when there is only one window */
static const char col_background[]			= "#2e3440";
static const char col_currentline[]			= "#44475a";
static const char col_selection[]			= "#4c566a";
static const char col_foreground[]			= "#d8dee9";
static const char col_comment[]				= "#6272a4";
static const char col_cyan[]				= "#88c0d0";
static const char col_green[]				= "#50fa7b";
static const char col_orange[]  			= "#ffb86c";
static const char col_pink[]				= "#ff79c6";
static const char col_purple[]				= "#bd93f9";
static const char col_red[]					= "#bd616a";
static const char col_yello[]				= "#ebcb8b";
static const unsigned int baralpha			= 0xd0;
static const unsigned int borderalpha		= OPAQUE;
static const char *colors[][3]				=
{
	/*					fg             bg             border   */
	[SchemeNorm] = { col_foreground, col_background, col_background },
	[SchemeSel]  = { col_foreground, col_selection,  col_cyan  },
	[SchemeHid]  = { col_selection, col_background, col_background},
};

static const unsigned int alphas[][3] = 
{
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
//static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };
static const char *tags[] = { "\uf120", "\uf7ae", "\uf121", "\uf04b", "\ue62e", "\uf251", "\ue727", "\uf537", "\uf684" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
};
/* layout(s) */
static const float mfact     = 0.80;
static const int nmaster     = 1;
static const int resizehints = 0;

static const Layout layouts[] =
{
	/* symbol     arrange function */
	{ "P",        tile },
	{ "DI",       NULL },
	{ "D",        monocle },
};

/* key definitions */
#define MODKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *roficmd[] =			{ "rofi", "-show", "run", NULL };
static const char *termcmd[]  =			{ "alacritty", NULL };
static const char scratchpadname[] =		"scratchpad";
static const char *scratchpadcmd[] =		{ "st", "-t", scratchpadname, "-g", "100x30", NULL };
static const char *web_browser_cmd[]  =		{ "google-chrome-stable", NULL };
static const char *qq_cmd[]  =			{ "/opt/deepinwine/apps/Deepin-TIM/run.sh", NULL };
static const char *stardict_cmd[]  =		{ "stardict", NULL };
//static const char *logout_cmd[]  =		{ "pkill", "startdwm", NULL };
static const char *reboot_cmd[]  =		{ "reboot", NULL };
static const char *poweroff_cmd[]  =		{ "poweroff", NULL };
static const char *volumeup[] =			{ "amixer", "-q", "sset", "Master", "5%+", NULL };
static const char *volumedown[] =		{ "amixer", "-q", "sset", "Master", "5%-", NULL };
static const char *volumetoggle[] =		{ "amixer", "-q", "sset", "Master", "toggle", NULL };
static const char *volumemax[] =		{ "amixer", "-q", "sset", "Master", "100%", NULL };
static const char *typora[] =			{"typora",NULL};
static const char *tg[]=			{"telegram-desktop",NULL};
static const char *flameshot[] = 		{"flameshot","gui",NULL};
static const char *jupyter[] = {"jupyter","notebook",NULL};
static const char *slock[] = {"slock",NULL};
static Key keys[] = {
	/* modifier                        key                function        	argument */
	{ MODKEY,                       XK_grave,  	togglescratch,  	{.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,       	togglebar,      	{0} },
	{ MODKEY|ShiftMask,             XK_j,      	rotatestack,    	{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      	rotatestack,    	{.i = -1 } },
	{ MODKEY,                       XK_j,      	focusstack,     	{.i = +1 } },
	{ MODKEY,                       XK_k,      	focusstack,      	{.i = -1 } },
	{ MODKEY,                       XK_i,     	incnmaster,     	{.i = +1 } },
	{ MODKEY,                       XK_d,      	incnmaster,     	{.i = -1 } },
	{ MODKEY,                       XK_h,      	setmfact,       	{.f = -0.05} },
	{ MODKEY,                       XK_l,      	setmfact,       	{.f = +0.05} },
	{ MODKEY|Mod4Mask,              XK_h,      	incrgaps,       	{.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_l,      	incrgaps,       	{.i = -1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_h,      	incrogaps,      	{.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_l,      	incrogaps,      	{.i = -1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_h,      	incrigaps,      	{.i = +1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_l,      	incrigaps,      	{.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,      	togglegaps,     	{0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      	defaultgaps,    	{0} },
	{ MODKEY,                       XK_y,      	incrihgaps,     	{.i = +1 } },
	{ MODKEY,                       XK_o,      	incrihgaps,     	{.i = -1 } },
	{ MODKEY|ControlMask,           XK_y,      	incrivgaps,     	{.i = +1 } },
	{ MODKEY|ControlMask,           XK_o,      	incrivgaps,     	{.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_y,      	incrohgaps,     	{.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_o,      	incrohgaps,     	{.i = -1 } },
	{ MODKEY|ShiftMask,             XK_y,      	incrovgaps,     	{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      	incrovgaps,     	{.i = -1 } },
	{ MODKEY,                       XK_Return, 	zoom,           	{0} },
	{ MODKEY,                       XK_Tab,    	view,           	{0} }, 
  { MODKEY,                       XK_t,      	setlayout,      	{.v = &layouts[0]} }, 
  { MODKEY,                       XK_f,      	setlayout,      	{.v = &layouts[1]} }, 
  { MODKEY|ShiftMask,             XK_f,       fullscreen,         {0} }, 
  { MODKEY,                       XK_m,      	setlayout,      	{.v = &layouts[2]} }, 
  { MODKEY,                       XK_space,  	setlayout,      	{0} }, 
  { MODKEY|ShiftMask,             XK_space,  	togglefloating, 	{0} },
	{ MODKEY,                       XK_0,      	view,           	{.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      	tag,           		{.ui = ~0 } },
	{ MODKEY,                       XK_comma,  	focusmon,       	{.i = -1 } },
	{ MODKEY,                       XK_period, 	focusmon,       	{.i = +1 } },
	{ MODKEY|ShiftMask,           	XK_comma, 	tagmon,         	{.i = -1 } },
	{ MODKEY|ShiftMask,           	XK_period, 	tagmon,         	{.i = +1 } },
	{ MODKEY,                       XK_Left,   	viewtoleft,     	{0} },
	{ MODKEY,                       XK_Right,  	viewtoright,    	{0} },
	{ MODKEY|ShiftMask,             XK_Left,   	tagtoleft,      	{0} },
	{ MODKEY|ShiftMask,             XK_Right,  	tagtoright,     	{0} },
  { MODKEY,                       XK_F12,     spawn,            {.v = jupyter } },
  { MODKEY|Mod4Mask,    		      XK_w,      	spawn,          	{.v = web_browser_cmd } },
	{ MODKEY|Mod4Mask,    		XK_s,      	spawn,          	{.v = stardict_cmd } },
	{ MODKEY|Mod4Mask,    		XK_q,      	spawn,          	{.v = qq_cmd } },
	{ MODKEY|ControlMask,		XK_q,		spawn,			{.v = tg} },
	{ MODKEY|Mod4Mask,    		XK_Return,   	spawn,          	{.v = termcmd } },
	
  // 隐藏窗口 rofi 截图 退出dwm 关闭窗口 typora 声音 亮度
	{ MODKEY,			XK_F1,		hidewin,		{0} },
        { MODKEY|ShiftMask,		XK_F1,		restorewin,		{0} },	
	{ MODKEY,                       XK_F2,    	spawn,          	{.v = roficmd } },
	{ MODKEY,                       XK_F3,     	quit,           	{0} },
	{ MODKEY,                       XK_F4,     	killclient,     	{0} },
	{ MODKEY,			XK_F5,		spawn,			{.v = typora} },
	{ MODKEY,			XK_F6,		spawn,			{.v = flameshot} },
	{ MODKEY,                       XK_F7,     	spawn,         		{.v = volumemax } },
	{ MODKEY,                       XK_F8,    	spawn,          	{.v = volumetoggle } },
	{ MODKEY,                       XK_F9,    	spawn,          	{.v = volumedown } },
	{ MODKEY,                       XK_F10,    	spawn,          	{.v = volumeup } },
	// 休眠重启关机
	{ MODKEY|ControlMask,  		XK_l,      	spawn,          	{.v = slock } },
	{ MODKEY|ControlMask,  		XK_r,      	spawn,         		{.v = reboot_cmd } },
	{ MODKEY|ControlMask,  		XK_p,      	spawn,          	{.v = poweroff_cmd } },
	TAGKEYS(                        XK_1,                      		0)
	TAGKEYS(                        XK_2,                      		1)
	TAGKEYS(                        XK_3,                      		2)
	TAGKEYS(                        XK_4,                      		3)
	TAGKEYS(                        XK_5,                      		4)
	TAGKEYS(                        XK_6,                      		5)
	TAGKEYS(			XK_7,					6)
	TAGKEYS(			XK_8,					7)
	TAGKEYS(			XK_9,					8)

};

static Button buttons[] = {
	/* click                      event mask          button             function           	argument */
	{ ClkLtSymbol,      	      0,                  Button1,          setlayout,         	{0} },
	{ ClkLtSymbol,                0,                  Button3,          setlayout,      	{.v = &layouts[2]} },
	{ ClkWinTitle,		      0,		  Button1,	    togglewin,		{0} },
	{ ClkWinTitle,                0,                  Button2,          zoom,           	{0} },
	{ ClkStatusText,              0,                  Button2,          spawn,          	{.v = termcmd } },
	{ ClkClientWin,               MODKEY,             Button1,          movemouse,      	{0} },
	{ ClkClientWin,               MODKEY,             Button2,          togglefloating, 	{0} },
	{ ClkClientWin,               MODKEY,             Button3,          resizemouse,    	{0} },
	{ ClkTagBar,                  0,                  Button1,          view,           	{0} },
	{ ClkTagBar,                  0,                  Button3,          toggleview,     	{0} },
	{ ClkTagBar,                  MODKEY,             Button1,          tag,           	{0} },
	{ ClkTagBar,                  MODKEY,             Button3,          toggletag,      	{0} },
};

