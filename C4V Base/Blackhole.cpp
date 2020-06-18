#include "stdafx.h"


bool get_vehicles(std::vector<uint32_t>& result) {
	if (!Hooking::m_replayIntf) return false;
	if (CVehicleInterface * vehInt = Hooking::m_replayIntf->pCVehicleInterface) {
		CVehHandle* vehList = vehInt->VehList;
		for (int i = 0; i < vehInt->iMaxVehicles; ++i) {
			void* pCVehicle = vehList[i].pCVehicle;
			if (!pCVehicle) continue;
			if (uint32_t handle = *(uint32_t*)pCVehicle) {
				result.push_back(handle);
			}
		}
		return true;
	}
	return false;
}


float blackHole::var::blackholeX;
float blackHole::var::blackholeY;
float blackHole::var::blackholeZ;
std::vector<uint32_t> blackHole::var::vehicles;
bool blackHole::var::toggle = false;

// loop the blackHole::tick
void blackHole::tick() {
	var::toggle ? initialize() : nullptr;
}

void blackHole::initialize()
{
	get_vehicles(var::vehicles);

	for (auto v : var::vehicles) {
		Hooking::network_request_control_of_entity(v);
		if (Hooking::network_has_control_of_entity(v)) {
			Vector3 vehiclePosition = get_entity_coords(v, false);
			float calculatedX = var::blackholeX - vehiclePosition.x, calculatedY = var::blackholeY - vehiclePosition.y, calculatedZ = var::blackholeZ - vehiclePosition.z;
			ENTITY::APPLY_FORCE_TO_ENTITY(v, 1, (calculatedX * 12), (calculatedY * 12), (calculatedZ * 88), 1, 1, 2, 0, false, 1, false, 0, 1);
		}
	}
	GRAPHICS::DRAW_MARKER(28, var::blackholeX, var::blackholeY, var::blackholeZ, 0, 0, 0, 0, 0, 0, 30, 30, 30, 0, 0, 255, 200, false, true, false, false, false, false, false);
}

void blackHole::setCurrentPos() {
	Vector3 myPos =get_entity_coords(player_ped_id(), 1);
	var::blackholeX = myPos.x + 160.f;
	var::blackholeY = myPos.y + 160.f;
	var::blackholeZ = myPos.z + 160.f;
}
