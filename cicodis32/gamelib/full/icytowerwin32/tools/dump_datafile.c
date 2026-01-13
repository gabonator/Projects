#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

static uint32_t be32(FILE *f)
{
    unsigned char b[4];
    fread(b, 1, 4, f);
    return (b[0]<<24)|(b[1]<<16)|(b[2]<<8)|b[3];
}

static void read4(FILE *f, char s[5])
{
    fread(s, 1, 4, f);
    s[4] = 0;
}

static const char *basename_from_path(const char *path)
{
    const char *p = path + strlen(path);
    while (p > path) {
        if (p[-1] == '\\' || p[-1] == '/')
            break;
        p--;
    }
    return p;
}

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "rb");
    char id[5];
    uint32_t count;

    read4(f, id);
    if (strcmp(id, "ALL.") != 0) {
        puts("Not an Allegro datafile");
        return 1;
    }

    count = be32(f);
    printf("Objects: %u\n\n", count);

    for (uint32_t i = 0; i < count; i++) {
        printf("Object %u:\n", i);
char orig_path[1024] = "";
char orig_name[1024] = "";

        while (1) {

            long pos = ftell(f);
            read4(f, id);

            /* property */
            if (memcmp(id, "prop", 4) == 0) {
                char pname[5];
                read4(f, pname);

                uint32_t len = be32(f);
                char *buf = malloc(len + 1);
                fread(buf, 1, len, f);
                buf[len] = 0;

                printf("  Property '%s' = \"%s\"\n", pname, buf);
if (strcmp(pname, "ORIG") == 0) {
    strncpy(orig_path, buf, sizeof(orig_path) - 1);
}
if (strcmp(pname, "NAME") == 0) {
    strncpy(orig_name, buf, sizeof(orig_name) - 1);
}
                free(buf);
                continue;
            }

            /* payload */
            fseek(f, pos, SEEK_SET);
            read4(f, id);

            uint32_t size = be32(f);
            uint32_t size2 = be32(f);
            printf("  Payload type: '%s'\n", id);
            printf("  Payload size: %u bytes\n\n", size);
            printf("  Payload size: %u bytes\n\n", size2);

char outname[1024] = "output/";
if (orig_path[0]) {
    strcat(outname, basename_from_path(orig_path));
} else {
    /* fallback */
    strcat(outname, "object.bin");
}
if (id[3] == 0x20) id[3] = 0;
sprintf(outname, "output/%s_%s", id, orig_name);
printf("out %s, %s\n", orig_path, outname);

FILE *out = fopen(outname, "wb");
if (!out) {
    perror("fopen output");
    fseek(f, size, SEEK_CUR);
} else {
    unsigned char buf[4096];
    uint32_t remaining = size;

    while (remaining > 0) {
        size_t chunk = remaining > sizeof(buf) ? sizeof(buf) : remaining;
        fread(buf, 1, chunk, f);
        fwrite(buf, 1, chunk, out);
        remaining -= chunk;
    }

    fclose(out);
    printf("  Saved to: %s\n\n", outname);
}

//            fseek(f, size, SEEK_CUR);
            break;
        }
    }

    fclose(f);
    return 0;
}
