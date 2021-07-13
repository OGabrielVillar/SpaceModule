#pragma once

#include "nodes/include.h"


namespace SpaceModule
{
	struct Camera {
		vec2 position = vec2(0.0f);
		float zoom = 1.0f;
	};

	class NodeSpace : public UIElement
	{
	public:
		NodeSpace();
		~NodeSpace() = default;

		void ProcessAudioSignal(float& in);

	private:
		Camera camera;

	};
}