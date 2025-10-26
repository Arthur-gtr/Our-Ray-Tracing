#ifndef MATRIX4_HPP
    #define MATRIX4_HPP
    #define MAT(m, row, col) m[(row) * 4 + (col)]


struct Vec4d
{
    float x;
    float y;
    float z;
    float w;
};


class Matrix4 {
    public:
        float matrice[16];
        Matrix4();
        Matrix4 operator *(const Matrix4& other) const;
        Vec4d mat_to_vec(const Vec4d& vector);
};

#endif
