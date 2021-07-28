#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "CommandList.h"
#include "platforms/JuceInputCodes.h"

namespace SpaceModule
{
	using flagtype = uint32_t;


	////////////
	struct InputInfo {
		InputInfo()
			: code(Input::InputCode::None), type(Input::InputType::None), msPos(0.0f, 0.0f)
		{}
		InputInfo(Input::InputCode code_in, Input::InputType type_in, float x_in, float y_in, Input::InputModifiers modifiers_in = 0)
			: code(code_in), type(type_in), msPos(x_in, y_in), modifiers(modifiers_in)
		{}

		Input::InputCode code;
		Input::InputType type;
		vec2 msPos;
		Input::InputModifiers modifiers = 0;

	};
	////////////
	struct InputCall{
	 public:
		class Flag {
		public:
			enum : flagtype {
				WaitForRelease = BIT(0),
				GetDragCall = BIT(1)
			};
		public:
			Flag() = default;
			Flag(flagtype in)
				: value(in)
			{}
			operator const flagtype() {
				return value;
			}
			bool Have(Flag flag_in) const {
				flagtype mask = value & flag_in;
				return mask == flag_in;
			}
			Flag& operator|=(Flag flag_in) {
				value |= flag_in.value;
				return *this;
			}
		protected:
			flagtype value = 0;
		};


	 public:
		InputCall()
		 : m_info()
		{}
		InputCall(Input::InputCode code_in, Input::InputType type_in, float x_in, float y_in)
		 : m_info(code_in, type_in, x_in, y_in)
		{}
		InputCall(const InputInfo& info_in)
		 : m_info(info_in)
		{}
		InputCall& operator =(const InputInfo& info_in) {
			m_info = info_in;
			return *this; 
		}
		InputCall& withOffset(const vec2& offset_in) {
			usingMat4 = true;
			offset = offset_in;
			return *this;
		}
		void stopOffset(){ usingMat4 = false; }

		bool ModifiersEquals(Input::InputModifiers mods_in ) const {
			return mods_in == m_info.modifiers;
		}
		void SetFlag(Flag flag_in) {
			m_flags = flag_in;
		}
		void AddFlag(Flag flag_in) {
			m_flags |= flag_in;
		}
		void ClearFlags() {
			m_flags = 0;
		}

		bool Have(Flag flag_in) const {
			return m_flags.Have(flag_in);
		}
		bool operator==(Input::InputCode code_in) const {
			return code_in == m_info.code;
		}
		bool operator!=(Input::InputCode code_in) const {
			return code_in != m_info.code;
		}
		bool operator==(Input::InputType type_in) const {
			return type_in == m_info.type;
		}
		bool operator!=(Input::InputType type_in) const {
			return type_in != m_info.type;
		}

		const vec2& GetMousePosition() const {
			if (!usingMat4){
				return m_info.msPos;
			} else {
				return offset;
			}
		}
	 private: 
		InputInfo m_info;
		Flag m_flags = 0;
		bool usingMat4 = false;
		vec2 offset = { 0.0f , 0.0f };
	};

	////////////
	class Command
	{
	 public:
	 public:
		class Flag {
		 public:
			enum : uint32_t {
				WaitForRelease = BIT(0),
				GetDragCall = BIT(1),
				IgnoreKeyModifiers = BIT(3),
				ShowInHelpBar = BIT(3),
				ShowInKeyBindingList = BIT(4)
			};
		 public:
			Flag() = default;
			Flag(flagtype in)
				: value(in)
			{}
			operator const flagtype() {
				return value;
			}
			bool Have(Flag flag_in) const {
				flagtype mask = value & flag_in;
				return mask == flag_in;
			}
		 protected:
			flagtype value = 0;
		};

	 public:
		Command();
		Command(Input::InputCode, const std::string&);
		Command(Input::CommandTemplate);
		~Command() = default;

		void SetUpTemplate(Input::CommandTemplate);

		bool PressInput(InputCall&);
		bool ReleaseInput(InputCall&);
		bool IsDragging() const { return dragging; };
		Input::InputCode GetCode() const;

	 protected:
		Input::InputCode m_bind = (Input::InputCode)0;
		Input::InputModifiers m_modifiers = 0;
		string m_name = "";
		Flag m_flags = 0;
		bool dragging = false;

	 public:
		float x_preDrag = 0.0f;
		float y_preDrag = 0.0f;

	};
}