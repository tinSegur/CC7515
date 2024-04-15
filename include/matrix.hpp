#include <cstddef>
#include <memory>
#include <ostream>
#include <string>
#include <tuple>
#include <fstream>
#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <sstream>

class Matrix {
	private:
		std::unique_ptr<double[]> mat; // Store the matrix
        int n = 0; // Number of rows
        int m = 0; // Number of columns
	public:
		//Constructors 
		Matrix(); // Empty constructor
		Matrix(int n); // Constructor, vector like[1xn]
		Matrix(int n, int m); // Constructor[nxm], n : rows, m : columns
		Matrix(const std::string& filename); // Constructor that reads from a file,
                                            // any format is valid
		Matrix(const Matrix	& matrix); // Copy constructor,
						                // https://www.geeksforgeeks.org/copy-constructor-in-cpp/
		~Matrix(); // Destructor


		// Setters and getters
		double& operator[](std::size_t x, std::size_t y) { // Set value to(i, j) < row, column >
			if ( x >= n | y >= m) {
				throw std::range_error("Index out of bounds");
			}

			return mat.get()[x * m + y];
		}


		double operator[](std::size_t x, std::size_t y) const { // Get value from(i, j) < row, column >
			if (x >= this->n | y >= this->m) {
				throw std::range_error("Index out of bounds");
			}
			return mat.get()[x * m + y];
		}


		void fill(double value) { // Fill all the matrix with a value
			for (int i = 0; i < n * m; i++) {
				mat.get()[i] = value;
			}
		}

		// Dimensions
		std::tuple<int, int> size() const; // Returns a list of the size of the
											// matrix, e.g.[2, 4], 2 rows, 4 columns
		int length()
			const; // Return max dimension, usefull for vectors, e.g.[2, 4] : > 4
		// Values
		double max() const; // Maximum value of the matrix
		double min() const; // Minimum value of the matrix
		
		// Utilitary functions

		friend std::ostream& operator<< (std::ostream & os, const Matrix & mat); // Display matrix to console
		void save_to_file(const std::string & filename) const; // Save matrix to a file, any format is valid
			
		// Booleans
		bool operator== (const Matrix & matrix) const { // Equal operator
            if (this->n != matrix.n or this->m != matrix.m) return false;

            for (int i = 0; i<this->m*this->n; i++){
                if (this->mat.get()[i] != matrix.mat.get()[i]){
                    return false;
                }
            }

            return true;
        }

		bool operator!= (const Matrix & matrix) const{ // Not-equal operator
            if (this->n != matrix.n or this->m != matrix.m) return true;

            for (int i = 0; i<this->m*this->n; i++){
                if (this->mat.get()[i] != matrix.mat.get()[i]){
                    return true;
                }
            }

            return false;
        }

		// Mathematical operation
		Matrix &operator=(const Matrix & matrix) { // Assignment operator
            this->n = matrix.n;
            this->m = matrix.m;

			this->mat.release();
            this->mat = std::make_unique<double[]>(n*m);

            for (int i = 0; i < this->n*this->m; i++){
                this->mat.get()[i] = matrix.mat.get()[i];
            }

            return *this;
        }

		Matrix &transpose(); // Transpose the matrix

		Matrix &operator*=(const Matrix & matrix) { // Multiplication
            if (this->m != matrix.n){
                throw std::length_error("Matrix dims don't match up correctly");
            }

            std::unique_ptr<double[]> new_mat = std::make_unique<double[]>(n*m);

            for (int i = 0; i < this->n; i++){
                for (int j = 0; j < matrix.m; j++){
                	new_mat.get()[i*this->m + j] = 0;
                    for (int k = 0; k < this->m; k++) {
                        new_mat.get()[i * this->m + j] += (*this)[i, k] * matrix[k, j];
                    }
                }
            }

            this->m = matrix.m;
            this->mat.swap(new_mat);

            return *this;
        }

		Matrix &operator*=(double a){// Multiply by a constant
            for (int i = 0; i < this->n*this->m; i++){
                this->mat.get()[i] *= a;
            }

            return *this;
        }


		Matrix &operator+=(const Matrix & matrix){ // Add

			if (this->size() != matrix.size()) {
				throw std::logic_error("Matrix sizes must match");
			}

            for (int i = 0; i < this->n*this->m; i++){
                this->mat.get()[i] += matrix.mat.get()[i];
            }

            return *this;
        }


		Matrix &operator-=(const Matrix & matrix) { // Substract

			if (this->size() != matrix.size()) {
				throw std::logic_error("Matrix sizes must match");
			}

			for (int i = 0; i < this->n*this->m; i++){
                this->mat.get()[i] -= matrix.mat.get()[i];
            }

            return *this;
        }

};