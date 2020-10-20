TizenFX Stub
============

Stubs to enable the TizenFX repository to build on Ubuntu and Windows.

Windows Build
-------------

  $ mkdir build
  $ cd build
  $ cmake -DCMAKE_INSTALL_PREFIX=%DALIENV_DIR% ..

MacOS Build
-------------
```bash
  $ mkdir -p build/tizen
  $ cd build/tizen
  $ cmake -DCMAKE_INSTALL_PREFIX=$DESKTOP_PREFIX ../..
  $ make -j8 install
```
