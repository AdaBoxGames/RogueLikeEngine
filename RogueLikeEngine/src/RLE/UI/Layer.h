#pragma once

// Standard Library includes
#include <string>

// RLE Library includes
#include "RLE/Core/Time.h"
#include "RLE/Events/Eventable.h"



namespace rle
{
	class Layer : public Eventable
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		Layer(const std::string& name = "Layer");

		// Virtual default destructor
		virtual ~Layer() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Called when the layer is added to the state machine
		virtual void onEnter() = 0;

		// Called when the layer leaves the state machine
		virtual void onExit() = 0;

		// Called once every frame to update the layer
		virtual void onUpdate(const time::step_ms delta) = 0;

		// Called once every frame to render the layer
		virtual void onRender() const = 0;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the name of the layer
		const std::string& name() const;



	private:
		std::string m_DebugName = "";
	};
}
