# GNU Radio C++ Flow Graph CMakeLists.txt
#
# Title: pmtscan
# GNU Radio version: 3.10.1.1


cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 14)

project(pmtscan)

find_package(Gnuradio "3.10" COMPONENTS
    blocks
    fec
    fft
    filter
    analog
    digital
    dtv
    audio
    channels
    pdu
    iio
    qtgui
    trellis
    uhd
    uhd UHD 4.0 RFNoC
    video-sdl
    vocoder
    wavelet
    zeromq
    network
    soapy
)




add_executable(pmtscan pmtscan.cpp)
target_link_libraries(pmtscan
    gnuradio::gnuradio-blocks
    gnuradio-uhd uhd
    gnuradio::gnuradio-fft

)

