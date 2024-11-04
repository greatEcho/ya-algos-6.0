#include <cassert>
#include "sol.cc"

void testPoint(void)
{
  assert(Point() == Point(-1, -1));
  assert(Point().null());
  assert(Point(1, 1) == Point(2-1, 1));
  assert(Point(1, 0) != Point(2, 0));
  assert(Point(1, 0) != Point(1, 1));
  assert(!Point(1, 2).null());
}

void testFigure(void)
{
}

void testleft_border(void)
{
  vector<vector<bool>> arr = {
      {0, 1, 0},
      {1, 1, 0},
      {1, 1, 1},
      {0, 0, 1},
    };
  assert(!left_border(arr, 0, 0));
  assert(left_border(arr, 0, 1));
  assert(!left_border(arr, 0, 2));
  assert(left_border(arr, 1, 0));
  assert(!left_border(arr, 1, 1));
  assert(!left_border(arr, 1, 2));
  assert(left_border(arr, 2, 0));
  assert(!left_border(arr, 2, 1));
  assert(!left_border(arr, 2, 2));
  assert(left_border(arr, 3, 2));
  vector<vector<bool>> arr1 = {
    {1}
    };
  assert(left_border(arr1, 0, 0));
}

void testright_border(void)
{
  vector<vector<bool>> arr = {
      {0, 1, 0},
      {1, 1, 0},
      {1, 0, 0},
    };
  assert(!right_border(arr, 0, 0));
  assert(right_border(arr, 0, 1));
  assert(!right_border(arr, 0, 2));
  assert(!right_border(arr, 1, 0));
  assert(right_border(arr, 1, 1));
  assert(!right_border(arr, 1, 2));
  assert(right_border(arr, 2, 0));
  assert(!right_border(arr, 2, 1));
  assert(!right_border(arr, 2, 2));
  vector<vector<bool>> arr1 = {
    {1},
    {1, 1},
    };
  assert(right_border(arr1, 0, 0));
  assert(!right_border(arr1, 1, 0));
  assert(right_border(arr1, 1, 1));
}

void testisI(void)
{
  vector<vector<bool>> arr1 = {
    {0, 1, 1, 0,},
    {0, 1, 1, 0,},
    {0, 1, 1, 0,},
    {0, 0, 0, 0,},
  };
  assert(isI(arr1, arr1.size()));

  vector<vector<bool>> arr2 = {
    {0, 1, 1, 0,},
    {0, 1, 1, 0,},
    {0, 1, 1, 0,},
    {0, 0, 1, 0,},
  };
  assert(!isI(arr2, arr2.size()));

  vector<vector<bool>> arr3 = {
    {0, 1, 1, 0,},
    {0, 1, 0, 0,},
    {0, 1, 1, 0,},
    {0, 0, 0, 0,},
  };
  assert(!isI(arr3, arr3.size()));

  vector<vector<bool>> arr4 = {
    {0, 1, 1, 0,},
    {0, 1, 1, 1,},
    {0, 1, 1, 0,},
    {0, 0, 0, 0,},
  };
  assert(!isI(arr4, arr4.size()));

  vector<vector<bool>> arr5 = {
    {1},
  };
  assert(isI(arr5, arr5.size()));

  vector<vector<bool>> arr6 = {
    {0},
  };
  assert(!isI(arr6, arr6.size()));
}



int main(void)
{
  testPoint();
  testleft_border();
  testright_border();
  testFigure();
  testisI();
}

