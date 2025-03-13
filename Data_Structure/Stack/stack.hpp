/********************************************************
 * @file    Stack.hpp
 * @brief   Định nghĩa lớp Stack sử dụng vector để quản lý dữ liệu ngăn xếp.
 * @version 1.0
 * @date    2025-01-10
 * @author  Anh Nguyen
 ********************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <cstdbool>   // Hỗ trợ kiểu boolean
#include <vector>     // Sử dụng vector để quản lý ngăn xếp

using namespace std;

/**
 * @class Stack
 * @brief Lớp Template Stack để quản lý ngăn xếp kiểu T.
 * @tparam T Kiểu dữ liệu của phần tử trong ngăn xếp.
 */
template <typename T>
class Stack
{
    private:
        vector<T> arr;      /**< Mảng lưu trữ giá trị các phần tử   */
        int top;            /**< Chỉ số phần tử ở đỉnh ngăn xếp     */
        int maxSize;        /**< Số lượng phần tử tối đa            */

    public:
        /**
         * @brief Hàm khởi tạo Stack với kích thước tối đa.
         * @param _maxSize Kích thước tối đa của Stack (mặc định 1000).
         */
        Stack(size_t _maxSize = 1000): top(-1), maxSize(_maxSize)
        {
            arr.reserve(maxSize); // Dự phòng kích thước vector
        }


        /**
         * @brief Kiểm tra xem Stack có rỗng không.
         * @return Trả về true nếu Stack rỗng, ngược lại false.
         */
        bool stack_isEmpty() const { return (top == -1); }

        
        /**
         * @brief Kiểm tra xem Stack có đầy không.
         * @return Trả về true nếu Stack đầy, ngược lại false.
         */
        bool stack_isFull() const { return (top == maxSize - 1); }

        /**
         * @brief Thêm một phần tử vào Stack.
         * @param data Giá trị của phần tử cần thêm vào Stack.
         * @note Nếu Stack đầy, hiển thị cảnh báo và không thêm phần tử.
         */
        void push(const T &data)
        {
            if (stack_isFull())
            {
                cout << "Stack Full!\n";
                return;
            }
        
            arr.emplace_back(data);
            top++;
        }
        
        /**
         * @brief Loại bỏ phần tử ở đỉnh Stack.
         * @return Trả về phần tử bị loại bỏ. Nếu Stack rỗng, trả về giá trị mặc định.
         * @note Nếu Stack rỗng, hiển thị cảnh báo.
         */
        T pop()
        {
            if (stack_isEmpty())
            {
                cout << "Stack Empty!\n";
                return T();
            }
        
            T val = arr.at(top);
            arr.at(top--) = 0;
            return val;
        }

        /**
         * @brief Lấy giá trị phần tử ở đỉnh Stack nhưng không xóa.
         * @return Trả về phần tử ở đỉnh Stack. Nếu Stack rỗng, trả về giá trị mặc định.
         * @note Nếu Stack rỗng, hiển thị cảnh báo.
         */
        T peek() const
        {
            if (stack_isEmpty())
            {
                cout << "Stack Empty!\n";
                return T();
            }
        
            return arr.at(top);
        }

        /**
         * @brief Lấy kích thước hiện tại của Stack.
         * @return Trả về số phần tử có trong Stack.
         */
        size_t size() const { return arr.size(); }

        /**
         * @brief Hiển thị toàn bộ nội dung của Stack.
         * @note Hiển thị địa chỉ bộ nhớ và giá trị từng phần tử.
         */
        void display() const
        {
            auto index = -1;
            for (const auto &item : arr)
            {
                index++;
                cout << "Element " << index << " - Addr: " << &item << " - Value: " << item << endl;
            }
            cout << endl;
        }
};

#endif  // STACK_HPP