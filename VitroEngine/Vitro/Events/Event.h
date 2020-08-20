#pragma once

#include "_pch.h"
#include "Vitro/Events/EventSource.h"
#include "Vitro/Events/EventType.h"

namespace Vitro
{
	class Event
	{
	public:
		virtual EventType GetType() const = 0;
		virtual std::string GetName() const = 0;
		virtual EventSource GetSourceFlags() const = 0;
		virtual explicit operator std::string() const = 0;

		inline bool HasSourceFlag(EventSource flag) const
		{
			return flag & GetSourceFlags();
		}

		inline bool IsHandled() const
		{
			return Handled;
		}

		template<typename E, typename H> inline void Dispatch(const H& handler)
		{
			if(GetType() == E::Type)
				Handled = handler(static_cast<E&>(*this));
		}

	private:
		bool Handled = false;
	};
}

// Must be used to pass non-static member functions as event handlers.
#define Method(m) std::bind(&m, this, std::placeholders::_1)

// Shorthand for implementing virtual methods related to the event type.
#define VTR_EVENT_TYPE(T) static constexpr EventType Type = EventType::T;				\
						  inline EventType   GetType() const override { return Type; }	\
						  inline std::string GetName() const override { return #T; }

// Shorthand for implementing virtual methods related to the event source.
#define VTR_EVENT_SOURCE(S) inline EventSource GetSourceFlags() const override { return S; }
