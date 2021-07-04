#pragma once

#include <random>

/*
class Random {
public:
	static void Init() {
		s_randomEngine.seed(std::random_device()());
	}
	static float Float() {
		return (float)s_distribution(s_randomEngine) / (float)std::numeric_limits<uint32_t>::max();
	}
private:
	static std::mt19937 s_randomEngine;
	static std::uniform_int_distribution<std::mt19937::result_type> s_distribution;
};*/


namespace utl {
	namespace _internals {

		class _Random {
		 private:
			_Random() { s_randomEngine.seed(std::random_device()()); }
		 public:
		 	_Random(const _Random&) = delete;
		 	_Random& operator=(const _Random&) = delete;

		 public:
		 	static float Float() {
		 		return (float)s_distribution(s_randomEngine) / (float)std::numeric_limits<uint32_t>::max();
		 	}

		 private:
		 	static std::mt19937 s_randomEngine;
		 	static std::uniform_int_distribution<std::mt19937::result_type> s_distribution;
		 public:
		 	static const _Random random;
		};
	}
	inline float random_float() {
		return _internals::_Random::random.Float();
	}
}