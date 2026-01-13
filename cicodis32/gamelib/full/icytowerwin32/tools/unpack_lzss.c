#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define N 4096
#define F 18
#define THRESHOLD 2

// LZSS decompression for Allegro 4
int decompress_lzss(FILE *in, FILE *out) {
    unsigned char text_buf[N + F - 1];
    int r = N - F;
    unsigned int flags = 0;

    memset(text_buf, 0, sizeof(text_buf));

    while (1) {
        if (((flags >>= 1) & 0x100) == 0) {
            int c = fgetc(in);
            if (c == EOF) break;
            flags = c | 0xFF00;
        }

        if (flags & 1) {
            int c = fgetc(in);
            if (c == EOF) break;
            fputc(c, out);
            text_buf[r++] = c;
            r &= (N - 1);
        } else {
            int i = fgetc(in);
            int j = fgetc(in);
            if (j == EOF) break;

            i |= ((j & 0xF0) << 4);
            j = (j & 0x0F) + THRESHOLD;

            for (int k = 0; k <= j; k++) {
                int c = text_buf[(i + k) & (N - 1)];
                fputc(c, out);
                text_buf[r++] = c;
                r &= (N - 1);
            }
        }
    }

    return 0;
}

// Check for Allegro magic header
int check_magic(FILE *f) {
    char magic[4];
    long pos = ftell(f);
    if (fread(magic, 1, 4, f) != 4) return 0;
//    fseek(f, pos, SEEK_SET); // reset file pointer

    // Common Allegro object headers
    if (memcmp(magic, "slh!", 4) == 0) return 1;
    if (memcmp(magic, "PACK", 4) == 0) return 1;
    // Add other magic headers if needed

    return 0; // unknown
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.packed output.raw\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "rb");
    if (!in) { perror("input"); return 1; }

    // Optionally check magic
    if (!check_magic(in)) {
        fprintf(stderr, "Warning: no Allegro magic header found. Continuing anyway.\n");
    }

    FILE *out = fopen(argv[2], "wb");
    if (!out) { perror("output"); fclose(in); return 1; }

    decompress_lzss(in, out);

    fclose(in);
    fclose(out);

    printf("Decompression finished: %s → %s\n", argv[1], argv[2]);
    return 0;
}
