#define COMMON_IMPLEMENTATION
#include "common.h"

int main()
{
  {
    constexpr isize array_count = 8;
    Array<i32, array_count> arr = {0, 1, 2, 3};
    ASSERT(arr.count() == array_count, "Array count incorrect");

    for (auto& i : arr)
    {
      printf("%d\n", i);
    }


    constexpr isize slice_begin = 1;
    auto slicer = slice(&arr, slice_begin, arr.count());
    ASSERT(slicer.count == arr.count() - slice_begin, "Array count incorrect");

    for (auto& s : slicer)
    {
      printf("%d\n", s);
    }
  }

  {
    String s = String("Yo!");
    printf("String: %s, count: %td\n", s.data, s.count);
  }

  {
    Arena arena = arena_make(MB(1));
    printf("%lu\n", arena.capacity);
    arena_free(&arena);
  }

  {
    u8 backing[KB(1)] = {0};
    Arena arena = arena_make_backed(backing, KB(1));
    printf("%lu\n", arena.capacity);
    arena_free(&arena);
  }
}
