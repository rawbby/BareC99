#include <allocator/allocator.h>
#include <common/log.h>
#include <common/sanitize.h>

#include <stdlib.h>

int
main()
{
  Allocator allocator;
  SANITIZE_ASSERT(Mallocator_create(&allocator) == 0, "");
  Mallocator_destroy(&allocator);

  void* pVoid;
  SANITIZE_ASSERT(allocator.malloc(allocator.pAllocatorExtra, &pVoid, 1024) == 0, "");
}
