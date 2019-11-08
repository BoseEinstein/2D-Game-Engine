#ifndef TINYMATH_H
#define TINYMATH_H

#include <cmath>

// Forward references of each of the structs
struct Vector3D;
struct Matrix3D;

// Vector3D performs vector operations with 3-dimensions
// The purpose of this class is primarily for 3D graphics
// applications.
struct Vector3D{
    // Note: x,y,z are a convention
    // x,y,z could be position, but also any 3-component value.
    float x,y,z;

    // Default conostrutcor
    // 'why default?' https://stackoverflow.com/questions/20828907/the-new-keyword-default-in-c11
    Vector3D() = default;

    // The "Real" constructor we want to use.
    // This initializes the values x,y,z
    Vector3D(float a, float b, float c){
      x=a;
      y=b;
      z=c;

      // TODO:
    }

    // Index operator, allowing us to access the individual
    // x,y,z components of our vector.
    float& operator[](int i){
        // TODO: Discuss with your partner why this works.
        //       There is no code to change here. 
      return ((&x)[i]);
    }

    // Index operator, allowing us to access the individual
    // x,y,z components of our vector.
    const float& operator[](int i) const{
        // TODO: Discuss with your partner why this works.
        //       There is no code to change here.
        return ((&x)[i]);
    }

    // Multiplication Operator
    // Multiply vector by a uniform-scalar.
    Vector3D& operator *=(float s){
        // TODO:
        x*=s;
        y*=s;
        z*=s;
        return (*this);
    }

    // Division Operator
    Vector3D& operator /=(float s){
        // TODO:
        x/=s;
        y/=s;
        z/=s;
        return (*this);
    }

    // Addition operator
    Vector3D& operator +=(const Vector3D& v){
        // TODO:

        x+=v.x;
        y+=v.y;
        z+=v.z;
      return (*this);
    }

    // Subtraction operator
    Vector3D& operator -=(const Vector3D& v){
        // TODO:

      x-=v.x;
      y-=v.y;
      z-=v.z;
      return (*this);
    }

};

// Compute the dot product of a Vector3D
inline float Dot(const Vector3D& a, const Vector3D& b){
  // TODO:
  return a[0]*b[0] + a[1]*b[1]+a[2]*b[2];
}

// Multiplication of a vector by a scalar values
inline Vector3D operator *(const Vector3D& v, float s){
  // TODO:
  Vector3D vec;
  vec[0] = v[0]*s;
  vec[1] = v[1]*s;
  vec[2] = v[2]*s;
  return vec;
}

// Division of a vector by a scalar value.
inline Vector3D operator /(const Vector3D& v, float s){
  // TODO:
  Vector3D vec;
  vec[0] = v[0]/s;
  vec[1] = v[1]/s;
  vec[2] = v[2]/s;
  return vec;
}

// Negat a Vector
inline Vector3D operator -(const Vector3D& v){
  // TODO:
  Vector3D vec;
  vec[0] = v[0]*-1;
  vec[1] = v[1]*-1;
  vec[2] = v[2]*-1;
  return vec;
}

// Return the magnitude of a vector
inline float Magnitude(const Vector3D& v){
  // TODO:
  return sqrt(Dot(v,v));
}

// Add two vectors together
inline Vector3D operator +(const Vector3D& a, const Vector3D& b){
  // TODO:
  Vector3D vec;
  vec.x = a.x + b.x;
  vec.y = a.y + b.y;
  vec.z = a.z + b.z;
  return vec;
}

// Subtract two vectors
inline Vector3D operator -(const Vector3D& a, const Vector3D& b){
  // TODO:
  Vector3D vec;
  vec.x = a.x-b.x;
  vec.y = a.y-b.y;
  vec.z = a.z-b.z;
  return vec;
}

// Set a vectors magnitude to 1
// Note: This is NOT generating a normal vector
inline Vector3D Normalize(const Vector3D& v){
  // TODO:
  Vector3D vec;
  vec = v/Magnitude(v);
  return vec;
}

// Vector Projection
inline Vector3D Project(const Vector3D& a, const Vector3D& b){
  // TODO:
  Vector3D vec;
  vec = a*(Dot(a,b)/(Magnitude(a)*Magnitude(a)));
  return vec;
}



// a x b (read: 'a crossed b')
// Produces a new vector perpendicular to a and b.
// (So long as a and b are not parallel which returns zero vector)
inline Vector3D CrossProduct(const Vector3D& a, const Vector3D& b){
  // TODO:
  Vector3D vec;
  return vec;
}

/**
// Matrix 3D represents 3x3 matrices in Math
struct Matrix3D{
private:
    float n[3][3];  // Store each value of the matrix

public:
    Matrix3D() = default;

    // TODO: Row or column major order you decide!
    // Matrix constructor with 9 scalar values.
    Matrix3D( float n00, float n01, float n02,
              float n10, float n11, float n12,
              float n20, float n21, float n22){

        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
    }

    // Matrix constructor from three vectors.
    Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c){
      n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
      n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
      n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
    }

    // Index operator with two dimensions
    // Example: M(1,1) returns row 1 and column 1 of matrix M.
    float& operator ()(int i, int j){
      return (n[j][i]);
    }

    // Index operator with two dimensions
    // Example: M(1,1) returns row 1 and column 1 of matrix M.
    const float& operator ()(int i, int j) const{
      return (n[j][i]);
    }

    // Return a row from a matrix as a vector.
    Vector3D& operator [](int j){
      return (*reinterpret_cast<Vector3D *>(n[j]));
    }

    // Return a row from a matrix as a vector.
    const Vector3D& operator [](int j) const{
      return (*reinterpret_cast<const Vector3D *>(n[j]));
    }

};

// Matrix Multiplication
Matrix3D operator *(const Matrix3D& A, const Matrix3D& B){
  // TODO:
  Matrix3D mat3D;
  mat3D[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0] + A[0][2]*B[2][0];
  mat3D[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1] + A[0][2]*B[2][1];
  mat3D[0][2] = A[0][0]*B[0][2] + A[0][1]*B[1][2] + A[0][2]*B[2][2];
  mat3D[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0] + A[1][2]*B[2][0];
  mat3D[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1] + A[1][2]*B[2][1];
  mat3D[1][2] = A[1][0]*B[0][2] + A[1][1]*B[1][2] + A[1][2]*B[2][2];
  mat3D[2][0] = A[2][0]*B[0][0] + A[2][1]*B[1][0] + A[2][2]*B[2][0];
  mat3D[2][1] = A[2][0]*B[0][1] + A[2][1]*B[1][1] + A[2][2]*B[2][1];
  mat3D[2][2] = A[2][0]*B[0][2] + A[2][1]*B[1][2] + A[2][2]*B[2][2];
    
  return mat3D;
  }


// Matrix multiply by a vector

Vector3D operator *(const Matrix3D& M, const Vector3D& v){
  // TODO:
  Vector3D vec;
  vec.x = Dot(M[0],v);
  vec.y = Dot(M[1],v);
  vec.z = Dot(M[2],v);
  return vec;
}*/


#endif
