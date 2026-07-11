#include "Vector3D.h"
#include <iostream>

int main() {
    // Create a Vector3D object using std::shared_ptr
    std::shared_ptr<Vector3D> vec = std::make_shared<Vector3D>(3.0, 4.0, 5.0);

    // Print the original vector
    std::cout << "Original Vector: (" << vec->getX() << ", " << vec->getY() << ", " << vec->getZ() << ")\n";

    // Normalize the vector
    normalizeVector(vec);

    // Print the normalized vector
    std::cout << "Normalized Vector: (" << vec->getX() << ", " << vec->getY() << ", " << vec->getZ() << ")\n";

    // Test with a null pointer
    std::shared_ptr<Vector3D> nullVec = nullptr;

    // Attempt to normalize a null vector
    normalizeVector(nullVec);

    // Test with a zero-length vector
    std::shared_ptr<Vector3D> zeroVec = std::make_shared<Vector3D>(0.0, 0.0, 0.0);
    normalizeVector(zeroVec);

    // Print the zero-length vector after normalization attempt
    std::cout << "Zero-length Vector after normalization attempt: (" << zeroVec->getX() << ", " << zeroVec->getY() << ", " << zeroVec->getZ() << ")\n";

    //Copy and Move semantics test
    std::shared_ptr<Vector3D> vecCopy = std::make_shared<Vector3D>(*vec); // Copy constructor
    std::cout << "Copied Vector: (" << vecCopy->getX() << ", " << vecCopy->getY() << ", " << vecCopy->getZ() << ")\n";

    // Move semantics test
    std::shared_ptr<Vector3D> vecMove = std::make_shared<Vector3D>(std::move(*vec)); // Move constructor
    std::cout << "Moved Vector: (" << vecMove->getX() << ", " << vecMove->getY() << ", " << vecMove->getZ() << ")\n";
    return 0;
}