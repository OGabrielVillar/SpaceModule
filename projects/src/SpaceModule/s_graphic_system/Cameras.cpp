#include "Cameras.h"

namespace SpaceModule {

	OrthographicCamera::OrthographicCamera( float left_in, float right_in, float top_in, float botton_in )
		: left(left_in), right(right_in), top(top_in), botton(botton_in),
		m_ProjectionMatrix( glm::ortho( left, right, top, botton, -1.f, 1.f ) ),
		m_ViewMatrix(glm::inverse(mat4(1.f))),
		m_ViewProjectionMatrix(m_ProjectionMatrix * m_ViewMatrix),
		m_InverseViewProjectionMatrix(glm::inverse(m_ViewProjectionMatrix))
	{}

	void OrthographicCamera::RecaculateViewMatrix()
	{
		mat4 transform = glm::translate(mat4(1.f), m_position);
		rotate(transform, m_rotation);

		m_ViewMatrix = glm::inverse(transform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
		m_InverseViewProjectionMatrix = glm::inverse(m_ViewProjectionMatrix);
	}

}