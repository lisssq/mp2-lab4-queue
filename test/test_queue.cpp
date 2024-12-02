#include "..\mp2-lab4-queue\queue.h"

#include <string>
#include "gtest.h"


// переписать названия тестов и вообще хорошенько их пересмотреть

TEST(Queue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(Queue<int> q(5));
}

TEST(Queue, throws_when_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(Queue<int> q(-5));
}

TEST(Queue, can_create_copied_queue)
{
	Queue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
		i++;
	}
	ASSERT_NO_THROW(Queue<int> q1(q));
}

TEST(Queue, copied_queue_is_equal_to_source_one)
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

TEST(Queue, copied_queue_has_its_own_memory)
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

TEST(Queue, can_correctly_compare_two_equal_queues)
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

TEST(Queue, can_correctly_compare_two_not_equal_queues)
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

TEST(Queue, can_assign_stack_to_itself)
{
	Queue<int> q(5);
	ASSERT_NO_THROW(q = q);
}

TEST(Queue, can_assign_queues_of_equal_size)
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

TEST(Queue, can_assign_queues_of_different_size)
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

TEST(Queue, new_queue_is_isEmpty)
{
	Queue<int> q(5);
	EXPECT_EQ(true, q.isEmpty());
}

TEST(Queue, queue_with_elements_is_not_isisEmpty)
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(false, q.isEmpty());
}

TEST(Queue, filled_queue_is_isFull)
{
	Queue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	EXPECT_EQ(true, q.isFull());
}

TEST(Queue, not_filled_queue_is_not_isFull)
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(false, q.isFull());
}


TEST(Queue, can_push)
{
	Queue<int> q(5);
	ASSERT_NO_THROW(q.Push(1));
}

TEST(Queue, can_pop)
{
	Queue<int> q(5);
	q.Push(1);
	ASSERT_NO_THROW(q.Pop());
}

TEST(Queue, can_not_push_to_filled_queue)
{
	Queue<int> q(5);
	int i = 1;
	while (!(q.isFull()))
	{
		q.Push(i);
	}
	ASSERT_ANY_THROW(q.Push(1));
}

TEST(Queue, can_not_pop_from_isEmpty_queue)
{
	Queue<int> q(5);
	ASSERT_ANY_THROW(q.Pop());
}

TEST(Queue, can_not_get_Front_from_isEmpty_stack)
{
	Queue<int> q(5);
	ASSERT_ANY_THROW(q.Front());
}

TEST(Queue, can_get_right_Front)
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(1, q.Front());
}

TEST(Queue, can_not_get_Back_from_isEmpty_stack)
{
	Queue<int> q(5);
	ASSERT_ANY_THROW(q.Back());
}

TEST(Queue, can_get_right_Back)
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(2, q.Back());
}

TEST(Queue, can_get_right_head_index)
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	int tmp = q.Pop();
	EXPECT_EQ(1, q.GetHeadIndex());
}

TEST(Queue, can_get_right_current_size)
{
	Queue<int> q(5);
	q.Push(0);
	q.Push(1);
	q.Push(2);
	int tmp = q.Pop();
	EXPECT_EQ(2, q.GetSizeNow());
}

TEST(Queue, can_get_right_max_size)
{
	Queue<int> q(5);
	EXPECT_EQ(5, q.MaxSize());
}