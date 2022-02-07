#ifndef CORE_ALLOCATOR_ALLOCATOR_ALLOCATOR_H
#define CORE_ALLOCATOR_ALLOCATOR_ALLOCATOR_H

typedef struct Allocator
{
  void* pAllocatorExtra;
  int (*malloc)(void* pAllocatorExtra, void** pVoid, size_t size);
  int (*realloc)(void* pAllocatorExtra, void** pVoid, size_t size);
  void (*free)(void* pAllocatorExtra, void** pVoid);
} Allocator;

int
Allocator_malloc(Allocator* pAllocator, void** ppVoid, size_t size);

int
Allocator_realloc(Allocator* pAllocator, void** ppVoid, size_t size);

void
Allocator_free(Allocator* pAllocator, void** ppVoid);

typedef Allocator Mallocator;

int
Mallocator_create(Mallocator* pAllocator);

void
Mallocator_destroy(Mallocator* pAllocator);

// typedef Allocator StackAllocator;
// void StackAllocator_create(StackAllocator* pAllocator);
// void StackAllocator_destroy(StackAllocator* pAllocator);

#endif
