#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

	void setIdeas(const std::string ideas[100]);
	const std::string* getIdeas(void) const;
	
	void setIdea(const std::string& idea);
	std::string getIdea(size_t index) const;
	void deleteIdea(size_t index);

private:
	std::string ideas[100];
};

#endif

