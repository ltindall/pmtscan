### Building

Tested on Ubuntu 22.04.1, stock gnuradio 3.10.1.1/(Python 3.10.6).

gnuradio-companion generates incorrect C++ code (incorrect char const, etc),
so to tune edit pmtscan.hpp and recompile.

```
$ conda activate airstack
$ sudo apt-get install gnuradio-dev
$ sudo apt install liblog4cpp5-dev
$ sudo apt install libsndfile1-dev
$ sudo apt install libfftw3-dev
$ sudo apt install libuhd-dev
$ # edith with https://github.com/gnuradio/gnuradio/pull/5256/files
$ conda install pybind11 -c conda-forge
$ git clone https://github.com/anarkiwi/gr-habets39 -b st3
$ cd gr-habets39 && mkdir build && cd build && cmake .. && make && sudo make install && sudo ldconfig && cd ../..
$ mkdir pmtscan/build && cd pmtscan/build && cmake .. && make
$ ./pmtscan
```
