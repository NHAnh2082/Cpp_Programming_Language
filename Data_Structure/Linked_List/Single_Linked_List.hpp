/********************************************************
 * @file Single_Linked_List.hpp
 * @brief Định nghĩa lớp danh sách liên kết đơn (Singly Linked List).
 * @version 1.0
 * @date 2025-01-10
 * @author Anh Nguyen
 ********************************************************/

#ifndef SINGLE_LINKED_LIST_HPP
#define SINGLE_LINKED_LIST_HPP

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

/**
 * @class Node
 * @brief Lớp đại diện cho một nút trong danh sách liên kết đơn.
 * @tparam T Kiểu dữ liệu của phần tử trong danh sách.
 */
template <typename T>
class Node 
{
    public:
        T data;                      /**< Dữ liệu của nút */
        shared_ptr<Node<T>> next;     /**< Con trỏ đến nút tiếp theo */

        /**
         * @brief Khởi tạo một nút với dữ liệu mới.
         * @param newData Dữ liệu cần lưu trữ trong nút.
         */
        explicit Node(T newData) : data(newData), next(nullptr) {}
};

/**
 * @class SinglyLinkedList
 * @brief Lớp danh sách liên kết đơn.
 * @tparam T Kiểu dữ liệu của phần tử trong danh sách.
 */
template <typename T>
class SinglyLinkedList 
{
    private:
        shared_ptr<Node<T>> head; /**< Con trỏ đến phần tử đầu tiên của danh sách */
        size_t count;             /**< Số lượng phần tử trong danh sách */

    public:
        /**
         * @brief Constructor khởi tạo danh sách rỗng.
         */
        SinglyLinkedList() : head(nullptr), count(0) {}

        /**
         * @brief Destructor mặc định.
         */
        ~SinglyLinkedList() = default;
    
        /**
         * @brief Thêm phần tử vào cuối danh sách.
         * @param newData Dữ liệu cần thêm vào danh sách.
         */
        void push_back(T newData)
        {
            auto newNode = make_shared<Node<T>>(newData);
            if (!head) 
            {
                head = newNode;
            } 
            else 
            {
                auto temp = head;
                while (temp->next) temp = temp->next;
                temp->next = newNode;
            }
            count++;
        }

        /**
         * @brief Thêm phần tử vào đầu danh sách.
         * @param newData Dữ liệu cần thêm vào danh sách.
         */
        void push_front(T newData)
        {
            auto newNode = make_shared<Node<T>>(newData);
            newNode->next = head;
            head = newNode;
            count++;
        }

        /**
         * @brief Chèn phần tử vào vị trí cụ thể trong danh sách.
         * @param newData Dữ liệu cần chèn vào danh sách.
         * @param position Vị trí chèn trong danh sách (bắt đầu từ 0).
         * @throws out_of_range Nếu vị trí vượt quá kích thước danh sách.
         */
        void insert(T newData, size_t position)
        {
            if (position > count) throw std::out_of_range("Invalid position");
            if (position == 0) return push_front(newData);
            if (position == count) return push_back(newData);
            
            auto newNode = std::make_shared<Node<T>>(newData);
            auto temp = head;
            for (size_t i = 0; i < position - 1; ++i) 
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            count++;
        }

        /**
         * @brief Xóa phần tử cuối danh sách.
         * @throws runtime_error Nếu danh sách rỗng.
         */
        void pop_back()
        {
            if (!head) throw std::runtime_error("List is empty");
            if (!head->next) 
            {
                head.reset();
            } 
            else 
            {
                auto temp = head;
                while (temp->next->next) temp = temp->next;
                temp->next.reset();
            }
            count--;
        }

        /**
         * @brief Xóa phần tử đầu danh sách.
         * @throws runtime_error Nếu danh sách rỗng.
         */
        void pop_front()
        {
            if (!head) throw std::runtime_error("List is empty");
            head = head->next;
            count--;
        }

        /**
         * @brief Xóa phần tử tại vị trí cụ thể.
         * @param position Vị trí của phần tử cần xóa (bắt đầu từ 0).
         * @throws out_of_range Nếu vị trí không hợp lệ.
         */
        void erase(size_t position)
        {
            if (!head || position >= count) throw std::out_of_range("Invalid position");
            if (position == 0) return pop_front();
            
            auto temp = head;
            for (size_t i = 0; i < position - 1; ++i) 
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            count--;
        }

        /**
         * @brief Lấy phần tử đầu danh sách.
         * @return Trả về dữ liệu của phần tử đầu danh sách.
         * @throws runtime_error Nếu danh sách rỗng.
         */
        T front() const
        {
            if (!head) throw std::runtime_error("List is empty");
            return head->data;
        }

        /**
         * @brief Lấy phần tử cuối danh sách.
         * @return Trả về dữ liệu của phần tử cuối danh sách.
         * @throws runtime_error Nếu danh sách rỗng.
         */
        T back() const
        {
            if (!head) throw std::runtime_error("List is empty");
            auto temp = head;
            while (temp->next) temp = temp->next;
            return temp->data;
        }

        /**
         * @brief Lấy phần tử tại vị trí cụ thể.
         * @param position Vị trí của phần tử (bắt đầu từ 0).
         * @return Trả về dữ liệu của phần tử tại vị trí được yêu cầu.
         * @throws out_of_range Nếu vị trí không hợp lệ.
         */
        T get(size_t position) const
        {
            if (!head || position >= count) throw std::out_of_range("Invalid position");
            auto temp = head;
            for (size_t i = 0; i < position; ++i) temp = temp->next;
            return temp->data;
        }

        /**
         * @brief Lấy kích thước danh sách.
         * @return Trả về số phần tử hiện có trong danh sách.
         */
        size_t size() const { return count; }

        /**
         * @brief Hiển thị danh sách các phần tử hiện tại.
         * @note In ra dữ liệu của từng phần tử trong danh sách.
         */
        void display() const
        {
            if (!head) 
            {
                std::cout << "List is empty\n";
                return;
            }
            auto temp = head;
            size_t index = 0;
            while (temp) 
            {
                std::cout << "Node " << index++ << ": " << temp->data << "\n";
                temp = temp->next;
            }
        }
};

#endif  // SINGLE_LINKED_LIST_HPP
