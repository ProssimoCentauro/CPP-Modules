#include <iostream>
#include "Serializer.hpp"

int	main()
{
	Data *dataStruct = new Data;
	
	dataStruct->lNum = 782346;
	dataStruct->fNum = 854.231;
	dataStruct->str = "Don't Panic!";

	std::cout << "dataStruct address: " << dataStruct << std::endl;
	std::cout << "dataStruct lNum: " << dataStruct->lNum << std::endl;
	std::cout << "dataStruct fNum: " << dataStruct->fNum << std::endl;
	std::cout << "dataStruct str: " << dataStruct->str << std::endl;
	std::cout << std::endl;

	uintptr_t uInt = Serializer::serialize(dataStruct);

	std::cout << "Serialized uInt: " << uInt << std::endl;
	std::cout << std::endl;

	Data *dataStruct2 = Serializer::deserialize(uInt);

	std::cout << "Deserialized dataStruct address: " << dataStruct2 << std::endl;
	std::cout << "Deserialized dataStruct lNum: " << dataStruct2->lNum << std::endl;
	std::cout << "Deserialized dataStruct fNum: " << dataStruct2->fNum << std::endl;
	std::cout << "Deserialized dataStruct str: " << dataStruct2->str << std::endl;

	delete(dataStruct);

	return 0;
}
