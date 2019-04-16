#ifndef _MAP_H
#define _MAP_H

class Map {
public:
	Map();
	~Map();

	static void LoadMap(std::string path, int sizeX, int sizeY);

};

#endif //_MAP_H