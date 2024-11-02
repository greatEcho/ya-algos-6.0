#include <cassert>
#include <iostream>

using std::cin; using std::cout; using std::endl;

typedef unsigned long int ulint;

struct Answer {
  ulint num_tshirts;
  ulint num_socks;
  Answer(void): num_tshirts(0), num_socks(0) {};
  Answer(ulint num_tshirts, ulint num_socks): num_tshirts(num_tshirts), num_socks(num_socks) {};
  bool operator==(const Answer &other) const {
    if (this->num_tshirts == other.num_tshirts &&
        this->num_socks == other.num_socks)
      return true;
    else return false;
  }
  ulint sum(void) {
    return num_tshirts + num_socks;
  }
};

ulint myMin(const ulint a, const ulint b);
ulint myMax(const ulint a, const ulint b);
Answer variant1(ulint num_bluet, ulint num_redt,
                ulint num_blues, ulint num_reds);
Answer variant2(ulint num_bluet, ulint num_redt,
                ulint num_blues, ulint num_reds);

Answer solution(ulint num_bluet, ulint num_redt, 
              ulint num_blues, ulint num_reds)
{
  // we should have atleast one pair of tshirts and socks
  assert(num_bluet != 0 || num_reds != 0);
  assert(num_redt != 0 || num_blues != 0);

  Answer ans1, ans2;
  // if one of values is zero
  if (!(num_bluet && num_redt && num_blues && num_reds)) {
    if (num_bluet == 0) return Answer(1, num_blues + 1);
    if (num_redt == 0)  return Answer(1, num_reds + 1);
    if (num_blues == 0) return Answer(num_bluet + 1, 1);
    if (num_reds == 0) return Answer(num_redt + 1, 1);
    assert(1 == 0);
  }
  ans1 = variant1(num_bluet, num_redt, num_blues, num_reds);
  ans2 = variant2(num_bluet, num_redt, num_blues, num_reds);
  
  //cout << ans1.num_tshirts << " " << ans1.num_socks << endl;
  //cout << ans2.num_tshirts << " " << ans2.num_socks << endl;
  //cout << "------\n";
  return (ans1.sum() < ans2.sum()) ? ans1 : ans2;
}

Answer variant1(ulint num_bluet, ulint num_redt,
                ulint num_blues, ulint num_reds)
{
  // TODO: решение принимается на основе футболок
  // Решение должно учитывать кол-во носков
  Answer answer;

  if (num_bluet + num_blues < num_redt + num_reds) {
    answer.num_tshirts = num_bluet + 1;
    answer.num_socks = num_blues + 1;
  }
  else {
    answer.num_tshirts = num_redt + 1;
    answer.num_socks = num_reds + 1;
  }

  return answer;
}

Answer variant2(ulint num_bluet, ulint num_redt,
                ulint num_blues, ulint num_reds)
{
  Answer answer;
  if (myMax(num_bluet, num_redt) <= myMax(num_blues, num_reds) ) {
  answer.num_tshirts = myMax(num_bluet, num_redt) + 1;
  answer.num_socks = 1;
  }
  else {
    answer.num_socks = myMax(num_blues, num_reds) + 1;
    answer.num_tshirts = 1;
  }

  return answer;
}

ulint myMin(const ulint a, const ulint b)
{
  return (a<=b) ? a : b;
}

ulint myMax(const ulint a, const ulint b)
{
  return (a>b) ? a: b;
}


#ifndef TEST
int main(void)
{
  ulint num_bluet, num_redt, num_blues, num_reds;
  cin >> num_bluet >> num_redt >> num_blues >> num_reds;

  Answer answer;
  answer = solution(num_bluet, num_redt, num_blues, num_reds);
  
  cout << answer.num_tshirts << " " << answer.num_socks << endl;
}
#endif
