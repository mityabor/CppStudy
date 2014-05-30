/*
 * main.cpp
 *
 *  Created on: 30 ??? 2014 ?.
 *      Author: d.borysenko
 */

// Uses a Array to reverse a name and test various properties of class
// Array<>.

#include <assert.h>
#include <iostream>
#include <string>
#include "Array.h"
using namespace std;

static const int INITIAL_NAME_LEN = 80;

typedef Array ARRAY;

int
main (int argc, char *argv[])
{
  ARRAY a1 (INITIAL_NAME_LEN, ' ');
  size_t i;
  string name;
  assert (a1.size () == INITIAL_NAME_LEN);

  std::cout << "please enter your name..: ";
  std::getline (std::cin, name);

  std::cout << "read in: " << name.length () << std::endl;

  for (i = 0; i < name.length (); i++)
    if (a1.set (name[i], i) == -1)
      {
        std::cout.flush();
        std::cerr << std::endl << "index out of range" <<i<< std::endl;
        return 1;
      }

  std::cout << "size is " << a1.size () << std::endl << "your name is..: ";

  for (i = 0; i < a1.size (); i++)
    std::cout << a1[i];

  std::cout << std::endl;

  // Test initialization with the copy constructor.
  ARRAY a2 (a1);
  ARRAY a3 (a1.size () + a2.size (), -1);

  // Test the assignment operator.
  a1 = a2;
  assert (a1.size () == a2.size ());
  assert (a1 == a2);
  assert (!(a1 != a2));

  a2 = a3;
  assert (a1.size () != a2.size ());
  assert (a1 != a2);

  // Test the operator[] for setting and getting.
  a2[0] = 'c';
  assert (a2[0] == 'c');

  // Test for self assignment.
  a3 = a3;

  std::cout << "your name backwards is..: ";

  // Note that we're "off by one here" so we'll get a range error.
  for (int j = name.length (); j > 0; j--)
    {
      ARRAY::value_type c;

      if (a1.get (c, j - 1) == -1)
        {
          std::cout.flush();
          std::cerr << std::endl << "index out of range" << std::endl;
          return 1;
        }
      std::cout << c;
    }

  std::cout << "\n";

  return 0;
}


