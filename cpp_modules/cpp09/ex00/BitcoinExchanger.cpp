/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchanger.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:27:41 by riccardobor       #+#    #+#             */
/*   Updated: 2023/11/13 11:40:24 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchanger.hpp"

BitcoinExchanger::BitcoinExchanger(void)
{
	this->generateExchanger();
}

BitcoinExchanger::~BitcoinExchanger()
{
	;
}

BitcoinExchanger::BitcoinExchanger(const BitcoinExchanger &toCopy)
{
	this->moltiplier = toCopy.moltiplier;
}

std::map<std::string, float> BitcoinExchanger::getMap()
{
	return (this->moltiplier);
}

float BitcoinExchanger::getValue(std::string date)
{
	this->moltiplier.find(date);
	return (this->moltiplier[date]);
}

BitcoinExchanger	&BitcoinExchanger::operator=(const BitcoinExchanger &toCopy)
{
	this->moltiplier = toCopy.moltiplier;
	return (*this);
}

void	BitcoinExchanger::generateExchanger(void)
{
	std::ifstream	file;
    std::string		line;
    std::string		date;
    float			value;

	file.open("data.csv");
    getline(file, line, '\n');
    while (std::getline(file, line))
    {
        date = line.substr(0, 10);
        size_t find = line.find(',') + 1;
        sscanf(line.c_str() + find, "%f", &value);
        this->moltiplier[date] = value;
    }
    file.close();
}

static void	findCloserDate(std::pair <std::string, float> p, std::map<std::string, float> moltiplier)
{
	int diff = INT_MAX;
	int _year = atoi(p.first.substr(0,4).c_str());
	int _month = atoi(p.first.substr(5,7).c_str());
	int _day = atoi(p.first.substr(8, 10).c_str());
	int _data = (_year*10000) + (_month*100) + _day;
	for (std::map<std::string, float>::iterator it = moltiplier.begin(); it != moltiplier.end(); it++)
	{
		int n_year = atoi(it->first.substr(0,4).c_str());
		int n_month = atoi(it->first.substr(5,7).c_str());
		int n_day = atoi(it->first.substr(8, 10).c_str());
		int n_data = (n_year*10000) + (n_month*100) + n_day;
		if ((_data - n_data) > 0 && (_data - n_data)<diff)
			diff = _data - n_data;
		if (_data - n_data < 0)
		{
			std::map<std::string, float>::iterator it2 = it--;
			std::cout << p.first << " => " << p.second << " = " << (it2->second * p.second) << std::endl;
			return;
		}
	}
}

void	BitcoinExchanger::checker(std::map<std::string, float> toCheck)
{
    std::map<std::string, float>::iterator i;
	for (std::map<std::string, float>::iterator i = toCheck.begin();
		i != toCheck.end(); i++)
	{
		try{
			std::string month = i->first.substr(i->first.find('-') + 1, i->first.find_last_of('-') -1);
			std::string day = i->first.substr(i->first.find_last_of('-') +1, i->first.npos);
			if ((month < "0" || month > "12") || (day < "0" || day > "31"))
			{
				throw badInputException();
			}
		}
		catch(badInputException &e){
			std::cerr << e.what() << " => " << i->first << std::endl;
			continue;
		}
		for (std::map<std::string, float>::iterator j = this->moltiplier.begin();
			1; j++)
		{
			if (i->first == j->first)
			{
				try{
					if (i->second >= 0 && i->second <= 1000)
					{
		            	std::cout << i->first << " => " << i->second << " = " << (i->second * j->second) << std::endl;
						break ;	
					}
					else if (i->second < 0)
						throw badValueExecption(0);
					else if (i->second > 1000)
						throw badValueExecption(1);
				}
				catch (badValueExecption &e)
				{
					std::cerr << e.what() << std::endl;
					continue;
				}
			}
			else if (j == this->moltiplier.end())
			{
				std::pair <std::string, float> p(i->first, i->second);
				findCloserDate(p, this->moltiplier);
				break;
			}	
		}
	}
}

