magick compo240x320.png -resize 240x320\! rgb:- | python3 -c '
import sys
rgb=sys.stdin.buffer.read()

print("#include <stdint.h>")
print("const uint16_t image[240*320] = {")

for i in range(0,len(rgb),3):
    r,g,b=rgb[i:i+3]
    pixel=((r>>3)<<11)|((g>>2)<<5)|(b>>3)
    print(f"0x{pixel:04x},", end="")
    if ((i//3+1)%12)==0:
        print()

print("};")
' > image.h