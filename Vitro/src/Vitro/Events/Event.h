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
		virtual const std::string GetName() const = 0;
		virtual EventSource GetSourceFlags() const = 0;

		virtual explicit operator std::string() const;

		bool HasSourceFlag(EventSource flag);
		bool IsHandled() const;

		template<class E, typename H> void Dispatch(const H& handler)
		{
			if(E::StaticType() == GetType())
				Handled = handler(static_cast<E&>(*this));
		}

	private:
		bool Handled = false;
	};
}

// Must be used to pass non-static member functions as event handlers.
#define Method(m) std::bind(&m, this, std::placeholders::_1)

// Shorthand for implementing virtual methods related to the event type.
#define $EventType(t) static EventType StaticType()				 { return EventType::t; }	\
					  EventType GetType() const override		 { return StaticType(); }	\
					  const std::string GetName() const override { return #t; }

// Shorthand for implementing virtual methods related to the event source.
#define $EventSource(s) EventSource GetSourceFlags() const override	{ return s; }
