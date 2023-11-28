#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main()
{
    std::ifstream jsonFile("config/npcs.json", std::ifstream::binary);
    json data = json::parse(jsonFile);

    std::string mapData = "";

    for (auto& element : data.items())
    {
        std::string id = element.key();
        json data = element.value();

        if (mapData != "")
            mapData += ",\n            ";

        mapData += "\"" + id + "\" => labyrinth_npc_data{ID := \"" + id + "\", Name := " + data["name"].dump() + "}";
    }

    std::ofstream verseFile("compiled_verse/data_npcs.verse");

    verseFile << "labyrinth_npc_data_file<public> := module\n";
    verseFile << "{\n";
    verseFile << "    GetData<public>() : [string]labyrinth_npc_data =\n";
    verseFile << "    {\n";
    verseFile << "        DataMap : [string]labyrinth_npc_data = map{\n";
    verseFile << "            " + mapData + "\n";
    verseFile << "        }\n\n";
    verseFile << "        return DataMap\n";
    verseFile << "    }\n";
    verseFile << "}\n";

    verseFile.close();
}