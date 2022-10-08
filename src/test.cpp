#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

class S21MatrixTest : public ::testing::Test {
 protected:
  void SetUp() {
    TestMatrix1 = new S21Matrix(4, 4);
    TestMatrix1->SetValue(0, 0, 3.0);
    TestMatrix1->SetValue(0, 1, -2.0);
    TestMatrix1->SetValue(0, 2, 3.55);
    TestMatrix1->SetValue(0, 3, 4.0);
    TestMatrix1->SetValue(1, 0, 0.0);
    TestMatrix1->SetValue(1, 1, 7.0);
    TestMatrix1->SetValue(1, 2, 0.0);
    TestMatrix1->SetValue(1, 3, -7.0);
    TestMatrix1->SetValue(2, 0, -1.0);
    TestMatrix1->SetValue(2, 1, -1.0);
    TestMatrix1->SetValue(2, 2, -1.0);
    TestMatrix1->SetValue(2, 3, 1.0);
    TestMatrix1->SetValue(3, 0, -2);
    TestMatrix1->SetValue(3, 1, -1);
    TestMatrix1->SetValue(3, 2, 1);
    TestMatrix1->SetValue(3, 3, 2);
    TestMatrix2 = new S21Matrix(4, 4);
    TestMatrix2->SetValue(0, 0, -3.0);
    TestMatrix2->SetValue(0, 1, 2.0);
    TestMatrix2->SetValue(0, 2, -3.55);
    TestMatrix2->SetValue(0, 3, -4.0);
    TestMatrix2->SetValue(1, 0, 0.0);
    TestMatrix2->SetValue(1, 1, -7.0);
    TestMatrix2->SetValue(1, 2, 0.0);
    TestMatrix2->SetValue(1, 3, 7.0);
    TestMatrix2->SetValue(2, 0, 1.0);
    TestMatrix2->SetValue(2, 1, 1.0);
    TestMatrix2->SetValue(2, 2, 1.0);
    TestMatrix2->SetValue(2, 3, -1.0);
    TestMatrix2->SetValue(3, 0, 2);
    TestMatrix2->SetValue(3, 1, 1);
    TestMatrix2->SetValue(3, 2, -1);
    TestMatrix2->SetValue(3, 3, -2);
  }
  void TearDown() {
    delete TestMatrix1;
    delete TestMatrix2;
  }
  double Epsilon = 1.E-13;
  S21Matrix *TestMatrix1;
  S21Matrix *TestMatrix2;
};

TEST(S21MatrixTestConstructor, DefaultConstructor) {
  S21Matrix TestMatrix1;
  ASSERT_EQ(TestMatrix1.GetCols(), 0);
  ASSERT_EQ(TestMatrix1.GetRows(), 0);
  ASSERT_THROW(TestMatrix1(0, 0), std::out_of_range);
}

TEST(S21MatrixTestConstructor, ParametrizedConstructorOne) {
  S21Matrix TestMatrix1(4);
  ASSERT_EQ(TestMatrix1.GetCols(), 4);
  ASSERT_EQ(TestMatrix1.GetRows(), 4);
  for (auto i = 0; i < TestMatrix1.GetCols(); i++)
    for (auto j = 0; j < TestMatrix1.GetRows(); j++)
      ASSERT_EQ(TestMatrix1.GetValue(i, j), 0);
  ASSERT_THROW(S21Matrix TestMatrix2(0), std::out_of_range);
}

TEST(S21MatrixTestConstructor, ParametrizedConstructorTwo) {
  S21Matrix TestMatrix1(4, 5);
  ASSERT_EQ(TestMatrix1.GetCols(), 5);
  ASSERT_EQ(TestMatrix1.GetRows(), 4);
  for (auto i = 0; i < TestMatrix1.GetRows(); i++)
    for (auto j = 0; j < TestMatrix1.GetCols(); j++)
      ASSERT_EQ(TestMatrix1.GetValue(i, j), 0);
  ASSERT_THROW(S21Matrix TestMatrix2(3, -3), std::out_of_range);
}

