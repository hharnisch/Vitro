#pragma once

namespace Vitro::Base
{
	class IndexBuffer
	{
	public:
		virtual void Bind() const = 0;
		virtual uint32_t Count() const = 0;
	};
}
