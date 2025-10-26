#include "matrice_4d.hpp"

Matrix4::Matrix4() {
    for (int i = 0; i < 16; ++i)
        matrice[i] = (i % 5 == 0) ? 1.f : 0.f;
}

Matrix4 Matrix4::operator*(const Matrix4& other) const {
    Matrix4 result;

    for (int col = 0; col < 4; ++col) {
        for (int row = 0; row < 4; ++row) {
            result.matrice[col * 4 + row] = 0.0f;
            for (int k = 0; k < 4; ++k) {
                result.matrice[col * 4 + row] += 
                    this->matrice[k * 4 + row] * other.matrice[col * 4 + k];
            }
        }
    }
    return result;
}


Vec4d Matrix4::mat_to_vec(const Vec4d& v) {
    Vec4d result;

    result.x = matrice[0]  * v.x + matrice[4]  * v.y + matrice[8]  * v.z + matrice[12] * v.w;
    result.y = matrice[1]  * v.x + matrice[5]  * v.y + matrice[9]  * v.z + matrice[13] * v.w;
    result.z = matrice[2]  * v.x + matrice[6]  * v.y + matrice[10] * v.z + matrice[14] * v.w;
    result.w = matrice[3]  * v.x + matrice[7]  * v.y + matrice[11] * v.z + matrice[15] * v.w;

    return result;
}