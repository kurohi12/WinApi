#pragma once
#include"Global.h"
#include"CObject.h"
#include"EventManager.h"


void CreateObject(CObject* obj, GROUP_TYPE type);

void Destroy(CObject* obj);

void ChangeScene(SCENE_TYPE scene);

template<typename T>
void DeleteVec(vector<T>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		if (nullptr != vec[i]) {
			delete vec[i];
		}
	}
	vec.clear();
}


template<typename T1, typename T2>
void DeleteMap(map<T1, T2>& _map) {
	typename map<T1, T2>::iterator iter = _map.begin();

	for (; iter != _map.end(); ++iter) {
		if (nullptr != iter->second) {
			delete iter->second;
		}
	}
	_map.clear();
}