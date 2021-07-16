#pragma once

#include "SpaceModule\core\SpaceModuleHeader.h"

#include "SpaceModule\s_ui_system\UIElement.h"
#include "SpaceModule\s_graphic_system\GraphicSystem.h"


namespace SpaceModule
{

	enum class SignalType 
	{ None, Float, Vec2, Vec3, Vec4, Mat4, Audio, Texture };

	enum class NodeType 
	{ None, AudioIn, AudioOut, MIDIIn, MIDIOut, Pattern, ASDR, LFO, Oscillator, Synth, Math, Gain };

}

namespace SpaceModule
{

	class Node : public UIElement
	{
		struct SignalSlot {
			SignalType type = SignalType::None;
			NodeType NodeLinkRestriction = NodeType::None;
			uint8_t slot;
			Node* node;
			SignalSlot* connectedTo;
		};

	public:
		Node(NodeType nodetype_in);
		virtual ~Node() = default;

		//virtual void OnRender(GraphicSystem& const gs) = 0;

		const NodeType& GetNodeType() const { return m_type; }
		bool operator==(NodeType type_in) const { return m_type == type_in; }

	protected: // node core
		NodeType m_type;
		float width;
		float height;

	};
	
}