#pragma once 
#include <memory>

class Vector3D {
private:
    std::unique_ptr<double[]> coords; 

public:
    // Constructors
    Vector3D();
    Vector3D(double x, double y, double z);

    // Destructor
    ~Vector3D() = default;

    // Copy semantics
    Vector3D(const Vector3D& other);
    Vector3D& operator=(const Vector3D& other);

    // Move semantics
    Vector3D(Vector3D&& other) noexcept;
    Vector3D& operator=(Vector3D&& other) noexcept;

    // Getters
    double getX() const;
    double getY() const;
    double getZ() const;

    // Setters
    void setX(double x);
    void setY(double y);
    void setZ(double z);
};
void normalizeVector(std::shared_ptr<Vector3D> vec);