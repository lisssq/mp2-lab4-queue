#include "..\mp2-lab4-queue\queue.h"

#include <string>
#include "gtest.h"



TEST(Queue, can_create_queue_with_positive_size)			//создаем очередь с "+" размером
{
	ASSERT_NO_THROW(Queue<int> q(5));
}

TEST(Queue, throws_when_create_queue_with_negative_size)	// создаем очередь с "-" размером
{
	ASSERT_ANY_THROW(Queue<int> q(-5));
}

TEST(Queue, can_create_copied_queue)						// можно создать копию очереди 
{
	Queue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);			// заполняем очередь
		i++;
	}
	ASSERT_NO_THROW(Queue<int> q1(q));		// создаем копию и проверяем что она создалась
}

TEST(Queue, copied_queue_is_equal_to_source_one)		// проверка что копия очереди равна исходной
{
	Queue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
		i++;
	}
	Queue<int> q1(q);
	while (!(q.isEmpty()) && !(q1.isEmpty()))
	{
		EXPECT_EQ(q.Pop(), q1.Pop());
	}
}

TEST(Queue, copied_queue_has_its_own_memory)		// наличие собственной памяти у копии
{
	Queue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
		i++;
	}
	Queue<int> q1(q);
	EXPECT_EQ(0, &q == &q1);
}



TEST(Queue, can_assign_stack_to_itself)		// проверка на правильность присваивания
{
	Queue<int> q(5);
	ASSERT_NO_THROW(q = q);
}

TEST(Queue, can_assign_queues_of_equal_size)		// присваивание одной очереди другой с равными размерами
{
	Queue<int> q(5);
	Queue<int> q1(5);
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

TEST(Queue, can_assign_queues_of_different_size)		// присваивание очередей с разными размерами
{
	Queue<int> q(5);
	Queue<int> q1(10);
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

TEST(Queue, new_queue_is_Empty)		// новая очередь пуста
{
	Queue<int> q(5);
	EXPECT_EQ(true, q.isEmpty());
}

TEST(Queue, queue_with_elements_is_not_Empty)		// очередь не пуста
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(false, q.isEmpty());
}

TEST(Queue, filled_queue_is_Full)		// очередь полная
{
	Queue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	EXPECT_EQ(true, q.isFull());
}

TEST(Queue, not_filled_queue_is_not_Full)		// очередь не полная
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(false, q.isFull());
}


TEST(Queue, can_not_get_Front_from_Empty_stack)		//нельзя получить доступ к Front
{
	Queue<int> q(5);
	ASSERT_ANY_THROW(q.Front());
}

TEST(Queue, can_get_right_Front)		//верный верхний элемент
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(1, q.Front());
}

TEST(Queue, can_not_get_Back_from_isEmpty_stack)		// нельзя взять нижний элемент
{
	Queue<int> q(5);
	ASSERT_ANY_THROW(q.Back());
}

TEST(Queue, can_get_right_Back)		// верный нижний элемент
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(2, q.Back());
}

TEST(Queue, can_get_right_head_index)		// верный индекс начала
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	int tmp = q.Pop();
	EXPECT_EQ(1, q.GetHeadIndex());
}

TEST(Queue, can_get_right_now_size)		// верный текущий размер очереди
{
	Queue<int> q(5);
	q.Push(0);
	q.Push(1);
	q.Push(2);
	int tmp = q.Pop();
	EXPECT_EQ(2, q.GetSizeNow());
}

TEST(Queue, can_get_right_max_size)		// верный максимальный размер очереди
{
	Queue<int> q(5);
	EXPECT_EQ(5, q.MaxSize());
}

TEST(Queue, can_correctly_compare_two_equal_queues)		//сравнение двух очередей на равенство
{
	Queue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	Queue<int> q1(5);
	int k = 1;
	while (!(q1.isFull()))
	{
		q1.Push(k);
	}
	EXPECT_EQ(true, q == q1);
}

TEST(Queue, can_correctly_compare_two_not_equal_queues)		// проверка на неравенство очередей с разным содержимым
{
	Queue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	Queue<int> q1(5);
	int k = 1;
	while (!(q1.isFull()))
	{
		q1.Push(k + 1);
	}
	EXPECT_EQ(true, q != q1);
}

TEST(Queue, can_push)		// можно добавить элемент
{
	Queue<int> q(5);
	ASSERT_NO_THROW(q.Push(1));
}

TEST(Queue, can_pop)		// можно извлечь элемент
{
	Queue<int> q(5);
	q.Push(1);
	ASSERT_NO_THROW(q.Pop());
}

TEST(Queue, can_not_push_to_Full_queue)		// нельзя добавить, переполнено
{
	Queue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	ASSERT_ANY_THROW(q.Push(1));
}

TEST(Queue, can_not_pop_from_Empty_queue)		// нельзя извлечь, пусто
{
	Queue<int> q(5);
	ASSERT_ANY_THROW(q.Pop());
}
