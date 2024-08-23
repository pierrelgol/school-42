/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:47:12 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/21 10:47:13 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

void Harl::no_op(void) {
}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my"
	             "7XL-double-cheese-triple-pickle-special-"
	             "ketchup burger. I really do!"
	          << std::endl;
}
void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money."
	             "You didn’t put enough bacon in my burger! "
	             "If you did, I wouldn’t be asking for more!"
	          << std::endl;
}
void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free."
	             " I’ve been coming for years whereas you started working"
	             "here since last month."
	          << std::endl;
}
void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::toInt(std::string const &level) const {
	if (level == "DEBUG")
		return (DEBUG);
	else if (level == "INFO")
		return (INFO);
	else if (level == "WARNING")
		return (WARNING);
	else if (level == "ERROR")
		return (ERROR);
	else
		return (0);
}

void Harl::complain(std::string level) const {
	const log_fn fn[5] = {no_op, debug, info, warning, error};
	fn[toInt(level)]();
}

Harl::~Harl() {
}
