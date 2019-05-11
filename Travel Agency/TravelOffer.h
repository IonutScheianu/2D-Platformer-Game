#pragma once
#include"Date.h"
#include<string>
#include<utility>

class TravelOffer
{
private:
	std::string m_type;
	std::pair<std::string, std::string> m_destination;
	Date m_departureDate;
	float m_price;

public:
	TravelOffer();
	TravelOffer(std::string type, std::pair<std::string, std::string> destination, Date departureDate, float price);
	friend std::ostream &operator<<(std::ostream& output, const TravelOffer &offer);
	friend std::istream &operator>>(std::istream& input, TravelOffer &offer);
	void updateAll(std::string type, std::pair<std::string, std::string> destination, Date departureDate, float price);
	bool operator==(const TravelOffer &offer);
	bool operator<(const TravelOffer &offer)const;
	bool operator>(const TravelOffer& offer)const;
	TravelOffer operator=(const TravelOffer& offer);
	bool operator>(const TravelOffer &offer);
	std::string getType();
	std::pair<std::string, std::string> getDestination();
	Date getDepartureDate();
	float getPrice();
	void applyDiscount(float percentage);
	~TravelOffer();
};

