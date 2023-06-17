#include "SolarSystem.hpp"
#include <bits/stdc++.h>

//std::vector<std::vector<Vector2D>> SolarSystem::paths = {};
map<CelestialBody*,vector<Vector2D>> SolarSystem::paths = {};
std::vector<CelestialBody*> SolarSystem::celestialBodys = {};

// Constructeur
SolarSystem::SolarSystem() {
  
}

// SolarSystem::SolarSystem(const SolarSystem &) {

// }

// virtual SolarSystem::~SolarSystem() {

// }

vector<CelestialBody*> SolarSystem::getBodys() {
  return celestialBodys;
}

map<CelestialBody*,vector<Vector2D>> SolarSystem::getPaths() {
  return paths;
}

void SolarSystem::addBody(CelestialBody* body) {
    celestialBodys.push_back(body);
    addPath(body,body->getPosition());
    return;
}

// vector<Vector2D> getPathOfBody(CelestialBody* body) {

// }

void SolarSystem::addPath(CelestialBody* body, Vector2D vect) {
  if(paths.find(body) == paths.end()) {
    vector<Vector2D> vectvect;
    paths[body] = vectvect;
  }
  if (paths[body].size() >= pathSize) {
    paths[body].erase(paths[body].begin());
  }
  paths[body].push_back(vect);
    // if (paths[body].size() > pathSize) {
    //   paths[body].erase(paths[body].begin());
    //   paths[body].insert(paths[body].begin(),Vector2D(vect));
    // } else {
    //   paths[body].insert(paths[body].begin(),Vector2D(vect));
    // }
    // return;
}

// ostream & operator<<(ostream & out, SolarSystem & d) {

// }

// map<CelestialBody, vector<Vector2D>> SolarSystem::getPaths() {
//   return paths;
// }


// maintenant des vector de pointeurs, il faut jouer avec vector dans le maine pour comprendre 
// comment marchent les fonctions begin, end etc sur des int et des int*
void SolarSystem::findIndexBody(CelestialBody* ser) {
  // std::vector<CelestialBody*>::iterator it;
  // it = std::find(*(celestialBodys.begin()),*(celestialBodys.end()), *ser);
  // if (it != celestialBodys.end()) {
  //   std::cout << "Element " << ser << " found at position : ";
  //   std::cout << it - celestialBodys.begin() << " (counting from zero) \n";
  // }
  // else
  //   std::cout << "Element not found.\n\n";
}

void SolarSystem::updateAllPositions() {
  SolarSystem s;
  for(unsigned int i = 0; i < s.getBodys().size(); i++) {
    s.getBodys()[i]->updatePosition();
  }
}

void SolarSystem::newtonGravAll() {
  SolarSystem s;
  for(unsigned int i = 0; i < s.getBodys().size(); i++) {
    for(unsigned int j = 0; j < s.getBodys().size(); j++) {
      if(i != j) {
        s.getBodys()[i]->newtonGrav(*s.getBodys()[j]);
      }
    }
  }
}

void SolarSystem::generateRandomObjetPhysique() {
  // Random Random = new Random();

  // double height = MainClass.interface_utilisateur.dimension.getHeight();
  // double width = MainClass.interface_utilisateur.dimension.getWidth();

  // double x = positiv(Random.nextDouble() * width);
  // double y = positiv(Random.nextDouble() * height);
  // double m = positiv(Random.nextDouble() * 500);
  // double vx = Random.nextGaussian() * 10;
  // double vy = Random.nextGaussian() * 10;

  // ObjetPhysique object = new ObjetPhysique(new Vector2D(x, y), m);
  // object.addForce(new Vector2D(vx, vy));
  // object.diameter = findDiametre(m);
}
