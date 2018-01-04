struct base1 { virtual ~base1() = default; };
struct base2 { virtual ~base2() = default; };
struct derived : public base1, public base2 {};

void downcast(base1 *b1)
{
  derived *d = dynamic_cast<derived*>(b1);
}

void crosscast(base1 *b1)
{
  base2 *b2 = dynamic_cast<base2*>(b1);
}

int main()
{
  derived *d = new derived;
  downcast(d);

  base1 *b1 = new derived;
  crosscast(b1);
}