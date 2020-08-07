#pragma once

namespace Vitro::Base
{
	template<typename U> class UniformBuffer
	{
	public:
		virtual void Bind() const = 0;
	};
}
