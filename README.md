# C++

<details><summary>Nhấp vào để xem chi tiết</summary>
<p>

<details><summary><b>Class</b></summary>
<p>

<details><summary><b>1. Giới thiệu về Class </b></summary>
<p>

- Trong C++, **class** là một kiểu dữ liệu do người dùng định nghĩa, dùng để nhóm các biến (thuộc tính) và hàm (phương thức) có liên quan lại với nhau. Nó là một phần cốt lõi của lập trình hướng đối tượng (OOP - Object-Oriented Programming).
- Các thành phần của **Class**:

	+ **Phạm vi truy cập** (Access Modifier): **public**, **protected**, **private**
 	+ Các thành phần dữ liệu (biến hay **property**).
  	+ Các phương thức (hàm thành phần hay **method**).

- Khai báo và sử dụng **class**:

```cpp
class <class_name>
{
   <access_modifier>:
      <data_type> property1;
      <data_type> property2;
      ...
      <return_type> <method_name_1>(argument1, argument2, ....);
      <return_type> <method_name_2>(argument1, argument2, ....);
};

<return_type> <class_name>::<method_name1>(argument1, argument2, ....)
{
    ...
}

<return_type> <class_name>::<method_name2>(argument1, argument2, ....)
{
    ...
}
```

<br>

💻 **Ví dụ 1:**
```cpp
class Person
{
    public:
        string firstName; // property
        string lastName;  // property
        int age;	  // property

        void fullName()   // method
	{  
            cout << firstName << " " << lastName;
        }
}
```

<br>

💻 **Ví dụ 2:**
```cpp
class SinhVien
{
    public:
        int ID;         // property
        string name;    // property
        string lop;     // property
        void display(); // method
};

void SinhVien::display()
{
    cout << "MSSV: " << ID << endl;
    cout << "Tên: " << name << endl;
    cout << "Lớp: " << lop << endl;
}
```

<br>

</p>
</details>

<details><summary><b>2. Phạm vi truy cập (Access Modifier)</b></summary>
<p>

- Access modifier là các "từ" dùng trước các khai báo của một class, property hay method để thể hiện khả năng truy cập của class, biến hay method đó ở các class khác.
- có 3 access modifier: **public**, **protected**, **private**

<br>

<details><summary><b>📚 public</b></summary>
<p>

- Truy cập từ bên trong class thông qua các method.
- Truy cập từ bên ngoài class thông qua các object.

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
    public:
        int ID;         // property
        string name;    // property
        string lop;     // property
        void display()  // method
	{ 
            cout << "MSSV: " << ID << endl;
            cout << "Tên: " << name << endl;
            cout << "Lớp: " << lop << endl;
        }
};

