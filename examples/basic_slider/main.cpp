#include "SimpleUI/Widgets/Slider.h"
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>

static std::string formatValue(float value)
{
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(2) << value;
	return stream.str();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode({620, 260}), "SimpleUI - basic slider");
	window.setFramerateLimit(60);

	sf::Font font("/System/Library/Fonts/Helvetica.ttc");
	Theme::get().font = &font;

	Slider<float> slider(0.f, 1.f, 0.05f, {80.f, 110.f}, {460.f, 40.f}, 0.10f);
	slider.color(sf::Color(70, 130, 180))
		  .trackColor(sf::Color(210, 214, 220))
		  .knobColor(sf::Color(100, 160, 210))
		  .onChange([](float value) {
			  std::cout << "Slider value: " << formatValue(value) << std::endl;
		  });

	sf::Text title(font);
	title.setCharacterSize(18);
	title.setFillColor(sf::Color(35, 35, 35));
	title.setString("Slider<float>(0.0, 1.0, 0.05)");

	sf::Text hint(font);
	hint.setCharacterSize(14);
	hint.setFillColor(sf::Color(120, 120, 120));
	hint.setString("Rozsah 0..1, krok 1/20 = 0.05, klikni alebo tahaj mysou");

	sf::Text valueText(font);
	valueText.setCharacterSize(38);
	valueText.setFillColor(sf::Color(35, 35, 35));

	sf::Text consoleText(font);
	consoleText.setCharacterSize(14);
	consoleText.setFillColor(sf::Color(120, 120, 120));
	consoleText.setString("Kazda zmena sa vypise aj do konzoly");

	std::cout << "Slider value: " << formatValue(slider.getValue()) << std::endl;

	sf::Clock clock;

	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();

		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();

			slider.handleEvent(*event);
		}

		slider.update(dt);

		valueText.setString(formatValue(slider.getValue()));

		auto valueBounds = valueText.getLocalBounds();
		valueText.setOrigin(valueBounds.position + valueBounds.size / 2.f);
		valueText.setPosition({310.f, 62.f});

		title.setPosition({80.f, 28.f});
		hint.setPosition({80.f, 70.f});
		consoleText.setPosition({80.f, 180.f});

		window.clear(sf::Color(245, 245, 245));
		window.draw(title);
		window.draw(hint);
		slider.draw(window);
		window.draw(valueText);
		window.draw(consoleText);
		window.display();
	}

	return 0;
}