TEST(S21MatrixTestConstructor, CopyConstructor) {
  S21Matrix TestMatrix2(4, 5);
  S21Matrix TestMatrix(TestMatrix2);
  ASSERT_EQ(TestMatrix.GetCols(), 5);
  ASSERT_EQ(TestMatrix.GetRows(), 4);
  for (auto i = 0; i < TestMatrix.GetRows(); i++)
    for (auto j = 0; j < TestMatrix.GetCols(); j++)
      ASSERT_EQ(TestMatrix.GetValue(i, j), 0);
  ASSERT_EQ(TestMatrix2.GetCols(), 5);
  ASSERT_EQ(TestMatrix2.GetRows(), 4);
  for (auto i = 0; i < TestMatrix2.GetRows(); i++)
    for (auto j = 0; j < TestMatrix2.GetCols(); j++)
      ASSERT_EQ(TestMatrix2.GetValue(i, j), 0);
}

TEST(S21MatrixTestConstructor, MoveConstructor) {
  S21Matrix TestMatrix2(4, 5);
  S21Matrix TestMatrix(std::move(TestMatrix2));
  ASSERT_EQ(TestMatrix.GetCols(), 5);
  ASSERT_EQ(TestMatrix.GetRows(), 4);
  for (auto i = 0; i < TestMatrix.GetRows(); i++)
    for (auto j = 0; j < TestMatrix.GetCols(); j++)
      ASSERT_EQ(TestMatrix.GetValue(i, j), 0);
  ASSERT_EQ(TestMatrix2.GetCols(), 0);
  ASSERT_EQ(TestMatrix2.GetRows(), 0);
}

TEST_F(S21MatrixTest, GetRows) {
  ASSERT_EQ(TestMatrix1->GetRows(), 4);
  ASSERT_EQ(TestMatrix2->GetRows(), 4);
}

TEST_F(S21MatrixTest, GetCols) {
  ASSERT_EQ(TestMatrix1->GetCols(), 4);
  ASSERT_EQ(TestMatrix2->GetCols(), 4);
}

TEST_F(S21MatrixTest, GetValue) {
  ASSERT_EQ(TestMatrix1->GetValue(0, 0), 3.0);
  ASSERT_EQ(TestMatrix1->GetValue(0, 1), -2.0);
  ASSERT_EQ(TestMatrix1->GetValue(0, 2), 3.55);
  ASSERT_EQ(TestMatrix1->GetValue(0, 3), 4.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 0), 0.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 1), 7.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 2), 0.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 3), -7.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 0), -1.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 1), -1.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 2), -1.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 3), 1.0);
  ASSERT_EQ(TestMatrix1->GetValue(3, 0), -2);
  ASSERT_EQ(TestMatrix1->GetValue(3, 1), -1);
  ASSERT_EQ(TestMatrix1->GetValue(3, 2), 1);
  ASSERT_EQ(TestMatrix1->GetValue(3, 3), 2);
  ASSERT_THROW(TestMatrix1->GetValue(3, 4), std::out_of_range);
  ASSERT_THROW(TestMatrix1->GetValue(0, -1), std::out_of_range);
  ASSERT_THROW(TestMatrix1->GetValue(-1, 0), std::out_of_range);
  ASSERT_THROW(TestMatrix1->GetValue(4, 3), std::out_of_range);
}

