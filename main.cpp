#include <math.h>

#include <array>
#include <iostream>
#include <map>

std::map<std::string, std::array<double, 2>>
incenter(std::array<double, 2> p1, std::array<double, 2> p2,
         std::array<double, 2> p3) {
    double x1 = p1[0], y1 = p1[1];
    double x2 = p2[0], y2 = p2[1];
    double x3 = p3[0], y3 = p3[1];

    double a = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    double c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    double incenterX = (a * x1 + b * x2 + c * x3) / (a + b + c);
    double incenterY = (a * y1 + b * y2 + c * y3) / (a + b + c);

    std::array<double, 2> incenterPoint;
    incenterPoint[0] = incenterX;
    incenterPoint[1] = incenterY;

    std::map<std::string, std::array<double, 2>> returnMap = {
        {"Incenter", incenterPoint}};

    return returnMap;
}

std::map<std::string, std::array<double, 2>>
centroid(std::array<double, 2> p1, std::array<double, 2> p2,
         std::array<double, 2> p3) {
    std::array<double, 2> centroidPoint;
    centroidPoint[0] = (p1[0] + p2[0] + p3[0]) / 3;
    centroidPoint[1] = (p1[1] + p2[1] + p3[1]) / 3;

    std::map<std::string, std::array<double, 2>> returnMap = {
        {"Centroid", centroidPoint}};

    return returnMap;
}

std::map<std::string, std::array<double, 2>>
circumcenter(std::array<double, 2> p1, std::array<double, 2> p2,
             std::array<double, 2> p3) {
    std::array<double, 2> circumcenterPoint;

    double x1 = p1[0];
    double y1 = p1[1];
    double x2 = p2[0];
    double y2 = p2[1];
    double x3 = p3[0];
    double y3 = p3[1];

    circumcenterPoint[0] =
        ((x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2) * (y1 - y3) -
         (x1 * x1 + y1 * y1 - x3 * x3 - y3 * y3) * (y1 - y2)) /
        (2 * (x1 - x2) * (y1 - y3) - 2 * (x1 - x3) * (y1 - y2));

    circumcenterPoint[1] =
        ((x1 - x2) * (x1 * x1 + y1 * y1 - x3 * x3 - y3 * y3) -
         (x1 - x3) * (x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2)) /
        (2 * (x1 - x2) * (y1 - y3) - 2 * (x1 - x3) * (y1 - y2));

    std::map<std::string, std::array<double, 2>> returnMap = {
        {"Circumcenter", circumcenterPoint}};

    return returnMap;
}

std::map<std::string, std::array<double, 2>>
orthocenter(std::array<double, 2> p1, std::array<double, 2> p2,
            std::array<double, 2> p3) {
    std::array<double, 2> orthocenterPoint;

    double x1 = p1[0];
    double y1 = p1[1];
    double x2 = p2[0];
    double y2 = p2[1];
    double x3 = p3[0];
    double y3 = p3[1];

    orthocenterPoint[0] = ((x2 * (x1 - x3) + y2 * (y1 - y3)) * (y3 - y2) -
                           (y3 - y1) * (x1 * (x2 - x3) + y1 * (y2 - y3))) /
                          ((x3 - x2) * (y3 - y1) - (y3 - y2) * (x3 - x1));

    orthocenterPoint[1] = ((x2 * (x1 - x3) + y2 * (y1 - y3)) * (x3 - x2) -
                           (x3 - x1) * (x1 * (x2 - x3) + y1 * (y2 - y3))) /
                          ((y3 - y2) * (x3 - x1) - (x3 - x2) * (y3 - y1));

    std::map<std::string, std::array<double, 2>> returnMap = {
        {"Orthocenter", orthocenterPoint}};

    return returnMap;
}

int main() {
    std::array<double, 2> p1;
    std::cout << "Enter coordinates of point 1 (x y): ";
    std::cin >> p1[0] >> p1[1];

    std::array<double, 2> p2;
    std::cout << "Enter coordinates of point 2 (x y): ";
    std::cin >> p2[0] >> p2[1];

    std::array<double, 2> p3;
    std::cout << "Enter coordinates of point 3 (x y): ";
    std::cin >> p3[0] >> p3[1];

    std::map<std::string, std::array<double, 2>> (*centerFunctions[4])(
        std::array<double, 2>, std::array<double, 2>, std::array<double, 2>) = {
        incenter, centroid, circumcenter, orthocenter};

    int numCenters = sizeof(centerFunctions) / sizeof(centerFunctions[0]);

    std::map<std::string, std::array<double, 2>> centers;

    for (int i = 0; i < numCenters; i++) {
        std::map<std::string, std::array<double, 2>> center =
            centerFunctions[i](p1, p2, p3);
        centers.insert({center.begin()->first, center.begin()->second});
        std::cout << center.begin()->first << ": " << center.begin()->second[0]
                  << ", " << center.begin()->second[1] << "\n";
    }

    return 0;
}
