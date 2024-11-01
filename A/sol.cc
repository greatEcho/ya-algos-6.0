#include <iostream>

using std::cin; using std::cout; using std::endl;

struct Point {
  short x;
  short y;
  Point(void): x(0), y(0) {};
  Point(short x, short y): x(x), y(y) {};
};

struct Sector {
  short x;
  short y;
};

void findSector(const Point  &left_raft, const Point  &right_raft, const Point &swimmer, Sector &sector);



int main(void)
{
  Sector sector;
  // read input
  Point left_raft, right_raft, swimmer;
  cin >> left_raft.x >> left_raft.y;
  cin >> right_raft.x >> right_raft.y;
  cin >> swimmer.x >> swimmer.y;

  if (swimmer.y <= left_raft.y) {
    // самый низ
    sector.y = 0;

  } else if (swimmer.y < right_raft.y) {
    // серединка
    sector.y = 1;
  } else {
    // верх
    sector.y = 2;
  }
  findSector(left_raft, right_raft, swimmer, sector);

  if (sector.y == 0) cout << 'S';
  if (sector.y == 2) cout << 'N';
  if (sector.x == 0) cout << 'W';
  if (sector.x == 2) cout << 'E';
  cout << endl;
}

void findSector(const Point  &left_raft, const Point  &right_raft, const Point &swimmer, Sector &sector)
{
  if (swimmer.x <= left_raft.x) {
    // слева
    sector.x = 0;
    
  } else if (swimmer.x < right_raft.x) {
    // посередине
    sector.x = 1;
  } else {
    // справа
    sector.x = 2;
  }
  
}
