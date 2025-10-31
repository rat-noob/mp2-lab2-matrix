#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);
	ASSERT_EQ(m, m1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);

	m1[1][1] = 10;

	ASSERT_NE(m1[1][1], m[1][1]);
}

TEST(TDynamicMatrix, can_get_size)
{
  
	TDynamicMatrix<int> m(5);

	ASSERT_NO_THROW(m.size());
	ASSERT_EQ(m.size(), 5);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(5);
	
	
	ASSERT_NO_THROW(m[1][1] = 10);
	ASSERT_NO_THROW(m[1][1]);
	ASSERT_EQ(m[1][1], 10);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(5);

	ASSERT_ANY_THROW(m[-5]=-5);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(5);

	ASSERT_ANY_THROW(m[4].at(10) = 10);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	ASSERT_NO_THROW(m=m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(5);


	ASSERT_NO_THROW(m1 = m);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(10);
	m = m1;
	ASSERT_EQ(m.size(),10);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(10);

	ASSERT_NO_THROW(m1 = m);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);

	ASSERT_EQ(m1 == m, 1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(5);

	ASSERT_EQ(m == m, 1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(10);

	ASSERT_EQ(m1 == m, 0);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);


	ASSERT_NO_THROW(TDynamicMatrix<int> res = m1 + m);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(10);


	ASSERT_ANY_THROW(TDynamicMatrix<int> res = m1 + m);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);


	ASSERT_NO_THROW(TDynamicMatrix<int> res = m1 - m);
}

TEST(TDynamicMatrix, correct_subtract_matrices)
{
	TDynamicMatrix<int> m(5);
	
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			 m[i][j]=1;
		}
	}
	
	
	m= m * 5;
	int res=0;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			res += m[i][j];
		}
	}
	ASSERT_EQ(res, 125);
}


TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(10);


	ASSERT_ANY_THROW(TDynamicMatrix<int> res = m1 - m);
}

TEST(TDynamicMatrix, can_mul_matrixes_with_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> m1(2);

	for (size_t i = 0; i < m.size(); i++)
	{
		for (size_t j = 0; j < m.size(); j++)
		{
			m[i][j] = 2;
			m1[i][j] = 2;
		}
	}

	ASSERT_NO_THROW(TDynamicMatrix<int> res = m1 * m);

	TDynamicMatrix<int> res = m1 * m;

	int sum=0;
	for (size_t i = 0; i < m.size(); i++)
	{
		for (size_t j = 0; j < m.size(); j++)
		{
			sum += res[i][j];
		}
	}

	ASSERT_EQ(sum, 32);
}

TEST(TDynamicMatrix, cant_mul_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(2);

	


	ASSERT_ANY_THROW(TDynamicMatrix<int> res = m1 * m);

	
}

