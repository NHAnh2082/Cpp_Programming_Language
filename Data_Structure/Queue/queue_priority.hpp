/********************************************************
 * @file    Queue_Priority.hpp
 * @brief   Định nghĩa lớp hàng đợi ưu tiên (Priority Queue).
 * @version 1.0
 * @date    2025-01-10
 * @author  Anh Nguyen
 ********************************************************/

#ifndef QUEUE_PRIORITY_HPP
#define QUEUE_PRIORITY_HPP

#include <vector>
#include <limits>
#include <cstdint>

using namespace std;

/**
 * @struct Element
 * @brief Cấu trúc lưu trữ phần tử trong hàng đợi ưu tiên.
 * @tparam T Kiểu dữ liệu của phần tử.
 */
template <typename T>
struct Element
{
    T data;             /**< Dữ liệu của phần tử                        */
    uint8_t priority;   /**< Độ ưu tiên (càng nhỏ, độ ưu tiên càng cao) */

    /**
     * @brief Khởi tạo phần tử với dữ liệu và độ ưu tiên.
     * @param _data Giá trị dữ liệu của phần tử.
     * @param _prior Độ ưu tiên của phần tử.
     */
    Element(T _data, uint8_t _prior) : data(_data), priority(_prior){}
};

/**
 * @class Priority_Queue
 * @brief Lớp template mô phỏng hàng đợi ưu tiên (FIFO theo độ ưu tiên).
 * @tparam T Kiểu dữ liệu của phần tử trong hàng đợi.
 */
template <typename T>
class Priority_Queue
{
    private:
        vector<Element<T>> elements;    /**< Mảng lưu trữ các phần tử */
        size_t capacity;                /**< Số lượng phần tử tối đa  */

        /**
         * @brief Tìm vị trí phần tử có độ ưu tiên cao nhất.
         * @return Trả về chỉ số phần tử có độ ưu tiên cao nhất.
         */
        int highest_priority() const
        {
            uint8_t highest = numeric_limits<uint8_t>::max();
            int index = -1;
        
            for (size_t i = 0; i < elements.size(); i++)
            {
                if (elements[i].priority < highest)
                {
                    highest = elements[i].priority;
                    index = i;
                }
            }
        
            return index;
        }

    public:
        /**
         * @brief Khởi tạo hàng đợi ưu tiên với số lượng phần tử tối đa.
         * @param _capacity Số lượng phần tử tối đa (mặc định 100).
         */
        Priority_Queue(size_t _capacity = 100) : capacity(_capacity)
        {
            elements.reserve(capacity);
        }

        /**
         * @brief Kiểm tra xem hàng đợi có rỗng không.
         * @return Trả về true nếu hàng đợi rỗng, ngược lại false.
         */
        bool pqueue_empty() const
        {
            return (elements.size() == 0 || elements.empty());
        }

        /**
         * @brief Kiểm tra xem hàng đợi có đầy không.
         * @return Trả về true nếu hàng đợi đầy, ngược lại false.
         */
        bool pqueue_full() const
        {
            return elements.size() == capacity;
        }

        /**
         * @brief Thêm phần tử vào hàng đợi theo độ ưu tiên.
         * @param data Giá trị cần thêm vào hàng đợi.
         * @param priority Độ ưu tiên của phần tử.
         * @note Nếu hàng đợi đầy, in thông báo lỗi.
         */
        void enqueue(T data, uint8_t priority)
        {
            if (pqueue_full())
            {
                cout << "Queue Full!\n";
                return;
            }
        
            elements.emplace_back(data, priority);
        }

        /**
         * @brief Xóa và trả về phần tử có độ ưu tiên cao nhất.
         * @return Trả về phần tử có độ ưu tiên cao nhất.
         * @note Nếu hàng đợi rỗng, trả về phần tử mặc định.
         */
        Element<T> dequeue()
        {
            if (pqueue_empty())
            {
                cout << "Queue Empty!\n";
                return Element<T>(T(), numeric_limits<uint8_t>::max());
            }
        
            int index = highest_priority();
            Element<T> top = elements[index];
            elements.erase(elements.begin() + index);
            return top;
        }

        /**
         * @brief Lấy phần tử có độ ưu tiên cao nhất mà không xóa.
         * @return Trả về phần tử có độ ưu tiên cao nhất.
         * @note Nếu hàng đợi rỗng, trả về phần tử mặc định.
         */
        Element<T> top() const
        {
            if (pqueue_empty())
            {
                cout << "Queue Empty!\n";
                return Element<T>(T(), numeric_limits<uint8_t>::max());
            }
        
            return elements[highest_priority()];
        }

        /**
         * @brief Hiển thị danh sách các phần tử trong hàng đợi.
         * @note In ra giá trị và độ ưu tiên của từng phần tử.
         */
        void display() const
        {
            for (const Element<T> &item : elements)
            {
                cout << "Value: " << item.data << " - Priority: " << static_cast<int>(item.priority) << endl;
            }
            cout << endl;
        }
};

#endif  // QUEUE_PRIORITY_HPP
