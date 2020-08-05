#include "_pch.h"
#include "KeyCode.h"

#define VTR_STRING_CONVERSION_CASE(X) case KeyCode::X: return #X

namespace Vitro
{
	std::string ToString(KeyCode key)
	{
		switch(key)
		{
			VTR_STRING_CONVERSION_CASE(None);
			VTR_STRING_CONVERSION_CASE(Backspace);
			VTR_STRING_CONVERSION_CASE(Tab);
			VTR_STRING_CONVERSION_CASE(Clear);
			VTR_STRING_CONVERSION_CASE(Enter);
			VTR_STRING_CONVERSION_CASE(Shift);
			VTR_STRING_CONVERSION_CASE(Control);
			VTR_STRING_CONVERSION_CASE(Alt);
			VTR_STRING_CONVERSION_CASE(Pause);
			VTR_STRING_CONVERSION_CASE(CapsLock);
			VTR_STRING_CONVERSION_CASE(Escape);
			VTR_STRING_CONVERSION_CASE(Space);
			VTR_STRING_CONVERSION_CASE(PageUp);
			VTR_STRING_CONVERSION_CASE(PageDown);
			VTR_STRING_CONVERSION_CASE(End);
			VTR_STRING_CONVERSION_CASE(Home);
			VTR_STRING_CONVERSION_CASE(ArrowLeft);
			VTR_STRING_CONVERSION_CASE(ArrowUp);
			VTR_STRING_CONVERSION_CASE(ArrowRight);
			VTR_STRING_CONVERSION_CASE(ArrowDown);
			VTR_STRING_CONVERSION_CASE(Select);
			VTR_STRING_CONVERSION_CASE(Print);
			VTR_STRING_CONVERSION_CASE(Execute);
			VTR_STRING_CONVERSION_CASE(PrintScreen);
			VTR_STRING_CONVERSION_CASE(Insert);
			VTR_STRING_CONVERSION_CASE(Delete);
			VTR_STRING_CONVERSION_CASE(Help);
			VTR_STRING_CONVERSION_CASE(A);
			VTR_STRING_CONVERSION_CASE(B);
			VTR_STRING_CONVERSION_CASE(C);
			VTR_STRING_CONVERSION_CASE(D);
			VTR_STRING_CONVERSION_CASE(E);
			VTR_STRING_CONVERSION_CASE(F);
			VTR_STRING_CONVERSION_CASE(G);
			VTR_STRING_CONVERSION_CASE(H);
			VTR_STRING_CONVERSION_CASE(I);
			VTR_STRING_CONVERSION_CASE(J);
			VTR_STRING_CONVERSION_CASE(K);
			VTR_STRING_CONVERSION_CASE(L);
			VTR_STRING_CONVERSION_CASE(M);
			VTR_STRING_CONVERSION_CASE(N);
			VTR_STRING_CONVERSION_CASE(O);
			VTR_STRING_CONVERSION_CASE(P);
			VTR_STRING_CONVERSION_CASE(Q);
			VTR_STRING_CONVERSION_CASE(R);
			VTR_STRING_CONVERSION_CASE(S);
			VTR_STRING_CONVERSION_CASE(T);
			VTR_STRING_CONVERSION_CASE(U);
			VTR_STRING_CONVERSION_CASE(V);
			VTR_STRING_CONVERSION_CASE(W);
			VTR_STRING_CONVERSION_CASE(X);
			VTR_STRING_CONVERSION_CASE(Y);
			VTR_STRING_CONVERSION_CASE(Z);
			VTR_STRING_CONVERSION_CASE(SuperLeft);
			VTR_STRING_CONVERSION_CASE(SuperRight);
			VTR_STRING_CONVERSION_CASE(Menu);
			VTR_STRING_CONVERSION_CASE(Sleep);
			VTR_STRING_CONVERSION_CASE(Pad0);
			VTR_STRING_CONVERSION_CASE(Pad1);
			VTR_STRING_CONVERSION_CASE(Pad2);
			VTR_STRING_CONVERSION_CASE(Pad3);
			VTR_STRING_CONVERSION_CASE(Pad4);
			VTR_STRING_CONVERSION_CASE(Pad5);
			VTR_STRING_CONVERSION_CASE(Pad6);
			VTR_STRING_CONVERSION_CASE(Pad7);
			VTR_STRING_CONVERSION_CASE(Pad8);
			VTR_STRING_CONVERSION_CASE(Pad9);
			VTR_STRING_CONVERSION_CASE(Multiply);
			VTR_STRING_CONVERSION_CASE(Add);
			VTR_STRING_CONVERSION_CASE(Separator);
			VTR_STRING_CONVERSION_CASE(Subtract);
			VTR_STRING_CONVERSION_CASE(Decimal);
			VTR_STRING_CONVERSION_CASE(Divide);
			VTR_STRING_CONVERSION_CASE(F1);
			VTR_STRING_CONVERSION_CASE(F2);
			VTR_STRING_CONVERSION_CASE(F3);
			VTR_STRING_CONVERSION_CASE(F4);
			VTR_STRING_CONVERSION_CASE(F5);
			VTR_STRING_CONVERSION_CASE(F6);
			VTR_STRING_CONVERSION_CASE(F7);
			VTR_STRING_CONVERSION_CASE(F8);
			VTR_STRING_CONVERSION_CASE(F9);
			VTR_STRING_CONVERSION_CASE(F10);
			VTR_STRING_CONVERSION_CASE(F11);
			VTR_STRING_CONVERSION_CASE(F12);
			VTR_STRING_CONVERSION_CASE(F13);
			VTR_STRING_CONVERSION_CASE(F14);
			VTR_STRING_CONVERSION_CASE(F15);
			VTR_STRING_CONVERSION_CASE(F16);
			VTR_STRING_CONVERSION_CASE(F17);
			VTR_STRING_CONVERSION_CASE(F18);
			VTR_STRING_CONVERSION_CASE(F19);
			VTR_STRING_CONVERSION_CASE(F20);
			VTR_STRING_CONVERSION_CASE(F21);
			VTR_STRING_CONVERSION_CASE(F22);
			VTR_STRING_CONVERSION_CASE(F23);
			VTR_STRING_CONVERSION_CASE(F24);
			VTR_STRING_CONVERSION_CASE(NumLock);
			VTR_STRING_CONVERSION_CASE(ScrollLock);
			VTR_STRING_CONVERSION_CASE(OEM26);
			VTR_STRING_CONVERSION_CASE(OEM27);
			VTR_STRING_CONVERSION_CASE(OEM28);
			VTR_STRING_CONVERSION_CASE(OEM29);
			VTR_STRING_CONVERSION_CASE(OEM30);
			VTR_STRING_CONVERSION_CASE(ShiftLeft);
			VTR_STRING_CONVERSION_CASE(ShiftRight);
			VTR_STRING_CONVERSION_CASE(ControlLeft);
			VTR_STRING_CONVERSION_CASE(ControlRight);
			VTR_STRING_CONVERSION_CASE(MenuLeft);
			VTR_STRING_CONVERSION_CASE(MenuRight);
			VTR_STRING_CONVERSION_CASE(WebBack);
			VTR_STRING_CONVERSION_CASE(WebForward);
			VTR_STRING_CONVERSION_CASE(WebRefresh);
			VTR_STRING_CONVERSION_CASE(WebStop);
			VTR_STRING_CONVERSION_CASE(WebSearch);
			VTR_STRING_CONVERSION_CASE(WebFavorites);
			VTR_STRING_CONVERSION_CASE(WebHome);
			VTR_STRING_CONVERSION_CASE(VolumeMute);
			VTR_STRING_CONVERSION_CASE(VolumeDown);
			VTR_STRING_CONVERSION_CASE(VolumeUp);
			VTR_STRING_CONVERSION_CASE(MediaNext);
			VTR_STRING_CONVERSION_CASE(MediaPrevious);
			VTR_STRING_CONVERSION_CASE(MediaStop);
			VTR_STRING_CONVERSION_CASE(MediaPlayPause);
			VTR_STRING_CONVERSION_CASE(Mail);
			VTR_STRING_CONVERSION_CASE(MediaSelect);
			VTR_STRING_CONVERSION_CASE(LaunchApp1);
			VTR_STRING_CONVERSION_CASE(LaunchApp2);
			VTR_STRING_CONVERSION_CASE(OEM1);
			VTR_STRING_CONVERSION_CASE(OEM2);
			VTR_STRING_CONVERSION_CASE(OEM3);
			VTR_STRING_CONVERSION_CASE(OEM4);
			VTR_STRING_CONVERSION_CASE(OEM5);
			VTR_STRING_CONVERSION_CASE(OEM6);
			VTR_STRING_CONVERSION_CASE(OEM7);
			VTR_STRING_CONVERSION_CASE(OEM8);
			VTR_STRING_CONVERSION_CASE(OEM9);
			VTR_STRING_CONVERSION_CASE(OEM10);
			VTR_STRING_CONVERSION_CASE(OEM11);
			VTR_STRING_CONVERSION_CASE(Process);
			VTR_STRING_CONVERSION_CASE(OEM12);
			VTR_STRING_CONVERSION_CASE(Unicode);
			VTR_STRING_CONVERSION_CASE(OEM13);
			VTR_STRING_CONVERSION_CASE(OEM14);
			VTR_STRING_CONVERSION_CASE(OEM15);
			VTR_STRING_CONVERSION_CASE(OEM16);
			VTR_STRING_CONVERSION_CASE(OEM17);
			VTR_STRING_CONVERSION_CASE(OEM18);
			VTR_STRING_CONVERSION_CASE(OEM19);
			VTR_STRING_CONVERSION_CASE(OEM20);
			VTR_STRING_CONVERSION_CASE(OEM21);
			VTR_STRING_CONVERSION_CASE(OEM22);
			VTR_STRING_CONVERSION_CASE(OEM23);
			VTR_STRING_CONVERSION_CASE(OEM24);
			VTR_STRING_CONVERSION_CASE(OEM25);
			case KeyCode::Number0:		return "0";
			case KeyCode::Number1:		return "1";
			case KeyCode::Number2:		return "2";
			case KeyCode::Number3:		return "3";
			case KeyCode::Number4:		return "4";
			case KeyCode::Number5:		return "5";
			case KeyCode::Number6:		return "6";
			case KeyCode::Number7:		return "7";
			case KeyCode::Number8:		return "8";
			case KeyCode::Number9:		return "9";
			case KeyCode::Plus:			return "+";
			case KeyCode::Comma:		return ",";
			case KeyCode::Minus:		return "-";
			case KeyCode::Period:		return ".";
			case KeyCode::AngleBracket:	return "<";
		}
		return "Unknown key code: " + std::to_string(static_cast<int>(key));
	}
}
