#include "Vector3D.h"
#include "Vector3D.h"
#include <cmath>
#include <iostream>

// Default Constructor
Vector3D::Vector3D() : coords(std::make_unique<double[]>(3)) {
    coords[0] = 0; 
    coords[1] = 0; 
    coords[2] = 0;
}

// Parameterized Constructor
Vector3D::Vector3D(double x, double y, double z) : coords(std::make_unique<double[]>(3)) {
    coords[0] = x; 
    coords[1] = y; 
    coords[2] = z;
}

// Copy Constructor
Vector3D::Vector3D(const Vector3D& other) : coords(std::make_unique<double[]>(3)) {
    if (other.coords) {
        coords[0] = other.coords[0];
        coords[1] = other.coords[1];
        coords[2] = other.coords[2];
    } else {
        coords[0] = 0; coords[1] = 0; coords[2] = 0;
    }
}

// Copy Assignment Operator
Vector3D& Vector3D::operator=(const Vector3D& other) {
    if (this == &other) return *this;

    if (!coords) {
        coords = std::make_unique<double[]>(3);
    }

    if (other.coords) {
        coords[0] = other.coords[0];
        coords[1] = other.coords[1];
        coords[2] = other.coords[2];
    } else {
        coords[0] = 0; coords[1] = 0; coords[2] = 0;
    }
    
    return *this;
}

// Move Constructor
Vector3D::Vector3D(Vector3D&& other) noexcept : coords(std::move(other.coords)) {
}

// Move Assignment Operator
Vector3D& Vector3D::operator=(Vector3D&& other) noexcept {
    if (this != &other) {
        coords = std::move(other.coords);
    }
    return *this;
}

// Getters 
double Vector3D::getX() const { return coords ? coords[0] : 0.0; }
double Vector3D::getY() const { return coords ? coords[1] : 0.0; }
double Vector3D::getZ() const { return coords ? coords[2] : 0.0; }

// Setters 
void Vector3D::setX(double x) { if (coords) coords[0] = x; }
void Vector3D::setY(double y) { if (coords) coords[1] = y; }
void Vector3D::setZ(double z) { if (coords) coords[2] = z; }


// Standalone Functions


void normalizeVector(std::shared_ptr<Vector3D> vec) {
    if (!vec) {
        std::cout << "Error: Vector is null!" << std::endl;
        return;
    }

    double x = vec->getX();
    double y = vec->getY();
    double z = vec->getZ();
    double length = std::sqrt(x * x + y * y + z * z);

    if (length > 0.0) {
        vec->setX(x / length);
        vec->setY(y / length);
        vec->setZ(z / length);
        std::cout << "Vector normalized successfully." << std::endl;
    } else {
        std::cout << "Vector length is 0, cannot normalize." << std::endl;
    }
}
