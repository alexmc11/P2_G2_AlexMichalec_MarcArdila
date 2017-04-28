#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>



void main() {
	std::ifstream fentrada("elements.dat");
	std::unordered_map<std::string, std::string, std::string> mymap;
	std::string line, result, elem1, elem2;
	int pos1, pos2, pos3, end;

	while (getline(fentrada, line)) {
		std::cout << line << std::endl;
		pos1 = 0;
		pos2 = line.find("=");
		pos3 = line.find("+");
		end = line.find("\n");
		result = line.substr(pos1, pos2 - 1);
		elem1 = line.substr(pos2 + 1, pos3 - 1);
		elem2 = line.substr(pos3 + 1, end);
		//usar find para encontrar posicion y luego usarla
		//calcular distancia entre una palabra y otra para que funcione el substr
	};
}