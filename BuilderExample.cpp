#include <iostream>


// Your end product 
class Home{
    std::string _foundation;
    std::string _wallColor;
    std::string _roof;
    std::string _floor;

public:

    Home(std::string set_foundation) {_foundation = set_foundation;}

    void setRoof(std::string set_roof) { _roof = set_roof; }

    void setWallColor(std::string set_wallColor) {_wallColor = set_wallColor; }

    void setFloorType(std::string set_floorType) {_floor = set_floorType; }

    std::string getRoofType() { return _roof; }
    std::string getWallColor() { return _wallColor; }
    std::string getFloorType() { return _floor; }
    
    void show() {
    std::cout << "Foundation: " << _foundation << "\n";
    std::cout << "Wall Color: " << _wallColor  << "\n";
    std::cout << "Floor Type: " << _floor      << "\n";
    std::cout << " Roof Type: "  << _roof       << "\n" << "\n";
    }
};


// AppleProductBuilder Abstract Class all builders should have at least these methods
class HomeBuilder{
protected:
    Home *_house;
public:
    virtual void buildFoundation() = 0;
    virtual void buildWalls() = 0;
    virtual void buildFloor() = 0;
    virtual void buildRoof() = 0;
    Home* getHomeMaterials(){ return _house; }
};


// AppleProductBuilder concrete class knows only how to build iPhone AppleProduct!
class GenericLot: public HomeBuilder {

public:

    void buildFoundation() { _house = new Home("Concrete"); }

    void buildRoof() { _house->setRoof("Shingles");   }

    void buildWalls() { _house->setWallColor("Blue");  }

    void buildFloor() { _house->setFloorType("Wooden");  }
};


class FancyLot: public HomeBuilder {

public:

    void buildFoundation() { _house = new Home("Marble"); }

    void buildRoof() { _house->setRoof("Tin");   }

    void buildWalls() { _house->setWallColor("Light Yellow");  }

    void buildFloor() { _house->setFloorType("Carpet");  }
};

class EmptyLot: public HomeBuilder {

public:

    void buildFoundation() { _house = new Home("N\\A"); }

    void buildRoof() { _house->setRoof("N\\A");   }

    void buildWalls() { _house->setWallColor("N\\A");  }

    void buildFloor() { _house->setFloorType("N\\A");  }
};


class Director{

    HomeBuilder *builder;

public:

    Home* createAppleProduct(HomeBuilder *builder) {
        builder-> buildFoundation();
        builder->buildWalls();
        builder->buildRoof();
        builder->buildFloor();
        return builder->getHomeMaterials();
    }
};

int main() {
	
  Director dir;
  GenericLot gl;
  FancyLot fl;
  EmptyLot el;

	Home *generic = dir.createAppleProduct(&gl);
	Home *fancy = dir.createAppleProduct(&fl);
    Home *empty = dir.createAppleProduct(&el);
	
   std::cout << "Generic Lot: \n" << "--------------\n";
	generic->show();
  delete generic;

    std::cout << "********************************\n";

    std::cout << "Fancy Lot: \n" << "--------------\n";
	fancy->show();
  delete fancy;  


  std::cout << "********************************\n";

    std::cout << "Empty Lot: \n" << "--------------\n";
	empty->show();
  delete empty;  
    
	return 0;
}
