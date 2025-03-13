/********************************************************
 * @file Doubly_Linked_List.hpp
 * @brief Định nghĩa lớp danh sách liên kết đôi (Doubly Linked List).
 * @version 1.0
 * @date 2025-01-10
 * @author Anh Nguyen
 ********************************************************/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

/**
 * @class DoublyLinkedList
 * @brief Lớp template mô phỏng danh sách liên kết đôi (DLL).
 * @tparam T Kiểu dữ liệu của phần tử trong danh sách.
 */
template <typename T>
class DoublyLinkedList 
{
    private:
        /**
         * @struct Node
         * @brief Cấu trúc một nút trong danh sách liên kết đôi.
         */
        struct Node 
        {
            T data;                      /**< Dữ liệu của nút */
            shared_ptr<Node> next;        /**< Con trỏ đến nút tiếp theo */
            weak_ptr<Node> prev;          /**< Con trỏ yếu đến nút trước đó */

            /**
             * @brief Khởi tạo một nút với giá trị dữ liệu.
             * @param value Giá trị của nút.
             */
            explicit Node(T value) : data(value), next(nullptr), prev() {}
        };

        shared_ptr<Node> head; /**< Con trỏ đến phần tử đầu tiên của danh sách */
        shared_ptr<Node> tail; /**< Con trỏ đến phần tử cuối cùng của danh sách */
        size_t list_size;      /**< Số lượng phần tử trong danh sách */

    public:
        /**
         * @brief Khởi tạo danh sách rỗng.
         */
        DoublyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

        /**
         * @brief Lấy kích thước danh sách.
         * @return Số phần tử hiện có trong danh sách.
         */
        size_t size() const { return list_size; }

        /**
         * @brief Kiểm tra danh sách có rỗng không.
         * @return Trả về true nếu danh sách rỗng, ngược lại false.
         */
        bool empty() const { return list_size == 0; }

        /**
         * @brief Thêm phần tử vào đầu danh sách.
         * @param value Giá trị cần thêm vào danh sách.
         */
        void push_front(T value)
        {
            auto new_node = make_shared<Node>(value);
            if (empty()) 
            {
                head = tail = new_node;
            } 
            else 
            {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
            list_size++;
        }

        /**
         * @brief Thêm phần tử vào cuối danh sách.
         * @param value Giá trị cần thêm vào danh sách.
         */
        void push_back(T value)
        {
            auto new_node = make_shared<Node>(value);
            if (empty()) 
            {
                head = tail = new_node;
            } 
            else 
            {
                new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
            }
            list_size++;
        }

        /**
         * @brief Xóa phần tử đầu danh sách.
         * @throws underflow_error Nếu danh sách rỗng.
         */
        void pop_front()
        {
            if (empty()) throw underflow_error("List is empty");

            head = head->next;

            if (head)
            {
                head->prev.reset();
            }
            else 
            {
                tail.reset();
            }

            list_size--;
        }

        /**
         * @brief Xóa phần tử cuối danh sách.
         * @throws underflow_error Nếu danh sách rỗng.
         */
        void pop_back()
        {
            if (empty()) throw std::underflow_error("List is empty");

            tail = tail->prev.lock();

            if (tail)
            {
                tail->next.reset();
            }
            else
            {
                head.reset();
            }

            list_size--;
        }

        /**
         * @brief Chèn phần tử vào vị trí cụ thể.
         * @param value Giá trị cần chèn vào danh sách.
         * @param position Vị trí chèn (bắt đầu từ 0).
         * @throws out_of_range Nếu vị trí không hợp lệ.
         */
        void insert(T value, size_t position)
        {
            if (position > list_size) throw out_of_range("Invalid position");
            if (position == 0) return push_front(value);
            if (position == list_size) return push_back(value);
        
            auto new_node = make_shared<Node>(value);
            auto temp = head;
            for (size_t i = 0; i < position - 1; ++i) 
            {
                temp = temp->next;
            }
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next->prev = new_node;
            temp->next = new_node;
            list_size++;
        }
        
        /**
         * @brief Xóa phần tử tại vị trí cụ thể.
         * @param position Vị trí cần xóa (bắt đầu từ 0).
         * @throws out_of_range Nếu vị trí không hợp lệ.
         */
        void erase(size_t position)
        {
            if (empty() || position >= list_size) throw out_of_range("Invalid position");
            if (position == 0) return pop_front();
            if (position == list_size - 1) return pop_back();
            
            auto temp = head;
            for (size_t i = 0; i < position; ++i) 
            {
                temp = temp->next;
            }
            temp->prev.lock()->next = temp->next;
            temp->next->prev = temp->prev;
            list_size--;
        }

        /**
         * @brief Lấy phần tử đầu danh sách.
         * @return Trả về dữ liệu của phần tử đầu danh sách.
         * @throws underflow_error Nếu danh sách rỗng.
         */
        T front() const
        {
            if (empty()) throw underflow_error("List is empty");
            return head->data;
        }
        
        /**
         * @brief Lấy phần tử cuối danh sách.
         * @return Trả về dữ liệu của phần tử cuối danh sách.
         * @throws underflow_error Nếu danh sách rỗng.
         */
        T back() const
        {
            if (empty()) throw underflow_error("List is empty");
            return tail->data;
        }

        /**
         * @brief Lấy phần tử tại vị trí cụ thể.
         * @param position Vị trí phần tử cần lấy (bắt đầu từ 0).
         * @return Trả về dữ liệu của phần tử.
         * @throws out_of_range Nếu vị trí không hợp lệ.
         */
        T get(size_t position) const
        {
            if (position >= list_size) throw out_of_range("Invalid position");
            auto temp = head;
            for (size_t i = 0; i < position; ++i) 
            {
                temp = temp->next;
            }
            return temp->data;
        }

        /**
         * @brief Hiển thị danh sách từ đầu đến cuối.
         */
        void display_forward() const
        {
            auto temp = head;
            while (temp) 
            {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "NULL" << std::endl;
        }
        
        /**
         * @brief Hiển thị danh sách từ cuối lên đầu.
         */
        void display_backward() const
        {
            auto temp = tail;
            while (temp) 
            {
                cout << temp->data << " <-> ";
                temp = temp->prev.lock();
            }
            cout << "NULL" << endl;
        }
        
        /**
         * @brief Xóa toàn bộ danh sách.
         */
        void clear()
        {
            while (!empty()) pop_front();
        }

        /**
         * @brief Destructor, tự động giải phóng bộ nhớ khi đối tượng bị hủy.
         */
        ~DoublyLinkedList() { clear(); }
};

#endif // DOUBLY_LINKED_LIST_H 