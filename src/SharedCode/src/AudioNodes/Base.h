#pragma once

#include <memory>

namespace {

	template<typename T>
	using Scope = std::unique_ptr<T>;

}