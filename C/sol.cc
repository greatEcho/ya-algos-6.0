#include <cassert>
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;


struct Point {
  short x;
  short y;
  Point(void): x(-1), y(-1) {};
  Point(short y, short x): x(x), y(y) {};
  bool null(void) {
    return (x == -1 && y == -1);
  }
  bool operator==(const Point &other) {
    return (x == other.x && y == other.y);
  }
  bool operator!=(const Point &other) {
    return (x != other.x || y != other.y);
  }
};

struct Figure {
  Point* arr;
  Figure(void) { 
    arr = new Point[6];
  }
  ~Figure(void) {
    delete[] arr;
  }
};

bool left_border(vector<vector<bool>> A, short i, short j);
bool right_border(vector<vector<bool>> A, short i, short j);
bool isI(vector<vector<bool>> A, const short n);

void solution(void)
{
  // read input in 2D array
  short n;
  char c;
  cin >> n;
  cout << n << endl;
  assert((1 <= n) && (n <= 10));
  vector<vector<bool>> table(n, vector<bool>(n));
  for (short i = 0; i < n*n; i++) {
    cin >> c;
    if (c == '.') table[i/n][i%n] = 0;
    if (c == '#') table[i/n][i%n] = 1;
  }

  bool answer;
  answer = isI(table, n);

  // print table
  for (short i = 0; i < n; i++) {
    for (short j = 0; j < n; j++) {
      cout << table[i][j] << ' ';
    }
    cout << endl;
  }

  cout << "Answer: " << answer << endl;
}



bool left_border(vector<vector<bool>> A, short i, short j)
{
  if (j == 0) return A[i][j];
  assert(j != 0);
  return (A[i][j-1] == 0 && A[i][j] == 1);
}

bool right_border(vector<vector<bool>> A, short i, short j)
{
  if (j == A[i].size() - 1) return A[i][j];
  assert(j != A[i].size() - 1);
  return (A[i][j] == 1 && A[i][j+1] == 0);
}

bool isI(vector<vector<bool>> A, const short n)
{
  Figure fig;
  uint sum = 0;
  bool found_first_line = false;
  for (short i = 0; i < n; i++) {
    // get row i
    for (short j = 0; j < n; j++) {
      // get cell [i,j]
      if (left_border(A, i, j)) {
        if (fig.arr[0].null()) {
          fig.arr[0] = Point(i, j);
        } else {
          if (fig.arr[0].x != j) {
            return false;
          }
        }
      }
      if (right_border(A, i, j)) {
        if (fig.arr[1].null()) {
          fig.arr[1] = Point(i, j);
        } else {
          if (fig.arr[1].x != j) {
            return false;
          }
        }
      }
      sum += A[i][j];
    }
  }
  return (sum != 0);
}

bool isO(vector<vector<bool>> A, const short n)
{

}

#ifndef TEST
int main(void)
{
  solution();
}
#endif
