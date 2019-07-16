#include "TravelCatalog.h"

TravelCatalog::TravelCatalog()
{
}
//
void TravelCatalog::addOffer()
{
	TravelOffer offer;
	std::cin >> offer;
	m_catalog.insert(offer);
}

void TravelCatalog::deleteExpiredOffers()
{
	Date currentDate;
	currentDate.getCurrentDate();
	for (std::set<TravelOffer>::iterator it = m_catalog.begin(); it != m_catalog.end(); ++it)
	{
		TravelOffer currentOffer = *it;
		if (currentDate > currentOffer.getDepartureDate())
		{
			m_catalog.erase(it);
		}
	}
}

void TravelCatalog::displayAll()
{
	for (std::set<TravelOffer>::iterator it = m_catalog.begin(); it != m_catalog.end(); ++it)
	{
		std::cout << *it << "\n";
	}
}


TravelCatalog::~TravelCatalog()
{
}