int main()
{
    SinhVien sv; // sv được gọi là object
    sv.ID = 2010117;
    sv.name = "Anh";
    sv.lop = "DD20TD1";
    sv.display();  
    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
using namespace std;

class HinhChuNhat
{
    public:
        double chieuDai;    // property
        double chieuRong;   // property

    // Hàm tính diện tích
    double tinhDienTich()   // method	
    {
        return chieuDai * chieuRong;
    }

    void display(); // method
};

void HinhChuNhat::display(){ cout << " Hello " << "\n"; }

int main()
{
    HinhChuNhat hinh1;
    hinh1.chieuDai = 10.0;
    hinh1.chieuRong = 5.0;
    hinh1.display();
    cout << "Dien tich: " << hinh1.tinhDienTich() << '\n';
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>📚 private</b></summary>
<p>

- Các thuộc tính mà bạn không muốn người khác có thể truy cập đến từ bên ngoài sẽ được khai báo ở **private**.
- Những property hay method nằm ở **private** thì chỉ có giá trị tại class và các **object** bên ngoài không thể truy cập đến.
- Muốn truy cập các thuộc tính **private** thì chỉ có thể truy cập gián tiếp thông qua các **method** hay **constructor** nằm trong cùng **class**.

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
    private:
        string name;
        string major;
        int id;
        double gpa;

    public:
        SinhVien()
	{
  	    static int _id = 1;
   	    id = _id;
	    _id++;
	}

	// getter method for name
        string getName(){ return name; }

	// setter method for name
	void setName(string _name){ name = _name; }

	// getter method for major
        string getChuyenNganh(){ return major;}

	// setter method for major
	void setMajor(string _major){ major = _major; }

	// setter method for gpa
        void setGPA(double _gpa){ gpa = _gpa; }

	// getter method for gpa
        double getGPA(){ return gpa; }

	// getter method for id
        int getID(){ return id; }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1("Trung", "DTVT");
    sv1.setName("Tuan");
    sv1.setMajor("Embedded");

    // sv1.ten = "Tuan";        // wrong
    // sv1.id = 10;             // wrong
    // sv1.chuyenNganh = "TDH"; // wrong

    cout << "ID: " << sv1.getID() << endl;
    cout << "Name: " << sv1.getName() << endl;
    cout << "Chuyen nganh: " << sv1.getMajor() << endl;
    return 0;
}
```

📝 Khi đã setup một số thông tin và không muốn users có thể truy cập vào và thay đổi được những thông tin thì ta nên khai báo nó ở phạm vi ``` private ```.

📝 Những property nào đã được khai báo ở phạm vi ``` private ``` thì nó sẽ chỉ có giá trị nội bộ trong class và chỉ có những metod nằm trong class mới có thể truy cập để thay đổi được.

📝 Việc ẩn đi những property bằng cách khai báo trong ``` private ``` chính là **tính đóng gói** trong hướng đối tượng.

<br>

</p>
</details>

<details><summary><b>📚 protected</b></summary>
<p>

- Các method và property nằm ở protected không thể truy cập từ các object bên ngoài.
- Các method và property nằm ở protected có thể truy cập trực tiếp từ các method bên trong class.
- Các method và property nằm ở protected còn có thể truy cập thông qua các class **kế thừa**.


💻 **Ví dụ 1:**
```cpp
#include <iostream>
using namespace std;

class Base
{
    protected:
        int protectedVar;

    public:
        Base() : protectedVar(10){}
};

class Derived : public Base
{
    public: 
        void showProtectedVar()
        {
            cout << "Protected variable: " << protectedVar << endl;
        }
};

int main(int argc, char const *argv[])
{
    Derived obj;
    // obj.protectedVar = 10; // wrong
    obj.showProtectedVar();   // right
    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <string>
using namespace std;

class DoiTuong
{
    protected:
	string name;
	string id;
	int id;
	double gpa;
};

class SinhVien : public DoiTuong
{
    public:
        SinhVien()
	{
  	    static int _id = 1;
   	    id = _id;
	    _id++;
	}

	// getter method for name
        string getName(){ return name; }

	// setter method for name
	void setName(string _name){ name = _name; }

	// getter method for major
        string getChuyenNganh(){ return major;}

	// setter method for major
	void setMajor(string _major){ major = _major; }

	// setter method for gpa
        void setGPA(double _gpa){ gpa = _gpa; }

	// getter method for gpa
        double getGPA(){ return gpa; }

	// getter method for id
        int getID(){ return id; }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1("Trung", "DTVT");
    sv1.setName("Tuan");
    sv1.setMajor("Embedded");

    // sv1.ten = "Tuan";        // wrong
    // sv1.id = 10;             // wrong
    // sv1.chuyenNganh = "TDH"; // wrong

    cout << "ID: " << sv1.getID() << endl;
    cout << "Name: " << sv1.getName() << endl;
    cout << "Chuyen nganh: " << sv1.getMajor() << endl;
    return 0;
}
```

<br>

</p>
</details>

</p>
</details>

<details><summary><b>3. Constructor (Phương thức khởi tạo) </b></summary>
<p>

- Constructor là một method có **tên trùng với tên của class**.
- Constructor có thể được khai báo ở cả ba phạm vi public, protected, private.
- Constructor thường được sử dụng để khởi tạo giá trị ban đầu cho các property trong class.

<br>

<details><summary><b>📚 Constructor với access modifier là PUBLIC</b></summary>
<p>

- Constructor sẽ được tự động gọi khi khởi tạo object (bên trong lẫn ngoài **class**).
- Constructor có thể có tham số truyền vào hoặc không.

<br>

💻 **Constructor không có tham số truyền vào**
```cpp
#include <iostream>
using namespace std;

class HinhChuNhat
{
    public:
        double chieuDai;
        double chieuRong;

        HinhChuNhat()
	{				
             chieuDai  = 10;
             chieuRong = 9;
        }

        // Hàm tính diện tích
        double tinhDienTich(){ return chieuDai * chieuRong; }
};

int main()
{
    HinhChuNhat hinh1;
    cout << "Chieu dai: " << hinh1.chieuDai << '\n';
    cout << "Chieu rong: " << hinh1.chieuRong << '\n';
    cout << "Dien tich: " << hinh1.tinhDienTich() << '\n';
    return 0;
}
```

<br>

💻 **Constructor có tham số truyền vào, không có giá trị mặc định**
```cpp
#include <iostream>
using namespace std;

class HinhChuNhat
{
    public:
        double chieuDai;
        double chieuRong;

        HinhChuNhat(int dai, int rong);

        double tinhDienTich()
        {
            return chieuDai * chieuRong;
        }
};

HinhChuNhat::HinhChuNhat(int dai, int rong)
{
    chieuDai = dai;
    chieuRong = rong;
}

int main()
{
    int a,b;
    cout << "Nhap chieu dai: ";  cin >> a;
    cout << "Nhap chieu rong: "; cin >> b;

    HinhChuNhat hinh3(a,b); 	// lấy giá trị mới nhập từ bàn phím
    cout << "Chieu dai: " << hinh3.chieuDai << '\n';
    cout << "Chieu rong: " << hinh3.chieuRong << '\n';
    cout << "Dien tich: " << hinh3.tinhDienTich() << '\n';
    return 0;
}
```

<br>

💻 **Constructor có tham số truyền vào, có giá trị mặc định**
```cpp
#include <iostream>
using namespace std;

class HinhChuNhat
{
    public:
        double chieuDai;
        double chieuRong;

        HinhChuNhat(int dai = 3, int rong = 5);

        double tinhDienTich()
        {
            return chieuDai * chieuRong;
        }
};

HinhChuNhat::HinhChuNhat(int dai, int rong)
{
    chieuDai = dai;
    chieuRong = rong;
}

int main()
{
    HinhChuNhat hinh1; 		// lấy giá trị mặc định (3,5)
    cout << "Chieu dai: " << hinh1.chieuDai << '\n';
    cout << "Chieu rong: " << hinh1.chieuRong << '\n';
    cout << "Dien tich: " << hinh1.tinhDienTich() << '\n';

    HinhChuNhat hinh2(10,20); 	// lấy giá trị mới
    cout << "Chieu dai: " << hinh2.chieuDai << '\n';
    cout << "Chieu rong: " << hinh2.chieuRong << '\n';
    cout << "Dien tich: " << hinh2.tinhDienTich() << '\n';

    int a,b;
    cout << "Nhap chieu dai: ";  cin >> a;
    cout << "Nhap chieu rong: "; cin >> b;

    HinhChuNhat hinh3(a,b); 	// lấy giá trị mới nhập từ bàn phím
    cout << "Chieu dai: " << hinh3.chieuDai << '\n';
    cout << "Chieu rong: " << hinh3.chieuRong << '\n';
    cout << "Dien tich: " << hinh3.tinhDienTich() << '\n';
    return 0;
}
```
📝 Khi constructor có tham số truyền số nhưng không có giá trị mặc định thì các object khi khởi tạo **bắt buộc** phải truyền giá trị cho các tham số.

📝 Khi constructor có tham số truyền vào và có giá trị mặc định:

📝 Nếu object được khởi tạo không có tham số truyền vào thì mặc định lấy 2 giá trị đã khởi tạo phía trên.

📝 Nếu object được khởi tạo và truyền vào giá trị mới thì nó sẽ ghi đè lên giá trị cũ và các lệnh thực thi phía sau sẽ lấy giá trị mới.

<br>

💻 **Initialization List**
```cpp
#include <iostream>

using namespace std;

class HinhChuNhat
{
    public:
        double chieuDai;
        double chieuRong;

        HinhChuNhat(int dai = 3, int rong = 5): chieuDai(dai), chieuRong(rong){}	// initialization list

        // Hàm tính diện tích
        double tinhDienTich()
        {
            return chieuDai * chieuRong;
        }
};
int main(){
    HinhChuNhat hinh1;
    cout << "Chieu dai: " << hinh1.chieuDai << '\n';
    cout << "Chieu rong: " << hinh1.chieuRong << '\n';
    cout << "Dien tich: " << hinh1.tinhDienTich() << '\n';
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>📚 Constructor với access modifier là PROTECTED</b></summary>
<p>

-  object không thể được khởi tạo trực tiếp từ bên ngoài class, mà chỉ có thể được khởi tạo từ các class kế thừa hoặc các method bên trong class đó.

💻 **Ví dụ:**
```cpp
#include <iostream>
using namespace std;

class Base
{
    protected:
        Base()
        {
            cout << "Protected constructor called!" << endl;
        }
};

class Derived : public Base
{
    public:
        Derived() : Base()	// Có thể gọi constructor protected của class Base
	{  
            cout << "Derived constructor called!" << endl;
        }
};

int main()
{
    // Base obj;  // Lỗi: Không thể khởi tạo đối tượng Base từ bên ngoài
    Derived obj;  // Hợp lệ: Có thể khởi tạo Derived, class con của Base
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>📚 Constructor với access modifier là PRIVATE</b></summary>
<p>

- Không ai có thể khởi tạo đối tượng của class từ bên ngoài, kể cả class con. Thường được sử dụng trong các **singleton pattern** (Tạo 1 đối tượng duy nhất và constructor cũng chạy 1 lần duy nhất) hoặc các trường hợp mà muốn kiểm soát chặt chẽ việc tạo đối tượng.

💻 **Ví dụ:**
```cpp
class MyClass
{
	private:
	    MyClass()
	    {
	        cout << "Private constructor called!" << endl;
	    }
	
	public:
	    static MyClass createInstance()
	    {
	        return MyClass();  // Có thể khởi tạo từ bên trong class với method static
	    }
};

int main()
{
    // MyClass obj;  // Lỗi: Không thể khởi tạo đối tượng từ bên ngoài
    MyClass obj = MyClass::createInstance();  // Hợp lệ: Sử dụng phương thức static để tạo đối tượng
    return 0;
}
```

<br>

</p>
</details>

</p>
</details>

<details><summary><b>4. Destructor (Phương thức hủy) </b></summary>
<p>

- Tương tự với Constructor, Destructor cũng là một method và có tên trùng với tên class nhưng có thể ký tự **~** ở phía trước tên.
- Destructor khi khai báo trong phạm vi public sẽ được tự động gọi khi object được giải phóng.
- Trong class, object bản chất cũng là 1 biến cục bộ nên nó sẽ được lưu trong phân vùng Stack và khi kết thúc hàm thì cũng bị thu hồi nhưng đối với **destructor**, trước khi thu hồi sẽ tự động khởi chạy.

<br>

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <string>
using namespace std;

class HinhChuNhat
{
    public:
        string name;
        double chieuDai;
        double chieuRong;

    HinhChuNhat(string ten)
    { 
        HinhChuNhat::name = ten;
        cout << "Khoi tao object: " << name << endl;
    }

    ~HinhChuNhat()
    {
        cout << "Destructor: " << name << '\n';
    }


    // Hàm tính diện tích
    double tinhDienTich(){ return chieuDai * chieuRong; }
};

void test()
{
    HinhChuNhat hinh1("Hinh1");
    HinhChuNhat hinh2("Hinh2");
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
```

**Kết quả:**
```cpp
Khoi tao object: Hinh1
Khoi tao object: Hinh2
Destructor: Hinh2
Destructor: Hinh1
```

📝 ``` hinh1("Hinh1") ```, ``` hinh2("Hinh2") ``` bản chất đều 2 biến cục bộ và lưu trong Stack

📝 object ``` hinh1("Hinh1") ``` được khởi tạo trước nên được đưa vào Stack trước, còn object ``` hinh2("Hinh2") ``` khởi tạo sau nên đưa vào Stack sau cùng nhưng khi lấy ra thì object ``` hinh2("Hinh2") ``` lại được lấy ra trước.

<br> 

</p>
</details>

<details><summary><b>5. Static in Class </b></summary>
<p>

<details><summary><b>📚 Static Property</b></summary>
<p>

Khi một property trong class được khai báo với từ khóa static:

- Tất cả các object sẽ dùng chung địa chỉ của property.
- Địa chỉ của property phải được khởi tạo trước khi khởi tạo object.

<br>

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <string>

using namespace std;

class HinhChuNhat
{ 
    public:
        double chieuDai;
        double chieuRong;
        static int var;
};

int HinhChuNhat::var; // 0xa1

int main()
{
    HinhChuNhat hinh1; // 0x01
    HinhChuNhat hinh2; // 0x08

    cout << "address of object hinh 1: " << &hinh1 << '\n';
    cout << "address of chieu dai 1: " << &hinh1.chieuDai << '\n'; 
    cout << "address of chieu rong 1: " << &hinh1.chieuRong << '\n';
    cout << "address of chieu dai 2: " << &hinh2.chieuDai << '\n'; 
    cout << "address of chieu rong 12: " << &hinh2.chieuRong << '\n';

    cout << "address of var: " << &hinh1.var << '\n'; 
    cout << "address of var: " << &hinh2.var << '\n'; 

    return 0;
}
```

**Kết quả**:
```cpp
address of object hinh 1: 0x7609ffb80
address of chieu dai 1: 0x7609ffb80
address of chieu rong 1: 0x7609ffb88
address of chieu dai 2: 0x7609ffb70
address of chieu rong 12: 0x7609ffb78
address of var: 0x7ff70cbc7030
address of var: 0x7ff70cbc7030
```

![image](https://github.com/user-attachments/assets/1ed9e3c7-c0b0-483a-8df2-cc0e9283a1fe)

<br>

</p>
</details>

<details><summary><b>📚 Static Method</b></summary>
<p>

- Static method là một method thuộc về class thay vì object của class.
- Static method có thể gọi ra mà không cần tạo đối tượng của class.
- Static method chỉ có thể truy cập các thành viên static khác của class (cả thuộc tính và phương thức).
- Static method sẽ không có con trỏ ``` this ``` vì không được gọi từ đối tượng.

💻 **Ví dụ:**
```cpp
#include <iostream>

using namespace std;

class MyClass
{
public:
    // Static method
    static void showMessage()
    {
        cout << "This is a static method." << endl;
    }

    // Static variable
    static int count;

    // Static method to manipulate static variable
    static void increaseCount()
    {
        count++;
    }
};

// Khởi tạo biến static
int MyClass::count = 0;

int main()
{
    // Gọi static method mà không cần tạo đối tượng
    MyClass::showMessage();

    // Gọi static method để thao tác với biến static
    MyClass::increaseCount();
    cout << "Count: " << MyClass::count << endl;

    return 0;
}
```

<br>

</p>
</details>

</p>
</details>

<details><summary><b>6. This Pointer </b></summary>
<p>

- this là một con trỏ đặc biệt có sẵn trong tất cả các method thành viên của class. Nó trỏ đến object hiện tại đang gọi method đó.
- this là hằng con trỏ (constant pointer), nghĩa là this luôn trỏ tới đối tượng hiện tại và bạn không thể thay đổi để this trỏ tới đối tượng khác. Tuy nhiên, giá trị của đối tượng mà this trỏ tới có thể thay đổi trừ khi hàm thành viên được khai báo là const.
- this chỉ tồn tại trong các method (ngoại trừ static method) của class.
- this tự động được truyền khi bạn gọi method của một object.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>

using namespace std;

class Student
{
    private:
        int age;

    public:
        Student(int age)
        {
            this->age = age; 	// Sử dụng 'this' để tham chiếu đến thành viên 'age' của đối tượng hiện tại
        }

        Student& setAge(int age)
        {
            this->age = age;
            return *this; 	// Trả về đối tượng hiện tại
        }

        void display()
        {
            cout << "Age: " << this->age << endl;
        }
};

int main()
{
    Student s1(20);
    s1.setAge(21).setAge(22); // Gọi liên tiếp các phương thức
    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <string>

using namespace std;

class Person
{
    private:
        string name;
        int age;
        int id;
    
    public:
        Person(string name, int age)
        {
            static int newID = 0;
            newID++;
            this->id = newID;

            // this = nullptr;
            this->name = name;  // this: constant pointer
            this->age  = age;
        }

        void setName(string newName)
        {
            this->name = newName;
        }

        void setAge(int newAge)
        {
            
            this->age = newAge;
        }

        void changeInfo(string name, int age)
        {
            this->setName(name);
            this->setAge(age);
        }

        string getName() const
        {
            return this->name;
        }

        int getAge() const
        {
            return this->age;
        }

        int getID() 
        {
            return this->id;
        }

        void showAddress()
        {
            cout << "Address of this pointer: " << this << endl;
        }

        void display()
        {
            cout << "Name: " << this->getName() << endl;
            cout << "ID: " << this->getID() << endl;
            cout << "Age: " << this->getAge() << endl;
        }
};

int main(int argc, char const *argv[])
{
    Person person1("Trung", 20);
    Person person2("Anh", 22);

    cout << "Address of object 1: " << &person1 << endl;
    person1.showAddress();

    cout << "Address of object 2: " << &person2 << endl;
    person2.showAddress();

    person1.display();

    person2.display();
    person2.changeInfo("Tuan", 25);
    person2.display();
    return 0;
}
```

<br>

</p>
</details>

</p>
</details>

<br>

<details><summary><b>Object Oriented Programming (OOP)</b></summary>
<p>

<details><summary><b>1. Tính đóng gói (Encapsulation) </b></summary>
<p>

- Là việc che giấu thông tin bên trong đối tượng, chỉ cung cấp những gì cần thiết ra bên ngoài thông qua các phương thức (method). Điều này giúp bảo vệ dữ liệu và giảm rủi ro không mong muốn.
- Những thông tin được lưu ở các thuộc tính (property) sẽ bị ẩn đi bằng cách khai báo ở quyền truy cập ``` private/protected ```.
- Trong trường hợp muốn đọc hoặc ghi các property này thì chỉ có thể truy cập gián tiếp thông qua các method ở quyền truy cập ``` public ```.

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <string>
#include <cctype>   // isdigit, isalpha
using namespace std;

/**
 * @class   SinhVien
 * @brief   Lớp đại diện cho thông tin của sinh viên.
 * @details Lớp này bao gồm các thuộc tính như tên, ID, GPA, 
 *          các phương thức để thiết lập và lấy thông tin của sinh viên.
 */
class SinhVien
{
    private:
        string name;   /**< Tên sinh viên */                    // tính đóng gói
        int id;        /**< ID sinh viên  */                    // tính đóng gói
        double gpa;    /**< Điểm trung bình */                  // tính đóng gói

       /**
        * @brief Kiểm tra tính hợp lệ của tên sinh viên.
        * @param[in] str Chuỗi tên cần kiểm tra.
        * @return true nếu hợp lệ, false nếu có ký tự không phải chữ cái.
        */
        bool checkName(string str)      // tính trừu tượng
        {
            for (int i=0; i<str.length(); i++)
            {
                if (isdigit(str[i]) || !isalpha(str[i])) return false;
            }
            return true;
        }


       /**
        * @brief Kiểm tra điểm GPA hợp lệ.
        * @param[in] newGPA Giá trị GPA cần kiểm tra.
        * @return true nếu GPA hợp lệ (0 - 10), false nếu không hợp lệ.
        */
        bool checkGPA(double newGPA)
        {
            if (newGPA < 0 || newGPA > 10) return false;
            return true;
        }

    public:
       /**
        * @brief Constructor của lớp SinhVien.
        * @details Gán giá trị ID tự động tăng khi tạo mới đối tượng.
        */
        SinhVien()
        {
            static int _ID = 1;
            id = _ID;
            _ID++;
        }

       /**
        * @brief Thiết lập tên sinh viên.
        * @param[in] newName Tên mới của sinh viên.
        * @details Nếu tên không hợp lệ, gán giá trị rỗng và hiển thị thông báo lỗi.
        */
        void setName(string newName)
        {
            // kiểm tra chuỗi đầu vào có hợp lệ hay không?
            if (checkName(newName)){
                name = newName;
            } else {
                name = "";
                cout << "Tên không hợp lệ!. Vui lòng nhập lại tên\n";
            }   
        }

       /**
        * @brief Lấy tên sinh viên.
        * @return Tên sinh viên dưới dạng chuỗi.
        */
        string getName() const { return name; }

       /**
        * @brief Lấy ID của sinh viên.
        * @return ID của sinh viên.
        */
        int getId() const { return id; }

       /**
        * @brief Thiết lập GPA cho sinh viên.
        * @param[in] newGPA Giá trị GPA cần thiết lập.
        * @details Nếu GPA không hợp lệ, đặt về 0.0 và hiển thị thông báo lỗi.
        */
        void setGPA(double newGPA)
        {
            if (checkGPA(newGPA)){
                gpa = newGPA;
            } else {
                gpa = 0.0;
                cout << "Điểm nhập vào không hợp lệ!. Vui lòng nhập lại\n";
            }
        }

       /**
        * @brief Lấy GPA của sinh viên.
        * @return Giá trị GPA của sinh viên.
        */
        double getGPA() const { return gpa; }
        
       /**
        * @brief Hiển thị thông tin của sinh viên.
        * @details In ra màn hình tên, ID và GPA của sinh viên.
        */
        void display()
        {
            cout << "Tên: " << getName() << endl;
            cout << "ID: " << getId() << endl;
            cout << "GPA: " << getGPA() << endl << endl;
        }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1;
    SinhVien sv2;

    // sv1.name = "Anh1123@@@";
    // sv2.name = "Trung";

    // sv1.id = 1;
    // sv2.id = 1;

    sv1.setName("Anh");
    sv1.setGPA(11);
    sv1.display();

    sv2.setName("Trung");
    sv2.setGPA(8.5);
    sv2.display();
    return 0;
}
```

<br>

<br>

</p>
</details>

<details><summary><b>2. Tính kế thừa (Inheritance) </b></summary>
<p>

- Kế thừa cho phép một class mới có thể sử dụng lại các thuộc tính và phương thức của một class đã có, và có thể mở rộng thêm tính năng. (tạm gọi là class con kế thừa từ class cha).
- Để kế thừa từ class khác, ta dùng ký tự ``` : ```.
- Tất cả thuộc tính và phương thức có quyền truy cập là ``` public ``` và ``` protected ``` ở class cha sẽ được class con kế thừa.
- Có 3 kiểu kế thừa là public, private và protected.

<details><summary><b>📚 Public Inheritance</b></summary>
<p>

- Các member **public** của **class cha** vẫn sẽ là **public** trong **class con**.
- Các member **protected** của **class cha** vẫn sẽ là **protected** trong **class con**.
- Các member **private** của class cha **không thể truy cập trực tiếp từ class con** nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <string>

using namespace std;

class Person
{
    protected:
        // các member nằm trong protected thì object sẽ không truy cập đến được
        // nhưng các class con kế thừa từ class cha thì có thể truy cập được
        string Name;
        int Age;
        string Home_Address;

    public:
        string getName(){           // getter   // đọc giá trị của property
            return this->Name;
        }
        void setName(string name){  // setter   // ghi giá trị của property
            this->Name = name;
        }

        int getAge(){               // getter
            return this->Age;
        }
        void setAge(int age){       // setter
            this->Age = age;
        }

        string getAddress(){                // getter
            return this->Home_Address;
        }
        void setAddress(string address){    // setter
            this->Home_Address = address;
        }

        void displayInfo(){
            cout << "Name: " << Name << endl;
            cout << "Age: " << Age << endl;
            cout << "Address: " << Home_Address << endl;
        }
};

class Student : public Person
{
    private:
        string School_Name;
        double GPA;
        int StudentID;

    public:
        Student(){
            static int id = 1000;
            Student::StudentID = id;
            id++;
        }

        string getSchoolName(){
            return Student::School_Name;
        }
        void setSchoolName(string school_name){
            Student::School_Name = school_name;
        }

        double getGPA(){
            return Student::GPA;
        }
        void setGPA(double gpa){
            Student::GPA = gpa;
        }

        int getID(){
            return Student::StudentID;
        }

        void displayInfo(){ // override
            cout << "Name: " << Student::Name << endl;
            cout << "Age: " << Student::Age << endl;
            cout << "Address: " << Student::Home_Address << endl;
            cout << "School name: " << Student::School_Name << endl;
            cout << "GPA: " << Student::GPA << endl;
        }
};

int main(){
    Person person1;
    person1.setName("Trung");
    person1.setAge(20);
    person1.setAddress("HCM");
    person1.displayInfo();

    cout << "-----------------------" << endl;
    
    Student student1;
    student1.setName("Trungg");
    student1.setAge(24);
    student1.setAddress("HCMM");
    student1.setGPA(8.1);
    student1.setSchoolName("DinhTienHoang");
    student1.displayInfo();
    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <string>

using namespace std;

class DoiTuong
{ 
    // private:
    //     int id;   
    //     string name;

    protected:
        string ten;
        int id;

    public:
        DoiTuong()
        {
            static int newID = 1;
            id = newID;
            newID++;
        }

        void setName(string newName)
        {
            ten = newName;
        }

        string getName() const
        {
            return ten;
        }

        int getID() const
        {
            return id;
        }

        void display()
        {
            cout << "ID: " << id << endl;
            cout << "Tên: " << ten << endl;
        }
};

class SinhVien : public DoiTuong
{
    private:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh)
        {
            chuyenNganh = _nganh;
        }

        void display()  // overload
        {
            DoiTuong::display();
            cout << "Chuyên ngành: " << chuyenNganh << endl << endl;
        }
};

class HocSinh : public DoiTuong
{    
    private:
        string lop;

    public:
        void setLop(string _lop)
        {
            lop = _lop;
        }

        void display()  // overload
        {
            DoiTuong::display();
            cout << "Lớp: " << lop << endl << endl;
        }
};

class GiaoVien : public DoiTuong
{
    private:
        string chuyenMon;

    public:
        void setChuyenMon(string _mon)
        {
            chuyenMon = _mon;
        }

        void display()  // overload
        {
            DoiTuong::display();
            cout << "Chuyên môn: " << chuyenMon << endl << endl;
        }
};

int main(int argc, char const *argv[])
{
    DoiTuong dt1("Hoang");
    dt1.display();
    cout << endl;

    SinhVien sv1("Tuan","DTVT");
    sv1.display();
    cout << endl;

    HocSinh hs1("Trung", "12A1");
    hs1.display();
    cout << endl;

    GiaoVien gv1("Bao", "Toan");
    gv1.display();
    cout << endl;

    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>📚 Protected Inheritance</b></summary>
<p>

- Các member **public, protected** của class cha sẽ là **protected** trong class con.
- Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>

using namespace std;

class Base
{
    protected:
        int protectedVar;

    public:
        Base(): protectedVar(10){}
        void showProtectedVar()
	{
            cout << "Protected variable: " << protectedVar << endl;
        }
};

class Derived : protected Base
{
    public:
        void accessBaseMembers()
	{
            // Có thể truy cập protectedVar vì nó được kế thừa dưới dạng protected
            cout << "Accessing protectedVar from Base: " << protectedVar << endl;
        }
};

int main()
{
    Derived obj;
    obj.accessBaseMembers();

    // Không thể truy cập trực tiếp thành viên protected từ đối tượng class con
    // obj.protectedVar; // Lỗi: không thể truy cập trực tiếp
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <string>

using namespace std;

class DoiTuong
{ 
    // private:
    //     int id;   
    //     string name;

    protected:
        int id;   
        string name;      

    public:
        DoiTuong(string newName){
            static int _id = 1;
            id = _id;
            _id++;

            // check chuỗi nhập vào, tránh có ký tự đặc biệt, số, space,...
            name = newName;
        }

        // getter
        int getID(){
            return id;
        }

        string getName(){
            return name;
        }

        void display(){
            cout << "Ten: " << getName() << endl;
            cout << "ID: " << getID() << endl;
        }
};

class SinhVien : protected DoiTuong
{
    private:
        string chuyenNganh;

    public:
        SinhVien(string name, string chuyenNganh): DoiTuong(name){
            SinhVien::chuyenNganh = chuyenNganh;
        }

        string getChuyenNganh(){
            return chuyenNganh;
        }

        void display(){
            cout << "Ten: " << SinhVien::getName() << endl;
            cout << "ID: " << SinhVien::getID() << endl;
            cout << "Chuyen nganh: " << SinhVien::getChuyenNganh() << endl;
        }
};

int main(int argc, char const *argv[])
{
    DoiTuong dt1("Hoang");
    dt1.display();

    cout << endl;

    SinhVien sv1("Tuan","DTVT");
    sv1.display();
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>📚 Private Inheritance</b></summary>
<p>

- Các member **public, protected** của class cha sẽ trở thành **private** trong class con.
- Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha.

<br>

💻 **Ví dụ**
```cpp
#include <iostream>

using namespace std;

class Base
{
    protected:
        int protectedVar;

    public:
        int publicVar;
        Base(): protectedVar(10), publicVar(20){}
};

class Derived : private Base
{
    public:
        void accessBaseMembers()
        {
            // Có thể truy cập protectedVar và publicVar bên trong class con
            cout << "protectedVar: " << protectedVar << endl;
            cout << "publicVar: " << publicVar << endl;
        }
};

int main()
{
    Derived obj;
    obj.accessBaseMembers();

    // Không thể truy cập trực tiếp thành viên của Base qua đối tượng Derived
    // obj.publicVar; // Lỗi: không thể truy cập vì publicVar đã trở thành private trong Derived
}
```

<br>

</p>
</details>

<details><summary><b>📚 Multiple Inheritance</b></summary>
<p>

- Đa kế thừa trong C++ cho phép một class kế thừa từ nhiều class khác.
- Đa kế thừa thường dùng để kết hợp các chức năng từ nhiều class.

💻 **Ví dụ:**
```cpp
#include <iostream>

using namespace std;

class Sensor
{
    public:
        void initialize()
        {
            cout << "Initializing sensor" << endl;
            // code khởi tạo cảm biến
        }

        int readData()
        {
            cout << "Reading sensor data" << endl;
            // code đọc dữ liệu cảm biến
            return 30;
        }
};

class Communication
{
    public:
        void setupCommunication()
        {
            cout << "Setting up communication protocol" << endl;
            // code thiết lập giao thức truyền thông (SPI, I2C, UART,...)
        }

        void sendData(int data)
        {
            cout << "Sending data: " << data << endl;
            // code gửi dữ liệu qua các giao thức
        }
};

class Control : public Sensor, public Communication
{
    public:
        Control()
        {
            setupCommunication();

            initialize();

            int data = readData();

            sendData(data);
        }
};

int main(int argc, char const *argv[])
{
    Control sensorControl;
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>📚 Virtual Inheritance</b></summary>
<p>

- Khi một lớp con kế thừa từ hai lớp cha, và hai lớp cha này đều kế thừa từ một lớp chung (gốc), thì lớp chung đó có thể bị kế thừa nhiều lần, dẫn đến việc dữ liệu từ lớp chung bị sao chép, gây ra các xung đột dữ liệu hoặc không nhất quán. Đây được gọi là vấn đề kim cương (Diamond problem).

💻 **Ví dụ:**
```cpp
#include <iostream>

using namespace std;

class A
{
    public:
        A(){ cout << "Constructor A\n"; }

        void hienThiA(){ cout << "Day la lop A\n"; }
};

class B : public A
{
    public:
        B(){ cout << "Constructor B\n"; }

        void hienThiB(){ cout << "Day la lop B\n"; }
};

class C : public A
{
    public:
        C(){ cout << "Constructor C\n"; }

        void hienThiC(){ cout << "Day la lop C\n"; }
};

class D : public B, public C{
    public:
        D(){ cout << "Constructor D\n"; }

        void hienThiD(){ cout << "Day la lop D\n"; }
};

int main()
{
    D d;
    d.hienThiA();
    return 0;
}
```
**Kết quả**:
``` error: request for member 'hienThiA' is ambiguous ```

📝 lớp D sẽ có hai phiên bản của class A, một từ B và một từ C, dẫn đến vấn đề đa kế thừa "diamond problem". 

📝 Muốn gọi method ``` hienThiA ``` thì ta phải chỉ định rõ ràng là gọi từ class nào. Ví dụ: ``` d.B::hienThiA() ``` hoặc ``` d.C::hienThiA() ```

📝 Không thể gọi trực tiếp method ``` hienThiA ``` vì lúc này compiler không biết nên gọi từ class nào.

<br>

Để khắc phục vấn đề trên thì ngoài việc chỉ định rõ ràng là gọi từ class nào, ta có thể thêm vào từ khóa ``` virtual ``` khi các class cha (class cơ sở) kế thừa từ class chung. Điều này giúp tạo ra một bản sao duy nhất của các thành phần được kế thừa từ class chung.

💻 **Ví dụ:**
```cpp
#include <iostream>

using namespace std;

class A
{
    public:
        A(){ cout << "Constructor A\n"; }

        void hienThiA(){ cout << "Day la lop A\n"; }
};

class B : virtual public A
{
    public:
        B(){ cout << "Constructor B\n"; }

        void hienThiB(){ cout << "Day la lop B\n"; }
};

class C : virtual public A
{
    public:
        C(){ cout << "Constructor C\n"; }

        void hienThiC(){ cout << "Day la lop C\n"; }
};

class D : public B, public C
{
    public:
        D(){ cout << "Constructor D\n"; }

        void hienThiD(){ cout << "Day la lop D\n"; }
};

int main() {
    D d;

    d.hienThiA();

    // Gọi phương thức từ lớp A qua B và C
    // d.B::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua B
    // d.C::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua C

    d.hienThiB();
    d.hienThiC();
    d.hienThiD();

    return 0;
}
```

<br>

</p>
</details>

</p>
</details>

<details><summary><b>3. Polymorphism </b></summary>
<p>

- Tính đa hình là khả năng cho phép một phương thức có thể hoạt động theo nhiều cách khác nhau, tùy thuộc vào ngữ cảnh hoặc đối tượng đang gọi nó.
- Tính đa hình có thể được chia thành hai loại chính:
	+ Đa hình tại thời điểm biên dịch (**Compile-time Polymorphism**): được thực hiện thông qua nạp chồng hàm (function overloading) hoặc nạp chồng toán tử (operator overloading).
 	+ Đa hình tại thời điểm chạy (**Run-time Polymorphism**): được thực hiện thông qua các phương thức ảo (virtual methods) và ghi đè phương thức (method overriding).

<br>

<details><summary><b>📚 Compile Time Polymorphism</b></summary>
<p>

<details><summary><b>📚📚 Nạp chồng hàm (Function Overloading)</b></summary>
<p>

Nạp chồng hàm (Function Overloading) xảy ra khi các phương thức trong cùng một lớp có cùng tên nhưng khác nhau về số lượng hoặc kiểu tham số. Compiler sẽ xác định method nào sẽ được gọi dựa trên tham số truyền vào.

<br>

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <string>
using namespace std;

// 1 method có thể có nhiều input parameter khác nhau
class TinhToan
{
    private:
        int a;
        int b;

    public:
        int tong(int a, int b)
 	{
            return a+b;
        }

	double tong(int a, double b)
	{
            return (double)a+b;
        }

	double tong(double a, double b)
	{
            return (double)a+b;
	}

        double tong(int a, int b, int c, double d)
	{
            return (double)a+b+c+d;
        }
};

int main(int argc, char const *argv[])
{
    TinhToan th, th1, th2, th3;
    cout << th.tong(2, 5) << endl;
    cout << th1.tong(2, 5, 7, 6.7) << endl;
    cout << th2.tong(2, 3.5) << endl;
    cout << th3.tong(2.5, 3.5) << endl;
    return 0;
}
```
📝 Viết method tính tổng, có thể là tổng của 2,3,4 hoặc nhiều hơn, hoặc là các tham số truyền vào khác nhau. Khi khởi tạo object và gọi method thì lúc đó nó sẽ căn cứ vào tham số truyền vào để biết là nó sẽ lấy method nào.

📝 Quá trình trên đểu xảy ra ở compiler, nghĩa là khi ta đưa các tham số đầu vào thì nó căn cứ vào đó và bắt đầu generate ra code.

📝 Trong C++ thì việc nhiều hàm có cùng tên nhưng khác nhau tham số đầu vào và kiểu dữ liệu trả về vẫn có thể nằm toàn cục chứ không nhất thiết phải nằm trong class.

<br>

</p>
</details>

<details><summary><b>📚📚 Nạp chồng toán tử (Operator Overloading)</b></summary>
<p>

Các toán tử như ``` +, -, *, /, ^, |, &, v.v ``` sẽ mặc định cho các biến có kiểu dữ liệu nguyên thủy (int, double, float, short, char, v.v) nhưng các kiểu dữ liệu tự định nghĩa thì không được phép, muốn sử dụng phải định nghĩa lại.

Nạp chồng toán tử (Operator Overloading) trong C++ là một tính năng cho phép bạn định nghĩa lại các toán tử để chúng hoạt động theo cách mà bạn mong muốn đối với các kiểu dữ liệu do người dùng định nghĩa (như class hoặc struct).

Khi bạn muốn nạp chồng một toán tử, bạn cần định nghĩa một hàm có từ khóa ``` operator ``` theo sau là ``` ký hiệu toán tử ``` mà bạn muốn nạp chồng.

Cú pháp: 

```cpp
<return_type> operator symbol (parameters)
{
	// logic của toán tử
}
```

Trong đó:

- **return_type**: Kiểu dữ liệu trả về của hàm (method).
- **operator symbol**: Toán tử mà bạn muốn nạp chồng.
- **parameters**: Các tham số truyền vào (tối đa một tham số (do bản chất toán học) với hầu hết các toán tử nhị phân (+, -, *, /, ...),  các toán tử đơn nguyên (++, --, !, ~) thường chỉ hoạt động trên this và không cần tham số. ).

**Các toán tử có thể overload được:**
```cpp
+	–	*	/	%	^	&	|
~	!	=	<	>	+=	-=	*=
/=	%=	^=	&=	|=	<<	>>	>>=
<<=	==	!=	<=	>=	&&	||	++
—	->*	,	->	[]	()	new	delete
new[]	delete[]
```

**Một số toán tử sau không overload được:**

- Toán tử . (chấm)
- Toán tử phạm vi ::
- Toán tử điều kiện ?:
- Toán tử sizeof

<br>

💻 **Ví dụ 1: Số phức**
```cpp
#include <iostream>

using namespace std;

class Complex
{
    private:
        double realPart;    // phần thực
        double imagPart;    // phần ảo
    
    public:
        Complex(double real = 0, double imag = 0): realPart(real), imagPart(imag){}

        // nạp chồng toán tử +
        Complex operator + (const Complex& other) const
    	{
            Complex result;
            result.realPart = this->realPart + other.realPart;
            result.imagPart = this->imagPart + other.imagPart;
            return result;
        }

        // nạp chồng toán tử so sánh bằng (==)
        bool operator == (const Complex& other) const
	{
            return (this->realPart == other.realPart && this->imagPart == other.imagPart);
        }

        // hàm hiển thị
        void display() const
	{
            cout << realPart << " + " << imagPart << "i" << endl;
        }
};

int main() 
{
    Complex c1(3,4);
    Complex c2(5,6);
    Complex c3 = c1 + c2;
    c1.display();
    c2.display();
    c3.display();

    if (c1 == c2){
        cout << "Hai số phức bằng nhau" << endl;
    } else {
        cout << "Hai số phức không bằng nhau" << endl;
    }
    return 0;
}
```

<br>

💻 **Ví dụ 2: Phân số**
```cpp
#include <iostream>
using namespace std;

class PhanSo
{
    private:
        int numerator;   // Tử số
        int denominator; // Mẫu số

        // Hàm tìm Ước Chung Lớn Nhất (Greatest Common Divisor - GCD)
        int gcd(int a, int b) const
	{
            return (b == 0) ? a : gcd(b, a % b);
        }

        // Hàm rút gọn phân số
        void simplify()
	{
            int divisor = gcd(numerator, denominator);
            numerator /= divisor;
            denominator /= divisor;
        }

    public:
        PhanSo(int num = 0, int den = 1): numerator(num), denominator(den)
	{
            if (!denominator)
            {
                throw invalid_argument("Mẫu số phải khác 0!");
            }
        }

        // nạp chồng toán tử nhân (*)
        PhanSo operator * (const PhanSo& other) const
	{
            // other.tu = 11;
            // other.mau = 13;
	    // this->tu = 100;
	    // this->mau = 200;
            PhanSo ketqua;
            ketqua.numerator   = this->numerator   * other.numerator;
            ketqua.denominator = this->denominator * other.denominator;
            ketqua.simplify();
            return ketqua;
        }
        
        // nạp chồng toán tử cộng (+)
        PhanSo operator + (const PhanSo& other) const
	{
            PhanSo ketqua;
            ketqua.numerator = this->numerator * other.denominator + this->denominator * other.numerator;
            ketqua.denominator = this->denominator * other.denominator;
            ketqua.simplify();
            return ketqua;
        }

        // nạp chồng toán tử so sánh bằng (==)
        bool operator == (const PhanSo& other) const
	{
            return (this->numerator == other.numerator && this->denominator == other.denominator);
        }

        // nạp chồng toán tử nhập (>>)
        friend istream& operator >> (istream& input, PhanSo& f)
	{
            cout << "Nhập tử số: ";
            input >> f.numerator;

            cout << "Nhập mẫu số: ";
            input >> f.denominator;

            if (!f.denominator)
	    {
                throw invalid_argument("Mẫu số phải khác 0!");
            }
            return input;
        }

        // nạp chồng toán tử xuất (<<)
        friend ostream& operator << (ostream& output, const PhanSo& f)
	{
            output << f.numerator << "/" << f.denominator;
            return output;
        }

        void display()
	{
            cout << "Tu: " << numerator << " , mau: " << denominator << endl;
        }
};

int main(int argc, char const *argv[])
{
    try
    {
        PhanSo p1(1, 2);             // 0xc8
        PhanSo p2(4, 6);             // 0xa5
        PhanSo p3 = p1 * p2;

        p1.display();
        p2.display();
        p3.display();

        if (p1 == p2){
            cout << "p1 = p2" << endl;
        } else {
            cout << "p1 # p2" << endl;
        }

        PhanSo p4, p5, p6;
        cout << "Nhập phân số p4:\n";
        cin >> p4;

        cout << "Nhập phân số p5:\n";
        cin >> p5;

        p6 = p4 + p5;
        cout << p6;
    }
    catch (const invalid_argument& e) 		// Bắt ngoại lệ invalid_argument
    {      
        cout << "Lỗi: " << e.what() << endl;  	// Hiển thị thông báo lỗi
    }
    
    return 0;
}
```

📝 **Toán tử cộng (+)**: dùng để cộng 2 phân số.

📝 **Toán tử nhân (*)**: dùng để nhân 2 phân số.

📝 Sau khi tính toán sẽ tự động rút gọn phân số kết quả thông qua gọi method ``` simplify() ```.

📝 **Toán tử so sánh bằng (==)**: so sánh hai phân số đã được rút gọn để xem chúng có bằng nhau hay không. Nếu tử số và mẫu số của hai phân số bằng nhau, thì chúng bằng nhau.

📝 **Toán tử nhập (>>)**: Toán tử nhập cho phép người dùng nhập tử số và mẫu số từ bàn phím. 

📝 **Toán tử xuất (<<)**: Toán tử xuất hiển thị phân số theo định dạng "tử số/mẫu số".

📝 **try**: một khối lệnh chứa các câu lệnh mà bạn muốn theo dõi các ngoại lệ. Nếu một ngoại lệ xảy ra trong khối try, chương trình sẽ lập tức dừng thực thi các lệnh tiếp theo trong khối try và chuyển sang tìm kiếm khối catch thích hợp để xử lý ngoại lệ.

📝 **catch**: bắt các ngoại lệ được ném ra từ khối try. Nếu một ngoại lệ xảy ra, nó sẽ được bắt ở khối catch tương ứng, và chương trình sẽ thực thi các lệnh trong khối catch để xử lý ngoại lệ đó.

📝 **throw**: là từ khóa được sử dụng để ném một ngoại lệ (exception). Khi một vấn đề xảy ra, chương trình có thể phát hiện lỗi đó và ném ngoại lệ với từ khóa throw. Ngoại lệ này sẽ được chuyển lên chuỗi các lệnh cho đến khi nó được bắt bởi một khối lệnh catch tương ứng.

<br>

</p>
</details>

</p>
</details>

<details><summary><b>📚 Run Time Polymorphism</b></summary>
<p>

Đa hình tại thời điểm chạy hay còn gọi là đa hình ghi đè (**overriding**), đa hình động xảy ra khi một lớp con ghi đè lại một phương thức của lớp cha và phương thức này được gọi thông qua con trỏ hoặc tham chiếu đến lớp cha. Phương thức của lớp con sẽ được gọi tại thời điểm thực thi, không phải lúc biên dịch.

<details><summary><b>📚📚 up-casting & down-casting </b></summary>
<p>

</p>
</details>

<details><summary><b>📚📚 Virtual Function </b></summary>
<p>

- Virtual Function (hàm ảo) là một hàm thành viên được khai báo trong lớp cha với từ khóa ``` virtual ```.
- Khi một hàm là virtual, nó có thể được ghi đè (``` override ```) trong các lớp con.
- Khi gọi một hàm ảo thông qua một con trỏ hoặc tham chiếu đến lớp con, hàm sẽ được quyết định dựa trên đối tượng thực tế mà con trỏ hoặc tham chiếu đang trỏ tới chứ không dựa vào kiểu của con trỏ.

<br>

💻 **Ví dụ:**
```cpp
class Base
{
	public:
	    virtual void display() { cout << "Display from Base class" << endl; }
};
```

<br>

</p>
</details>

<details><summary><b>📚📚 Override </b></summary>
<p>

- Các lớp con có thể ghi đè hàm ảo bằng cách định nghĩa lại nó.
- Khi một hàm ảo được ghi đè, hành vi của nó sẽ phụ thuộc vào kiểu của đối tượng thực tế, chứ không phải kiểu của con trỏ hay tham chiếu.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>
using namespace std;

class cha
{
    public:
        virtual void display()		// Hàm ảo
	{                            
            cout << "display from class cha" << endl;
        }
};

class con : public cha
{
    public:
        void display() override		// Ghi đè hàm ảo
	{                           
            cout << "display from class con" << endl;
        }
};

int main()
{
    cha *ptr;
    con obj;

    // trỏ con trỏ class cha đến đối tượng class con
    ptr = &obj;

    // Gọi hàm ảo
    ptr->display();
}
```
**Kết quả**:
```cpp
display from class con
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        virtual void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : public DoiTuong{
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void display() override {
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};

class HocSinh : public DoiTuong{
    protected:
        string lop;
   
    public:
        void setLop(string _lop){
            lop = _lop;
        }

        void display() override {
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "lop: " << lop << endl;
        }
};

class GiaoVien : public DoiTuong{
    protected:
        string chuyenMon;

    public:
        void setChuyenMon(string _mon){
            chuyenMon = _mon;
        }

        void display() override {
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen mon: " << chuyenMon << endl;
        }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1;
    sv1.setName("Trung");
    sv1.setChuyenNganh("TDH");

    HocSinh hs1;
    hs1.setName("Tuan");
    hs1.setLop("12A1");

    GiaoVien gv1;
    gv1.setName("Hoang");
    gv1.setChuyenMon("Toan");

    DoiTuong *dt;

    dt = &sv1;
    dt->display();

    dt = &hs1;
    dt->display();

    dt = &gv1;
    dt->display();


    // DoiTuong *ptr[] = {&sv1, &hs1, &gv1};

    // ptr[0]->display();
    // ptr[1]->display();
    // ptr[2]->display();

    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>📚📚 Pure Virtual Function </b></summary>
<p>

- Hàm thuần ảo là một hàm ảo không có phần định nghĩa trong class cha, được khai báo với cú pháp = 0 và khiến class cha trở thành class trừu tượng, nghĩa là không thể tạo đối tượng từ class này.

💻 **Ví dụ:**
```cpp
#include <iostream>
using namespace std;

class Base
{
    public:
        virtual void display() = 0;
};

int main(int argc, char const *argv[])
{
    Base baseObj;	// error: cannot declare variable 'baseObj' to be of abstract type 'Base'
    return 0;
}
```

<br>

- Hàm thuần ảo phải được ghi đè trong class con và chỉ các class con đã ghi đè tất cả các Hàm thuần ảo mới có thể tạo ra đối tượng.

💻 **Ví dụ:**
```cpp
#include <iostream>
using namespace std;

class cha
{
    public:
        virtual void display() = 0; // Hàm thuần ảo
};

class con : public cha
{
    public:
        void display() override     // Ghi đè Hàm thuần ảo
        {   
            cout << "display from class con" << endl;
        }
};

int main()
{
    cha *ptr;
    con obj;

    ptr = &obj;
    ptr->display(); // Output: display from class con

    return 0;
}
```

📝 Con trỏ ptr là của class cha, nhưng nó trỏ đến đối tượng của class con.

📝 Method display() trong class cha được khai báo là hàm thuần ảo, vì vậy khi gọi ``` ptr->display() ```, C++ sẽ kiểm tra xem đối tượng thực sự mà ptr trỏ tới là gì, và cụ thể ở đây là object ``` obj ``` của class con và nó gọi hàm ``` display() ``` của class con.

📝 Đây là **đa hình**: Cùng một giao diện, nhưng hành vi thực tế khác nhau dựa trên kiểu của đối tượng thực sự.

<br>

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <string>

using namespace std;

class Xe
{
    public:
        virtual void hienThiThongTin() = 0;
};

class Toyota : public Xe
{
    private:
        string model;
        int namSanXuat;
        string dongCo;

    public:
        Toyota(string m, int nam, string dongCo): model(m), namSanXuat(nam), dongCo(dongCo){}

        void hienThiThongTin() override
        {
            cout << "Hang xe: Toyota\n";
            cout << "Model: " << model << "\n";
            cout << "Nam san xuat: " << namSanXuat << "\n";
            cout << "Dong co: " << dongCo << "\n";
        }
};

class Honda : public Xe{
    private:
        string model;
        int namSanXuat;
        string mauSac;

    public:
        Honda(string m, int nam, string mau): model(m), namSanXuat(nam), mauSac(mau){}

        void hienThiThongTin() override {
            cout << "Hang xe: Honda\n";
            cout << "Model: " << model << "\n";
            cout << "Nam san xuat: " << namSanXuat << "\n";
            cout << "Mau sac: " << mauSac << "\n";
        }
};

class Mazda : public Xe{
    private:
        string model;
        int namSanXuat;
        string loaiDanDong;

    public:
        Mazda(string m, int nam, string loaiDanDong): model(m), namSanXuat(nam), loaiDanDong(loaiDanDong){}

        void hienThiThongTin() override {
            cout << "Hang xe: Mazda\n";
            cout << "Model: " << model << "\n";
            cout << "Nam san xuat: " << namSanXuat << "\n";
            cout << "Loai dan dong: " << loaiDanDong << "\n";
        }
};

int main() {
    // Toyota to;
    // Honda ho;
    // Mazda mz;
    // Xe *xe;

    // xe = &to;
    // xe->hienThiThongTin();
   
    Mazda cx3("CX-3", 2019, "Dan dong 4 banh");

    Xe *ptr[] = {new Toyota("campry", 2020, "V6"),
                 new Honda("civic", 2019, "do"),
                 new Mazda("CX-5", 2021, "Dan dong 4 banh"),
                 new Toyota("corolla", 2018, "I4 1.8L"),
                 new Honda("accord", 2020, "den"),
                 &cx3};
   
    for (int i=0; i<6; i++){
        ptr[i]->hienThiThongTin();
        cout << "--------------" << endl;
        delete ptr[i];
    }

    return 0;
}
```

<br>

</p>
</details>

</p>
</details>

</p>
</details>

<details><summary><b>4. Abstraction </b></summary>
<p>

- Trừu tượng hóa và việc chỉ ra những thông tin quan trọng nhất của đối tượng, giấu đi nhưng chi tiết phức tạp không cần thiết (logic xử lý, thuật toán để đưa ra kết quả cuối cùng), giúp tập trung vào cách sử dụng đối tượng hơn là cách nó được thực hiện.

<br>

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class PTBH
{
    private:    // x1, x2 là tính đóng gói
        double x1;
        double x2;
        double a,b,c;

        double delta()
	{
            return (double)(b*b - 4*a*c);
        }

        void ketqua()
	{
            if (PTBH::delta() < 0)
	    {
                cout << "PTVN" << endl;
            }
            else if (PTBH::delta() == 0)
	    {
                cout << "x1 = x2 = " << (double)(-b/(2*a)) << endl;
            }
            else
	    {
                cout << "x1 = " << (-b + sqrt(delta()))/(2*a) << endl;
                cout << "x2 = " << (-b - sqrt(delta()))/(2*a) << endl;
            }
        
	
    public:
        void printResult(double a, double b, double c)
	{
            PTBH::a = a;
            PTBH::b = b;
            PTBH::c = c;
            ketqua();
        }
};

int main(int argc, char const *argv[])
{
    PTBH phuongtrinh1;
    phuongtrinh1.printResult(1,2,10);
    return 0;
}
```

📝 Tính trừu tượng giống với tính đóng gói nhưng khác nhau về ý nghĩa.

📝 Tính đóng gói: những property ở private thì phải truy cập gián tiếp thông qua các method, constructor, getter, setter.

📝 Tính trừu tượng: khi thiết kế một class cho người dùng sử dụng thì người dùng chỉ được phép sử dụng những hàm do lập trình viên quy định , quá trình tạo ra kết quả cuối cùng không được phép truy cập đến, bị ẩn đi mặc dù nằm trong private.

</p>
</details>

</p>
</details>

<br>

<details><summary><b>Tham chiếu - Tham trị</b></summary>
<p>

<details><summary><b>1. Tham trị (Pass by value)</b></summary>
<p>

- Trong C++, "tham trị" (pass by value) là một cách truyền tham số vào hàm, trong đó một bản sao của biến được truyền cho hàm. Điều này có nghĩa là bất kỳ thay đổi nào được thực hiện trên tham số bên trong hàm sẽ không ảnh hưởng đến giá trị của biến gốc bên ngoài hàm.
- Khi sử dụng tham trị, nó sẽ tốn bộ nhớ trên RAM để cấp phát, sau đó thực hiện copy giá trị.

💻 Ví dụ:
```cpp
#include <iostream>

void test(int a)	// int a = 10 (0x20: 10)
{   	
    printf("dia chi a: %p\n", &a);
}

int main()
{
    int x = 10; 	// 0x34: 10
    printf("dia chi x: %p\n", &x);
    test(x);
}
```

</p>
</details>

<details><summary><b>2. Tham chiếu (Pass by reference)</b></summary>
<p>

- Trong C++, tham chiếu (pass by reference) là một cách truyền tham số vào hàm, trong đó thay vì truyền một bản sao của biến, địa chỉ của biến sẽ được truyền vào trực tiếp. Điều này có nghĩa là bất kỳ thay đổi nào thực hiện trên tham số trong hàm sẽ ảnh hưởng trực tiếp đến biến gốc bên ngoài hàm.
- Tham chiếu (&): bỏ qua bước khởi tạo biến, không tốn bộ nhớ RAM, Stack không tăng lên

💻 Ví dụ 1:
```cpp
#include <iostream>

void test(int &a)
{   
    cout << "Địa chỉ biến a: " << &a << endl;
    a = 50;
    cout << "Giá trị: " << a << endl;
}

int main()
{
    int x = 10; 	// 0x34: 10
    cout << "Địa chỉ biến x: " << &x << endl;
    test(x);
}
```

📝 Lưu ý: tham chiếu có thể thay đổi giá trị.

📝 Nếu nhu cầu của bạn là chỉ đọc thì thêm từ khóa const, vì nó chỉ cho phép đọc giá trị, không cho phép thay đổi.

💻 Ví dụ 2:
```cpp
#include <iostream>

void test(const int &a)
{   
    cout << "Địa chỉ biến a: " << &a << endl;
    cout << "Giá trị: " << a << endl;
}

int main()
{
    int x = 10; 	// 0x34: 10
    cout << "Địa chỉ biến x: " << &x << endl;
    test(x);
}
```

</p>
</details>

</p>
</details>

<br>

<details><summary><b>Cấp phát động trong C++</b></summary>
<p>

<details><summary><b>1 new operator </b></summary>
<p>

- Toán tử new được sử dụng để cấp phát bộ nhớ động cho một biến, một mảng hoặc một đối tượng.
- Khi sử dụng new, bộ nhớ sẽ được cấp phát trên phân vùng Heap (khu vực nhớ dành cho cấp phát động) thay vì trên stack (khu vực nhớ dành cho cấp phát tĩnh).

<br>

</p>
</details>

<details><summary><b>2 delete operator </b></summary>
<p>

- Toán tử delete dùng để giải phóng bộ nhớ đã được cấp phát bằng new. Điều này giúp tránh lãng phí bộ nhớ và hiện tượng rò rỉ bộ nhớ (memory leak).

<br>

</p>
</details>

<details><summary><b>3. Examples </b></summary>
<p>

💻 **Ví dụ 1: Cấp phát động một biến đơn**
```cpp
#include <iostream>

using namespace std;

int main()
{
    int *ptr = new int(10);
    /****************************************************
     * new int(10)
     *      + Khởi tạo một biến int
     *      + Cấp phát động cho biến int (0x01 - Heap)
     *      + Gán giá trị tại địa chỉ vừa cấp phát là 10
     *      + Trả về địa chỉ của vùng nhớ mới được cấp phát
     * 
     * con trỏ ptr sẽ trỏ đến địa chỉ trên
     ***************************************************/

    cout << "Địa chỉ đối tượng: " << ptr << endl;
    cout << "Giá trị đối tượng: " << *ptr << endl;

    delete ptr;
    return 0;
}
```

<br>

💻 **Ví dụ 2: Cấp phát động một mảng**
```cpp
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{   
    int size;
    cout << "Nhập kích thước của mảng: ";
    cin >> size;

    int *arr = new int[size]; 

    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 2;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  // Giải phóng bộ nhớ   

    return 0;
}
```

📝 Mặc dù việc cấp phát động bằng new trong C++ không thể thay đổi kích thước giống như realloc trong C, nhưng cấp phát động vẫn có nhiều điểm khác biệt so với khai báo mảng tĩnh.
📝 Mảng tĩnh: 

- Kích thước phải được xác định khi biên dịch (compile-time), nghĩa là bạn cần biết trước số lượng phần tử và không thể thay đổi trong khi chạy chương trình.
- Bộ nhớ của mảng tĩnh được cấp phát trên stack, và nó sẽ tự động giải phóng khi ra khỏi phạm vi (scope) của nó. Bộ nhớ mảng tĩnh không tồn tại lâu dài trong suốt chương trình mà phụ thuộc vào phạm vi khai báo.
- Kích thước mảng trên stack bị giới hạn bởi kích thước của stack (thường là vài MB), nên nếu bạn cần một mảng lớn, mảng tĩnh có thể không khả thi và dễ gây lỗi stack overflow.

📝 Cấp phát động với new: 

- Bạn có thể xác định kích thước mảng tại thời điểm chạy, giúp linh hoạt hơn nếu kích thước mảng phụ thuộc vào các giá trị mà bạn chỉ biết trong quá trình chạy chương trình.
- Bộ nhớ được cấp phát trên heap, có thể tồn tại cho đến khi bạn giải phóng thủ công bằng delete[]. Điều này cho phép bộ nhớ tồn tại lâu dài hơn, ngay cả khi phạm vi khai báo của con trỏ đã kết thúc.
- Vì bộ nhớ cấp phát động nằm trên heap, bạn có thể tạo ra các mảng rất lớn nếu bộ nhớ hệ thống còn đủ, mà không bị giới hạn bởi stack.

<br>

💻 **Ví dụ 3: Cấp phát động cho một biến của struct**
```cpp
#include <iostream>

using namespace std;

typedef struct
{
    int x;
    int y;
} Point;

int main(int argc, char const *argv[])
{   
    Point *p1 = new Point;
    p1->x = 10;
    p1->y = 20;
    cout << "Point 1: (" << p1->x << ", " << p1->y << ")" << endl << endl;

    Point *p2 = new Point{5, 15};
    cout << "Point 2: (" << p2->x << ", " << p2->y << ")" << endl << endl;

    Point *points = new Point[3];    // Cấp phát động cho một mảng gồm 3 biến Point
    points[0] = {1,2};
    points[1] = {3,4};
    points[2] = {5,6};
    for (int i = 0; i < 3; i++)
    {
        cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")" << endl;
    }

    delete p1;
    delete p2;
    delete[] points;

    return 0;
}
```

<br>

💻 **Ví dụ 4: Cấp phát động một mảng**
```cpp
#include <iostream>

using namespace std;

class SinhVien
{
    private:
        string name;
        int id;
        int age;
    
    public:
        SinhVien(string _name, int _age): name(_name), age(_age)
        {
            static int _id = 1;
            id = _id;
            _id++;
        }

        void display()
        {
            cout << "Name: " << name << ", ID: " << id << ", Age: " << age << endl;
        }
};

int main(int argc, char const *argv[])
{   
    SinhVien *p1 = new SinhVien("Trung", 25);
    p1->display();

    SinhVien *p2 = new SinhVien("Tuan", 22);
    p2->display();

    return 0;
}
```

<br>

</p>
</details>

</p>
</details>

<br>

<details><summary><b>Data Structure</b></summary>
<p>

<details><summary><b>1. Linked List</b></summary>
<p>

<details><summary><b>📚 Single Linked List </b></summary>
<p>

https://github.com/NHAnh2082/Cpp_Programming_Language/blob/3b23d1737f9b6e5db35057cdb03ac59fcceff890/Data_Structure/Linked_List/Single_Linked_List.hpp

</p>
</details>

<details><summary><b>📚 Doubly Linked List</b></summary>
<p>

https://github.com/NHAnh2082/Cpp_Programming_Language/blob/3b23d1737f9b6e5db35057cdb03ac59fcceff890/Data_Structure/Linked_List/Doubly_Linked_List.hpp

</p>
</details>

</p>
</details>

<details><summary><b>2. Stack</b></summary>
<p>

https://github.com/NHAnh2082/Cpp_Programming_Language/blob/3b23d1737f9b6e5db35057cdb03ac59fcceff890/Data_Structure/Stack/stack.hpp

</p>
</details>

<details><summary><b>3. Queue</b></summary>
<p>

<details><summary><b>📚 Linear Queue</b></summary>
<p>

https://github.com/NHAnh2082/Cpp_Programming_Language/blob/3b23d1737f9b6e5db35057cdb03ac59fcceff890/Data_Structure/Queue/queue_linear.hpp

</p>
</details>

<details><summary><b>📚 Circular Queue</b></summary>
<p>

https://github.com/NHAnh2082/Cpp_Programming_Language/blob/3b23d1737f9b6e5db35057cdb03ac59fcceff890/Data_Structure/Queue/queue_circular.hpp

</p>
</details>

<details><summary><b>📚 Priority Queue</b></summary>
<p>

https://github.com/NHAnh2082/Cpp_Programming_Language/blob/3b23d1737f9b6e5db35057cdb03ac59fcceff890/Data_Structure/Queue/queue_priority.hpp

</p>
</details>

</p>
</details>

</p>
</details>

<br>

<details><summary><b>auto & decltype keywords</b></summary>
<p>

<details><summary><b>1. auto keyword </b></summary>
<p>

- Cú pháp khai báo biến thông thường: ``` <data_type> <name_of_variable> = <initial_value> ```
- Dựa trên cú pháp khai báo biến này, lập trình viên phải xác định trước được kiểu dữ liệu cần sử dụng để lưu trữ giá trị.
- Từ C++11, **compiler** có thể tự suy luận kiểu dữ liệu cho giá trị mà bạn muốn sử dụng bằng cách sử dụng từ khóa **auto**, quá trình suy luận này diễn ra tại thời điểm biên dịch.
- Cú pháp: ``` auto <name_of_variable> = <expression> ```
- Giá trị khởi tạo là thành phần **bắt buộc** phải có khi sử dụng từ khóa auto, compiler sẽ dựa trên giá trị khởi tạo để quyết định kiểu dữ liệu nào phù hợp với biến (có thể là 1 con số, 1 kí tự, 1 chuỗi kí tự, hoặc 1 biểu thức toán học...).

<br>

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <typeinfo>
#include <cstdint>

using namespace std;

int main(int argc, char const *argv[])
{
    auto x = 10;		// i	-> int
    auto pi = 3.14;		// d	-> double
    auto character = 'a';	// c	-> char
    auto str = "Anh";		// PKc	-> Pointer constant char -> const char *

    cout << "Type of x: "         << typeid(x).name()           << endl;
    cout << "Type of PI: "        << typeid(pi).name()          << endl;
    cout << "Type of character: " << typeid(character).name()   << endl;
    cout << "Type of string: "    << typeid(str).name()         << endl;
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>2. decltype keyword</b></summary>
<p>

- Cũng tương tự với từ khóa **auto**, từ khóa **decltype** giúp chương trình tự động xác định kiểu dữ liệu cho biến. Nhưng cách sử dụng từ khóa decltype có một chút khác biệt so với cách sử dụng từ khóa auto.

- Để phân biệt:

	+ Từ khóa **auto** xác định kiểu dữ liệu dựa trên phần khởi tạo của biến.
	+ Từ khóa **decltype** xác định kiểu dữ liệu từ 1 biến hoặc 1 biểu thức khác.

Vì thế, khi sử dụng từ khóa decltype, chúng ta phải sử dụng kèm với 1 đối tượng cụ thể (1 biến, 1 biểu thức hoặc 1 đối tượng của class nào đó...).

- Cú pháp: ``` decltype(<object or expression>) <name_of_variable> = <initial_value> ```
- Giá trị khởi tạo (phần đặt trong ngoặc vuông) là không bắt buộc vì từ khóa decltype đã xác định được kiểu dữ liệu bằng cách lấy kiểu dữ liệu của đối tượng (object) hoặc biểu thức (expression).

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    decltype(x) y = 20;  // y có kiểu int giống x
    cout << y << endl;

    decltype(3.14) pi;  // pi có kiểu double
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>

using namespace std;

int fun1(){ return 10; }

char fun2(){ return 'g'; }

int main()
{
    decltype(fun1()) x; // Data type of x is same as return type of fun1()
    decltype(fun2()) y; // Data type of y is same as return type of fun2()

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;

    return 0;
}
```

<br>

💻 **Ví dụ 3:**
```cpp
#include <iostream>

using namespace std;

template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a+b)
{
    return a+b;
}

int main(int argc, char const *argv[])
{
    cout << "Sum of 2, 3 = " << sum(2, 3) << endl;
    return 0;
}
```

<br>

</p>
</details>

</p>
</details>

<br>

<details><summary><b>uniform initialization & constexpr</b></summary>
<p>

<details><summary><b>1. uniform initialization (khởi tạo đồng nhất)</b></summary>
<p>

Từ C++11, C++ hỗ trợ cú pháp ``` {} ``` để khởi tạo biến một cách thống nhất.

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <vector>

struct Point
{
   int x,y;
};

int main()
{
   int a{10};			// khởi tạo kiểu int	// int a = 10
   double b{5.5};		// khởi tạo kiểu double // double b = 5.5
   Point p{1,2};		// khởi tạo struct	// Point p = {1,2}
   vector<int> vec{1,2,3,4};	// khởi tạo vector	// vector<int> vec = {1,2,3,4}
}
```

📝 Lợi ích của Uniform Initialization:

- Tránh lỗi khởi tạo (ví dụ: không có chuyển đổi ngầm giữa double → int).
- Đồng nhất cú pháp giữa biến, struct, array, và container.

<br>

**Ứng dụng**

📝 **Khởi tạo mảng động**

```cpp
#include <iostream>

using namespace std;

int main()
{
	// demonstrate initialization of dynamic array in C++ using uniform initialization
	int* ptr = new int[5]{ 1, 2, 3, 4, 5 };

	// printing the contents of the array
	for (int i = 0; i < 5; i++) cout << *(ptr + i) << " ";
}
```

<br>

📝 **Khởi tạo mảng trong class**

```cpp
#include <iostream>

using namespace std;

class A
{
	int arr[3];

public:
	// initializing array using uniform initialization
	A(int x, int y, int z) : arr{ x, y, z }{};

	void show()
	{
		for (int i = 0; i < 3; i++) cout << *(arr + i) <<" ";
	}
};

int main()
{
	A a(1, 2, 3);
	a.show();
	return 0;
}
```

<br>

📝 **Khởi tạo ngầm (implicit) các đối tượng**

```cpp
#include <iostream>

using namespace std;

class A
{
	int a;
	int b;

public:
	A(int x, int y): a(x), b(y){}

	void show() { cout << a << " " << b; }
};

A f(int a, int b)
{
	return { a, b };
}

void f1(A x)
{
	x.show();
}

int main()
{
	A x = f(1, 2);
	x.show();
	f1({3,4});
	return 0;
}
```

<br>

</p>
</details>

<details><summary><b>2. constexpr (biểu thức hằng số)</b></summary>
<p>

- Từ C++11, **constexpr** cho phép khai báo các biến hoặc hàm có thể tính toán tại thời điểm biên dịch.
- Khi một biến, hàm hoặc toán tử được khai báo với **constexpr**, giá trị của nó phải được **tính toán trong lúc biên dịch** nếu có thể. Điều này giúp tăng hiệu suất chương trình bằng cách giảm thiểu các phép tính tại runtime.

```cpp
#include <iostream>

using namespace std;

constexpr int square(int x)
{
    return x * x;
}

int main()
{
    constexpr int a = 10;     		// Hằng số
    constexpr int b = square(a); 	// Được tính tại compile-time

    int x = 5;
    // constexpr int y = square(x); 	// Lỗi vì x không phải hằng số
}
```

<br>

</p>
</details>

</p>
</details>

<br>

<details><summary><b>Template</b></summary>
<p>

<details><summary><b>1. Giới thiệu Template </b></summary>
<p>

Trong C++ cho phép viết nhiều hàm có tên giống nhau nhưng khác nhau tham số truyền vào và kiểu trả về (Tính đa hình Compile - Time). Ví dụ:

```cpp
int tong(int a, int b)
{
    return a+b;
}

double tong(double a, double b)
{
    return a+b;
}
```

📝 Hai hàm trên có chức năng giống nhau, đều dùng để tính tổng 2 số, chỉ khác nhau kiểu trả về và kiểu dữ liệu các input params.

🤔 Vậy làm sao để thiết kế một hàm chung cho hai hoặc nhiều hàm tương tự trên❓

➡️ Sử dụng Template.

Template là một tính năng mạnh mẽ giúp viết mã tổng quát, có thể làm việc với nhiều kiểu dữ liệu khác nhau mà không cần phải viết lại mã cho từng kiểu cụ thể. Có hai loại template chính trong C++:

- Function Template (Hàm mẫu).
- Class Template (Lớp mẫu).

</p>
</details>

<details><summary><b>2. Function Template </b></summary>
<p>

Function Template trong C++ cho phép bạn viết một hàm tổng quát có thể hoạt động với nhiều kiểu dữ liệu khác nhau mà không cần viết lại mã nguồn cho từng kiểu dữ liệu cụ thể. Điều này giúp tăng tính tái sử dụng của mã và làm cho chương trình linh hoạt hơn.

<br>

💻 **Function Template với một kiểu dữ liệu tổng quát**

```cpp
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
T sum(T a, T b)
{
    return (T)a+b;
}

template <typename T>
T divide(T a, T b)
{
    assert(b != 0 && "Mẫu số bằng 0");
    return (T)a/b;
}

int main(int argc, char const *argv[])
{
    cout << "Sum: " << sum(1,5) << endl;        	// T: int
    cout << "Sum: " << sum(1.5,5.6) << endl;    	// T: double
    cout << "Divide: " << divide(3,1) << endl;
    cout << "Divide: " << divide(3.5,1.6) << endl;
    cout << "Divide: " << divide(3,0) << endl;
    return 0;
}
```

📝 Khi gọi hàm sum, compiler sẽ suy luận kiểu dựa trên các tham số truyền vào. Hàm trên tính tổng 2 số nhưng tham số truyền vào phải cùng kiểu dữ liệu ( (int, int) hoặc (double, double) hoặc (float, float) ...). Nếu cố tình truyền vào 2 tham số với kiểu dữ liệu khác nhau thì compiler sẽ báo lỗi ``` error: no matching function for call to 'sum(int, double)' ```

📝 Nếu muốn tính tổng 2 số có kiểu dữ liệu khác nhau thì phải khai báo một template khác.

<br>

💻 **Function Template với nhiều kiểu dữ liệu tổng quát**

```cpp
#include <iostream>

using namespace std;

template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a+b)
{
    return a+b;
}

int main(int argc, char const *argv[])
{
    cout << "Sum: " << sum(1, 5) << endl;	// T1, T2: int
    cout << "Sum: " << sum(1.5, 5.8) << endl;	// T1, T2: double
    cout << "Sum: " << sum(1.6, 5) << endl; 	// T1: double, T2: int
    return 0;		
}
```

📝 Từ khóa auto để cho phép trình biên dịch tự động suy ra kiểu trả về của phép cộng giữa a và b.

📝 Phiên bản này tổng quát hơn so với phiên bản ban đầu vì nó có thể xử lý hai kiểu dữ liệu khác nhau.

<br>

💻 **Function Template với tham số mặc định**

```cpp
#include <iostream>

using namespace std;

template <typename T = int>
T square(T x)
{
    return x * x;
}

int main(int argc, char const *argv[])
{
    cout << square(4) << endl;			// lấy mặc định -> int 	  -> 16
    cout << square<double>(4.5) << endl;	// ép kiểu 	-> double -> 20.25
    return 0;		
}
```

<br>

💻 **Function Template với Specialization (Chuyên biệt hóa)**

- Specialization (chuyên biệt hóa) được sử dụng khi một kiểu dữ liệu cụ thể yêu cầu một cách xử lý khác biệt so với các kiểu dữ liệu chung.

```cpp
#include <iostream>

using namespace std;

template <typename T>
void display(T value)
{
    cout << value << endl;
}

// Chuyên biệt hóa cho kiểu 'const char*'
template <>
void display<const char*>(const char *str)
{
    cout << "String: " << str << endl;
}

// Chuyên biệt hóa cho kiểu 'int'
template <>
void display<int>(int value)
{
    cout << ++value << endl;
}

int main(int argc, char const *argv[])
{
    display(3.14);
    display("Hello");
    display(2);
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>3. Class Template </b></summary>
<p>

Class Template trong C++ giúp tạo ra các lớp tổng quát có thể hoạt động với nhiều kiểu dữ liệu khác nhau mà không cần định nghĩa lại mã nguồn cho từng kiểu dữ liệu cụ thể.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>

using namespace std;

template <typename T>
class Sensor
{
    private:
        T value;
    
    public: 
        Sensor(T init): value(init){}

        void readSensor(T newValue)
	{
            value = newValue;
        }

        T getValue()
	{
            return value;
        }

        void display()
	{
            cout << "Giá trị cảm biến: " << value << endl;
        }
};

int main(int argc, char const *argv[])
{
    Sensor<double> tempSensor(25.7);
    tempSensor.display();

    Sensor<int> lightSensor(512);
    lightSensor.display();

    Sensor<string> stateSensor("OFF");
    stateSensor.display();
    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
class Pair
{
	private:
	    T1 first;
	    T2 second;

	public:
	    Pair(T1 f, T2 s) : first(f), second(s) {}

	    void show()
	    {
	        std::cout << "First: " << first << ", Second: " << second << std::endl;
	    }
};

int main()
{
    Pair<int, double> p1(10, 3.14);
    Pair<string, char> p2("Hello", 'A');

    p1.show(); // Output: First: 10,    Second: 3.14
    p2.show(); // Output: First: Hello, Second: A
    return 0;
}
```

<br>

💻 **Ví dụ 3:**
```cpp
#include <iostream>

using namespace std;

template <typename T>
class Test
{
    private: 
        T value;
    
    public:
        Test(T v);

        void display();
};

// Định nghĩa constructor bên ngoài class
template <typename T>
Test<T>::Test(T v) : value(v){}

// Định nghĩa method bên ngoài class
template <typename T>
void Test<T>::display()
{
    cout << "Value: " << value << endl;
}

int main(int argc, char const *argv[])
{
    Test<string> t1("hello");
    t1.display();

    Test<int> t2(10);
    t2.display();
    return 0;
}
```

<br>

💻 **Ví dụ 4:**
```cpp
#include <iostream>
#include <string>

using namespace std;

// Template chung
template <typename T>
class Printer 
{
    public:
        void print(T value) 
        {
            cout << "Generic: " << value << endl;
        }
};

// Chuyên biệt hóa cho kiểu std::string
template <>
class Printer<string> 
{
    public:
        void print(string value) 
        {
            cout << "String specialization: " << value << endl;
        }
};

int main() 
{
    Printer<int> intPrinter;
    intPrinter.print(100);      // Output: Generic: 100

    Printer<string> strPrinter;
    strPrinter.print("Hello");  // Output: String specialization: Hello
    return 0;
}
```

<br>

💻 **Ví dụ 5:**
```cpp
#include <iostream>
#include <string>

using namespace std;

class Sensor
{
    public:
        virtual double getValue() const = 0;

        virtual string getUnit() const = 0;
};

// Class đại diện cho cảm biến nhiệt độ (Temperature Sensor)
class TemperatureSensor : public Sensor
{
    private:
        double temp;

    public:
        double getValue() const override
        {
            // temp = 30.3;
            return 40.5; // Giá trị cảm biến giả định
        }

        string getUnit() const override
        {
            return "Celsius";
        }
};

// Class đại diện cho cảm biến áp suất lốp (Tire Pressure Sensor)
class TirePressureSensor : public Sensor
{
    public:
        double getValue() const override 
        {
            return 32; // Giá trị cảm biến giả định
        }

        string getUnit() const override 
        {
            return "PSI";
        }
};

// Template class quản lý hai cảm biến khác nhau
template <typename Sensor1, typename Sensor2>
class VehicleSensors
{
    private:
        Sensor1 sensor1;  // Đối tượng cảm biến 1
        Sensor2 sensor2;  // Đối tượng cảm biến 2

    public:
        // Constructor nhận vào hai đối tượng cảm biến
        VehicleSensors(Sensor1 s1, Sensor2 s2) : sensor1(s1), sensor2(s2) {}

        // Hàm hiển thị thông tin của cả hai cảm biến
        void displaySensorsInfo() const 
        {
            cout << "Sensor 1 Value: " << sensor1.getValue() << " " << sensor1.getUnit() << endl;
            cout << "Sensor 2 Value: " << sensor2.getValue() << " " << sensor2.getUnit() << endl;
        }
};

int main()
{
    // Tạo đối tượng cảm biến nhiệt độ
    TemperatureSensor tempSensor;

    // Tạo đối tượng cảm biến áp suất lốp
    TirePressureSensor pressureSensor;

    // Quản lý cả hai cảm biến bằng class VehicleSensors
    VehicleSensors vehicleSensors(tempSensor, pressureSensor);
    vehicleSensors.displaySensorsInfo();

    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>4. Variadic Template </b></summary>
<p>

Variadic Template cho phép bạn tạo các hàm template hoặc lớp template có thể nhận một số lượng tham số không xác định. Điều này giúp bạn viết mã linh hoạt hơn khi làm việc với danh sách tham số có kích thước động.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>

using namespace std;

template <typename... Args>
void count(Args... args)
{
    cout << "Number of arguments: " << sizeof...(args) << endl;
}

int main(int argc, char const *argv[])
{
    count(1, 2, 3.5, 'a', "hello");
    return 0;
}
```

📝 ``` typename... ```: định nghĩa nhiều kiểu tổng quát: typename Args1, typename Args2, typename Args3, v.v

📝 ``` Args... ```: nhiều kiểu dữ liệu, ứng với tham số truyền vào: Args1 arg1, Args2 arg2, Args3 arg3, v.v

📝 ``` sizeof...(args) ```: đếm số lượng tham số

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>

using namespace std;

template <typename T>
void print(T last)
{
    cout << last << endl;
}

template <typename T, typename... Args>
void print(T first, Args... args)
{
    cout << first << " ";
    if (sizeof...(args) > 0) print(args...);
}

template<typename... Args>
void print1(Args... args)
{
    (cout << ... << args) << '\n';
}

int main(int argc, char const *argv[])
{
    print(1, 2, 3.5, 'a', "hello");
    print1(1, 2, 3.5, 'a', "hello");
    return 0;
}
```

📝 ``` print(args...) ```: gọi lại hàm với danh sách tham số còn lại.

📝 ``` (std::cout << ... << args) ```: In tất cả các tham số

<br>

💻 **Ví dụ 3:**
```cpp
#include <iostream>

using namespace std;

/* Cách 1 */
// template <typename... Args>
// auto sum(Args... args)
// {
//     return (args + ...);
// }

/* Cách 2 */
// Function Template khi chỉ có một tham số
template<typename T>
T sum(T value)
{
    return value;
}

// Function Template sử dụng Variadic Template, ít nhất 2 tham số
template<typename T, typename... Args>  
auto sum(T first, Args... args)
{        
    return first + sum(args...);        
}

int main(int argc, char const *argv[])
{
    cout << sum(1, 2, 3.6, 5.7, 40) << endl;
    /*********************************************************************************************
     * Lần 1: first = 1,    args... = 2, 3.6, 5.7, 40  --> 1 + sum(2, 3.6, 5.7, 40)
     * Lần 2: first = 2,    args... = 3.6, 5.7, 40     --> 1 + (2 + sum(3.6, 5.7, 40))
     * Lần 3: first = 3.6,  args... = 5.7, 40          --> 1 + 2 + (3.6 + sum(5.7, 40))
     * Lần 4: first = 5.7,  args... = 40               --> 1 + 2 + 3.6 + (5.7 + sum(40))
     * Lần 5: gọi hàm sum một đối số --> return 40     --> 1 + 2 + 3.6 + 5.7 + 40
     ********************************************************************************************/
    return 0;
}
```

<br>

💻 **Ví dụ 4:**
```cpp
#include <iostream>

using namespace std;

// Class tổng quát sử dụng Variadic Template
template <typename... Args>
class MyClass;

// Định nghĩa class khi không có đối số
template <>
class MyClass<>
{
    public:
        void display() 
        {
            cout << "No arguments" << endl;
        }
};

// Định nghĩa class khi có ít nhất một đối số
template <typename T, typename... Args> 
class MyClass<T, Args...> : public MyClass<Args...>
{
    private:
        T first_;

    public:
        MyClass(T first, Args... args): first_(first),  MyClass<Args...>(args...){} // T first_ = first, Args1 args1_ = args1, Args2 args2_ = args2,...

        void display()
        {
            cout << first_ << " ";
            MyClass<Args...>::display(); // Gọi hàm display của lớp cơ sở
        }   

};

int main() 
{
    MyClass<int, double, char> obj(1, 2.5, 'A');
    obj.display();  // Kết quả: 1 2.5 A

    MyClass obj1;
    obj1.display();
    return 0;
}

/**************************************************************
 * Lần 1:
 *  + T = int, Args... = double, char
 *  + first = 1, args... = 2.5, 'A'
 *  --> In ra: 1            --> MyClass<double, char>(2.5, 'A')
 * 
 * Lần 2:
 *  + T = double, Args... = char
 *  + first = 2.5, args... = 'A'
 *  --> In ra: 1 2.5        --> MyClass<char>('A')
 * 
 * Lần 3:
 *  + T = char, Args... không còn
 *  + first = 'A', args... không còn
 *  --> In ra: 1 2.5 'A'    --> MyClass<>
 * 
 * Lần 4:
 *  + Không còn đối số
 *  --> In ra: 1 2.5 'A' No arguments
 *************************************************************/
```

<br>

</p>
</details>

</p>
</details>

<br>

<details><summary><b>Namespace</b></summary>
<p>

<details><summary><b>1. Giới thiệu Namespace </b></summary>
<p>

- Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các biến, hàm, class, ... cùng tên trong các phần của chương trình hoặc các thư viện khác nhau.
- Cú pháp:
```cpp
namespace name_of_namespace{
    /* source code */
}
```

💻 **Ví dụ 1:**
File B.cpp
```cpp
#include <iostream>

using namespace std;

namespace fileB
{
    void display(int id){
        cout << "This is file B.cpp, id = " << id << endl;
    }
}
```

File C.cpp
```cpp
#include <iostream>
using namespace std;

namespace fileC
{
    void display(int id){
        cout << "This is file C.cpp, id = " << id << endl;
    }
}
```

File A.cpp
```cpp
#include <iostream>
#include "fileB.cpp"
#include "fileC.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    fileB::display(2);
    fileC::display(2);
    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
using namespace std;

namespace A
{
    char *name = (char*)"Trung 20";

    void display(){ cout << "Name: " << name << endl; }
}


namespace B
{
    char *name = (char*)"Trung 21";

    void display(){ cout << "Name: " << name << endl; }

    class SinhVien
    {
        private:
            string name;
            int id;
        
        public:
            SinhVien()
            {
                static int _ID = 1;
                id = _ID;
                _ID++;
            }

            void setName(string newName){
                name = newName;
            }

            string getName() const{
                return name;
            }

            int getID() const{
                return id;
            }

            void display(){
                cout << "Tên sinh viên: " << getName() << endl;
                cout << "ID: " << getID() << endl;
            }
    };
}

int main(int argc, char const *argv[])
{
    cout << "Name: " << A::name << endl;
    cout << "Name: " << B::name << endl;


    A::display();
    B::display();


    B::SinhVien sv1;
    sv1.setName("Trung");
    sv1.display();
    return 0;
}
```

📝 Chuỗi "Trung 21": nằm ở rdata (data read-only) hoặc text tùy compiler.

📝 char *name: biến con trỏ toàn cục, đã khởi tạo nên lưu ở data.

📝 string name: một biến cục bộ trong mỗi đối tượng SinhVien. Khi một đối tượng SinhVien được tạo, vùng nhớ cho name sẽ được cấp phát trong:

- stack: nếu đối tượng SinhVien được khai báo tĩnh hoặc cục bộ trong một hàm.
- Heap: nếu đối tượng SinhVien được cấp phát động bằng new.

📝 int id: Tương tự name, biến id là biến thành viên non-static của class, nên sẽ được lưu trong stack hoặc heap tùy vào cách cấp phát đối tượng SinhVien.

📝 static int _ID: biến static cục bộ trong constructor SinhVien. Biến static cục bộ được lưu trữ trong data segment và tồn tại suốt thời gian chạy của chương trình.

<br>

</p>
</details>

<details><summary><b>2. using keyword </b></summary>
<p>

- Từ khóa using cho phép bạn khai báo namespace để sử dụng các thành viên trong namespace mà không cần phải sử dụng toán tử '::' mỗi khi truy cập.
- Chỉ sử dụng using namespace khi member muốn truy cập đến là duy nhất.

💻 **Ví dụ:**
```cpp
#include <iostream>

using namespace std;

namespace A{
    char *name = (char*)"Trung 20";
}

namespace B{
    char *name = (char*)"Trung 21";
}

using namespace A;

// using namespace B; // error: tham chiếu không rõ ràng

int main(int argc, char const *argv[])
{
    cout << "Name: " << name << endl;
    cout << "Name: " << B::name << endl;
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>3. Nested Namespace </b></summary>
<p>

- C++ cho phép tạo các namespace lồng nhau, nghĩa là một namespace có thể chứa một namespace khác bên trong nó.

💻 **Ví dụ:**
```cpp
#include <iostream>

using namespace std;

namespace A{
    char *name = (char*)"Trung 20";

    namespace C{
        char *str = (char*)"Hoang";
    }
}

namespace B{
    char *name = (char*)"Trung 21";
}

using namespace A::C;

int main(int argc, char const *argv[])
{
    cout << "Name: " << A::name << endl;
    cout << "Name: " << B::name << endl;
    cout << "Name: " << A::C::str << endl;

    str = (char*)"Hello World";
    cout << "Name: " << str << endl;
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>4. Extending a Namespace </b></summary>
<p>

- Namespace có thể được mở rộng bằng cách khai báo nhiều lần cùng một tên namespace trong các phần khác nhau của chương trình. Các khai báo này sẽ được trình biên dịch ghép lại thành một namespace duy nhất.

💻 **Ví dụ:**

**File lcd1.hpp**
```cpp
#ifndef _LCD1_HPP
#define _LCD1_HPP

namespace LCD{
    int temp;

    class lcd{
        private:

        public:
            lcd(/* args */);
            ~lcd();
    };

    lcd::lcd(){}

    lcd::~lcd(){}
}

#endif
```

**File lcd2.hpp**
```cpp
#ifndef _LCD2_HPP
#define _LCD2_HPP

namespace LCD{
    char *text;
}

#endif
```

**File main.cpp**
```cpp
#include <iostream>
#include "lcd1.hpp"
#include "lcd2.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    LCD::lcd;
    LCD::temp;
    LCD::text;
    return 0;
}

```

<br>

</p>
</details>

<details><summary><b>5. Standard Namespace (std) </b></summary>
<p>

- Một trong những namespace quan trọng và phổ biến nhất trong C++ là std. Tất cả các thành phần của thư viện chuẩn C++ (như cout, cin, vector, string) đều được định nghĩa bên trong namespace std.

💻 **Ví dụ:**
```cpp
#include <iostream>

using namespace std;

namespace std{
    struct{
        int x;
        int y;
    } point;

    void display(){
        cout << "x = " << point.x << endl;
        cout << "y = " << point.y << endl;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "Hello world!" << std::endl;

    cout << "Hello world!" << endl;
   
    std::point.x = 10;
    std::point.y = 20;
    std::display();

    return 0;
}
```

<br>

</p>
</details>

</p>
</details>

<br>

<details><summary><b>Standard Template Library (STL)</b></summary>
<p>

<details><summary><b>1. Giới thiệu STL</b></summary>
<p>

STL là một thư viện trong ngôn ngữ lập trình C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến. STL đã trở thành một phần quan trọng của ngôn ngữ C++ và làm cho việc lập trình trở nên mạnh mẽ, linh hoạt và hiệu quả.

Một số thành phần chính của STL:

- Container
- Iterator
- Algorithms
- Functor

<br>

</p>
</details>

<details><summary><b>2. Vector</b></summary>
<p>

- Là một trong những container quan trọng nhất trong STL.
- Bản chất của vector là một class template. Nó cung cấp một mảng động với khả năng thay đổi kích thước một cách linh hoạt.
- Có thể truy cập các phần tử của mảng bằng cách sử dụng chỉ số.
- Có thể chèn hoặc xóa bất kỳ phần tử nào trong mảng.
- Một số method của vector:

+ **at()**: truy cập để đọc hoặc thay đổi giá trị phần tử của vector.
+ **size()**: trả về kích thước của vector.
+ **resize()**: thay đổi kích thước của vector.
+ **begin()**: Trả về một iterator trỏ đến địa chỉ phần tử đầu tiên của vector.
+ **end()**: Trả về một iterator trỏ đến địa chỉ sau phần tử cuối cùng của vector.
+ **push_back()**: thêm phần tử vào vị trí cuối của vector.
+ **pop_back()**: xóa phần tử ở vị trí cuối của vector.
+ **insert()**: thêm phần tử vào vị trí bất kỳ.
+ **erase()**: xoá phần tử ở ví trí bất kỳ hoặc xóa các phần tử trong phạm vi được chỉ định.
+ **clear()**: xóa toàn bộ phần tử của vector (thu hồi tất cả địa chỉ).

<br>

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Khởi tạo vector bằng danh sách khởi tạo {}
    vector<int> vec = {1, 2, 3, 4, 5};

    // Thêm phần tử vào cuối vector bằng push_back
    vec.push_back(6);
    vec.push_back(7);

    // Thay đổi kích thước của vector với resize
    vec.resize(10); // Tăng kích thước vector lên 10 phần tử, các phần tử mới được khởi tạo với 0
    vec.at(8) = 50; // ghi giá trị mới
    vec.at(9) = 25;

    // In vector sau khi resize bằng vòng lặp for cải tiến và phương thức at()
    cout << "Vector sau khi resize: ";
    for (auto item : vec) {
        cout << item << " ";
    }
    cout << endl;

    // Thêm phần tử vào vị trí thứ 3 (sau phần tử thứ 2) bằng insert
    vec.insert(vec.begin() + 2, 99);

    // Thêm một phần tử khác vào vị trí thứ 5
    vec.insert(vec.begin() + 4, 88);

    // Xóa phần tử thứ 4 (sau phần tử đầu tiên thêm vào) bằng erase
    vec.erase(vec.begin() + 3);

    // Xóa thêm một phần tử khác tại vị trí thứ 6
    vec.erase(vec.begin() + 5);

    // Sử dụng pop_back() để xóa phần tử cuối cùng
    vec.pop_back();

    // In vector sau khi sử dụng insert, erase, và pop_back, sử dụng iterator
    cout << "Vector sau khi thêm, xóa và pop_back: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>3. List</b></summary>
<p>

- Triển khai dưới dạng danh sách liên kết hai chiều (linked list), nghĩa là gồm những nodes có địa chỉ ngẫu nhiên liên kết với nhau.
- Chỉ cỏ thể truy cập các phần tử một cách tuần tự (không hỗ trợ truy cập ngẫu nhiên).
- Có thể chèn/xóa ở bất kỳ vị trí nào trong danh sách.
- Một số method của list:

+ **size()**: trả về kích thước của list hay số lượng node trong list.
+ **begin()**: Trả về iterator trỏ đến địa chỉ node đầu tiên của list.
+ **end()**: Trả về iterator trỏ đến địa chỉ node cuối cùng của list.
+ **push_back()**: thêm node vào vị trí cuối của list.
+ **push_front()**: thêm node vào vị trí đầu của list.
+ **pop_back()**: xóa node ở vị trí cuối của list.
+ **pop_front()**: xóa node ở vị trí đầu của list.
+ **insert()**: thêm node ở vị trí bất kỳ
+ **erase()**: xoá node ở ví trí bất kỳ hoặc xóa các node trong phạm vi được chỉ định.
+ **remove()**: Xóa các node với giá trị được chỉ định.

<br>

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <list>

using namespace std;

int main() {
    // Khởi tạo list bằng danh sách khởi tạo {}
    list<int> lst = {1, 2, 3, 4, 5};

    // Thêm phần tử vào cuối list bằng push_back
    lst.push_back(6);
    lst.push_back(7);

    // Thêm phần tử vào đầu list bằng push_front
    lst.push_front(0);
    lst.push_front(-1);

    // Thay đổi kích thước của list bằng resize
    lst.resize(12, 0); // Tăng kích thước list lên 12 phần tử, các phần tử mới được khởi tạo với 0

    list<int>::iterator it;

    // In list sau khi resize bằng vòng lặp for cải tiến
    cout << "List sau khi push_front và resize: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Thêm phần tử vào vị trí thứ 3 (sau phần tử thứ 2) bằng insert
    it = lst.begin();
    for (int i = 0; i < 2; ++i) {
        ++it;
    }
    lst.insert(it, 99);

    // Thêm một phần tử khác vào vị trí thứ 5
    it = lst.begin();
    for (int i = 0; i < 4; ++i) {
        ++it;
    }
    lst.insert(it, 88);

    // Xóa phần tử thứ 4 (sau phần tử đầu tiên thêm vào) bằng erase
    it = lst.begin();
    for (int i = 0; i < 3; ++i) {
        ++it;
    }
    lst.erase(it);

    // Xóa thêm một phần tử khác tại vị trí thứ 6
    it = lst.begin();
    for (int i = 0; i < 5; ++i) {
        ++it;
    }
    lst.erase(it);

    // Sử dụng pop_back() để xóa phần tử cuối cùng
    lst.pop_back();

    // Sử dụng pop_front() để xóa phần tử đầu tiên
    lst.pop_front();

    // Kiểm tra list có rỗng không bằng empty()
    if (lst.empty()) {
        cout << "List hiện tại rỗng." << endl;
    } else {
        cout << "List sau khi thêm, xóa, pop_back và pop_front: ";
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>4. Map</b></summary>
<p>

- Cung cấp một cấu trúc dữ liệu ánh xạ key – value, trong đó value giữa các object có thể giống nhau nhưng key là duy nhất trong map, nếu có 2 value cùng key thì lấy key và value sau cùng.
- Có thể thêm phần tử mới vào map bằng cách sử dụng operator [] hoặc hàm insert(). Để xóa phần tử, bạn có thể sử dụng hàm erase().
- Có thể sử dụng iterator để duyệt qua các phần tử của map.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]){    
    map<int, string> array; // key: int, value: string

    array[1] = "Hoang";
    array[2] = "Tuan";
    array[3] = "Anh";

    for (auto item : array){
        cout << "key: " << item.first << " - value: " << item.second << endl; 
    }

    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
    map<string, int> myMap;

    // Thêm phần tử vào map
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;

    for (auto item : myMap){
        cout << "Key: " << item.first << " , " << "Value: " << item.second << endl;
    }

    cout << "---------------" << endl;

    map<string, int> ::iterator it; // it = myMap.begin()

    // myMap.insert(make_pair("four", 4));
    myMap.insert({"four", 4});
    myMap.erase("one");

    for (it = myMap.begin(); it != myMap.end(); it++){
        cout << "Key: " << (*it).first << " , " << "Value: " << (*it).second << endl;
    }

    return 0;
}
```

<br>

💻 **Ví dụ 3:**
```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef struct{
    string ten;
    int    tuoi;
    string lop;
} SinhVien;

int main(int argc, char const *argv[]){
    map<string, SinhVien> Database = {
        {
            "SV100", {
                "Hoang",
                20,
                "DDT"
            }
        },
        {
            "SV101", {
                "Tuan",
                21,
                "CDT"
            }
        },
        {
            "SV102", {
                "Anh",
                22,
                "KTMT"
            }
        }
    };

    for (auto item : Database){
        cout << "ID: " << item.first << " - Ten: " << item.second.ten << " - Tuoi: " << item.second.tuoi << " - Lop: " << item.second.lop << endl;
    }
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>5. Iterator</b></summary>
<p>

- Iterator là một đối tượng đại diện cho vị trí trong container và cho phép duyệt qua các phần tử của container (như std::vector, std::list, std::map, v.v.). Chúng có thể được xem là một công cụ để truy cập tuần tự các phần tử mà không cần biết cấu trúc nội bộ của container. Iterator sẽ lưu địa chỉ đầu tiên của list và cho phép duyệt qua từng phần tử.
- Iterator là một class, bên trong quản lý một con trỏ. Con trỏ này là thành phần giúp iterator biết được nó đang trỏ tới phần tử nào trong container. Con trỏ này lưu trữ địa chỉ của phần tử đầu tiên trong vector hay node đầu tiên trong list, và tử đó duyệt qua từng phần tử.
- Khi bạn muốn in ra địa chỉ mà một iterator đang trỏ tới, bạn cần sử dụng &(*it).

+ *it: (*) là toán tử truy cập giá trị đã được định nghĩa lại (overload) bên trong iterator.
+ &(*it): lấy địa chỉ của giá trị mà iterator it trỏ tới.

- Các thư viện như std::vector, std::list, và nhiều container khác trong C++ Standard Library đều định nghĩa một class iterator riêng bên trong chúng. Điều này giúp mỗi container có một loại iterator phù hợp với cách tổ chức dữ liệu và cách duyệt qua các phần tử của nó.

<br>

</p>
</details>

<details><summary><b>6. Building and Designing Library</b></summary>
<p>

<details><summary><b>📚 vector</b></summary>
<p>

</p>
</details>

<details><summary><b>📚 list</b></summary>
<p>

</p>
</details>

</p>
</details>

</p>
</details>

<br>

<details><summary><b>Lambda expression</b></summary>
<p>

Lambda là một tính năng mạnh mẽ được thêm vào ngôn ngữ lập trình C++ từ phiên bản C++11.

Lambda có những đặc điểm sau:

- Là 1 hàm không tên.
- Sử dụng 1 lần duy nhất trong chương trình.
- Được định nghĩa tại chỗ.
- Có thể sử dụng trực tiếp hoặc gán cho biến

Cú pháp:
```cpp
[capture](parameters) -> return_type
{
	// function body
}

[capture](parameters)
{
	// function body
}
```

- **capture**: cho biết cách các biến ở phạm vi bên ngoài được sử dụng trong lambda

	+ []: không sử dụng bất kỳ biến nào từ môi trường xung quanh

	+ [x]: chỉ định biến cụ thể (x), theo giá trị, read-only.

	+ [&x]: chỉ định biến cụ thể (x), theo tham chiếu, read, write.

	+ [=]: sử dụng tất cả biến xung quanh, theo giá trị.

	+ [&]: sử dụng tất cả biến xung quanh, theo tham chiếu.

	+ [=, &x]: sử dụng tất cả biến xung quanh theo giá trị, trừ biến 'x' theo tham chiếu.

	+ [&, x]: sử dụng tất cả biến xung quanh theo tham chiếu, trừ 'x' theo giá trị.

- **parameters**: danh sách các tham số truyền vào của lambda (giống function).

- **return_type**:

	+ kiểu trả về của lambda.
 	+ Nếu không chỉ định, kiểu trả về sẽ được suy diễn.

**function body**: Đặt trong dấu ngoặc nhọn {} và chứa mã nguồn thực thi của lambda.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // định nghĩa lambda và gán cho biến
    auto greet = []()
    {
        cout << "Hello, lambda!\n";
    };
    greet();


    auto sum = [](auto... args)
    {
        int sum = 0;
        int arr[] = {args...};
        for (size_t i=0; i<(sizeof(arr)/sizeof(arr[0])); i++)
        {
            sum += arr[i];
        }
        return sum;
    };
    cout << "Sum: " << sum(3,9) << endl;


    // định nghĩa lambda và sử dụng trực tiếp
    cout << [](int a, int b, int c)
    {   
        return a + b + c;
    }(2,3,4) << endl;


    // sử dụng biến xung quanh lambda
    int x = 1, y = 2, z = 3;

    // sử dụng giá trị
    auto lambda = [x,y]()
    {
        // x = 5;   // wrong
        // y = 10;  // wrong
        cout << "Captured x: " << x << endl;
        cout << "Captured y: " << y << endl;
    };
    lambda();


    // sử dụng tham chiếu
    auto lambda1 = [&x, &y]()
    {
        x += 5;     // 0x01: 1  ->   0x01: 6
        y = 50;
        cout << "Modified x: " << x << endl;
        cout << "Modified y: " << y << endl;
    };
    lambda1();


    // sử dụng tất cả các biến xung quanh, giá trị
    auto lambda2 = [=]()
    {
        cout << "Captured x: " << x << " , y: " << y << " , z: " << z << endl;
    };
    lambda2();


    // sử dụng tất cả các biến xung quanh, tham chiếu
    auto lambda3 = [&]()
    {   
        x = 10;
        y = 20;
        z = 30;
        cout << "Modified x: " << x << " , y: " << y << " , z: " << z << endl;
    };
    lambda3();

    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec {1, 2, 3, 4, 5, 6};

    int count_even = 0;
    int count_odd  = 0;
    vector<int> evens, odds;

    count_if(vec.begin(), vec.end(), [&](int x)
    {
        if (x % 2 == 0){
            count_even++;
            evens.push_back(x);
        } else {
            count_odd++;
            odds.push_back(x);
        }
        return false;
    });

    cout << "Number of even numbers: " << count_even << endl;
    cout << "Even numbers: ";
    for (auto item : evens)
    {
        cout << item << " ";
    }
    cout << endl;

    
    cout << "Number of odd numbers: " << count_odd << endl;
    cout << "Odd numbers: ";
    for (auto item : odds)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
```

<br>

💻 **Ví dụ 3:**
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {32, 71, 12, 40, 2, 80, 53, 35};

    vector<int>::iterator it;

    cout << "Initial: ";
    for (it = arr.begin(); it != arr.end(); it++){
        cout << " " << *it;
    }
    cout << endl;


    // sắp xếp tăng dần
    sort(arr.begin(), arr.end(), [](int i, int j) -> bool{
        return i < j;
    });

    cout << "Increase: ";
    for (it = arr.begin(); it != arr.end(); it++){
        cout << " " << *it;
    }
    cout << endl;


    // sắp xếp giảm dần
    sort(arr.begin(), arr.end(), [](int i, int j) -> bool{
        return i > j;
    });

    cout << "Decrease: ";
    for (it = arr.begin(); it != arr.end(); it++){
        cout << " " << *it;
    }
    
    return 0;
}
```

<br>

</p>
</details>

<br>

<details><summary><b>Smart Pointer</b></summary>
<p>

<details><summary><b>1. Giới thiệu về RAII</b></summary>
<p>

<details><summary><b>📚 Khái niệm</b></summary>
<p>

- **RAII (Resource Acquisition Is Initialization)** là một kỹ thuật quản lý tài nguyên trong lập trình C++, trong đó tài nguyên (bộ nhớ, file, mutex, socket,...) được **cấp phát khi một đối tượng được khởi tạo** và được **giải phóng khi đối tượng đó bị hủy**. Điều này giúp tránh rò rỉ tài nguyên và đảm bảo việc giải phóng tài nguyên diễn ra một cách tự động, ngay cả khi có ngoại lệ xảy ra.

<br>

</p>
</details>

<details><summary><b>📚 Nguyên tắc hoạt động</b></summary>
<p>

- **Cấp phát tài nguyên trong Constructor**: Khi một đối tượng được tạo, nó sẽ lấy tài nguyên cần thiết (ví dụ: cấp phát bộ nhớ động, mở file, lock mutex,...).
- **Giải phóng tài nguyên trong destructor**: Khi đối tượng đi ra khỏi phạm vi (scope), destructor của nó được gọi và tài nguyên sẽ được giải phóng một cách an toàn.

</p>
</details>

<details><summary><b>📚 Ví dụ minh họa</b></summary>
<p>

🔹**Quản lý bộ nhớ với RAII**

- Trước khi có RAII, nếu dùng new và delete thủ công, dễ bị memory leak:

```cpp
void badExample()
{
    int* ptr = new int(10);
    // Nếu có ngoại lệ xảy ra trước khi delete, sẽ bị memory leak.
    delete ptr;
}
```

<br>

- Dùng RAII với ``` std::unique_ptr ``` để tự động giải phóng bộ nhớ:

```cpp
#include <memory>

void goodExample()
{
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    // Không cần delete, bộ nhớ sẽ được giải phóng tự động khi ptr ra khỏi scope.
}
```

<br>
<br>

🔹**Quản lý file với RAII**

- Khi mở file bằng ``` FILE* ```, cần gọi ``` fclose() ``` thủ công:

```cpp
#include <cstdio>

void bad_FileHandling()
{
    FILE* file = fopen("example.txt", "w");
    if (!file) return;
    // Nếu return sớm mà quên fclose, sẽ bị rò rỉ file descriptor.
    fclose(file);
}
```

<br>

- Dùng RAII với ``` std::ofstream ```:

```cpp
#include <fstream>

void goodFileHandling()
{
    std::ofstream file("example.txt");
    if (!file) return;
    // Không cần gọi close(), file sẽ được đóng tự động khi ra khỏi scope.
}
```

<br>

</p>
</details>

</p>
</details>

<details><summary><b>2. Giới thiệu về Smart Pointer</b></summary>
<p>

- **Smart Pointer** khác hoàn con trỏ thô (**raw pointer**) thông thường, nó là một **class** giúp quản lý bộ nhớ tự động. Nó đảm bảo rằng bộ nhớ được cấp phát động sẽ được giải phóng một cách an toàn, giúp tránh **memory leak** và **dangling pointer**.
- Smart pointer tự động quản lý tài nguyên bằng cách sử dụng **RAII (Resource Acquisition Is Initialization)**, tức là tài nguyên sẽ được giải phóng khi đối tượng đi ra khỏi phạm vi (scope).
- Có 3 loại smart pointer chính trong C++ được định nghĩa trong thư viện ``` memory ```:

    + ``` std::unique_ptr ```
    + ``` std::shared_ptr ```
    + ``` std::weak_ptr ```

<br>

</p>
</details>

<details><summary><b>3. Unique Pointer</b></summary>
<p>

- **Unique Pointer** (``` unique_ptr ```) là một smart pointer quản lý bộ nhớ tự động trong C++.
- ``` unique_ptr ``` đảm bảo rằng chỉ có duy nhất một con trỏ sở hữu đối tượng tại một thời điểm (quyền sở hữu độc quyền).
- Khi ``` unique_ptr ``` bị hủy hoặc được gán cho một con trỏ khác, đối tượng mà nó sở hữu sẽ tự động được giải phóng.

💻
```cpp
#include <iostream>
#include <memory>  // Cần thiết để sử dụng smart pointer

using namespace std;

int main() 
{
    unique_ptr<int> ptr = make_unique<int>(10);
    
    cout << "Value: " << *ptr << endl;

    return 0;
}
```

📝 ``` make_unique<int>(10) ```: tạo ra một đối tượng kiểu int với giá trị khởi tạo là 10 và địa chỉ được cấp phát nằm trên vùng nhớ heap, sau đó trả về một con trỏ thông minh ``` unique_ptr ``` trỏ tới đối tượng đó.

📝 ``` unique_ptr<int> ```: chỉ ra rằng unique pointer này sẽ quản lý một đối tượng kiểu **int**.

📝 ``` ptr ```: tên của object thuộc class unique_ptr, nó được tạo ra và sở hữu vùng nhớ vừa được cấp phát. Từ thời điểm này, ptr có trách nhiệm quản lý vùng nhớ của đối tượng kiểu int.

<br>

Những phương thức chính mà ``` std::unique_ptr ``` hỗ trợ:

<b>1. operator*() và operator->()**</b>

- ``` operator*() ```: dereference con trỏ để truy cập giá trị của đối tượng mà **unique_ptr** đang quản lý.
- ``` operator->() ```: truy cập thành viên của đối tượng mà **unique_ptr** trỏ tới.


💻
```cpp
#include <iostream>
#include <memory>  // Cần thiết để sử dụng smart pointer

using namespace std;

class Example{
    private:
        int data;

    public:
        Example(int value): data(value){
            cout << "Constructor called, data = " << data << endl;
        }

        ~Example(){
            cout << "Destructor called, data = " << data << endl;
        }

        void display(){
            cout << "Value: " << data << endl;
        }
};

int main() 
{
    unique_ptr<Example> ptr = make_unique<Example>(10);
    ptr->display();

    *ptr = 20;
    (*ptr).display();
    return 0;
}
```

<br>

<b>2. get()</b>

- Trả về con trỏ thô (raw pointer) đến đối tượng mà **unique_ptr** đang quản lý.
-  Con trỏ thô trả về bởi **get()** không chuyển quyền sở hữu, tức là đối tượng vẫn được quản lý bởi **unique_ptr**.

💻
```cpp
#include <iostream>
#include <memory>  // Cần thiết để sử dụng smart pointer

using namespace std;

class Example{
    private:
        int data;

    public:
        Example(int value): data(value){
            cout << "Constructor called, data = " << data << endl;
        }

        ~Example(){
            cout << "Destructor called, data = " << data << endl;
        }

        void display(){
            cout << "Value: " << data << endl;
        }
};

int main() 
{
    unique_ptr<Example> ptr;
    ptr = make_unique<Example>(30);

    Example *rawPtr2 = ptr.get();   
    rawPtr2->display();
    return 0;
}
```

<br>

<b>3. release()</b>

- Giải phóng quyền sở hữu đối với đối tượng mà unique_ptr đang quản lý (``` unique_ptr ``` giờ đây trở thành ``` con trỏ null ```(nullptr)) và trả về con trỏ thô (raw pointer) đến đối tượng đó.
- Sau khi gọi ``` release() ```, unique_ptr không còn quản lý đối tượng nữa, và trách nhiệm giải phóng bộ nhớ thuộc về người gọi (giải phóng thủ công với ``` delete ```).

💻
```cpp
#include <iostream>
#include <memory>  // Cần thiết để sử dụng smart pointer

using namespace std;

class Example{
    private:
        int data;

    public:
        Example(int value): data(value){
            cout << "Constructor called, data = " << data << endl;
        }

        ~Example(){
            cout << "Destructor called, data = " << data << endl;
        }

        void display(){
            cout << "Value: " << data << endl;
        }
};

int main() 
{
    unique_ptr<Example> ptr = make_unique<Example>(30);

    Example *rawPtr = ptr.release();
    if (!ptr){
        cout << "ptr đã bị tách quyền sở hữu và trở thành nullptr\n";
    }
    rawPtr->display();  
    delete rawPtr;      
    return 0;
}
```

<br>

<b>4. reset()</b>

- Giải phóng đối tượng mà unique_ptr đang quản lý (nếu có) và có thể quản lý một đối tượng mới (nếu được cung cấp).
- Nếu không cung cấp đối tượng mới, reset() sẽ khiến unique_ptr trở thành nullptr.

💻
```cpp
#include <iostream>
#include <memory>  // Cần thiết để sử dụng smart pointer

using namespace std;

class Example{
    private:
        int data;

    public:
        Example(int value): data(value){
            cout << "Constructor called, data = " << data << endl;
        }

        ~Example(){
            cout << "Destructor called, data = " << data << endl;
        }

        void display(){
            cout << "Value: " << data << endl;
        }
};

int main() 
{
    unique_ptr<Example> ptr = make_unique<Example>(30);

    ptr.reset(new Example(20)); // ptr quản lý đối tượng mới
    ptr->display();

    ptr.reset();
    if (!ptr){
           cout << "ptr trở thành nullptr\n";
    }
    return 0;
}
```

<br>

<b>5. swap()</b>

Hoán đổi (swap) nội dung của hai unique_ptr với nhau, tức là đổi đối tượng mà hai unique_ptr quản lý.

💻
```cpp
#include <iostream>
#include <memory>  // Cần thiết để sử dụng smart pointer

using namespace std;

class Example{
    private:
        int data;

    public:
        Example(int value): data(value){
            cout << "Constructor called, data = " << data << endl;
        }

        ~Example(){
            cout << "Destructor called, data = " << data << endl;
        }

        void display(){
            cout << "Value: " << data << endl;
        }
};

int main() 
{
    unique_ptr<Example> ptr1 = make_unique<Example>(30);
    unique_ptr<Example> ptr2 = make_unique<Example>(60);
    ptr1.swap(ptr2);

    ptr1->display();
    ptr2->display();
    return 0;
}
```

<br>

<b>6. move()</b>

Chuyển nhượng quyền sở hữu tài nguyên (move semantics). Sau khi chuyển nhượng (move), con trỏ gốc sẽ trở thành nullptr và quyền sở hữu tài nguyên được chuyển sang **unique_ptr** mới.

💻
```cpp
#include <iostream>
#include <memory>  // Cần thiết để sử dụng smart pointer

using namespace std;

class Example{
    private:
        int data;

    public:
        Example(int value): data(value){
            cout << "Constructor called, data = " << data << endl;
        }

        ~Example(){
            cout << "Destructor called, data = " << data << endl;
        }

        void display(){
            cout << "Value: " << data << endl;
        }
};

int main() 
{
    unique_ptr<Example> ptr1 = make_unique<Example>(30);
    unique_ptr<Example> newPtr = move(ptr); // chuyển quyền sở hữu từ ptr sang newPtr

    if (!ptr){
        cout << "ptr đã trở thành nullptr sau khi chuyển quyền sở hữu\n";
    }
    newPtr->display();  // newPtr giờ sở hữu đối tượng
    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>4. Shared Pointer</b></summary>
<p>

- **Shared Pointer** (``` shared_ptr ```) là một smart pointer hỗ trợ chia sẻ quyền sở hữu đối với một đối tượng.
- Nhiều ``` shared_ptr ``` có thể cùng sở hữu một đối tượng. Đối tượng chỉ được giải phóng khi không còn ``` shared_ptr ``` nào sở hữu nó (đếm tham chiếu đạt giá trị 0).

- shared pointer (shared_ptr) là một smart pointer hỗ trợ chia sẻ quyền sở hữu đối với một đối tượng.
- Nhiều shared_ptr có thể cùng sở hữu một đối tượng. Đối tượng chỉ được giải phóng khi không còn shared_ptr nào sở hữu nó (đếm tham chiếu đạt giá trị 0).

<br>

Những phương thức chính mà ``` std::shared_ptr ``` hỗ trợ:

<b>1. operator*() và operator->()</b>: tương tự ``` unique_ptr ```

<b>2. get()</b>: tương tự ``` unique_ptr ```

<b>3. reset()</b>: tương tự ``` unique_ptr ```

<b>4. swap()</b>: tương tự ``` unique_ptr ```

<b>5. operator=</b>

Sao chép hoặc di chuyển quyền sở hữu giữa các ``` shared_ptr ```.

<b>6. use_count()</b>

Trả về số lượng shared_ptr đang cùng quản lý đối tượng (bộ đếm tham chiếu).

<br>

💻
```cpp
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char const *argv[])
{
    shared_ptr<int> ptr1 = make_shared<int>(20); // 0x01
    shared_ptr<int> ptr2 = ptr1;
    shared_ptr<int> ptr3 = ptr1;

    {
        shared_ptr<int> ptr4 = ptr1;
        cout << "Count: " << ptr1.use_count() << endl;
    }

    cout << "ptr1 = " << *ptr1 << endl;
    cout << "ptr2 = " << *ptr2 << endl;
    cout << "ptr3 = " << *ptr3 << endl;

    cout << "Count: " << ptr1.use_count() << endl;
    
    int *ptr = ptr1.get();
    cout << "ptr: " << *ptr << endl;
    *ptr = 50;
    cout << "ptr: " << *ptr << endl;
    /*
     * trả về 1 con trỏ int
     */

    shared_ptr<int> a = make_shared<int>(40);   // 0xa1
    shared_ptr<int> b = make_shared<int>(50);   // 0xb3
    a.swap(b);
    cout << "a = " << *a << endl;
    cout << "b = " << *b << endl;
    
    return 0;
}
```
**Kết quả:**
```cpp
Count: 4
ptr1 = 20
ptr2 = 20
ptr3 = 20
Count: 3
ptr: 20
ptr: 50
a = 50
b = 40
```

<br>

</p>
</details>

<details><summary><b>5. Weak Pointer</b></summary>
<p>

- **Weak Pointer** (``` weak_ptr ```) là một smart pointer không sở hữu đối tượng mà nó trỏ tới. Nó chỉ đóng vai trò theo dõi đối tượng được quản lý bởi một ``` shared_ptr ``` mà không làm tăng bộ đếm tham chiếu.
- ``` weak_ptr ``` chỉ theo dõi mỗi ``` shared_ptr ```, không theo dõi ``` unique_ptr ``` vì chính đặc điểm của ``` unique_ptr ``` đã ngăn chặn việc đó.

<br>

Những phương thức chính mà ``` std::shared_ptr ``` hỗ trợ:

<b>1. use_count()</b>: tương tự ``` shared_ptr ```

<b>2. reset()</b>: tương tự ``` shared_ptr ``` và ``` unique_ptr ```

<b>3. swap()</b>: tương tự ``` shared_ptr ``` và ``` unique_ptr ```

<b>4. operator=</b>

- Gán một ``` shared_ptr ``` hoặc một ``` weak_ptr ``` khác cho ``` weak_ptr ```.
- Khi gán một shared_ptr cho một weak_ptr sẽ không làm tăng bộ đếm tham chiếu.

<b>5. lock()</b>

Trả về shared_ptr trỏ tới đối tượng mà weak_ptr theo dõi, hoặc null nếu đối tượng đã bị hủy.

<b>6. expired()</b>

Trả về true nếu đối tượng mà weak_ptr theo dõi đã bị hủy.

<br>

💻
```cpp
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char const *argv[])
{
    // Tạo hai shared_ptr cùng quản lý một đối tượng int
    shared_ptr<int> ptr1 = make_shared<int>(20); // 0x01
    shared_ptr<int> ptr2 = ptr1;

    // Tạo một weak_ptr trỏ tới đối tượng được quản lý bởi shared_ptr
    weak_ptr<int> ptr3 = ptr1;

    cout << "Count: " << ptr1.use_count() << endl;

    cout << "ptr3: " << *(ptr3.lock()) << endl;

    ptr1.reset();   // giải phóng quyền sở hữu của ptr1 đối với đối tượng tại địa chỉ 0x01

    cout << "check: " << ptr3.expired() << endl;
    /*
     * nếu 0x01 còn tồn tại thì trả về false
     * ngược lại thì trả về true
     */

    ptr2.reset();
    cout << "check: " << ptr3.expired() << endl;
    
    return 0;
}
```
**Kết quả:**
```cpp
Count: 2
ptr2: 20
check: 0
check: 1
```

<br>

</p>
</details>

<details><summary><b>6. Building and Desinging Library</b></summary>
<p>

<details><summary><b>📚 Unique Pointer</b></summary>
<p>

https://github.com/NHAnh2082/Cpp_Programming_Language/blob/3b23d1737f9b6e5db35057cdb03ac59fcceff890/Smart_%20Pointer/Lib/Unique_Pointer.hpp

</p>
</details>

<details><summary><b>📚 Shared Pointer</b></summary>
<p>

https://github.com/NHAnh2082/Cpp_Programming_Language/blob/3b23d1737f9b6e5db35057cdb03ac59fcceff890/Smart_%20Pointer/Lib/Shared_Pointer.hpp

</p>
</details>

<details><summary><b>📚 Weak Pointer</b></summary>
<p>

https://github.com/NHAnh2082/Cpp_Programming_Language/blob/3b23d1737f9b6e5db35057cdb03ac59fcceff890/Smart_%20Pointer/Lib/Weak_Pointer.hpp

</p>
</details>

</p>
</details>

</p>
</details>

<br>

<details><summary><b>Design Patterns</b></summary>
<p>

<details><summary><b>1. Giới thiệu về Design Patterns</b></summary>
<p>

Design Patterns là các giải pháp tổng quát cho các vấn đề phổ biến trong phát triển phần mềm. Chúng là một dạng "công thức" giúp các lập trình viên xử lý các tình huống thường gặp trong quá trình thiết kế.

Design Patterns không phải là ngôn ngữ cụ thể nào cả. Nó có thể thực hiện được ở phần lớn các ngôn ngữ lập trình, chẳng hạn như C/C++, C#, Java,...

Design Patterns được chia thành 3 nhóm chính:

- Creational Pattern (mẫu khởi tạo): Quản lý việc khởi tạo đối tượng, ví dụ: Singleton, Factory, Prototype,...
- Behavioral Pattern (mẫu tương tác): Xác định cách các đối tượng tương tác với nhau ví dụ: Observer, MVP, Iterator,...
- Structural Pattern (mẫu cấu trúc): Tổ chức cấu trúc của các lớp và đối tượng, ví dụ: Decorator, Adapter, Composite,...

<br>

</p>
</details>

<details><summary><b>2. Single Pattern</b></summary>
<p>

- Singleton là một mẫu thiết kế thuộc nhóm Creational (mẫu khởi tạo), nó đảm bảo rằng một class chỉ tạo được duy nhất một đối tượng (object) và cung cấp một phương thức tĩnh để có thể truy cập đến đối tượng này.
- Singleton thường sử dụng cho những hệ thống chỉ cần một phiên bản duy nhất như: kết nối cơ sở dữ liệu, bộ nhớ đệm (cache), logger để ghi log, hoặc cấu hình hệ thống.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>

void gpioInit()
{
    std::cout << "Cấu hình GPIO" << std::endl;
}

void gpioSetPin(int pin, bool value)
{
    std::cout << "Pin " << pin << " set to " << (value ? "HIGH" : "LOW") << std::endl;
}

void gpioReadPin(int pin)
{
    std::cout << "Reading Pin " << pin << std::endl;
}

class GPIOManager
{
    private:
	// Constructor ở private để ngăn chặn tạo object từ bên ngoài
        GPIOManager()
        {
	    gpioInit();
	    // bổ sung thêm tính năng
	}

	// Thuộc tính tĩnh dùng để quản lý đối tượng duy nhất được tạo ra
        static GPIOManager* instance;	

    public:
        static GPIOManager *getInstance()
	{
            if (!instance)
	    {
                instance = new GPIOManager(); // Đây là đối tượng duy nhất được tạo             
            }
            return instance;
        }
        
        void setPin(int pin, bool value)
	{
            gpioSetPin(pin, value);
        }

        void readPin(int pin)
	{
            gpioReadPin(pin);
        }
};

GPIOManager* GPIOManager::instance = nullptr; // 0xc8 : địa chỉ cố định

int main(int argc, char const *argv[])
{
    GPIOManager* gpioManager1 = GPIOManager::getInstance();

    gpioManager1->setPin(1, true);

    gpioManager1->readPin(2);

    GPIOManager* gpioManager2 = GPIOManager::getInstance();

    return 0;
}
```
📝 gpioManager1 và gpioManager2 đều cùng trỏ đến cùng một đối tượng ``` instance ``` có địa chỉ là 0xc8, được gọi thông qua method ``` getIntance() ```, nghĩa là chúng đều cùng trỏ đến 1 vùng làm việc chung.

📝 Constructor ``` GPIOManager() ``` nằm ở private để không cho phép khởi tạo object thông thường.

📝 ``` static GPIOManager* instance ```: con trỏ instance thuộc class GPIOManager và phải được khởi tạo trước vì là static trong class: ``` GPIOManager* GPIOManager::instance = nullptr ```, khởi tạo ban đầu là con trỏ NULL.

📝 Khi ``` gpioManager1 ``` cấu hình Pin hay đọc giá trị Pin nào thì ``` gpioManager2 ``` cũng sẽ thực hiện tương tự.

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include "stm32f10x.h"  

class UART
{
    private:
        static UART* instance;  
        
        UART()
	{
            initUART();
        }

        void initUART()
	{
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
            USART_InitTypeDef USART_InitStructure;

            USART_InitStructure.USART_BaudRate = 115200;
            USART_InitStructure.USART_WordLength = USART_WordLength_8b;
            USART_InitStructure.USART_StopBits = USART_StopBits_1;
            USART_InitStructure.USART_Parity = USART_Parity_No;
            USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
            USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

            USART_Init(USART1, &USART_InitStructure);
            USART_Cmd(USART1, ENABLE);
        }

    public:
        static UART* getInstance()
	{
            if (instance == nullptr)
	    {
                instance = new UART();  // Tạo instance nếu chưa có
            }
            return instance;
        }

        void sendData(uint8_t data)
	{
            while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
            USART_SendData(USART1, data);
        }

        uint8_t receiveData()
	{
            while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
            return USART_ReceiveData(USART1);
        }
};

UART* UART::instance = nullptr;

int main()
{
    UART* uart1 = UART::getInstance();

    // Gửi một ký tự qua UART
    uart1->sendData('H');

    UART* uart2 = UART::getInstance();

    // Nhận một ký tự từ UART
    uint8_t received = uart2->receiveData();

    while (1) {
        // Thực hiện công việc liên quan khác
    }
}
```
📝 uart1 và uart2 cùng trỏ đến một đối tượng ``` instance ``` thông qua method ``` getInstance ``` nên sẽ có chung cấu hình, điều này đảm bảo rằng cấu hình UART là nhất quán trong toàn bộ hệ thống.

<br>

💻 **Ví dụ 3:**
```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Mẫu thiết kế được áp dụng vào trong những hoàn cảnh mà yêu cầu
 * class chỉ cho phép 1 đối tượng được tạo ra
 */

class Vehicle
{
    private:
        const string modelName;
        string ownerName;
        string license;

    public:
        Vehicle(string name): modelName(name){}

        virtual void run()
        {
            cout << modelName << " is running\n";
        }
};

class VehicleManager
{
    private:
        vector<Vehicle*> Vehicles;

        static VehicleManager *manager;

        // Giới hạn số lần cấp phát động để tạo ra đối tượng
        VehicleManager(){}

    public:
        static VehicleManager* getManager()
        {
            if (manager == nullptr)
            {
                manager = new VehicleManager();
            }
            return manager;
        }

        void addVehicle(Vehicle *vehicle)
        {
            Vehicles.push_back(vehicle);
        }

        void start()
        {
            for (auto i : Vehicles)
            {
                i->run();
            }
        }
};

VehicleManager* VehicleManager::manager = nullptr;

int main(int argc, char const *argv[])
{
    Vehicle *taxi  = new Vehicle("Honda");
    Vehicle *motor = new Vehicle("Wave");

    VehicleManager *vm = VehicleManager::getManager();
    vm->addVehicle(taxi);
    vm->addVehicle(motor);
    vm->start();

    return 0;
}
```

<br>

**Ứng dụng**:

- Quản lý tài nguyên hệ thống (cơ sở dữ liệu, tập tin, máy in).
- Các bộ nhớ đệm (cache), quản lý trạng thái ứng dụng.
- Đăng ký logger cho toàn bộ ứng dụng.

<br>

</p>
</details>

<details><summary><b>3. Observer Pattern</b></summary>
<p>

Observer là một mẫu thiết kế thuộc nhóm Behavioral, cho phép một đối tượng (gọi là Subject) thông báo cho nhiều đối tượng khác (gọi là Observer) về sự thay đổi trạng thái mà không cần biết chi tiết về các đối tượng đó.

**Đặc điểm chính của Observer Pattern**:

1. **Mối quan hệ của Subject và Observer**:

- Subject giữ một danh sách các Observer. Các Observer đăng ký nhận thông báo từ Subject khi có sự thay đổi trạng thái. Observer có thể thêm, xoá hoặc cập nhật trong danh sách này.

2. **Tự động thông báo (Push Notification)**:

- Khi trạng thái của Subject thay đổi, nó sẽ tự động thông báo cho tất cả các Observer đã đăng ký. Các Observer không cần chủ động kiểm tra trạng thái của Subject mà sẽ nhận thông báo ngay khi có thay đổi.

3. **Tính linh hoạt và mở rộng**:

- Observer Pattern cho phép dễ dàng thêm hoặc xóa các Observer mà không cần thay đổi Subject hoặc Observer có thể dễ dàng ngừng nhận thông báo từ Subject bằng cách hủy đăng ký, giúp kiểm soát tốt hơn việc quản lý tài nguyên và sự kiện trong hệ thống.

4. **Giảm sự phụ thuộc chặt chẽ**:

- Subject không cần biết chính xác về các Observer mà nó quản lý, chỉ cần biết rằng chúng tuân theo một giao diện chung để nhận thông báo. Điều này giúp giảm sự phụ thuộc chặt chẽ giữa các đối tượng và làm cho mã dễ bảo trì hơn.

5. **Nhiều Observer có thể theo dõi một hoặc nhiều Subject**:

- Nhiều Observer có thể cùng theo dõi một Subject. Điều này cho phép cùng một sự kiện trong Subject có thể ảnh hưởng đến nhiều đối tượng khác nhau.
- Một Observer có thể đăng ký để nhận thông báo từ nhiều Subject khác nhau, và mỗi Subject sẽ thông báo cho Observer khi có sự thay đổi liên quan.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Interface for observers (display, logger, etc.)
class Observer{

    public:
        virtual void update(float temperature, float humidity, float light) = 0;
};

// Subject (SensorManager) holds the state and notifies observers
class SensorManager
{
        float temperature;
        float humidity;
        float light;
        vector<Observer*> observers;

    public:
        void registerObserver(Observer* observer)
        {
            observers.push_back(observer);
        }

        void removeObserver(Observer* observer)
        {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        }

        void notifyObservers()
        {
            for (auto observer : observers)
            {
                observer->update(temperature, humidity, light);
            }
        }

        void setMeasurements(float temp, float hum, float lightLvl) 
        {
            temperature = temp;
            humidity = hum;
            light = lightLvl;
            notifyObservers();  // Push notification to all registered observers
        }
};

// Another Subject class
class WeatherStation
{
        float windSpeed;
        vector<Observer*> observers;

    public:
        void registerObserver(Observer* observer)
        {
            observers.push_back(observer);
        }

        void removeObserver(Observer* observer)
        {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        }

        void notifyObservers()
        {
            for (auto observer : observers)
            {
                observer->update(windSpeed, 0.0, 0.0);  // update for wind speed only
            }
        }

        void setWindSpeed(float speed)
        {
            windSpeed = speed;
            notifyObservers();  // Notify all observers of wind speed change
        }
};

// Display component (an observer)
class Display : public Observer 
{
    public:
        void update(float temperature, float humidity, float light) override 
        {
            cout << "Display: Temperature: " << temperature 
                 << ", Humidity: " << humidity 
                 << ", Light: " << light << endl;
        }
};

// Logger component (an observer)
class Logger : public Observer 
{
    public:
        void update(float temperature, float humidity, float light) override 
        {
            cout << "Logging data... Temp: " << temperature 
                 << ", Humidity: " << humidity 
                 << ", Light: " << light << endl;
        }
};

int main() 
{
    Display display;
    Logger  logger;

    SensorManager  sensorManager;
    WeatherStation weatherStation;

    // register observers to SensorManager
    sensorManager.registerObserver(&display);
    sensorManager.registerObserver(&logger);

    // register observers to WeatherManager
    weatherStation.registerObserver(&display);
    weatherStation.registerObserver(&logger);

    // simulate sensor data update
    sensorManager.setMeasurements(25.0, 60.0, 700.0);
    sensorManager.setMeasurements(26.0, 65.0, 800.0);
    cout << "\n";

    // simulate wind speed update
    weatherStation.setWindSpeed(15.0);
    weatherStation.setWindSpeed(25.4);
    cout << "\n";

    // Remove Logger from SensorManager notifications
    sensorManager.removeObserver(&logger);

    // Update sensor data again to see only Display receiving notifications
    sensorManager.setMeasurements(27.0, 70.0, 900.0);

    return 0;
}
```
**Kết quả**:
```cpp
Display: Temperature: 25, Humidity: 60, Light: 700
Logging data... Temp: 25, Humidity: 60, Light: 700
Display: Temperature: 26, Humidity: 65, Light: 800
Logging data... Temp: 26, Humidity: 65, Light: 800

Display: Temperature: 15, Humidity: 0, Light: 0
Logging data... Temp: 15, Humidity: 0, Light: 0
Display: Temperature: 25.4, Humidity: 0, Light: 0
Logging data... Temp: 25.4, Humidity: 0, Light: 0

Display: Temperature: 27, Humidity: 70, Light: 900
```
📝 Các property ``` temperature, humidity, light ``` và ``` vector<Observer*> observers ``` mặc định nằm ở pham vi truy cập private.

📝 **SensorManager** và **WeatherStation** (Subject) quản lý danh sách các **Observer**. Các Observer có thể đăng ký thông qua phương thức ``` registerObserver() ``` và có thể bị xóa bằng ``` removeObserver() ```. Điều này đảm bảo việc quản lý danh sách Observer một cách linh hoạt.

📝 Khi trạng thái thay đổi trong SensorManager (ví dụ: nhiệt độ, độ ẩm, ánh sáng), tất cả các Observer được thông báo qua phương thức ``` notifyObservers() ``` mà không cần chúng chủ động kiểm tra.

📝 Bất kỳ Observer nào cũng có thể dễ dàng được thêm hoặc xóa khỏi Subject mà không cần thay đổi cấu trúc của Subject hoặc Observer. Ví dụ: Sau khi Logger được xóa khỏi danh sách Observer của SensorManager, chỉ có Display nhận được thông báo khi có sự thay đổi.

📝 SensorManager không cần biết chi tiết về Display hay Logger, chỉ cần biết rằng chúng tuân theo giao diện Observer (với việc override method ``` update() ```). Điều này giúp giảm sự phụ thuộc chặt chẽ giữa các đối tượng và tăng khả năng bảo trì.

📝 Display và Logger theo dõi cả SensorManager và WeatherStation. Khi bất kỳ trạng thái nào trong hai Subject này thay đổi, các Observer sẽ nhận được thông báo tương ứng.

<br>

💻
```cpp
#include <iostream>
#include <vector>

using namespace std;

// Observer interface
class ButtonObserver
{
    public:
        virtual void update(int buttonID, bool state) = 0;
};

// Subject class - Button
class Button
{
        int buttonID;
        bool state;
        vector<ButtonObserver*> observers;

    public:
        Button(int id): buttonID(id), state(false){}

        void registerObserver(ButtonObserver* observer)
        {
            observers.push_back(observer);
        }

        void notifyObservers()
        {
            for (auto observer : observers)
            {
                observer->update(buttonID, state);
            }
        }

        void pressButton()
        {
            state = true;
            notifyObservers();
        }

        void releaseButton()
        {
            state = false;
            notifyObservers();
        }
};

// LED device acting as an observer
class LED : public ButtonObserver
{
    public:
        void update(int buttonID, bool state) override 
        {
            cout << "LED reacts to Button " << buttonID << " being " << (state ? "pressed" : "released") << std::endl;
        }
};

// Buzzer device acting as an observer
class Buzzer : public ButtonObserver
{
    public:
        void update(int buttonID, bool state) override {
            cout << "Buzzer reacts to Button " << buttonID << " being " << (state ? "pressed" : "released") << std::endl;
        }
};

int main() 
{
    Button button1(1);
    Button button2(2);

    Buzzer buzzer;
    LED    led;

    // Register observers
    button1.registerObserver(&led);
    button1.registerObserver(&buzzer);

    button2.registerObserver(&led);

    // Simulate button presses
    button1.pressButton();
    button1.releaseButton();
    cout << "\n";

    button2.pressButton();
    button2.releaseButton();

    return 0;
}
```
**Kết quả**:
```cpp
LED reacts to Button 1 being pressed
Buzzer reacts to Button 1 being pressed
LED reacts to Button 1 being released
Buzzer reacts to Button 1 being released

LED reacts to Button 2 being pressed
LED reacts to Button 2 being released
```

**Ứng dụng**:

- Giao diện đồ họa (cập nhật giao diện khi dữ liệu thay đổi).
- Hệ thống thông báo (quản lý sự kiện, hệ thống báo lỗi).
- Trong Automotive, Observer có thể được dùng để phát hiện và thông báo các thay đổi trạng thái của sensor hoặc các mô-đun điều khiển.

<br>

</p>
</details>

<details><summary><b>4. Factory Pattern</b></summary>
<p>

Factory Pattern là một mẫu thiết kế (design pattern) thuộc nhóm Creational patterns, cung cấp một cơ chế để tạo ra các đối tượng mà không cần chỉ rõ lớp cụ thể của các đối tượng đó. Thay vì khởi tạo trực tiếp các đối tượng, Factory Pattern sử dụng một phương thức hoặc một lớp trung gian (Factory) để quyết định loại đối tượng nào sẽ được khởi tạo dựa trên tham số đầu vào hoặc logic cụ thể.

Đặc điểm của Factory Pattern:

- **Tính trừu tượng**: Factory Pattern ẩn đi chi tiết về cách các đối tượng được tạo ra, giúp chương trình tách biệt giữa việc khởi tạo đối tượng và việc sử dụng đối tượng đó.
- **Tính mở rộng**: Factory Pattern giúp hệ thống dễ dàng mở rộng khi cần thêm các lớp con mới mà không làm ảnh hưởng đến mã nguồn hiện có.
- **Tính linh hoạt**: Khi hệ thống cần thay đổi hoặc thêm mới các đối tượng cụ thể, chúng ta chỉ cần cập nhật factory mà không cần sửa đổi mã nguồn chính.
- **Giảm sự phụ thuộc**: Factory Pattern giúp mã nguồn giảm sự phụ thuộc vào các lớp cụ thể, từ đó tăng tính module và khả năng tái sử dụng.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <string>

using namespace std;

// Abstract class
class Sensor
{
    public:
        virtual void readData() = 0;
};

// Temperature class
class TemperatureSensor : public Sensor
{
    public:
        void readData() override
	{
            cout<<"reading temp data: "<<endl;
        }
};

// Humidity class
class HumiditySensor : public Sensor
{
    public:
        void readData() override
	{
            cout<<"reading humidity data: "<<endl;
        }
};

// Factory class (Creator)
class SensorFactory
{
    public:
        static Sensor* createSensor(const string& sensorType)
	{
            if(sensorType == "temp")
 	    {
                return new TemperatureSensor();     // trả về đối tượng TemperatureSensor
            }
            else if (sensorType == "humi")
	    {
                return new HumiditySensor();        // trả về đối tượng PressureSensor
            }
            else
	    {
                return nullptr;                     // trả về con trỏ null
            }
        }
};


int main(int argc, char const *argv[])
{
    Sensor* sensor = SensorFactory::createSensor("humi");
    sensor->readData();
    return 0;
}
```

📝 **Abstract class** ``` Sensor ```: Đây là lớp cơ sở trừu tượng cho tất cả các loại cảm biến. Lớp này định nghĩa phương thức readData() là phương thức ảo thuần túy (pure virtual), yêu cầu các lớp con phải triển khai nó.

📝  Các lớp con cụ thể như ``` TemperatureSensor ```, ``` PressureSensor ```, và ``` HumiditySensor ``` triển khai phương thức ``` readData() ``` theo cách riêng để đọc dữ liệu từ các cảm biến tương ứng.

📝 **Factory class** ``` SensorFactory ```: Lớp này chứa một phương thức tĩnh ``` createSensor() ``` để tạo và trả về đối tượng cảm biến dựa trên loại cảm biến được chỉ định qua chuỗi ký tự đầu vào. Đây chính là tính trừu tượng vì người dùng chỉ được phép truyền vào tên cảm biến còn quá trình triển khai cảm biến như thế nào đã bị ẩn đi.

📝 Trong hàm main(), ta chỉ cần gọi phương thức ``` SensorFactory::createSensor() ``` và cung cấp loại cảm biến mà ta cần. Factory sẽ trả về đối tượng cảm biến phù hợp mà không cần khởi tạo thủ công từng lớp cụ thể

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <string>

using namespace std;

// Base class
class Sensor 
{
    public:
        // phương thức ảo thuần túy đọc dữ liệu cảm biến
        virtual void readData() = 0;
};

// Concrete product: temperature
class TemperatureSensor : public Sensor 
{
    public:
        // Đọc dữ liệu từ cảm biến nhiệt độ
        void readData() override 
        {
            cout << "reading temp data..." << endl;
            // cấu hình, logic xử lý
        }
};

// Concrete product: humidity
class HumiditySensor : public Sensor 
{
    public:
        // Đọc dữ liệu từ cảm biến độ ẩm
        void readData() override 
        {
            cout << "reading humidity data..." << endl;
        }
};

// Concrete product: pressure
class PressureSensor : public Sensor 
{
    public:
        // Đọc dữ liệu từ cảm biến áp suất
        void readData() override 
        {
            cout << "reading pressure data..." << endl;
        }
};

// Concrete product: light
class LightSensor : public Sensor
{
    public:
        // Đọc dữ liệu từ cảm biến áp suất
        void readData() override 
        {
            cout << "reading light data..." << endl;
        }
};

// Định nghĩa các loại cảm biến
typedef enum 
{
    TEMPERATURE,
    PRESSURE,
    HUMIDITY,
    LIGHT
} SensorType;

// Sensor Factory để tạo ra các đối tượng cảm biến
class SensorFactory 
{
    public:
        // Tạo đối tượng cảm biến dựa trên loại cảm biến
        static Sensor* createSensor(SensorType type) 
        {
            switch (type) 
            {
                case SensorType::TEMPERATURE:
                    return new TemperatureSensor(); // 0xc8

                case SensorType::HUMIDITY:
                    return new HumiditySensor();    // 0xa1

                case SensorType::PRESSURE:
                    return new PressureSensor();    // 0xf4
                
                case SensorType::LIGHT:
                    return new LightSensor();       // 0x04

                default:
                    cout << "Invalid sensor type!\n";
                    return nullptr;
            }

            // if (type == "temp"){
            //     return new TemperatureSensor();
            // } else if (type == "humi"){
            //     return new HumiditySensor(); 
            // }
        }
};

int main(int argc, char const *argv[]) 
{
    Sensor* sensor1 = SensorFactory::createSensor(SensorType::TEMPERATURE);
    sensor1->readData();

    Sensor* sensor2 = SensorFactory::createSensor(SensorType::TEMPERATURE);
    sensor2->readData();

    auto sensor3 = SensorFactory::createSensor(SensorType::PRESSURE);
    sensor3->readData();

    auto sensor4 = SensorFactory::createSensor(SensorType::HUMIDITY);
    sensor4->readData();

    SensorFactory::createSensor(SensorType::LIGHT);

    return 0;
}
```
📝 Enum ``` SensorType ```: sử dụng một enum để đại diện cho các loại cảm biến khác nhau (Temperature, Pressure, Humidity). Điều này giúp giảm thiểu lỗi liên quan đến việc nhập sai chuỗi (string) và làm mã dễ bảo trì hơn.

📝 **Factory Method** ``` createSensor() ```: method này giờ đây nhận tham số kiểu SensorType (enum) thay vì một chuỗi. Dựa trên giá trị của enum, nó khởi tạo và trả về đối tượng cảm biến tương ứng.

📝 Trong hàm ``` main() ```, thay vì sử dụng chuỗi để chỉ định loại cảm biến, ta truyền vào một giá trị của SensorType enum, giúp mã dễ hiểu và tránh lỗi không mong muốn.

<br>

</p>
</details>

<details><summary><b>5. Decorator Pattern</b></summary>
<p>

Decorator Pattern là một mẫu thiết kế thuộc nhóm structural patterns, cho phép thêm các chức năng hoặc hành vi mới cho một đối tượng mà không cần thay đổi cấu trúc của lớp đối tượng đó. Thay vì kế thừa để mở rộng tính năng, Decorator sử dụng sự kết hợp của đối tượng để thêm các hành vi cho đối tượng hiện có.

Đặc điểm của Decorator Pattern:

- **Tính linh hoạt**: Decorator Pattern cho phép thêm hành vi mới vào đối tượng một cách linh hoạt mà không làm thay đổi các đối tượng khác.
- **Tính mở rộng**: Decorator Pattern cho phép mở rộng tính năng mà không cần thay đổi mã gốc.
- **Dễ bảo trì**: Bạn có thể dễ dàng bổ sung hoặc thay thế các tính năng bằng cách thay đổi các decorator mà không ảnh hưởng đến các lớp khác.
- **Giảm sự phức tạp của kế thừa**: Thay vì tạo ra nhiều lớp con để mở rộng hành vi, Decorator Pattern cho phép kết hợp các hành vi một cách linh hoạt bằng cách xếp chồng các decorator.

<br>

```cpp
#include <iostream>

using namespace std;

class Shape 
{
    protected:
        string color;

    public:
        Shape(const string &color_ = "black") : color(color_){}

        virtual void draw() const 
        {
            cout << "Drawing a generic shape" << endl;
        }

        virtual double calculateArea() const 
        {
            return 0.0; 
        }
};

class Circle : public Shape 
{
    private:
        double radius;

    public:
        Circle(double r, const string &color_ = "black") 
            : radius(r), Shape(color_){}

        void draw() const override 
        {
            cout << "Drawing a Circle in color " << color << endl;
        }

        void setColor(const string& c) 
        {
            color = c;
        }

        string getColor() const 
        {
            return color;
        }

        double calculateArea() const override 
        {
            return 3.14 * radius * radius;
        }
};

class Rectangle : public Shape 
{
    private:
        double width, height;

    public:
        Rectangle(double w, double h, const string &color_ = "black") 
            : width(w), height(h), Shape(color_){}

        void draw() const override 
        {
            cout << "Drawing a Rectangle in color " << color << endl;
        }

        double calculateArea() const override 
        {
            return width * height;
        }
};

int main() 
{
    Shape *shapes[] = { new Circle(5, "red"), new Rectangle(4, 6, "yellow") };

    for (auto shape : shapes) 
    {
        shape->draw();
        cout << "Area: " << shape->calculateArea() << endl;
    }

    for (auto shape : shapes) 
    {
        delete shape;
    }

    return 0;
}
```

<br>

💻 **Ví dụ 1:**
```cpp

```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>

using namespace std;

/**
 * @class   Sensor
 * @brief   Base Component: Lớp cơ sở trừu tượng đại diện cho cảm biến.
 * @details Định nghĩa phương thức ảo readData để các lớp kế thừa 
 *          có thể triển khai tính năng đọc dữ liệu từ cảm biến.
 */
class Sensor
{
    public:
        /********************************************************
         * @brief   Phương thức ảo để đọc dữ liệu từ cảm biến.
         * @return  void
         ********************************************************/
        virtual void readData() const = 0;
};


/**
 * @class   TemperatureSensor
 * @brief   Concrete Component: Lớp cảm biến nhiệt độ cụ thể, kế thừa từ Sensor.
 * @details Lớp này triển khai phương thức readData để đọc dữ liệu nhiệt độ.
 */
class TemperatureSensor : public Sensor
{
    public:
        /********************************************************
         * @brief  Đọc dữ liệu nhiệt độ.
         * @return void
         ********************************************************/
        void readData() const override 
        {
            cout << "Reading temperature data...\n";
        }
};


/**
 * @class   SensorDecorator
 * @brief   Base Decorator: Lớp cơ sở cho các decorator của cảm biến.
 * @details Lớp này chứa một con trỏ đến đối tượng cảm biến gốc 
 *          và triển khai cơ bản phương thức readData bằng cách gọi cảm biến gốc.
 */
class SensorDecorator : public Sensor
{
    protected:
        Sensor *wrappedSensor;  /**< con trỏ đến đối tượng cảm biến gốc */

    public:
        /********************************************************
         * @brief Khởi tạo decorator với một cảm biến gốc.
         * @param sensor Con trỏ đến cảm biến gốc cần mở rộng chức năng.
         ********************************************************/
        SensorDecorator(Sensor* sensor): wrappedSensor(sensor){} 


        /********************************************************
         * @brief Gọi phương thức đọc dữ liệu từ cảm biến gốc.
         * @return void
         ********************************************************/
        void readData() const override 
        {
            wrappedSensor->readData();
        }
};


/**
 * @class   LoggingSensor
 * @brief   Concrete Decorator: Lớp decorator thêm chức năng ghi log cho cảm biến.
 * @details Lớp này kế thừa từ SensorDecorator và mở rộng chức năng bằng cách
 *          ghi log dữ liệu sau khi đọc từ cảm biến gốc.
 */
class LoggingSensor : public SensorDecorator
{
    public:
        /********************************************************
         * @brief Khởi tạo LoggingSensor với một cảm biến gốc.
         * @param sensor Con trỏ đến cảm biến cần thêm chức năng ghi log.
         ********************************************************/
        LoggingSensor(Sensor* sensor): SensorDecorator(sensor){}   


        /********************************************************
         * @brief   Đọc dữ liệu từ cảm biến và ghi log sau đó.
         * @return  void
         ********************************************************/
        void readData() const override
        {
            SensorDecorator::readData();
            logData();
        }


        /********************************************************
         * @brief Ghi log dữ liệu cảm biến.
         * @return void
         ********************************************************/
        void logData() const
        {
            cout << "Logging temperature data...\n";
            // code to log sensor data
        }
};


/**
 * @class   CheckLimitSensor
 * @brief   Concrete Decorator: Lớp decorator thêm chức năng kiểm tra giới hạn cho cảm biến.
 * @details Lớp này kế thừa từ SensorDecorator và mở rộng chức năng bằng cách
 *          kiểm tra giới hạn sau khi đọc dữ liệu từ cảm biến gốc.
 */
class CheckLimitSensor : public SensorDecorator
{
    public:
        /********************************************************
         * @brief Khởi tạo CheckLimitSensor với một cảm biến gốc.
         * @param sensor Con trỏ đến cảm biến cần thêm chức năng kiểm tra giới hạn.
         ********************************************************/
        CheckLimitSensor(Sensor* sensor): SensorDecorator(sensor){}


        /********************************************************
         * @brief  Đọc dữ liệu từ cảm biến và kiểm tra giới hạn.
         * @return void
         ********************************************************/
        void readData() const override
        {
            SensorDecorator::readData();
            checkLimits();
        }


        /********************************************************
         * @brief  Kiểm tra giới hạn nhiệt độ.
         * @return void
         ********************************************************/
        void checkLimits() const
        {
            cout << "Checking temperature limits...\n";
            // code
        }
};


int main(int argc, char const *argv[])
{
    // Base sensor object
    Sensor *sensor = new TemperatureSensor();   // sensor -> 0x01 (object temperature)

    // Adding checking function via decorator
    sensor = new CheckLimitSensor(sensor);      // sensor -> 0xa2 (object checking), wrap -> 0x01

    // Adding logging function via decorator
    sensor = new LoggingSensor(sensor);         // sensor -> 0xb4 (object logging), wrap -> 0xa2

    // Reading data with all added function
    sensor->readData();

    delete sensor;

    return 0;
}

/**
 * sensor: 0xc8 (temperature)
 * sensor: 0xf4 (checkLimit)
 * sensor: 0xa1 (logging)
 * 0xf4 (0xc8)
 * 0xa1 (0xf4)
 */
```

📝 **Base Component** ``` Sensor ```: Đây là giao diện trừu tượng của cảm biến, định nghĩa phương thức readData() mà mọi lớp con phải thực hiện.

📝 **Concrete Component** ``` TemperatureSensor ```: class cảm biến nhiệt độ, thực hiện việc đọc dữ liệu từ cảm biến thực tế.

📝 **Base Decorator** ``` SensorDecorator ```: Đây là lớp trừu tượng cho các decorator, kế thừa từ Sensor và chứa một tham chiếu đến Sensor. Lớp này cho phép các lớp con mở rộng hành vi của đối tượng Sensor được gói bên trong nó.

📝 **Concrete Decorator** ``` LoggingSensorDecorator ``` và ``` LimitCheckSensorDecorator ```: Đây là các lớp decorator cụ thể, chúng mở rộng hành vi của cảm biến bằng cách thêm chức năng ghi log (LoggingSensorDecorator) và kiểm tra giới hạn (LimitCheckSensorDecorator). Mỗi decorator vẫn gọi hàm readData() của cảm biến gốc, nhưng thêm các hành vi bổ sung vào quá trình.

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <string>

using namespace std;

/**
 * @class   HMI
 * @brief   Interface cơ bản cho hệ thống HUD.
 * @details Định nghĩa giao diện hiển thị và các phương thức lấy thông tin
 *          cơ bản như tốc độ và mức nhiên liệu.
 */
class HMI
{
    public:
        virtual void display() const = 0;       /** Hiển thị thông tin lên màn hình HUD */
        virtual double getSpeed() const = 0;    /** Đọc tốc độ hiện tại của xe */
        virtual double getFuel() const = 0;     /** Đọc mức nhiên liệu hiện tại */
};


/**
 * @class   HUD
 * @brief   Lớp cơ bản hiển thị thông tin HUD.
 */
class HUD : public HMI
{
    private:
        double speed;       // tốc độ xe
        double fuelLevel;   // mức nhiên liệu

    public:
        HUD(double _speed, double _fuelLevel): speed(_speed), fuelLevel(_fuelLevel){}

        double getSpeed() const { return speed; }

        double getFuel() const { return fuelLevel; }

        void display() const override
        {
            cout << "Speed: " << getSpeed() << " km/h, Fuel Level: " << getFuel() << "%" << endl;
        }
};


/**
 * @class   HUDDecorator
 * @brief   Lớp cơ sở cho các decorator của HUD.
 */
class HUDDecorator : public HMI
{
    protected:
        HMI *wrapHMI;

    public:
        HUDDecorator(HMI *hmi): wrapHMI(hmi){}

        double getSpeed() const override
        {
            return wrapHMI->getSpeed();
        }

        double getFuel() const override
        {
            return wrapHMI->getFuel();
        }

        void display() const override
        {
            wrapHMI->display();
        }
};


/**
 * @class   SpeedWarning
 * @brief   Hiển thị cảnh báo tốc độ.
 */
class SpeedWarning : public HUDDecorator
{
    protected:
        double maxSpeed;    // tốc độ tối đa
        double minSpeed;    // tốc độ tối thiểu

    public:
        SpeedWarning(HMI *hud, double maxLimit, double minLimit): HUDDecorator(hud), maxSpeed(maxLimit), minSpeed(minLimit){}

        void display() const override
        {
            HUDDecorator::display();
            warning();
        }

        double getMaxSpeed() const { return maxSpeed; }

        double getMinSpeed() const { return minSpeed; }

        void warning() const
        {
            double currentSpeed = getSpeed();
            if (currentSpeed > maxSpeed)
            {
                cout << "Warning: Speed Exceeds " << getMaxSpeed() << " km/h!" << endl;
            } 
            else if (currentSpeed < minSpeed)
            {
                cout << "Warning: Speed Below " << getMinSpeed() << " km/h" << endl;
            }
        }
};


/**
 * @class   FuelWarning
 * @brief   Hiển thị cảnh báo nhiên liệu.
 */
class FuelWarning : public HUDDecorator
{
    protected:
        double fuelThreshold; // Ngưỡng cảnh báo nhiên liệu

    public:
        FuelWarning(HMI *hud, double threshold): HUDDecorator(hud), fuelThreshold(threshold){}

        void display() const override
        {
            HUDDecorator::display();
            warning();
        }

        void warning() const 
        {
            double currentFuel = getFuel();

            if (currentFuel < fuelThreshold) 
            {
                cout << "Warning: Fuel Level Low (" << currentFuel << "%)!" << endl;
            }
        }
};


/**
 * @class   Color
 * @brief   Hiển thị thông tin với màu sắc.
 */
class Color : public HUDDecorator
{
    private:
        string RedColor;    // màu đỏ cho vượt quá tốc độ
        string YellowColor; // màu vàng cho dưới tốc độ quy định

    public:
        Color(HMI *hud, const string &_color1, const string &_color2)
            : HUDDecorator(hud), RedColor(_color1), YellowColor(_color2){}

        void display() const override
        {
            HUDDecorator::display();
            addColor();
        }

        void addColor() const
        {
            double currentSpeed = getSpeed();
            const SpeedWarning *sw = dynamic_cast<const SpeedWarning*>(wrapHMI);

            if (sw)
            {
                if (currentSpeed > sw->getMaxSpeed())
                {
                    cout << "Display color: " << RedColor << endl;
                } 
                else if (currentSpeed < sw->getMinSpeed())
                {
                    cout << "Display color: " << YellowColor << endl;
                }
            }
        }
};

int main(int argc, char const *argv[])
{   
    double speed = 120;     // Tốc độ hiện tại (km/h)
    double fuel  = 10;      // Mức nhiên liệu hiện tại (%)

    // Tạo đối tượng HUD
    HMI *hud = new HUD(speed, fuel);

    // Thêm tính năng
    hud = new SpeedWarning(hud, 100, 40);
    hud = new Color(hud, "Red", "Yellow");
    hud = new FuelWarning(hud, 20);

    // Hiển thị thông tin
    hud->display();

    delete hud;

    return 0;
}
```

<br>

</p>
</details>

<details><summary><b>6. Model-View-Presenter (MVP) Pattern</b></summary>
<p>

MVP (Model - View - Presenter) là một mẫu thiết kế thuộc nhóm Behavioral, phổ biến trong lập trình giao diện người dùng (UI) và phát triển ứng dụng. MVP tách biệt các thành phần của ứng dụng thành ba phần chính: **Model**, **View**, và **Presenter**. Cấu trúc này giúp dễ dàng quản lý, kiểm thử, và bảo trì mã nguồn.

- ``` Model ```: Chứa logic liên quan đến dữ liệu của ứng dụng, bao gồm các đối tượng, cơ sở dữ liệu, và giao tiếp với các API khác.
- ``` View ```: Hiển thị giao diện (Interface) và nhận tương tác từ người dùng (như nhập liệu, bấm nút). 
- ``` Presenter ```: Là cầu nối giữa Model và View, chịu trách nhiệm xử lý logic, điều phối dữ liệu từ Model đến View và ngược lại.

**Luồng hoạt động của MVP Pattern:**

- Người dùng tương tác với giao diện người dùng (View).
- View chuyển sự kiện này cho Presenter.
- Presenter xử lý yêu cầu bằng cách lấy dữ liệu từ Model.
- Model xử lý dữ liệu và trả về kết quả cho Presenter.
- Presenter tiếp tục cập nhật View với dữ liệu đã xử lý từ Model.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <string>

using namespace std;

/**
 * @class   SinhVienModel
 * @brief   Class lưu trữ thông tin của một sinh viên.
 * @details Class này chứa các thuộc tính cơ bản của sinh viên, bao gồm tên, tuổi và mã số sinh viên.
 *          Class này cung cấp các phương thức để truy cập và thay đổi thông tin sinh viên.
 */
class SinhVienModel 
{
    private:
        string name;      /**< Tên của sinh viên  */
        int age;          /**< Tuổi của sinh viên */
        string studentId; /**< Mã số sinh viên    */

    public:
        /**
         * @brief Constructor khởi tạo thông tin sinh viên.
         * @param name Tên của sinh viên.
         * @param age Tuổi của sinh viên.
         * @param studentId Mã số sinh viên của sinh viên.
         */
        SinhVienModel(const string& name, int age, const string& studentId) : name(name), age(age), studentId(studentId) {}

        /**
         * @brief Cập nhật tên của sinh viên.
         * @param newName Tên mới của sinh viên.
         */
        void setName(const string& newName) 
        {
            name = newName;
        }

        /**
         * @brief Cập nhật tuổi của sinh viên.
         * @param newAge Tuổi mới của sinh viên.
         */
        void setAge(int newAge) 
        {
            age = newAge;
        }

        /**
         * @brief Cập nhật mã số sinh viên.
         * @param newStudentId Mã số sinh viên mới.
         */
        void setStudentId(const string& newStudentId)
        {
            studentId = newStudentId;
        }

        /**
         * @brief  Lấy tên của sinh viên.
         * @return string: Tên của sinh viên.
         */
        string getName() const 
        {
            return name;
        }

        /**
         * @brief  Lấy tuổi của sinh viên.
         * @return int: Tuổi của sinh viên.
         */
        int getAge() const 
        {
            return age;
        }

        /**
         * @brief  Lấy mã số sinh viên.
         * @return string: Mã số sinh viên.
         */
        string getStudentId() const 
        {
            return studentId;
        }
};

/**
 * @class   SinhVienView
 * @brief   Class quản lý giao diện hiển thị và nhập liệu cho sinh viên.
 * @details Class này chịu trách nhiệm hiển thị thông tin sinh viên ra màn hình
 *          và lấy thông tin sinh viên từ người dùng thông qua giao diện console.
 */
class SinhVienView 
{
    public:
        /**
         * @brief Hiển thị thông tin sinh viên lên console.
         * @param name Tên của sinh viên.
         * @param age Tuổi của sinh viên.
         * @param studentId Mã số sinh viên.
         */
        void displayStudentInfo(const string& name, int age, const string& studentId) 
        {
            cout << "Thông tin sinh viên:" << endl;
            cout << "Tên: " << name << endl;
            cout << "Tuổi: " << age << endl;
            cout << "Mã số sinh viên: " << studentId << endl;
        }

        /**
         * @brief Nhận thông tin sinh viên từ người dùng qua console.
         * @param name Tham chiếu đến biến lưu trữ tên sinh viên.
         * @param age Tham chiếu đến biến lưu trữ tuổi sinh viên.
         * @param studentId Tham chiếu đến biến lưu trữ mã số sinh viên.
         */
        void inputStudentInfo(string& name, int& age, string& studentId) 
        {
            cout << "Nhập thông tin sinh viên:" << endl;

            cout << "Tên: ";
            getline(cin, name);

            cout << "Tuổi: ";
            cin >> age;
            cin.ignore();  // Bỏ qua ký tự newline trong buffer

            cout << "Mã số sinh viên: ";
            getline(cin, studentId);
        }
};

/**
 * @class   SinhVienPresenter
 * @brief   Class đóng vai trò trung gian giữa SinhVienModel và SinhVienView.
 * @details Class này điều phối luồng dữ liệu giữa Model và View. Nó cập nhật dữ liệu từ người dùng vào Model
 *          thông qua View và hiển thị thông tin từ Model lên View.
 */
class SinhVienPresenter 
{
    private:
        SinhVienModel& model; /**< Tham chiếu đến đối tượng SinhVienModel để lưu trữ dữ liệu sinh viên */
        SinhVienView& view;   /**< Tham chiếu đến đối tượng SinhVienView để quản lý giao diện hiển thị và nhập liệu */

    public:
        /**
         * @brief Constructor khởi tạo presenter với model và view.
         * @param m Tham chiếu đến SinhVienModel.
         * @param v Tham chiếu đến SinhVienView.
         */
        SinhVienPresenter(SinhVienModel& m, SinhVienView& v) : model(m), view(v) {}

        /**
         * @brief   Cập nhật thông tin sinh viên thông qua giao diện người dùng.
         * @details Phương thức này lấy dữ liệu từ người dùng qua View và cập nhật vào Model.
         */
        void updateStudentInfo() 
        {
            string name;
            int age;
            string studentId;
            
            view.inputStudentInfo(name, age, studentId);
            model.setName(name);
            model.setAge(age);
            model.setStudentId(studentId);
        }

        /**
         * @brief   Hiển thị thông tin sinh viên ra giao diện người dùng.
         * @details Phương thức này lấy dữ liệu từ Model và gửi đến View để hiển thị.
         */
        void showStudentInfo() 
        {
            view.displayStudentInfo(model.getName(), model.getAge(), model.getStudentId());
        }
};


int main() 
{
    SinhVienModel model("Tuấn", 20, "HTN123");  /**< Tạo model với thông tin sinh viên mặc định */
    SinhVienView view;                          /**< Tạo view để quản lý giao diện */
    SinhVienPresenter presenter(model, view);   /**< Tạo presenter để điều phối model và view */

    int choice;
    do{
        cout << "\n1. Hiển thị thông tin sinh viên" << std::endl;
        cout << "2. Cập nhật thông tin sinh viên" << std::endl;
        cout << "3. Thoát" << std::endl;
        cout << "Nhập lựa chọn: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
            case 1:
                presenter.showStudentInfo();
                break;
                
            case 2:
                presenter.updateStudentInfo();
                break;

            case 3:
                cout << "Thoát chương trình." << endl;
                break;

            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
        }
        
    } while (choice != 3);

    return 0;
}
```

📝 Tạo một đối tượng SinhVienModel với thông tin sinh viên ban đầu.

📝 Đối tượng SinhVienView được tạo để xử lý hiển thị và nhập dữ liệu từ người dùng.

📝 Đối tượng SinhVienPresenter được khởi tạo, nhận đối tượng SinhVienModel và SinhVienView làm đối số để làm cầu nối giữa Model và View.

📝 Có 3 lựa chọn cho người dùng 

📝 Lựa chọn 1: Hiển thị thông tin sinh viên

- Chương trình gọi phương thức presenter.showStudentInfo().

- Phương thức showStudentInfo() trong SinhVienPresenter sẽ lấy thông tin từ Model (tên, tuổi, mã số sinh viên) qua các phương thức getName(), getAge(), và getStudentId() của SinhVienModel.

- Presenter chuyển dữ liệu này cho View qua phương thức displayStudentInfo() của SinhVienView để hiển thị thông tin ra màn hình

📝 Lựa chọn 2: Cập nhật thông tin sinh viên

- Chương trình gọi phương thức presenter.updateStudentInfo().

- Phương thức updateStudentInfo() trong SinhVienPresenter sẽ yêu cầu View thu thập thông tin mới từ người dùng thông qua inputStudentInfo().

- View nhận các giá trị mới từ người dùng và trả lại cho Presenter.

- Presenter sau đó gọi các phương thức setName(), setAge(), và setStudentId() trong SinhVienModel để cập nhật thông tin mới vào Model.

📝 Lựa chọn 3: Thoát chương trình

<br>

</p>
</details>

</p>
</details>

<br>

<details><summary><b>Multithreading</b></summary>
<p>

<details><summary><b>1. Giới thiệu về Process</b></summary>
<p>

- Là 1 chương trình đang chạy trên hệ thống hoặc một tập hợp các công việc được thực hiện trên máy tính.
- Mỗi process có vùng nhớ riêng biệt.
- Có thể thao tác với những phần cứng bên dưới (bàn phím, chuột, ...)
- Việc giao tiếp giữa các process thường khó khăn và yêu cầu các phương thức như IPC (Inter-Process Communication).
- Mỗi tiến trình có thể bao gồm một hoặc nhiều luồng (thread) của việc thực hiện công việc.

![image](https://github.com/user-attachments/assets/998179b3-a5ad-4b8d-9416-413d3fa1181e)

**Ví dụ 1:**

- Khi mở một cửa sổ Google Chrome thì đó là một **tiến trình chính** được khởi tạo.
- Khi bạn mở nhiều **tab** trong Chrome thì mỗi tab được gọi là **tiến trình con (Child Process)**, Chrome sử dụng mô hình này để cô lập các tab nhằm đảm bảo rằng nếu một tab gặp sự cố, nó không làm ảnh hưởng đến các tab khác. Điều này cũng tăng cường bảo mật vì mỗi tiến trình có không gian bộ nhớ riêng.
- Ở mỗi tab, nếu có nhiều tác vụ như download tài liệu về máy tính, upload tài liệu từ máy tính, hiển thị hình ảnh, v.v thì mỗi tác vụ đó được gọi là một luồng (thread).

<br>

**Ví dụ 2:**

- Khi bạn khởi động ứng dụng Zalo, hệ điều hành tạo ra một tiến trình chính để quản lý toàn bộ ứng dụng. Đây là tiến trình mẹ, chịu trách nhiệm:

	+ Quản lý giao diện chính của ứng dụng.
 	+ Điều phối các tiến trình con và các luồng bên trong.
	+ Kết nối với máy chủ của Zalo để gửi/nhận dữ liệu.

- Tiến trình con:

	+ Một tiến trình để xử lý tin nhắn.
	+ Một tiến trình để xử lý cuộc gọi (âm thanh và video).
	+ Một tiến trình để đồng bộ hóa thông báo với máy chủ.

- Các luồng trong từng tiến trình:

	+ Luồng giao diện người dùng (UI Thread): Xử lý giao diện và tương tác của người dùng.
	+ Luồng mạng: Kết nối với máy chủ Zalo để gửi/nhận dữ liệu.
	+ Luồng nhập dữ liệu.
 	+ Luồng truyền dữ liệu.
  	+ Luồng nhận dữ liệu.   

<br>

**Ví dụ 3:**

- Khi mở IDE VSCode thì đây là **tiến trình chính**.
- Khi bạn chạy các file ``` .c, .cpp, .py, .js, v.v ``` (sau khi biên dịch) thì mỗi file sẽ tạo ra một tiến trình con duy nhất được hệ điều hành tạo ra để thực thi chương trình của bạn.
- Mỗi tiến trình con chính là toàn bộ chương trình đã viết, bao gồm **luồng chính** và các **luồng phụ** bên trong.

<br>

</p>
</details>

<details><summary><b>2. Giới thiệu về Thread</b></summary>
<p>

- Thread là đơn vị nhỏ hơn của một process, còn được gọi là "luồng". Một process có thể chứa nhiều thread, và các thread này chia sẻ cùng không gian địa chỉ bộ nhớ của process đó.
- Các luồng trong cùng một tiến trình có thể chia sẻ cùng một không gian bộ nhớ và các tài nguyên khác của tiến trình, bao gồm cả biến toàn cục và biến cục bộ.

<details><summary><b>📚 Tạo và chạy nhiều thread</b></summary>
<p>

- cú pháp: 

    ``` std::thread thread_id(function, args...) ```

    + ``` std::thread ```: class dùng để tạo, khởi chạy, quản lý các luồng

    + ``` thread_id ```: tên đại diện cho luồng

    + ``` function ```: hàm (method) hoặc lambda mà luồng sẽ thực thi

    + ``` args... ```: danh sách tham số truyền vào hàm

<br>

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void delay(uint32_t time)
{
    this_thread::sleep_for(chrono::seconds(time));
    /**
     * Hàm này mô phỏng một tác vụ tạm dừng (delay) trong khoảng thời gian (us, ms, s, v.v).
     * std::this_thread::sleep_for() tạm dừng luồng hiện tại trong thời gian được chỉ định.
     * Ví dụ, nếu time = 1, luồng sẽ bị tạm dừng trong 1 giây.
     */
}

void task1(uint32_t time)
{
    int i = 0;
    for (int j = 0; j < 8; j++)
    {
        cout << "task 1, i = " << i++ << endl;
        delay(time);
    }
}

void task2(uint32_t time)
{
    int i = 0;
    for (int j = 0; j < 8; j++)
    {
        cout << "task 2, i = " << i++ << endl;
        delay(time);
    }
}

int main(int argc, char const *argv[])
{
    thread t1(task1, 1);     // t1: đại diện cho luồng 1
    thread t2(task2, 3);     // t2: đại diện cho luồng 2
    
    while(1)
    {
        cout << "This is main thread\n";
        delay(1);
    }

    return 0;
}
```
📝 Khi luồng chính (main thread) thì toàn bộ tiến trình con cũng sẽ kết thúc.

📝 Trong mã nguồn trên, nếu thay ``` while(1) ``` bằng ``` for (int i=0; i<3; i++) ``` thì khi chạy sẽ gặp lỗi ``` terminate called without an active exception ```. Đây là lỗi xung đột vì luồng chính kết thúc trước các luồng phụ, trong khi luồng phụ vẫn còn chạy và có thể trả về kết quả (tài nguyên của luồng chưa được giải phóng).

<br>

</p>
</details>

<details><summary><b>📚 Quản lý các thread</b></summary>
<p>

<details><summary><b>📚📚 join()</b></summary>
<p>

- Dùng cho các luồng phụ, đồng bộ hóa luồng phụ với luồng chính (main thread).
- Khi 1 luồng phụ gọi phương thức ``` join() ```, nó đảm bảo rằng luồng hiện tại sẽ không tiếp tục thực hiện cho đến khi luồng được join() hoàn tất. Điều này hữu ích khi bạn cần chắc chắn rằng một luồng đã hoàn thành công việc trước khi tiếp tục với luồng chính.
- Có thể lấy kết quả trả về của luồng phụ sau khi ``` join ``` kết thúc.
- Mỗi luồng chỉ có thể gọi method join() duy nhất 1 lần.
- Nếu một luồng đã được join(), nó không còn khả năng tham gia (joinable) nữa.

<br>

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int result1 = 0;
int result2 = 0;

void delay(uint32_t time)
{
    this_thread::sleep_for(chrono::seconds(time));
}

void task1(uint32_t time)
{
    int i = 0;
    for (int j = 0; j < 5; j++)
    {
        cout << "task 1, i = " << i++ << endl;
        delay(time);
    }

    result1 = i;
}

void task2(uint32_t time)
{
    int i = 0;
    for (int j = 0; j < 5; j++)
    {
        cout << "task 2, i = " << i++ << endl;
        delay(time);
    }

    result2 = i;
}

int main(int argc, char const *argv[])
{
    thread t1(task1, 1);     // t1: đại diện cho luồng 1
    thread t2(task2, 2);     // t2: đại diện cho luồng 2

    t1.join();
    t2.join();

    cout << "Kết quả cuối cùng của luồng 1: " << result1 << endl;
    cout << "Kết quả cuối cùng của luồng 2: " << result2 << endl;
    
    for (int i=0; i<7; i++)
    {
        cout << "This is main thread\n";
        delay(1);
    }

    return 0;
}
```

📝 Đặt luồng chính ``` (while(1)) ``` sau khi gọi join().

📝 Luồng 1 (thực thi hàm ``` task1 ```) và luồng 2 (thực thi hàm ``` task2 ```) sẽ chạy song song với nhau.

📝 Luồng chính ``` (while(1)) ``` chỉ bắt đầu chạy khi luồng 1 kết thúc và luồng 2 cũng kết thúc. Điều này sẽ đảm bảo không xảy ra xung đột vì các luồng phụ đã kết thúc trước luồng chính.


</p>
</details>

<details><summary><b>📚📚 joinable()</b></summary>
<p>

- Kiểm tra xem một thread đã kết thúc hoặc đã gọi join() hay chưa. Nếu chưa thì trả về true, khi này ta có thể bắt đầu khởi chạy thread. Ngược lại, nếu thread đã kết thúc rồi thì trả về false.

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void delay(uint32_t time)
{
    this_thread::sleep_for(chrono::seconds(time));
}

void task1(uint32_t time)
{
    int i = 0;
    for (int j = 0; j < 5; j++)
    {
        cout << "task 1, i = " << i++ << endl;
        delay(time);
    }
}

void task2(uint32_t time)
{
    int i = 0;
    for (int j = 0; j < 5; j++)
    {
        cout << "task 2, i = " << i++ << endl;
        delay(time);
    }
}

int main(int argc, char const *argv[])
{
    thread t1(task1, 1);     // t1: đại diện cho luồng 1
    thread t2(task2, 2);     // t2: đại diện cho luồng 2

    if (t1.joinable())
    {
        cout << "Thread 1 chưa kết thúc hoặc chưa gọi join()\n";
        t1.join();
    }
    else
    {
        cout << "Thread 1 đã kết thúc hoặc đã gọi join()\n";
    }
    

    if (t2.joinable())
    {
        cout << "Thread 2 chưa kết thúc hoặc chưa gọi join()\n";
        t2.join();
    }
    else
    {
        cout << "Thread 2 đã kết thúc hoặc đã gọi join()\n";
    }
    
    for (int i=0; i<7; i++)
    {
        cout << "This is main thread\n";
        delay(1);
    }

    return 0;
}
```

</p>
</details>

<details><summary><b>📚📚 detach()</b></summary>
<p>

- Dùng cho các luồng phụ.
- Luồng phụ gọi phương thức ``` detach() ``` sẽ tách luồng khỏi luồng chính và cho phép nó chạy độc lập, nghĩa là luồng chính và luồng phụ gọi ``` detach ``` sẽ không chờ lẫn nhau.
- Không thể join() một luồng đã được detach(). Nếu một luồng đã được tách ra, nó không còn khả năng tham gia (joinable) nữa.
- Luồng chính khi kết thúc trước luồng gọi detach thì luồng đó cũng bị hủy và kết thúc do tiến trình đã kết thúc. Điều này xảy ra vì khi tiến trình kết thúc (do luồng chính kết thúc), tất cả các luồng trong tiến trình (bao gồm luồng đã detach) sẽ bị hệ điều hành hủy ngay lập tức.

💻 **Ví dụ:**
```cpp
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int result1 = 0;
int result2 = 0;

void delay(uint32_t time)
{
    this_thread::sleep_for(chrono::seconds(time));
}

void task1(uint32_t time)
{
    int i = 0;
    for (int j = 0; j < 5; j++)
    {
        cout << "task 1, i = " << i++ << endl;
        delay(time);
    }

    result1 = i;
}

void task2(uint32_t time)
{
    int i = 0;
    for (int j = 0; j < 5; j++)
    {
        cout << "task 2, i = " << i++ << endl;
        delay(time);
    }

    result2 = i;
}

int main(int argc, char const *argv[])
{
    thread t1(task1, 1);     // t1: đại diện cho luồng 1
    thread t2(task2, 2);     // t2: đại diện cho luồng 2

    t1.detach();
    t2.detach();

    cout << "Kết quả cuối cùng của luồng 1: " << result1 << endl;
    cout << "Kết quả cuối cùng của luồng 2: " << result2 << endl;
    
    for (int i=0; i<7; i++)
    {
        cout << "This is main thread\n";
        delay(1);
    }

    return 0;
}
```

📝 Luồng task1, luồng task2 và luồng chính chạy song song và độc lập với nhau.

📝 Luồng chính không còn chờ luồng task1 và luồng task2 chạy xong rồi mới thực hiện.

📝 Kết quả của luồng task1 và task2 sẽ không lấy ra được:

```cpp
Kết quả cuối cùng của luồng 1: 0
Kết quả cuối cùng của luồng 2: 0
This is main thread
task 2, i = 0
task 1, i = 0
This is main thread
task 1, i = 1
This is main thread
task 2, i = 1
task 1, i = 2
This is main thread
task 1, i = 3
This is main thread
task 2, i = 2
task 1, i = 4
This is main thread
This is main thread
task 2, i = 3
```

<br>

- **Khi nào sử dụng join()? Khi nào sử dụng detach()?**

    + Sử dụng join() khi luồng phụ thực hiện một công việc quan trọng mà kết quả của nó cần thiết cho luồng chính

    + Sử dụng detach() khi công việc của các luồng phụ không ảnh hưởng đến luồng chính 

<br>

</p>
</details>

</p>
</details>

</p>
</details>

<details><summary><b>3. Đồng bồ hóa các threads</b></summary>
<p>

<details><summary><b>📚 Atomic Operator</b></summary>
<p>

- ``` std::atomic ``` là một **struct template** trong C++ được thiết kế để thực hiện các thao tác trên các biến toàn cục mà các thao tác này không thể bị gián đoạn bởi các luồng khác. Điều này giúp đảm bảo tính nhất quán của dữ liệu và tránh tình trạng **data race** khi nhiều luồng cùng truy cập và thay đổi dữ liệu chia sẻ.
- Các thao tác atomic:

	+ Gán và đọc giá trị (store và load): Ghi và đọc giá trị của biến atomic.
	+ Tăng và giảm giá trị (++, --): Tăng hoặc giảm giá trị của biến atomic.
	+ Cộng và trừ giá trị (+=, -=): Thực hiện phép cộng, trừ giá trị nguyên tử.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> sharedCounter(0); // biến chia sẻ giữa các luồng

void incrementTask(int iter)
{
    for (int i=0; i<iter; i++)
    {
        cout << ++sharedCounter << endl;
    }
}

int main(int argc, char const *argv[])
{
    thread t1(incrementTask, 100);
    thread t2(incrementTask, 100);

    t1.join();
    t2.join();

    cout << "Final result: " << sharedCounter << endl;

    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

mutex mtx;

atomic<int> value_int(0);

void delay(uint32_t time)
{
    this_thread::sleep_for(chrono::seconds(time));
}

void display(int id, uint32_t time)
{
    while(1)
    {
        unique_lock<mutex> ulock(mtx);
        cout << "This is task display: " << id << endl;
        ulock.unlock();

        ulock.lock();
        value_int.fetch_add(1); // Tăng giá trị lên 1
        cout << "Data after fetch_add: " << value_int.load() << endl;
        ulock.unlock();

        ulock.lock();
        value_int.fetch_sub(1); // Giảm giá trị đi 1
        cout << "Data after fetch_sub: " << value_int.load() << endl;
        ulock.unlock();

        ulock.lock();
        value_int.store(50); // Đặt giá trị mới trực tiếp là 50
        cout << "Data after store: " << value_int.load() << endl;
        ulock.unlock();

        ulock.lock();
        int old_value = value_int.exchange(100); // Đổi giá trị hiện tại thành 100
        cout << "Data after exchange (old value): " << old_value << ", new value: " << value_int.load() << endl;
        ulock.unlock();

        ulock.lock();
        int expected = 100;
        if (value_int.compare_exchange_weak(expected, 200)) // Đổi giá trị thành 200 nếu giá trị hiện tại là 100
        {
            cout << "compare_exchange_weak succeeded, new value: " << value_int.load() << endl;
        }
        else
        {
            cout << "compare_exchange_weak failed, expected: " << expected << ", current value: " << value_int.load() << endl;
        }
        ulock.unlock();

        delay(time);        
    }
}

int main() 
{
    thread t1(display, 1, 1);
    thread t2(display, 2, 2);
    thread t3(display, 3, 2);


    t1.join();
    t2.join();
    t3.join();

    return 0;
}

/********************************************
 * atomic: dùng cho biến toàn cục
 * lock_guard, unique_lock: dùng cho ngoại vi
 *******************************************/
```

📝 ``` store(new_value) ```: Gán một giá trị mới vào biến một cách an toàn trước khi thực hiện các thao tác khác.

📝 ``` load() ```: Lấy giá trị hiện tại của biến

📝 ``` fetch_add(n) ```: Tăng giá trị của biến lên ``` n ``` đơn vị.

📝 ``` fetch_add(1) ```: Tăng giá trị của biến lên 1 đơn vị, giống với toán tử ``` ++ ```.

📝 ``` fetch_sub(n) ```: Giảm giá trị của biến xuống ``` n ``` đơn vị.

📝 ``` fetch_sub(1) ```: Giảm giá trị của biến xuống 1 đơn vị, , giống với toán tử ``` -- ```.

📝 ``` exchange(new_value) ```: Đổi giá trị của biến nguyên tử thành một giá trị mới và trả về giá trị cũ.

📝 ``` compare_exchange_weak(expected, desired) ```: Nếu giá trị hiện tại của biến nguyên tử bằng **expected**, thay đổi giá trị thành **desired**. Nếu không, cập nhật **expected** bằng giá trị hiện tại.

```cpp
int expected = 100;
value_int.compare_exchange_weak(expected, 200);
```

- Nếu value_int là 100, nó sẽ được đổi thành 200.

<br>

</p>
</details>

<details><summary><b>📚 Mutex</b></summary>
<p>

- **Mutex (Mutual Exclusion)**: Là một đối tượng đồng bộ hóa cung cấp cơ chế để giới hạn truy cập tài nguyên (ngoại vi: bàn phím, màn hình, camera, ...) chỉ cho một luồng tại một thời điểm. Khi một luồng khóa (lock) mutex, các luồng khác phải chờ cho đến khi mutex được mở khóa (unlock) mới có thể tiếp tục truy cập tài nguyên.
- Trạng thái của mutex: có hai trạng thái chính:

	+ **Khóa (locked)**: Khi một luồng giữ (lock) mutex, trạng thái của mutex là locked. Điều này nghĩa là mutex hiện đang được "sở hữu" bởi một luồng và không luồng nào khác có thể truy cập tài nguyên được bảo vệ bởi mutex cho đến khi luồng giữ mutex mở khóa (unlock). Nếu một luồng khác cố gắng lock mutex khi nó đang ở trạng thái locked, luồng đó sẽ bị block (chờ đợi) cho đến khi mutex được unlock.
	+ **Mở khóa (unlocked)**: Khi mutex không bị bất kỳ luồng nào giữ (lock), trạng thái của mutex là unlocked. Trong trạng thái này, bất kỳ luồng nào cũng có thể lock mutex và trở thành luồng sở hữu nó. Sau khi một luồng sở hữu mutex, trạng thái chuyển thành locked, và các luồng khác phải chờ.

- ``` std::mutex ``` được định nghĩa trong thư viện <mutex>. Các phương thức cơ bản bao gồm:

	+ **lock()**: Khóa mutex.
	+ **unlock()**: Mở khóa mutex.
	+ **try_lock()**: Thử khóa mutex. Nếu mutex chưa bị khóa, nó sẽ khóa mutex và trả về true. Nếu đã bị khóa bởi một luồng khác, nó sẽ không chặn luồng hiện tại mà trả về false.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
using namespace std;

atomic<int> sharedCounter(0); // biến chia sẻ giữa các luồng

mutex mtx;

void incrementTask(int iter)
{
    for (int i=0; i<iter; i++)
    {
        mtx.lock();                      // Khóa mutex trước khi truy cập biến chia sẻ
        cout << ++sharedCounter << endl; // Thao tác trên biến chia sẻ và in ra terminal
        mtx.unlock();                    // Mở khóa mutex sau khi truy cập
    }
}

int main(int argc, char const *argv[])
{
    thread t1(incrementTask, 100);
    thread t2(incrementTask, 100);

    t1.join();
    t2.join();

    cout << "Final result: " << sharedCounter << endl;
    return 0;
}
```

<br>

- ``` std::lock_guard ``` là một lớp RAII (Resource Acquisition Is Initialization) quản lý tự động việc khóa và mở khóa, giúp giảm lỗi lập trình như quên mở khóa. Các đối tượng std::lock_guard thường được khai báo cục bộ trong một hàm hoặc một khối lệnh.
- Chúng không lưu trữ tài nguyên được bảo vệ, mà chỉ quản lý việc khóa/mở khóa std::mutex một cách tự động.
- Tự động khóa mutex khi đối tượng được tạo.
- Tự động mở khóa khi đối tượng bị hủy.

💻 **Driver:**
```cpp
template<typename _Mutex>
class lock_guard
{
    public:
        typedef _Mutex mutex_type;

        lock_guard(mutex_type& __m) : _M_device(__m){ 
            _M_device.lock(); 
        }

        // lock_guard(mutex_type& __m, adopt_lock_t) noexcept : _M_device(__m){} // calling thread owns mutex

        ~lock_guard(){ 
            _M_device.unlock(); 
        }

        lock_guard(const lock_guard&) = delete;
        lock_guard& operator=(const lock_guard&) = delete;

    private:
        mutex_type&  _M_device;
};
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
using namespace std;

atomic<double> counter(0);

mutex mtx;

void delay(uint32_t time)
{
    this_thread::sleep_for(chrono::seconds(time));
}

void display(int id)
{
    while (1)
    {
        lock_guard<mutex> lock(mtx);
        cout << "This is task display: " << id << endl;
        counter = counter + 3.14;
        cout << "Counter: " << counter << endl;
        delay(1);
    }
}

int main(int argc, char const *argv[])
{
    thread t1(display, 1);
    thread t2(display, 2);
    thread t3(display, 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
```

<br>

- ``` std::unique_lock ``` tự động khóa mutex khi được tạo nhưng cung cấp tính linh hoạt hơn std::lock_guard, cho phép mở khóa thủ công hoặc tự động mở khóa khi ra khỏi phạm vi, hoặc thử khóa với thời gian chờ.

💻 **Driver:**
```cpp
template<typename _Mutex>
class unique_lock
{
    public:
        typedef _Mutex mutex_type;

        unique_lock() noexcept : _M_device(0), _M_owns(false){}

        unique_lock(mutex_type& __m): _M_device(std::__addressof(__m)), _M_owns(false)
        {
            lock();
            _M_owns = true;
        }     

        void lock()
        {
            if (!_M_device){
                __throw_system_error(int(errc::operation_not_permitted));
            }
            else if (_M_owns){
                __throw_system_error(int(errc::resource_deadlock_would_occur));
            }
            else{
                _M_device->lock();
                _M_owns = true;
            }
        }

        ~unique_lock()
        {
            if (_M_owns)
                unlock();
        }

        void unlock()
        {
            if (!_M_owns)
                __throw_system_error(int(errc::operation_not_permitted));
            else if (_M_device){
                _M_device->unlock();
                _M_owns = false;
            }
        }
        
    private:
        mutex_type* _M_device;
        bool        _M_owns;
};
```

<br>

💻 **Ví dụ 3:**
```cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

bool lock_test = false;

void delay(uint32_t time){ this_thread::sleep_for(chrono::seconds(time)); }

void display(int id)
{
    while (1)
    {
        unique_lock<mutex> lock(mtx);   
        cout << "This is task display: " << id << endl;
        delay(1);
        lock.unlock();
    }
}

int main(int argc, char const *argv[])
{
    thread t1(display, 1);
    thread t2(display, 2);
    thread t3(display, 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
```

<br>

💻 **Ví dụ 4:**
```cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

mutex mtx;

void delay(uint32_t time){ this_thread::sleep_for(chrono::seconds(time)); }

void task(int id)
{
    while(1)
    {
        unique_lock<mutex> ulock(mtx);
        cout << "Peripheral HMI " << id << endl;
        ulock.unlock();
        delay(1);

        ulock.lock();
        cout << "Peripheral camera " << id << endl;
        ulock.unlock();
        delay(2);

        ulock.lock();
        cout << "Peripheral keyboard " << id << endl;
        ulock.unlock();
        delay(3);
    }
}

int main(int argc, char const *argv[])
{
    thread t1(task, 1);
    thread t2(task, 2);
    thread t3(task, 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
```

<br>

📝 ``` mutex ``` khai báo **toàn cục**, còn ``` unique_lock, lock_guard ``` thì khai báo **cục bộ**.

- **``` mutex ``` cần được dùng chung giữa các luồng:**

	+ Một mutex phải được chia sẻ bởi tất cả các luồng muốn đồng bộ hóa truy cập vào cùng một tài nguyên.
	+ Nếu mutex được khai báo cục bộ (trong phạm vi hàm hoặc scope), mỗi luồng sẽ có bản sao riêng của mutex, làm mất tác dụng của đồng bộ hóa.

- **``` unique_lock, lock_guard ``` chỉ tồn tại trong phạm vi cần thiết**:

	+ ``` unique_lock ``` và ``` lock_guard ``` chỉ là công cụ quản lý khóa tạm thời, được sử dụng trong các vùng code cần bảo vệ, vì vậy chúng nên được khai báo cục bộ.
	+ Điều này giúp giảm thiểu thời gian giữ khóa, tránh **deadlock** và tăng hiệu suất chương trình.

📝 Trong lập trình đa luồng, ``` mutex ``` (mutual exclusion) được sử dụng để đảm bảo rằng chỉ có một luồng truy cập vào tài nguyên dùng chung tại một thời điểm.

📝 ``` unique_lock ``` và ``` lock_guard ``` được thiết kế để làm việc với mutex nhằm đảm bảo việc khóa và mở khóa mutex một cách an toàn và tự động.

<br>

</p>
</details>

<details><summary><b>📚 Condition variable</b></summary>
<p>

- ``` std::condition_variable ``` là 1 cơ chế giao tiếp và đồng bộ hóa giữa 2 hoặc nhiều luồng, cho phép một luồng chờ cho đến khi một điều kiện cụ thể được đáp ứng, và một luồng khác có thể thông báo khi điều kiện đó được thỏa mãn.
- Cách hoạt động của std::condition_variable:

a) Một luồng chờ (``` wait() ```) cho đến khi có tín hiệu từ một luồng khác:

- Luồng này sẽ chờ trong trạng thái chờ điều kiện, tránh lãng phí tài nguyên CPU.
- Để sử dụng wait(), cần có một ``` std::unique_lock<std::mutex> ``` và một đối tượng ``` std::condition_variable ```, vì nó phải tạm thời mở khóa mutex để các luồng khác có thể truy cập vào mutex và thay đổi điều kiện. Sau khi điều kiện được thỏa mãn và luồng được đánh thức, ``` std::unique_lock ``` sẽ tự động khóa lại mutex để đảm bảo tính nhất quán trước khi tiếp tục.
- Lưu ý: ``` std::lock_guard ``` không hỗ trợ mở khóa và khóa lại mutex như vậy. Khi một ``` std::lock_guard ``` được tạo, nó sẽ giữ mutex cho đến khi đối tượng bị hủy (khi ra khỏi phạm vi), do đó không phù hợp để sử dụng với wait.

b) Một luồng khác thông báo (notify_one() hoặc notify_all()) rằng điều kiện đã được đáp ứng:

- ``` notify_one() ```: gửi thông báo tới 1 luồng đang chờ.
- ``` notify_all() ```: gửi thông báo tới nhiều luồng đang chờ.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <thread>               // Tạo luồng
#include <mutex>                // Khóa dữ liệu khi có nhiều luồng truy cập
#include <condition_variable>   // Biến điều kiện giúp đồng bộ hóa giữa các luồng
#include <chrono>               // Quản lý thời gian
#include <atomic>               // Biến nguyên tử để tránh xung đột dữ liệu

using namespace std;

/********************************************************
 * @brief Hàm tạo độ trễ cho luồng
 * @param time Thời gian trễ (đơn vị: giây)
 ********************************************************/
void delay(uint32_t time) { 
    this_thread::sleep_for(chrono::seconds(time)); 
}

// Biến toàn cục dùng để lưu dữ liệu cảm biến
atomic<int> sensor_data(0);

// Cờ kiểm tra xem dữ liệu đã sẵn sàng hay chưa
bool check_data = false;

// Đối tượng mutex dùng để đồng bộ dữ liệu giữa các luồng
mutex mtx;

// Biến điều kiện để báo hiệu khi có dữ liệu mới
condition_variable cv;

/********************************************************
 * @brief Hàm mô phỏng quá trình đọc dữ liệu từ cảm biến
 * @details Cứ mỗi 2 giây, hàm này sẽ cập nhật dữ liệu cảm biến
 *          và gửi tín hiệu cho luồng xử lý dữ liệu.
 * @return void
 ********************************************************/
void sensor_read()
{
    while (1)
    {
        delay(2);  // Tạo độ trễ 2 giây
        unique_lock<mutex> lock(mtx);
        sensor_data = rand() % 100; // Giả lập giá trị cảm biến ngẫu nhiên
        check_data = true;          // Đánh dấu dữ liệu đã sẵn sàng
        cout << "Read data done!\n";
        lock.unlock();
        cv.notify_one(); // Báo hiệu cho luồng xử lý dữ liệu
    }
}

/********************************************************
 * @brief Hàm xử lý dữ liệu từ cảm biến
 * @details Chờ dữ liệu cảm biến sẵn sàng, sau đó in ra màn hình
 * @return void
 ********************************************************/
void process_data()
{
    while (1)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{return check_data;});  // Chờ đến khi dữ liệu sẵn sàng
        cout << "Data: " << sensor_data << endl; // Hiển thị dữ liệu
        lock.unlock();
        check_data = false; // Reset cờ dữ liệu
    }
}

int main(int argc, char const *argv[])
{
    thread task1(sensor_read);  // Tạo luồng đọc dữ liệu cảm biến
    thread task2(process_data); // Tạo luồng xử lý dữ liệu

    task1.join(); // Chờ luồng 1 kết thúc
    task2.join(); // Chờ luồng 2 kết thúc
    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <thread>               // Tạo luồng
#include <mutex>                // Khóa dữ liệu khi có nhiều luồng truy cập
#include <condition_variable>   // Biến điều kiện giúp đồng bộ hóa giữa các luồng
#include <chrono>               // Quản lý thời gian
#include <atomic>               // Biến nguyên tử để tránh xung đột dữ liệu

using namespace std;

/********************************************************
 * @brief Hàm tạo độ trễ cho luồng
 * @param time Thời gian trễ (đơn vị: giây)
 ********************************************************/
void delay(uint32_t time){ this_thread::sleep_for(chrono::seconds(time)); }

// Biến toàn cục dùng để lưu dữ liệu cảm biến
atomic<int> sensor_data(0);

// Cờ kiểm tra xem dữ liệu đã sẵn sàng hay chưa
bool check_data = false;

// Đối tượng mutex dùng để đồng bộ dữ liệu giữa các luồng
mutex mtx;

// Biến điều kiện để báo hiệu khi có dữ liệu mới
condition_variable cv;

/********************************************************
 * @brief Hàm mô phỏng quá trình đọc dữ liệu từ cảm biến
 * @details Cứ mỗi 2 giây, hàm này sẽ cập nhật dữ liệu cảm biến
 *          và gửi tín hiệu cho tất cả các luồng xử lý dữ liệu.
 * @return void
 ********************************************************/
void sensor_read()
{
    while (1)
    {
        delay(2);  // Tạo độ trễ 2 giây
        sensor_data = rand() % 100; // Giả lập giá trị cảm biến ngẫu nhiên
        check_data = true;          // Đánh dấu dữ liệu đã sẵn sàng
        
        unique_lock<mutex> lock(mtx);    // Có thể không cần vì atomic có thể tự bảo vệ
        cout << "Read data done!\n";
        lock.unlock();

        cv.notify_all(); // Báo hiệu cho tất cả các luồng xử lý dữ liệu
    }
}

/********************************************************
 * @brief Hàm xử lý dữ liệu từ cảm biến (luồng 1)
 * @details Chờ dữ liệu cảm biến sẵn sàng, sau đó in ra màn hình.
 * @return void
 ********************************************************/
void process_data_1()
{
    while (1)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []()->bool{return check_data;}); // Chờ đến khi dữ liệu sẵn sàng
        cout << "Process Data 1: " << sensor_data << endl;
        lock.unlock();
        check_data = false;  
    }
}

/********************************************************
 * @brief Hàm xử lý dữ liệu từ cảm biến (luồng 2)
 * @details Chờ dữ liệu cảm biến sẵn sàng, sau đó in ra màn hình.
 * @return void
 ********************************************************/
void process_data_2()
{
    while (1)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []()->bool{return check_data;}); // Chờ đến khi dữ liệu sẵn sàng
        cout << "Process Data 2: " << sensor_data << endl;
        lock.unlock();  // Giảm độ nghẽn (unlock ngay sau khi hoàn thành tác vụ)
        check_data = false;       
    }
}

