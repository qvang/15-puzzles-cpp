#include <iostream>
#include <vector>

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
    out << "  " << tile.m_displayValue << " ";

  return out;
}

constexpr int consoleLines{25};

class Board {
public:
  Board() {
    for (std::size_t i{}; i < 16; ++i) {
      Tile tile{static_cast<int>(i)};
      boardArray.push_back(tile);
    }
  }

  std::vector<Tile> boardArray{};

  friend std::ostream &operator<<(std::ostream &out, Board board);
};

std::ostream &operator<<(std::ostream &out, Board board) {

  for (std::size_t i{}; i < consoleLines; ++i) {
    out << '\n';
  }

  int j{};
  for (std::size_t i{1}; i <= 16; ++i) {
    if (j % 4 == 0 && i != 1) {
      out << '\n';
    }
    out << board.boardArray[i];
    j++;
  }

  return out;
}

int main() {
  Board board{};
  std::cout << board;

  return 0;
}
