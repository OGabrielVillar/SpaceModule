#pragma once

#include "SpaceModule\core\SpaceModuleHeader.h"

namespace SpaceModule
{

	struct SignalInput {
	
	};

	struct SignalOutput {
	
	};

	enum class NodeType {
		None, AudioIn, AudioOut, MIDIIn, MIDIOut, Pattern, ASDR, LFO, Oscillator, Synth, Math
	};

	class Node
	{
	public:
		Node(NodeType nodetype_in);
		virtual ~Node() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		//virtual void OnUpdate(Timestep ts) {}
		virtual void OnRender() {}
		//virtual void OnEvent(Event & event) {}

		const std::string& GetName() const { return m_CustomName; }
		const NodeType& GetNodeType() const { return m_Type; }
	private: // node core
		NodeType m_Type;
		std::vector<SignalInput> signals_inputs;
		std::vector<SignalOutput> signals_output;
	
	private: // node user interface
		std::string m_CustomName;
		
		
	};
	
}