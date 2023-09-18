#ifndef _GLOBALVALUES
#define _GLOBALVALUES

class GlobalValues {
    public:
        static int PHYSICS_TICK_SPEED;
        static double timeScale;
        static double SOLARMASS;
        static double SOLARDIAMETER;
        static double ASTROUNIT;
        static double DELTATIME;
        static double GRAVITATIONALCONSTANT;
        static double pathSize;

        //static double getDeltaTime();
        static void updateGlobalValues();


};


#endif