/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:37:10 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/26 17:48:02 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span(unsigned int N): _maxSize(N), _span(){
	_span.reserve(N);
}

Span::Span(const Span &src): _span(src._span){}

Span::~Span(){}

Span&	Span::operator=(const Span &rhs){
	if (this != &rhs)
	{
		_span = rhs._span;
	}
	return (*this);
}

void	Span::addNumber(int N){
	if (_span.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_span.push_back(N);
}

int	Span::shortestSpan(){
    if (_span.size() < 2){
        throw std::runtime_error("Not enough elements for a span");
	}

	std::vector<int> sorted = this->_span;
	std::sort(sorted.begin(), sorted.end());
	int	minSpan = INT_MAX;

	for (std::vector<int>::const_iterator it = sorted.begin(); it + 1 != sorted.end(); ++it) {
		int diff = *(it + 1) - *it;
		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

int Span::longestSpan(){
    if (_span.size() < 2)
        throw std::runtime_error("Not enough elements for a span");

    std::vector<int> sorted = _span;
    std::sort(sorted.begin(), sorted.end());

    return sorted.back() - sorted.front();
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	for (; begin != end; begin++) {
		if (_span.size() >= _maxSize)
			throw std::runtime_error("Span is full");
		_span.push_back(*begin);
	}
}

void	Span::displaySpan() {
	if (_span.empty()) {
		std::cout << "Span is empty." << std::endl;
		return ;
	}
	std::vector<int>::iterator begin = _span.begin();
	std::vector<int>::iterator end = _span.end();

	for (; begin != end ; ++begin)
		std::cout << *begin
	<< std::endl;
	return ;
}
