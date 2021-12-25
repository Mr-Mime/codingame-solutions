#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct coords {
    int x;
    int y;
};

int get_height();

int main()
{
    // the number of points used to draw the surface of Mars.
    int surface_n;
    scanf("%d", &surface_n);

    // Save the surface points
    struct coords surface_points[surface_n];
    for (int i = 0; i < surface_n; i++) {
        scanf("%d%d", &surface_points[i].x, &surface_points[i].y);
    }

    int landing_height = 0;

    // game loop
    while (1) {
        int X;
        int Y;
        // the horizontal speed (in m/s), can be negative.
        int h_speed;
        // the vertical speed (in m/s), can be negative.
        int v_speed;
        // the quantity of remaining fuel in liters.
        int fuel;
        // the rotation angle in degrees (-90 to 90).
        int rotate;
        // the thrust power (0 to 4).
        int power;
        scanf("%d%d%d%d%d%d%d", &X, &Y, &h_speed, &v_speed, &fuel, &rotate, &power);

        // If the landing height has not been set, we need to calculate it
        if (landing_height == 0) {
            // Therefore we go through the surface points and check for the two on the same height (y value)
            for (int i = 0; i < surface_n-1; i++) {
                if (surface_points[i].x < X && surface_points[i+1].x > X) {
                    landing_height = surface_points[i].y;
                    fprintf(stderr, "Landing height is: %d\n", landing_height);
                    break;
                }
            }
        }
        
        // Calculate actual height, calculate speed in 4 and the stopping distance we will need 
        int height_above_ground = Y - landing_height;
        int speed_in_4_sec = round((v_speed - 3.7 - 2.7 - 1.7));
        int stop_distance = (40*40 - speed_in_4_sec*speed_in_4_sec) / 2 * -4;

        // Debug output
        fprintf(stderr, "Current speed: %d\n", v_speed);
        fprintf(stderr, "Speed in 4 seconds: %d\n", speed_in_4_sec);
        fprintf(stderr, "Distamce to stop: %d", stop_distance);

        // If the stop distance is lower than the remaining dist to ground, we need full thrust to decelerate
        if (stop_distance > height_above_ground) {
            printf("0 4\n");
        } else {
            printf("0 0\n");
        }
    }

    return 0;
}
