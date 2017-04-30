#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
template<>
struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(const std::pair<std::string, std::string> &p) const
	{

		return ((hash<std::string>()(p.first)
			^ (hash<std::string>()(p.second) << 1)) >> 1);
		}
};


void main() {
	std::ifstream fentrada("elements.dat");
	std::unordered_map<std::pair<std::string, std::string>, std::string> mymap;
	std::string line, result, elem1, elem2;
	int pos1, pos2, pos3, end;
	int res1, res2, res3;

	
	
	while (getline(fentrada, line)) {
		std::pair<std::string, std::string> key;
		std::cout << line << std::endl;
		//encontrar signos
		pos1 = 0;
		pos2 = line.find("=");
		pos3 = line.find("+");
		end = line.find("\n");
		//operaciones para que cree el substr
		res1 = pos2 - pos1 - 1;
		res2 = (pos3 - 1) - (pos2 + 1);
		res3 = end - (pos3 + 1);
		//leer los elementos y almacenarlos en strings
		result = line.substr(pos1, res1);
		elem1 = line.substr(pos2 + 2, res2);
		elem2 = line.substr(pos3 + 2, res3);

		key.first = elem1;
		key.second = elem2;
		mymap[key] = result;
		
	};


}