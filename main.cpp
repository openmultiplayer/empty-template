/*
 *  This Source Code Form is subject to the terms of the Mozilla Public License,
 *  v. 2.0. If a copy of the MPL was not distributed with this file, You can
 *  obtain one at http://mozilla.org/MPL/2.0/.
 *
 *  The original code is copyright (c) 2022, open.mp team and contributors.
 */

// Required for most of open.mp.
#include <sdk.hpp>

// This should use an abstract interface if it is to be passed to other components.  Like the files
// in `<Server/Components/>` you would share only this base class and keep the implementation
// private.
class EmptyTemplate final : public IComponent
{
private:
	// Hold a reference to the main server core.
	ICore* core_ = nullptr;

public:
	// Visit https://open.mp/uid to generate a new unique ID.
	PROVIDE_UID(/* UID GOES HERE */);

	// When this component is destroyed we need to tell any linked components this it is gone.
	~EmptyTemplate()
	{
	}

	// Implement the main component API.
	StringView componentName() const override
	{
		return "Empty Template";
	}

	SemanticVersion componentVersion() const override
	{
		return SemanticVersion(0, 0, 1, 0);
	}

	void onLoad(ICore* c) override
	{
		// Cache core, player pool here.
		core_ = c;
		core_->printLn("Empty component template loaded.");
	}

	void onInit(IComponentList* components) override
	{
	}

	void onReady() override
	{
		// Fire events here at earliest.
	}

	void onFree(IComponent* component) override
	{
	}

	void free() override
	{
		// Deletes the component.
		delete this;
	}

	void reset() override
	{
		// Resets data when the mode changes.
	}
};

// Automatically called when the compiled binary is loaded.
COMPONENT_ENTRY_POINT()
{
	return new EmptyTemplate();
}
