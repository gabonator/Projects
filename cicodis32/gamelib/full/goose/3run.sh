# argument to app.elf is number of frames to simulate. For the last frame when the program
# is built with HEADLESS macro, it will print the video buffer into stderr
#
# 0, 1, 2 = black
# 3 - intro
# 90 - intro with text
# 260 - game started
# 480 - enemy firing
# 990 - tunnel opening
# 1080 - inside tunnel
# 1250 - tunnel ends
# 1820 - explosion, death, restart

./app.elf 1820 2> image.raw
magick -size 320x200 -depth 8 rgb:image.raw image.png

