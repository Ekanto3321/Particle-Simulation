#include "const.h"
#include "raylib.h"

class point{

public:

    float x;
    float y;
    int m;
    float xdir;
    float ydir;
    Color color;

    point(){

        this->x = gen_ran_fl(0,screenWidth);
        this->y = gen_ran_fl(0,screenHeight);
        this->m = gen_ran(rad-rad*0.45,rad+rad*0.5);
        // this->m = gen_ran(rad,rad);

        if(gen_ran(0,1)){
            //x computed
            this->xdir = gen_ran_fl(-fact,fact);
            if(xdir<0)this->ydir = xdir+fact;
            else this->ydir = fact-xdir;
        }
        else{
            //y computed
            this->ydir = gen_ran_fl(-fact,fact);
            if(ydir<0)this->xdir = ydir+fact;
            else this->xdir = fact-ydir;
        }

        this->color = { 
            255,  
            255,  
            255,  
            255                              
        };

        // if(this->x>screenWidth/2){
        //     this->color = { 
        //         0,  
        //         255,  
        //         0,  
        //         255                              
        //     };
        // }
        // else {
        //     this->color = { 
        //         255,  
        //         0,  
        //         0,  
        //         255                              
        //     };
        // }

        // this->color = { 
        //     (unsigned char)gen_ran(0, 255),  
        //     (unsigned char)gen_ran(0, 255),  
        //     (unsigned char)gen_ran(0, 255),  
        //     255                              
        // };

    }   
    

};

std::pair<std::pair<float,float>,std::pair<float,float>> resolve(point p1, point p2){


    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float distance = std::sqrt(dx * dx + dy * dy);

    // Normal vector
    float nx = dx / distance;
    float ny = dy / distance;

    // Relative velocity
    float rvx = p2.xdir - p1.xdir;
    float rvy = p2.ydir - p1.ydir;

    // Velocity along the normal
    float velAlongNormal = rvx * nx + rvy * ny;

    // // If velocities are separating, don't resolve
    if (velAlongNormal > 0) return{{p1.xdir,p1.ydir},{p2.xdir,p2.ydir}};
    
    // Apply impulse to velocities
    p1.xdir -= -velAlongNormal * nx;
    p1.ydir -= -velAlongNormal * ny;
    p2.xdir += -velAlongNormal * nx;
    p2.ydir += -velAlongNormal * ny;
    return {{p1.xdir,p1.ydir},{p2.xdir,p2.ydir}};

}
