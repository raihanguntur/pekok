#pragma once
#include <fstream>
#include <iostream>

struct SaveData
{
	static void SaveToFile()
	{
		//BSON::Object obj;
		//obj.map["conopen"] = Globals::ShowConsole;
		//obj.map["piopen"] = Globals::ShowPlayerMenu;
		//obj.map["minimapopen"] = Globals::showMinimap;
		//obj.map["pt"] = Globals::EspBools["Player Trail"].value;
		//
		//obj.map["tr"] =  Globals::playerTracerColor.x;
		//obj.map["tg"] =  Globals::playerTracerColor.y;
		//obj.map["tb"] =  Globals::playerTracerColor.z;
		//				 
		//obj.map["per"] = Globals::localPlayerESPColor.x;
		//obj.map["peg"] = Globals::localPlayerESPColor.y;
		//obj.map["peb"] = Globals::localPlayerESPColor.z;
		//				 
		//obj.map["oer"] = Globals::otherPlayerESPColor.x;
		//obj.map["oeg"] = Globals::otherPlayerESPColor.y;
		//obj.map["oeb"] = Globals::otherPlayerESPColor.z;
		//
		//obj.map["cer"] = Globals::collectableBoxColor.x;
		//obj.map["ceg"] = Globals::collectableBoxColor.y;
		//obj.map["ceb"] = Globals::collectableBoxColor.z;
		//
		//obj.map["ctr"] = Globals::collectableTracerColor.x;
		//obj.map["ctg"] = Globals::collectableTracerColor.y;
		//obj.map["ctb"] = Globals::collectableTracerColor.z;
		//
		//obj.map["mer"] = Globals::monsterBoxColor.x;
		//obj.map["meg"] = Globals::monsterBoxColor.y;
		//obj.map["meb"] = Globals::monsterBoxColor.z;
		//
		//obj.map["mtr"] = Globals::monsterTracerColor.x;
		//obj.map["mtg"] = Globals::monsterTracerColor.y;
		//obj.map["mtb"] = Globals::monsterTracerColor.z;
		//
		//obj.map["pet"] = Globals::SelfBoxThickness;
		//obj.map["tet"] = Globals::playerTracerThickness;
		//obj.map["oet"] = Globals::OtherPlayerBoxThickness;
		//obj.map["cet"] = Globals::collectableEspThickness;
		//obj.map["ctt"] = Globals::collectableTracerThickness;
		//obj.map["met"] = Globals::monsterEspThickness;
		//obj.map["mtt"] = Globals::monsterTracerThickness;
		//
		//obj.map["minimapza"] = Globals::minimapZoomAmount;
		//
		//
		//std::ofstream outFile = std::ofstream("ArkSaveData.bson");
		//std::vector<char> dumpedData = BSON::BSONEncoder::Dump(obj);
		//outFile.write(dumpedData.data(), dumpedData.size());
	}
	static BSON::Object ReadFromFile(bool* valid)
	{
		//FILE* f = fopen("ArkSaveData.bson", "rb");
		//if (!f)
		//{
		//	*valid = false;
		//	return BSON::Object();
		//}
		//fseek(f, 0, SEEK_END);
		//long fsize = ftell(f);
		//fseek(f, 0, SEEK_SET);  /* same as rewind(f); */
		//
		//std::vector<char> buffer = {};
		//buffer.resize(fsize + 1);
		//fread(buffer.data(), 1, fsize, f);
		//fclose(f);
		//
		//buffer[fsize] = 0;
		//
		//
		//*valid = true;
		//return BSON::BSONEncoder::Load(buffer);
		*valid = false;
		return BSON::Object();
	}

};