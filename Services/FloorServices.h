#ifndef FLOORSERVICES_H
#define FLOORSERVICES_H
#include <vector>
#include "../Models/Floor.h"

class FloorServices {
    public:
        std::vector<Floor> getAllFloors();
        void updateFloor(Floor updatedFloor);
};
#endif