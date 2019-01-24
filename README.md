# KappaDBMS

[![Build Status](https://travis-ci.org/KappaTych/KappaDBMS.svg?branch=develop)](https://travis-ci.org/KappaTych/KappaDBMS)
[![Coverage Status](https://coveralls.io/repos/github/KappaTych/KappaDBMS/badge.svg?branch=develop)](https://coveralls.io/github/KappaTych/KappaDBMS?branch=develop)

Main tasks:
- Multiple users
- SQLite based SQL-syntax
- Server / Client architecture (decentralized in future)
- Storage implements Bw-Tree for indexes
- Custom programming languages support (for writing internal procedures)

Installation
------------

Download project using `git`, download required dependencies:
```sh
$ git clone https://github.com/KappaTych/KappaDBMS.git
$ cd KappaDBMS
$ git submodule update --init --recursive
```

First of all you must generate flex-bison files (for that you must have flex/bison installation on your machine):
```sh
$ make -C src/parser/flex-bison
```

After that you can build whole project via cmake:
```sh
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
```

Running
-------

```sh
$ cd build && make kappa
$ ./bin/kappa --help
Server Application for Kappa Database Management System
Usage:
  bin/kappa [OPTION...]

  -h, --help       Show help
  -s, --size INT   Set size of buffer per client (default: 4096)
  -p, --port PORT  Set server port (default: 12564)
```

Dependencies
------------

* bison v3.2
* flex v2.6.4
* [nlohmann/json](https://github.com/nlohmann/json)
* [nlohmann/fifo_map](https://github.com/nlohmann/fifo_map)
* [jarro2783/cxxopts](https://github.com/jarro2783/cxxopts)
* [DFHack/clsocket](https://github.com/DFHack/clsocket)
* [vit-vit/CTPL](https://github.com/vit-vit/CTPL)
* [cginternals/cppfs](https://github.com/cginternals/cppfs)

For building tests we use [google/googletest](https://github.com/google/googletest)

Authors
-------
+ [Anastasia P.](https://github.com/pototckaia)
+ [Anton Podchuvalov](https://github.com/tonichoff)
+ [nixtaxe](https://github.com/nixtaxe)
+ [GlushkovVK](https://github.com/TrueFinch)
+ [QuickSilver](https://github.com/abelidze)


License
-------
KappaDBMS is open-sourced software licensed under the [Apache-2.0 License](https://opensource.org/licenses/Apache-2.0).

#### Disclaimer

This program is provided "AS IS" without warranty of any kind.