#include <iostream>

class Tile {

public:
  Tile() = default;
  explicit Tile(int displayValue) : m_displayValue(displayValue) {}

  int getNum() { return m_displayValue; }
  bool isEmpty() { return (m_displayValue == 0); }
  friend std::ostream &operator<<(std::ostream &out, Tile tile);

private:
  int m_displayValue{};
};

std::ostream &operator<<(std::ostream &out, Tile tile) {
  if (tile.m_displayValue == 0)
    out << "    ";
  else if (tile.m_displayValue > 9)
    out << " " << tile.m_displayValue << " ";
  else
    out << "  " << tile.m_displayValue << "  ";

  return out;
}

int main() {
  Tile tile1{10};
  Tile tile2{8};
  Tile tile3{0}; // the missing tile
  Tile tile4{1};

  return 0;
}