TEST_F(S21MatrixTest, SetSize) {
  TestMatrix1->SetSize(5, 5);
  ASSERT_EQ(TestMatrix1->GetCols(), 5);
  ASSERT_EQ(TestMatrix1->GetRows(), 5);
  ASSERT_EQ(TestMatrix1->GetValue(0, 0), 3.0);
  ASSERT_EQ(TestMatrix1->GetValue(0, 1), -2.0);
  ASSERT_EQ(TestMatrix1->GetValue(0, 2), 3.55);
  ASSERT_EQ(TestMatrix1->GetValue(0, 3), 4.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 0), 0.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 1), 7.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 2), 0.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 3), -7.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 0), -1.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 1), -1.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 2), -1.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 3), 1.0);
  ASSERT_EQ(TestMatrix1->GetValue(3, 0), -2);
  ASSERT_EQ(TestMatrix1->GetValue(3, 1), -1);
  ASSERT_EQ(TestMatrix1->GetValue(3, 2), 1);
  ASSERT_EQ(TestMatrix1->GetValue(3, 3), 2);
  for (auto i = 0; i < TestMatrix1->GetRows(); i++)
    ASSERT_EQ(TestMatrix1->GetValue(i, 4), 0);
  for (auto j = 0; j < TestMatrix1->GetCols(); j++)
    ASSERT_EQ(TestMatrix1->GetValue(4, j), 0);
  TestMatrix1->SetSize(2, 2);
  ASSERT_EQ(TestMatrix1->GetCols(), 2);
  ASSERT_EQ(TestMatrix1->GetRows(), 2);
  ASSERT_EQ(TestMatrix1->GetValue(0, 0), 3.0);
  ASSERT_EQ(TestMatrix1->GetValue(0, 1), -2.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 0), 0.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 1), 7.0);
  ASSERT_THROW(TestMatrix1->SetRows(0), std::out_of_range);
  ASSERT_THROW(TestMatrix1->SetRows(-1), std::out_of_range);
}

TEST_F(S21MatrixTest, SetRows) {
  TestMatrix1->SetRows(7);
  ASSERT_EQ(TestMatrix1->GetCols(), 4);
  ASSERT_EQ(TestMatrix1->GetRows(), 7);
  for (auto i = 4; i < TestMatrix1->GetRows(); i++)
    for (auto j = 0; j < TestMatrix1->GetCols(); j++)
      ASSERT_EQ(TestMatrix1->GetValue(i, j), 0);
  ASSERT_THROW(TestMatrix1->SetRows(0), std::out_of_range);
}

TEST_F(S21MatrixTest, SetCols) {
  TestMatrix1->SetCols(8);
  ASSERT_EQ(TestMatrix1->GetCols(), 8);
  ASSERT_EQ(TestMatrix1->GetRows(), 4);
  for (auto i = 0; i < TestMatrix1->GetRows(); i++)
    for (auto j = 4; j < TestMatrix1->GetCols(); j++)
      ASSERT_EQ(TestMatrix1->GetValue(i, j), 0);
  ASSERT_THROW(TestMatrix1->SetCols(0), std::out_of_range);
}

TEST_F(S21MatrixTest, SetValue) {
  TestMatrix1->SetValue(0, 0, 15.0);
  ASSERT_EQ(TestMatrix1->GetValue(0, 0), 15.0);
  ASSERT_THROW(TestMatrix1->SetValue(4, 4, 16), std::out_of_range);
  ASSERT_THROW(TestMatrix1->SetValue(-1, 1, 16), std::out_of_range);
  ASSERT_THROW(TestMatrix1->SetValue(1, -1, 16), std::out_of_range);
}

TEST_F(S21MatrixTest, EqMatrix) {
  ASSERT_FALSE(TestMatrix1->EqMatrix(*TestMatrix2));
  TestMatrix1->SumMatrix(*TestMatrix2);
  TestMatrix1->SumMatrix(*TestMatrix2);
  ASSERT_TRUE(TestMatrix1->EqMatrix(*TestMatrix2));
  S21Matrix TestMatrix3(3, 4);
  ASSERT_FALSE(TestMatrix1->EqMatrix(TestMatrix3));
}

TEST_F(S21MatrixTest, SumMatrix) {
  TestMatrix1->SumMatrix(*TestMatrix2);
  for (auto i = 0; i < TestMatrix1->GetRows(); i++)
    for (auto j = 0; j < TestMatrix1->GetCols(); j++)
      ASSERT_EQ(TestMatrix1->GetValue(i, j), 0);
  S21Matrix TestMatrix3(5);
  ASSERT_THROW(TestMatrix1->SumMatrix(TestMatrix3), std::out_of_range);
}

