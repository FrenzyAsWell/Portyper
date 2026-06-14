#include <ftxui/component/component_options.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>

#include <string>

namespace ui = ftxui;

ui::Decorator alpha_color = ui::bgcolor(ftxui::Color::RGBA(0, 0, 0, 0));

int main (int argc, char *argv[]) {
	std::string content;

	ui::InputOption input_style = ui::InputOption::Spacious();
	input_style.transform = [](ui::InputState _state) {
		if (_state.focused)
			_state.element |= alpha_color;
		else
			_state.element |= alpha_color;

		return _state.element;
	};

	ui::Component entInput = ui::Input(&content, "Input Component", input_style);

	ui::Component entRenderer = ui::Renderer(entInput, [&]{
		return ui::vbox({
			ui::text("Portyper init."),
			ui::separator(),
			entInput->Render() | ui::flex,
		}) | ui::border;
	});

	ui::ScreenInteractive entScreen = ui::ScreenInteractive::Fullscreen();
	entScreen.Loop(entRenderer);

	return 0;
}
