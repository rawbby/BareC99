#include "allocator/allocator.h"

#include <common/sanitize.h>

#include <stdlib.h>

int
Allocator_malloc(Allocator* pAllocator, void** ppVoid, size_t size)
{
  pAllocator->malloc(pAllocator->pAllocatorExtra, ppVoid, size);
}

int
Allocator_realloc(Allocator* pAllocator, void** ppVoid, size_t size)
{
  pAllocator->realloc(pAllocator->pAllocatorExtra, ppVoid, size);
}

void
Allocator_free(Allocator* pAllocator, void** ppVoid)
{
  pAllocator->free(pAllocator->pAllocatorExtra, ppVoid);
}

static int
Mallocator_malloc(void* pAllocatorExtra, void** pVoid, size_t size)
{
  SANITIZE_ASSERT(pAllocatorExtra == NULL, "Mallocator has no extra but field is set! Not an initialized Mallocator!");
  void* pVoidTmp = malloc(size);
  if (pVoidTmp == NULL)
    return 1;

  *pVoid = pVoidTmp;
  return 0;
}

static int
Mallocator_realloc(void* pAllocatorExtra, void** pVoid, size_t size)
{
  SANITIZE_ASSERT(pAllocatorExtra == NULL, "Mallocator has no extra but field is set! Not an initialized Mallocator!");
  void* pVoidTmp = realloc(*pVoid, size);
  if (pVoidTmp == NULL)
    return 1;

  *pVoid = pVoidTmp;
  return 0;
}

static void
Mallocator_free(void* pAllocatorExtra, void** pVoid)
{
  SANITIZE_ASSERT(pAllocatorExtra == NULL, "Mallocator has no extra but field is set! Not an initialized Mallocator!");
  free(*pVoid);
  *pVoid = NULL;
}

int
Mallocator_create(Mallocator* pAllocator)
{
  pAllocator->pAllocatorExtra = NULL;
  pAllocator->malloc = Mallocator_malloc;
  pAllocator->realloc = Mallocator_realloc;
  pAllocator->free = Mallocator_free;
  return 0;
}

void
Mallocator_destroy(Mallocator* pAllocator)
{}

// void
// StackAllocator_create(StackAllocator* pAllocator)
// {}

// void
// StackAllocator_destroy(StackAllocator* pAllocator)
// {}
