
#include "matrix.hpp"

//Matrix constructors

Matrix::Matrix() {
	this->n = 0;
	this->m = 0;
	mat = nullptr;
}

Matrix::Matrix(int n) {
	this->n = 1;
	this->m = n;
	mat = std::make_unique<double[]>(n*m);
}

Matrix::Matrix(int n, int m) {
	this->n = n;
	this->m = m;
	mat = std::make_unique<double[]>(n*m);
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

    n = std::stoi(line.substr(0, p));
    line.erase(line.begin(), line.begin()+ p + 1);

    p = line.find("\n");
    m = std::stoi(line.substr(0, p));

    mat = std::make_unique<double[]>(n*m);

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
	this->mat = std::make_unique<double[]>(n*m);
	for (int i = 0; i < n * m; i++) {
		this->mat.get()[i] = matrix.mat.get()[i];
	}
}

Matrix::~Matrix() {
	mat.reset();
}

// Dimensions
std::tuple<int, int> Matrix::size() const {
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
    os << "\n[\n\t";

    for (int i = 0; i < mat.n; i++){
        for (int j = 0; j < mat.m; j++){
            os << " " << mat.mat.get()[i*mat.m + j] << " ";
        }

    	if (i < (mat.n-1)) {
    		os << "\n\t";
    	}

    }

    os << "\n]";

    return os;
}

void Matrix::save_to_file(const std::string & filename) const {
    std::ofstream out;
    out.open(filename);

    out << this->n << " " << this->m << "\n";

    for (size_t i = 0; i < this->n; i++){
        for (size_t j = 0; j < this->m; j++){
            out << (*this)[i, j] << " ";
        }
        out << "\n";
    }

}

Matrix& Matrix::transpose() {

    double buffer;

	std::unique_ptr<double[]> nw = std::make_unique<double[]>(n*m);

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			nw[j*m + i] = mat.get()[i*n + j];
		}
	}

	int b = n;
	n = m;
	m = b;

	mat.swap(nw);
	nw.release();

	return *this;
}




