apt-get source xserver-xorg-input-wacom 

git diff --no-prefix origin/master github/master > distortion.patch

patch -p0 < ../linuxwacom-xf86-input-wacom/distortion.patch

debuild -us -uc
