/********************
GNU Radio C++ Flow Graph Source File

Title: pmtscan
GNU Radio version: 3.10.1.1
********************/

#include "pmtscan.hpp"
#include <gnuradio/realtime.h>

using namespace gr;


pmtscan::pmtscan ()  {


    this->tb = gr::make_top_block("pmtscan");

// Blocks:
        this->uhd_usrp_source_0 = gr::uhd::usrp_source::make(
           ::uhd::device_addr_t("type=b200,num_recv_frames=1000,recv_frame_size=16360"),
           ::uhd::stream_args_t("fc32", ""));
        this->uhd_usrp_source_0->set_samp_rate(samp_rate);
        this->uhd_usrp_source_0->set_time_unknown_pps(::uhd::time_spec_t());

        this->uhd_usrp_source_0->set_center_freq(70e6, 0);
        this->uhd_usrp_source_0->set_gain(40, 0);
        this->uhd_usrp_source_0->set_antenna("TX/RX", 0);

        this->habets39_sweepsinkv_0 = gr::habets39::sweepsinkv::make('rx_freq', points, samp_rate, freq_start, freq_end, tune_step_hz, tune_step_fft);

        this->fft_vxx_0 = fft::fft_vcc::make(points, true, fft::window::blackmanharris(points), true, 1);

        this->blocks_stream_to_vector_0 = blocks::stream_to_vector::make(sizeof(gr_complex)*1, points);

        this->blocks_file_sink_0 = blocks::file_sink::make(sizeof(char)*1, 'test.tsv', false);

        this->blocks_complex_to_mag_0 = blocks::complex_to_mag::make(points);


// Connections:
    this->tb->hier_block2::msg_connect(this->habets39_sweepsinkv_0, "tune", this->uhd_usrp_source_0, "command");
    this->tb->hier_block2::connect(this->blocks_complex_to_mag_0, 0, this->habets39_sweepsinkv_0, 0);
    this->tb->hier_block2::connect(this->blocks_stream_to_vector_0, 0, this->fft_vxx_0, 0);
    this->tb->hier_block2::connect(this->fft_vxx_0, 0, this->blocks_complex_to_mag_0, 0);
    this->tb->hier_block2::connect(this->habets39_sweepsinkv_0, 0, this->blocks_file_sink_0, 0);
    this->tb->hier_block2::connect(this->uhd_usrp_source_0, 0, this->blocks_stream_to_vector_0, 0);
}

pmtscan::~pmtscan () {
}

// Callbacks:
double pmtscan::get_samp_rate () const {
    return this->samp_rate;
}

void pmtscan::set_samp_rate (double samp_rate) {
    this->samp_rate = samp_rate;
    this->set_tune_step_hz(int(this->samp_rate / 2));
    this->uhd_usrp_source_0->set_samp_rate(this->samp_rate);
}

int pmtscan::get_tune_step_hz () const {
    return this->tune_step_hz;
}

void pmtscan::set_tune_step_hz (int tune_step_hz) {
    this->tune_step_hz = tune_step_hz;
}

int pmtscan::get_tune_step_fft () const {
    return this->tune_step_fft;
}

void pmtscan::set_tune_step_fft (int tune_step_fft) {
    this->tune_step_fft = tune_step_fft;
}

int pmtscan::get_points () const {
    return this->points;
}

void pmtscan::set_points (int points) {
    this->points = points;
}

double pmtscan::get_freq_start () const {
    return this->freq_start;
}

void pmtscan::set_freq_start (double freq_start) {
    this->freq_start = freq_start;
}

double pmtscan::get_freq_end () const {
    return this->freq_end;
}

void pmtscan::set_freq_end (double freq_end) {
    this->freq_end = freq_end;
}


int main (int argc, char **argv) {
    if (enable_realtime_scheduling() != RT_OK) {
        std::cout << "Error: failed to enable real-time scheduling." << std::endl;
    }

    pmtscan* top_block = new pmtscan();
    top_block->tb->start();
    std::cout << "Press Enter to quit: ";
    std::cin.ignore();
    top_block->tb->stop();
    top_block->tb->wait();

    return 0;
}
