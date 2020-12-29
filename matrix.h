#include<iostream>
#include<vector>
#include<cmath>
typedef unsigned int UINT;

class Matrix{
	private:
		UINT itsRows, itsCols;
		std::vector<std::vector<int>> mat;		// 2D vector
		
		void setDimension(UINT rows, UINT cols){
			for(UINT r = 0; r < rows; r++){
				mat.push_back(std::vector<int>(cols));
			}
		}
		
	public:
							//Constructors
		Matrix() : itsRows(0), itsCols(0) {}
		Matrix(UINT rows, UINT cols) :
			itsRows(rows), itsCols(cols)
		{
			std::cout << "Enter values in respective rows and columns;\n";
			for(UINT r = 0; r < rows; r++){
				mat.push_back(std::vector<int>(cols));		//for every row, add a vector of "col" elements.
				for(UINT c = 0; c < cols; c++){
					printf("Row %d, Column %d: ", r+1, c+1);
					std::cin >> mat[r][c];
				}
			}
		}
		~Matrix(){}
		
					//	Accessors
		UINT getCols() const {return itsCols;}
		UINT getRows() const {return itsRows;}
		
		int getSize() const {return itsRows*itsCols;}
		
					//	Overloading Operators
		friend std::ostream& operator<<(std::ostream& stream, const Matrix &rhs){
			for(auto i : rhs.mat){
				for(auto x : i){
					stream << x << "\t";
				}
				stream << std::endl;
			}
			return stream;
		}
		
		Matrix operator+(Matrix &rhs){
			if(itsRows == rhs.itsRows && itsCols == rhs.itsCols){
				for(UINT r = 0; r < itsRows; r++){
					for(UINT c = 0; c < itsCols; c++){
						mat[r][c] = mat[r][c] + rhs.mat[r][c];					
					}
				}
				return *this;
			} else {
				std::cout << "Matrices must have same dimensions\n";
			}
		}
		
		Matrix operator-(Matrix &rhs){
			if(itsRows == rhs.itsRows && itsCols == rhs.itsCols){
				for(UINT r = 0; r < itsRows; r++){
					for(UINT c = 0; c < itsCols; c++){
						mat[r][c] = mat[r][c] - rhs.mat[r][c];					
					}
				}
				return *this;
			} else {
				std::cout << "Matrices must have same dimensions\n";
			} 
		}
		
		Matrix operator*(Matrix &rhs){
			if(itsCols == rhs.itsRows){
				Matrix result;
				result.setDimension(itsRows, rhs.itsCols);
				for(UINT i = 0; i < itsRows; i++){
					for(UINT j = 0; j < rhs.itsCols; j++){
						for(UINT k = 0; k < itsCols; k++){
							result.mat[i][j] += mat[i][k]*rhs.mat[k][j];
						}
					}
				}
				return result;
			} else {
				std::cout << "Cannot perform this matrix multiplicatoin.\n";
			}
		}
		
		Matrix & operator=(const Matrix &rhs){
			if(this==&rhs)
				return *this;
			if(itsRows == rhs.itsRows && itsCols == rhs.itsCols){
				for(UINT i = 0; i < itsRows; i++){
					for(UINT j = 0; j < itsCols; j++){
						mat[i][j] = rhs.mat[i][j];
					}
				}
				return *this;
			}
		}
		
		int det(int n){
			int d = 0;
			Matrix innerMat;
			innerMat.setDimension(itsRows, itsCols);
			if(itsRows == itsCols){
				if(itsRows == 2){
					return (mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0]);
				} else {
					for(int x = 0; x < n; x++){
						int subi = 0;
						for(int i = 1; i < n; i++){
							int subj = 0;
							for(int j = 0; j < n; j++){
								if(j == x)
								continue;
								innerMat.mat[subi][subj] = mat[i][j];
								subj++;
							}
							subi++;
						}
						d = d + (pow(-1, x) * mat[0][x] * det(n-1));
					}
				}
				return d;
			}
		}
		
		/*void dispElements(){
			for(auto i : mat){
				for(auto x : i){
					std::cout << x << "\t";
				}
				std::cout << std::endl;
			}
		}*/
};
