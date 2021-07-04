#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

namespace SpaceModule {
namespace Input {

	enum class InputType : bool {
		Release = 0 ,
		Press   = 1 
	};
	enum class InputCode : uint16_t
	{

		None = 0,


		//////////////////////
		//--KEYBOARD INPUT--//
		//////////////////////

		KB_Space = 32,
		KB_Apostrophe = 39, /* ' */
		KB_Comma = 44, /* , */
		KB_Minus = 45, /* - */
		KB_Period = 46, /* . */
		KB_Slash = 47, /* / */

		KB_0 = 48, /* 0 */
		KB_1 = 49, /* 1 */
		KB_2 = 50, /* 2 */
		KB_3 = 51, /* 3 */
		KB_4 = 52, /* 4 */
		KB_5 = 53, /* 5 */
		KB_6 = 54, /* 6 */
		KB_7 = 55, /* 7 */
		KB_8 = 56, /* 8 */
		KB_9 = 57, /* 9 */

		KB_Semicolon = 59, /* ; */
		KB_Equal = 61, /* = */

		KB_A = 65,
		KB_B = 66,
		KB_C = 67,
		KB_D = 68,
		KB_E = 69,
		KB_F = 70,
		KB_G = 71,
		KB_H = 72,
		KB_I = 73,
		KB_J = 74,
		KB_K = 75,
		KB_L = 76,
		KB_M = 77,
		KB_N = 78,
		KB_O = 79,
		KB_P = 80,
		KB_Q = 81,
		KB_R = 82,
		KB_S = 83,
		KB_T = 84,
		KB_U = 85,
		KB_V = 86,
		KB_W = 87,
		KB_X = 88,
		KB_Y = 89,
		KB_Z = 90,

		KB_LeftBracket = 91,  /* [ */
		KB_Backslash = 92,  /* \ */
		KB_RightBracket = 93,  /* ] */
		KB_GraveAccent = 96,  /* ` */

		KB_World1 = 161, /* non-US #1 */
		KB_World2 = 162, /* non-US #2 */

		/* Function keys */
		KB_Escape = 256,
		KB_Enter = 257,
		KB_Tab = 258,
		KB_Backspace = 259,
		KB_Insert = 260,
		KB_Delete = 261,
		KB_Right = 262,
		KB_Left = 263,
		KB_Down = 264,
		KB_Up = 265,
		KB_PageUp = 266,
		KB_PageDown = 267,
		KB_Home = 268,
		KB_End = 269,
		KB_CapsLock = 280,
		KB_ScrollLock = 281,
		KB_NumLock = 282,
		KB_PrintScreen = 283,
		KB_Pause = 284,
		KB_F1 = 290,
		KB_F2 = 291,
		KB_F3 = 292,
		KB_F4 = 293,
		KB_F5 = 294,
		KB_F6 = 295,
		KB_F7 = 296,
		KB_F8 = 297,
		KB_F9 = 298,
		KB_F10 = 299,
		KB_F11 = 300,
		KB_F12 = 301,
		KB_F13 = 302,
		KB_F14 = 303,
		KB_F15 = 304,
		KB_F16 = 305,
		KB_F17 = 306,
		KB_F18 = 307,
		KB_F19 = 308,
		KB_F20 = 309,
		KB_F21 = 310,
		KB_F22 = 311,
		KB_F23 = 312,
		KB_F24 = 313,
		KB_F25 = 314,

		/* Keypad */
		KP_0 = 320,
		KP_1 = 321,
		KP_2 = 322,
		KP_3 = 323,
		KP_4 = 324,
		KP_5 = 325,
		KP_6 = 326,
		KP_7 = 327,
		KP_8 = 328,
		KP_9 = 329,
		KP_Decimal = 330,
		KP_Divide = 331,
		KP_Multiply = 332,
		KP_Subtract = 333,
		KP_Add = 334,
		KP_Enter = 335,
		KP_Equal = 336,

		KB_LeftShift = 340,
		KB_LeftControl = 341,
		KB_LeftAlt = 342,
		KB_LeftSuper = 343,
		KB_RightShift = 344,
		KB_RightControl = 345,
		KB_RightAlt = 346,
		KB_RightSuper = 347,
		KB_Menu = 348,

		///////////////////
		//--MOUSE INPUT--//
		///////////////////

		MS_Button0 = 350,
		MS_Button1 = 351,
		MS_LeftButton = 351,
		MS_Button2 = 352,
		MS_RightButton = 352,

		MS_Button3 = 353,
		MS_MiddleButton = 353,
		MS_ScrollUp = 354,
		MS_ScrollDown = 355
	};
	inline bool isMouseEvent(InputCode rhs) {
		return ( 350 <= (uint16_t)rhs ) && ( (uint16_t)rhs < 355 );
	}

}
}