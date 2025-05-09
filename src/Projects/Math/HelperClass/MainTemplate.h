#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>

#define TEXT_POSITION_INIT float g_TextPosition = 0.0f;
#define TEXT_POSITION_RESET g_TextPosition = 0.0f;

// NOTE: You have access to:
// sf::RenderWindow window
// sf::Text infoText
//  float g_TextPosition

// Create window and text without starting the game loop
#define MAIN_TEMPLATE_GAME_START                                                                                                                                                   \
    int main()                                                                                                                                                                     \
    {                                                                                                                                                                              \
        sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dot Product - Front/Behind Example");                                                                                  \
        window.setFramerateLimit(170);                                                                                                                                             \
        TEXT_POSITION_INIT                                                                                                                                                         \
        sf::Text infoText = Object::CreateText("", (std::filesystem::current_path().parent_path() / "SegoeUI.ttf").string(), 16, sf::Color::White);

// Start the game loop
#define GAME_LOOP_START                                                                                                                                                            \
    while (window.isOpen())                                                                                                                                                        \
    {                                                                                                                                                                              \
        window.clear(sf::Color(30, 30, 30));                                                                                                                                       \
        sf::Event evt{};                                                                                                                                                           \
        while (window.pollEvent(evt))                                                                                                                                              \
            if (evt.type == sf::Event::Closed)                                                                                                                                     \
                window.close();                                                                                                                                                    \
        TEXT_POSITION_RESET

// Finish the while loop and stop the execution
#define MAIN_TEMPLATE_GAME_END                                                                                                                                                     \
    window.display();                                                                                                                                                              \
    }                                                                                                                                                                              \
    return 0;                                                                                                                                                                      \
    }

// For backwards compatibility - includes both initialization and loop start
#define LEGACY_MAIN_TEMPLATE_GAME_START                                                                                                                                            \
    MAIN_TEMPLATE_GAME_START                                                                                                                                                       \
    GAME_LOOP_START

#define DISPLAY_TEXT(message)                                                                                                                                                      \
    infoText.setPosition(0.f, g_TextPosition);                                                                                                                                     \
    infoText.setString(message);                                                                                                                                                   \
    window.draw(infoText);                                                                                                                                                         \
    g_TextPosition += 20.f;