#include <stdio.h>

float GetHouseSize(float width, float height, float roof_height);


int main()
{
    float width = 0.F;
    float height = 0.F;
    float roof_height = 0.F;
    float size  = 0.F;

    printf("input the width, height, and roof height: ");
    scanf("%f %f %f", &width, &height, &roof_height);

    size = GetHouseSize( width,  height,  roof_height);

    printf("house size = %f", size);


    return 0;

}

float GetHouseSize(float width, float height, float roof_height)
{
    float size = width * (height - roof_height) + 0.5 * width * roof_height;

    return size;

}