int main(int argc, char const *argv[])
{
    thread task1(sensor_read);     // Tạo luồng đọc dữ liệu cảm biến
    thread task2(process_data_1);  // Tạo luồng xử lý dữ liệu 1
    thread task3(process_data_2);  // Tạo luồng xử lý dữ liệu 2

    task1.join(); // Chờ luồng 1 kết thúc
    task2.join(); // Chờ luồng 2 kết thúc
    task3.join(); // Chờ luồng 3 kết thúc

    return 0;
}
```

<br>

💻 **Ví dụ 3:**
```cpp
#include <iostream>
#include <thread>               // Quản lý luồng
#include <chrono>               // Quản lý thời gian
#include <mutex>                // Đồng bộ hóa luồng
#include <atomic>               // Biến nguyên tử
#include <condition_variable>   // Điều kiện đồng bộ hóa giữa các luồng
#include <vector>               // Sử dụng buffer để lưu dữ liệu cảm biến

using namespace std;

// Đối tượng mutex dùng để đồng bộ dữ liệu giữa các luồng
mutex mtx;

// Biến điều kiện để kiểm soát việc đọc và xử lý dữ liệu
condition_variable cv;

// Biến nguyên tử dùng để đếm dữ liệu cảm biến
atomic<int> data_sensor(0);

