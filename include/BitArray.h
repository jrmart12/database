#ifndef BITARRAY_H
#define BITARRAY_H
#include <cassert>
#include <math.h>


class BitArray
{
private:
  class Bit
  {
    friend class BitArray;
      private:
        int i;
        char *data;
        Bit (int i, char *data);
      public:
        operator bool () const;
        Bit operator = (bool val);
  };

private:
  int len_;
  char *array;
public:
  BitArray (int num_bits);
  ~BitArray ();
  Bit operator [] (int i);
  int len () const;
};

#endif // BITARRAY_H
