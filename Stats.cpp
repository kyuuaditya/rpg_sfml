#include "Stats.h"
#include <iostream>

void Stats::Initialize() {
}

void Stats::Load() {
    if (font.loadFromFile("assets/fonts/Alef-Regular.ttf")){
        std::cout<<"font loaded"<<std::endl;
        frameRate.setFont(font);
    }else {
        std::cout<<"font not loaded"<<std::endl;
    }
    frameRate.setPosition(10, 10);
}

void Stats::Update() {
        sf::Time deltaTimeTimer =  clock.restart();
        sf::Time deltaTimeTimer2 =  clock2.getElapsedTime();

        deltaTime = deltaTimeTimer.asMilliseconds();
        float deltaTimem= deltaTimeTimer.asMicroseconds();
        float deltaTime2 = deltaTimeTimer2.asMilliseconds();

        // frameRateSmooth += (double)1000000/ deltaTimem;
        deltaTimeSmooth += deltaTimem;
        
        nFrames+=1;

        if (deltaTime2 >= 1000){
            clock2.restart();
            std::string frameRateText="fps: " + std::to_string((nFrames*1000000)/deltaTimeSmooth) + " frame time: " +std::to_string(deltaTimeSmooth/(1000*nFrames));
            // std::cout<<nFrames<<std::endl;
            // std::cout<<frameRateSmooth/nFrames<<std::endl;
            frameRate.setString(frameRateText);
            // frameRateSmooth = 0;
            deltaTimeSmooth =0;
            nFrames =0;
        }
}

void Stats::Draw(sf::RenderWindow& window) {
    window.draw(frameRate);
}
