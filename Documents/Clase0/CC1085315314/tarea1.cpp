#include <iostream>
#include <cstdlib>

using namespace std;
template <typename T>
class Matriz {
private:
    T* matrix;
    int rows, cols;
public:
    // Constructor
    Matriz(int n, int m) : rows(n), cols(m) {
        matrix = new T[rows * cols];
    }

    // Constructor de copia
    Matriz(const Matriz<T>& other) {
        rows = other.rows;
        cols = other.cols;
        matrix = new T[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            matrix[i] = other.matrix[i];
        }
    }

    // Destructor
    ~Matriz() {
        delete[] matrix;
    }

    // Método para establecer el valor en una posición de la matriz
    void set(int i, int j, T value) {
        matrix[i * cols + j] = value;
    }

    // Método para obtener el valor en una posición de la matriz
    T get(int i, int j) const {
        return matrix[i * cols + j];
    }

    // Sobrecarga del operador de asignación
    Matriz<T>& operator=(const Matriz<T>& other) {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            delete[] matrix;
            matrix = new T[rows * cols];
            for (int i = 0; i < rows * cols; i++) {
                matrix[i] = other.matrix[i];
            }
        }
        return *this;
    }

    // Sobrecarga del operador de suma
    Matriz<T> operator+(const Matriz<T>& other) const {
        Matriz<T> result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.matrix[i] = matrix[i] + other.matrix[i];
        }
        return result;
    }

    // Sobrecarga del operador de resta
    Matriz<T> operator-(const Matriz<T>& other) const {
        Matriz<T> result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.matrix[i] = matrix[i] - other.matrix[i];
        }
        return result;
    }

    // Sobrecarga del operador de asignación y suma
    Matriz<T>& operator+=(const Matriz<T>& other) {
        for (int i = 0; i < rows * cols; i++) {
            matrix[i] += other.matrix[i];
        }
        return *this;
    }

    // Sobrecarga del operador de asignación y resta
    Matriz<T>& operator-=(const Matriz<T>& other) {
        for (int i = 0; i < rows * cols; i++) {
            matrix[i] -= other.matrix[i];
        }
        return *this;
    }
// Método para imprimir la matriz
void print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i * cols + j] << " ";
        }
        cout << endl;
    }
}
    // Método para obtener la transpuesta de la matriz
    Matriz<T> transpose() const {
        Matriz<T> result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.set(j, i, get(i, j));
            }
        }
        return result;
    }
};

int main() {
    

    Matriz<int> m(3, 3); // En este caso la matriz es 3x3 puedes ser de una dimension simpre q sea viable las operaciones.
    Matriz<int> n(3, 3);
    
  

    
    m.set(0, 0, 1); // ejemplo del codigo 
    m.set(0, 1, 1);
    m.set(0, 2, 2);
    m.set(1, 0, 1);
    m.set(1, 1, 1);
    m.set(1, 2, 2);
    m.set(2, 0, 1);
    m.set(2, 1, 15);
    m.set(2, 2, 0);
    
    n.set(0, 0, 10);
    n.set(0, 1, 1);
    n.set(0, 2, 2);
    n.set(1, 0, 0);
    n.set(1, 1, 1);
    n.set(1, 2, 2);
    n.set(2, 0, 19);
    n.set(2, 1, 1);
    n.set(2, 2, 0);
    
    cout << "Matriz m:" << endl;
    m.print();
    cout << "Matriz n:" << endl;
    n.print();
    
    Matriz<int> suma = m + n;
    Matriz<int> resta = m - n;

    
    Matriz<int> transpuestam = m.transpose();
    Matriz<int> transpuestan = n.transpose();
   
    cout << "Suma:" << endl;
    suma.print();
    
    cout << "Resta:" << endl;
    resta.print();

    cout << "Transpuesta m:" << endl;
    transpuestam.print();
    cout << "Transpuesta n:" << endl;
    transpuestan.print();
    
    

    return 0;
}



