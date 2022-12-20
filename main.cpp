/*
 *  This Source Code Form is subject to the terms of the Mozilla Public License,
 *  v. 2.0. If a copy of the MPL was not distributed with this file, You can
 *  obtain one at http://mozilla.org/MPL/2.0/.
 *
 *  The original code is copyright (c) 2022, open.mp team and contributors.
 */

#include <sdk.hpp>

class EmptyTemplate final : public IComponent
{
private:
	ICore* core_ = nullptr;

public:
	// https://open.mp/uid
	PROVIDE_UID(/* UID GOES HERE */);

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
		c->printLn("Empty component template loaded.");
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

	~EmptyTemplate()
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

COMPONENT_ENTRY_POINT()
{
	return new EmptyTemplate();
}
