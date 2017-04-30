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
	std::string caso;
	std::string numero;
	std::vector<std::string> lista{"air", "fire", "earth", "water"};

	
	
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
		//meter los datos en el mapa
		key.first = elem1;
		key.second = elem2;
		mymap[key] = result;
		
	};

	std::cin >> caso;

	if (caso == "add")
	{
		std::cin >> numero;
		for (int i = 0; i < lista.size(); i++)
		{

			if (i == numero)
			{
				lista.insert(lista);
			}
		}
	}
	else if (caso == "add basics")
	{
		
	}
	else if (caso == "delete")
	{

	}
	else if (caso == "info")
	{

	}
	else if (caso == "sort")
	{

	}
	else if (caso == "clean")
	{

	}
	else if (caso == "help")
	{

	}
}