#include <stdio.h>
#include <math.h>

int main() {
    int h, m;
    float h_angle, m_angle, angle;
    scanf("%d:%d", &h, &m);
    if (h >= 12) {
        h -= 12;
    }
    h_angle = (h * 30.0) + (m * 0.5);
    m_angle = m * 6.0;
    angle = fabs(h_angle - m_angle);
    if (angle > 180) {
        angle = 360 - angle;
    }
    printf("%.3f\n", angle);
    return 0;
}
