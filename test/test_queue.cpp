#include "..\mp2-lab4-queue\TQueue.h"

#include <string>
#include "gtest.h"



TEST(
	, can_create_queue_with_positive_size)			//создаем очередь с "+" размером
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, throws_when_create_queue_with_negative_size)	// создаем очередь с "-" размером
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, can_create_copied_queue)						// можно создать копию очереди 
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);			// заполняем очередь
		i++;
	}
	ASSERT_NO_THROW(TQueue<int> q1(q));		// создаем копию и проверяем что она создалась
}

TEST(TQueue, copied_queue_is_equal_to_source_one)		// проверка что копия очереди равна исходной
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
		i++;
	}
	TQueue<int> q1(q);
	while (!(q.isEmpty()) && !(q1.isEmpty()))
	{
		EXPECT_EQ(q.Pop(), q1.Pop());
	}
}

TEST(TQueue, copied_queue_has_its_own_memory)		// наличие собственной памяти у копии
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
		i++;
	}
	TQueue<int> q1(q);
	EXPECT_EQ(0, &q == &q1);
}



TEST(TQueue, can_assign_stack_to_itself)		// проверка на правильность присваивания
{
	TQueue<int> q(5);
	ASSERT_NO_THROW(q = q);
}

TEST(TQueue, can_assign_queues_of_equal_size)		// присваивание одной очереди другой с равными размерами
{
	TQueue<int> q(5);
	TQueue<int> q1(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	int k = 1;
	while (!(q1.isFull()))
	{
		q1.Push(k + 1);
	}
	ASSERT_NO_THROW(q = q1);
	q = q1;
	while (!(q.isEmpty()) && !(q1.isEmpty()))
	{
		EXPECT_EQ(q.Pop(), q1.Pop());
	}
}

TEST(TQueue, can_assign_queues_of_different_size)		// присваивание очередей с разными размерами
{
	TQueue<int> q(5);
	TQueue<int> q1(10);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	int k = 1;
	while (!(q1.isFull()))
	{
		q1.Push(k);
	}
	ASSERT_NO_THROW(q = q1);
	q = q1;
	while (!(q.isEmpty()) && !(q1.isEmpty()))
	{
		EXPECT_EQ(q.Pop(), q1.Pop());
	}
}

TEST(TQueue, new_queue_is_Empty)		// новая очередь пуста
{
	TQueue<int> q(5);
	EXPECT_EQ(true, q.isEmpty());
}

TEST(TQueue, queue_with_elements_is_not_Empty)		// очередь не пуста
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(false, q.isEmpty());
}

TEST(TQueue, filled_queue_is_Full)		// очередь полная
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	EXPECT_EQ(true, q.isFull());
}

TEST(TQueue, not_filled_queue_is_not_Full)		// очередь не полная
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(false, q.isFull());
}


TEST(TQueue, can_not_get_Front_from_Empty_stack)		//нельзя получить доступ к Front
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.Front());
}

TEST(TQueue, can_get_right_Front)		//верный верхний элемент
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(1, q.Front());
}

TEST(TQueue, can_not_get_Back_from_isEmpty_stack)		// нельзя взять нижний элемент
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.Back());
}

TEST(TQueue, can_get_right_Back)		// верный нижний элемент
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(2, q.Back());
}

TEST(TQueue, can_get_right_head_index)		// верный индекс начала
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	int tmp = q.Pop();
	EXPECT_EQ(1, q.GetHeadIndex());
}

TEST(TQueue, can_get_right_now_size)		// верный текущий размер очереди
{
	TQueue<int> q(5);
	q.Push(0);
	q.Push(1);
	q.Push(2);
	int tmp = q.Pop();
	EXPECT_EQ(2, q.GetSizeNow());
}

TEST(TQueue, can_get_right_max_size)		// верный максимальный размер очереди
{
	TQueue<int> q(5);
	EXPECT_EQ(5, q.GetMaxSize());
}

TEST(TQueue, can_correctly_compare_two_equal_queues)		//сравнение двух очередей на равенство
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	TQueue<int> q1(5);
	int k = 1;
	while (!(q1.isFull()))
	{
		q1.Push(k);
	}
	EXPECT_EQ(true, q == q1);
}

TEST(TQueue, can_correctly_compare_two_not_equal_queues)		// проверка на неравенство очередей с разным содержимым
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	TQueue<int> q1(5);
	int k = 1;
	while (!(q1.isFull()))
	{
		q1.Push(k + 1);
	}
	EXPECT_EQ(true, q != q1);
}

TEST(TQueue, can_push)		// можно добавить элемент
{
	TQueue<int> q(5);
	ASSERT_NO_THROW(q.Push(1));
}

TEST(TQueue, can_pop)		// можно извлечь элемент
{
	TQueue<int> q(5);
	q.Push(1);
	ASSERT_NO_THROW(q.Pop());
}

TEST(TQueue, can_not_push_to_Full_queue)		// нельзя добавить, переполнено
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	ASSERT_ANY_THROW(q.Push(1));
}

TEST(TQueue, can_not_pop_from_Empty_queue)		// нельзя извлечь, пусто
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.Pop());
}
