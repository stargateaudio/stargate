# AppImage
This document describes how to build an AppImage for Stargate DAW.

# Current issues
This is not as portable as one would hope.  Starting with an old base
like Debian 10 in late 2021, Qt does not work correctly in distros like
Ubuntu 20.04 or Debian 11, although it will work well in another fresh
Debian 10 VM running a live USB image, including other DE variants.
It does not even work correctly on comparably old distros like CentOS 8.

Uses an ultra-heavyweight Debian base, because it's much simpler than the
alternative of packaging a massive Qt application with many dependencies.

The current AppImage is about 250MB.  The theoretical minimum is maybe 50MB,
or more realistically, 100MB.  Most of this comes from the chroot retaining
a lot of things that are not needed for the AppImage, however, deleting them
would require rebuilding the entire chroot every time.

An LZMA compressed file system is slower to read than a normal file system,
but this is a limitation of AppImage and not something we can change

# Prerequisites
- A Debian 10 install
- Clone the Stargate repo
- Download appimagetool
- Install debootstrap

# Creating the AppDir
```
# cd to the stargate directory
debootstrap --variant=minbase buster stargate.AppDir
```

# Updating with the latest Stargate DAW
```
rm src/*.deb
./scripts/deb.py
cp src/stargate-*.deb stargate.AppDir
sudo chroot stargate.AppDir
apt install --reinstall ./stargate-*.deb
exit
```

# Setup files and links
```
cd stargate.AppDir
```

Create a file called AppRun
```
#!/bin/sh -xe

export LD_LIBRARY_PATH="$(python3 -c "
import glob
import os
result = []
appdir = os.environ['APPDIR']
for root, dirs, files in os.walk(appdir):
    if glob.glob(
        os.path.join(root, '*.so'),
    ) or glob.glob(
        os.path.join(root, '*.so.[0-9]'),
	):
        result.append(root)
_str = ':'.join(result)
assert len(_str) <= 4096, len(_str)
print(_str)
")"

${APPDIR}/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 \
	${APPDIR}/usr/bin/python3 \
	${APPDIR}/usr/bin/stargate \
	"$@"
```

```
chmod +x AppRun
ln -s usr/share/pixmaps/stargate.png .DirIcon
ln -s usr/share/applications/stargate.desktop stargate.desktop
ls -s usr/share/pixmaps/stargate.png stargate.png
```

# Create the image
```
./appimagetool-x86_64.AppImage ./stargate.AppDir
```
