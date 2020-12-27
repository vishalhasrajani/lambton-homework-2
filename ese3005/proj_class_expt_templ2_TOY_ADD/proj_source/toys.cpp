

#include <toys.h>
#include <iostream>
#include <string>
#include <vector>

// Toy constructor, initializes the object
Toy::Toy(void)
{
}

// Toy::end() method
bool Toy::end()
{
	if (data.manuf_date == END_MARKER)
	{
		return true;
	}
	return false;
}

// Toy::get() method, populates the data record from standard input
int Toy::get(void)
{
	long Nc=3; // stores the number of categories

	// get the Toy manufacturing date
	std::cin >> data.manuf_date;

	// get the price
	std::cin >> data.price;

	// get the toy name
	std::cin >> data.toy_name;



	// get the categories and ratings
	std::string cat_name;
	for (long j = 0; j != Nc; ++j)
	{
		std::cin >> cat_name;
		Toy::data.category.push_back(cat_name);
	}
	double rating;
	for (long j = 0; j != Nc; ++j)
	{
		std::cin >> rating;
		data.ratings.push_back(rating);
	}

	std::cin >> data.room;
	// generate a unique key
	data.key = keygen(data.manuf_date, data.toy_name);

	return 0; // in the future, can add error checking
}

// Toy::put() method, sends data contents to standard output
void Toy::put(void) const
{
	long Nc = 3;

	// put key
	std::cout << "key: " << data.key << std::endl;

	// put the Manufacturing date
	std::cout << "Manufacture-Date: " << data.manuf_date << std::endl;

	// put the price
	std::cout << "price: " << data.price << std::endl;

	// put the Toy name
	std::cout << "Toy name: " << data.toy_name << std::endl;

	// put categories and ratings
	std::string cat_name;
	double rating;
	for (long j = 0; j != Nc; ++j)
	{
		cat_name = data.category[j];
		rating = data.ratings[j];
		std::cout << "\t" << cat_name << ":\t" << rating << std::endl;
	}
	// put Room for the toy
	std::cout << "Room: " << data.room << std::endl;
	// line spacing
	std::cout << std::endl << std::endl;
}

// Toy::keygen() method
std::string Toy::keygen(std::string A, std::string B)
{
	std::string ret = A + "_" + B;

	return ret;
}

