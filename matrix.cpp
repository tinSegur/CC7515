#include "matrix.h"


//Matrix constructors

Matrix::Matrix() {
	this->n = 0;
	this->m = 0;
	this->mat = nullptr;
}

Matrix::Matrix(int n) {
	this->n = 1;
	this->m = n;
	this->mat = std::unique_ptr<double>(new double[n * m]);
}

Matrix::Matrix(int n, int m) {
	this->n = n;
	this->m = m;
	this->mat = std::unique_ptr<double>(new double[n * m]);
}

Matrix::Matrix(const std::string& filename) {
	std::ifstream file;
	file.open(filename, std::ios::in);

	if (!file.is_open()) {
		std::cerr << "Error: file not found" << std::endl;
		exit(1);
	}


	file.close();
}

Matrix::Matrix(const Matrix& matrix) {
	this->n = matrix.n;
	this->m = matrix.m;
	this->mat = std::unique_ptr<double>(new double[n * m]);
	for (int i = 0; i < n * m; i++) {
		this->mat.get()[i] = matrix.mat.get()[i];
	}
}

Matrix::~Matrix() {
	delete[] this->mat.get();
}

// Dimensions
std::tuple<int, int>& Matrix::size() const {
    std::tuple<int, int> ret = std::tuple<int, int>(this->n, this->m);
    return ret;
}

int Matrix::length() const {
    return std::max(this->n, this->m);
}

double Matrix::max() const {
    double ret = mat.get()[0];
    for (int i = 1; i < this->m*this->n; i++){
        ret = (ret > mat.get()[i]) ? ret : mat.get()[i];
    }

    return ret;
}

double Matrix::min() const {
    double ret = mat.get()[0];
    for (int i = 1; i < this->m*this->n; i++){
        ret = (ret < mat.get()[i]) ? ret : mat.get()[i];
    }

    return ret;
}

// Utility

std::ostream& operator<<(std::ostream& os, const Matrix& mat){
    os << "[";

    for (int i = 0; i < mat.n; i++){
        for (int j = 0; j < mat.m; j++){
            os << " " << mat.mat.get()[i*mat.m + j] << " ";
        }
        os << "\n";
    }

    os << "]";

    return os;
}

void Matrix::save_to_file(const std::string & filename) const {

}




