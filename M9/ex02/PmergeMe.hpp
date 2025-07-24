/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:03:58 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/24 12:12:42 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <stdexcept>
# include <iterator>
# include <sstream>
# include <string>
# include <limits>
# include <cstdlib>
# include <cctype>
# include <iomanip>
# include <functional>
# include <ctime>
# include <iterator>
# include <numeric>
# include <cmath>
# include <string>

class PmergeMe {
public:

PmergeMe(const std::vector<unsigned int>& vec, const std::deque<unsigned int>& deq);
~PmergeMe();

void process();

private:

double _time;
clock_t _start;
clock_t _end;

std::vector<unsigned int> _vec;
std::deque<unsigned int>  _deq;

void sort(std::vector<unsigned int>& arr);
void sort(std::deque<unsigned int>& arr);

PmergeMe();
PmergeMe(const PmergeMe& other);
PmergeMe& operator=(const PmergeMe& other);

};

// ----------------------------- OUTILS GLOBAUX ----------------------------- //

template <typename Container>
bool isSorted(const Container& cont);

template <typename Container>
void display(const Container& cont);

std::vector<unsigned int> getJacobsthalIndexes(unsigned int size);

void parseInput(int argc, char **argv);


#endif