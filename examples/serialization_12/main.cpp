#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>
#include <iostream>
#include <sstream>

using namespace boost::archive;

std::stringstream ss;

class animal
{
public:
  animal() = default;
  animal(int legs) : legs_{legs} {}
  virtual int legs() const { return legs_; }
  virtual ~animal() = default;

private:
  friend class boost::serialization::access;

  template <typename Archive>
  void serialize(Archive &ar, const unsigned int version) { ar & legs_; }

  int legs_;
};

class bird : public animal
{
public:
  bird() = default;
  bird(int legs, bool can_fly) :
    animal{legs}, can_fly_{can_fly} {}
  bool can_fly() const { return can_fly_; }

private:
  friend class boost::serialization::access;

  template <typename Archive>
  void serialize(Archive &ar, const unsigned int version)
  {
    ar & boost::serialization::base_object<animal>(*this);
    ar & can_fly_;
  }

  bool can_fly_;
};

BOOST_CLASS_EXPORT(bird)

void save()
{
  text_oarchive oa{ss};
  animal *a = new bird{2, false};
  oa << a;
  delete a;
}

void load()
{
  text_iarchive ia{ss};
  animal *a;
  ia >> a;
  std::cout << a->legs() << '\n';
  delete a;
}

int main()
{
  save();
  load();
}