#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#ifdef USING_JUCE_API

namespace SpaceModule {
	namespace Input {

		class InputModifiers {
		 public:
			enum : uint8_t
			{
				noModifiers = 0,
				shiftModifier = BIT(0),
				ctrlModifier = BIT(1),
				altModifier = BIT(2),
			};
		 public:
			InputModifiers(uint8_t modifier_in)
				: value(modifier_in & 7)
			{}
			InputModifiers(int modifier_in)
				: value(modifier_in & 7)
			{}
			InputModifiers operator|(InputModifiers a) {
				return InputModifiers(a.value | value);
			}
			bool operator==(InputModifiers a) {
				return a.value == value;
			}
			uint8_t GetRaw() {
				return value;
			}
		 private:
			uint8_t value;
		};


		enum class InputType : uint8_t {
			None = 0,
			Press = 1,
			Release = 2,
		};


		enum class InputCode : uint32_t
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
			KB_Escape = 27,
			KB_Enter = 13,
			KB_Tab = 9,
			KB_Backspace = 8,
			KB_Insert = 65581,
			KB_Delete = 65582,
			KB_Right = 65575,
			KB_Left = 65573,
			KB_Down = 65576,
			KB_Up = 65574,
			KB_PageUp = 65569,
			KB_PageDown = 65570,
			KB_End = 65571,
			KB_Home = 65572,
			KB_F1 = 65648,
			KB_F2 = 65649,
			KB_F3 = 65650,
			KB_F4 = 65651,
			KB_F5 = 65652,
			KB_F6 = 65653,
			KB_F7 = 65654,
			KB_F8 = 65655,
			KB_F9 = 65656,
			KB_F10 = 65657,
			KB_F11 = 65658,
			KB_F12 = 65659,

			/* Keypad */
			KP_0 = 65632,
			KP_1 = 65633,
			KP_2 = 65634,
			KP_3 = 65635,
			KP_4 = 65636,
			KP_5 = 65637,
			KP_6 = 65638,
			KP_7 = 65639,
			KP_8 = 65640,
			KP_9 = 65641,
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

			MS_Button0       = 1048576,
			MS_Button1       = 1048577,
			MS_LeftButton    = 1048577,
			MS_Button2       = 1048578,
			MS_RightButton   = 1048578,

			MS_Button3       = 1048579,
			MS_MiddleButton  = 1048579,
			MS_ScrollUp      = 1048580,
			MS_ScrollDown    = 1048581
		};
		inline bool isMouseEvent(InputCode rhs) {
			return (1048576 <= (uint16_t)rhs) && ((uint16_t)rhs < 1048581);
		}

	}
}

#endif