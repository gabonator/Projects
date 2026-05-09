#ifdef RASPI
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int init_mmap()
{

#ifndef MAP_FIXED_NOREPLACE
#define MAP_FIXED_NOREPLACE 0x100000
#endif

    const size_t length = 256UL * 1024UL * 1024UL;   // 256 MiB
    void *requested = (void *)0x10000000UL;

    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size <= 0) {
        perror("sysconf(_SC_PAGESIZE)");
        return 1;
    }

    if (((uintptr_t)requested % (uintptr_t)page_size) != 0) {
        fprintf(stderr, "Requested address %p is not page-aligned (page size = %ld)\n",
                requested, page_size);
        return 1;
    }

    void *p = mmap(
        requested,
        length,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE,
        -1,
        0
    );

    if (p == MAP_FAILED) {
        fprintf(stderr, "mmap failed: %s\n", strerror(errno));
        if (errno == EEXIST) {
            fprintf(stderr, "The requested range is already mapped.\n");
        }
        return 1;
    }

    printf("Requested address: %p\n", requested);
    printf("Returned  address: %p\n", p);

    if (p != requested) {
        fprintf(stderr, "Address mismatch.\n");
        munmap(p, length);
        return 1;
    }
    return 0;
}

#else

int init_mmap()
{
    return 0;
}
#endif
