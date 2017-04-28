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
	int res1, res2, res3;
	while (getline(fentrada, line)) {
		std::cout << line << std::endl;
		pos1 = 0;
		pos2 = line.find("=");
		pos3 = line.find("+");
		end = line.find("\n");
		res1 = pos2 - pos1 - 1;
		res2 = (pos3 - 1) - (pos2 + 1);
		res3 = end - (pos3 + 1);
		result = line.substr(pos1, res1);
		elem1 = line.substr(pos2 + 2, res2);
		elem2 = line.substr(pos3 + 2, res3);
		//usar find para encontrar posicion y luego usarla
		//calcular distancia entre una palabra y otra para que funcione el substr
	};
}