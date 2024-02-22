// jesus fucking christ with vscode, and moving directories around make sure 
// ur using the right isntance of a file holy fuck
// this is what they meant when they said unix is user fridnly, but picky with who it's friends are
#include "rtweekend.h"

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"

int main() {
    
    hittable_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    
    cam.image_width  = 400;

    cam.samples_per_pixel = 100;

    cam.max_depth = 50;

    cam.render(world);

    return 0;
}
