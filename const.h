#include <random>
#include <utility>

const int screenWidth = 800;
const int screenHeight = 800;
const int fps = 60;
const int rad = 3;
const int noPoints = 2000;
bool paused = false;
const int fact = 2;
const float threshold = 5; 
const int zones = 10;
int zoneInc = screenHeight/zones;

int gen_ran(int min_val, int max_val) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(min_val, max_val); 
    return dis(gen); 
}

double gen_ran_fl(double min_val, double max_val) {
    static std::mt19937 gen(std::random_device{}());  
    std::uniform_real_distribution<double> dis(min_val, max_val); 
    double value = dis(gen);
    return std::round(value * 100) / 100; //for 2 decimal places
}

