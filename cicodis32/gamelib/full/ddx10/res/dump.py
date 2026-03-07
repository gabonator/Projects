import pefile
import os
import sys

def get_resource_name(entry):
    if entry.name is not None:
        return str(entry.name)
    else:
        return str(entry.id)

def dump_resources(pe_path, output_dir, only_type=None):
    pe = pefile.PE(pe_path)

    if not hasattr(pe, "DIRECTORY_ENTRY_RESOURCE"):
        print("No resource directory found.")
        return

    os.makedirs(output_dir, exist_ok=True)

    for resource_type in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        type_name = get_resource_name(resource_type)

        if only_type and type_name != only_type:
            continue

        for resource_id in resource_type.directory.entries:
            name = get_resource_name(resource_id)

            for resource_lang in resource_id.directory.entries:
                data_entry = resource_lang.data

                rva = data_entry.struct.OffsetToData
                size = data_entry.struct.Size

                data = pe.get_data(rva, size)

                # Try to detect PNG automatically
                if data.startswith(b"\x89PNG"):
                    ext = ".png"
                elif data.startswith(b"BM"):
                    ext = ".bmp"
                elif data.startswith(b"\xFF\xD8"):
                    ext = ".jpg"
                else:
                    ext = ".bin"

                filename = f"{type_name}_{name}{ext}"
                filepath = os.path.join(output_dir, filename)

                with open(filepath, "wb") as f:
                    f.write(data)

                print(f"[+] Dumped {filename}")

    print("Done.")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python dump_resources.py <dll_path> <output_dir>")
        sys.exit(1)

    dll_path = sys.argv[1]
    output_dir = sys.argv[2]

    # change only_type to "DATA" to extract only DATA resources
    dump_resources(dll_path, output_dir, only_type="DATA")
