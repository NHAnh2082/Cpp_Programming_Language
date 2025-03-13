/**************************************************************************
 * @file    Queue_Circular.hpp
 * @brief   Định nghĩa lớp hàng đợi vòng (Circular Queue) sử dụng mảng động.
 * @version 1.0
 * @date    2025-01-10
 * @author  Nguyễn Văn Thưởng
 *************************************************************************/

#ifndef QUEUE_CIRCULAR_HPP
#define QUEUE_CIRCULAR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;


/**
 * @class Queue
 * @brief Lớp template mô phỏng hàng đợi vòng (FIFO).
 * @tparam T Kiểu dữ liệu của phần tử trong hàng đợi.
 */
template <typename T>
class Queue 
{
    private:
        unique_ptr<T[]> items;  /**< Con trỏ thông minh quản lý bộ nhớ động */
        int size;               /**< Kích thước tối đa của hàng đợi */
        int front;              /**< Chỉ số phần tử đầu hàng đợi */
        int rear;               /**< Chỉ số phần tử cuối hàng đợi */

    public:
        /**
         * @brief Khởi tạo hàng đợi vòng với kích thước nhất định.
         * @param capacity Kích thước tối đa của hàng đợi.
         */
        Queue(int capacity) : size(capacity), front(-1), rear(-1), items(std::make_unique<T[]>(capacity)) {}


        /**
         * @brief Kiểm tra xem hàng đợi có rỗng không.
         * @return Trả về true nếu hàng đợi rỗng, ngược lại false.
         */
        bool isEmpty() const { return front == -1; }


        /**
         * @brief Kiểm tra xem hàng đợi có đầy không.
         * @return Trả về true nếu hàng đợi đầy, ngược lại false.
         */
        bool isFull() const { return (rear + 1) % size == front; }


        /**
         * @brief Thêm phần tử vào cuối hàng đợi.
         * @param data Giá trị cần thêm vào hàng đợi.
         * @throws runtime_error Nếu hàng đợi đã đầy.
         */
        void enqueue(const T& data) 
        {
            if (isFull()) throw runtime_error("Queue is full!");

            if (isEmpty()) 
            {
                front = rear = 0;
            } 
            else 
            {
                rear = (rear + 1) % size;
            }

            items[rear] = data;
            cout << "Enqueued: " << data << endl;
        }


        /**
         * @brief Xóa phần tử đầu tiên khỏi hàng đợi.
         * @return Trả về giá trị phần tử đầu hàng đợi.
         * @throws runtime_error Nếu hàng đợi rỗng.
         */
        T dequeue() 
        {
            if (isEmpty()) throw std::runtime_error("Queue is empty!");

            T dequeuedValue = items[front];

            if (front == rear) 
            {
                front = rear = -1;
            } 
            else 
            {
                front = (front + 1) % size;
            }

            return dequeuedValue;
        }


        /**
         * @brief Lấy giá trị phần tử đầu hàng đợi nhưng không xóa.
         * @return Trả về giá trị phần tử đầu hàng đợi.
         * @throws runtime_error Nếu hàng đợi rỗng.
         */
        T getFront() const 
        {
            if (isEmpty()) throw runtime_error("Queue is empty!");
            return items[front];
        }


        /**
         * @brief Lấy giá trị phần tử cuối hàng đợi nhưng không xóa.
         * @return Trả về giá trị phần tử cuối hàng đợi.
         * @throws runtime_error Nếu hàng đợi rỗng.
         */
        T getRear() const 
        {
            if (isEmpty()) throw runtime_error("Queue is empty!");
            return items[rear];
        }

        
        /**
         * @brief Hiển thị các phần tử trong hàng đợi.
         * @note Nếu hàng đợi rỗng, thông báo trên console.
         */
        void display() const 
        {
            if (isEmpty()) 
            {
                cout << "Queue is empty!" << std::endl;
                return;
            }

            cout << "Queue: ";
            int i = front;

            while (1) 
            {
                cout << items[i] << " ";
                if (i == rear) break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
};

#endif  // QUEUE_CIRCULAR_HPP