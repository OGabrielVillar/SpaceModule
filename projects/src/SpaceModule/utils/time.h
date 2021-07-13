#pragma once
#include <chrono>

namespace utl {

	class timer {
	 public:
		timer() : last(std::chrono::steady_clock::now()) {}

		operator float() const {
			return m_time;
		}

		float update() {
			using namespace std::chrono;
			const auto old = last;
			last = steady_clock::now();
			const duration<float> frameTime = last - old;
			m_time = frameTime.count();
			return m_time;
		}

		float get() {
			return m_time;
		}
		float get_ms() {
			return m_time * 0.00f;
		}

	 private:
		float m_time = 0.0f;
		std::chrono::steady_clock::time_point last;
	};

}