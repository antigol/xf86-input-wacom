=== create patch ===

== git config file ==
[remote "github"]
	url = git@github.com:antigol/xf86-input-wacom.git
	fetch = +refs/heads/*:refs/remotes/github/*
[remote "wacom"]
	url = git://git.code.sf.net/p/linuxwacom/xf86-input-wacom
	fetch = +refs/heads/*:refs/remotes/wacom/*
[branch "master"]
	remote = github
	merge = refs/heads/master

git pull wacom master
git pull
git push
git diff --no-prefix wacom/master github/master > distortion.patch


=== patch and install ===

apt-get source xf86-input-wacom

patch -p0 < path/to/distortion.patch

sudo apt-get install devscripts build-essential lintian

dpkg-buildpackage -us -uc
