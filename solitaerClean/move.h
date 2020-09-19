#pragma once

class Move {
public:
	Move() : _pos(0), _dir(0) {}
	Move(pos_t pos, pos_t dir) : _pos(pos), _dir(dir) {}
	pos_t getPos() { return _pos; }
	pos_t getDir() { return _dir; }
private:
	pos_t _pos;
	pos_t _dir;
};
