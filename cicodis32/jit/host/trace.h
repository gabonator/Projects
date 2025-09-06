#include <execinfo.h>
#include <iostream>
#include <cstdlib>

void trace() {
    void *buffer[100];
    int nptrs = backtrace(buffer, 100);
    char **symbols = backtrace_symbols(buffer, nptrs);

    std::cout << "Stack trace:\n";
    for (int i = 0; i < nptrs; i++) {
        std::cout << symbols[i] << "\n";
    }
    free(symbols);
    exit(7);
}