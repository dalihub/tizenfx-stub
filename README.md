TizenFX Stub
============

Stubs to enable the TizenFX repository to build on Ubuntu

## Install
```sh
$ cmake -DCMAKE_INSTALL_PREFIX=$DESKTOP_PREFIX .
$ make install -j9
```

## Install NUI resources (Optional)
Install
```sh
# usage: ./installFXRes.py [TizenFXDirectory]
$ sudo ./installFXRes.py ../TizenFX
```

Clean
```sh
$ sudo ./installFXRes.py ../TizenFX -c
```


