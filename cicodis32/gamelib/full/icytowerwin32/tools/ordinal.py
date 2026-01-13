import pefile

pe = pefile.PE("alleg40.dll")
for exp in pe.DIRECTORY_ENTRY_EXPORT.symbols:
    name = exp.name.decode('utf-8') if exp.name else None
    print(exp.ordinal, name)