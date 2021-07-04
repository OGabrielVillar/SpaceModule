#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "CommandList.h"
#include "InputSignal.h"

namespace SpaceModule
{
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
		Input::InputCode        m_inputBind;
		std::string      m_name;

		bool             getReleaseInfo = 0;
		bool             getDragInfo = 0;

		bool             showInHelpBar = 0;
		bool             showInKeyBindingList = 0;

	public:
		float            x_preDrag;
		float            y_preDrag;

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