
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

    std::string line;
    std::vector<std::string> splitline = {};
    std::getline(file, line);

    int p = line.find(" ");

    this->n = std::stoi(line.substr(0, p));
    line.erase(line.begin(), line.begin()+ p + 1);

    p = line.find("\n");
    this->m = std::stoi(line.substr(0, p));

    this->mat = std::unique_ptr<double>(new double[this->n*this->m]);

    for (int i = 0; i < this->n; i++){
        std::getline(file, line);

        for (int j = 0; j < this->m; j++){
            p = line.find(" ");
            (*this)[i, j] = std::stod(line.substr(0, p));
            line.erase(line.begin(), line.begin() + p + 1);
        }

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
    std::ofstream out;
    out.open(filename);

    out << this->n << " " << this->m << "\n";

    for (size_t i = 0; i < this->n; i++){
        for (size_t j = 0; j < this->m; j++){
            out << this[i, j] << " ";
        }
        out << "\n";
    }

}

Matrix& Matrix::transpose() {

    double buffer;
	for (size_t i = 0; i < this->n; i++) {
		for (size_t j = 0; j < i; j++) {
			buffer = this->mat.get()[i*this->m + j];
            this->mat.get()[i*this->m + j] = this->mat.get()[j*this->m + i];
            this->mat.get()[j*this->m + i] = buffer;
		}
	}

	return *this;
}