// Bộ đệm dùng để lưu dữ liệu cảm biến trước khi xử lý
vector<int> buffer;

// Kích thước tối đa của buffer
const unsigned int MAX_BUFFER_SIZE = 5;

// Biến cờ kiểm soát việc dừng chương trình
bool stop = false;

/********************************************************
 * @brief Hàm tạo độ trễ
 * @param time Thời gian trễ (đơn vị: giây)
 ********************************************************/
void delay(int time)
{
    this_thread::sleep_for(chrono::seconds(time));
}

/********************************************************
 * @brief Luồng đọc dữ liệu cảm biến
 * @details Dữ liệu được đọc và thêm vào buffer nếu chưa đầy.
 *          Khi buffer đầy, luồng sẽ chờ đến khi có không gian trống.
 *          Dữ liệu sẽ tăng dần theo biến toàn cục `data_sensor`.
 * @return void
 ********************************************************/
void readData()
{
    while (!stop)
    {
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock, [](){ return buffer.size() < MAX_BUFFER_SIZE || stop; });

        if (stop) break; // Thoát nếu có yêu cầu dừng

        // Thêm dữ liệu vào buffer
        buffer.push_back(++data_sensor);
        cout << "Added data: " << data_sensor << endl;

        cv.notify_one();  // Thông báo cho luồng xử lý dữ liệu
        ulock.unlock();    // Giải phóng mutex trước khi ngủ

        delay(1);
    }
}

