#pragma once
#include "Math.h"

namespace SpaceModule {
	struct radians { 
		radians(float in)
			: value(in)
		{}
		operator float() {
			return value;
		}
		float value; 
	};
	struct degrees {
		degrees(float in)
			: value(in)
		{}
		operator float() {
			return value;
		}
		float value;
	};

	struct angle {
	 public:
	 	angle()
	 		: x(0.0f), y(1.0f)
	 	{}
	 	angle(float x_in, float y_in)
	 		: x(x_in), y(y_in) 
	 	{}
	 	angle(radians rad_in)
	 		: x(std::cos(rad_in)), y(std::sin(rad_in))
	 	{}
	 	angle(degrees deg_in)
	 		: x(std::cos(deg_in * glm::pi<float>() / 180.f)), y(std::sin(deg_in* glm::pi<float>() / 180.f))
	 	{}

	 public:
	 	float radians() const {
	 		return std::atan2(y, x);
	 	}
	 	float degrees() const {
	 		return std::atan2(y, x) * 180.f / glm::pi<float>();
	 	}

		angle& normalize() {
			float len(std::sqrt(x * x + y * y));
			if (len != 0.0f)
			{
				x *= (1.0f / len);
				y *= (1.0f / len);
			}
			return *this;
		}

	 public:
	 	angle& operator+=(angle& in) {
	 		x = x * in.x - y * in.y;
	 		y = x * in.y + y * in.x;
	 		return *this;
	 	}
		operator vec2() {
			return vec2(x,y);
		}
	 public:
	 	float x;
	 	float y;
	};
	inline angle invert(const angle& angle_in) {
		return angle(angle_in.x, -angle_in.y);
	}
	inline vec2 rotate(const vec2& vec_in, const angle& angle_in) {
		return vec2(vec_in.x * angle_in.x - vec_in.y * angle_in.y,
			        vec_in.x * angle_in.y + vec_in.y * angle_in.x);
	}
	inline angle rotate(const angle& angleA_in, const angle& angleB_in) {
		return angle(angleA_in.x * angleB_in.x - angleA_in.y * angleB_in.y,
			         angleA_in.x * angleB_in.y + angleA_in.y * angleB_in.x);
	}
	inline angle operator+(const angle& angleA_in, const angle& angleB_in) {
		return rotate(angleA_in, angleB_in);
	}
	inline angle operator-(const angle& angle_in) {
		return invert(angle_in);
	}
	inline void boba() {
		angle() + angle();
	}

}