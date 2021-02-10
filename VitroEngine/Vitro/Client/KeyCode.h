#pragma once

#include "_pch.h"

namespace Vitro
{
	// Identical to Windows virtual key codes.
	enum class KeyCode : unsigned char
	{
		None		   = 0, // Sent by some Unicode characters on the Windows virtual keyboard.
		Backspace	   = 8,
		Tab			   = 9,
		Clear		   = 12,
		Enter		   = 13,
		Shift		   = 16,
		Control		   = 17,
		Alt			   = 18,
		Pause		   = 19,
		CapsLock	   = 20,
		Escape		   = 27,
		Space		   = 32,
		PageUp		   = 33,
		PageDown	   = 34,
		End			   = 35,
		Home		   = 36,
		ArrowLeft	   = 37,
		ArrowUp		   = 38,
		ArrowRight	   = 39,
		ArrowDown	   = 40,
		Select		   = 41,
		Print		   = 42,
		Execute		   = 43,
		PrintScreen	   = 44,
		Insert		   = 45,
		Delete		   = 46,
		Help		   = 47,
		Number0		   = 48,
		Number1		   = 49,
		Number2		   = 50,
		Number3		   = 51,
		Number4		   = 52,
		Number5		   = 53,
		Number6		   = 54,
		Number7		   = 55,
		Number8		   = 56,
		Number9		   = 57,
		A			   = 65,
		B			   = 66,
		C			   = 67,
		D			   = 68,
		E			   = 69,
		F			   = 70,
		G			   = 71,
		H			   = 72,
		I			   = 73,
		J			   = 74,
		K			   = 75,
		L			   = 76,
		M			   = 77,
		N			   = 78,
		O			   = 79,
		P			   = 80,
		Q			   = 81,
		R			   = 82,
		S			   = 83,
		T			   = 84,
		U			   = 85,
		V			   = 86,
		W			   = 87,
		X			   = 88,
		Y			   = 89,
		Z			   = 90,
		SuperLeft	   = 91,
		SuperRight	   = 92,
		Menu		   = 93,
		Sleep		   = 95,
		Pad0		   = 96,
		Pad1		   = 97,
		Pad2		   = 98,
		Pad3		   = 99,
		Pad4		   = 100,
		Pad5		   = 101,
		Pad6		   = 102,
		Pad7		   = 103,
		Pad8		   = 104,
		Pad9		   = 105,
		Multiply	   = 106,
		Add			   = 107,
		Separator	   = 108,
		Subtract	   = 109,
		Decimal		   = 110,
		Divide		   = 111,
		F1			   = 112,
		F2			   = 113,
		F3			   = 114,
		F4			   = 115,
		F5			   = 116,
		F6			   = 117,
		F7			   = 118,
		F8			   = 119,
		F9			   = 120,
		F10			   = 121,
		F11			   = 122,
		F12			   = 123,
		F13			   = 124,
		F14			   = 125,
		F15			   = 126,
		F16			   = 127,
		F17			   = 128,
		F18			   = 129,
		F19			   = 130,
		F20			   = 131,
		F21			   = 132,
		F22			   = 133,
		F23			   = 134,
		F24			   = 135,
		NumLock		   = 144,
		ScrollLock	   = 145,
		OEM26		   = 146,
		OEM27		   = 147,
		OEM28		   = 148,
		OEM29		   = 149,
		OEM30		   = 150,
		ShiftLeft	   = 160,
		ShiftRight	   = 161,
		ControlLeft	   = 162,
		ControlRight   = 163,
		MenuLeft	   = 164,
		MenuRight	   = 165,
		WebBack		   = 166,
		WebForward	   = 167,
		WebRefresh	   = 168,
		WebStop		   = 169,
		WebSearch	   = 170,
		WebFavorites   = 171,
		WebHome		   = 172,
		VolumeMute	   = 173,
		VolumeDown	   = 174,
		VolumeUp	   = 175,
		MediaNext	   = 176,
		MediaPrevious  = 177,
		MediaStop	   = 178,
		MediaPlayPause = 179,
		Mail		   = 180,
		MediaSelect	   = 181,
		LaunchApp1	   = 182,
		LaunchApp2	   = 183,
		OEM1		   = 186,
		Plus		   = 187,
		Comma		   = 188,
		Minus		   = 189,
		Period		   = 190,
		OEM2		   = 191,
		OEM3		   = 192,
		OEM4		   = 219,
		OEM5		   = 220,
		OEM6		   = 221,
		OEM7		   = 222,
		OEM8		   = 223,
		OEM9		   = 225,
		AngleBracket   = 226,
		OEM10		   = 227,
		OEM11		   = 228,
		Process		   = 229,
		OEM12		   = 230,
		Unicode		   = 231,
		OEM13		   = 233,
		OEM14		   = 234,
		OEM15		   = 235,
		OEM16		   = 236,
		OEM17		   = 237,
		OEM18		   = 238,
		OEM19		   = 239,
		OEM20		   = 240,
		OEM21		   = 241,
		OEM22		   = 242,
		OEM23		   = 243,
		OEM24		   = 244,
		OEM25		   = 245,
	};

	std::string ToString(KeyCode key);
}
