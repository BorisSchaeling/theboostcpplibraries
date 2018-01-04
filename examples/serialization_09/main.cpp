#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/scoped_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <iostream>
#include <sstream>

using namespace boost::archive;

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
  text_oarchive oa{ss};
  boost::scoped_ptr<animal> a{new animal{4}};
  oa << a;
}

void load()
{
  text_iarchive ia{ss};
  boost::scoped_ptr<animal> a;
  ia >> a;
  std::cout << a->legs() << '\n';
}

int main()
{
  save();
  load();
}