#pragma once

#include "SpaceModule\core\SpaceModuleHeader.h"

#include "SpaceModule\s_ui_system\UIElementRect.h"
#include "SpaceModule\s_graphic_system\GraphicSystem.h"

namespace SpaceModule
{

	struct SignalInput {
	
	};

	struct SignalOutput {
	
	};

	enum class NodeType {
		None, AudioIn, AudioOut, MIDIIn, MIDIOut, Pattern, ASDR, LFO, Oscillator, Synth, Math
	};

	class Node : public UIElementRect
	{
	public:
		Node(NodeType nodetype_in);
		virtual ~Node() = default;

		virtual void OnRender(GraphicSystem& const gs) = 0;

		const std::string& GetName() const { return m_CustomName; }
		const NodeType& GetNodeType() const { return m_Type; }
	protected: // node core
		NodeType m_Type;
		std::vector<SignalInput> signals_inputs;
		std::vector<SignalOutput> signals_output;
		
		
	};
	
}