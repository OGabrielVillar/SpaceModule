#include "Command.h"

namespace SpaceModule
{
    Command::Command()
    {
    }
    Command::Command(Input::InputCode inputBind_in, const std::string& name_in) :
        m_bind(inputBind_in),
        m_name(name_in)
    {
    }
    Command::Command(Input::CommandTemplate template_in)
    {
        SetUpTemplate(template_in);
    }
    bool Command::PressInput(InputCall& call_in)
    {
        if (call_in == m_bind)
        {
            if (m_flags.Have(Flag::GetDragCall))
                    call_in.AddFlag(InputCall::Flag::GetDragCall);
            if (m_flags.Have(Flag::WaitForRelease))
                    call_in.AddFlag(InputCall::Flag::WaitForRelease);
            return true;
        }
        return false;
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
            m_flags = Flag::WaitForRelease | Flag::GetDragCall;
            break;
        case(Input::CommandTemplate::ui_KnobModifyValue):
            m_bind = Input::InputCode::MS_LeftButton;
            m_name = "Modify Value";
            m_flags = Flag::WaitForRelease | Flag::GetDragCall;
            break;
        case(Input::CommandTemplate::ui_PrintTimer):
            m_bind = Input::InputCode::MS_RightButton;
            m_name = "Print Timer";
            break;
        case(Input::CommandTemplate::ui_DragWindow):
            m_bind = Input::InputCode::MS_LeftButton;
            m_name = "Drag Window";
            m_flags = Flag::WaitForRelease | Flag::GetDragCall;
            break;
        default:
            break;
        }
    }
}