/********************************************************
 * @brief Luồng xử lý dữ liệu
 * @details Lấy dữ liệu từ buffer và xử lý. Khi buffer trống,
 *          luồng sẽ chờ đến khi có dữ liệu mới.
 *          Xử lý dữ liệu đầu tiên trong buffer theo FIFO.
 * @return void
 ********************************************************/
void processData()
{
    while (!stop)
    {
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock, [](){ return !buffer.empty() || stop; });

        if (stop && buffer.empty()) break; // Thoát nếu buffer rỗng và có yêu cầu dừng

        // Xử lý dữ liệu đầu tiên trong buffer
        cout << "Processed data " << buffer.front() << endl;
        buffer.erase(buffer.begin());  // Xóa dữ liệu đầu tiên

        cv.notify_one();  // Thông báo cho luồng đọc dữ liệu
        ulock.unlock();    // Giải phóng mutex trước khi ngủ

        delay(8);
    }
}


int main()
{
    thread t1(readData);   // Tạo luồng đọc dữ liệu cảm biến
    thread t2(processData); // Tạo luồng xử lý dữ liệu

    delay(35); // Chạy trong 35 giây

    // Dừng luồng an toàn
    {
        lock_guard<mutex> lock(mtx);
        stop = true;
    }
    cv.notify_all(); // Thông báo cho tất cả các luồng thoát

    t1.join(); // Chờ luồng đọc dữ liệu kết thúc
    t2.join(); // Chờ luồng xử lý dữ liệu kết thúc

    cout << "Main: All threads stopped. Exiting program.\n";

    return 0;
}
```

📝 **Luồng chính (main)**

- **Khởi tạo hai luồng**:

	+ Luồng t1 chạy hàm ``` readData ``` để thêm dữ liệu vào buffer.
	+ Luồng t2 chạy hàm ``` processData ``` để lấy dữ liệu từ buffer và xử lý.

- **Chạy trong 10 giây**:

	+ Sử dụng delay(10) để luồng chính chờ trong 10 giây trước khi dừng cả hai luồng.

- **Dừng chương trình**:

	+ Đặt cờ ``` stop = true ``` để báo hiệu hai luồng kết thúc vòng lặp.
	+ Gọi ``` cv.notify_all() ``` để đánh thức bất kỳ luồng nào đang chờ.

- **Đợi hai luồng kết thúc**:

	+ Gọi ``` t1.join() ``` và ``` t2.join() ``` để đảm bảo hai luồng kết thúc trước khi chương trình thoát.

📝 **Luồng đọc dữ liệu (read data)**

- **Nhiệm vụ**: Thêm dữ liệu liên tục vào buffer, giả lập việc thu thập dữ liệu từ cảm biến.
- **Flow**:

	1. **Chờ điều kiện**:
	
 		+ ``` cv.wait() ``` kiểm tra điều kiện ``` buffer.size() < MAX_BUFFER_SIZE ```.
		+ Nếu buffer đầy, luồng sẽ chờ đến khi consumer (luồng processData) xử lý bớt dữ liệu.

	2. **Thêm dữ liệu**:

		+ Nếu buffer chưa đầy, dữ liệu mới (data) được thêm vào cuối vector buffer.
		+ In thông báo: ``` "Added data: <data>" ```.
	
 	3. **Thông báo tới luồng xử lý**:

		+ Gọi ``` cv.notify_one() ``` để báo cho luồng ``` processData ``` biết rằng đã có dữ liệu mới.

	4. **Delay**:

		+ Giả lập việc đọc dữ liệu bằng cách chờ 1 giây (delay(1)).

	5. **Thoát vòng lặp**:

		+ Nếu cờ ``` stop = true ```, luồng kết thúc.

📝 **Luồng xử lý dữ liệu (process data)**

- **Nhiệm vụ**: Lấy dữ liệu từ buffer và xử lý, giả lập phân tích dữ liệu từ cảm biến.
- **Flow**:

	1. **Chờ điều kiện**:
	
 		+ ``` cv.wait() ``` kiểm tra điều kiện ``` !buffer.empty() ```.
		+ Nếu buffer rỗng, luồng sẽ chờ đến khi producer (luồng readData) thêm dữ liệu.

	2. **Lấy và xóa dữ liệu**:

		+ Lấy phần tử đầu tiên trong buffer (``` buffer.front() ```)..
		+ Xóa phần tử đầu tiên (``` buffer.erase(buffer.begin()) ```).
	
 	3. **Thông báo tới luồng đọc**:

		+ Gọi ``` cv.notify_one() ``` để báo cho luồng ``` readData ``` biết rằng buffer đã có chỗ trống.

	4. **Delay**:

		+ Giả lập việc đọc dữ liệu bằng cách chờ 1 giây (delay(1)).

	5. **Thoát vòng lặp**:

		+ Nếu cờ ``` stop = true ```, luồng kết thúc.

<br>


</p>
</details>

<details><summary><b>📚 Semaphore</b></summary>
<p>

Semaphore là một cơ chế đồng bộ hóa trong lập trình đa luồng, giúp quản lý truy cập vào tài nguyên dùng chung. Semaphore được chia làm 2 loại:

- **Counting Semaphore:** (Semaphore đếm): Có thể có giá trị bất kỳ, giúp quản lý một số lượng nhất định các tài nguyên.
- **Binary Semaphore:** (Semaphore nhị phân): Chỉ có hai giá trị 0 hoặc 1, tương tự như một mutex (khóa), dùng để kiểm soát truy cập vào một tài nguyên duy nhất.

<br>

Semaphore được khởi tạo với một giá trị nguyên dương, và mỗi lần một thread yêu cầu tài nguyên, giá trị này sẽ giảm đi một đơn vị (down/wait). Khi một thread giải phóng tài nguyên, giá trị semaphore sẽ tăng lên một đơn vị (up/signal).

<br>

Các thao tác chính trong Semaphore:

- **wait (down)**: Nếu semaphore lớn hơn 0, giảm nó đi 1. Nếu semaphore bằng 0, thread sẽ chờ đến khi semaphore > 0.
- **signal (up)**: Tăng giá trị semaphore lên 1, cho phép các thread khác tiếp tục.

C++ không hỗ trợ trực tiếp semaphore trong thư viện chuẩn, nhưng bạn có thể sử dụng thư viện <semaphore> trong C++20, hoặc thư viện POSIX trên Linux (<semaphore.h>) hoặc các lớp semaphore tự triển khai.

<br>

💻 **Ví dụ 1:**
```cpp
/***************************************************************************
 * @file    Ex_Semaphore_1.cpp
 * @brief   Chương trình quản lý kết nối mạng bằng semaphore đếm
 * @details Chương trình này sử dụng semaphore đếm để giới hạn số lượng kết nối
 *          mạng đồng thời tối đa là 5 kết nối. Các kết nối được thực hiện thông
 *          qua các luồng (threads) và giả lập quá trình kết nối mạng trong 2 giây.
 * @version 1.0
 * @date    2024-11-11
 * @author  Anh Nguyen
 ***************************************************************************/

