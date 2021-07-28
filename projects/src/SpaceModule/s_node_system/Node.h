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

		const NodeType& GetNodeType() const { return m_type; }

	protected: // Drag Node Command
		bool DragNode_Press(InputCall& info_in);
		void DragNode_Release(InputCall& info_in);
		void DragNode_Drag(const vec2&);
		vec2 DragNode_ConstrainSlope(const vec2&) const;

	private:
		void UpdateSlopeBounds();

	private:
		SlopeBounds slope_limit;
		Command cmd_dragNode;
		vec2 dist_preDrag = { 0.f, 0.f };
		vec2 msPos_preDrag = { 0.f, 0.f };

	 protected: // node core
		NodeType m_type;
		float width;
		float height;

	};
	
}