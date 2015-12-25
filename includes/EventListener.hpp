class EventListener
{
	private:
		static void	keyboardEvent(sf::Event event);
		static void	mouseEvent(sf::Event event);
		static void	wheelEvent(sf::Event event);

	public:
		static void	checkEvents(sf::Window &window);
};