TEST_F(S21MatrixTest, SubMatrix) {
  TestMatrix1->SubMatrix(*TestMatrix2);
  for (auto i = 0; i < TestMatrix1->GetRows(); i++)
    for (auto j = 0; j < TestMatrix1->GetCols(); j++)
      ASSERT_EQ(TestMatrix1->GetValue(i, j), -2 * TestMatrix2->GetValue(i, j));
  S21Matrix TestMatrix3(5);
  ASSERT_THROW(TestMatrix1->SubMatrix(TestMatrix3), std::out_of_range);
}

TEST_F(S21MatrixTest, MulNumber) {
  TestMatrix1->MulNumber(4.5);
  for (auto i = 0; i < TestMatrix1->GetRows(); i++)
    for (auto j = 0; j < TestMatrix1->GetCols(); j++)
      ASSERT_EQ(TestMatrix1->GetValue(i, j),
                -4.5 * TestMatrix2->GetValue(i, j));
}

TEST_F(S21MatrixTest, MulMatrix) {
  TestMatrix1->SetCols(2);
  TestMatrix2->SetRows(2);
  TestMatrix1->MulMatrix(*TestMatrix2);
  ASSERT_EQ(TestMatrix1->GetCols(), 4);
  ASSERT_EQ(TestMatrix1->GetRows(), 4);
  ASSERT_EQ(TestMatrix1->GetValue(0, 0), -9.0);
  ASSERT_EQ(TestMatrix1->GetValue(0, 1), 20.0);
  ASSERT_NEAR(TestMatrix1->GetValue(0, 2), -10.65, Epsilon);
  ASSERT_EQ(TestMatrix1->GetValue(0, 3), -26.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 0), 0.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 1), -49.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 2), 0.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 3), 49.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 0), 3.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 1), 5.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 2), 3.55);
  ASSERT_EQ(TestMatrix1->GetValue(2, 3), -3.0);
  ASSERT_EQ(TestMatrix1->GetValue(3, 0), 6.0);
  ASSERT_EQ(TestMatrix1->GetValue(3, 1), 3.0);
  ASSERT_EQ(TestMatrix1->GetValue(3, 2), 7.1);
  ASSERT_EQ(TestMatrix1->GetValue(3, 3), 1.0);
  S21Matrix TestMatrix3(3);
  ASSERT_THROW(TestMatrix1->MulMatrix(TestMatrix3), std::out_of_range);
}

TEST_F(S21MatrixTest, Transpose) {
  TestMatrix1->SetCols(2);
  S21Matrix TestMatrix3 = TestMatrix1->Transpose();
  ASSERT_EQ(TestMatrix3.GetCols(), 4);
  ASSERT_EQ(TestMatrix3.GetRows(), 2);
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), TestMatrix1->GetValue(j, i));
}

TEST_F(S21MatrixTest, CalcComplements) {
  S21Matrix TestMatrix3(TestMatrix1->CalcComplements());
  ASSERT_NEAR(TestMatrix3.GetValue(0, 0), -7.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(0, 1), -21.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(0, 2), 7.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(0, 3), -21.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 0), -1.55, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 1), -21.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 2), 7.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 3), -15.55, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 0), -10.85, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 1), -70.70, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 2), 49.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 3), -70.70, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 0), 14.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 1), 3.85, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 2), -14.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 3), 3.85, Epsilon);
  S21Matrix TestMatrix4(3, 4);
  ASSERT_THROW(TestMatrix4.CalcComplements(), std::out_of_range);
}

TEST_F(S21MatrixTest, Determinant) {
  ASSERT_NEAR(TestMatrix1->Determinant(), -38.15, Epsilon);
  ASSERT_NEAR(TestMatrix2->Determinant(), -38.15, Epsilon);
  S21Matrix TestMatrix3(3, 4);
  ASSERT_THROW(TestMatrix3.Determinant(), std::out_of_range);
  S21Matrix TestMatrix4(1, 1);
  ASSERT_EQ(TestMatrix4.Determinant(), 0);
}

