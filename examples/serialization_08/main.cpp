#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <sstream>

std::stringstream ss;

class animal
{
public:
  animal() = default;
  animal(int legs) : legs_{legs} {}
  int legs() const { return legs_; }

private:
  friend class boost::serialization::access;

  template <typename Archive>
  void serialize(Archive &ar, const unsigned int version) { ar & legs_; }

  int legs_;
};

void save()
{
  boost::archive::text_oarchive oa{ss};
  animal *a = new animal{4};
  oa << a;
  std::cout << std::hex << a << '\n';
  delete a;
}

void load()
{
  boost::archive::text_iarchive ia{ss};
  animal *a;
  ia >> a;
  std::cout << std::hex << a << '\n';
  std::cout << std::dec << a->legs() << '\n';
  delete a;
}

int main()
{
  save();
  load();
}