#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "CommandList.h"
#include "InputSignal.h"

namespace SpaceModule
{

	enum class cmd_flags : uint32_t {
		getReleaseInfo = BIT(0),
		getDragInfo = BIT(1),
		showInHelpBar = BIT(2),
		showInKeyBindingList = BIT(3)
	};
	inline cmd_flags operator|(cmd_flags a, cmd_flags b)
	{
		return static_cast<cmd_flags>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
	}

	class Command
	{
	public:
		Command();
		Command(Input::InputCode, const std::string&);
		Command(Input::CommandTemplate);
		~Command() = default;

		Input::InputCode GetCode() const;

		void SetUpTemplate(Input::CommandTemplate);
	
	protected:
		Input::InputCode m_bind;
		string m_name;
		cmd_flags m_flags;

	public:
		float x_preDrag;
		float y_preDrag;

	};


	////////////
	struct InputInfo {
		InputInfo() : code(Input::InputCode::None), type(Input::InputType::Release), ms_x(), ms_y() {}
		InputInfo(Input::InputCode code_in, Input::InputType type_in, float x_in, float y_in) : code(code_in), type(type_in), ms_x(x_in), ms_y(y_in) {}

		Input::InputCode code;
		Input::InputType type;
		float ms_x;
		float ms_y;

	};
	////////////
	template <typename T>
	struct InputInfoFinal{
		InputInfoFinal() : code(Input::InputCode::None), type(Input::InputType::Release), ms_x(), ms_y() {}
		InputInfoFinal(Input::InputCode code_in, Input::InputType type_in, float x_in, float y_in) : code(code_in), type(type_in), ms_x(x_in), ms_y(y_in) {}
		InputInfoFinal& operator =(const InputInfo& info_in) { code = info_in.code; type = info_in.type; ms_x = info_in.ms_x; ms_y = info_in.ms_y; return *this; }

		Input::InputCode code;
		Input::InputType type;
		float ms_x;
		float ms_y;

		bool wait_for_release = false;
		bool get_drag_info = false;
		T* object = nullptr;

	};
}