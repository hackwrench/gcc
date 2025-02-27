/* { dg-do run {target { riscv_zvfh_hw } } } */
/* { dg-additional-options "-Wno-pedantic" } */

#include <assert.h>

#include "vec_extract-1.c"
#include "vec_extract-2.c"
#include "vec_extract-3.c"
#include "vec_extract-4.c"

#define CHECK(S, V, IDX)				\
void check_##V##_##IDX ()				\
  {							\
    V v;						\
    for (int i = 0; i < sizeof (V) / sizeof (S); i++)	\
      v[i] = i;						\
    S res = vec_extract_##V##_##IDX (v);		\
    assert (res == v[IDX]);				\
  }

#define CHECK_ALL(T)					\
  T (_Float16, vnx8hf, 0)				\
  T (_Float16, vnx8hf, 3)				\
  T (_Float16, vnx8hf, 7)				\
  T (_Float16, vnx16hf, 0)				\
  T (_Float16, vnx16hf, 3)				\
  T (_Float16, vnx16hf, 7)				\
  T (_Float16, vnx16hf, 8)				\
  T (_Float16, vnx16hf, 15)				\
  T (_Float16, vnx32hf, 0)				\
  T (_Float16, vnx32hf, 3)				\
  T (_Float16, vnx32hf, 7)				\
  T (_Float16, vnx32hf, 8)				\
  T (_Float16, vnx32hf, 16)				\
  T (_Float16, vnx32hf, 31)				\
  T (_Float16, vnx64hf, 0)				\
  T (_Float16, vnx64hf, 3)				\
  T (_Float16, vnx64hf, 7)				\
  T (_Float16, vnx64hf, 8)				\
  T (_Float16, vnx64hf, 16)				\
  T (_Float16, vnx64hf, 31)				\
  T (_Float16, vnx64hf, 42)				\
  T (_Float16, vnx64hf, 63)				\

CHECK_ALL (CHECK)

#define RUN(S, V, IDX)					\
  check_##V##_##IDX ();

#define RUN_ALL(T)					\
  T (_Float16, vnx8hf, 0)				\
  T (_Float16, vnx8hf, 3)				\
  T (_Float16, vnx8hf, 7)				\
  T (_Float16, vnx16hf, 0)				\
  T (_Float16, vnx16hf, 3)				\
  T (_Float16, vnx16hf, 7)				\
  T (_Float16, vnx16hf, 8)				\
  T (_Float16, vnx16hf, 15)				\
  T (_Float16, vnx32hf, 0)				\
  T (_Float16, vnx32hf, 3)				\
  T (_Float16, vnx32hf, 7)				\
  T (_Float16, vnx32hf, 8)				\
  T (_Float16, vnx32hf, 16)				\
  T (_Float16, vnx32hf, 31)				\
  T (_Float16, vnx64hf, 0)				\
  T (_Float16, vnx64hf, 3)				\
  T (_Float16, vnx64hf, 7)				\
  T (_Float16, vnx64hf, 8)				\
  T (_Float16, vnx64hf, 16)				\
  T (_Float16, vnx64hf, 31)				\
  T (_Float16, vnx64hf, 42)				\
  T (_Float16, vnx64hf, 63)				\

int main ()
{
  RUN_ALL (RUN);
}
