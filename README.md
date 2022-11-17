### Building

Tested on Ubuntu 22.04.1, stock gnuradio 3.10.1.1/(Python 3.10.6).

gnuradio-companion generates incorrect C++ code (incorrect char const, etc),
so to tune edit pmtscan.hpp and recompile.

```
$ sudo apt-get install gnuradio-dev
$ git clone https://github.com/anarkiwi/gr-habets39 -b st3
$ cd gr-habets39 && mkdir build && cd build && cmake .. && make && sudo make install && sudo ldconfig && cd ../..
$ mkdir pmtscan/build && cd pmtscan/build && cmake .. && make
$ ./pmtscan
```
