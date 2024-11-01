#include <cassert>
#include "sol.cc"

#define TEST

void testmyMin(void)
{
  assert(myMin(5, 2) == 2);
  assert(myMin(1, 0) == 0);
  assert(myMin(1, 3) == 1);
  assert(myMin(3, 3) == 3);
  assert(myMin(2948920, 22501985) == 2948920);
}

void testmyMax(void)
{
  assert(myMax(5, 2) == 5);
  assert(myMax(1, 0) == 1);
  assert(myMax(1, 3) == 3);
  assert(myMax(3, 3) == 3);
  assert(myMax(2948920, 22501985) == 22501985);
}

void testsolution(void)
{
  assert( solution(5, 2, 4, 7) == Answer(6, 1) );
  assert( solution(5, 2, 7, 4) == Answer(6, 1) );
  assert( solution(9, 2, 7, 4) == Answer(3, 5) );
  assert( solution(6, 2, 7, 3) == Answer(3, 4) );
  assert( solution(9, 5, 7, 4) == Answer(1, 8) );
  assert( solution(5, 0, 7, 4) == Answer(1, 5) );
  assert( solution(5, 0, 7, 0) == Answer(1, 1) );
  assert( solution(5, 1, 7, 0) == Answer(2, 1) );
  assert( solution(5, 1, 7, 1) == Answer(2, 2) );
  assert( solution(1, 1, 1, 1) == Answer(2, 1) );
  assert( solution(0, 2, 5, 1) == Answer(3, 2) );
}

int main(void)
{
  testmyMin();
  testmyMax();
  testsolution();

}
