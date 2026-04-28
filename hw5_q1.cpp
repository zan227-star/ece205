#include <iostream>
using namespace std;

class BicycleSpeedometer {
    private:
    
    double distance; // in miles
    double travelTime; // in minutes

    public:

    BicycleSpeedometer() 
    {
        distance = 0.0;
        travelTime = 0.0;
    }

    void setDistance(double d)
    {
        distance = d;
    }

    void setTime(double t) 
    {
        travelTime = t;
    }

    double getDistance()
    {
        return distance;
    }

    double getTime()
    {
        return travelTime;
    }

    double calAvgSpeed()
    {
        if (travelTime == 0) 
        {
            cout << "Time can't be zero." << endl;
            return 0.0;
        }

        return distance / (travelTime / 60);
    }
};

int main()
{
    BicycleSpeedometer speed;

    double dist, t;

    cout << "What was the distance traveled (in miles):" << endl;
    cin >> dist;

    cout << "How much time did this take:" << endl;
    cin >> t;

    speed.setDistance(dist);
    speed.setTime(t);

    cout << speed.getDistance() << " miles" << endl;
    cout << speed.getTime() << " minutes" << endl;
    cout << speed.calAvgSpeed() << " mph" << endl;

    return 0;
}