#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
#include <mutex>

using namespace std;

/**************************************************************************
 * @brief   Mutex để đồng bộ luồng khi ghi ra terminal
 * @details Mutex này đảm bảo chỉ có 1 luồng ghi ra màn hình tại một thời điểm.
 **************************************************************************/
mutex mtx;

/**************************************************************************
 * @brief   Đối tượng semaphore đếm cho quản lý kết nối mạng
 * @details Đối tượng semaphore này giới hạn số lượng kết nối mạng đồng thời
 *          tối đa là 5 kết nối, đảm bảo tài nguyên mạng được phân bổ hợp lý.
 **************************************************************************/
counting_semaphore<5> connection_semaphore(5);

/**************************************************************************
 * @brief   Kết nối mạng giả lập
 * @details Hàm này sử dụng semaphore để quản lý truy cập vào tài nguyên mạng,
 *          mô phỏng thời gian kết nối trong 2 giây và sau đó giải phóng tài nguyên.
 * @param   id    ID của kết nối mạng, giúp phân biệt các kết nối khác nhau.
 * @return  void
 **************************************************************************/
void connect_to_network(int id) 
{
    /**< Khi có 1 luồng truy cập, semaphore giảm giá trị đi 1 */
    connection_semaphore.acquire(); 

    /**< Hiển thị thông báo ra màn hình terminal, sử dụng mutex để đảm bảo chỉ 1 luồng ghi ra màn hình */
    unique_lock<mutex> ulock(mtx); 
    cout << "Connection " << id << " đang sử dụng tài nguyên mạng...\n";
    ulock.unlock();

    /**< Mô phỏng thời gian kết nối */
    this_thread::sleep_for(chrono::seconds(2));

    /**< Hiển thị thông báo ra màn hình terminal, sử dụng mutex để đảm bảo chỉ 1 luồng ghi ra màn hình */
    ulock.lock();
    cout << "Connection " << id << " đã giải phóng tài nguyên mạng.\n";
    ulock.unlock();

    /**< Sau khi 1 luồng thực thi xong, semaphore tăng giá trị thêm 1 */
    connection_semaphore.release();  // Giải phóng tài nguyên mạng
}

