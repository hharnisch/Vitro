#pragma once

#include "Vitro/Graphics/VertexTopology.h"

namespace Vitro::Base
{
	template<typename V> class VertexBuffer
	{
	public:
		virtual void Bind(VertexTopology topology) const = 0;
	};
}
