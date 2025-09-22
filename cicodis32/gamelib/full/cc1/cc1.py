import re

text = open("cc1.cpp").read()
pattern1 = r"push\(ax\);\s*ax\s*=\s*0x([0-9a-fA-F]+);\s*dx\s*=\s*0x([0-9a-fA-F]+);\s*push\(dx\);\s*push\(ax\);\s*push\(cs\);"
pattern2 = r"ax\s*=\s*0x([0-9a-fA-F]+);\s*dx\s*=\s*0x([0-9a-fA-F]+);\s*cx = ax;\s*bx = dx;\s*ax = .*;\s*dx = 0x002d;"

seen = set()
targets = []
for ax, dx in re.findall(pattern1, text):
  pair = (ax.lower(), dx.lower())
  if pair in seen:
    continue
  seen.add(pair)
  targets.append(f'"{dx.lower()}:{ax.lower()}"')

for ax, dx in re.findall(pattern2, text):
  pair = (ax.lower(), dx.lower())
  if pair in seen:
    continue
  seen.add(pair)
  targets.append(f'"{dx.lower()}:{ax.lower()}"')

print('{"id": "jumpTable", "addr": "01ed:d87c", callsFar:[' + ", ".join(targets) + ']}')
print('{"id": "jumpTable", "addr": "01ed:d8d8", callsFar:[' + ", ".join(targets) + ']}')