TEST_F(S21MatrixTest, InverseMatrix) {
  S21Matrix TestMatrix3(TestMatrix1->InverseMatrix());
  ASSERT_NEAR(TestMatrix3.GetValue(0, 0), 20.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(0, 1), 31.0 / 763.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(0, 2), 31.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(0, 3), -40.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 0), 60.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 1), 60.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 2), 202.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 3), -11.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 0), -20.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 1), -20.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 2), -140.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 3), 40.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 0), 60.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 1), 311.0 / 763.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 2), 202.0 / 109.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 3), -11.0 / 109.0, Epsilon);
  S21Matrix TestMatrix4(3, 4);
  ASSERT_THROW(TestMatrix4.InverseMatrix(), std::out_of_range);
  S21Matrix TestMatrix5(1, 1);
  ASSERT_THROW(TestMatrix5.InverseMatrix(), std::out_of_range);
}

TEST_F(S21MatrixTest, OperatorSum) {
  S21Matrix TestMatrix3(4);
  TestMatrix3 = (*TestMatrix1) + (*TestMatrix2);
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), 0);
  S21Matrix TestMatrix4(5);
  ASSERT_THROW(TestMatrix3 + TestMatrix4, std::out_of_range);
}

TEST_F(S21MatrixTest, OperatorSub) {
  S21Matrix TestMatrix3(4);
  TestMatrix3 = (*TestMatrix1) - (*TestMatrix2);
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), 2 * TestMatrix1->GetValue(i, j));
  S21Matrix TestMatrix4(1);
  ASSERT_THROW(TestMatrix4 - TestMatrix3, std::out_of_range);
}

TEST_F(S21MatrixTest, OperatorMultMatrix) {
  S21Matrix TestMatrix3 = (*TestMatrix1) * (*TestMatrix2);
  ASSERT_NEAR(TestMatrix3.GetValue(0, 0), 2.55, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(0, 1), 27.55, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(0, 2), -11.1, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(0, 3), -37.55, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 0), -14.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 1), -56.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 2), 7.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(1, 3), 63.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 0), 4.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 1), 5.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 2), 1.55, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(2, 3), -4.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 0), 11.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 1), 6.0, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 2), 6.1, Epsilon);
  ASSERT_NEAR(TestMatrix3.GetValue(3, 3), -4.0, Epsilon);
  S21Matrix TestMatrix4(3);
  ASSERT_THROW(TestMatrix3 * TestMatrix4, std::out_of_range);
}

TEST_F(S21MatrixTest, OperatorMultNumOne) {
  S21Matrix TestMatrix3 = 6.0 * (*TestMatrix1);
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), 6.0 * TestMatrix1->GetValue(i, j));
}

TEST_F(S21MatrixTest, OperatorMultNumTwo) {
  S21Matrix TestMatrix3 = (*TestMatrix2) * 7.0;
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), 7.0 * TestMatrix2->GetValue(i, j));
}

TEST_F(S21MatrixTest, OperatorEquals) {
  S21Matrix TestMatrix3(*TestMatrix2);
  ASSERT_TRUE(TestMatrix3 == (*TestMatrix2));
  ASSERT_FALSE(TestMatrix3 == (*TestMatrix1));
}

TEST_F(S21MatrixTest, OperatorAssignmentCopy) {
  S21Matrix TestMatrix3;
  TestMatrix3 = (*TestMatrix1);
  ASSERT_EQ(TestMatrix3.GetCols(), 4);
  ASSERT_EQ(TestMatrix3.GetRows(), 4);
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), TestMatrix1->GetValue(i, j));
  ASSERT_EQ(TestMatrix1->GetCols(), 4);
  ASSERT_EQ(TestMatrix1->GetRows(), 4);
  ASSERT_EQ(TestMatrix1->GetValue(0, 0), 3.0);
  ASSERT_EQ(TestMatrix1->GetValue(0, 1), -2.0);
  ASSERT_EQ(TestMatrix1->GetValue(0, 2), 3.55);
  ASSERT_EQ(TestMatrix1->GetValue(0, 3), 4.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 0), 0.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 1), 7.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 2), 0.0);
  ASSERT_EQ(TestMatrix1->GetValue(1, 3), -7.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 0), -1.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 1), -1.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 2), -1.0);
  ASSERT_EQ(TestMatrix1->GetValue(2, 3), 1.0);
  ASSERT_EQ(TestMatrix1->GetValue(3, 0), -2);
  ASSERT_EQ(TestMatrix1->GetValue(3, 1), -1);
  ASSERT_EQ(TestMatrix1->GetValue(3, 2), 1);
  ASSERT_EQ(TestMatrix1->GetValue(3, 3), 2);
  ASSERT_NO_THROW(TestMatrix3 = TestMatrix3);
}

