#include <iostream>
#include <string>
using namespace std;

//***************** Implement UserPair Here *********************
template <class T>
class UserPair
{
public:
  UserPair(T first, T second)
  {
    m_first = first;
    m_second = second;
  }
  T First()
  {
    return m_first;
  }
  T Second()
  {
    return m_second;
  }

  T GetMax()
  {
    if (m_first > m_second)
    {
      return m_first;
    }
    else if (m_first == m_second)
    {
      return (m_first);
    }
    else
    {
      return m_second;
    }
  }

  T GetMin()
  {
    if (m_first < m_second)
    {
      return m_first;
    }
    else if (m_first == m_second)
    {
      return (m_first);
    }
    else
    {
      return m_second;
    }
  }

  T GetSum()
  {
    T sum = m_first + m_second;
    return sum;
  }

private:
  T m_first;
  T m_second;
};

//**************************************************************
int main()
{
  UserPair<int> intPair(1, 5);
  UserPair<string> stringPair("Hello", "World");

  cout << "intPair: {" << intPair.First() << ", " << intPair.Second() << "}\n";
  cout << "stringPair: {" << stringPair.First() << ", " << stringPair.Second() << "}\n";

  cout << "intPair max: " << intPair.GetMax() << endl
       << "intPair min: " << intPair.GetMin() << endl
       << "intPair sum: " << intPair.GetSum() << endl
       << "stringPair max: " << stringPair.GetMax() << endl
       << "stringPair min: " << stringPair.GetMin() << endl
       << "stringPair sum: " << stringPair.GetSum() << endl;

  return 0;
}
