#include<iostream>
#include<vector>

class Matrix{
	private:
		unsigned int const itsRows, itsCols;
		std::vector<std::vector<int>> mat;
	public:
		Matrix(unsigned int cols, unsigned rows) :
			itsRows(rows), itsCols(cols)
		{
			mat.resize(itsCols, std::vector<int>(itsRows));
			std::cout << "Enter values in respective rows and columns;\n";
			for(unsigned int r = 0; r < rows; r++){
				for(unsigned int c = 0; c < cols; c++){
					printf("Row %d, Column %d: ", r+1, c+1);
					std::cin >> mat[r][c];
				}
			}
		}
		~Matrix(){}
		
		unsigned int getCols() const {return itsCols;}
		unsigned int getRows() const {return itsRows;}
		
		void changeElement(int row, int col, int num){
			mat[row][col] = num;
		}
		
		int getSize() const {return itsRows*itsCols;}
};