int main() 
{
    thread connections[10];     /**< Tạo 1 mảng chứa 10 luồng */
    
    for (int i = 0; i < 10; ++i) 
    {
        connections[i] = thread(connect_to_network, i + 1);
    }

    for (auto& connection : connections) 
    {
        connection.join();
    }

    return 0;
}

/**
 * @note    Chỉ biên dịch được với C++20 trở lên. Biên dịch với lệnh:
 *          g++ -std=c++20 Ex_Semaphore_1.cpp -o Ex_Semaphore_1
 */
```

<br>

💻 **Ví dụ 2:**
```cpp
/**************************************************************************
 * @file    Ex_Semaphore_2.cpp
 * @brief   Điều khiển mở và đóng cửa xe sử dụng semaphore nhị phân
 * @details File này chứa các hàm để thực hiện mở và đóng cửa xe ô tô, đảm bảo
 *          rằng không có xung đột giữa các thao tác mở và đóng nhờ sử dụng
 *          semaphore nhị phân. Chỉ một thao tác mở hoặc đóng cửa có thể diễn
 *          ra tại một thời điểm, ngăn ngừa xung đột.
 * @version 1.0
 * @date    2024-11-11
 * @author  Anh Nguyen
 **************************************************************************/

#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
#include <mutex>

using namespace std;

