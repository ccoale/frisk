#ifndef _FRISK_H
#define _FRISK_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <functional>

#define FRISK_TRUE  1
#define FRISK_FALSE 0

#define FRISK_TEST_HEADER void(Frisk::Test &)

#define FRISK_TEST_TYPE_DEFAULT     0x00
#define FRISK_TEST_TYPE_CRITICAL    0x01

namespace Frisk
{
  struct Test
  {
    /*
     ** This is the test function that is called
     ** for this specific test.
     */
    std::function<FRISK_TEST_HEADER> function;

    /*
     ** The textual name of this test.
     */
    std::string name;

    /*
     ** The type of test (i.e. critical)
     */
    int type;
  }
}

#endif /* _FRISK_H */
