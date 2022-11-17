#ifndef PMTSCAN_HPP
#define PMTSCAN_HPP
/********************
GNU Radio C++ Flow Graph Header File

Title: pmtscan
GNU Radio version: 3.10.1.1
********************/

/********************
** Create includes
********************/
#include <gnuradio/top_block.h>
#include <gnuradio/blocks/complex_to_mag.h>
#include <gnuradio/blocks/file_sink.h>
#include <gnuradio/blocks/stream_to_vector.h>
#include <gnuradio/fft/fft.h>
#include <gnuradio/fft/fft_v.h>
#include <gnuradio/fft/window.h>
#include <habets39/sweepsinkv.h>
#include <gnuradio/uhd/usrp_source.h>



using namespace gr;



class pmtscan {

private:


    gr::uhd::usrp_source::sptr uhd_usrp_source_0;
    gr::habets39::sweepsinkv::sptr habets39_sweepsinkv_0;
    fft::fft_v<gr_complex, true>::sptr fft_vxx_0;
    blocks::stream_to_vector::sptr blocks_stream_to_vector_0;
    blocks::file_sink::sptr blocks_file_sink_0;
    blocks::complex_to_mag::sptr blocks_complex_to_mag_0;


// Variables:
    double samp_rate = 8.192e6;
    int tune_step_hz = int(samp_rate / 2);
    int tune_step_fft = 32;
    int points = 1024;
    double freq_start = 70e6;
    double freq_end = 6e9;

public:
    top_block_sptr tb;
    pmtscan();
    ~pmtscan();

    double get_samp_rate () const;
    void set_samp_rate(double samp_rate);
    int get_tune_step_hz () const;
    void set_tune_step_hz(int tune_step_hz);
    int get_tune_step_fft () const;
    void set_tune_step_fft(int tune_step_fft);
    int get_points () const;
    void set_points(int points);
    double get_freq_start () const;
    void set_freq_start(double freq_start);
    double get_freq_end () const;
    void set_freq_end(double freq_end);

};


#endif

