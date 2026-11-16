#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

std::string bl = "\x1b[94m";
std::string wh = "\x1b[0m";

int WIDTH = 46;

void banner() {
    std::cout << bl << " _______  _____   _____         _______ __   __ _______  _____\n";
    std::cout << " |       |_____] |_____] |      |_____|   |_|   |______ |_____|\n";
    std::cout << " |_____  |       |       |_____ |     |    |    |______ |    |_\n\n";
    std::cout << wh << "                    cpplayer v2.0\n\n";
}

std::string fit(const std::string& s) {
    if (s.size() >= static_cast<size_t>(WIDTH))
        return s.substr(0, WIDTH - 3) + "...";
    return s + std::string(WIDTH - s.size(), ' ');
}

void loadForFile() {
    std::string file;
    std::cout << "Which song do you want to listen to? Write in\n";
    std::getline(std::cin, file);

    sf::Music music;
    if (!music.openFromFile(file)) {
        std::cerr << "Failed to load " << file << std::endl;
        return;
    }

    music.setLooping(false);
    music.setVolume(65.f);
    music.play();

    std::string inner = " Playing: " + file;
    std::cout << "\n╔" << std::string(WIDTH, '=') << "╗\n";
    std::cout << "║" << bl << fit(inner) << wh << "║\n";
    std::cout << "╚" << std::string(WIDTH, '=') << "╝\n" << std::flush;

    while (music.getStatus() == sf::Music::Status::Playing)
        sf::sleep(sf::milliseconds(200));
}

int main() {
    banner();
    loadForFile();
    return 0;
}