/*
 * ImageView.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_PLANE_GUI_IMAGEVIEW_HPP_
#define SRC_PLANE_GUI_IMAGEVIEW_HPP_

#include <string>

#include "BaseWidget.hpp"
#include "../math/Vec2.hpp"
#include "../utils/Color.hpp"

namespace plane {

class ImageView : public BaseWidget {
public:
	ImageView(std::string imgFilePath) {
		this->imgFilePath = imgFilePath;
		width = -1;
		height = -1;
	}

	ImageView(std::string imgFilePath, int w, int h) {
		this->imgFilePath = imgFilePath;
		width = w;
		height = h;
	}

	virtual ~ImageView() {}

	virtual void paint(IScreen& screen) {
		const Vec2<float>& pos = getPos();
		if (width < 0 || height < 0) {
			screen.drawImage(imgFilePath, pos.getX(), pos.getY(), width, height);
		} else {
			screen.drawImageSized(imgFilePath, pos.getX(), pos.getY(), width, height);
		}
	}
private:
	std::string imgFilePath;
	float width;
	float height;
};

}

#endif /* SRC_PLANE_GUI_IMAGEVIEW_HPP_ */
