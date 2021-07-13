#include "Command.h"

namespace SpaceModule
{
    Command::Command() :
        m_bind(Input::InputCode::None),
        m_name(),
        m_flags((cmd_flags)0),
        x_preDrag(0.0f),
        y_preDrag(0.0f)
    {
    }
    Command::Command(Input::InputCode inputBind_in, const std::string& name_in) :
        m_bind(inputBind_in),
        m_name(name_in),
        m_flags((cmd_flags)0),
        x_preDrag(0.0f),
        y_preDrag(0.0f)
    {
    }
    Command::Command(Input::CommandTemplate template_in) :
        m_bind(Input::InputCode::None),
        m_name(),
        m_flags((cmd_flags)0),
        x_preDrag(0.0f),
        y_preDrag(0.0f)
    {
        SetUpTemplate(template_in);
    }
    Input::InputCode Command::GetCode() const
    {
        return m_bind;
    }
    void Command::SetUpTemplate(Input::CommandTemplate template_in)
    {
        switch (template_in)
        {
        case(Input::CommandTemplate::ui_ButtonPress):
            m_bind = Input::InputCode::MS_LeftButton;
            m_name = "Press";
            m_flags = cmd_flags::getReleaseInfo | cmd_flags::getDragInfo;
            break;
        case(Input::CommandTemplate::ui_KnobModifyValue):
            m_bind = Input::InputCode::MS_LeftButton;
            m_name = "Modify Value";
            m_flags = cmd_flags::getReleaseInfo | cmd_flags::getDragInfo;
            break;
        case(Input::CommandTemplate::ui_PrintTimer):
            m_bind = Input::InputCode::MS_RightButton;
            m_name = "Print Timer";
            break;
        default:
            break;
        }
    }
}
