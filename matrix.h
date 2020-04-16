#include<iostream>
#include<vector>
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
		Matrix(){}
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
				Matrix result;
				result.setDimension(itsRows, itsCols);
				for(UINT r = 0; r < itsRows; r++){
					for(UINT c = 0; c < itsCols; c++){
						result.mat[r][c] = mat[r][c] + rhs.mat[r][c];					
					}
				}
				return result;
			} else {
				std::cout << "Matrices must have same dimensions\n";
			}
		}
		
		Matrix operator-(Matrix &rhs){
			if(itsRows == rhs.itsRows && itsCols == rhs.itsCols){
				Matrix result;
				result.setDimension(itsRows, itsCols);
				for(UINT r = 0; r < itsRows; r++){
					for(UINT c = 0; c < itsCols; c++){
						result.mat[r][c] = mat[r][c] - rhs.mat[r][c];					
					}
				}
				return result;
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
		
		/*void dispElements(){
			for(auto i : mat){
				for(auto x : i){
					std::cout << x << "\t";
				}
				std::cout << std::endl;
			}
		}*/
};