TEST_F(S21MatrixTest, OperatorAssignmentMove) {
  S21Matrix TestMatrix3 = (*TestMatrix1);
  S21Matrix TestMatrix4;
  TestMatrix4 = (std::move(TestMatrix3));
  ASSERT_EQ(TestMatrix4.GetCols(), 4);
  ASSERT_EQ(TestMatrix4.GetRows(), 4);
  ASSERT_EQ(TestMatrix3.GetCols(), 0);
  ASSERT_EQ(TestMatrix3.GetRows(), 0);
  for (auto i = 0; i < TestMatrix4.GetRows(); i++)
    for (auto j = 0; j < TestMatrix4.GetCols(); j++)
      ASSERT_EQ(TestMatrix4.GetValue(i, j), TestMatrix1->GetValue(i, j));
  ASSERT_NO_THROW(TestMatrix4 = (std::move(TestMatrix4)));
}

TEST_F(S21MatrixTest, OperatorSumAssignment) {
  S21Matrix TestMatrix3(4);
  TestMatrix3 += (*TestMatrix1);
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), TestMatrix1->GetValue(i, j));
  TestMatrix3 += (*TestMatrix2);
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), 0);
  S21Matrix TestMatrix4(3);
  ASSERT_THROW(TestMatrix4 += (*TestMatrix1), std::out_of_range);
}

TEST_F(S21MatrixTest, OperatorSubAssignment) {
  S21Matrix TestMatrix3(4);
  TestMatrix3 -= (*TestMatrix1);
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), TestMatrix2->GetValue(i, j));
  TestMatrix3 -= (*TestMatrix2);
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), 0);
  S21Matrix TestMatrix4(3);
  ASSERT_THROW(TestMatrix4 -= (*TestMatrix1), std::out_of_range);
}

TEST_F(S21MatrixTest, OperatorMultMatrixAssignment) {
  S21Matrix TestMatrix3(4);
  TestMatrix3.SetValue(0, 0, 1.0);
  TestMatrix3.SetValue(1, 1, 1.0);
  TestMatrix3.SetValue(2, 2, 1.0);
  TestMatrix3.SetValue(3, 3, 1.0);
  TestMatrix3 *= (*TestMatrix2);
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), TestMatrix2->GetValue(i, j));
  S21Matrix TestMatrix4(4);
  TestMatrix3 *= TestMatrix4;
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), 0);
  S21Matrix TestMatrix5(3);
  ASSERT_THROW(TestMatrix4 *= TestMatrix5, std::out_of_range);
}

TEST_F(S21MatrixTest, OperatorMultNumAssignment) {
  S21Matrix TestMatrix3(*TestMatrix1);
  TestMatrix3 *= 6.0;
  for (auto i = 0; i < TestMatrix3.GetRows(); i++)
    for (auto j = 0; j < TestMatrix3.GetCols(); j++)
      ASSERT_EQ(TestMatrix3.GetValue(i, j), 6.0 * TestMatrix1->GetValue(i, j));
}

TEST_F(S21MatrixTest, OperatorBrackets) {
  for (auto i = 0; i < TestMatrix1->GetRows(); i++)
    for (auto j = 0; j < TestMatrix1->GetCols(); j++)
      ASSERT_EQ((*TestMatrix1)(i, j), TestMatrix1->GetValue(i, j));
  ASSERT_THROW((*TestMatrix1)(5, 4), std::out_of_range);
  ASSERT_THROW((*TestMatrix1)(4, 5), std::out_of_range);
  ASSERT_THROW((*TestMatrix1)(-1, 0), std::out_of_range);
  ASSERT_THROW((*TestMatrix1)(0, -1), std::out_of_range);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
