#pragma once

#include "Vitro/Graphics/VertexTopology.h"

namespace Vitro::Base
{
	template<typename V> class VertexBuffer
	{
	public:
		virtual void Bind(VertexTopology vt) const = 0;
		virtual uint32_t Count() const = 0;
	};
}
