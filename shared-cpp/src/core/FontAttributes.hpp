/*
 * FontAttributes.hpp
 *
 *  Created on: 29.03.2018
 */

#ifndef SRC_CORE_FONTATTRIBUTES_HPP_
#define SRC_CORE_FONTATTRIBUTES_HPP_

namespace plane {

class FontAttributes {
public:
	FontAttributes() {
		size = 12;
		bold = false;
		italic = false;
		underlined = false;
	}

	FontAttributes(float size) {
		this->size = size;
		bold = false;
		italic = false;
		underlined = false;
	}

	FontAttributes(float size, bool bold, bool italic, bool underlined) {
		this->size = size;
		this->bold = bold;
		this->italic = italic;
		this->underlined = underlined;
	}

	virtual ~FontAttributes() {}

	void setSize(float size) { this->size = size; }

	float getSize() { return size; }

	bool isBold() { return bold; }

	bool isItalic() { return italic; }

	bool isUnderlined() { return underlined; }
private:
	float size;
	bool bold;
	bool italic;
	bool underlined;
};

}

#endif /* SRC_CORE_FONTATTRIBUTES_HPP_ */
