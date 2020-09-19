#pragma once
typedef int pos_t;

template<pos_t ROW_SIZE, pos_t BORDER_ROWS>
class Pos {
public:
	Pos() : _pos(0) {}
	Pos(pos_t pos) : _pos(pos) {}
	Pos(pos_t x, pos_t y) : _pos(ROW_SIZE + x + y * ROW_SIZE) { }
	auto operator++(int) { _pos++; return *this; }
	operator pos_t() { return _pos;  }
private:
	pos_t _pos;
};