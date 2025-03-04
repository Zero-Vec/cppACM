#include <stdio.h>
#include <math.h>

int main() {
    int hour, minute;
    float hour_angle, minute_angle, angle;

    scanf("%d:%d", &hour, &minute);

    if (hour >= 12) {
        hour -= 12;
    }

    hour_angle = (hour * 30.0) + (minute * 0.5);
    minute_angle = minute * 6.0;

    angle = fabs(hour_angle - minute_angle);

    if (angle > 180) {
        angle = 360 - angle;
    }

    printf("%.3f\n", angle);

    return 0;
}