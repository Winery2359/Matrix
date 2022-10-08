#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;
  void AllocateMatrixMemory();
  void FreeMatrixMemory();
  void NullMatrix();
  void CheckEqMatrixSize(int rows, int cols) const;
  void CheckMatrixSquareSize() const;
  void CheckIndexInRange(int row, int col) const;

 public:
  S21Matrix();
  explicit S21Matrix(int rows);
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;
  ~S21Matrix();

  int GetRows() const;
  int GetCols() const;
  double GetValue(int row, int col) const;

  void SetSize(int rows, int cols);
  void SetRows(int rows);
  void SetCols(int cols);
  void SetValue(int row, int col, double value);

  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant() const;
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(const double x) const;
  friend S21Matrix operator*(const double x, const S21Matrix &other);
  bool operator==(const S21Matrix &other) const;
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator=(S21Matrix &&other) noexcept;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(double x);
  double &operator()(int row, int col) const;
};

S21Matrix operator*(const double x, const S21Matrix &other);

#endif  // SRC_S21_MATRIX_OOP_H_