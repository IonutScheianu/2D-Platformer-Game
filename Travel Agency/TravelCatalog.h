#pragma once
#include"TravelOffer.h"
#include<set>
class TravelCatalog
{
private:
	std::set<TravelOffer>m_catalog;
public:
	TravelCatalog();
	void addOffer();
	void deleteExpiredOffers();
	void displayAll();
	~TravelCatalog();
};

