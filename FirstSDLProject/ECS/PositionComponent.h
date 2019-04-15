#ifndef _POSITION_COMPONENT_H
#define _POSITION_COMPONENT_H

class PositionComponent : public Component {
public:
	PositionComponent() {
		xpos = 0;
		ypos = 0;
	}

	PositionComponent(int x, int y) {
		xpos = x;
		ypos = y;
	}

	int X() { return xpos; }
	int Y() { return ypos; }

	void Init() override {
		xpos = 0;
		ypos = 0;
	}

	void Set(int x, int y) {
		xpos = x;
		ypos = y;
	}

	void Update() override {
		xpos++;
		ypos++;
	}

private:
	int xpos;
	int ypos;
};

#endif //_POSITION_COMPONENT_H
