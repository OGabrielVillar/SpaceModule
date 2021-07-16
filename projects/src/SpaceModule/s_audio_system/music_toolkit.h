#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

namespace SpaceModule {
	namespace PreDefNotes {

		struct predef_notes {
			const float predef_note_A  = 440.f             * 0.0625f;
			const float predef_note_Bb = 440.f * 1.059463f * 0.0625f;
			const float predef_note_B  = 440.f * 1.122462f * 0.0625f;
			const float predef_note_C  = 440.f * 1.189207f * 0.0625f;
			const float predef_note_Db = 440.f * 1.259921f * 0.0625f;
			const float predef_note_D  = 440.f * 1.334840f * 0.0625f;
			const float predef_note_Eb = 440.f * 1.414214f * 0.0625f;
			const float predef_note_E  = 440.f * 1.498307f * 0.0625f;
			const float predef_note_F  = 440.f * 1.587401f * 0.0625f;
			const float predef_note_Gb = 440.f * 1.681793f * 0.0625f;
			const float predef_note_G  = 440.f * 1.781797f * 0.0625f;
			const float predef_note_Ab = 440.f * 1.887749f * 0.0625f;
		};
		struct predef_octaves {
			const float predef_note_0  =    1.f;
			const float predef_note_1  =    2.f;
			const float predef_note_2  =    4.f;
			const float predef_note_3  =    8.f;
			const float predef_note_4  =   16.f;
			const float predef_note_5  =   32.f;
			const float predef_note_6  =   64.f;
			const float predef_note_7  =  128.f;
			const float predef_note_8  =  256.f;
			const float predef_note_9  =  512.f;
			const float predef_note_10 = 1024.f;
		};

		static const predef_notes   notes_reference;
		static const predef_octaves octaves_reference;
	}

	enum class Notes : int {
		A  = 0,
		Bb = 1,
		B  = 2,
		C  = 3,
		Db = 4,
		D  = 5,
		Eb = 6,
		E  = 7,
		F  = 8,
		Gb = 9,
		G  = 10,
		Ab = 11
	};

	inline float get_note_frequency(Notes note_in,int octave_in) {
		return *((float*)&PreDefNotes::notes_reference + (int)note_in) * *((float*)&PreDefNotes::octaves_reference + octave_in);
	}
	//struct note {
	//	note() {}
	//	float frequency = 440.f;
	//};
}