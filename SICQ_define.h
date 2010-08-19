//! \file SICQ_define.h definitions
#pragma once

#define SICQ_ERROR_SUCCESS					0
#define SICQ_ERROR_EVENTWINDOWISEXIST		1
#define SICQ_ERROR_EVENTWINDOWISNOTEXIST	2
#define SICQ_ERROR_CANNOTCONNECTTOSERVER	3


#define WM_SICQ_EVENTWND_LOGIN				WM_USER+100

//! Login
//! \param wParam true if success, false if fail
//! \param lParam a pointer to SICQ class
#define WM_SICQ_MAINWND_LOGIN				WM_USER+200

struct FOODGROUP
{
	bool Support;
	unsigned short Version;
};

struct FOODGROUPS
{
	FOODGROUP Oservice;
	FOODGROUP Locate;
	FOODGROUP Buddy;
	FOODGROUP ICBM;
	FOODGROUP Invite;
	FOODGROUP Popup;
	FOODGROUP PD;
	FOODGROUP Lookup;
	FOODGROUP Stats;
	FOODGROUP Trans;
	FOODGROUP SSI;
	FOODGROUP Spec;
	FOODGROUP Unk1;
	FOODGROUP Unk2;
	FOODGROUP Unk3;
};