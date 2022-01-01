#pragma once
#include "Globals.h"
namespace Functions
{
	void AddIl2CppTickFunc(float timeout, FUNC function)
	{
		Globals::il2cppCoroutines.push_back(TickFunc(timeout, function));
	}
	void AddIl2CppFunctionCall(FUNC function)
	{
		Globals::il2cppFunctionQueue.push(function);
	}
	void AddIl2CppDataFunctionCall(DATAFUNC function)
	{
		Globals::il2cppDataFunctionQueue.push(function);
	}
}

std::vector<Vector2i> FindPath(Vector2i start, Vector2i end, Il2CppArrayT<Il2CppArrayT<LayerBlock>*>* worldBlocks, Il2CppArrayT<Il2CppArrayT<WorldItemBase*>*>* worldItemDataLayer);