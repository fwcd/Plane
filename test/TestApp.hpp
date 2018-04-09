/*
 * TestApp.hpp
 *
 *  Created on: 31.03.2018
 *      Author: fredrik
 */

#ifndef TEST_TESTAPP_HPP_
#define TEST_TESTAPP_HPP_

#include <memory>

// Include plane sources
#include <plane/utils/Color.hpp>
#include <plane/core/Screen.hpp>
#include <plane/core/PlaneApp.hpp>
#include <plane/gui/GUI.hpp>
#include <plane/gui/Label.hpp>
#include <plane/gui/ImageView.hpp>
#include <plane/gui/Button.hpp>

namespace plane {

class TestApp : public PlaneApp {
public:
	virtual ~TestApp() {}

	virtual void initialize(std::shared_ptr<Screen> screen) {
		screen->setBackground(Color(60, 60, 60));

		std::shared_ptr<Label> label(new Label("Label", 24, *screen));
		label->setColor(COLOR_WHITE);
		std::shared_ptr<ImageView> image(new ImageView("resources/demo.jpg"));
		std::shared_ptr<Button> button(new Button("Demo", 14, *screen));
		std::shared_ptr<Button> button2(new Button("Demo", 18, *screen));

		std::shared_ptr<GUI> gui(new GUI(screen));
		gui->add(label);
		gui->add(button);
		gui->add(image);
		gui->add(button2);
		screen->addOnTop(gui);
		LOG.info("Initialized GUI");
	}
};

}

#endif /* TEST_TESTAPP_HPP_ */
