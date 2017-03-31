#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Duck {  void quacks() {}   };
struct Dog  {  void barks() {}   };
// a seagull that knows how to quack
struct Seagull {  void quacks() {}   };

template <class T> T CompileIfDuck(T animal)   { animal.quacks();}

int main() {
  Duck duck;  Dog dog; Seagull seagull;
  CompileIfDuck(duck);		// compiles
  //CompileIfDuck(dog);		// does not compile
  CompileIfDuck(seagull);	// compiles
}
