import pefile
import struct
import os

DLL_PATH = "../input/Delay Lama.dll"
OUTPUT_DIR = "rsrc"

os.makedirs(OUTPUT_DIR, exist_ok=True)

def create_bmp(data):
    """
    Add BMP file header to RT_BITMAP resource data
    """
    header_size = struct.unpack("<I", data[0:4])[0]

    if header_size == 12:
        offset = 14 + 12
    else:
        offset = 14 + 40

    filesize = len(data) + 14

    bmp_header = struct.pack(
        "<2sIHHI",
        b"BM",
        filesize,
        0,
        0,
        offset
    )

    return bmp_header + data


def dump_bitmaps(pe):
    count = 0

    if not hasattr(pe, "DIRECTORY_ENTRY_RESOURCE"):
        print("No resources found.")
        return

    for entry in pe.DIRECTORY_ENTRY_RESOURCE.entries:

        rtype = entry.name if entry.name else entry.struct.Id

        if rtype != 2:
            continue

        for res in entry.directory.entries:

            name = res.name if res.name else res.struct.Id

            for lang in res.directory.entries:

                data = lang.data.struct
                offset = data.OffsetToData
                size = data.Size

                raw = pe.get_memory_mapped_image()[offset:offset+size]

                bmp = create_bmp(raw)

                filename = os.path.join(
                    OUTPUT_DIR,
                    f"bitmap_{name}_{lang.struct.Id}.bmp"
                )

                with open(filename, "wb") as f:
                    f.write(bmp)

                print("Extracted:", filename)
                count += 1

    print(f"\nTotal bitmaps extracted: {count}")


def main():
    print("Loading DLL...")
    pe = pefile.PE(DLL_PATH)

    dump_bitmaps(pe)


if __name__ == "__main__":
    main()