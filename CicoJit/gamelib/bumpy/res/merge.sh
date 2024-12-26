#magick montage image1.png image2.png image3.png blank.png image4.png image5.png image6.png image7.png image8.png -tile 3x3 -geometry 100x100+5+5 output.png

#exit 0
set -e
magick convert -size 640x400 xc:none blank.png
tiles=
for level in {1..9}; do
  tiles="${tiles} ../$(printf "%02d" $level).png"
  for room in {1..15}; do
    id=$(printf "%02d" $level)$(printf "%02d" $room)
    if [ -e "${id}.png" ]; then
      tiles="${tiles} ${id}.png"
      #rm res/temp.bmp
      #./bumpy res/temp.bmp $level $room
      #convert res/temp.bmp -resize 200% res/$(printf "%02d" $level)$(printf "%02d" $room)bkg.png
    else
      tiles="${tiles} blank.png"
    fi
  done
done

magick montage -background black ${tiles} -tile 16x9 -geometry 640x400 -quality 50 output.jpg
exit 0

magick convert -size 640x400 xc:none blank.png

exit 0
magick montage -tile 1x -geometry 640x400+0+0 *.png -quality 50 output.jpg
exit 0
for file in ../*bkg.png; do 
  id=${file:3:4}
  convert ../${id}bkg.png ../${id}.png -composite ${id}.png
  #echo "${file:3:4}" 
done
