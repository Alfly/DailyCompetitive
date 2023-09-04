#include <math.h>
#include <stdio.h>

#define R 7     // radius
#define X 10    // 圆心(X, Y)
#define Y 10

int main() {
    // 逐行打印
    // 上层空白
    for (int row = 0; row < Y - R; row++) printf("\n");
    // 水平扫描 圆[R, -R]
    for (int l = R; l >= -R; l--) {
        int width = sqrt(R * R - l * l);    // 横坐标的偏移量
        int x;
        int scale = 2;                      // 字体长宽比例为2
        for (x = 0; x < scale * (X - width); x++) printf(" ");
        printf("*");
        for (; x < scale * (X + width); x++) printf(" "); // 空心圆
        // for (; x < scale * (X + width); x++) printf("*");    // 实心圆
        printf("*\n");
    }
    return 0;
}