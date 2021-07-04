#include "Command.h"

namespace SpaceModule
{
    Command::Command() :
        m_inputBind(Input::InputCode::None),
        m_name(),
        getReleaseInfo(0),
        getDragInfo(0),
        showInHelpBar(0),
        showInKeyBindingList(0),
        x_preDrag(0.0f),
        y_preDrag(0.0f)
    {
    }
    Command::Command(Input::InputCode inputBind_in, const std::string& name_in) :
        m_inputBind(inputBind_in),
        m_name(name_in),
        getReleaseInfo(0),
        getDragInfo(0),
        showInHelpBar(0),
        showInKeyBindingList(0),
        x_preDrag(0.0f),
        y_preDrag(0.0f)
    {
    }
    Command::Command(Input::CommandTemplate template_in) :
        m_inputBind(Input::InputCode::None),
        m_name(),
        getReleaseInfo(0),
        getDragInfo(0),
        showInHelpBar(0),
        showInKeyBindingList(0),
        x_preDrag(0.0f),
        y_preDrag(0.0f)
    {
        SetUpTemplate(template_in);
    }
    Input::InputCode Command::GetCode() const
    {
        return m_inputBind;
    }
    void Command::SetUpTemplate(Input::CommandTemplate template_in)
    {
        switch (template_in)
        {
        case(Input::CommandTemplate::ui_ButtonPress):
            m_inputBind = Input::InputCode::MS_LeftButton;
            m_name = "Press";
            getReleaseInfo = 1;
            getDragInfo = 0;
            showInHelpBar = 0;
            showInKeyBindingList = 0;
            break;
        case(Input::CommandTemplate::ui_KnobModifyValue):
            m_inputBind = Input::InputCode::MS_LeftButton;
            m_name = "Modify Value";
            getReleaseInfo = 1;
            getDragInfo = 1;
            showInHelpBar = 0;
            showInKeyBindingList = 0;
            break;
        default:
            break;
        }
    }
}
