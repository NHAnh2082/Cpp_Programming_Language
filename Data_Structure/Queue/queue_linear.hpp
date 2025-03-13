/************************************************************************
 * @file    Queue_Linear.hpp
 * @brief   Định nghĩa lớp hàng đợi tuyến tính (Queue) sử dụng mảng động.
 * @version 1.0
 * @date    2025-01-10
 * @author  Anh Nguyen
 ***********************************************************************/

#ifndef QUEUE_LINEAR_HPP
#define QUEUE_LINEAR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;


/**
 * @class Queue
 * @brief Lớp template mô phỏng cấu trúc hàng đợi tuyến tính (FIFO).
 * @tparam T Kiểu dữ liệu của phần tử trong hàng đợi.
 */
template <typename T>
class Queue 
{
    private:
        unique_ptr<T[]> item;  /**< Con trỏ thông minh quản lý bộ nhớ hàng đợi */
        int size;              /**< Kích thước tối đa của hàng đợi */
        int front;             /**< Chỉ số đầu hàng đợi */
        int rear;              /**< Chỉ số cuối hàng đợi */

    public:
        /**
         * @brief Khởi tạo hàng đợi với kích thước tối đa.
         * @param size Số lượng phần tử tối đa trong hàng đợi.
         */
        explicit Queue(int size) : size(size), front(-1), rear(-1) 
        {
            item = make_unique<T[]>(size);
        }


        /**
         * @brief Kiểm tra xem hàng đợi có đầy không.
         * @return Trả về true nếu hàng đợi đầy, ngược lại false.
         */
        bool isFull() const { return rear == size - 1; }


        /**
         * @brief Kiểm tra xem hàng đợi có rỗng không.
         * @return Trả về true nếu hàng đợi rỗng, ngược lại false.
         */
        bool isEmpty() const { return front == -1 || front > rear; }


        /**
         * @brief  Thêm phần tử vào cuối hàng đợi.
         * @param  data Giá trị cần thêm vào hàng đợi.
         * @throws overflow_error Nếu hàng đợi đã đầy.
         */
        void enqueue(T data) 
        {
            if (isFull()) 
            {
                throw overflow_error("Queue is full!");
            }

            if (front == -1) front = rear = 0;
            else rear++;
            item[rear] = data;
            cout << "Enqueued: " << data << "\n";
        }


        /**
         * @brief Loại bỏ phần tử đầu hàng đợi.
         * @return Trả về giá trị phần tử đã loại bỏ.
         * @throws underflow_error Nếu hàng đợi rỗng.
         */
        T dequeue() 
        {
            if (isEmpty()) throw underflow_error("Queue is empty!");

            T dequeue_value = item[front];

            if (front == rear) 
            {
                front = rear = -1;
            } 
            else 
            {
                front++;
            }
            return dequeue_value;
        }


        /**
         * @brief Hiển thị các phần tử trong hàng đợi.
         * @note Nếu hàng đợi rỗng, thông báo trên console.
         */
        void display() const 
        {
            if (isEmpty()) 
            {
                cout << "Queue is empty!\n";
                return;
            }

            cout << "Queue: ";
            for (int i=front; i<=rear; ++i) 
            {
                cout << item[i] << " ";
            }
            cout << "\n";
        }


        /**
         * @brief Lấy phần tử ở đầu hàng đợi mà không xóa.
         * @return Trả về giá trị phần tử ở đầu hàng đợi.
         * @throws underflow_error Nếu hàng đợi rỗng.
         */
        T getFront() const 
        {
            if (isEmpty()) throw underflow_error("Queue is empty!");
            return item[front];
        }


        /**
         * @brief Lấy phần tử ở cuối hàng đợi mà không xóa.
         * @return Trả về giá trị phần tử ở cuối hàng đợi.
         * @throws underflow_error Nếu hàng đợi rỗng.
         */
        T getRear() const 
        {
            if (isEmpty()) throw underflow_error("Queue is empty!");
            return item[rear];
        }
};

#endif  // QUEUE_LINEAR_HPP