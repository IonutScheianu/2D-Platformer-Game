#include "TravelOffer.h"
#include<algorithm>

TravelOffer::TravelOffer()
{
	m_type = "";
	m_destination.first = "";
	m_destination.second = "";
	m_departureDate.updateAll(NULL, NULL, NULL);
	m_price = NULL;
}

TravelOffer::TravelOffer(std::string type, std::pair<std::string, std::string> destination, Date departureDate, float price)
{
	m_type = type;
	m_destination = destination;
	m_departureDate = departureDate;
	m_price = price;
}

TravelOffer::~TravelOffer()
{
}

void TravelOffer::updateAll(std::string type, std::pair<std::string, std::string> destination, Date departureDate, float price)
{
	m_type = type;
	m_destination = destination;
	m_departureDate = departureDate;
	m_price = price;
}

bool TravelOffer::operator==(const TravelOffer &offer)
{
	if (m_type == offer.m_type && m_destination == offer.m_destination && m_departureDate == offer.m_departureDate && m_price == offer.m_price)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool TravelOffer::operator<(const TravelOffer &offer) const
{
	return(m_departureDate < offer.m_departureDate);
}

bool TravelOffer::operator>(const TravelOffer& offer) const
{
	return(m_departureDate > offer.m_departureDate);
}

TravelOffer TravelOffer::operator=(const TravelOffer& offer)
{
	m_type = offer.m_type;
	m_destination = offer.m_destination;
	m_departureDate = offer.m_departureDate;
	m_price = offer.m_price;
	return *this;
}


bool TravelOffer::operator>(const TravelOffer &offer)
{
	return(m_departureDate > offer.m_departureDate);
}

std::string TravelOffer::getType()
{
	return m_type;
}

std::pair<std::string, std::string> TravelOffer::getDestination()
{
	return m_destination;
}

Date TravelOffer::getDepartureDate()
{
	return m_departureDate;
}

float TravelOffer::getPrice()
{
	return m_price;
}

void TravelOffer::applyDiscount(float percentage)
{
	if (percentage >= 100)
	{
		throw "Percentage greater thean 100";
	}
	m_price = m_price - (m_price * percentage / 100);
}

std::ostream &operator<<(std::ostream &output, const TravelOffer &offer)
{
	output << "Travel Offer:\n" << "-Type: " << offer.m_type << "\n-Destination: " << offer.m_destination.first << ", " << offer.m_destination.second << "\n-Departure Date: " << offer.m_departureDate << "\n-Price: " << offer.m_price << " euro\n";
	return output;
}

std::istream &operator>>(std::istream &input, TravelOffer &offer)
{
	std::cout << "Adding a new offer:\n";
	std::cout << "Type: ";
	input >> offer.m_type;
	std::cout << "Country: ";
	input >> offer.m_destination.first;
	std::cout << "City: ";
	input >> offer.m_destination.second;
	std::cout << "Departure date: ";
	input >> offer.m_departureDate;
	std::cout << "Price: ";
	input >> offer.m_price;
	std::cout << std::endl;
	
	return input;
}

