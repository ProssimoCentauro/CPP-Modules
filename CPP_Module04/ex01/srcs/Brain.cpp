#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = "";
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdeas(const std::string ideas[100]) {
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = ideas[i];
}

const std::string* Brain::getIdeas(void) const {
	return this->ideas;
}

void Brain::setIdea(const std::string& idea) {
	for (int i = 0; i < 100; ++i) {
		if (this->ideas[i].empty()) {
			this->ideas[i] = idea;
			return;
		}
	}
	std::cout << "No space left in brain for new ideas!" << std::endl;
}

std::string Brain::getIdea(size_t index) const {
	if (index < 100)
		return this->ideas[index];
	else
		return "";
}

void Brain::deleteIdea(size_t index) {
	if (index < 100)
		this->ideas[index] = "";
}
