sudo mkdir /Volumes/Windows
sudo bindfs -o volname=Windows "/Users/gabrielvalky/VirtualBox VMs/demo" /Volumes/Windows
sudo mkdir /Volumes/Cico
sudo bindfs -o volname=Cico "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Demo/Root" /Volumes/Cico
PATH=$PATH:/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Demo/
