#pragma once
#include "SpaceModule/core/SpaceModuleHeader.h"

namespace SpaceModule {

	class OrthographicCamera {
	public:
		OrthographicCamera(float left_in, float right_in, float top_in, float botton_in);

		const vec3& GetPosition() const { return m_position; }
		const angle& GetRotation() const { return m_rotation; }
		const mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
		const mat4& GetInverseMatrix() const { return m_InverseViewProjectionMatrix; }
		const vec2& GetScreenCenter() const { return m_screenCenter; }

		void SetPosition(const vec3& position_in) {
			m_position = position_in;
			RecaculateViewMatrix();
		}
		void SetPosition(const vec2& position_in) {
			m_position.x = position_in.x;
			m_position.y = position_in.y;
			RecaculateViewMatrix();
		}
		void SetRotation(const angle& angle_in) {
			m_rotation = angle_in;
			RecaculateViewMatrix();
		}
		void SetScreenCenter(const vec2& vec_in) {
			m_screenCenter = vec_in;
			m_ProjectionMatrix = translate( glm::ortho( left, right, top, botton ), vec3( vec_in.x, vec_in.y , 0.f ) );
			RecaculateViewMatrix();
		}
		void RotateBy(const angle& angle_in) {
			m_rotation += angle_in;
			RecaculateViewMatrix();
		}

	private:
		void RecaculateViewMatrix();

	private:
		float left, right, top, botton;

		vec2 m_screenCenter = { 0.0f, 0.0f };
		vec3 m_position = { 0.0f , 0.0f , 0.0f };
		angle m_rotation = angle(degrees(0.f));

		mat4 m_ProjectionMatrix;
		mat4 m_ViewMatrix;
		mat4 m_ViewProjectionMatrix;
		mat4 m_InverseViewProjectionMatrix;
	};

}