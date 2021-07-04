#include "random.h"

namespace utl {
	namespace _internals {
		std::mt19937 _Random::s_randomEngine;
		std::uniform_int_distribution<std::mt19937::result_type> _Random::s_distribution;
		const _Random _Random::random;
	}
}