// Use: 
// Set diffusor_time_scaler and diffusor_skew in Diffusor.h
// Compile with: g++ -std=c++17 -g diff_test_main.cpp -o diffusor_test
// Run: ./diffusor_test



#include <iostream>
#include <vector>
#include <fstream>
#include "ReverbEngine.h"


int main(){
    const int fs=48000;
    const int N = fs;

    ReverbEngine<float> reverbEngine;

// USER PARAMETERS::::::::::::::::::::::



    
// Impulse for test
    std::vector<std::array<float,2>> impulse(N, std::array<float, 2>{0.0f, 0.0f});
    std::vector<std::array<float,2>> output(N, std::array<float, 2>{0.0f, 0.0f});
    impulse[0][0] = 1.0f;
    impulse[0][1] = 1.0f;
    for (int i=0; i<N; i++){
        output[i] = reverbEngine.process(impulse[i]);
    }
    #ifdef DIF_TEST
    reverbEngine.exportAllTestOutputs();
    #endif
    return 0;
}
// OBS: Retur er stereo-sumeret. Dvs der bliver en masse udfasning så plot ikke ligner matlab.
// Skal der udskrives filer inde fra Diffusor eller returneres 8 kanaler
// i en modificering af ReverbEnging.process() til testen?