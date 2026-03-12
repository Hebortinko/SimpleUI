#include "SimpleUI/Widgets/Button.h"
#include "SimpleUI/Style/Presets.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({500, 300}), "SimpleUI - basic button");
    window.setFramerateLimit(60);

    sf::Font font("/System/Library/Fonts/Helvetica.ttc");
    Theme::get().font = &font;

    Button btnPlus ("+",     {0.f, 0.f}, {50.f, 40.f});
    Button btnMinus("-",     {0.f, 0.f}, {50.f, 40.f});
    Button btnReset("Reset", {0.f, 0.f}, {70.f, 40.f});

    btnPlus .style(Presets::Success());
    btnMinus.style(Presets::Danger());
    btnReset.style(Presets::Ghost());

    int counter = 0;
    btnPlus .onClick([&counter] { counter++; });
    btnMinus.onClick([&counter] { counter--; });
    btnReset.onClick([&counter] { counter = 0; });

    sf::Text counterText(font);
    counterText.setCharacterSize(48);
    counterText.setFillColor(sf::Color(30, 30, 30));

    sf::Text labelText(font);
    labelText.setCharacterSize(13);
    labelText.setFillColor(sf::Color(150, 150, 150));
    labelText.setString("click the buttons");

    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) window.close();
            btnPlus .handleEvent(*event);
            btnMinus.handleEvent(*event);
            btnReset.handleEvent(*event);
        }

        btnPlus .update(dt);
        btnMinus.update(dt);
        btnReset.update(dt);

        float W = window.getSize().x;
        float H = window.getSize().y;

        
        counterText.setString(std::to_string(counter));
        auto cb = counterText.getLocalBounds();
        counterText.setOrigin(cb.position + cb.size / 2.f);
        counterText.setPosition({W / 2.f, H / 2.f - 20.f});

        
        auto lb = labelText.getLocalBounds();
        labelText.setOrigin(lb.position + lb.size / 2.f);
        labelText.setPosition({W / 2.f, H / 2.f + 40.f});

        
        float totalW = 50.f + 10.f + 50.f + 10.f + 70.f;
        float startX = (W - totalW) / 2.f;
        float btnY   = 30.f;
        btnMinus.setPosition({startX,               btnY});
        btnPlus .setPosition({startX + 60.f,        btnY});
        btnReset.setPosition({startX + 120.f,       btnY});

        window.clear(sf::Color(245, 245, 245));
        btnMinus.draw(window);
        btnPlus .draw(window);
        btnReset.draw(window);
        window.draw(counterText);
        window.draw(labelText);
        window.display();
    }
}