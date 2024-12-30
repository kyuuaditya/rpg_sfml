#include "Stats.h"
#include <iostream>

void Stats::Initialize() {
}

void Stats::Load() { // load font
    if (font.loadFromFile("assets/fonts/Alef-Regular.ttf")) {
        std::cout << "font loaded" << std::endl;
        frameRate.setFont(font);
    }
    else {
        std::cout << "font not loaded" << std::endl;
    }
    frameRate.setPosition(x, y);
}


void Stats::Update() { // update average frame rate
    sf::Time deltaTimeTimer = clock.restart();
    deltaTime = deltaTimeTimer.asMicroseconds() / 1000;

    deltaTimeGap += deltaTime;
    nFrames += 1;

    if (deltaTimeGap >= updateTime) { // update the average frame rate
        std::string frameRateText = "fps: " + std::to_string(nFrames * 1000 / updateTime) + " frame time: " + std::to_string(deltaTimeGap / (nFrames));
        frameRate.setString(frameRateText);
        nFrames = 0;
        deltaTimeGap = 0;
    }
}

void Stats::Draw(sf::RenderWindow& window) {
    window.draw(frameRate); // draw frame rate
}
