#include "SolarSystem.hpp"
#include <bits/stdc++.h>
#include "../GUI/guiMain.hpp"

// double SOLARMASS = 20000;

double SOLARMASS = 1.989 * pow(10,30); // in kg
double SOLARDIAMETER = 1400000; // in km
double ASTROUNIT = 150000000; // in km
double DELTATIME = 0.0000000001;

// Constructeur
SolarSystem::SolarSystem(Vector2D center) : paths{}, celestialBodys{}, dimension{30*ASTROUNIT,30*ASTROUNIT}, center{center} {
  double f = (double)rand() / RAND_MAX;
  double m = (f*7.5 + 0.5) * SOLARMASS;
  star = new Star{m,center,this};
  star->setDiameter(SOLARDIAMETER);
}

SolarSystem::~SolarSystem(){
  cout << "deleting SolarSystem" << endl;
  // for (int i =0; i< celestialBodys.size();i++)
  //  {
  //    delete (celestialBodys[i]);
  //  } 

  // std::vector< Planet* >::iterator it = celestialBodys.begin();
  // for ( ; it != celestialBodys.end(); it++ ) {
  //   std::cout << (*it) << endl;
  //   //delete *it;
  // }

  // celestialBodys.clear();
  
  celestialBodys.erase(celestialBodys.begin(),celestialBodys.end());

  // for(unsigned int i = 0; i < celestialBodys.size(); i++) {
  //         delete celestialBodys[i];
  // }
  delete star;
}

// SolarSystem::SolarSystem(const SolarSystem &) {

// }

// virtual SolarSystem::~SolarSystem() {

// }

vector<Planet*> SolarSystem::getBodys() {
  return celestialBodys;
}

map<Planet*,vector<Vector2D>> SolarSystem::getPaths() {
  return paths;
}

Vector2D SolarSystem::getDimension() {
  return dimension;
}
Vector2D SolarSystem::getCenter() {
  return center;
}

void SolarSystem::addBody(Planet* body) {
    celestialBodys.push_back(body);
    addPath(body,body->getPosition());
    return;
}

// vector<Vector2D> getPathOfBody(CelestialBody* body) {

// }

void SolarSystem::addPath(Planet* body, Vector2D vect) {
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
  for(unsigned int i = 0; i < getBodys().size(); i++) {
    getBodys()[i]->updatePosition();
  }
}

void SolarSystem::newtonGravAll() {
  for(unsigned int i = 0; i < getBodys().size(); i++) {
    for(unsigned int j = 0; j < getBodys().size(); j++) {
      if(i != j) {
        getBodys()[i]->newtonGrav(getBodys()[j]);
      }
    }
    getBodys()[i]->newtonGrav(star);
  }
}

void SolarSystem::generateRandomPlanet() {
  double height = dimension.getX()/2;
  double width = dimension.getY()/2;

  double f = (double)rand() / RAND_MAX;
  double x = f * width;
  double neg = (double)rand() / RAND_MAX;
  if (neg<0.5) {
    x = -x;
  }
  x += center.getX();
  // if (x<0) { x = -x; }
  // cout << "x : " << x << endl;

  f = (double)rand() / RAND_MAX;
  double y = f * height;
  neg = (double)rand() / RAND_MAX;
  if (neg<0.5) {
    y = -y;
  }
  y += center.getY();
  // if (y<0) { y = -y; }
  // cout << "y : " << y << endl;

  f = (double)rand() / RAND_MAX;
  double m = f * 50;
  // if (m<0) { m = -m; }
  // cout << "m : " << m << endl;

  f = (double)rand() / RAND_MAX;
  double vx = f * 10;
  neg = (double)rand() / RAND_MAX;
  if (neg<0.5) {
    vx = -vx;
  }
  // cout << "vx : " << vx << endl;
  f = (double)rand() / RAND_MAX;
  double vy = f * 10;
  neg = (double)rand() / RAND_MAX;
  if (neg<0.5) {
    vy = -vy;
  }
  // cout << "vy : " << vy << endl;

  Planet *object = new Planet{m, Vector2D{x, y}, this};
  object->addVelocity(Vector2D{vx, vy});
  //object->diameter = findDiametre(m);

  // cout << "===============" << endl;
}


Star* SolarSystem::getStar() {
  return star;
}
void SolarSystem::setStar(Star* s) {
  star = s;
}