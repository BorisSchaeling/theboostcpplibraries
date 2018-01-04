#include <boost/parameter.hpp>
#include <boost/mpl/placeholders.hpp>
#include <type_traits>
#include <typeinfo>
#include <iostream>

BOOST_PARAMETER_TEMPLATE_KEYWORD(integral_type)
BOOST_PARAMETER_TEMPLATE_KEYWORD(floating_point_type)
BOOST_PARAMETER_TEMPLATE_KEYWORD(any_type)

using namespace boost::parameter;
using boost::mpl::placeholders::_;

typedef parameters<
  required<tag::integral_type, std::is_integral<_>>,
  required<tag::floating_point_type, std::is_floating_point<_>>,
  required<tag::any_type, std::is_object<_>>
> complicated_signature;

template <class A, class B, class C>
class complicated
{
public:
  typedef typename complicated_signature::bind<A, B, C>::type args;
  typedef typename value_type<args, tag::integral_type>::type integral_type;
  typedef typename value_type<args, tag::floating_point_type>::type
    floating_point_type;
  typedef typename value_type<args, tag::any_type>::type any_type;
};

int main()
{
  typedef complicated<floating_point_type<double>, integral_type<int>,
    any_type<bool>> c;
  std::cout << typeid(c::integral_type).name() << '\n';
  std::cout << typeid(c::floating_point_type).name() << '\n';
  std::cout << typeid(c::any_type).name() << '\n';
}