/**************************************************************************
 * @brief   Mutex để đồng bộ luồng khi ghi ra terminal
 * @details Mutex này đảm bảo chỉ có 1 luồng ghi ra màn hình tại một thời điểm.
 **************************************************************************/
mutex mtx;

/**************************************************************************
 * @brief   Semaphore nhị phân quản lý trạng thái cửa xe
 * @details Giá trị semaphore là 1 khi cửa sẵn sàng cho thao tác mới và là 0 
 *          khi đang thao tác (mở hoặc đóng).
 **************************************************************************/
binary_semaphore door_semaphore(1);

/**************************************************************************
 * @brief   Mở cửa xe
 * @details Chức năng này thực hiện mở cửa xe và kiểm soát thao tác mở bằng semaphore.
 *          Khi cửa đang được mở, các thao tác khác sẽ bị ngăn chặn.
 * @param[in]  id - ID của người điều khiển cửa xe
 * @return  void
 **************************************************************************/
void open_door(int id) 
{
    /**< Khóa semaphore để thực hiện thao tác mở cửa */
    door_semaphore.acquire();

    /**< Hiển thị thông báo ra màn hình terminal, sử dụng mutex để đảm bảo chỉ 1 luồng ghi ra màn hình */
    unique_lock<mutex> ulock(mtx); 
    cout << "Cửa xe đang mở bởi người điều khiển " << id << ".\n";
    ulock.unlock();

    /**< Giả lập thời gian mở cửa */
    this_thread::sleep_for(chrono::seconds(1));

    /**< Hiển thị thông báo ra màn hình terminal, sử dụng mutex để đảm bảo chỉ 1 luồng ghi ra màn hình */
    ulock.lock();
    cout << "Cửa xe đã mở.\n";
    ulock.unlock();

    /**< Giải phóng semaphore sau khi mở cửa hoàn tất */
    door_semaphore.release();
}

/**************************************************************************
 * @brief   Đóng cửa xe
 * @details Chức năng này thực hiện đóng cửa xe và kiểm soát thao tác đóng bằng semaphore.
 *          Khi cửa đang được đóng, các thao tác khác sẽ bị ngăn chặn.
 * @param[in]  id - ID của người điều khiển cửa xe
 * @return  void
 **************************************************************************/
void close_door(int id) 
{
    /**< Khóa semaphore để thực hiện thao tác đóng cửa */
    door_semaphore.acquire(); 

    /**< Hiển thị thông báo ra màn hình terminal, sử dụng mutex để đảm bảo chỉ 1 luồng ghi ra màn hình */
    unique_lock<mutex> ulock(mtx);      
    cout << "Cửa xe đang đóng bởi người điều khiển " << id << ".\n";
    ulock.unlock();

    /**< Giả lập thời gian đóng cửa */
    this_thread::sleep_for(chrono::seconds(1));

    /**< Hiển thị thông báo ra màn hình terminal, sử dụng mutex để đảm bảo chỉ 1 luồng ghi ra màn hình */
    ulock.lock();
    cout << "Cửa xe đã đóng.\n";
    ulock.unlock();

    /**< Giải phóng semaphore sau khi đóng cửa hoàn tất */
    door_semaphore.release();
}

int main() 
{
    // Tạo thread để thực hiện mở cửa bởi người điều khiển 1
    thread t1(open_door, 1);

    // Tạo thread để thực hiện đóng cửa bởi người điều khiển 2
    thread t2(close_door, 2);

    // Chờ cả hai thread hoàn tất thao tác
    t1.join();
    t2.join();

    return 0;
}

/**
 * @note    Chỉ biên dịch được với C++20 trở lên. Biên dịch với lệnh:
 *          g++ -std=c++20 Ex_Semaphore_2.cpp -o Ex_Semaphore_2
 */
```

<br>

</p>
</details>

<details><summary><b>📚 Race Condition</b></summary>
<p>

Race condition là một vấn đề trong lập trình đa luồng xảy ra khi:

- Kết quả hoặc hành vi của chương trình phụ thuộc vào thứ tự thực thi không xác định của các luồng.

- Hai hoặc nhiều luồng truy cập vào cùng một tài nguyên chia sẻ (biến, ngoại vi) mà không có cơ chế đồng bộ hóa phù hợp.

- Ví dụ điển hình: Nhiều luồng cùng truy cập ngoại vi, Nhiều luồng ghi vào file log mà không đồng bộ hóa.

<br>

</p>
</details>

<details><summary><b>📚 Data Race</b></summary>
<p>

Data race là một trường hợp cụ thể của race condition xảy ra khi:

- Hai hoặc nhiều luồng truy cập vào cùng một dữ liệu (biến).

- Ít nhất một trong các luồng thực hiện ghi vào tài nguyên.

- Ví dụ điển hình: Hai luồng ghi vào cùng một biến chia sẻ mà không đồng bộ hóa.

<br>

</p>
</details>

</p>
</details>

<details><summary><b>4. Asynchronous</b></summary>
<p>

<details><summary><b>📚 Giới thiệu </b></summary>
<p>

- Luồng bất đồng bộ (asynchronous thread) là một cơ chế trong lập trình cho phép thực thi một tác vụ trên một luồng riêng biệt mà không làm gián đoạn luồng chính, đồng thời kết quả của tác vụ có thể được truy vấn sau khi luồng kết thúc.
- Luồng bất đồng bộ trong C++ thường được tạo ra thông qua việc sử dụng ``` std::async ``` từ thư viện ``` <future> ```. Khi bạn gọi một hàm sử dụng ``` std::async ```, nó sẽ thực thi hàm đó trên một luồng riêng biệt, và trả về một đối tượng ``` std::future ```.
- Luồng bất đồng bộ khác với luồng thông thường ở chỗ:

	+ Luồng được quản lý tự động bởi hệ thống runtime của C++.
	+ Các luồng của ``` std::thread ``` không có cơ chế xử lý kết quả, nghĩa là đối với ``` join ``` muốn lấy kết quả cuối cùng của luồng thì phải khai báo 1 biến toàn cục để lưu trữ vào đó, đối với ``` detach ``` thì không lấy được kết quả cuối cùng của luồng dù có khai báo biến toàn cục để lưu trữ. Nhưng đối với luồng bất đồng bộ thì kết quả của luồng có thể được lấy ra khi cần thiết.

- Trong C++, lập trình bất đồng bộ cho phép chạy các tác vụ trong các luồng riêng biệt, xử lý các tác vụ mất thời gian (như I/O, tính toán nặng) mà không làm gián đoạn luồng chính. Các thành phần chính để hỗ trợ lập trình bất đồng bộ trong C++ bao gồm:

	+ ``` std::async ```: Khởi chạy một tác vụ bất đồng bộ, trả về đối tượng.
	+ ``` std::future ```: Được sử dụng để lưu trữ kết quả của một tác vụ sẽ hoàn thành trong tương lai.
	+ ``` std::shared_future ```: Cho phép nhiều luồng cùng truy cập kết quả của một tác vụ bất đồng bộ.

<br>

</p>
</details>

<details><summary><b>📚 Tạo và chạy luồng bất đồng bộ </b></summary>
<p>

- ``` std::async ``` là một hàm trong C++ (từ C++11 trở đi) tạo ra một luồng để thực thi một công việc (task) có thể chạy bất đồng bộ, dựa trên một hàm hoặc biểu thức lambda mà bạn cung cấp. Kết quả của công việc này được trả về dưới dạng ``` std::future ```, kiểu dữ liệu cho phép truy xuất giá trị của tác vụ sau khi nó hoàn tất.
- Cú pháp: ``` std::future<T> std::async(std::launch policy, Callable&& func, Args&&... args) ```

- **policy**: chế độ chạy:

	+ ``` std::launch::async ```: hàm sẽ chạy ngay lập tức trên một luồng mới.
	+ ``` std::launch::deferred ```: hàm chỉ chạy khi kết quả của ``` std::future ``` được yêu cầu (lazy evaluation), nghĩa là khi bạn gọi ``` future.get() ```.

- **func**: Hàm hoặc biểu thức lambda cần thực hiện bất đồng bộ.
- **args**: Các tham số truyền vào func (nếu có).

<br>

</p>
</details>

<details><summary><b>📚 Truy xuất kết quả </b></summary>
<p>

- Khi ``` std::async ``` được gọi, một tác vụ bất đồng bộ được tạo ra và vùng bộ nhớ cho kết quả sẽ được cấp phát động (trên heap).
- ``` std::future ``` hoặc ``` std::shared_future ``` sẽ nắm quyền quản lý kết quả này và giữ một con trỏ đến vùng nhớ chứa kết quả.
- Khi ``` get() ``` được gọi, giá trị được trả về từ bộ nhớ này. Nếu là ``` std::future ```, ``` get() ``` sẽ chỉ có thể gọi một lần. Nếu là ``` std::shared_future ```, ``` get() ``` có thể gọi nhiều lần.
- Sự khác nhau giữa ``` std::future ``` và ``` std::shared_future ```:

	+ ``` std::future ```: Đại diện cho một giá trị sẽ có trong tương lai và chỉ cho phép một luồng duy nhất lấy giá trị đó. Sau khi phương thức get() được gọi, giá trị sẽ được "di chuyển" và không thể lấy lại từ std::future lần nữa. Nếu có nhiều thread cố gắng gọi get() trên cùng một std::future, chương trình sẽ bị lỗi.
	+ ``` std::shared_future ```: Cho phép nhiều luồng cùng chia sẻ và truy cập kết quả của một tác vụ bất đồng bộ. Đối tượng shared_future có thể được sao chép và chia sẻ giữa các thread, mỗi thread có thể gọi get() mà không làm mất kết quả.

- Khi khởi tạo bằng ``` std::async ```, std::future là lựa chọn mặc định. Nếu cần chia sẻ kết quả giữa nhiều thread, bạn phải chuyển ``` std::future ``` sang ``` std::shared_future ```.

<br>

💻 **Ví dụ 1:**
```cpp
#include <iostream>
#include <thread>
#include <future>
#include <mutex>

using namespace std;

int sensor_data = 0;

mutex mtx;

void delay(uint32_t time){this_thread::sleep_for(chrono::seconds(time));}

int sensor_read(){
    for (int i=0; i<7; i++){
        unique_lock<mutex> ulock(mtx);
        cout << "sensor read, i = " << i << endl;
        ulock.unlock();
        delay(1);
    }
    sensor_data = rand() % 100;
    cout << "Read data done!\n";
    return sensor_data;
}

void task1(uint32_t time){
    int i = 0;
    while(1){
        unique_lock<mutex> ulock(mtx);
        cout << "task 1, i = " << i++ << endl;
        ulock.unlock();
        delay(time);
    }
}

void task2(uint32_t time){
    int i = 0;
    while(1){
        unique_lock<mutex> ulock(mtx);
        cout << "task 2, i = " << i++ << endl;
        ulock.unlock();
        delay(time);
    }
}

int main(int argc, char const *argv[])
{
    future<int> sensor_future = async(launch::async, sensor_read);
    /*
    std::async với launch::async sẽ khởi chạy sensor_read trong một thread riêng biệt,
    nghĩa là hàm `sensor_read` chạy trong một thread riêng mà không làm ảnh hưởng chương trình chính.
    Kiểu trả về là future<int>, cho phép lấy giá trị kết quả từ sensor_read sau khi hoàn thành.
    */

    thread t1(task1, 1);     // t1: đại diện cho luồng 1
    thread t2(task2, 3);     // t2: đại diện cho luồng 2

    int i = 0;
    while (i<10){
        unique_lock<mutex> ulock(mtx);
        cout << "This is main, i = " << i++ << endl;
        ulock.unlock();
        delay(1);
    }

    cout << "Data đã hoàn thành 1: " << sensor_future.get() << endl;// delete
    // cout << "Data đã hoàn thành 2: " << sensor_future.get() << endl;

    t1.join();
    t2.join();

    return 0;
}
```

<br>

**Ví dụ 2:**

```cpp
#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

int asyncTask(){
    this_thread::sleep_for(chrono::seconds(3));
    return 100;
}

void processResult(int id, shared_future<int> f){
    unique_lock<mutex> lock(mtx);
    cout << "Task " << id << ": " << f.get() << endl;
    lock.unlock();
}
/*********************************************************************************************************************
 * Hàm này nhận hai tham số: id là một số nguyên đại diện cho ID của tác vụ và f là một shared_future<int> dùng để lấy kết 
 * quả từ tác vụ bất đồng bộ.
 * Trong hàm, f.get() được gọi để lấy giá trị từ shared_future và in ra kết quả. Kết quả này sẽ là 100 vì đó là giá trị 
 * trả về của asyncTask.
 * shared_future cho phép nhiều luồng cùng truy cập vào kết quả của một tác vụ bất đồng bộ.
 ********************************************************************************************************************/

int main(int argc, char const *argv[])
{
    shared_future<int> shared_ft = async(launch::async, asyncTask).share();
    /*********************************************************************************************************************
     * Phương thức .share() được gọi trên đối tượng future để chuyển đổi nó thành std::shared_future<int>. Điều này cho 
     * phép nhiều luồng cùng chia sẻ kết quả của tác vụ mà không làm mất giá trị.
     ********************************************************************************************************************/

    thread t1(processResult, 1, shared_ft);
    thread t2(processResult, 2, shared_ft);
    /*********************************************************************************************************************
     * t1 và t2 được khởi tạo để chạy hàm processResult với các tham số tương ứng là 1 và 2 cho id, cùng với shared_ft 	 
     * (kết quả chia sẻ).
     * Cả hai thread sẽ chạy song song và gọi f.get() từ shared_ft để lấy kết quả từ tác vụ asyncTask. Vì shared_future 
     * cho phép chia sẻ kết quả, nên việc gọi f.get() trên các thread khác nhau vẫn an toàn và có thể thực hiện đồng 
     * thời.t1 và t2 được khởi tạo để chạy hàm processResult với các tham số tương ứng là 1 và 2 cho id, cùng với 
     * shared_ft (kết quả chia sẻ).
     * Cả hai thread sẽ chạy song song và gọi f.get() từ shared_ft để lấy kết quả từ tác vụ asyncTask. Vì shared_future 
     * cho phép chia sẻ kết quả, nên việc gọi f.get() trên các thread khác nhau vẫn an toàn và có thể thực hiện đồng thời.
     *********************************************************************************************************************/


    t1.join();
    t2.join();

    return 0;
}
```

<br>

💻 **Ví dụ 2:**
```cpp
#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <chrono>
#include <conio.h>

using namespace std;

// Hàm giả lập tải tài nguyên
string loadResource(const std::string& resourceName) 
{
    this_thread::sleep_for(chrono::seconds(2)); // Giả lập thời gian tải
    return "Resource " + resourceName + " loaded.";
}

// Cập nhật trạng thái nhân vật dựa trên đầu vào
void updateGameState(char input, int& playerX, int& playerY) 
{
    switch (input) 
    {
        case 'w': --playerY; break; // Di chuyển lên
        case 's': ++playerY; break; // Di chuyển xuống
        case 'a': --playerX; break; // Di chuyển trái
        case 'd': ++playerX; break; // Di chuyển phải
        default: break;
    }
}

// Render trạng thái game
void render(int playerX, int playerY) 
{
    // system("cls"); // Xóa màn hình (chỉ dùng trên Windows)
    cout << "Rendering game...\n";
    cout << "Player position: (" << playerX << ", " << playerY << ")\n";
}

int main() 
{
    std::cout << "Game starting...\n";

    // Tải tài nguyên bất đồng bộ
    auto textureFuture = async(launch::async, loadResource, "Texture");
    auto soundFuture   = async(launch::async, loadResource, "Sound");

    // Biến trạng thái game
    int playerX = 0, playerY = 0;
    char input = 0;

    // Cờ để kiểm tra tài nguyên đã tải xong
    bool textureLoaded = false;
    bool soundLoaded = false;

    bool isRunning = true;
    while (isRunning) 
    {
        // 1. Xử lý đầu vào
        if (_kbhit()) // Kiểm tra có phím được nhấn
        { 
            input = _getch(); // Lấy ký tự phím

            if (input == 'q') 
            {
                isRunning = false; // Thoát game
            } 
            else 
            {
                updateGameState(input, playerX, playerY);
            }
        }

        // 2. Render game
        render(playerX, playerY);

        // 3. Kiểm tra tài nguyên đã tải xong chưa
        if (!textureLoaded && textureFuture.wait_for(chrono::seconds(0)) == future_status::ready) 
        {
            cout << textureFuture.get() << "\n";
            textureLoaded = true; // Đánh dấu đã tải xong
        }

        if (!soundLoaded && soundFuture.wait_for(chrono::seconds(0)) == future_status::ready) 
        {
            cout << soundFuture.get() << "\n";
            soundLoaded = true; // Đánh dấu đã tải xong
        }

        if (textureLoaded && soundLoaded) 
        {
            cout << "All resources loaded. Game is fully ready!\n";
        }

        // 4. Tạm dừng một chút để giảm tải CPU
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    cout << "Game exited.\n";
    return 0;
}

/**
 * Luồng chính:
 *      Xử lý đầu vào từ người chơi.
 *      Cập nhật trạng thái game (di chuyển nhân vật dựa trên đầu vào).
 *      Hiển thị khung hình (render).'
 *
 * Luồng bất đồng bộ:
 *      Tải tài nguyên đồ họa và âm thanh trong nền (như texture hoặc nhạc nền).
 * 
 * Trong khi tải tài nguyên:
 * 	Luồng chính hiển thị màn hình "Loading..." để người chơi biết game đang chuẩn bị.
 * 	Người chơi có thể nhấn phím để thử tương tác (nhưng nhân vật chưa di chuyển được vì dữ liệu chưa sẵn sàng).
 *
 * Sau khi tải tài nguyên:
 * 	Luồng bất đồng bộ báo rằng tài nguyên đã sẵn sàng bằng cách đặt isGameReady = true.
 * 	Luồng chính chuyển sang trạng thái hoàn thiện, cho phép người chơi điều khiển nhân vật và hiển thị đầy đủ thông tin.
 */
```

<br>

</p>
</details>

</p>
</details>

</p>
</details>
 
</p>
</details>
