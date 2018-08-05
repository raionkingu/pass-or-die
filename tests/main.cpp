#include "../include/die!hpp"

#include <stdexcept>

int main()
{
	die::Framework tests("hello kitty", "Testing the powers of Hello Kitty!");
	tests.displayGreetings();

	tests.addShouldNotPanic("smart kitty", []() {
			int i = 0;
			++i;
			die::assert_eq(i, 1);
		});
	tests.addShouldPanic("kitty panic", []() {
			int i = 0;
			++i;
			die::assert_ne(i, 1);
		});
	tests.addShouldThrow("kitty throws up", std::runtime_error("burps"), "std::runtime_error", []() {
			throw std::runtime_error("burps");
		});

	tests.exec();
	tests.displaySummary();

	return 0;
}
