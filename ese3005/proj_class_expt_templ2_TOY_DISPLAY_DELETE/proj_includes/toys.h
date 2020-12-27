

#ifndef TOYS_H_
#define TOYS_H_

#define END_MARKER "-9999"

//#include <iostream>
#include <string>
#include <vector>

typedef struct
{
	std::string key; // primary key
	std::string manuf_date;
	float price;
	std::string toy_name;
	std::vector<std::string> category;
	std::vector<double> ratings;
	std::string room;
} record_t;

/*
 * this defines a Toy object
 */
class Toy
{
public:
	Toy(void); // constructor
	// data of a Toy
	record_t data;
	int get(); // get the data from standard input and keygen();
	void put() const; // send the record to standard output;
	bool end(); // checks if toy record is the last one, updates last_record

private:
	std::string keygen(std::string, std::string);
};

#endif /* TOYS_H_ */
