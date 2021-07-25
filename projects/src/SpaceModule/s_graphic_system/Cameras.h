#pragma once
#include "SpaceModule/core/SpaceModuleHeader.h"

namespace SpaceModule {

	class OrthographicCamera {
	public:
		OrthographicCamera();
		OrthographicCamera(float left_in, float right_in, float top_in, float botton_in);

		float GetSize() const { return size; }
		const vec3& GetPosition() const { return m_position; }
		const angle& GetRotation() const { return m_rotation; }
		const mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
		const mat4& GetInverseMatrix() const { return m_InverseViewProjectionMatrix; }
		const vec2& GetScreenCenter() const { return m_screenCenter; }

		void SetSize(float size_in) {
			size = size_in;
			RecaculateViewMatrix();
		}
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
			RecaculateViewMatrix();
		}
		void RotateBy(const angle& angle_in) {
			m_rotation += angle_in;
			RecaculateViewMatrix();
		}
		void ScaleBy(float scale_in) {
			size *= scale_in; 
			RecaculateViewMatrix();
		}

		void DragBegin(const vec2& msPos_initial);
		void DragUpdate(const vec2& msPos_initial);

	private:
		void RecaculateViewMatrix();

	private:
		float size = 1.f;
		float left, right, top, botton;

		vec2 m_screenCenter = { 0.0f, 0.0f };
		vec3 m_position = { 0.0f , 0.0f , 0.0f };
		angle m_rotation = angle(degrees(0.f));

		mat4 m_ProjectionMatrix;
		mat4 m_ViewMatrix;
		mat4 m_ViewProjectionMatrix;
		mat4 m_InverseViewProjectionMatrix;

		vec3 m_position_preDrag = { 0.0f, 0.0f, 0.0f };
		vec2 m_msPos_preDrag = { 0.0f, 0.0f };
	};

}